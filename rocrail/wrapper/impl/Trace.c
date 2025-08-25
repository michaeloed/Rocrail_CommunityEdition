/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/Trace.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.Trace
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_trace = {
  "trace",  "",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_trace.name;
}
static const char* _node_remark(void) {
  return RocsWgen_trace.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_trace.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_trace.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * automatic
 */
static struct __attrdef RocsWgen_automatic = {
  "automatic",  "Trace level for extra info in automatic mode.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isautomatic(iONode node) {
  Boolean defval = xBool( RocsWgen_automatic );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_trace, node );
  return NodeOp.getBool( node, "automatic", defval );
}
static void _setautomatic(iONode node, Boolean p_automatic) {
  if( node == NULL ) return;
  xNode( RocsWgen_trace, node );
  NodeOp.setBool( node, "automatic", p_automatic );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * byte
 */
static struct __attrdef RocsWgen_byte = {
  "byte",  "Activates dump tracelevel.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isbyte(iONode node) {
  Boolean defval = xBool( RocsWgen_byte );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_trace, node );
  return NodeOp.getBool( node, "byte", defval );
}
static void _setbyte(iONode node, Boolean p_byte) {
  if( node == NULL ) return;
  xNode( RocsWgen_trace, node );
  NodeOp.setBool( node, "byte", p_byte );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * calc
 */
static struct __attrdef RocsWgen_calc = {
  "calc",  "Activates calculation trace level.",  "",  "bool",  "true",  "*",  False,
};
static Boolean _iscalc(iONode node) {
  Boolean defval = xBool( RocsWgen_calc );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_trace, node );
  return NodeOp.getBool( node, "calc", defval );
}
static void _setcalc(iONode node, Boolean p_calc) {
  if( node == NULL ) return;
  xNode( RocsWgen_trace, node );
  NodeOp.setBool( node, "calc", p_calc );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * debug
 */
static struct __attrdef RocsWgen_debug = {
  "debug",  "Trace level debug.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isdebug(iONode node) {
  Boolean defval = xBool( RocsWgen_debug );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_trace, node );
  return NodeOp.getBool( node, "debug", defval );
}
static void _setdebug(iONode node, Boolean p_debug) {
  if( node == NULL ) return;
  xNode( RocsWgen_trace, node );
  NodeOp.setBool( node, "debug", p_debug );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * dumpsize
 */
static struct __attrdef RocsWgen_dumpsize = {
  "dumpsize",  "Max. byte dump size.",  "byte",  "int",  "128",  "16-*",  False,
};
static int _getdumpsize(iONode node) {
  int defval = xInt( RocsWgen_dumpsize );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_trace, node );
  return NodeOp.getInt( node, "dumpsize", defval );
}
static void _setdumpsize(iONode node, int p_dumpsize) {
  if( node == NULL ) return;
  xNode( RocsWgen_trace, node );
  NodeOp.setInt( node, "dumpsize", p_dumpsize );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * exceptionfile
 */
static struct __attrdef RocsWgen_exceptionfile = {
  "exceptionfile",  "Create extra file for exceptions.",  "",  "bool",  "false",  "*",  False,
};
static Boolean _isexceptionfile(iONode node) {
  Boolean defval = xBool( RocsWgen_exceptionfile );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_trace, node );
  return NodeOp.getBool( node, "exceptionfile", defval );
}
static void _setexceptionfile(iONode node, Boolean p_exceptionfile) {
  if( node == NULL ) return;
  xNode( RocsWgen_trace, node );
  NodeOp.setBool( node, "exceptionfile", p_exceptionfile );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * gfile
 */
static struct __attrdef RocsWgen_gfile = {
  "gfile",  "",  "",  "string",  "rocview",  "",  False,
};
static const char* _getgfile(iONode node) {
  const char* defval = xStr( RocsWgen_gfile );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_trace, node );
  return NodeOp.getStr( node, "gfile", defval );
}
static void _setgfile(iONode node, const char* p_gfile) {
  if( node == NULL ) return;
  xNode( RocsWgen_trace, node );
  NodeOp.setStr( node, "gfile", p_gfile );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * info
 */
static struct __attrdef RocsWgen_info = {
  "info",  "Activates info trace level.",  "",  "bool",  "true",  "*",  False,
};
static Boolean _isinfo(iONode node) {
  Boolean defval = xBool( RocsWgen_info );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_trace, node );
  return NodeOp.getBool( node, "info", defval );
}
static void _setinfo(iONode node, Boolean p_info) {
  if( node == NULL ) return;
  xNode( RocsWgen_trace, node );
  NodeOp.setBool( node, "info", p_info );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * invoke
 */
static struct __attrdef RocsWgen_invoke = {
  "invoke",  "External program or script to invoke on exception file creation.",  "",  "string",  "./xmail.pl",  "*",  False,
};
static const char* _getinvoke(iONode node) {
  const char* defval = xStr( RocsWgen_invoke );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_trace, node );
  return NodeOp.getStr( node, "invoke", defval );
}
static void _setinvoke(iONode node, const char* p_invoke) {
  if( node == NULL ) return;
  xNode( RocsWgen_trace, node );
  NodeOp.setStr( node, "invoke", p_invoke );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * invokeasync
 */
static struct __attrdef RocsWgen_invokeasync = {
  "invokeasync",  "The invokation will take place in a separate thread.",  "",  "bool",  "false",  "*",  False,
};
static Boolean _isinvokeasync(iONode node) {
  Boolean defval = xBool( RocsWgen_invokeasync );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_trace, node );
  return NodeOp.getBool( node, "invokeasync", defval );
}
static void _setinvokeasync(iONode node, Boolean p_invokeasync) {
  if( node == NULL ) return;
  xNode( RocsWgen_trace, node );
  NodeOp.setBool( node, "invokeasync", p_invokeasync );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * listen2all
 */
static struct __attrdef RocsWgen_listen2all = {
  "listen2all",  "The trace listener will get all traces.",  "",  "bool",  "false",  "",  False,
};
static Boolean _islisten2all(iONode node) {
  Boolean defval = xBool( RocsWgen_listen2all );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_trace, node );
  return NodeOp.getBool( node, "listen2all", defval );
}
static void _setlisten2all(iONode node, Boolean p_listen2all) {
  if( node == NULL ) return;
  xNode( RocsWgen_trace, node );
  NodeOp.setBool( node, "listen2all", p_listen2all );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * meminfo
 */
static struct __attrdef RocsWgen_meminfo = {
  "meminfo",  "Activates memory info trace level.",  "",  "bool",  "false",  "*",  False,
};
static Boolean _ismeminfo(iONode node) {
  Boolean defval = xBool( RocsWgen_meminfo );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_trace, node );
  return NodeOp.getBool( node, "meminfo", defval );
}
static void _setmeminfo(iONode node, Boolean p_meminfo) {
  if( node == NULL ) return;
  xNode( RocsWgen_trace, node );
  NodeOp.setBool( node, "meminfo", p_meminfo );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * monitor
 */
static struct __attrdef RocsWgen_monitor = {
  "monitor",  "Activates monitor tracelevel.",  "",  "bool",  "true",  "",  False,
};
static Boolean _ismonitor(iONode node) {
  Boolean defval = xBool( RocsWgen_monitor );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_trace, node );
  return NodeOp.getBool( node, "monitor", defval );
}
static void _setmonitor(iONode node, Boolean p_monitor) {
  if( node == NULL ) return;
  xNode( RocsWgen_trace, node );
  NodeOp.setBool( node, "monitor", p_monitor );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * nr
 */
static struct __attrdef RocsWgen_nr = {
  "nr",  "Number of continuous trace files. In case of 0 or 1: All traces are written in one file disregarding filesize.",  "",  "int",  "10",  "*",  False,
};
static int _getnr(iONode node) {
  int defval = xInt( RocsWgen_nr );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_trace, node );
  return NodeOp.getInt( node, "nr", defval );
}
static void _setnr(iONode node, int p_nr) {
  if( node == NULL ) return;
  xNode( RocsWgen_trace, node );
  NodeOp.setInt( node, "nr", p_nr );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * parse
 */
static struct __attrdef RocsWgen_parse = {
  "parse",  "Activates parse tracelevel.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isparse(iONode node) {
  Boolean defval = xBool( RocsWgen_parse );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_trace, node );
  return NodeOp.getBool( node, "parse", defval );
}
static void _setparse(iONode node, Boolean p_parse) {
  if( node == NULL ) return;
  xNode( RocsWgen_trace, node );
  NodeOp.setBool( node, "parse", p_parse );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * protpath
 */
static struct __attrdef RocsWgen_protpath = {
  "protpath",  "Protocol path; Where to write the trace files. (Use relative only if using http service.) Path is relative to pwd!",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getprotpath(iONode node) {
  const char* defval = xStr( RocsWgen_protpath );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_trace, node );
  return NodeOp.getStr( node, "protpath", defval );
}
static void _setprotpath(iONode node, const char* p_protpath) {
  if( node == NULL ) return;
  xNode( RocsWgen_trace, node );
  NodeOp.setStr( node, "protpath", p_protpath );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * rfile
 */
static struct __attrdef RocsWgen_rfile = {
  "rfile",  "",  "",  "string",  "rocrail",  "",  False,
};
static const char* _getrfile(iONode node) {
  const char* defval = xStr( RocsWgen_rfile );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_trace, node );
  return NodeOp.getStr( node, "rfile", defval );
}
static void _setrfile(iONode node, const char* p_rfile) {
  if( node == NULL ) return;
  xNode( RocsWgen_trace, node );
  NodeOp.setStr( node, "rfile", p_rfile );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * size
 */
static struct __attrdef RocsWgen_size = {
  "size",  "Filesize of trace files.",  "kb",  "int",  "100",  "10-*",  False,
};
static int _getsize(iONode node) {
  int defval = xInt( RocsWgen_size );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_trace, node );
  return NodeOp.getInt( node, "size", defval );
}
static void _setsize(iONode node, int p_size) {
  if( node == NULL ) return;
  xNode( RocsWgen_trace, node );
  NodeOp.setInt( node, "size", p_size );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * unique
 */
static struct __attrdef RocsWgen_unique = {
  "unique",  "Create a unique trace filename at startup.",  "",  "bool",  "false",  "*",  False,
};
static Boolean _isunique(iONode node) {
  Boolean defval = xBool( RocsWgen_unique );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_trace, node );
  return NodeOp.getBool( node, "unique", defval );
}
static void _setunique(iONode node, Boolean p_unique) {
  if( node == NULL ) return;
  xNode( RocsWgen_trace, node );
  NodeOp.setBool( node, "unique", p_unique );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[20] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_trace.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node trace not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node trace not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_automatic;
  attrList[1] = &RocsWgen_byte;
  attrList[2] = &RocsWgen_calc;
  attrList[3] = &RocsWgen_debug;
  attrList[4] = &RocsWgen_dumpsize;
  attrList[5] = &RocsWgen_exceptionfile;
  attrList[6] = &RocsWgen_gfile;
  attrList[7] = &RocsWgen_info;
  attrList[8] = &RocsWgen_invoke;
  attrList[9] = &RocsWgen_invokeasync;
  attrList[10] = &RocsWgen_listen2all;
  attrList[11] = &RocsWgen_meminfo;
  attrList[12] = &RocsWgen_monitor;
  attrList[13] = &RocsWgen_nr;
  attrList[14] = &RocsWgen_parse;
  attrList[15] = &RocsWgen_protpath;
  attrList[16] = &RocsWgen_rfile;
  attrList[17] = &RocsWgen_size;
  attrList[18] = &RocsWgen_unique;
  attrList[19] = NULL;
  nodeList[0] = NULL;
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


struct __wTrace wTrace = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _isautomatic,
  _setautomatic,
  _isbyte,
  _setbyte,
  _iscalc,
  _setcalc,
  _isdebug,
  _setdebug,
  _getdumpsize,
  _setdumpsize,
  _isexceptionfile,
  _setexceptionfile,
  _getgfile,
  _setgfile,
  _isinfo,
  _setinfo,
  _getinvoke,
  _setinvoke,
  _isinvokeasync,
  _setinvokeasync,
  _islisten2all,
  _setlisten2all,
  _ismeminfo,
  _setmeminfo,
  _ismonitor,
  _setmonitor,
  _getnr,
  _setnr,
  _isparse,
  _setparse,
  _getprotpath,
  _setprotpath,
  _getrfile,
  _setrfile,
  _getsize,
  _setsize,
  _isunique,
  _setunique,
  _node_dump,
};
