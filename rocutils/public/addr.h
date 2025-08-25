/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: rocutils
  * XML: 
  * XML: 
  * Date: Fri Aug  3 14:01:51 2018
  */

#ifndef __object_Addr_H
#define __object_Addr_H

#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"

#ifdef __cplusplus
  extern "C" {
#endif





typedef struct OAddr {
  /***** Base *****/
  struct OBase  base;

  /***** Object: Addr *****/
  /**  */
  void (*fromFADA)( int fada ,int* module ,int* port ,int* gate );
  /**  */
  void (*fromPADA)( int pada ,int* module ,int* port );
  /**  */
  int (*toFADA)( int module ,int port ,int gate );
  /**  */
  int (*toPADA)( int module ,int port );
} *iOAddr;

extern struct OAddr AddrOp;

#ifdef __cplusplus
  }
#endif


#endif
