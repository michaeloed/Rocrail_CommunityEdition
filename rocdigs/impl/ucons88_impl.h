/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocDigs
  * XML: $Source: /cvsroot/rojav/rocdigs/rocdigs.xml,v $
  * XML: $Revision: 1.14 $
  * Date: Fri Aug  3 14:03:49 2018
  */

#include "rocdigs/public/ucons88.h"


static const char* name = "OuConS88";

typedef struct OuConS88Data {

    /**  */
  iONode ini;
    /**  */
  const char* iid;
    /**  */
  const char* device;
    /**  */
  Boolean run;
    /**  */
  iOThread reader;
    /**  */
  iOThread writer;
    /**  */
  obj listenerObj;
    /**  */
  digint_listener listenerFun;
    /**  */
  iOSocket socket;
    /**  */
  Boolean connOK;
    /**  */
  Boolean connAck;
    /**  */
  Boolean power;
    /**  */
  int fbB1;
    /**  */
  int fbB2;
    /**  */
  int fbB3;

} *iOuConS88Data;

static iOuConS88Data Data( void* p ) { return (iOuConS88Data)((iOuConS88)p)->base.data; }

