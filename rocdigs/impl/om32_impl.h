/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocDigs
  * XML: $Source: /cvsroot/rojav/rocdigs/rocdigs.xml,v $
  * XML: $Revision: 1.14 $
  * Date: Fri Aug  3 14:03:49 2018
  */

#include "rocdigs/public/om32.h"


static const char* name = "OOM32";

typedef struct OOM32Data {

    /**  */
  iONode ini;
    /**  */
  const char* iid;
    /**  */
  iOSerial serial;
    /**  */
  obj listenerObj;
    /**  */
  digint_listener listenerFun;

} *iOOM32Data;

static iOOM32Data Data( void* p ) { return (iOOM32Data)((iOOM32)p)->base.data; }

