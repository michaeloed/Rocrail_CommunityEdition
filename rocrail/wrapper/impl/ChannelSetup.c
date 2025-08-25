/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/ChannelSetup.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.ChannelSetup
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_channelsetup = {
  "channelsetup",  "",  False,  "n",
};

static const char* _node_name(void) {
  return RocsWgen_channelsetup.name;
}
static const char* _node_remark(void) {
  return RocsWgen_channelsetup.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_channelsetup.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_channelsetup.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * channel
 */
static struct __attrdef RocsWgen_channel = {
  "channel",  "",  "",  "int",  "0",  "0-15",  False,
};
static int _getchannel(iONode node) {
  int defval = xInt( RocsWgen_channel );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_channelsetup, node );
  return NodeOp.getInt( node, "channel", defval );
}
static void _setchannel(iONode node, int p_channel) {
  if( node == NULL ) return;
  xNode( RocsWgen_channelsetup, node );
  NodeOp.setInt( node, "channel", p_channel );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * delay
 */
static struct __attrdef RocsWgen_delay = {
  "delay",  "0=10ms, 1=20ms, ...",  "",  "int",  "0",  "0-*",  False,
};
static int _getdelay(iONode node) {
  int defval = xInt( RocsWgen_delay );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_channelsetup, node );
  return NodeOp.getInt( node, "delay", defval );
}
static void _setdelay(iONode node, int p_delay) {
  if( node == NULL ) return;
  xNode( RocsWgen_channelsetup, node );
  NodeOp.setInt( node, "delay", p_delay );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * offpos
 */
static struct __attrdef RocsWgen_offpos = {
  "offpos",  "",  "",  "int",  "150",  "0-4095",  False,
};
static int _getoffpos(iONode node) {
  int defval = xInt( RocsWgen_offpos );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_channelsetup, node );
  return NodeOp.getInt( node, "offpos", defval );
}
static void _setoffpos(iONode node, int p_offpos) {
  if( node == NULL ) return;
  xNode( RocsWgen_channelsetup, node );
  NodeOp.setInt( node, "offpos", p_offpos );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * offsteps
 */
static struct __attrdef RocsWgen_offsteps = {
  "offsteps",  "",  "",  "int",  "10",  "0-255",  False,
};
static int _getoffsteps(iONode node) {
  int defval = xInt( RocsWgen_offsteps );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_channelsetup, node );
  return NodeOp.getInt( node, "offsteps", defval );
}
static void _setoffsteps(iONode node, int p_offsteps) {
  if( node == NULL ) return;
  xNode( RocsWgen_channelsetup, node );
  NodeOp.setInt( node, "offsteps", p_offsteps );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * onpos
 */
static struct __attrdef RocsWgen_onpos = {
  "onpos",  "",  "",  "int",  "600",  "0-4095",  False,
};
static int _getonpos(iONode node) {
  int defval = xInt( RocsWgen_onpos );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_channelsetup, node );
  return NodeOp.getInt( node, "onpos", defval );
}
static void _setonpos(iONode node, int p_onpos) {
  if( node == NULL ) return;
  xNode( RocsWgen_channelsetup, node );
  NodeOp.setInt( node, "onpos", p_onpos );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * onsteps
 */
static struct __attrdef RocsWgen_onsteps = {
  "onsteps",  "",  "",  "int",  "10",  "0-255",  False,
};
static int _getonsteps(iONode node) {
  int defval = xInt( RocsWgen_onsteps );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_channelsetup, node );
  return NodeOp.getInt( node, "onsteps", defval );
}
static void _setonsteps(iONode node, int p_onsteps) {
  if( node == NULL ) return;
  xNode( RocsWgen_channelsetup, node );
  NodeOp.setInt( node, "onsteps", p_onsteps );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * options
 */
static struct __attrdef RocsWgen_options = {
  "options",  "",  "",  "int",  "0",  "",  False,
};
static int _getoptions(iONode node) {
  int defval = xInt( RocsWgen_options );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_channelsetup, node );
  return NodeOp.getInt( node, "options", defval );
}
static void _setoptions(iONode node, int p_options) {
  if( node == NULL ) return;
  xNode( RocsWgen_channelsetup, node );
  NodeOp.setInt( node, "options", p_options );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * state
 */
static struct __attrdef RocsWgen_state = {
  "state",  "Saved output state.",  "",  "int",  "0",  "",  False,
};
static int _getstate(iONode node) {
  int defval = xInt( RocsWgen_state );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_channelsetup, node );
  return NodeOp.getInt( node, "state", defval );
}
static void _setstate(iONode node, int p_state) {
  if( node == NULL ) return;
  xNode( RocsWgen_channelsetup, node );
  NodeOp.setInt( node, "state", p_state );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[9] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_channelsetup.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node channelsetup not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node channelsetup not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_channel;
  attrList[1] = &RocsWgen_delay;
  attrList[2] = &RocsWgen_offpos;
  attrList[3] = &RocsWgen_offsteps;
  attrList[4] = &RocsWgen_onpos;
  attrList[5] = &RocsWgen_onsteps;
  attrList[6] = &RocsWgen_options;
  attrList[7] = &RocsWgen_state;
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


struct __wChannelSetup wChannelSetup = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getchannel,
  _setchannel,
  _getdelay,
  _setdelay,
  _getoffpos,
  _setoffpos,
  _getoffsteps,
  _setoffsteps,
  _getonpos,
  _setonpos,
  _getonsteps,
  _setonsteps,
  _getoptions,
  _setoptions,
  _getstate,
  _setstate,
  _node_dump,
};
