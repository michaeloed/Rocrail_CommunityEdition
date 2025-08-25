/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocRail
  * XML: $Source: /cvsroot/rojav/rocrail/rocrail.xml,v $
  * XML: $Revision: 1.56 $
  * Date: Fri Aug  3 14:03:35 2018
  */

#ifndef __object_Var_H
#define __object_Var_H

#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"

/* Rocs includes: */
#include "rocs/public/node.h"
#include "rocs/public/map.h"

/* RocRail and system includes: */
#include "rocrail/public/htmlint.h"

#ifdef __cplusplus
  extern "C" {
#endif





typedef struct OVar {
  /***** Base *****/
  struct OBase  base;

  /***** Object: Var *****/
  /**  */
  void (*checkActions)( iONode var );
  /**  */
  char* (*getText)( const char* valStr ,iOMap map ,char separator );
  /**  */
  int (*getValue)( const char* valStr ,iOMap map );
  /**  */
  Boolean (*setRandom)( iONode var );
} *iOVar;

extern struct OVar VarOp;

#ifdef __cplusplus
  }
#endif


#endif
