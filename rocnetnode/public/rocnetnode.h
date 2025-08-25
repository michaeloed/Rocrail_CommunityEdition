/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Sep 24 2018 12:45:52)
  * Module: RocNetNode
  * XML: 
  * XML: 
  * Date: Mon Sep 24 12:45:53 2018
  */

#ifndef __object_RocNetNode_H
#define __object_RocNetNode_H

#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"

/* Rocs includes: */
#include "rocs/public/node.h"
#include "rocs/public/trace.h"
#include "rocs/public/thread.h"
#include "rocs/public/socket.h"
#include "rocs/public/mutex.h"
#include "rocs/public/map.h"
#include "rocs/public/list.h"

/* RocNetNode and system includes: */
#include "rocint/public/digint.h"

#ifdef __cplusplus
  extern "C" {
#endif





typedef struct ORocNetNode {
  /***** Base *****/
  struct OBase  base;

  /***** Object: RocNetNode *****/
  /**  */
  int (*Main)( struct ORocNetNode* inst ,int argc ,char** argv );
  /**  */
  struct ORocNetNode* (*inst)( iONode ini );
  /**  */
  Boolean (*shutdown)( void );
  /**  */
  void (*stop)( void );
  /**  */
  void (*sysHalt)( void );
  /**  */
  void (*sysUpdate)( int revision ,int offline );
} *iORocNetNode;

extern struct ORocNetNode RocNetNodeOp;

#ifdef __cplusplus
  }
#endif


#endif
