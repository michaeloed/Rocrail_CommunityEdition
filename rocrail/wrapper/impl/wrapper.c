/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/str.h"
#include "rocs/public/wutils.h"

Boolean xBool( struct __attrdef attr) { 
  if( attr.defval != NULL && StrOp.equalsi( "true", attr.defval ) )
    return True;
  else
    return False;
} 
int xInt( struct __attrdef attr) {
  if( attr.defval == NULL )
    return 0;
  return atoi( attr.defval );
} 
long xLong( struct __attrdef attr) {
  if( attr.defval == NULL )
    return 0;
  return atol( attr.defval );
} 
double xFloat( struct __attrdef attr) {
  if( attr.defval == NULL )
    return 0.0;
  return atof( attr.defval );
} 
const char* xStr( struct __attrdef attr) {
  if( attr.defval == NULL || StrOp.equalsi( "NULL", attr.defval ) )
    return NULL;
  return attr.defval;
} 
Boolean xNode( struct __nodedef def, iONode node ) {
  if( !StrOp.equalsi( def.name, NodeOp.getName( node ) ) ) {
    TraceOp.trc( "wrapper", TRCLEVEL_WRAPPER, __LINE__, 9999, "Wrong wrapper? NodeName %s expected instead of %s", def.name, NodeOp.getName( node ) );
    return False;
  } 
  return True;
} 
Boolean xAttr( struct __attrdef* def, iONode node ) {
  Boolean ok = True;
  iOAttr attr = NodeOp.findAttr( node, (const char*)def->name );
  if( attr == NULL && def->required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required attribute %s.%s not found!", NodeOp.getName( node ), def->name );
    return False;
  } 
  else if( attr == NULL && !def->required ) {
    return True;
  } 
  ok = wUtils.checkAttrRange( NodeOp.getName( node ), def->name, def->vtype, def->range, NodeOp.getStr( node, def->name, def->defval ) );
  if( !ok && !def->required ) {
    NodeOp.setStr( node, def->name, StrOp.dup( def->defval ) );
    ok = True;
    TraceOp.trc( "param", TRCLEVEL_WARNING, __LINE__, 9999, "Using default [%s%s] for %s.%s.", def->defval, def->unit, NodeOp.getName( node ), def->name );
  } 
  return ok;
} 
Boolean xAttrTest( struct __attrdef* def[], iONode node ) {
  Boolean ok = True;
  int i = 0;
  int cnt = NodeOp.getAttrCnt( node );
  TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Testing %d attributes in node [%s]", cnt, NodeOp.getName( node ) );
  for( i = 0; i < cnt; i++ ) {
    iOAttr attr = NodeOp.getAttr( node, i );
    int n = 0;
    Boolean attrMatch = False;
    struct __attrdef* attrdef = def[n];
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Checking attribute [%s] in node [%s]", AttrOp.getName( attr ), NodeOp.getName( node ) );
    while( attrdef ) {
      if( StrOp.equalsi( AttrOp.getName( attr ), attrdef->name ) ) {
        attrMatch = True;
        break;
      };
      n++;
      attrdef = def[n];
    };
    if( !attrMatch && n > 0 ) {
      ok = False;
      TraceOp.trc( "param", TRCLEVEL_WARNING, __LINE__, 9999, "Unknown attribute [%s] found in node [%s]", AttrOp.getName( attr ), NodeOp.getName( node ) );
    } 
  }
  return ok;
} 
Boolean xNodeTest( struct __nodedef* def[], iONode node ) {
  Boolean ok = True;
  int i = 0;
  int cnt = NodeOp.getChildCnt( node );
  TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Testing %d childnodes in node [%s]", cnt, NodeOp.getName( node ) );
  for( i = 0; i < cnt; i++ ) {
    iONode childnode = NodeOp.getChild( node, i );
    int n = 0;
    Boolean nodeMatch = False;
    struct __nodedef* nodedef = def[n];
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Checking childnode [%s] in node [%s]", NodeOp.getName( childnode ), NodeOp.getName( node ) );
    while( nodedef ) {
      if( StrOp.equalsi( NodeOp.getName( childnode ), nodedef->name ) || StrOp.equalsi( NodeOp.getName( childnode ), "remark" ) ) {
        nodeMatch = True;
        break;
      };
      n++;
      nodedef = def[n];
    };
    if( !nodeMatch && n > 0 ) {
      ok = False;
      TraceOp.trc( "param", TRCLEVEL_WARNING, __LINE__, 9999, "Unknown childnode [%s] found in node [%s]", NodeOp.getName( childnode ), NodeOp.getName( node ) );
    } 
  }
  return ok;
} 
