# Code Generators
The project was forked from Rocrail that used some code generators to create C
source files and headers from XML documents. These generators are build from the
project sources, which in turn already require these generated sources. This
creates a circular dependency, which is not a good idea, so an analysis should
check the importance of them and most likely find a way to make them dispensable.

## Analysis
As part of the `rocs` library 4 generator binaries are built:

* *ogen*: object generator
* *wgen*: wrapper object generator
* *png2wx*: converter for png into an image format for wxWidget
* *xml2cstr*:

The object generators seem to mimic an object oriented pattern for C. Therefor,
the results will be referenced as classes in this document, even if they are not.
When it is required to refer to real classes, it will be mentioned clearly.

### ogen
Each of the origin project's sub-components provide a XML file (`roc*.xml`) as
input for *ogen*. The content could be considered class declarations. Unfortunately,
there is no schema file that could be used to validate these input files.

There are class diagrams in the `./generators` sub-directory, created during this
analysis using [*cpp2dia*](http://cpp2dia.sourceforge.net/) and some manual tweaking.
As this tool expects C++ class declarations, a small parser for the `roc*.xml` files
was written that prints out C++ class headers for what is defined in these files.
This tool is also included here.

During the build process, the *ogen* binary is called for each *roc\** sub-component
to generate a set of files in the related directory. For every `<object>` tag in
the XML file it creates:

* `public/*.h` declares a structure which represents the class with function
  pointers for the methods and the structure of the base class (`OBase`)
* `impl/*_impl.h` declares a structure containing the class' properties; an
  instance of this structure is contained in the base class `OBase`; it also
  defines a function (`static iO*Data Data(void* p)`) that returns a pointer to
  this structure from a given instance
* `impl/*.c` contains dummy implementations of the methods; usually, there is a
  real implementation of them within the source tree (the generated one might
  have served as the starting point)
* `impl/*.fm` defines a global instance of the class structure, initialized with
  the function pointers to the actual implementations; could be seen as the
  '*class instance*', which can create actual objects (instances) of the class,
  usually through a method called `inst()`

#### How it is used
A source file in which the class should be used needs to include the `<class>.h`.
Only the class' implementation file includes `<class>_impl.h`, which makes the
attributes accessible there through the `Data()` function. This is sufficient as
the attributes are considered at least *protected*. On the other hand including
the *impl* header elsewhere might redefine the `Data()` function, which leads to
an error due to no support of function overloading in C.

To create an instance of such a class now, the `inst()` method of the *class
instance* needs to be called. This class instance is the instance of the struct
that the generator created as a class declaration and initialized in the related
`.fm` file. Usually it is called `<class>Op`. To follow the example in the next
section:
```
iOEvent evt = EventOp.inst("someEvent", True);
```
The `iOEvent` type is *typedef*'ed alias for an `OEvent` struct pointer. Every
class gets such an alias for a pointer to its struct (see `<class>.h`).

Now, the class' methods can be called on the instance. As it is already defined
in the XML file, the first parameter of a method is usually called `inst` of the
type `this`. The generator creates a parameter of the related pointer type using
the `iO<class>` alias. To finally call the method, the *class instance* is used
with the instance as the first parameter, e.g.:
```
EventOp.reset(evt);
```
The attributes of an object are only accessed through setter and getter or other
methods of a class. There, the data struct is retrieved from the instance by the
(private) `Data()` function, e.g. (simplified):
```
iOEventData data = Data(instance);
data->posted = True;
```

#### Example: One of the classes in the *rocs* lib is the `Event` class.
The class is defined in the XML file like this:
```
<object name="Event" remark="Event semaphore.">
  <fun name="inst" vt="this" remark="Object creator.">
    <param name="name" vt="const char*" remark="Event name."/>
    <param name="create" vt="Boolean" remark="Create event if not exist."/>
  </fun>
  <fun name="trywait" vt="Boolean" remark="Wait a given time for event to become posted.">
    <param name="inst" vt="this" remark="Event instance."/>
    <param name="time" vt="int" unit="ms" remark="Time to wait in ms."/>
  </fun>
  <fun name="wait" vt="Boolean" remark="Wait for event to become posted.">
    <param name="inst" vt="this" remark="Event instance."/>
  </fun>
  <fun name="set" vt="Boolean" remark="Set the event.">
    <param name="inst" vt="this" remark="Event instance."/>
  </fun>
  <fun name="reset" vt="Boolean" remark="Reset the event.">
    <param name="inst" vt="this" remark="Event instance."/>
  </fun>
  <data>
    <var name="name" vt="char*" remark="Event name."/>
    <var name="handle" vt="void*" remark="Event handle."/>
    <var name="posted" vt="Boolean" remark=""/>
  </data>
</object>
```
The *ogen* generator produces the following output from it (shortened to show the
principle). The first is the header containing the `struct` declaration and an
instance of that. While the structure could be considered the equivalent of a C++
class declaration in this concept, the actual class is that instance of the struct.
It is declared `extern` because it is defined and initialized in the `.fm` file.

```
// file: rocs/public/event.h
typedef struct OEvent {
  /***** Base *****/
  struct OBase  base;

  /***** Object: Event *****/
  /** Object creator. */
  struct OEvent* (*inst)( const char* name ,Boolean create );
  /** Reset the event. */
  Boolean (*reset)( struct OEvent* inst );
  /** Set the event. */
  Boolean (*set)( struct OEvent* inst );
  /** Wait a given time for event to become posted. */
  Boolean (*trywait)( struct OEvent* inst ,int time );
  /** Wait for event to become posted. */
  Boolean (*wait)( struct OEvent* inst );
} *iOEvent;

extern struct OEvent EventOp;
```
Then, there is the file containing the struct for the member attributes and the
getter function that returns a pointer to this struct of a certain instance.
Also here the `struct` contains comments filled with the content of the XML's
`remark` attribute. These comments are skipped here.
```
// file: impl/event_impl.h
#include "rocs/public/event.h"

static const char* name = "OEvent";

typedef struct OEventData {
  char* name;
  void* handle;
  Boolean posted;

} *iOEventData;

static iOEventData Data( void* p ) { return (iOEventData)((iOEvent)p)->base.data; }
```
The `.c` file contains the implementation of the class' methods. The generated
file might have served as a starting point once a new class was introduced. Except
for the `__del()` and `_inst()` methods, all the other methods are just empty and
have implementations in the related file from the source tree. They all follow the
pattern of the name defined in the class struct prepended by 1 or 2 '_'. The
implementation always includes the related `.fm` file in the end.
```
#include "rocs/impl/event_impl.h"

static void __del( void* inst ) {
  if( inst != NULL ) {
    iOEventData data = Data(inst);
    /* Cleanup data->xxx members...*/

    freeMem( data );
    freeMem( inst );
    instCnt--;
  }
  return;
}

static struct OEvent* _inst( const char* name ,Boolean create ) {
  iOEvent __Event = allocMem( sizeof( struct OEvent ) );
  iOEventData data = allocMem( sizeof( struct OEventData ) );
  MemOp.basecpy( __Event, &EventOp, 0, sizeof( struct OEvent ), data );

  /* Initialize data->xxx members... */

  instCnt++;
  return __Event;
}
/* ----- DO NOT REMOVE OR EDIT THIS INCLUDE LINE! -----*/
#include "rocs/impl/event.fm"
/* ----- DO NOT REMOVE OR EDIT THIS INCLUDE LINE! -----*/
```
The `.fm` file puts the class together. It creates an instance of the generated
struct and initializes the members (function pointers) with the functions from
the `.c` file. The first member of the struct is of type `struct OBase`, which
is considered the base class. This gets initialized by the inner `{}` block. The
result is the instance that is declared as `extern` reference in the header that
declares the class.
```
struct OEvent EventOp = {
  {
    NULL,
    __del,
    __name,
    __serialize,
    __deserialize,
    __toString,
    __count,
    __clone,
    __equals,
    __properties,
    __id,
    __event,
  },
  _inst,
  _reset,
  _set,
  _trywait,
  _wait,
};
```

### wgen

### png2wx

### xml2cstr
