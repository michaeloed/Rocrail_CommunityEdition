/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/Weather.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.Weather
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_weather = {
  "weather",  "",  False,  "n",
};

static const char* _node_name(void) {
  return RocsWgen_weather.name;
}
static const char* _node_remark(void) {
  return RocsWgen_weather.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_weather.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_weather.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * colorsliding
 */
static struct __attrdef RocsWgen_colorsliding = {
  "colorsliding",  "Color sliding time.",  "min",  "int",  "30",  "10-120",  False,
};
static int _getcolorsliding(iONode node) {
  int defval = xInt( RocsWgen_colorsliding );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_weather, node );
  return NodeOp.getInt( node, "colorsliding", defval );
}
static void _setcolorsliding(iONode node, int p_colorsliding) {
  if( node == NULL ) return;
  xNode( RocsWgen_weather, node );
  NodeOp.setInt( node, "colorsliding", p_colorsliding );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * colortable
 */
static struct __attrdef RocsWgen_colortable = {
  "colortable",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _iscolortable(iONode node) {
  Boolean defval = xBool( RocsWgen_colortable );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_weather, node );
  return NodeOp.getBool( node, "colortable", defval );
}
static void _setcolortable(iONode node, Boolean p_colortable) {
  if( node == NULL ) return;
  xNode( RocsWgen_weather, node );
  NodeOp.setBool( node, "colortable", p_colortable );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * deactivate
 */
static struct __attrdef RocsWgen_deactivate = {
  "deactivate",  "Comma separated list of outputs to deactivate at start.",  "",  "string",  "",  "*",  False,
};
static const char* _getdeactivate(iONode node) {
  const char* defval = xStr( RocsWgen_deactivate );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_weather, node );
  return NodeOp.getStr( node, "deactivate", defval );
}
static void _setdeactivate(iONode node, const char* p_deactivate) {
  if( node == NULL ) return;
  xNode( RocsWgen_weather, node );
  NodeOp.setStr( node, "deactivate", p_deactivate );
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
  xNode( RocsWgen_weather, node );
  return NodeOp.getStr( node, "id", defval );
}
static void _setid(iONode node, const char* p_id) {
  if( node == NULL ) return;
  xNode( RocsWgen_weather, node );
  NodeOp.setStr( node, "id", p_id );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * maxbri
 */
static struct __attrdef RocsWgen_maxbri = {
  "maxbri",  "Maximal brightness.",  "",  "int",  "255",  "0-255",  False,
};
static int _getmaxbri(iONode node) {
  int defval = xInt( RocsWgen_maxbri );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_weather, node );
  return NodeOp.getInt( node, "maxbri", defval );
}
static void _setmaxbri(iONode node, int p_maxbri) {
  if( node == NULL ) return;
  xNode( RocsWgen_weather, node );
  NodeOp.setInt( node, "maxbri", p_maxbri );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * minbri
 */
static struct __attrdef RocsWgen_minbri = {
  "minbri",  "Minimal brightness.",  "",  "int",  "0",  "0-255",  False,
};
static int _getminbri(iONode node) {
  int defval = xInt( RocsWgen_minbri );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_weather, node );
  return NodeOp.getInt( node, "minbri", defval );
}
static void _setminbri(iONode node, int p_minbri) {
  if( node == NULL ) return;
  xNode( RocsWgen_weather, node );
  NodeOp.setInt( node, "minbri", p_minbri );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * nightsliding
 */
static struct __attrdef RocsWgen_nightsliding = {
  "nightsliding",  "Night sliding time.",  "min",  "int",  "30",  "1-120",  False,
};
static int _getnightsliding(iONode node) {
  int defval = xInt( RocsWgen_nightsliding );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_weather, node );
  return NodeOp.getInt( node, "nightsliding", defval );
}
static void _setnightsliding(iONode node, int p_nightsliding) {
  if( node == NULL ) return;
  xNode( RocsWgen_weather, node );
  NodeOp.setInt( node, "nightsliding", p_nightsliding );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * offatshutdown
 */
static struct __attrdef RocsWgen_offatshutdown = {
  "offatshutdown",  "",  "",  "bool",  "true",  "",  False,
};
static Boolean _isoffatshutdown(iONode node) {
  Boolean defval = xBool( RocsWgen_offatshutdown );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_weather, node );
  return NodeOp.getBool( node, "offatshutdown", defval );
}
static void _setoffatshutdown(iONode node, Boolean p_offatshutdown) {
  if( node == NULL ) return;
  xNode( RocsWgen_weather, node );
  NodeOp.setBool( node, "offatshutdown", p_offatshutdown );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * outputs
 */
static struct __attrdef RocsWgen_outputs = {
  "outputs",  "Comma separated list of outputs from east to west.",  "",  "string",  "",  "*",  False,
};
static const char* _getoutputs(iONode node) {
  const char* defval = xStr( RocsWgen_outputs );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_weather, node );
  return NodeOp.getStr( node, "outputs", defval );
}
static void _setoutputs(iONode node, const char* p_outputs) {
  if( node == NULL ) return;
  xNode( RocsWgen_weather, node );
  NodeOp.setStr( node, "outputs", p_outputs );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * relativetime
 */
static struct __attrdef RocsWgen_relativetime = {
  "relativetime",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isrelativetime(iONode node) {
  Boolean defval = xBool( RocsWgen_relativetime );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_weather, node );
  return NodeOp.getBool( node, "relativetime", defval );
}
static void _setrelativetime(iONode node, Boolean p_relativetime) {
  if( node == NULL ) return;
  xNode( RocsWgen_weather, node );
  NodeOp.setBool( node, "relativetime", p_relativetime );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * slidingdaylight
 */
static struct __attrdef RocsWgen_slidingdaylight = {
  "slidingdaylight",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isslidingdaylight(iONode node) {
  Boolean defval = xBool( RocsWgen_slidingdaylight );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_weather, node );
  return NodeOp.getBool( node, "slidingdaylight", defval );
}
static void _setslidingdaylight(iONode node, Boolean p_slidingdaylight) {
  if( node == NULL ) return;
  xNode( RocsWgen_weather, node );
  NodeOp.setBool( node, "slidingdaylight", p_slidingdaylight );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * usebri
 */
static struct __attrdef RocsWgen_usebri = {
  "usebri",  "",  "",  "bool",  "true",  "",  False,
};
static Boolean _isusebri(iONode node) {
  Boolean defval = xBool( RocsWgen_usebri );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_weather, node );
  return NodeOp.getBool( node, "usebri", defval );
}
static void _setusebri(iONode node, Boolean p_usebri) {
  if( node == NULL ) return;
  xNode( RocsWgen_weather, node );
  NodeOp.setBool( node, "usebri", p_usebri );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * usesat
 */
static struct __attrdef RocsWgen_usesat = {
  "usesat",  "",  "",  "bool",  "true",  "",  False,
};
static Boolean _isusesat(iONode node) {
  Boolean defval = xBool( RocsWgen_usesat );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_weather, node );
  return NodeOp.getBool( node, "usesat", defval );
}
static void _setusesat(iONode node, Boolean p_usesat) {
  if( node == NULL ) return;
  xNode( RocsWgen_weather, node );
  NodeOp.setBool( node, "usesat", p_usesat );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * usewhite
 */
static struct __attrdef RocsWgen_usewhite = {
  "usewhite",  "",  "",  "bool",  "true",  "",  False,
};
static Boolean _isusewhite(iONode node) {
  Boolean defval = xBool( RocsWgen_usewhite );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_weather, node );
  return NodeOp.getBool( node, "usewhite", defval );
}
static void _setusewhite(iONode node, Boolean p_usewhite) {
  if( node == NULL ) return;
  xNode( RocsWgen_weather, node );
  NodeOp.setBool( node, "usewhite", p_usewhite );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * usewhite2
 */
static struct __attrdef RocsWgen_usewhite2 = {
  "usewhite2",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isusewhite2(iONode node) {
  Boolean defval = xBool( RocsWgen_usewhite2 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_weather, node );
  return NodeOp.getBool( node, "usewhite2", defval );
}
static void _setusewhite2(iONode node, Boolean p_usewhite2) {
  if( node == NULL ) return;
  xNode( RocsWgen_weather, node );
  NodeOp.setBool( node, "usewhite2", p_usewhite2 );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * sunrise
 */
static struct __nodedef RocsWgen_sunrise = {
  "sunrise",  "Sunrise definition",  False,  "1",};
static iONode _getsunrise(iONode node) {
  xNode( RocsWgen_weather, node );
  return NodeOp.findNode( node, "sunrise");
}


static iONode _nextsunrise(iONode node, iONode child) {
  xNode( RocsWgen_weather, node );
  return NodeOp.findNextNode( node, child);
}
static void _setsunrise(iONode node, iONode p_sunrise) {
  xNode( RocsWgen_weather, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * noon
 */
static struct __nodedef RocsWgen_noon = {
  "noon",  "Noon definition",  False,  "1",};
static iONode _getnoon(iONode node) {
  xNode( RocsWgen_weather, node );
  return NodeOp.findNode( node, "noon");
}


static iONode _nextnoon(iONode node, iONode child) {
  xNode( RocsWgen_weather, node );
  return NodeOp.findNextNode( node, child);
}
static void _setnoon(iONode node, iONode p_noon) {
  xNode( RocsWgen_weather, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * sunset
 */
static struct __nodedef RocsWgen_sunset = {
  "sunset",  "Sunset definition",  False,  "1",};
static iONode _getsunset(iONode node) {
  xNode( RocsWgen_weather, node );
  return NodeOp.findNode( node, "sunset");
}


static iONode _nextsunset(iONode node, iONode child) {
  xNode( RocsWgen_weather, node );
  return NodeOp.findNextNode( node, child);
}
static void _setsunset(iONode node, iONode p_sunset) {
  xNode( RocsWgen_weather, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * night
 */
static struct __nodedef RocsWgen_night = {
  "night",  "Night definition",  False,  "1",};
static iONode _getnight(iONode node) {
  xNode( RocsWgen_weather, node );
  return NodeOp.findNode( node, "night");
}


static iONode _nextnight(iONode node, iONode child) {
  xNode( RocsWgen_weather, node );
  return NodeOp.findNextNode( node, child);
}
static void _setnight(iONode node, iONode p_night) {
  xNode( RocsWgen_weather, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * weathercolor
 */
static struct __nodedef RocsWgen_weathercolor = {
  "weathercolor",  "Hourly color definition",  False,  "n",};
static iONode _getweathercolor(iONode node) {
  xNode( RocsWgen_weather, node );
  return NodeOp.findNode( node, "weathercolor");
}


static iONode _nextweathercolor(iONode node, iONode child) {
  xNode( RocsWgen_weather, node );
  return NodeOp.findNextNode( node, child);
}
static void _setweathercolor(iONode node, iONode p_weathercolor) {
  xNode( RocsWgen_weather, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * weathertheme
 */
static struct __nodedef RocsWgen_weathertheme = {
  "weathertheme",  "",  False,  "n",};
static iONode _getweathertheme(iONode node) {
  xNode( RocsWgen_weather, node );
  return NodeOp.findNode( node, "weathertheme");
}


static iONode _nextweathertheme(iONode node, iONode child) {
  xNode( RocsWgen_weather, node );
  return NodeOp.findNextNode( node, child);
}
static void _setweathertheme(iONode node, iONode p_weathertheme) {
  xNode( RocsWgen_weather, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * actionctrl
 */
static struct __nodedef RocsWgen_actionctrl = {
  "actionctrl",  "",  False,  "n",};
static iONode _getactionctrl(iONode node) {
  xNode( RocsWgen_weather, node );
  return NodeOp.findNode( node, "actionctrl");
}


static iONode _nextactionctrl(iONode node, iONode child) {
  xNode( RocsWgen_weather, node );
  return NodeOp.findNextNode( node, child);
}
static void _setactionctrl(iONode node, iONode p_actionctrl) {
  xNode( RocsWgen_weather, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[16] = {NULL};
static struct __nodedef* nodeList[8] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_weather.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node weather not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node weather not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_colorsliding;
  attrList[1] = &RocsWgen_colortable;
  attrList[2] = &RocsWgen_deactivate;
  attrList[3] = &RocsWgen_id;
  attrList[4] = &RocsWgen_maxbri;
  attrList[5] = &RocsWgen_minbri;
  attrList[6] = &RocsWgen_nightsliding;
  attrList[7] = &RocsWgen_offatshutdown;
  attrList[8] = &RocsWgen_outputs;
  attrList[9] = &RocsWgen_relativetime;
  attrList[10] = &RocsWgen_slidingdaylight;
  attrList[11] = &RocsWgen_usebri;
  attrList[12] = &RocsWgen_usesat;
  attrList[13] = &RocsWgen_usewhite;
  attrList[14] = &RocsWgen_usewhite2;
  attrList[15] = NULL;
  nodeList[0] = &RocsWgen_sunrise;
  nodeList[1] = &RocsWgen_noon;
  nodeList[2] = &RocsWgen_sunset;
  nodeList[3] = &RocsWgen_night;
  nodeList[4] = &RocsWgen_weathercolor;
  nodeList[5] = &RocsWgen_weathertheme;
  nodeList[6] = &RocsWgen_actionctrl;
  nodeList[7] = NULL;
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


struct __wWeather wWeather = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getcolorsliding,
  _setcolorsliding,
  _iscolortable,
  _setcolortable,
  _getdeactivate,
  _setdeactivate,
  _getid,
  _setid,
  _getmaxbri,
  _setmaxbri,
  _getminbri,
  _setminbri,
  _getnightsliding,
  _setnightsliding,
  _isoffatshutdown,
  _setoffatshutdown,
  _getoutputs,
  _setoutputs,
  _isrelativetime,
  _setrelativetime,
  _isslidingdaylight,
  _setslidingdaylight,
  _isusebri,
  _setusebri,
  _isusesat,
  _setusesat,
  _isusewhite,
  _setusewhite,
  _isusewhite2,
  _setusewhite2,
  _getsunrise,
  _nextsunrise,
  _setsunrise,
  _getnoon,
  _nextnoon,
  _setnoon,
  _getsunset,
  _nextsunset,
  _setsunset,
  _getnight,
  _nextnight,
  _setnight,
  _getweathercolor,
  _nextweathercolor,
  _setweathercolor,
  _getweathertheme,
  _nextweathertheme,
  _setweathertheme,
  _getactionctrl,
  _nextactionctrl,
  _setactionctrl,
  _node_dump,
};
