/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocview
  * Date: Fri Aug  3 14:03:52 2018
  */

#ifndef __WRAPPER_H
#define __WRAPPER_H

#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/attr.h"
#include "rocs/public/trace.h"


typedef enum {vt_bool,vt_int,vt_long,vt_float,vt_string} attr_vt;
struct __attrdef {
  char*   name;
  char*   remark;
  char*   unit;
  char*   vtype;
  char*   defval; /* NULL if no default */
  char*   range;  /* "10-1000" or "10,20,30" or "no,yes,delete" or "*" */
  Boolean required;
};

struct __nodedef {
  char*   name;
  char*   remark;
  Boolean required;
  char*   cardinality;
};

Boolean xBool( struct __attrdef attr); 
int xInt( struct __attrdef attr); 
long xLong( struct __attrdef attr); 
double xFloat( struct __attrdef attr); 
const char* xStr( struct __attrdef attr); 
Boolean xNode( struct __nodedef attr, iONode node); 
Boolean xAttr( struct __attrdef* attr, iONode node); 
Boolean xAttrTest( struct __attrdef* attr[], iONode node); 
Boolean xNodeTest( struct __nodedef* nodeList[], iONode node); 


#endif
