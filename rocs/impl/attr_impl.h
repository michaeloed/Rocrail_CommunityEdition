/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  2 2018 14:02:35)
  * Module: rocs
  * XML: $Source: /home/cvs/xspooler/rocs/rocs.xml,v $
  * XML: $Revision: 1.85 $
  * Date: Thu Aug  2 14:02:39 2018
  */

#include "rocs/public/attr.h"


static const char* name = "OAttr";

typedef struct OAttrData {

    /** Attribute name. */
  char* name;
    /** Attribute value. */
  char* val;
    /** Attribute value.(Un-escaped.) */
  char* origval;
    /** Attribute is escaped. */
  Boolean escaped;

} *iOAttrData;

static iOAttrData Data( void* p ) { return (iOAttrData)((iOAttr)p)->base.data; }

