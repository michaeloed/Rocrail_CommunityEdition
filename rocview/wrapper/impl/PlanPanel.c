/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocview
  * Date: Fri Aug  3 14:03:53 2018
  */

#include "rocview/wrapper/public/PlanPanel.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocview.PlanPanel
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_planpanel = {
  "planpanel",  "",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_planpanel.name;
}
static const char* _node_remark(void) {
  return RocsWgen_planpanel.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_planpanel.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_planpanel.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * bktext
 */
static struct __attrdef RocsWgen_bktext = {
  "bktext",  "finetune blocktext font size: use 1.75 for Win32",  "",  "float",  "1.25",  "",  False,
};
static double _getbktext(iONode node) {
  double defval = xFloat( RocsWgen_bktext );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_planpanel, node );
  return NodeOp.getFloat( node, "bktext", defval );
}
static void _setbktext(iONode node, double p_bktext) {
  if( node == NULL ) return;
  xNode( RocsWgen_planpanel, node );
  NodeOp.setFloat( node, "bktext", p_bktext );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * bktext_blue
 */
static struct __attrdef RocsWgen_bktext_blue = {
  "bktext_blue",  "",  "",  "int",  "0",  "",  False,
};
static int _getbktext_blue(iONode node) {
  int defval = xInt( RocsWgen_bktext_blue );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_planpanel, node );
  return NodeOp.getInt( node, "bktext_blue", defval );
}
static void _setbktext_blue(iONode node, int p_bktext_blue) {
  if( node == NULL ) return;
  xNode( RocsWgen_planpanel, node );
  NodeOp.setInt( node, "bktext_blue", p_bktext_blue );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * bktext_green
 */
static struct __attrdef RocsWgen_bktext_green = {
  "bktext_green",  "",  "",  "int",  "0",  "",  False,
};
static int _getbktext_green(iONode node) {
  int defval = xInt( RocsWgen_bktext_green );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_planpanel, node );
  return NodeOp.getInt( node, "bktext_green", defval );
}
static void _setbktext_green(iONode node, int p_bktext_green) {
  if( node == NULL ) return;
  xNode( RocsWgen_planpanel, node );
  NodeOp.setInt( node, "bktext_green", p_bktext_green );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * bktext_red
 */
static struct __attrdef RocsWgen_bktext_red = {
  "bktext_red",  "",  "",  "int",  "0",  "",  False,
};
static int _getbktext_red(iONode node) {
  int defval = xInt( RocsWgen_bktext_red );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_planpanel, node );
  return NodeOp.getInt( node, "bktext_red", defval );
}
static void _setbktext_red(iONode node, int p_bktext_red) {
  if( node == NULL ) return;
  xNode( RocsWgen_planpanel, node );
  NodeOp.setInt( node, "bktext_red", p_bktext_red );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * bktextid
 */
static struct __attrdef RocsWgen_bktextid = {
  "bktextid",  "",  "",  "bool",  "true",  "",  False,
};
static Boolean _isbktextid(iONode node) {
  Boolean defval = xBool( RocsWgen_bktextid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_planpanel, node );
  return NodeOp.getBool( node, "bktextid", defval );
}
static void _setbktextid(iONode node, Boolean p_bktextid) {
  if( node == NULL ) return;
  xNode( RocsWgen_planpanel, node );
  NodeOp.setBool( node, "bktextid", p_bktextid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * blue
 */
static struct __attrdef RocsWgen_blue = {
  "blue",  "",  "",  "int",  "255",  "",  False,
};
static int _getblue(iONode node) {
  int defval = xInt( RocsWgen_blue );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_planpanel, node );
  return NodeOp.getInt( node, "blue", defval );
}
static void _setblue(iONode node, int p_blue) {
  if( node == NULL ) return;
  xNode( RocsWgen_planpanel, node );
  NodeOp.setInt( node, "blue", p_blue );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * cx
 */
static struct __attrdef RocsWgen_cx = {
  "cx",  "",  "",  "int",  "64",  "",  False,
};
static int _getcx(iONode node) {
  int defval = xInt( RocsWgen_cx );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_planpanel, node );
  return NodeOp.getInt( node, "cx", defval );
}
static void _setcx(iONode node, int p_cx) {
  if( node == NULL ) return;
  xNode( RocsWgen_planpanel, node );
  NodeOp.setInt( node, "cx", p_cx );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * cy
 */
static struct __attrdef RocsWgen_cy = {
  "cy",  "",  "",  "int",  "48",  "",  False,
};
static int _getcy(iONode node) {
  int defval = xInt( RocsWgen_cy );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_planpanel, node );
  return NodeOp.getInt( node, "cy", defval );
}
static void _setcy(iONode node, int p_cy) {
  if( node == NULL ) return;
  xNode( RocsWgen_planpanel, node );
  NodeOp.setInt( node, "cy", p_cy );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * fill
 */
static struct __attrdef RocsWgen_fill = {
  "fill",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isfill(iONode node) {
  Boolean defval = xBool( RocsWgen_fill );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_planpanel, node );
  return NodeOp.getBool( node, "fill", defval );
}
static void _setfill(iONode node, Boolean p_fill) {
  if( node == NULL ) return;
  xNode( RocsWgen_planpanel, node );
  NodeOp.setBool( node, "fill", p_fill );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * green
 */
static struct __attrdef RocsWgen_green = {
  "green",  "",  "",  "int",  "255",  "",  False,
};
static int _getgreen(iONode node) {
  int defval = xInt( RocsWgen_green );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_planpanel, node );
  return NodeOp.getInt( node, "green", defval );
}
static void _setgreen(iONode node, int p_green) {
  if( node == NULL ) return;
  xNode( RocsWgen_planpanel, node );
  NodeOp.setInt( node, "green", p_green );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * itemidps
 */
static struct __attrdef RocsWgen_itemidps = {
  "itemidps",  "",  "",  "int",  "7",  "",  False,
};
static int _getitemidps(iONode node) {
  int defval = xInt( RocsWgen_itemidps );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_planpanel, node );
  return NodeOp.getInt( node, "itemidps", defval );
}
static void _setitemidps(iONode node, int p_itemidps) {
  if( node == NULL ) return;
  xNode( RocsWgen_planpanel, node );
  NodeOp.setInt( node, "itemidps", p_itemidps );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * locobook
 */
static struct __attrdef RocsWgen_locobook = {
  "locobook",  "",  "",  "bool",  "true",  "",  False,
};
static Boolean _islocobook(iONode node) {
  Boolean defval = xBool( RocsWgen_locobook );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_planpanel, node );
  return NodeOp.getBool( node, "locobook", defval );
}
static void _setlocobook(iONode node, Boolean p_locobook) {
  if( node == NULL ) return;
  xNode( RocsWgen_planpanel, node );
  NodeOp.setBool( node, "locobook", p_locobook );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * planbook
 */
static struct __attrdef RocsWgen_planbook = {
  "planbook",  "",  "",  "bool",  "true",  "",  False,
};
static Boolean _isplanbook(iONode node) {
  Boolean defval = xBool( RocsWgen_planbook );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_planpanel, node );
  return NodeOp.getBool( node, "planbook", defval );
}
static void _setplanbook(iONode node, Boolean p_planbook) {
  if( node == NULL ) return;
  xNode( RocsWgen_planpanel, node );
  NodeOp.setBool( node, "planbook", p_planbook );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * processblockevents
 */
static struct __attrdef RocsWgen_processblockevents = {
  "processblockevents",  "",  "",  "bool",  "true",  "",  False,
};
static Boolean _isprocessblockevents(iONode node) {
  Boolean defval = xBool( RocsWgen_processblockevents );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_planpanel, node );
  return NodeOp.getBool( node, "processblockevents", defval );
}
static void _setprocessblockevents(iONode node, Boolean p_processblockevents) {
  if( node == NULL ) return;
  xNode( RocsWgen_planpanel, node );
  NodeOp.setBool( node, "processblockevents", p_processblockevents );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * processrouteevents
 */
static struct __attrdef RocsWgen_processrouteevents = {
  "processrouteevents",  "",  "",  "bool",  "true",  "",  False,
};
static Boolean _isprocessrouteevents(iONode node) {
  Boolean defval = xBool( RocsWgen_processrouteevents );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_planpanel, node );
  return NodeOp.getBool( node, "processrouteevents", defval );
}
static void _setprocessrouteevents(iONode node, Boolean p_processrouteevents) {
  if( node == NULL ) return;
  xNode( RocsWgen_planpanel, node );
  NodeOp.setBool( node, "processrouteevents", p_processrouteevents );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * raster
 */
static struct __attrdef RocsWgen_raster = {
  "raster",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _israster(iONode node) {
  Boolean defval = xBool( RocsWgen_raster );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_planpanel, node );
  return NodeOp.getBool( node, "raster", defval );
}
static void _setraster(iONode node, Boolean p_raster) {
  if( node == NULL ) return;
  xNode( RocsWgen_planpanel, node );
  NodeOp.setBool( node, "raster", p_raster );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * red
 */
static struct __attrdef RocsWgen_red = {
  "red",  "",  "",  "int",  "255",  "",  False,
};
static int _getred(iONode node) {
  int defval = xInt( RocsWgen_red );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_planpanel, node );
  return NodeOp.getInt( node, "red", defval );
}
static void _setred(iONode node, int p_red) {
  if( node == NULL ) return;
  xNode( RocsWgen_planpanel, node );
  NodeOp.setInt( node, "red", p_red );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * scale
 */
static struct __attrdef RocsWgen_scale = {
  "scale",  "",  "",  "float",  "1.0",  "",  False,
};
static double _getscale(iONode node) {
  double defval = xFloat( RocsWgen_scale );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_planpanel, node );
  return NodeOp.getFloat( node, "scale", defval );
}
static void _setscale(iONode node, double p_scale) {
  if( node == NULL ) return;
  xNode( RocsWgen_planpanel, node );
  NodeOp.setFloat( node, "scale", p_scale );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * scblue
 */
static struct __attrdef RocsWgen_scblue = {
  "scblue",  "",  "",  "int",  "0",  "",  False,
};
static int _getscblue(iONode node) {
  int defval = xInt( RocsWgen_scblue );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_planpanel, node );
  return NodeOp.getInt( node, "scblue", defval );
}
static void _setscblue(iONode node, int p_scblue) {
  if( node == NULL ) return;
  xNode( RocsWgen_planpanel, node );
  NodeOp.setInt( node, "scblue", p_scblue );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * scgreen
 */
static struct __attrdef RocsWgen_scgreen = {
  "scgreen",  "",  "",  "int",  "255",  "",  False,
};
static int _getscgreen(iONode node) {
  int defval = xInt( RocsWgen_scgreen );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_planpanel, node );
  return NodeOp.getInt( node, "scgreen", defval );
}
static void _setscgreen(iONode node, int p_scgreen) {
  if( node == NULL ) return;
  xNode( RocsWgen_planpanel, node );
  NodeOp.setInt( node, "scgreen", p_scgreen );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * scred
 */
static struct __attrdef RocsWgen_scred = {
  "scred",  "",  "",  "int",  "255",  "",  False,
};
static int _getscred(iONode node) {
  int defval = xInt( RocsWgen_scred );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_planpanel, node );
  return NodeOp.getInt( node, "scred", defval );
}
static void _setscred(iONode node, int p_scred) {
  if( node == NULL ) return;
  xNode( RocsWgen_planpanel, node );
  NodeOp.setInt( node, "scred", p_scred );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * showborder
 */
static struct __attrdef RocsWgen_showborder = {
  "showborder",  "",  "",  "bool",  "true",  "",  False,
};
static Boolean _isshowborder(iONode node) {
  Boolean defval = xBool( RocsWgen_showborder );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_planpanel, node );
  return NodeOp.getBool( node, "showborder", defval );
}
static void _setshowborder(iONode node, Boolean p_showborder) {
  if( node == NULL ) return;
  xNode( RocsWgen_planpanel, node );
  NodeOp.setBool( node, "showborder", p_showborder );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * showcounters
 */
static struct __attrdef RocsWgen_showcounters = {
  "showcounters",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isshowcounters(iONode node) {
  Boolean defval = xBool( RocsWgen_showcounters );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_planpanel, node );
  return NodeOp.getBool( node, "showcounters", defval );
}
static void _setshowcounters(iONode node, Boolean p_showcounters) {
  if( node == NULL ) return;
  xNode( RocsWgen_planpanel, node );
  NodeOp.setBool( node, "showcounters", p_showcounters );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * showid
 */
static struct __attrdef RocsWgen_showid = {
  "showid",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isshowid(iONode node) {
  Boolean defval = xBool( RocsWgen_showid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_planpanel, node );
  return NodeOp.getBool( node, "showid", defval );
}
static void _setshowid(iONode node, Boolean p_showid) {
  if( node == NULL ) return;
  xNode( RocsWgen_planpanel, node );
  NodeOp.setBool( node, "showid", p_showid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * showlocked
 */
static struct __attrdef RocsWgen_showlocked = {
  "showlocked",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isshowlocked(iONode node) {
  Boolean defval = xBool( RocsWgen_showlocked );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_planpanel, node );
  return NodeOp.getBool( node, "showlocked", defval );
}
static void _setshowlocked(iONode node, Boolean p_showlocked) {
  if( node == NULL ) return;
  xNode( RocsWgen_planpanel, node );
  NodeOp.setBool( node, "showlocked", p_showlocked );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * showpending
 */
static struct __attrdef RocsWgen_showpending = {
  "showpending",  "Show pending switches with a red background.",  "",  "bool",  "true",  "",  False,
};
static Boolean _isshowpending(iONode node) {
  Boolean defval = xBool( RocsWgen_showpending );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_planpanel, node );
  return NodeOp.getBool( node, "showpending", defval );
}
static void _setshowpending(iONode node, Boolean p_showpending) {
  if( node == NULL ) return;
  xNode( RocsWgen_planpanel, node );
  NodeOp.setBool( node, "showpending", p_showpending );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * showsc
 */
static struct __attrdef RocsWgen_showsc = {
  "showsc",  "",  "",  "bool",  "true",  "",  False,
};
static Boolean _isshowsc(iONode node) {
  Boolean defval = xBool( RocsWgen_showsc );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_planpanel, node );
  return NodeOp.getBool( node, "showsc", defval );
}
static void _setshowsc(iONode node, Boolean p_showsc) {
  if( node == NULL ) return;
  xNode( RocsWgen_planpanel, node );
  NodeOp.setBool( node, "showsc", p_showsc );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * svgpath
 */
static struct __attrdef RocsWgen_svgpath = {
  "svgpath",  "scan this path for svg symbols",  "",  "string",  "svg/themes/SpDrS60",  "",  False,
};
static const char* _getsvgpath(iONode node) {
  const char* defval = xStr( RocsWgen_svgpath );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_planpanel, node );
  return NodeOp.getStr( node, "svgpath", defval );
}
static void _setsvgpath(iONode node, const char* p_svgpath) {
  if( node == NULL ) return;
  xNode( RocsWgen_planpanel, node );
  NodeOp.setStr( node, "svgpath", p_svgpath );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * svgpath2
 */
static struct __attrdef RocsWgen_svgpath2 = {
  "svgpath2",  "scan this path for svg symbols",  "",  "string",  ".",  "",  False,
};
static const char* _getsvgpath2(iONode node) {
  const char* defval = xStr( RocsWgen_svgpath2 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_planpanel, node );
  return NodeOp.getStr( node, "svgpath2", defval );
}
static void _setsvgpath2(iONode node, const char* p_svgpath2) {
  if( node == NULL ) return;
  xNode( RocsWgen_planpanel, node );
  NodeOp.setStr( node, "svgpath2", p_svgpath2 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * svgpath3
 */
static struct __attrdef RocsWgen_svgpath3 = {
  "svgpath3",  "scan this path for svg symbols",  "",  "string",  ".",  "",  False,
};
static const char* _getsvgpath3(iONode node) {
  const char* defval = xStr( RocsWgen_svgpath3 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_planpanel, node );
  return NodeOp.getStr( node, "svgpath3", defval );
}
static void _setsvgpath3(iONode node, const char* p_svgpath3) {
  if( node == NULL ) return;
  xNode( RocsWgen_planpanel, node );
  NodeOp.setStr( node, "svgpath3", p_svgpath3 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * svgpath4
 */
static struct __attrdef RocsWgen_svgpath4 = {
  "svgpath4",  "scan this path for svg symbols",  "",  "string",  ".",  "",  False,
};
static const char* _getsvgpath4(iONode node) {
  const char* defval = xStr( RocsWgen_svgpath4 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_planpanel, node );
  return NodeOp.getStr( node, "svgpath4", defval );
}
static void _setsvgpath4(iONode node, const char* p_svgpath4) {
  if( node == NULL ) return;
  xNode( RocsWgen_planpanel, node );
  NodeOp.setStr( node, "svgpath4", p_svgpath4 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * svgpath5
 */
static struct __attrdef RocsWgen_svgpath5 = {
  "svgpath5",  "scan this path for svg symbols",  "",  "string",  ".",  "",  False,
};
static const char* _getsvgpath5(iONode node) {
  const char* defval = xStr( RocsWgen_svgpath5 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_planpanel, node );
  return NodeOp.getStr( node, "svgpath5", defval );
}
static void _setsvgpath5(iONode node, const char* p_svgpath5) {
  if( node == NULL ) return;
  xNode( RocsWgen_planpanel, node );
  NodeOp.setStr( node, "svgpath5", p_svgpath5 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * textps
 */
static struct __attrdef RocsWgen_textps = {
  "textps",  "",  "",  "int",  "10",  "",  False,
};
static int _gettextps(iONode node) {
  int defval = xInt( RocsWgen_textps );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_planpanel, node );
  return NodeOp.getInt( node, "textps", defval );
}
static void _settextps(iONode node, int p_textps) {
  if( node == NULL ) return;
  xNode( RocsWgen_planpanel, node );
  NodeOp.setInt( node, "textps", p_textps );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * tooltip
 */
static struct __attrdef RocsWgen_tooltip = {
  "tooltip",  "",  "",  "bool",  "true",  "",  False,
};
static Boolean _istooltip(iONode node) {
  Boolean defval = xBool( RocsWgen_tooltip );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_planpanel, node );
  return NodeOp.getBool( node, "tooltip", defval );
}
static void _settooltip(iONode node, Boolean p_tooltip) {
  if( node == NULL ) return;
  xNode( RocsWgen_planpanel, node );
  NodeOp.setBool( node, "tooltip", p_tooltip );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * tracewindow
 */
static struct __attrdef RocsWgen_tracewindow = {
  "tracewindow",  "",  "",  "bool",  "true",  "",  False,
};
static Boolean _istracewindow(iONode node) {
  Boolean defval = xBool( RocsWgen_tracewindow );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_planpanel, node );
  return NodeOp.getBool( node, "tracewindow", defval );
}
static void _settracewindow(iONode node, Boolean p_tracewindow) {
  if( node == NULL ) return;
  xNode( RocsWgen_planpanel, node );
  NodeOp.setBool( node, "tracewindow", p_tracewindow );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[36] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_planpanel.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node planpanel not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node planpanel not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_bktext;
  attrList[1] = &RocsWgen_bktext_blue;
  attrList[2] = &RocsWgen_bktext_green;
  attrList[3] = &RocsWgen_bktext_red;
  attrList[4] = &RocsWgen_bktextid;
  attrList[5] = &RocsWgen_blue;
  attrList[6] = &RocsWgen_cx;
  attrList[7] = &RocsWgen_cy;
  attrList[8] = &RocsWgen_fill;
  attrList[9] = &RocsWgen_green;
  attrList[10] = &RocsWgen_itemidps;
  attrList[11] = &RocsWgen_locobook;
  attrList[12] = &RocsWgen_planbook;
  attrList[13] = &RocsWgen_processblockevents;
  attrList[14] = &RocsWgen_processrouteevents;
  attrList[15] = &RocsWgen_raster;
  attrList[16] = &RocsWgen_red;
  attrList[17] = &RocsWgen_scale;
  attrList[18] = &RocsWgen_scblue;
  attrList[19] = &RocsWgen_scgreen;
  attrList[20] = &RocsWgen_scred;
  attrList[21] = &RocsWgen_showborder;
  attrList[22] = &RocsWgen_showcounters;
  attrList[23] = &RocsWgen_showid;
  attrList[24] = &RocsWgen_showlocked;
  attrList[25] = &RocsWgen_showpending;
  attrList[26] = &RocsWgen_showsc;
  attrList[27] = &RocsWgen_svgpath;
  attrList[28] = &RocsWgen_svgpath2;
  attrList[29] = &RocsWgen_svgpath3;
  attrList[30] = &RocsWgen_svgpath4;
  attrList[31] = &RocsWgen_svgpath5;
  attrList[32] = &RocsWgen_textps;
  attrList[33] = &RocsWgen_tooltip;
  attrList[34] = &RocsWgen_tracewindow;
  attrList[35] = NULL;
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


struct __wPlanPanel wPlanPanel = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getbktext,
  _setbktext,
  _getbktext_blue,
  _setbktext_blue,
  _getbktext_green,
  _setbktext_green,
  _getbktext_red,
  _setbktext_red,
  _isbktextid,
  _setbktextid,
  _getblue,
  _setblue,
  _getcx,
  _setcx,
  _getcy,
  _setcy,
  _isfill,
  _setfill,
  _getgreen,
  _setgreen,
  _getitemidps,
  _setitemidps,
  _islocobook,
  _setlocobook,
  _isplanbook,
  _setplanbook,
  _isprocessblockevents,
  _setprocessblockevents,
  _isprocessrouteevents,
  _setprocessrouteevents,
  _israster,
  _setraster,
  _getred,
  _setred,
  _getscale,
  _setscale,
  _getscblue,
  _setscblue,
  _getscgreen,
  _setscgreen,
  _getscred,
  _setscred,
  _isshowborder,
  _setshowborder,
  _isshowcounters,
  _setshowcounters,
  _isshowid,
  _setshowid,
  _isshowlocked,
  _setshowlocked,
  _isshowpending,
  _setshowpending,
  _isshowsc,
  _setshowsc,
  _getsvgpath,
  _setsvgpath,
  _getsvgpath2,
  _setsvgpath2,
  _getsvgpath3,
  _setsvgpath3,
  _getsvgpath4,
  _setsvgpath4,
  _getsvgpath5,
  _setsvgpath5,
  _gettextps,
  _settextps,
  _istooltip,
  _settooltip,
  _istracewindow,
  _settracewindow,
  _node_dump,
};
