/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/WeatherList.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.WeatherList
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_weatherlist = {
  "weatherlist",  "",  False,  "n",
};

static const char* _node_name(void) {
  return RocsWgen_weatherlist.name;
}
static const char* _node_remark(void) {
  return RocsWgen_weatherlist.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_weatherlist.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_weatherlist.cardinality;
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * weather
 */
static struct __nodedef RocsWgen_weather = {
  "weather",  "",  False,  "n",};
static iONode _getweather(iONode node) {
  xNode( RocsWgen_weatherlist, node );
  return NodeOp.findNode( node, "weather");
}


static iONode _nextweather(iONode node, iONode child) {
  xNode( RocsWgen_weatherlist, node );
  return NodeOp.findNextNode( node, child);
}
static void _setweather(iONode node, iONode p_weather) {
  xNode( RocsWgen_weatherlist, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[1] = {NULL};
static struct __nodedef* nodeList[2] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_weatherlist.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node weatherlist not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node weatherlist not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = NULL;
  nodeList[0] = &RocsWgen_weather;
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


struct __wWeatherList wWeatherList = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getweather,
  _nextweather,
  _setweather,
  _node_dump,
};
