/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocRail
  * XML: $Source: /cvsroot/rojav/rocrail/rocrail.xml,v $
  * XML: $Revision: 1.56 $
  * Date: Fri Aug  3 14:03:35 2018
  */

#ifndef __object_Car_H
#define __object_Car_H

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





typedef struct OCar {
  /***** Base *****/
  struct OBase  base;

  /***** Interface: HtmlInt *****/
  /**  */
  char* (*getForm)( void* object );
  /**  */
  char* (*postForm)( void* object ,const char* data );
  /**  */
  const char* (*tableHdr)( void );
  /**  */
  char* (*toHtml)( void* object );

  /***** Object: Car *****/
  /**  */
  void (*addWaybill)( struct OCar* inst ,iONode waybill );
  /**  */
  Boolean (*cmd)( struct OCar* inst ,iONode cmd );
  /**  */
  int (*getAddress)( struct OCar* inst );
  /**  */
  int (*getCV)( struct OCar* inst ,int nr );
  /**  */
  int (*getFnNrByDesc)( struct OCar* inst ,const char* desc );
  /**  */
  iONode (*getFunctionStatus)( struct OCar* inst ,iONode funcmd );
  /**  */
  const char* (*getIdent)( struct OCar* inst );
  /**  */
  int (*getLen)( struct OCar* inst );
  /**  */
  const char* (*getLocality)( struct OCar* inst );
  /**  */
  int (*getVMax)( struct OCar* inst );
  /**  */
  int (*getWeight)( struct OCar* inst );
  /**  */
  struct OCar* (*inst)( iONode ini );
  /**  */
  Boolean (*isCommuter)( struct OCar* inst );
  /**  */
  void (*modify)( struct OCar* inst ,iONode mod );
  /**  */
  void (*setCV)( struct OCar* inst ,int nr ,int value );
  /**  */
  void (*setLocality)( struct OCar* inst ,const char* id );
  /**  */
  void (*swapPlacing)( struct OCar* inst ,iONode cmd );
} *iOCar;

extern struct OCar CarOp;

#ifdef __cplusplus
  }
#endif


#endif
