/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocDigs
  * XML: $Source: /cvsroot/rojav/rocdigs/rocdigs.xml,v $
  * XML: $Revision: 1.14 $
  * Date: Fri Aug  3 14:03:49 2018
  */

#include "rocdigs/public/ecos.h"


static const char* name = "OECoS";

typedef struct OECoSData {

    /** Ini Node pointer */
  iONode ini;
    /** Trace pointer */
  iOTrace trace;
    /** Listener pointer */
  obj listenerObj;
    /** Listener Function pointer */
  digint_listener listenerFun;
    /** Interface ID */
  const char* iid;
    /** Turnout switch time? */
  int swtime;
    /** IO Socket */
  iOSocket socket;
    /** Mutex Handler */
  iOMutex writemux;
    /** Reader Thread */
  iOThread reader;
    /** Command Thread */
  iOThread initrun;
    /** Hostname/IP Address */
  const char* host;
    /** TCP/IP Port */
  int port;
    /** Run Flag */
  Boolean run;
    /** Connection Flag */
  Boolean connected;
    /** Previous sensor states */
  int olds88[64];
    /**  */
  iOMutex mapmux;
    /** Loco Name to OID Mapper */
  iOMap locoNameToEcosOidMap;
    /** OID to Loco Name Mapper */
  iOMap ecosOidToLocoNameMap;
    /** DCC Switch Addr to OID Mapper */
  iOMap dccSwitchAddrToOidMap;
    /** DCC OID to Switch Addr Mapper */
  iOMap dccOidToSwitchAddrMap;
    /** DCC Switch state control */
  unsigned char dccSwitchStates[2048];
    /** Power Flag */
  Boolean power;
    /**  */
  Boolean enablecom;

} *iOECoSData;

static iOECoSData Data( void* p ) { return (iOECoSData)((iOECoS)p)->base.data; }

