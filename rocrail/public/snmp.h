/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocRail
  * XML: $Source: /cvsroot/rojav/rocrail/rocrail.xml,v $
  * XML: $Revision: 1.56 $
  * Date: Fri Aug  3 14:03:35 2018
  */

#ifndef __object_SNMP_H
#define __object_SNMP_H

#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"

/* Rocs includes: */
#include "rocs/public/socket.h"
#include "rocs/public/node.h"
#include "rocs/public/thread.h"
#include "rocs/public/map.h"

#ifdef __cplusplus
  extern "C" {
#endif





typedef struct OSNMP {
  /***** Base *****/
  struct OBase  base;

  /***** Object: SNMP *****/
  int pdu_SEQUENCE;
  int pdu_GETREQ;
  int pdu_GETNEXTREQ;
  int pdu_GETRSP;
  int pdu_SETREQ;
  int pdu_TRAP;
  int pdu_BULKREQ;
  int var_INT;
  int var_STRING;
  int var_OBJECTID;
  int var_NULL;
  int var_TIMETICK;
  int var_IP;
  int var_EOFMIB;
  int trap_COLDSTART;
  int trap_WARMSTART;
  int trap_LINKDOWN;
  int trap_LINKUP;
  int trap_USER;
  int err_OK;
  int err_tooBig;
  int err_noSuchName;
  int err_badValue;
  int err_readOnly;
  int err_genErr;
  /**  */
  void (*exception)( struct OSNMP* inst ,const char* msg );
  /**  */
  struct OSNMP* (*inst)( iONode ini );
  /**  */
  void (*link)( struct OSNMP* inst ,int count ,Boolean up );
  /**  */
  void (*shutdown)( struct OSNMP* inst );
} *iOSNMP;

extern struct OSNMP SNMPOp;

#ifdef __cplusplus
  }
#endif


#endif
