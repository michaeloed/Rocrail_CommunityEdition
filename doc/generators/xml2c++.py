#!/usr/bin/python
#
# file: xml2c++.py
# This tool prints C++ class declarations from the rocrail components' xml files
# for mimicing classes in C. The main purpose for this tool was to feed the
# output into cpp2dia to get class diagrams for refactoring.

import xml.etree.ElementTree as ET
from optparse import OptionParser
from sys import stderr

INDENT=4

class Method(object):
    def __init__(self, eTree, abstract=False):
        self.fName = eTree.attrib["name"]
        self.retType = eTree.attrib.get("vt", "void")
        self.abstract = " = 0;" if abstract else ";"
        self._params = []

        for param in eTree:
            if param.tag != "param":
                print(stderr, "unexpected tag found for parameters of method '%s': %s" % (self.fName, param.tag))
                continue
            self._params.append((param.attrib["vt"], param.attrib["name"]))
    
    def __str__(self):
        return "    {self.retType} {self.fName}({params}){self.abstract}".format(
                params=", ".join(["%s %s"%(t,n) for t,n in self._params]), self=self)

class Attributes(list):
    def __init__(self, eTree):
        for attrib in eTree:
            if attrib.tag != "var":
                print(stderr, "unexpected tag found for class members: '%s'" % attrib.tag)
                continue
            self.append((attrib.attrib["vt"], attrib.attrib["name"]))

    def appendAttrib(self, const):
        self.append(const.attrib)
    
    def __str__(self):
        return "\n".join(["    {} {};".format(t,n) for t,n in self])

class Attrib(object):
    def __init__(self, eTree):
        self._name = "{}".format(eTree.attrib["name"])
        self._type = "{}".format(eTree.attrib["vt"])

    def getAttrib(self):
        return (self._type, self._name)

    attrib = property(getAttrib)

class Const(Attrib):
    def __init__(self, eTree):
        if eTree.attrib["vt"] == "const char*":
            fmtNameStr = "{} = \"{}\""
            fmtTypeStr = "{}"
        else:
            fmtNameStr = "{} = {}"
            fmtTypeStr = "const {}"
        self._name = fmtNameStr.format(eTree.attrib["name"], eTree.attrib["val"])
        self._type = fmtTypeStr.format(eTree.attrib["vt"])

class Doc(object):
    def __init__(self, docStr, indentLevel=0):
        self._docStr = docStr
        self._iLvl = indentLevel
    
    def __str__(self):
        if self._docStr != "":
            return """
{0}/**
{0} * {self._docStr}
{0} */""".format(" "*self._iLvl*INDENT, self=self)
        else:
            return ""

class _Class(object):
    def __init__(self, eTree, namespace):
        self.abstract = eTree.tag == "interface"
        assert self.abstract or eTree.tag == "object", "unexpected tag found on class level: %s" % eTree.tag
        self.remark = Doc(eTree.attrib.get("remark", ""))
        self.className = eTree.attrib["name"]
        self.baseClass = self.getBaseClass(eTree.attrib.get("interface", "OBase"))
        self.namespace = namespace.lower()
        self._methods = []
        self._attributes = Attributes([])

        for member in eTree:
            if member.tag == "fun":
                self._methods.append(Method(member, self.abstract))
            elif member.tag == "data":
                self._attributes.extend(Attributes(member))
            elif member.tag == "const":
                self._attributes.appendAttrib(Const(member))
            else:
                print(stderr, "unknown tag found for member of class %s: %s" % (self.className, member.tag))

    def getBaseClass(self, interface):
        if interface.startswith("$"):
            bc = interface.rsplit("/", 1)[1] # remove path of the referenced xml file
            bc = bc.split(":") # split class from the xml file
            bc = "{}::{}".format(bc[0][:-4], bc[1]) # join xml name (w/o file ext.) to <namespace>::<class>
        else:
            bc = interface
        return bc

    def __str__(self):
        methods = "\n".join(["{}".format(m) for m in self._methods])
        attribs = "\n".join(["{}".format(a) for a in self._attributes])
        # no namespaces as cpp2dia has a problem with it
        return """// namespace {self.namespace} {{
{self.remark}
class {self.className} : public {self.baseClass} {{
public:
{methods}
{self._attributes}
}}
//}}
""".format(self=self, methods=methods)#, attributes=attribs)

op = OptionParser(usage="%prog [options]", description="Generates C++ class headers "
        "from the old Rocrail xml files to feed them into an UML generator")
op.add_option("-i", dest="source", metavar="XML_FILE", help="xml file to parse")
options, args = op.parse_args()

tree = ET.parse(options.source)
root = tree.getroot()

classes = []
for _cls in root:
    try:
        namespace = root.attrib["name"]
    except KeyError:
        namespace = root.attrib.get("modulename", "_none")
    classes.append(_Class(_cls, namespace))

for cls in classes:
    print(cls)
