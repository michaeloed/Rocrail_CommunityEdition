/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocDigs
  * XML: $Source: /cvsroot/rojav/rocdigs/rocdigs.xml,v $
  * XML: $Revision: 1.14 $
  * Date: Fri Aug  3 14:03:49 2018
  */

#include "rocdigs/public/rfid12.h"


static const char* name = "ORFID12";

typedef struct ORFID12Data {

    /**  */
  iONode ini;
    /**  */
  const char* iid;
    /**  */
  iOSerial serial;
    /**  */
  Boolean run;
    /**  */
  Boolean serialOK;
    /**  */
  Boolean initOK;
    /**  */
  iOThread reader;
    /**  */
  iOThread ticker;
    /**  */
  const char* device;
    /**  */
  serial_bps bps;
    /**  */
  obj listenerObj;
    /**  */
  digint_listener listenerFun;
    /**  */
  int fboffset;
    /**  */
  int protver;
    /**  */
  unsigned long readerTick[8];
    /**  */
  char ident[8][64];

} *iORFID12Data;

static iORFID12Data Data( void* p ) { return (iORFID12Data)((iORFID12)p)->base.data; }

