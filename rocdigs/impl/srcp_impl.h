/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocDigs
  * XML: $Source: /cvsroot/rojav/rocdigs/rocdigs.xml,v $
  * XML: $Revision: 1.14 $
  * Date: Fri Aug  3 14:03:49 2018
  */

#include "rocdigs/public/srcp.h"


static const char* name = "OSRCP";

typedef struct OSRCPData {

    /**  */
  iONode ini;
    /**  */
  const char* iid;
    /**  */
  iONode srcpini;
    /**  */
  iOTrace trace;
    /**  */
  obj listenerObj;
    /**  */
  digint_listener listenerFun;
    /**  */
  iOSocket cmdSocket;
    /**  */
  iOSocket infoSocket;
    /**  */
  iOThread infoReader;
    /**  */
  const char* host;
    /**  */
  int port;
    /**  */
  Boolean run;
    /**  */
  Boolean evalfirst;
    /**  */
  Boolean handshakeerror;
    /**  */
  srcpstate state;
    /**  */
  iOMap knownObjects;
    /**  */
  sublib_init subInit;
    /**  */
  sublib_connect subConnect;
    /**  */
  sublib_disconnect subDisconnect;
    /**  */
  sublib_read subRead;
    /**  */
  sublib_write subWrite;
    /**  */
  sublib_available subAvailable;
    /**  */
  iOThread subReader;
    /**  */
  iOThread subWriter;
    /**  */
  iOQueue subReadQueue;
    /**  */
  iOQueue subWriteQueue;
    /**  */
  iOSerial serial;
    /**  */
  iOMutex serialMux;
    /**  */
  Boolean serialOK;
    /**  */
  Boolean enablecom;

} *iOSRCPData;

static iOSRCPData Data( void* p ) { return (iOSRCPData)((iOSRCP)p)->base.data; }

