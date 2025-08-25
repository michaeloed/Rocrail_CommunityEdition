/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/Color.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.Color
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_color = {
  "color",  "",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_color.name;
}
static const char* _node_remark(void) {
  return RocsWgen_color.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_color.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_color.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * blue
 */
static struct __attrdef RocsWgen_blue = {
  "blue",  "Blue value",  "",  "int",  "0",  "0-255",  False,
};
static int _getblue(iONode node) {
  int defval = xInt( RocsWgen_blue );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_color, node );
  return NodeOp.getInt( node, "blue", defval );
}
static void _setblue(iONode node, int p_blue) {
  if( node == NULL ) return;
  xNode( RocsWgen_color, node );
  NodeOp.setInt( node, "blue", p_blue );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * brightness
 */
static struct __attrdef RocsWgen_brightness = {
  "brightness",  "Brightness",  "",  "int",  "0",  "0-255",  False,
};
static int _getbrightness(iONode node) {
  int defval = xInt( RocsWgen_brightness );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_color, node );
  return NodeOp.getInt( node, "brightness", defval );
}
static void _setbrightness(iONode node, int p_brightness) {
  if( node == NULL ) return;
  xNode( RocsWgen_color, node );
  NodeOp.setInt( node, "brightness", p_brightness );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * green
 */
static struct __attrdef RocsWgen_green = {
  "green",  "Green value",  "",  "int",  "0",  "0-255",  False,
};
static int _getgreen(iONode node) {
  int defval = xInt( RocsWgen_green );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_color, node );
  return NodeOp.getInt( node, "green", defval );
}
static void _setgreen(iONode node, int p_green) {
  if( node == NULL ) return;
  xNode( RocsWgen_color, node );
  NodeOp.setInt( node, "green", p_green );
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
  xNode( RocsWgen_color, node );
  return NodeOp.getStr( node, "id", defval );
}
static void _setid(iONode node, const char* p_id) {
  if( node == NULL ) return;
  xNode( RocsWgen_color, node );
  NodeOp.setStr( node, "id", p_id );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * red
 */
static struct __attrdef RocsWgen_red = {
  "red",  "Red value",  "",  "int",  "0",  "0-255",  False,
};
static int _getred(iONode node) {
  int defval = xInt( RocsWgen_red );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_color, node );
  return NodeOp.getInt( node, "red", defval );
}
static void _setred(iONode node, int p_red) {
  if( node == NULL ) return;
  xNode( RocsWgen_color, node );
  NodeOp.setInt( node, "red", p_red );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * saturation
 */
static struct __attrdef RocsWgen_saturation = {
  "saturation",  "Brightness",  "",  "int",  "254",  "0-254",  False,
};
static int _getsaturation(iONode node) {
  int defval = xInt( RocsWgen_saturation );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_color, node );
  return NodeOp.getInt( node, "saturation", defval );
}
static void _setsaturation(iONode node, int p_saturation) {
  if( node == NULL ) return;
  xNode( RocsWgen_color, node );
  NodeOp.setInt( node, "saturation", p_saturation );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * white
 */
static struct __attrdef RocsWgen_white = {
  "white",  "White value",  "",  "int",  "0",  "0-255",  False,
};
static int _getwhite(iONode node) {
  int defval = xInt( RocsWgen_white );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_color, node );
  return NodeOp.getInt( node, "white", defval );
}
static void _setwhite(iONode node, int p_white) {
  if( node == NULL ) return;
  xNode( RocsWgen_color, node );
  NodeOp.setInt( node, "white", p_white );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * white2
 */
static struct __attrdef RocsWgen_white2 = {
  "white2",  "Second white value",  "",  "int",  "0",  "0-255",  False,
};
static int _getwhite2(iONode node) {
  int defval = xInt( RocsWgen_white2 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_color, node );
  return NodeOp.getInt( node, "white2", defval );
}
static void _setwhite2(iONode node, int p_white2) {
  if( node == NULL ) return;
  xNode( RocsWgen_color, node );
  NodeOp.setInt( node, "white2", p_white2 );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[9] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_color.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node color not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node color not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_blue;
  attrList[1] = &RocsWgen_brightness;
  attrList[2] = &RocsWgen_green;
  attrList[3] = &RocsWgen_id;
  attrList[4] = &RocsWgen_red;
  attrList[5] = &RocsWgen_saturation;
  attrList[6] = &RocsWgen_white;
  attrList[7] = &RocsWgen_white2;
  attrList[8] = NULL;
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


struct __wColor wColor = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getblue,
  _setblue,
  _getbrightness,
  _setbrightness,
  _getgreen,
  _setgreen,
  _getid,
  _setid,
  _getred,
  _setred,
  _getsaturation,
  _setsaturation,
  _getwhite,
  _setwhite,
  _getwhite2,
  _setwhite2,
  _node_dump,
};
