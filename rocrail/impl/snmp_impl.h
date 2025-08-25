/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocRail
  * XML: $Source: /cvsroot/rojav/rocrail/rocrail.xml,v $
  * XML: $Revision: 1.56 $
  * Date: Fri Aug  3 14:03:35 2018
  */

#include "rocrail/public/snmp.h"


static const char* name = "OSNMP";


/**  */
typedef struct SnmpVar {
    /**  */
  char oid[128];
    /**  */
  int vartype;
    /**  */
  char vars[128];
    /**  */
  int vari;
} *iOSnmpVar;

/**  */
typedef struct SnmpHdr {
    /**  */
  int seqlen;
    /**  */
  int version;
    /**  */
  char community[128];
    /**  */
  int request;
    /**  */
  int reqID;
    /**  */
  int errstatus;
    /**  */
  int errindex;
    /**  */
  int oids;
    /**  */
  struct SnmpVar oid[32];
} *iOSnmpHdr;
typedef struct OSNMPData {

    /**  */
  iONode ini;
    /**  */
  iOSocket snmpSock;
    /**  */
  iOSocket snmpTrapSock;
    /**  */
  iOThread server;
    /**  */
  Boolean trap;
    /**  */
  Boolean run;
    /**  */
  iOMap mibDB;
    /**  */
  iOMap mibMap;
    /**  */
  iOMap mibRW;
    /**  */
  iOList oidList;
    /**  */
  int seqnr;
    /**  */
  int linkup;
    /**  */
  int linkcnt;
    /**  */
  char* lastexc;

} *iOSNMPData;

static iOSNMPData Data( void* p ) { return (iOSNMPData)((iOSNMP)p)->base.data; }

