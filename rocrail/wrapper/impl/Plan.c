/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/Plan.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.Plan
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_plan = {
  "plan",  "Root node of the planfile.",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_plan.name;
}
static const char* _node_remark(void) {
  return RocsWgen_plan.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_plan.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_plan.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * donkey
 */
static struct __attrdef RocsWgen_donkey = {
  "donkey",  "Flags if a valid donation key is found.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isdonkey(iONode node) {
  Boolean defval = xBool( RocsWgen_donkey );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_plan, node );
  return NodeOp.getBool( node, "donkey", defval );
}
static void _setdonkey(iONode node, Boolean p_donkey) {
  if( node == NULL ) return;
  xNode( RocsWgen_plan, node );
  NodeOp.setBool( node, "donkey", p_donkey );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * healthy
 */
static struct __attrdef RocsWgen_healthy = {
  "healthy",  "",  "",  "bool",  "true",  "",  False,
};
static Boolean _ishealthy(iONode node) {
  Boolean defval = xBool( RocsWgen_healthy );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_plan, node );
  return NodeOp.getBool( node, "healthy", defval );
}
static void _sethealthy(iONode node, Boolean p_healthy) {
  if( node == NULL ) return;
  xNode( RocsWgen_plan, node );
  NodeOp.setBool( node, "healthy", p_healthy );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * modplan
 */
static struct __attrdef RocsWgen_modplan = {
  "modplan",  "Flags the Rocview if it is assembled from a modular layout definition.",  "",  "bool",  "false",  "",  False,
};
static Boolean _ismodplan(iONode node) {
  Boolean defval = xBool( RocsWgen_modplan );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_plan, node );
  return NodeOp.getBool( node, "modplan", defval );
}
static void _setmodplan(iONode node, Boolean p_modplan) {
  if( node == NULL ) return;
  xNode( RocsWgen_plan, node );
  NodeOp.setBool( node, "modplan", p_modplan );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * modtitle
 */
static struct __attrdef RocsWgen_modtitle = {
  "modtitle",  "Title of plan.",  "",  "string",  "Module Overview",  "*",  False,
};
static const char* _getmodtitle(iONode node) {
  const char* defval = xStr( RocsWgen_modtitle );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_plan, node );
  return NodeOp.getStr( node, "modtitle", defval );
}
static void _setmodtitle(iONode node, const char* p_modtitle) {
  if( node == NULL ) return;
  xNode( RocsWgen_plan, node );
  NodeOp.setStr( node, "modtitle", p_modtitle );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * name
 */
static struct __attrdef RocsWgen_name = {
  "name",  "Filename of plan.",  "",  "string",  "plan.xml",  "*",  False,
};
static const char* _getname(iONode node) {
  const char* defval = xStr( RocsWgen_name );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_plan, node );
  return NodeOp.getStr( node, "name", defval );
}
static void _setname(iONode node, const char* p_name) {
  if( node == NULL ) return;
  xNode( RocsWgen_plan, node );
  NodeOp.setStr( node, "name", p_name );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * rocguiversion
 */
static struct __attrdef RocsWgen_rocguiversion = {
  "rocguiversion",  "Rocgui version at last save of a local plan.",  "",  "string",  "",  "*",  False,
};
static const char* _getrocguiversion(iONode node) {
  const char* defval = xStr( RocsWgen_rocguiversion );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_plan, node );
  return NodeOp.getStr( node, "rocguiversion", defval );
}
static void _setrocguiversion(iONode node, const char* p_rocguiversion) {
  if( node == NULL ) return;
  xNode( RocsWgen_plan, node );
  NodeOp.setStr( node, "rocguiversion", p_rocguiversion );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * rocrailpwd
 */
static struct __attrdef RocsWgen_rocrailpwd = {
  "rocrailpwd",  "Rocrail working directory.",  "",  "string",  "",  "*",  False,
};
static const char* _getrocrailpwd(iONode node) {
  const char* defval = xStr( RocsWgen_rocrailpwd );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_plan, node );
  return NodeOp.getStr( node, "rocrailpwd", defval );
}
static void _setrocrailpwd(iONode node, const char* p_rocrailpwd) {
  if( node == NULL ) return;
  xNode( RocsWgen_plan, node );
  NodeOp.setStr( node, "rocrailpwd", p_rocrailpwd );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * rocrailversion
 */
static struct __attrdef RocsWgen_rocrailversion = {
  "rocrailversion",  "Rocrail version at last save of a plan.",  "",  "string",  "",  "*",  False,
};
static const char* _getrocrailversion(iONode node) {
  const char* defval = xStr( RocsWgen_rocrailversion );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_plan, node );
  return NodeOp.getStr( node, "rocrailversion", defval );
}
static void _setrocrailversion(iONode node, const char* p_rocrailversion) {
  if( node == NULL ) return;
  xNode( RocsWgen_plan, node );
  NodeOp.setStr( node, "rocrailversion", p_rocrailversion );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * themes
 */
static struct __attrdef RocsWgen_themes = {
  "themes",  "Preferred themes for redndering this plan by Rocviews.",  "",  "string",  "",  "*",  False,
};
static const char* _getthemes(iONode node) {
  const char* defval = xStr( RocsWgen_themes );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_plan, node );
  return NodeOp.getStr( node, "themes", defval );
}
static void _setthemes(iONode node, const char* p_themes) {
  if( node == NULL ) return;
  xNode( RocsWgen_plan, node );
  NodeOp.setStr( node, "themes", p_themes );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * title
 */
static struct __attrdef RocsWgen_title = {
  "title",  "Title of plan.",  "",  "string",  "New Plan",  "*",  False,
};
static const char* _gettitle(iONode node) {
  const char* defval = xStr( RocsWgen_title );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_plan, node );
  return NodeOp.getStr( node, "title", defval );
}
static void _settitle(iONode node, const char* p_title) {
  if( node == NULL ) return;
  xNode( RocsWgen_plan, node );
  NodeOp.setStr( node, "title", p_title );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * digint
 */
static struct __nodedef RocsWgen_digint = {
  "digint",  "",  False,  "n",};
static iONode _getdigint(iONode node) {
  xNode( RocsWgen_plan, node );
  return NodeOp.findNode( node, "digint");
}


static iONode _nextdigint(iONode node, iONode child) {
  xNode( RocsWgen_plan, node );
  return NodeOp.findNextNode( node, child);
}
static void _setdigint(iONode node, iONode p_digint) {
  xNode( RocsWgen_plan, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * system
 */
static struct __nodedef RocsWgen_system = {
  "system",  "",  False,  "1",};
static iONode _getsystem(iONode node) {
  xNode( RocsWgen_plan, node );
  return NodeOp.findNode( node, "system");
}


static iONode _nextsystem(iONode node, iONode child) {
  xNode( RocsWgen_plan, node );
  return NodeOp.findNextNode( node, child);
}
static void _setsystem(iONode node, iONode p_system) {
  xNode( RocsWgen_plan, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * weatherlist
 */
static struct __nodedef RocsWgen_weatherlist = {
  "weatherlist",  "",  False,  "n",};
static iONode _getweatherlist(iONode node) {
  xNode( RocsWgen_plan, node );
  return NodeOp.findNode( node, "weatherlist");
}


static iONode _nextweatherlist(iONode node, iONode child) {
  xNode( RocsWgen_plan, node );
  return NodeOp.findNextNode( node, child);
}
static void _setweatherlist(iONode node, iONode p_weatherlist) {
  xNode( RocsWgen_plan, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * zlevel
 */
static struct __nodedef RocsWgen_zlevel = {
  "zlevel",  "Z-Level description",  False,  "n",};
static iONode _getzlevel(iONode node) {
  xNode( RocsWgen_plan, node );
  return NodeOp.findNode( node, "zlevel");
}


static iONode _nextzlevel(iONode node, iONode child) {
  xNode( RocsWgen_plan, node );
  return NodeOp.findNextNode( node, child);
}
static void _setzlevel(iONode node, iONode p_zlevel) {
  xNode( RocsWgen_plan, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * boosterlist
 */
static struct __nodedef RocsWgen_boosterlist = {
  "boosterlist",  "Booster list for power management",  False,  "1",};
static iONode _getboosterlist(iONode node) {
  xNode( RocsWgen_plan, node );
  return NodeOp.findNode( node, "boosterlist");
}


static iONode _nextboosterlist(iONode node, iONode child) {
  xNode( RocsWgen_plan, node );
  return NodeOp.findNextNode( node, child);
}
static void _setboosterlist(iONode node, iONode p_boosterlist) {
  xNode( RocsWgen_plan, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * mv
 */
static struct __nodedef RocsWgen_mv = {
  "mv",  "Measurement Velocity Track",  False,  "1",};
static iONode _getmv(iONode node) {
  xNode( RocsWgen_plan, node );
  return NodeOp.findNode( node, "mv");
}


static iONode _nextmv(iONode node, iONode child) {
  xNode( RocsWgen_plan, node );
  return NodeOp.findNextNode( node, child);
}
static void _setmv(iONode node, iONode p_mv) {
  xNode( RocsWgen_plan, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * swlist
 */
static struct __nodedef RocsWgen_swlist = {
  "swlist",  "Turnout table",  False,  "1",};
static iONode _getswlist(iONode node) {
  xNode( RocsWgen_plan, node );
  return NodeOp.findNode( node, "swlist");
}


static iONode _nextswlist(iONode node, iONode child) {
  xNode( RocsWgen_plan, node );
  return NodeOp.findNextNode( node, child);
}
static void _setswlist(iONode node, iONode p_swlist) {
  xNode( RocsWgen_plan, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * sglist
 */
static struct __nodedef RocsWgen_sglist = {
  "sglist",  "Signal table",  False,  "1",};
static iONode _getsglist(iONode node) {
  xNode( RocsWgen_plan, node );
  return NodeOp.findNode( node, "sglist");
}


static iONode _nextsglist(iONode node, iONode child) {
  xNode( RocsWgen_plan, node );
  return NodeOp.findNextNode( node, child);
}
static void _setsglist(iONode node, iONode p_sglist) {
  xNode( RocsWgen_plan, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * colist
 */
static struct __nodedef RocsWgen_colist = {
  "colist",  "Common Output table",  False,  "1",};
static iONode _getcolist(iONode node) {
  xNode( RocsWgen_plan, node );
  return NodeOp.findNode( node, "colist");
}


static iONode _nextcolist(iONode node, iONode child) {
  xNode( RocsWgen_plan, node );
  return NodeOp.findNextNode( node, child);
}
static void _setcolist(iONode node, iONode p_colist) {
  xNode( RocsWgen_plan, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * fblist
 */
static struct __nodedef RocsWgen_fblist = {
  "fblist",  "Sensor table",  False,  "1",};
static iONode _getfblist(iONode node) {
  xNode( RocsWgen_plan, node );
  return NodeOp.findNode( node, "fblist");
}


static iONode _nextfblist(iONode node, iONode child) {
  xNode( RocsWgen_plan, node );
  return NodeOp.findNextNode( node, child);
}
static void _setfblist(iONode node, iONode p_fblist) {
  xNode( RocsWgen_plan, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * locationlist
 */
static struct __nodedef RocsWgen_locationlist = {
  "locationlist",  "Location table",  False,  "1",};
static iONode _getlocationlist(iONode node) {
  xNode( RocsWgen_plan, node );
  return NodeOp.findNode( node, "locationlist");
}


static iONode _nextlocationlist(iONode node, iONode child) {
  xNode( RocsWgen_plan, node );
  return NodeOp.findNextNode( node, child);
}
static void _setlocationlist(iONode node, iONode p_locationlist) {
  xNode( RocsWgen_plan, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * sclist
 */
static struct __nodedef RocsWgen_sclist = {
  "sclist",  "Schedule table",  False,  "1",};
static iONode _getsclist(iONode node) {
  xNode( RocsWgen_plan, node );
  return NodeOp.findNode( node, "sclist");
}


static iONode _nextsclist(iONode node, iONode child) {
  xNode( RocsWgen_plan, node );
  return NodeOp.findNextNode( node, child);
}
static void _setsclist(iONode node, iONode p_sclist) {
  xNode( RocsWgen_plan, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * tourlist
 */
static struct __nodedef RocsWgen_tourlist = {
  "tourlist",  "Tour table",  False,  "1",};
static iONode _gettourlist(iONode node) {
  xNode( RocsWgen_plan, node );
  return NodeOp.findNode( node, "tourlist");
}


static iONode _nexttourlist(iONode node, iONode child) {
  xNode( RocsWgen_plan, node );
  return NodeOp.findNextNode( node, child);
}
static void _settourlist(iONode node, iONode p_tourlist) {
  xNode( RocsWgen_plan, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * bklist
 */
static struct __nodedef RocsWgen_bklist = {
  "bklist",  "Block table",  False,  "1",};
static iONode _getbklist(iONode node) {
  xNode( RocsWgen_plan, node );
  return NodeOp.findNode( node, "bklist");
}


static iONode _nextbklist(iONode node, iONode child) {
  xNode( RocsWgen_plan, node );
  return NodeOp.findNextNode( node, child);
}
static void _setbklist(iONode node, iONode p_bklist) {
  xNode( RocsWgen_plan, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * sblist
 */
static struct __nodedef RocsWgen_sblist = {
  "sblist",  "Staging Yard Table",  False,  "1",};
static iONode _getsblist(iONode node) {
  xNode( RocsWgen_plan, node );
  return NodeOp.findNode( node, "sblist");
}


static iONode _nextsblist(iONode node, iONode child) {
  xNode( RocsWgen_plan, node );
  return NodeOp.findNextNode( node, child);
}
static void _setsblist(iONode node, iONode p_sblist) {
  xNode( RocsWgen_plan, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * linklist
 */
static struct __nodedef RocsWgen_linklist = {
  "linklist",  "Block Link table",  False,  "1",};
static iONode _getlinklist(iONode node) {
  xNode( RocsWgen_plan, node );
  return NodeOp.findNode( node, "linklist");
}


static iONode _nextlinklist(iONode node, iONode child) {
  xNode( RocsWgen_plan, node );
  return NodeOp.findNextNode( node, child);
}
static void _setlinklist(iONode node, iONode p_linklist) {
  xNode( RocsWgen_plan, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * stlist
 */
static struct __nodedef RocsWgen_stlist = {
  "stlist",  "Route table",  False,  "1",};
static iONode _getstlist(iONode node) {
  xNode( RocsWgen_plan, node );
  return NodeOp.findNode( node, "stlist");
}


static iONode _nextstlist(iONode node, iONode child) {
  xNode( RocsWgen_plan, node );
  return NodeOp.findNextNode( node, child);
}
static void _setstlist(iONode node, iONode p_stlist) {
  xNode( RocsWgen_plan, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * tklist
 */
static struct __nodedef RocsWgen_tklist = {
  "tklist",  "Track table",  False,  "1",};
static iONode _gettklist(iONode node) {
  xNode( RocsWgen_plan, node );
  return NodeOp.findNode( node, "tklist");
}


static iONode _nexttklist(iONode node, iONode child) {
  xNode( RocsWgen_plan, node );
  return NodeOp.findNextNode( node, child);
}
static void _settklist(iONode node, iONode p_tklist) {
  xNode( RocsWgen_plan, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * ttlist
 */
static struct __nodedef RocsWgen_ttlist = {
  "ttlist",  "Turntable",  False,  "1",};
static iONode _getttlist(iONode node) {
  xNode( RocsWgen_plan, node );
  return NodeOp.findNode( node, "ttlist");
}


static iONode _nextttlist(iONode node, iONode child) {
  xNode( RocsWgen_plan, node );
  return NodeOp.findNextNode( node, child);
}
static void _setttlist(iONode node, iONode p_ttlist) {
  xNode( RocsWgen_plan, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * declist
 */
static struct __nodedef RocsWgen_declist = {
  "declist",  "Decoder table",  False,  "1",};
static iONode _getdeclist(iONode node) {
  xNode( RocsWgen_plan, node );
  return NodeOp.findNode( node, "declist");
}


static iONode _nextdeclist(iONode node, iONode child) {
  xNode( RocsWgen_plan, node );
  return NodeOp.findNextNode( node, child);
}
static void _setdeclist(iONode node, iONode p_declist) {
  xNode( RocsWgen_plan, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * lclist
 */
static struct __nodedef RocsWgen_lclist = {
  "lclist",  "Loc table",  False,  "1",};
static iONode _getlclist(iONode node) {
  xNode( RocsWgen_plan, node );
  return NodeOp.findNode( node, "lclist");
}


static iONode _nextlclist(iONode node, iONode child) {
  xNode( RocsWgen_plan, node );
  return NodeOp.findNextNode( node, child);
}
static void _setlclist(iONode node, iONode p_lclist) {
  xNode( RocsWgen_plan, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * operatorlist
 */
static struct __nodedef RocsWgen_operatorlist = {
  "operatorlist",  "Operator table",  False,  "1",};
static iONode _getoperatorlist(iONode node) {
  xNode( RocsWgen_plan, node );
  return NodeOp.findNode( node, "operatorlist");
}


static iONode _nextoperatorlist(iONode node, iONode child) {
  xNode( RocsWgen_plan, node );
  return NodeOp.findNextNode( node, child);
}
static void _setoperatorlist(iONode node, iONode p_operatorlist) {
  xNode( RocsWgen_plan, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * carlist
 */
static struct __nodedef RocsWgen_carlist = {
  "carlist",  "Car table",  False,  "1",};
static iONode _getcarlist(iONode node) {
  xNode( RocsWgen_plan, node );
  return NodeOp.findNode( node, "carlist");
}


static iONode _nextcarlist(iONode node, iONode child) {
  xNode( RocsWgen_plan, node );
  return NodeOp.findNextNode( node, child);
}
static void _setcarlist(iONode node, iONode p_carlist) {
  xNode( RocsWgen_plan, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * waybilllist
 */
static struct __nodedef RocsWgen_waybilllist = {
  "waybilllist",  "Waybill table",  False,  "1",};
static iONode _getwaybilllist(iONode node) {
  xNode( RocsWgen_plan, node );
  return NodeOp.findNode( node, "waybilllist");
}


static iONode _nextwaybilllist(iONode node, iONode child) {
  xNode( RocsWgen_plan, node );
  return NodeOp.findNextNode( node, child);
}
static void _setwaybilllist(iONode node, iONode p_waybilllist) {
  xNode( RocsWgen_plan, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * txlist
 */
static struct __nodedef RocsWgen_txlist = {
  "txlist",  "text symbols table",  False,  "1",};
static iONode _gettxlist(iONode node) {
  xNode( RocsWgen_plan, node );
  return NodeOp.findNode( node, "txlist");
}


static iONode _nexttxlist(iONode node, iONode child) {
  xNode( RocsWgen_plan, node );
  return NodeOp.findNextNode( node, child);
}
static void _settxlist(iONode node, iONode p_txlist) {
  xNode( RocsWgen_plan, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * aclist
 */
static struct __nodedef RocsWgen_aclist = {
  "aclist",  "timed action table",  False,  "1",};
static iONode _getaclist(iONode node) {
  xNode( RocsWgen_plan, node );
  return NodeOp.findNode( node, "aclist");
}


static iONode _nextaclist(iONode node, iONode child) {
  xNode( RocsWgen_plan, node );
  return NodeOp.findNextNode( node, child);
}
static void _setaclist(iONode node, iONode p_aclist) {
  xNode( RocsWgen_plan, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * seltablist
 */
static struct __nodedef RocsWgen_seltablist = {
  "seltablist",  "selection table list",  False,  "1",};
static iONode _getseltablist(iONode node) {
  xNode( RocsWgen_plan, node );
  return NodeOp.findNode( node, "seltablist");
}


static iONode _nextseltablist(iONode node, iONode child) {
  xNode( RocsWgen_plan, node );
  return NodeOp.findNextNode( node, child);
}
static void _setseltablist(iONode node, iONode p_seltablist) {
  xNode( RocsWgen_plan, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * vrlist
 */
static struct __nodedef RocsWgen_vrlist = {
  "vrlist",  "variable list",  False,  "1",};
static iONode _getvrlist(iONode node) {
  xNode( RocsWgen_plan, node );
  return NodeOp.findNode( node, "vrlist");
}


static iONode _nextvrlist(iONode node, iONode child) {
  xNode( RocsWgen_plan, node );
  return NodeOp.findNextNode( node, child);
}
static void _setvrlist(iONode node, iONode p_vrlist) {
  xNode( RocsWgen_plan, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[11] = {NULL};
static struct __nodedef* nodeList[29] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_plan.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node plan not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node plan not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_donkey;
  attrList[1] = &RocsWgen_healthy;
  attrList[2] = &RocsWgen_modplan;
  attrList[3] = &RocsWgen_modtitle;
  attrList[4] = &RocsWgen_name;
  attrList[5] = &RocsWgen_rocguiversion;
  attrList[6] = &RocsWgen_rocrailpwd;
  attrList[7] = &RocsWgen_rocrailversion;
  attrList[8] = &RocsWgen_themes;
  attrList[9] = &RocsWgen_title;
  attrList[10] = NULL;
  nodeList[0] = &RocsWgen_digint;
  nodeList[1] = &RocsWgen_system;
  nodeList[2] = &RocsWgen_weatherlist;
  nodeList[3] = &RocsWgen_zlevel;
  nodeList[4] = &RocsWgen_boosterlist;
  nodeList[5] = &RocsWgen_mv;
  nodeList[6] = &RocsWgen_swlist;
  nodeList[7] = &RocsWgen_sglist;
  nodeList[8] = &RocsWgen_colist;
  nodeList[9] = &RocsWgen_fblist;
  nodeList[10] = &RocsWgen_locationlist;
  nodeList[11] = &RocsWgen_sclist;
  nodeList[12] = &RocsWgen_tourlist;
  nodeList[13] = &RocsWgen_bklist;
  nodeList[14] = &RocsWgen_sblist;
  nodeList[15] = &RocsWgen_linklist;
  nodeList[16] = &RocsWgen_stlist;
  nodeList[17] = &RocsWgen_tklist;
  nodeList[18] = &RocsWgen_ttlist;
  nodeList[19] = &RocsWgen_declist;
  nodeList[20] = &RocsWgen_lclist;
  nodeList[21] = &RocsWgen_operatorlist;
  nodeList[22] = &RocsWgen_carlist;
  nodeList[23] = &RocsWgen_waybilllist;
  nodeList[24] = &RocsWgen_txlist;
  nodeList[25] = &RocsWgen_aclist;
  nodeList[26] = &RocsWgen_seltablist;
  nodeList[27] = &RocsWgen_vrlist;
  nodeList[28] = NULL;
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


struct __wPlan wPlan = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _isdonkey,
  _setdonkey,
  _ishealthy,
  _sethealthy,
  _ismodplan,
  _setmodplan,
  _getmodtitle,
  _setmodtitle,
  _getname,
  _setname,
  _getrocguiversion,
  _setrocguiversion,
  _getrocrailpwd,
  _setrocrailpwd,
  _getrocrailversion,
  _setrocrailversion,
  _getthemes,
  _setthemes,
  _gettitle,
  _settitle,
  _getdigint,
  _nextdigint,
  _setdigint,
  _getsystem,
  _nextsystem,
  _setsystem,
  _getweatherlist,
  _nextweatherlist,
  _setweatherlist,
  _getzlevel,
  _nextzlevel,
  _setzlevel,
  _getboosterlist,
  _nextboosterlist,
  _setboosterlist,
  _getmv,
  _nextmv,
  _setmv,
  _getswlist,
  _nextswlist,
  _setswlist,
  _getsglist,
  _nextsglist,
  _setsglist,
  _getcolist,
  _nextcolist,
  _setcolist,
  _getfblist,
  _nextfblist,
  _setfblist,
  _getlocationlist,
  _nextlocationlist,
  _setlocationlist,
  _getsclist,
  _nextsclist,
  _setsclist,
  _gettourlist,
  _nexttourlist,
  _settourlist,
  _getbklist,
  _nextbklist,
  _setbklist,
  _getsblist,
  _nextsblist,
  _setsblist,
  _getlinklist,
  _nextlinklist,
  _setlinklist,
  _getstlist,
  _nextstlist,
  _setstlist,
  _gettklist,
  _nexttklist,
  _settklist,
  _getttlist,
  _nextttlist,
  _setttlist,
  _getdeclist,
  _nextdeclist,
  _setdeclist,
  _getlclist,
  _nextlclist,
  _setlclist,
  _getoperatorlist,
  _nextoperatorlist,
  _setoperatorlist,
  _getcarlist,
  _nextcarlist,
  _setcarlist,
  _getwaybilllist,
  _nextwaybilllist,
  _setwaybilllist,
  _gettxlist,
  _nexttxlist,
  _settxlist,
  _getaclist,
  _nextaclist,
  _setaclist,
  _getseltablist,
  _nextseltablist,
  _setseltablist,
  _getvrlist,
  _nextvrlist,
  _setvrlist,
  _node_dump,
};
