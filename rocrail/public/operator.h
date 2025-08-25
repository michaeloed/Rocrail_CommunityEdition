/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocRail
  * XML: $Source: /cvsroot/rojav/rocrail/rocrail.xml,v $
  * XML: $Revision: 1.56 $
  * Date: Fri Aug  3 14:03:35 2018
  */

#ifndef __object_Operator_H
#define __object_Operator_H

#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"

/* Rocs includes: */
#include "rocs/public/node.h"

/* RocRail and system includes: */
#include "rocrail/public/htmlint.h"

#ifdef __cplusplus
  extern "C" {
#endif





typedef struct OOperator {
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

  /***** Object: Operator *****/
  /**  */
  Boolean (*cmd)( struct OOperator* inst ,iONode cmd );
  /**  */
  const char* (*getCargo)( struct OOperator* inst );
  /**  */
  const char* (*getClass)( struct OOperator* inst );
  /**  */
  int (*getLen)( struct OOperator* inst ,int* trainweight );
  /**  */
  int (*getVMax)( struct OOperator* inst );
  /**  */
  Boolean (*hasCar)( struct OOperator* inst ,const char* id );
  /**  */
  Boolean (*hasClass)( struct OOperator* inst ,const char* class );
  /**  */
  struct OOperator* (*inst)( iONode ini );
  /**  */
  Boolean (*isCommuter)( struct OOperator* inst );
  /**  */
  Boolean (*matchIdent)( struct OOperator* inst ,const char* ident1 ,const char* ident2 ,const char* ident3 ,const char* ident4 );
  /**  */
  void (*modify)( struct OOperator* inst ,iONode mod );
  /**  */
  void (*setClass)( struct OOperator* inst ,const char* class );
  /**  */
  Boolean (*setFnByDesc)( struct OOperator* inst ,const char* desc ,Boolean flip ,Boolean fon ,int duration );
  /**  */
  void (*setLocality)( struct OOperator* inst ,const char* bkid );
  /**  */
  void (*swapPlacing)( struct OOperator* inst ,iONode cmd );
} *iOOperator;

extern struct OOperator OperatorOp;

#ifdef __cplusplus
  }
#endif


#endif
