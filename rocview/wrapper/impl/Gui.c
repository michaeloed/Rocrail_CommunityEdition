/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Sep 20 2018 19:13:20)
  * Module: rocview
  * Date: Thu Sep 20 19:13:31 2018
  */

#include "rocview/wrapper/public/Gui.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocview.Gui
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_gui = {
  "gui",  "",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_gui.name;
}
static const char* _node_remark(void) {
  return RocsWgen_gui.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_gui.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_gui.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * checkupdates
 */
static struct __attrdef RocsWgen_checkupdates = {
  "checkupdates",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _ischeckupdates(iONode node) {
  Boolean defval = xBool( RocsWgen_checkupdates );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_gui, node );
  return NodeOp.getBool( node, "checkupdates", defval );
}
static void _setcheckupdates(iONode node, Boolean p_checkupdates) {
  if( node == NULL ) return;
  xNode( RocsWgen_gui, node );
  NodeOp.setBool( node, "checkupdates", p_checkupdates );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * clocktype
 */
static struct __attrdef RocsWgen_clocktype = {
  "clocktype",  "clock type select",  "",  "string",  "default",  "default,ampm,24h,none,digital",  False,
};
static const char* _getclocktype(iONode node) {
  const char* defval = xStr( RocsWgen_clocktype );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_gui, node );
  return NodeOp.getStr( node, "clocktype", defval );
}
static void _setclocktype(iONode node, const char* p_clocktype) {
  if( node == NULL ) return;
  xNode( RocsWgen_gui, node );
  NodeOp.setStr( node, "clocktype", p_clocktype );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * decpath
 */
static struct __attrdef RocsWgen_decpath = {
  "decpath",  "reference decoder specifications to this path",  "",  "string",  "decspecs",  "",  False,
};
static const char* _getdecpath(iONode node) {
  const char* defval = xStr( RocsWgen_decpath );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_gui, node );
  return NodeOp.getStr( node, "decpath", defval );
}
static void _setdecpath(iONode node, const char* p_decpath) {
  if( node == NULL ) return;
  xNode( RocsWgen_gui, node );
  NodeOp.setStr( node, "decpath", p_decpath );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * defaultworkspace
 */
static struct __attrdef RocsWgen_defaultworkspace = {
  "defaultworkspace",  "Open workspace at startup.",  "",  "string",  "",  "",  False,
};
static const char* _getdefaultworkspace(iONode node) {
  const char* defval = xStr( RocsWgen_defaultworkspace );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_gui, node );
  return NodeOp.getStr( node, "defaultworkspace", defval );
}
static void _setdefaultworkspace(iONode node, const char* p_defaultworkspace) {
  if( node == NULL ) return;
  xNode( RocsWgen_gui, node );
  NodeOp.setStr( node, "defaultworkspace", p_defaultworkspace );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * dirimagefwd
 */
static struct __attrdef RocsWgen_dirimagefwd = {
  "dirimagefwd",  "image to use for the direction button",  "",  "string",  "",  "",  False,
};
static const char* _getdirimagefwd(iONode node) {
  const char* defval = xStr( RocsWgen_dirimagefwd );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_gui, node );
  return NodeOp.getStr( node, "dirimagefwd", defval );
}
static void _setdirimagefwd(iONode node, const char* p_dirimagefwd) {
  if( node == NULL ) return;
  xNode( RocsWgen_gui, node );
  NodeOp.setStr( node, "dirimagefwd", p_dirimagefwd );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * dirimagerev
 */
static struct __attrdef RocsWgen_dirimagerev = {
  "dirimagerev",  "image to use for the direction button",  "",  "string",  "",  "",  False,
};
static const char* _getdirimagerev(iONode node) {
  const char* defval = xStr( RocsWgen_dirimagerev );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_gui, node );
  return NodeOp.getStr( node, "dirimagerev", defval );
}
static void _setdirimagerev(iONode node, const char* p_dirimagerev) {
  if( node == NULL ) return;
  xNode( RocsWgen_gui, node );
  NodeOp.setStr( node, "dirimagerev", p_dirimagerev );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * dispatchmode
 */
static struct __attrdef RocsWgen_dispatchmode = {
  "dispatchmode",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isdispatchmode(iONode node) {
  Boolean defval = xBool( RocsWgen_dispatchmode );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_gui, node );
  return NodeOp.getBool( node, "dispatchmode", defval );
}
static void _setdispatchmode(iONode node, Boolean p_dispatchmode) {
  if( node == NULL ) return;
  xNode( RocsWgen_gui, node );
  NodeOp.setBool( node, "dispatchmode", p_dispatchmode );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * fsutf8
 */
static struct __attrdef RocsWgen_fsutf8 = {
  "fsutf8",  "",  "",  "bool",  "true",  "",  False,
};
static Boolean _isfsutf8(iONode node) {
  Boolean defval = xBool( RocsWgen_fsutf8 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_gui, node );
  return NodeOp.getBool( node, "fsutf8", defval );
}
static void _setfsutf8(iONode node, Boolean p_fsutf8) {
  if( node == NULL ) return;
  xNode( RocsWgen_gui, node );
  NodeOp.setBool( node, "fsutf8", p_fsutf8 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * grayicons
 */
static struct __attrdef RocsWgen_grayicons = {
  "grayicons",  "",  "",  "bool",  "true",  "",  False,
};
static Boolean _isgrayicons(iONode node) {
  Boolean defval = xBool( RocsWgen_grayicons );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_gui, node );
  return NodeOp.getBool( node, "grayicons", defval );
}
static void _setgrayicons(iONode node, Boolean p_grayicons) {
  if( node == NULL ) return;
  xNode( RocsWgen_gui, node );
  NodeOp.setBool( node, "grayicons", p_grayicons );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * gridfontsizeadjust
 */
static struct __attrdef RocsWgen_gridfontsizeadjust = {
  "gridfontsizeadjust",  "",  "",  "int",  "0",  "",  False,
};
static int _getgridfontsizeadjust(iONode node) {
  int defval = xInt( RocsWgen_gridfontsizeadjust );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_gui, node );
  return NodeOp.getInt( node, "gridfontsizeadjust", defval );
}
static void _setgridfontsizeadjust(iONode node, int p_gridfontsizeadjust) {
  if( node == NULL ) return;
  xNode( RocsWgen_gui, node );
  NodeOp.setInt( node, "gridfontsizeadjust", p_gridfontsizeadjust );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * helpurl
 */
static struct __attrdef RocsWgen_helpurl = {
  "helpurl",  "WikiOnAStick: http://localhost:8800",  "",  "string",  "http://wiki.rocrail.net",  "",  False,
};
static const char* _gethelpurl(iONode node) {
  const char* defval = xStr( RocsWgen_helpurl );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_gui, node );
  return NodeOp.getStr( node, "helpurl", defval );
}
static void _sethelpurl(iONode node, const char* p_helpurl) {
  if( node == NULL ) return;
  xNode( RocsWgen_gui, node );
  NodeOp.setStr( node, "helpurl", p_helpurl );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * host
 */
static struct __attrdef RocsWgen_host = {
  "host",  "last used rrcon",  "",  "string",  "localhost",  "",  False,
};
static const char* _gethost(iONode node) {
  const char* defval = xStr( RocsWgen_host );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_gui, node );
  return NodeOp.getStr( node, "host", defval );
}
static void _sethost(iONode node, const char* p_host) {
  if( node == NULL ) return;
  xNode( RocsWgen_gui, node );
  NodeOp.setStr( node, "host", p_host );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * id
 */
static struct __attrdef RocsWgen_id = {
  "id",  "rocview ID",  "",  "string",  "rocview",  "*",  False,
};
static const char* _getid(iONode node) {
  const char* defval = xStr( RocsWgen_id );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_gui, node );
  return NodeOp.getStr( node, "id", defval );
}
static void _setid(iONode node, const char* p_id) {
  if( node == NULL ) return;
  xNode( RocsWgen_gui, node );
  NodeOp.setStr( node, "id", p_id );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * imagepath
 */
static struct __attrdef RocsWgen_imagepath = {
  "imagepath",  "load loco pictures from this path",  "",  "string",  "images",  "",  False,
};
static const char* _getimagepath(iONode node) {
  const char* defval = xStr( RocsWgen_imagepath );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_gui, node );
  return NodeOp.getStr( node, "imagepath", defval );
}
static void _setimagepath(iONode node, const char* p_imagepath) {
  if( node == NULL ) return;
  xNode( RocsWgen_gui, node );
  NodeOp.setStr( node, "imagepath", p_imagepath );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * jssupport
 */
static struct __attrdef RocsWgen_jssupport = {
  "jssupport",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isjssupport(iONode node) {
  Boolean defval = xBool( RocsWgen_jssupport );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_gui, node );
  return NodeOp.getBool( node, "jssupport", defval );
}
static void _setjssupport(iONode node, Boolean p_jssupport) {
  if( node == NULL ) return;
  xNode( RocsWgen_gui, node );
  NodeOp.setBool( node, "jssupport", p_jssupport );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * lang
 */
static struct __attrdef RocsWgen_lang = {
  "lang",  "",  "",  "string",  "en",  "en,de,nl,sv,fr,tr",  False,
};
static const char* _getlang(iONode node) {
  const char* defval = xStr( RocsWgen_lang );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_gui, node );
  return NodeOp.getStr( node, "lang", defval );
}
static void _setlang(iONode node, const char* p_lang) {
  if( node == NULL ) return;
  xNode( RocsWgen_gui, node );
  NodeOp.setStr( node, "lang", p_lang );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * lncvtab
 */
static struct __attrdef RocsWgen_lncvtab = {
  "lncvtab",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _islncvtab(iONode node) {
  Boolean defval = xBool( RocsWgen_lncvtab );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_gui, node );
  return NodeOp.getBool( node, "lncvtab", defval );
}
static void _setlncvtab(iONode node, Boolean p_lncvtab) {
  if( node == NULL ) return;
  xNode( RocsWgen_gui, node );
  NodeOp.setBool( node, "lncvtab", p_lncvtab );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * locoimagecolumn
 */
static struct __attrdef RocsWgen_locoimagecolumn = {
  "locoimagecolumn",  "",  "",  "bool",  "true",  "",  False,
};
static Boolean _islocoimagecolumn(iONode node) {
  Boolean defval = xBool( RocsWgen_locoimagecolumn );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_gui, node );
  return NodeOp.getBool( node, "locoimagecolumn", defval );
}
static void _setlocoimagecolumn(iONode node, Boolean p_locoimagecolumn) {
  if( node == NULL ) return;
  xNode( RocsWgen_gui, node );
  NodeOp.setBool( node, "locoimagecolumn", p_locoimagecolumn );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * locosortbyaddress
 */
static struct __attrdef RocsWgen_locosortbyaddress = {
  "locosortbyaddress",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _islocosortbyaddress(iONode node) {
  Boolean defval = xBool( RocsWgen_locosortbyaddress );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_gui, node );
  return NodeOp.getBool( node, "locosortbyaddress", defval );
}
static void _setlocosortbyaddress(iONode node, Boolean p_locosortbyaddress) {
  if( node == NULL ) return;
  xNode( RocsWgen_gui, node );
  NodeOp.setBool( node, "locosortbyaddress", p_locosortbyaddress );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * locowidgetstab
 */
static struct __attrdef RocsWgen_locowidgetstab = {
  "locowidgetstab",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _islocowidgetstab(iONode node) {
  Boolean defval = xBool( RocsWgen_locowidgetstab );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_gui, node );
  return NodeOp.getBool( node, "locowidgetstab", defval );
}
static void _setlocowidgetstab(iONode node, Boolean p_locowidgetstab) {
  if( node == NULL ) return;
  xNode( RocsWgen_gui, node );
  NodeOp.setBool( node, "locowidgetstab", p_locowidgetstab );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * locowidgetwidth
 */
static struct __attrdef RocsWgen_locowidgetwidth = {
  "locowidgetwidth",  "",  "",  "int",  "260",  "",  False,
};
static int _getlocowidgetwidth(iONode node) {
  int defval = xInt( RocsWgen_locowidgetwidth );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_gui, node );
  return NodeOp.getInt( node, "locowidgetwidth", defval );
}
static void _setlocowidgetwidth(iONode node, int p_locowidgetwidth) {
  if( node == NULL ) return;
  xNode( RocsWgen_gui, node );
  NodeOp.setInt( node, "locowidgetwidth", p_locowidgetwidth );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * monitoring
 */
static struct __attrdef RocsWgen_monitoring = {
  "monitoring",  "",  "",  "bool",  "true",  "",  False,
};
static Boolean _ismonitoring(iONode node) {
  Boolean defval = xBool( RocsWgen_monitoring );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_gui, node );
  return NodeOp.getBool( node, "monitoring", defval );
}
static void _setmonitoring(iONode node, Boolean p_monitoring) {
  if( node == NULL ) return;
  xNode( RocsWgen_gui, node );
  NodeOp.setBool( node, "monitoring", p_monitoring );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * monitorsize
 */
static struct __attrdef RocsWgen_monitorsize = {
  "monitorsize",  "",  "",  "int",  "4",  "",  False,
};
static int _getmonitorsize(iONode node) {
  int defval = xInt( RocsWgen_monitorsize );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_gui, node );
  return NodeOp.getInt( node, "monitorsize", defval );
}
static void _setmonitorsize(iONode node, int p_monitorsize) {
  if( node == NULL ) return;
  xNode( RocsWgen_gui, node );
  NodeOp.setInt( node, "monitorsize", p_monitorsize );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * openpath
 */
static struct __attrdef RocsWgen_openpath = {
  "openpath",  "use this path for init the file open dialog",  "",  "string",  ".",  "",  False,
};
static const char* _getopenpath(iONode node) {
  const char* defval = xStr( RocsWgen_openpath );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_gui, node );
  return NodeOp.getStr( node, "openpath", defval );
}
static void _setopenpath(iONode node, const char* p_openpath) {
  if( node == NULL ) return;
  xNode( RocsWgen_gui, node );
  NodeOp.setStr( node, "openpath", p_openpath );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * reconnectafterservershutdown
 */
static struct __attrdef RocsWgen_reconnectafterservershutdown = {
  "reconnectafterservershutdown",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isreconnectafterservershutdown(iONode node) {
  Boolean defval = xBool( RocsWgen_reconnectafterservershutdown );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_gui, node );
  return NodeOp.getBool( node, "reconnectafterservershutdown", defval );
}
static void _setreconnectafterservershutdown(iONode node, Boolean p_reconnectafterservershutdown) {
  if( node == NULL ) return;
  xNode( RocsWgen_gui, node );
  NodeOp.setBool( node, "reconnectafterservershutdown", p_reconnectafterservershutdown );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * rendergc
 */
static struct __attrdef RocsWgen_rendergc = {
  "rendergc",  "",  "",  "bool",  "true",  "",  False,
};
static Boolean _isrendergc(iONode node) {
  Boolean defval = xBool( RocsWgen_rendergc );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_gui, node );
  return NodeOp.getBool( node, "rendergc", defval );
}
static void _setrendergc(iONode node, Boolean p_rendergc) {
  if( node == NULL ) return;
  xNode( RocsWgen_gui, node );
  NodeOp.setBool( node, "rendergc", p_rendergc );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * resetspeeddir
 */
static struct __attrdef RocsWgen_resetspeeddir = {
  "resetspeeddir",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isresetspeeddir(iONode node) {
  Boolean defval = xBool( RocsWgen_resetspeeddir );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_gui, node );
  return NodeOp.getBool( node, "resetspeeddir", defval );
}
static void _setresetspeeddir(iONode node, Boolean p_resetspeeddir) {
  if( node == NULL ) return;
  xNode( RocsWgen_gui, node );
  NodeOp.setBool( node, "resetspeeddir", p_resetspeeddir );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * restorelcctrl
 */
static struct __attrdef RocsWgen_restorelcctrl = {
  "restorelcctrl",  "",  "",  "bool",  "true",  "",  False,
};
static Boolean _isrestorelcctrl(iONode node) {
  Boolean defval = xBool( RocsWgen_restorelcctrl );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_gui, node );
  return NodeOp.getBool( node, "restorelcctrl", defval );
}
static void _setrestorelcctrl(iONode node, Boolean p_restorelcctrl) {
  if( node == NULL ) return;
  xNode( RocsWgen_gui, node );
  NodeOp.setBool( node, "restorelcctrl", p_restorelcctrl );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * restrictedit4auto
 */
static struct __attrdef RocsWgen_restrictedit4auto = {
  "restrictedit4auto",  "",  "",  "bool",  "true",  "",  False,
};
static Boolean _isrestrictedit4auto(iONode node) {
  Boolean defval = xBool( RocsWgen_restrictedit4auto );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_gui, node );
  return NodeOp.getBool( node, "restrictedit4auto", defval );
}
static void _setrestrictedit4auto(iONode node, Boolean p_restrictedit4auto) {
  if( node == NULL ) return;
  xNode( RocsWgen_gui, node );
  NodeOp.setBool( node, "restrictedit4auto", p_restrictedit4auto );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * sensormonitorauto
 */
static struct __attrdef RocsWgen_sensormonitorauto = {
  "sensormonitorauto",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _issensormonitorauto(iONode node) {
  Boolean defval = xBool( RocsWgen_sensormonitorauto );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_gui, node );
  return NodeOp.getBool( node, "sensormonitorauto", defval );
}
static void _setsensormonitorauto(iONode node, Boolean p_sensormonitorauto) {
  if( node == NULL ) return;
  xNode( RocsWgen_gui, node );
  NodeOp.setBool( node, "sensormonitorauto", p_sensormonitorauto );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * showlocoimage
 */
static struct __attrdef RocsWgen_showlocoimage = {
  "showlocoimage",  "",  "",  "bool",  "true",  "",  False,
};
static Boolean _isshowlocoimage(iONode node) {
  Boolean defval = xBool( RocsWgen_showlocoimage );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_gui, node );
  return NodeOp.getBool( node, "showlocoimage", defval );
}
static void _setshowlocoimage(iONode node, Boolean p_showlocoimage) {
  if( node == NULL ) return;
  xNode( RocsWgen_gui, node );
  NodeOp.setBool( node, "showlocoimage", p_showlocoimage );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * showlocoimageinblock
 */
static struct __attrdef RocsWgen_showlocoimageinblock = {
  "showlocoimageinblock",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isshowlocoimageinblock(iONode node) {
  Boolean defval = xBool( RocsWgen_showlocoimageinblock );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_gui, node );
  return NodeOp.getBool( node, "showlocoimageinblock", defval );
}
static void _setshowlocoimageinblock(iONode node, Boolean p_showlocoimageinblock) {
  if( node == NULL ) return;
  xNode( RocsWgen_gui, node );
  NodeOp.setBool( node, "showlocoimageinblock", p_showlocoimageinblock );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * showonlystartschedules
 */
static struct __attrdef RocsWgen_showonlystartschedules = {
  "showonlystartschedules",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isshowonlystartschedules(iONode node) {
  Boolean defval = xBool( RocsWgen_showonlystartschedules );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_gui, node );
  return NodeOp.getBool( node, "showonlystartschedules", defval );
}
static void _setshowonlystartschedules(iONode node, Boolean p_showonlystartschedules) {
  if( node == NULL ) return;
  xNode( RocsWgen_gui, node );
  NodeOp.setBool( node, "showonlystartschedules", p_showonlystartschedules );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * showroute4switch
 */
static struct __attrdef RocsWgen_showroute4switch = {
  "showroute4switch",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isshowroute4switch(iONode node) {
  Boolean defval = xBool( RocsWgen_showroute4switch );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_gui, node );
  return NodeOp.getBool( node, "showroute4switch", defval );
}
static void _setshowroute4switch(iONode node, Boolean p_showroute4switch) {
  if( node == NULL ) return;
  xNode( RocsWgen_gui, node );
  NodeOp.setBool( node, "showroute4switch", p_showroute4switch );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * showsecondhand
 */
static struct __attrdef RocsWgen_showsecondhand = {
  "showsecondhand",  "",  "",  "bool",  "true",  "",  False,
};
static Boolean _isshowsecondhand(iONode node) {
  Boolean defval = xBool( RocsWgen_showsecondhand );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_gui, node );
  return NodeOp.getBool( node, "showsecondhand", defval );
}
static void _setshowsecondhand(iONode node, Boolean p_showsecondhand) {
  if( node == NULL ) return;
  xNode( RocsWgen_gui, node );
  NodeOp.setBool( node, "showsecondhand", p_showsecondhand );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * showspeedometer
 */
static struct __attrdef RocsWgen_showspeedometer = {
  "showspeedometer",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isshowspeedometer(iONode node) {
  Boolean defval = xBool( RocsWgen_showspeedometer );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_gui, node );
  return NodeOp.getBool( node, "showspeedometer", defval );
}
static void _setshowspeedometer(iONode node, Boolean p_showspeedometer) {
  if( node == NULL ) return;
  xNode( RocsWgen_gui, node );
  NodeOp.setBool( node, "showspeedometer", p_showspeedometer );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * showtrainidinblock
 */
static struct __attrdef RocsWgen_showtrainidinblock = {
  "showtrainidinblock",  "",  "",  "bool",  "true",  "",  False,
};
static Boolean _isshowtrainidinblock(iONode node) {
  Boolean defval = xBool( RocsWgen_showtrainidinblock );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_gui, node );
  return NodeOp.getBool( node, "showtrainidinblock", defval );
}
static void _setshowtrainidinblock(iONode node, Boolean p_showtrainidinblock) {
  if( node == NULL ) return;
  xNode( RocsWgen_gui, node );
  NodeOp.setBool( node, "showtrainidinblock", p_showtrainidinblock );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * simulatesensors
 */
static struct __attrdef RocsWgen_simulatesensors = {
  "simulatesensors",  "",  "",  "bool",  "true",  "",  False,
};
static Boolean _issimulatesensors(iONode node) {
  Boolean defval = xBool( RocsWgen_simulatesensors );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_gui, node );
  return NodeOp.getBool( node, "simulatesensors", defval );
}
static void _setsimulatesensors(iONode node, Boolean p_simulatesensors) {
  if( node == NULL ) return;
  xNode( RocsWgen_gui, node );
  NodeOp.setBool( node, "simulatesensors", p_simulatesensors );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * speak4block
 */
static struct __attrdef RocsWgen_speak4block = {
  "speak4block",  "",  "",  "string",  "",  "",  False,
};
static const char* _getspeak4block(iONode node) {
  const char* defval = xStr( RocsWgen_speak4block );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_gui, node );
  return NodeOp.getStr( node, "speak4block", defval );
}
static void _setspeak4block(iONode node, const char* p_speak4block) {
  if( node == NULL ) return;
  xNode( RocsWgen_gui, node );
  NodeOp.setStr( node, "speak4block", p_speak4block );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * speakcmd
 */
static struct __attrdef RocsWgen_speakcmd = {
  "speakcmd",  "",  "",  "string",  "",  "",  False,
};
static const char* _getspeakcmd(iONode node) {
  const char* defval = xStr( RocsWgen_speakcmd );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_gui, node );
  return NodeOp.getStr( node, "speakcmd", defval );
}
static void _setspeakcmd(iONode node, const char* p_speakcmd) {
  if( node == NULL ) return;
  xNode( RocsWgen_gui, node );
  NodeOp.setStr( node, "speakcmd", p_speakcmd );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * startdefaultworkspace
 */
static struct __attrdef RocsWgen_startdefaultworkspace = {
  "startdefaultworkspace",  "",  "",  "bool",  "true",  "",  False,
};
static Boolean _isstartdefaultworkspace(iONode node) {
  Boolean defval = xBool( RocsWgen_startdefaultworkspace );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_gui, node );
  return NodeOp.getBool( node, "startdefaultworkspace", defval );
}
static void _setstartdefaultworkspace(iONode node, Boolean p_startdefaultworkspace) {
  if( node == NULL ) return;
  xNode( RocsWgen_gui, node );
  NodeOp.setBool( node, "startdefaultworkspace", p_startdefaultworkspace );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * statusboosteruid
 */
static struct __attrdef RocsWgen_statusboosteruid = {
  "statusboosteruid",  "",  "",  "int",  "0",  "",  False,
};
static int _getstatusboosteruid(iONode node) {
  int defval = xInt( RocsWgen_statusboosteruid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_gui, node );
  return NodeOp.getInt( node, "statusboosteruid", defval );
}
static void _setstatusboosteruid(iONode node, int p_statusboosteruid) {
  if( node == NULL ) return;
  xNode( RocsWgen_gui, node );
  NodeOp.setInt( node, "statusboosteruid", p_statusboosteruid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * tabalign
 */
static struct __attrdef RocsWgen_tabalign = {
  "tabalign",  "0 default, 1 left, 2 multiline",  "",  "int",  "0",  "0-2",  False,
};
static int _gettabalign(iONode node) {
  int defval = xInt( RocsWgen_tabalign );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_gui, node );
  return NodeOp.getInt( node, "tabalign", defval );
}
static void _settabalign(iONode node, int p_tabalign) {
  if( node == NULL ) return;
  xNode( RocsWgen_gui, node );
  NodeOp.setInt( node, "tabalign", p_tabalign );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * toolbar
 */
static struct __attrdef RocsWgen_toolbar = {
  "toolbar",  "",  "",  "bool",  "true",  "",  False,
};
static Boolean _istoolbar(iONode node) {
  Boolean defval = xBool( RocsWgen_toolbar );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_gui, node );
  return NodeOp.getBool( node, "toolbar", defval );
}
static void _settoolbar(iONode node, Boolean p_toolbar) {
  if( node == NULL ) return;
  xNode( RocsWgen_gui, node );
  NodeOp.setBool( node, "toolbar", p_toolbar );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * updatespath
 */
static struct __attrdef RocsWgen_updatespath = {
  "updatespath",  "download updates in this path",  "",  "string",  "updates",  "",  False,
};
static const char* _getupdatespath(iONode node) {
  const char* defval = xStr( RocsWgen_updatespath );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_gui, node );
  return NodeOp.getStr( node, "updatespath", defval );
}
static void _setupdatespath(iONode node, const char* p_updatespath) {
  if( node == NULL ) return;
  xNode( RocsWgen_gui, node );
  NodeOp.setStr( node, "updatespath", p_updatespath );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * updatesserver
 */
static struct __attrdef RocsWgen_updatesserver = {
  "updatesserver",  "location of updates",  "",  "string",  "rocrail.net",  "",  False,
};
static const char* _getupdatesserver(iONode node) {
  const char* defval = xStr( RocsWgen_updatesserver );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_gui, node );
  return NodeOp.getStr( node, "updatesserver", defval );
}
static void _setupdatesserver(iONode node, const char* p_updatesserver) {
  if( node == NULL ) return;
  xNode( RocsWgen_gui, node );
  NodeOp.setStr( node, "updatesserver", p_updatesserver );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * updatestimestamp
 */
static struct __attrdef RocsWgen_updatestimestamp = {
  "updatestimestamp",  "timestamp of last viewed updates xml for the update notifier; this number increases after adding items on the server",  "",  "long",  "0",  "",  False,
};
static long _getupdatestimestamp(iONode node) {
  long defval = xLong( RocsWgen_updatestimestamp );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_gui, node );
  return NodeOp.getLong( node, "updatestimestamp", defval );
}
static void _setupdatestimestamp(iONode node, long p_updatestimestamp) {
  if( node == NULL ) return;
  xNode( RocsWgen_gui, node );
  NodeOp.setLong( node, "updatestimestamp", p_updatestimestamp );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * useallspeedsteps
 */
static struct __attrdef RocsWgen_useallspeedsteps = {
  "useallspeedsteps",  "",  "",  "bool",  "true",  "",  False,
};
static Boolean _isuseallspeedsteps(iONode node) {
  Boolean defval = xBool( RocsWgen_useallspeedsteps );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_gui, node );
  return NodeOp.getBool( node, "useallspeedsteps", defval );
}
static void _setuseallspeedsteps(iONode node, Boolean p_useallspeedsteps) {
  if( node == NULL ) return;
  xNode( RocsWgen_gui, node );
  NodeOp.setBool( node, "useallspeedsteps", p_useallspeedsteps );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * verticaltoolbar
 */
static struct __attrdef RocsWgen_verticaltoolbar = {
  "verticaltoolbar",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isverticaltoolbar(iONode node) {
  Boolean defval = xBool( RocsWgen_verticaltoolbar );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_gui, node );
  return NodeOp.getBool( node, "verticaltoolbar", defval );
}
static void _setverticaltoolbar(iONode node, Boolean p_verticaltoolbar) {
  if( node == NULL ) return;
  xNode( RocsWgen_gui, node );
  NodeOp.setBool( node, "verticaltoolbar", p_verticaltoolbar );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * xslpath
 */
static struct __attrdef RocsWgen_xslpath = {
  "xslpath",  "reference stylsheets to this path",  "",  "string",  "stylesheets",  "",  False,
};
static const char* _getxslpath(iONode node) {
  const char* defval = xStr( RocsWgen_xslpath );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_gui, node );
  return NodeOp.getStr( node, "xslpath", defval );
}
static void _setxslpath(iONode node, const char* p_xslpath) {
  if( node == NULL ) return;
  xNode( RocsWgen_gui, node );
  NodeOp.setStr( node, "xslpath", p_xslpath );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * trace
 */
static struct __nodedef RocsWgen_trace = {
  "trace",  "",  False,  "1",};
static iONode _gettrace(iONode node) {
  xNode( RocsWgen_gui, node );
  return NodeOp.findNode( node, "trace");
}


static iONode _nexttrace(iONode node, iONode child) {
  xNode( RocsWgen_gui, node );
  return NodeOp.findNextNode( node, child);
}
static void _settrace(iONode node, iONode p_trace) {
  xNode( RocsWgen_gui, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * accelerator
 */
static struct __nodedef RocsWgen_accelerator = {
  "accelerator",  "",  False,  "n",};
static iONode _getaccelerator(iONode node) {
  xNode( RocsWgen_gui, node );
  return NodeOp.findNode( node, "accelerator");
}


static iONode _nextaccelerator(iONode node, iONode child) {
  xNode( RocsWgen_gui, node );
  return NodeOp.findNextNode( node, child);
}
static void _setaccelerator(iONode node, iONode p_accelerator) {
  xNode( RocsWgen_gui, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * workspaces
 */
static struct __nodedef RocsWgen_workspaces = {
  "workspaces",  "",  False,  "1",};
static iONode _getworkspaces(iONode node) {
  xNode( RocsWgen_gui, node );
  return NodeOp.findNode( node, "workspaces");
}


static iONode _nextworkspaces(iONode node, iONode child) {
  xNode( RocsWgen_gui, node );
  return NodeOp.findNextNode( node, child);
}
static void _setworkspaces(iONode node, iONode p_workspaces) {
  xNode( RocsWgen_gui, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * swctrl
 */
static struct __nodedef RocsWgen_swctrl = {
  "swctrl",  "",  False,  "1",};
static iONode _getswctrl(iONode node) {
  xNode( RocsWgen_gui, node );
  return NodeOp.findNode( node, "swctrl");
}


static iONode _nextswctrl(iONode node, iONode child) {
  xNode( RocsWgen_gui, node );
  return NodeOp.findNextNode( node, child);
}
static void _setswctrl(iONode node, iONode p_swctrl) {
  xNode( RocsWgen_gui, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * mgv
 */
static struct __nodedef RocsWgen_mgv = {
  "mgv",  "",  False,  "1",};
static iONode _getmgv(iONode node) {
  xNode( RocsWgen_gui, node );
  return NodeOp.findNode( node, "mgv");
}


static iONode _nextmgv(iONode node, iONode child) {
  xNode( RocsWgen_gui, node );
  return NodeOp.findNextNode( node, child);
}
static void _setmgv(iONode node, iONode p_mgv) {
  xNode( RocsWgen_gui, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * rrcon
 */
static struct __nodedef RocsWgen_rrcon = {
  "rrcon",  "",  False,  "n",};
static iONode _getrrcon(iONode node) {
  xNode( RocsWgen_gui, node );
  return NodeOp.findNode( node, "rrcon");
}


static iONode _nextrrcon(iONode node, iONode child) {
  xNode( RocsWgen_gui, node );
  return NodeOp.findNextNode( node, child);
}
static void _setrrcon(iONode node, iONode p_rrcon) {
  xNode( RocsWgen_gui, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * modpanel
 */
static struct __nodedef RocsWgen_modpanel = {
  "modpanel",  "",  False,  "1",};
static iONode _getmodpanel(iONode node) {
  xNode( RocsWgen_gui, node );
  return NodeOp.findNode( node, "modpanel");
}


static iONode _nextmodpanel(iONode node, iONode child) {
  xNode( RocsWgen_gui, node );
  return NodeOp.findNextNode( node, child);
}
static void _setmodpanel(iONode node, iONode p_modpanel) {
  xNode( RocsWgen_gui, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * planpanel
 */
static struct __nodedef RocsWgen_planpanel = {
  "planpanel",  "",  False,  "1",};
static iONode _getplanpanel(iONode node) {
  xNode( RocsWgen_gui, node );
  return NodeOp.findNode( node, "planpanel");
}


static iONode _nextplanpanel(iONode node, iONode child) {
  xNode( RocsWgen_gui, node );
  return NodeOp.findNextNode( node, child);
}
static void _setplanpanel(iONode node, iONode p_planpanel) {
  xNode( RocsWgen_gui, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * tab
 */
static struct __nodedef RocsWgen_tab = {
  "tab",  "",  False,  "n",};
static iONode _gettab(iONode node) {
  xNode( RocsWgen_gui, node );
  return NodeOp.findNode( node, "tab");
}


static iONode _nexttab(iONode node, iONode child) {
  xNode( RocsWgen_gui, node );
  return NodeOp.findNextNode( node, child);
}
static void _settab(iONode node, iONode p_tab) {
  xNode( RocsWgen_gui, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * splitpanel
 */
static struct __nodedef RocsWgen_splitpanel = {
  "splitpanel",  "",  False,  "1",};
static iONode _getsplitpanel(iONode node) {
  xNode( RocsWgen_gui, node );
  return NodeOp.findNode( node, "splitpanel");
}


static iONode _nextsplitpanel(iONode node, iONode child) {
  xNode( RocsWgen_gui, node );
  return NodeOp.findNextNode( node, child);
}
static void _setsplitpanel(iONode node, iONode p_splitpanel) {
  xNode( RocsWgen_gui, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * window
 */
static struct __nodedef RocsWgen_window = {
  "window",  "",  False,  "1",};
static iONode _getwindow(iONode node) {
  xNode( RocsWgen_gui, node );
  return NodeOp.findNode( node, "window");
}


static iONode _nextwindow(iONode node, iONode child) {
  xNode( RocsWgen_gui, node );
  return NodeOp.findNextNode( node, child);
}
static void _setwindow(iONode node, iONode p_window) {
  xNode( RocsWgen_gui, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * jsmap
 */
static struct __nodedef RocsWgen_jsmap = {
  "jsmap",  "",  False,  "1",};
static iONode _getjsmap(iONode node) {
  xNode( RocsWgen_gui, node );
  return NodeOp.findNode( node, "jsmap");
}


static iONode _nextjsmap(iONode node, iONode child) {
  xNode( RocsWgen_gui, node );
  return NodeOp.findNextNode( node, child);
}
static void _setjsmap(iONode node, iONode p_jsmap) {
  xNode( RocsWgen_gui, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * mic
 */
static struct __nodedef RocsWgen_mic = {
  "mic",  "Mouse Integrated Controller",  False,  "1",};
static iONode _getmic(iONode node) {
  xNode( RocsWgen_gui, node );
  return NodeOp.findNode( node, "mic");
}


static iONode _nextmic(iONode node, iONode child) {
  xNode( RocsWgen_gui, node );
  return NodeOp.findNextNode( node, child);
}
static void _setmic(iONode node, iONode p_mic) {
  xNode( RocsWgen_gui, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * cvconf
 */
static struct __nodedef RocsWgen_cvconf = {
  "cvconf",  "",  False,  "1",};
static iONode _getcvconf(iONode node) {
  xNode( RocsWgen_gui, node );
  return NodeOp.findNode( node, "cvconf");
}


static iONode _nextcvconf(iONode node, iONode child) {
  xNode( RocsWgen_gui, node );
  return NodeOp.findNextNode( node, child);
}
static void _setcvconf(iONode node, iONode p_cvconf) {
  xNode( RocsWgen_gui, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * lcctrl
 */
static struct __nodedef RocsWgen_lcctrl = {
  "lcctrl",  "",  False,  "1",};
static iONode _getlcctrl(iONode node) {
  xNode( RocsWgen_gui, node );
  return NodeOp.findNode( node, "lcctrl");
}


static iONode _nextlcctrl(iONode node, iONode child) {
  xNode( RocsWgen_gui, node );
  return NodeOp.findNextNode( node, child);
}
static void _setlcctrl(iONode node, iONode p_lcctrl) {
  xNode( RocsWgen_gui, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * powerctrl
 */
static struct __nodedef RocsWgen_powerctrl = {
  "powerctrl",  "",  False,  "1",};
static iONode _getpowerctrl(iONode node) {
  xNode( RocsWgen_gui, node );
  return NodeOp.findNode( node, "powerctrl");
}


static iONode _nextpowerctrl(iONode node, iONode child) {
  xNode( RocsWgen_gui, node );
  return NodeOp.findNextNode( node, child);
}
static void _setpowerctrl(iONode node, iONode p_powerctrl) {
  xNode( RocsWgen_gui, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * sensormonitor
 */
static struct __nodedef RocsWgen_sensormonitor = {
  "sensormonitor",  "",  False,  "1",};
static iONode _getsensormonitor(iONode node) {
  xNode( RocsWgen_gui, node );
  return NodeOp.findNode( node, "sensormonitor");
}


static iONode _nextsensormonitor(iONode node, iONode child) {
  xNode( RocsWgen_gui, node );
  return NodeOp.findNextNode( node, child);
}
static void _setsensormonitor(iONode node, iONode p_sensormonitor) {
  xNode( RocsWgen_gui, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * locogrid
 */
static struct __nodedef RocsWgen_locogrid = {
  "locogrid",  "",  False,  "1",};
static iONode _getlocogrid(iONode node) {
  xNode( RocsWgen_gui, node );
  return NodeOp.findNode( node, "locogrid");
}


static iONode _nextlocogrid(iONode node, iONode child) {
  xNode( RocsWgen_gui, node );
  return NodeOp.findNextNode( node, child);
}
static void _setlocogrid(iONode node, iONode p_locogrid) {
  xNode( RocsWgen_gui, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[51] = {NULL};
static struct __nodedef* nodeList[19] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_gui.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node gui not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node gui not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_checkupdates;
  attrList[1] = &RocsWgen_clocktype;
  attrList[2] = &RocsWgen_decpath;
  attrList[3] = &RocsWgen_defaultworkspace;
  attrList[4] = &RocsWgen_dirimagefwd;
  attrList[5] = &RocsWgen_dirimagerev;
  attrList[6] = &RocsWgen_dispatchmode;
  attrList[7] = &RocsWgen_fsutf8;
  attrList[8] = &RocsWgen_grayicons;
  attrList[9] = &RocsWgen_gridfontsizeadjust;
  attrList[10] = &RocsWgen_helpurl;
  attrList[11] = &RocsWgen_host;
  attrList[12] = &RocsWgen_id;
  attrList[13] = &RocsWgen_imagepath;
  attrList[14] = &RocsWgen_jssupport;
  attrList[15] = &RocsWgen_lang;
  attrList[16] = &RocsWgen_lncvtab;
  attrList[17] = &RocsWgen_locoimagecolumn;
  attrList[18] = &RocsWgen_locosortbyaddress;
  attrList[19] = &RocsWgen_locowidgetstab;
  attrList[20] = &RocsWgen_locowidgetwidth;
  attrList[21] = &RocsWgen_monitoring;
  attrList[22] = &RocsWgen_monitorsize;
  attrList[23] = &RocsWgen_openpath;
  attrList[24] = &RocsWgen_reconnectafterservershutdown;
  attrList[25] = &RocsWgen_rendergc;
  attrList[26] = &RocsWgen_resetspeeddir;
  attrList[27] = &RocsWgen_restorelcctrl;
  attrList[28] = &RocsWgen_restrictedit4auto;
  attrList[29] = &RocsWgen_sensormonitorauto;
  attrList[30] = &RocsWgen_showlocoimage;
  attrList[31] = &RocsWgen_showlocoimageinblock;
  attrList[32] = &RocsWgen_showonlystartschedules;
  attrList[33] = &RocsWgen_showroute4switch;
  attrList[34] = &RocsWgen_showsecondhand;
  attrList[35] = &RocsWgen_showspeedometer;
  attrList[36] = &RocsWgen_showtrainidinblock;
  attrList[37] = &RocsWgen_simulatesensors;
  attrList[38] = &RocsWgen_speak4block;
  attrList[39] = &RocsWgen_speakcmd;
  attrList[40] = &RocsWgen_startdefaultworkspace;
  attrList[41] = &RocsWgen_statusboosteruid;
  attrList[42] = &RocsWgen_tabalign;
  attrList[43] = &RocsWgen_toolbar;
  attrList[44] = &RocsWgen_updatespath;
  attrList[45] = &RocsWgen_updatesserver;
  attrList[46] = &RocsWgen_updatestimestamp;
  attrList[47] = &RocsWgen_useallspeedsteps;
  attrList[48] = &RocsWgen_verticaltoolbar;
  attrList[49] = &RocsWgen_xslpath;
  attrList[50] = NULL;
  nodeList[0] = &RocsWgen_trace;
  nodeList[1] = &RocsWgen_accelerator;
  nodeList[2] = &RocsWgen_workspaces;
  nodeList[3] = &RocsWgen_swctrl;
  nodeList[4] = &RocsWgen_mgv;
  nodeList[5] = &RocsWgen_rrcon;
  nodeList[6] = &RocsWgen_modpanel;
  nodeList[7] = &RocsWgen_planpanel;
  nodeList[8] = &RocsWgen_tab;
  nodeList[9] = &RocsWgen_splitpanel;
  nodeList[10] = &RocsWgen_window;
  nodeList[11] = &RocsWgen_jsmap;
  nodeList[12] = &RocsWgen_mic;
  nodeList[13] = &RocsWgen_cvconf;
  nodeList[14] = &RocsWgen_lcctrl;
  nodeList[15] = &RocsWgen_powerctrl;
  nodeList[16] = &RocsWgen_sensormonitor;
  nodeList[17] = &RocsWgen_locogrid;
  nodeList[18] = NULL;
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


struct __wGui wGui = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  __DATE__,
  __TIME__,
  "24h",
  "ampm",
  "default",
  "digital",
  "none",
  "rocview.ini",
  "be",
  "bs",
  "bg",
  "ca",
  "zh_TW",
  "zh_CN",
  "cs",
  "da",
  "nl",
  "en",
  "en_AU",
  "en_CA",
  "en_GB",
  "fi",
  "fr",
  "de",
  "el",
  "hu",
  "id",
  "it",
  "ja",
  "ko",
  "nb",
  "pl",
  "pt",
  "pt_BR",
  "ro",
  "ru",
  "sr_latin",
  "sl",
  "es",
  "sv",
  "tr",
  999,
  "rocview.ini",
  "Rocrail",
  "Sunrise",
  "snapshot",
  2,
  0,
  _ischeckupdates,
  _setcheckupdates,
  _getclocktype,
  _setclocktype,
  _getdecpath,
  _setdecpath,
  _getdefaultworkspace,
  _setdefaultworkspace,
  _getdirimagefwd,
  _setdirimagefwd,
  _getdirimagerev,
  _setdirimagerev,
  _isdispatchmode,
  _setdispatchmode,
  _isfsutf8,
  _setfsutf8,
  _isgrayicons,
  _setgrayicons,
  _getgridfontsizeadjust,
  _setgridfontsizeadjust,
  _gethelpurl,
  _sethelpurl,
  _gethost,
  _sethost,
  _getid,
  _setid,
  _getimagepath,
  _setimagepath,
  _isjssupport,
  _setjssupport,
  _getlang,
  _setlang,
  _islncvtab,
  _setlncvtab,
  _islocoimagecolumn,
  _setlocoimagecolumn,
  _islocosortbyaddress,
  _setlocosortbyaddress,
  _islocowidgetstab,
  _setlocowidgetstab,
  _getlocowidgetwidth,
  _setlocowidgetwidth,
  _ismonitoring,
  _setmonitoring,
  _getmonitorsize,
  _setmonitorsize,
  _getopenpath,
  _setopenpath,
  _isreconnectafterservershutdown,
  _setreconnectafterservershutdown,
  _isrendergc,
  _setrendergc,
  _isresetspeeddir,
  _setresetspeeddir,
  _isrestorelcctrl,
  _setrestorelcctrl,
  _isrestrictedit4auto,
  _setrestrictedit4auto,
  _issensormonitorauto,
  _setsensormonitorauto,
  _isshowlocoimage,
  _setshowlocoimage,
  _isshowlocoimageinblock,
  _setshowlocoimageinblock,
  _isshowonlystartschedules,
  _setshowonlystartschedules,
  _isshowroute4switch,
  _setshowroute4switch,
  _isshowsecondhand,
  _setshowsecondhand,
  _isshowspeedometer,
  _setshowspeedometer,
  _isshowtrainidinblock,
  _setshowtrainidinblock,
  _issimulatesensors,
  _setsimulatesensors,
  _getspeak4block,
  _setspeak4block,
  _getspeakcmd,
  _setspeakcmd,
  _isstartdefaultworkspace,
  _setstartdefaultworkspace,
  _getstatusboosteruid,
  _setstatusboosteruid,
  _gettabalign,
  _settabalign,
  _istoolbar,
  _settoolbar,
  _getupdatespath,
  _setupdatespath,
  _getupdatesserver,
  _setupdatesserver,
  _getupdatestimestamp,
  _setupdatestimestamp,
  _isuseallspeedsteps,
  _setuseallspeedsteps,
  _isverticaltoolbar,
  _setverticaltoolbar,
  _getxslpath,
  _setxslpath,
  _gettrace,
  _nexttrace,
  _settrace,
  _getaccelerator,
  _nextaccelerator,
  _setaccelerator,
  _getworkspaces,
  _nextworkspaces,
  _setworkspaces,
  _getswctrl,
  _nextswctrl,
  _setswctrl,
  _getmgv,
  _nextmgv,
  _setmgv,
  _getrrcon,
  _nextrrcon,
  _setrrcon,
  _getmodpanel,
  _nextmodpanel,
  _setmodpanel,
  _getplanpanel,
  _nextplanpanel,
  _setplanpanel,
  _gettab,
  _nexttab,
  _settab,
  _getsplitpanel,
  _nextsplitpanel,
  _setsplitpanel,
  _getwindow,
  _nextwindow,
  _setwindow,
  _getjsmap,
  _nextjsmap,
  _setjsmap,
  _getmic,
  _nextmic,
  _setmic,
  _getcvconf,
  _nextcvconf,
  _setcvconf,
  _getlcctrl,
  _nextlcctrl,
  _setlcctrl,
  _getpowerctrl,
  _nextpowerctrl,
  _setpowerctrl,
  _getsensormonitor,
  _nextsensormonitor,
  _setsensormonitor,
  _getlocogrid,
  _nextlocogrid,
  _setlocogrid,
  _node_dump,
};
