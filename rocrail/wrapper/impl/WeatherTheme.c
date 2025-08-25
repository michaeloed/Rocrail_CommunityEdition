/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/WeatherTheme.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.WeatherTheme
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_weathertheme = {
  "weathertheme",  "",  False,  "n",
};

static const char* _node_name(void) {
  return RocsWgen_weathertheme.name;
}
static const char* _node_remark(void) {
  return RocsWgen_weathertheme.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_weathertheme.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_weathertheme.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * dim
 */
static struct __attrdef RocsWgen_dim = {
  "dim",  "",  "%",  "int",  "0",  "0-100",  False,
};
static int _getdim(iONode node) {
  int defval = xInt( RocsWgen_dim );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_weathertheme, node );
  return NodeOp.getInt( node, "dim", defval );
}
static void _setdim(iONode node, int p_dim) {
  if( node == NULL ) return;
  xNode( RocsWgen_weathertheme, node );
  NodeOp.setInt( node, "dim", p_dim );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * duration
 */
static struct __attrdef RocsWgen_duration = {
  "duration",  "",  "",  "int",  "20",  "10-1440",  False,
};
static int _getduration(iONode node) {
  int defval = xInt( RocsWgen_duration );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_weathertheme, node );
  return NodeOp.getInt( node, "duration", defval );
}
static void _setduration(iONode node, int p_duration) {
  if( node == NULL ) return;
  xNode( RocsWgen_weathertheme, node );
  NodeOp.setInt( node, "duration", p_duration );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * hour
 */
static struct __attrdef RocsWgen_hour = {
  "hour",  "",  "",  "int",  "0",  "0-23",  False,
};
static int _gethour(iONode node) {
  int defval = xInt( RocsWgen_hour );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_weathertheme, node );
  return NodeOp.getInt( node, "hour", defval );
}
static void _sethour(iONode node, int p_hour) {
  if( node == NULL ) return;
  xNode( RocsWgen_weathertheme, node );
  NodeOp.setInt( node, "hour", p_hour );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * id
 */
static struct __attrdef RocsWgen_id = {
  "id",  "",  "",  "string",  "",  "*",  False,
};
static const char* _getid(iONode node) {
  const char* defval = xStr( RocsWgen_id );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_weathertheme, node );
  return NodeOp.getStr( node, "id", defval );
}
static void _setid(iONode node, const char* p_id) {
  if( node == NULL ) return;
  xNode( RocsWgen_weathertheme, node );
  NodeOp.setStr( node, "id", p_id );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * minute
 */
static struct __attrdef RocsWgen_minute = {
  "minute",  "",  "",  "int",  "0",  "0-59",  False,
};
static int _getminute(iONode node) {
  int defval = xInt( RocsWgen_minute );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_weathertheme, node );
  return NodeOp.getInt( node, "minute", defval );
}
static void _setminute(iONode node, int p_minute) {
  if( node == NULL ) return;
  xNode( RocsWgen_weathertheme, node );
  NodeOp.setInt( node, "minute", p_minute );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * outputs
 */
static struct __attrdef RocsWgen_outputs = {
  "outputs",  "Comma separated list of outputs from lightning.",  "",  "string",  "",  "*",  False,
};
static const char* _getoutputs(iONode node) {
  const char* defval = xStr( RocsWgen_outputs );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_weathertheme, node );
  return NodeOp.getStr( node, "outputs", defval );
}
static void _setoutputs(iONode node, const char* p_outputs) {
  if( node == NULL ) return;
  xNode( RocsWgen_weathertheme, node );
  NodeOp.setStr( node, "outputs", p_outputs );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * random
 */
static struct __attrdef RocsWgen_random = {
  "random",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _israndom(iONode node) {
  Boolean defval = xBool( RocsWgen_random );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_weathertheme, node );
  return NodeOp.getBool( node, "random", defval );
}
static void _setrandom(iONode node, Boolean p_random) {
  if( node == NULL ) return;
  xNode( RocsWgen_weathertheme, node );
  NodeOp.setBool( node, "random", p_random );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * sound
 */
static struct __attrdef RocsWgen_sound = {
  "sound",  "Comma separated list of sounds.",  "",  "string",  "",  "*",  False,
};
static const char* _getsound(iONode node) {
  const char* defval = xStr( RocsWgen_sound );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_weathertheme, node );
  return NodeOp.getStr( node, "sound", defval );
}
static void _setsound(iONode node, const char* p_sound) {
  if( node == NULL ) return;
  xNode( RocsWgen_weathertheme, node );
  NodeOp.setStr( node, "sound", p_sound );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * soundoutput
 */
static struct __attrdef RocsWgen_soundoutput = {
  "soundoutput",  "Sound output",  "",  "string",  "",  "*",  False,
};
static const char* _getsoundoutput(iONode node) {
  const char* defval = xStr( RocsWgen_soundoutput );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_weathertheme, node );
  return NodeOp.getStr( node, "soundoutput", defval );
}
static void _setsoundoutput(iONode node, const char* p_soundoutput) {
  if( node == NULL ) return;
  xNode( RocsWgen_weathertheme, node );
  NodeOp.setStr( node, "soundoutput", p_soundoutput );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * soundrandomrate
 */
static struct __attrdef RocsWgen_soundrandomrate = {
  "soundrandomrate",  "",  "",  "int",  "5",  "0-9",  False,
};
static int _getsoundrandomrate(iONode node) {
  int defval = xInt( RocsWgen_soundrandomrate );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_weathertheme, node );
  return NodeOp.getInt( node, "soundrandomrate", defval );
}
static void _setsoundrandomrate(iONode node, int p_soundrandomrate) {
  if( node == NULL ) return;
  xNode( RocsWgen_weathertheme, node );
  NodeOp.setInt( node, "soundrandomrate", p_soundrandomrate );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[11] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_weathertheme.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node weathertheme not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node weathertheme not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_dim;
  attrList[1] = &RocsWgen_duration;
  attrList[2] = &RocsWgen_hour;
  attrList[3] = &RocsWgen_id;
  attrList[4] = &RocsWgen_minute;
  attrList[5] = &RocsWgen_outputs;
  attrList[6] = &RocsWgen_random;
  attrList[7] = &RocsWgen_sound;
  attrList[8] = &RocsWgen_soundoutput;
  attrList[9] = &RocsWgen_soundrandomrate;
  attrList[10] = NULL;
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


struct __wWeatherTheme wWeatherTheme = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getdim,
  _setdim,
  _getduration,
  _setduration,
  _gethour,
  _sethour,
  _getid,
  _setid,
  _getminute,
  _setminute,
  _getoutputs,
  _setoutputs,
  _israndom,
  _setrandom,
  _getsound,
  _setsound,
  _getsoundoutput,
  _setsoundoutput,
  _getsoundrandomrate,
  _setsoundrandomrate,
  _node_dump,
};
