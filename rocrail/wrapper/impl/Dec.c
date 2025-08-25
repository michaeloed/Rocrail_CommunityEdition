/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:35 2018
  */

#include "rocrail/wrapper/public/Dec.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.Dec
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_dec = {
  "dec",  "DCC Decoder definition.",  False,  "n",
};

static const char* _node_name(void) {
  return RocsWgen_dec.name;
}
static const char* _node_remark(void) {
  return RocsWgen_dec.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_dec.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_dec.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * addr
 */
static struct __attrdef RocsWgen_addr = {
  "addr",  "",  "",  "int",  "0",  "0-255",  True,
};
static int _getaddr(iONode node) {
  int defval = xInt( RocsWgen_addr );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_dec, node );
  return NodeOp.getInt( node, "addr", defval );
}
static void _setaddr(iONode node, int p_addr) {
  if( node == NULL ) return;
  xNode( RocsWgen_dec, node );
  NodeOp.setInt( node, "addr", p_addr );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * bus
 */
static struct __attrdef RocsWgen_bus = {
  "bus",  "",  "",  "int",  "0",  "0-*",  False,
};
static int _getbus(iONode node) {
  int defval = xInt( RocsWgen_bus );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_dec, node );
  return NodeOp.getInt( node, "bus", defval );
}
static void _setbus(iONode node, int p_bus) {
  if( node == NULL ) return;
  xNode( RocsWgen_dec, node );
  NodeOp.setInt( node, "bus", p_bus );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * catnr
 */
static struct __attrdef RocsWgen_catnr = {
  "catnr",  "Catalog number.",  "",  "string",  "",  "*",  False,
};
static const char* _getcatnr(iONode node) {
  const char* defval = xStr( RocsWgen_catnr );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_dec, node );
  return NodeOp.getStr( node, "catnr", defval );
}
static void _setcatnr(iONode node, const char* p_catnr) {
  if( node == NULL ) return;
  xNode( RocsWgen_dec, node );
  NodeOp.setStr( node, "catnr", p_catnr );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * decfile
 */
static struct __attrdef RocsWgen_decfile = {
  "decfile",  "Decoder definition file.",  "",  "string",  "nmra-rp922-acc.xml",  "*",  False,
};
static const char* _getdecfile(iONode node) {
  const char* defval = xStr( RocsWgen_decfile );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_dec, node );
  return NodeOp.getStr( node, "decfile", defval );
}
static void _setdecfile(iONode node, const char* p_decfile) {
  if( node == NULL ) return;
  xNode( RocsWgen_dec, node );
  NodeOp.setStr( node, "decfile", p_decfile );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * desc
 */
static struct __attrdef RocsWgen_desc = {
  "desc",  "Description of loc.",  "",  "string",  "",  "*",  False,
};
static const char* _getdesc(iONode node) {
  const char* defval = xStr( RocsWgen_desc );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_dec, node );
  return NodeOp.getStr( node, "desc", defval );
}
static void _setdesc(iONode node, const char* p_desc) {
  if( node == NULL ) return;
  xNode( RocsWgen_dec, node );
  NodeOp.setStr( node, "desc", p_desc );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * docu
 */
static struct __attrdef RocsWgen_docu = {
  "docu",  "",  "",  "string",  "http://",  "*",  False,
};
static const char* _getdocu(iONode node) {
  const char* defval = xStr( RocsWgen_docu );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_dec, node );
  return NodeOp.getStr( node, "docu", defval );
}
static void _setdocu(iONode node, const char* p_docu) {
  if( node == NULL ) return;
  xNode( RocsWgen_dec, node );
  NodeOp.setStr( node, "docu", p_docu );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * id
 */
static struct __attrdef RocsWgen_id = {
  "id",  "",  "",  "string",  "",  "*",  True,
};
static const char* _getid(iONode node) {
  const char* defval = xStr( RocsWgen_id );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_dec, node );
  return NodeOp.getStr( node, "id", defval );
}
static void _setid(iONode node, const char* p_id) {
  if( node == NULL ) return;
  xNode( RocsWgen_dec, node );
  NodeOp.setStr( node, "id", p_id );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * iid
 */
static struct __attrdef RocsWgen_iid = {
  "iid",  "Interface ID.",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getiid(iONode node) {
  const char* defval = xStr( RocsWgen_iid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_dec, node );
  return NodeOp.getStr( node, "iid", defval );
}
static void _setiid(iONode node, const char* p_iid) {
  if( node == NULL ) return;
  xNode( RocsWgen_dec, node );
  NodeOp.setStr( node, "iid", p_iid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * image
 */
static struct __attrdef RocsWgen_image = {
  "image",  "decoder image file",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getimage(iONode node) {
  const char* defval = xStr( RocsWgen_image );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_dec, node );
  return NodeOp.getStr( node, "image", defval );
}
static void _setimage(iONode node, const char* p_image) {
  if( node == NULL ) return;
  xNode( RocsWgen_dec, node );
  NodeOp.setStr( node, "image", p_image );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * manu
 */
static struct __attrdef RocsWgen_manu = {
  "manu",  "Manufacturer.",  "",  "string",  "",  "*",  False,
};
static const char* _getmanu(iONode node) {
  const char* defval = xStr( RocsWgen_manu );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_dec, node );
  return NodeOp.getStr( node, "manu", defval );
}
static void _setmanu(iONode node, const char* p_manu) {
  if( node == NULL ) return;
  xNode( RocsWgen_dec, node );
  NodeOp.setStr( node, "manu", p_manu );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * prev_id
 */
static struct __attrdef RocsWgen_prev_id = {
  "prev_id",  "in case of an id change this should help to find the original in the loc table",  "",  "string",  "",  "*",  False,
};
static const char* _getprev_id(iONode node) {
  const char* defval = xStr( RocsWgen_prev_id );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_dec, node );
  return NodeOp.getStr( node, "prev_id", defval );
}
static void _setprev_id(iONode node, const char* p_prev_id) {
  if( node == NULL ) return;
  xNode( RocsWgen_dec, node );
  NodeOp.setStr( node, "prev_id", p_prev_id );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * prot
 */
static struct __attrdef RocsWgen_prot = {
  "prot",  "",  "",  "string",  "P",  "*",  False,
};
static const char* _getprot(iONode node) {
  const char* defval = xStr( RocsWgen_prot );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_dec, node );
  return NodeOp.getStr( node, "prot", defval );
}
static void _setprot(iONode node, const char* p_prot) {
  if( node == NULL ) return;
  xNode( RocsWgen_dec, node );
  NodeOp.setStr( node, "prot", p_prot );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * protver
 */
static struct __attrdef RocsWgen_protver = {
  "protver",  "Protocol version",  "",  "int",  "1",  "*",  False,
};
static int _getprotver(iONode node) {
  int defval = xInt( RocsWgen_protver );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_dec, node );
  return NodeOp.getInt( node, "protver", defval );
}
static void _setprotver(iONode node, int p_protver) {
  if( node == NULL ) return;
  xNode( RocsWgen_dec, node );
  NodeOp.setInt( node, "protver", p_protver );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * cvbyte
 */
static struct __nodedef RocsWgen_cvbyte = {
  "cvbyte",  "",  False,  "n",};
static iONode _getcvbyte(iONode node) {
  xNode( RocsWgen_dec, node );
  return NodeOp.findNode( node, "cvbyte");
}


static iONode _nextcvbyte(iONode node, iONode child) {
  xNode( RocsWgen_dec, node );
  return NodeOp.findNextNode( node, child);
}
static void _setcvbyte(iONode node, iONode p_cvbyte) {
  xNode( RocsWgen_dec, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[14] = {NULL};
static struct __nodedef* nodeList[2] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_dec.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node dec not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node dec not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_addr;
  attrList[1] = &RocsWgen_bus;
  attrList[2] = &RocsWgen_catnr;
  attrList[3] = &RocsWgen_decfile;
  attrList[4] = &RocsWgen_desc;
  attrList[5] = &RocsWgen_docu;
  attrList[6] = &RocsWgen_id;
  attrList[7] = &RocsWgen_iid;
  attrList[8] = &RocsWgen_image;
  attrList[9] = &RocsWgen_manu;
  attrList[10] = &RocsWgen_prev_id;
  attrList[11] = &RocsWgen_prot;
  attrList[12] = &RocsWgen_protver;
  attrList[13] = NULL;
  nodeList[0] = &RocsWgen_cvbyte;
  nodeList[1] = NULL;
  {
    int i = 0;
    Boolean err = False;
    xAttrTest( attrList, node );
    xNodeTest( nodeList, node );
    while( attrList[i] ) {
      err |= !xAttr( attrList[i], node );
      i++;
    };
    return !err;
  }
  
}


struct __wDec wDec = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getaddr,
  _setaddr,
  _getbus,
  _setbus,
  _getcatnr,
  _setcatnr,
  _getdecfile,
  _setdecfile,
  _getdesc,
  _setdesc,
  _getdocu,
  _setdocu,
  _getid,
  _setid,
  _getiid,
  _setiid,
  _getimage,
  _setimage,
  _getmanu,
  _setmanu,
  _getprev_id,
  _setprev_id,
  _getprot,
  _setprot,
  _getprotver,
  _setprotver,
  _getcvbyte,
  _nextcvbyte,
  _setcvbyte,
  _node_dump,
};
