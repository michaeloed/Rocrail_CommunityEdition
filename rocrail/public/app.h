/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocRail
  * XML: $Source: /cvsroot/rojav/rocrail/rocrail.xml,v $
  * XML: $Revision: 1.56 $
  * Date: Fri Aug  3 14:03:35 2018
  */

#ifndef __object_App_H
#define __object_App_H

#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"

/* Rocs includes: */
#include "rocs/public/node.h"

/* RocRail and system includes: */
#include "rocrail/public/clntcon.h"
#include "rocrail/public/srcpcon.h"
#include "rocrail/public/control.h"
#include "rocrail/public/weather.h"
#include "rocrail/public/model.h"
#include "rocrail/public/http.h"
#include "rocrail/public/snmp.h"
#include "rocrail/public/script.h"

#ifdef __cplusplus
  extern "C" {
#endif





typedef struct OApp {
  /***** Base *****/
  struct OBase  base;

  /***** Object: App *****/
  /**  */
  int (*Main)( struct OApp* inst ,int argc ,char** argv );
  /**  */
  void (*broadcastEvent)( iONode evt );
  /**  */
  void (*ebreak)( void );
  /** Get the the last 10 exceptions. */
  const char** (*getBackTrace)( void );
  /**  */
  iOClntCon (*getClntCon)( void );
  /**  */
  iOControl (*getControl)( void );
  /** Path to icons. */
  const char* (*getIconPath)( void );
  /** Path to images. */
  const char* (*getImgPath)( void );
  /**  */
  iONode (*getIni)( void );
  /** Current ini filename. */
  const char* (*getIniFile)( void );
  /**  */
  iONode (*getIniNode)( const char* nodename );
  /** Path to the rocrail libraries. */
  const char* (*getLibPath)( void );
  /**  */
  iOModel (*getModel)( void );
  /**  */
  iONode (*getNewIni)( void );
  /**  */
  iOSrcpCon (*getSrcpCon)( void );
  /**  */
  long (*getStartTime)( void );
  /**  */
  iOWeather (*getWeather)( void );
  /**  */
  int (*getrevno)( void );
  /**  */
  void (*go)( void );
  /**  */
  struct OApp* (*inst)( void );
  /**  */
  Boolean (*isConsoleMode)( void );
  /**  */
  Boolean (*isCreateModplan)( void );
  /**  */
  Boolean (*isRunAtStartup)( void );
  /**  */
  Boolean (*isStress)( void );
  /**  */
  void (*link)( int count ,Boolean up );
  /**  */
  void (*listThreads)( void );
  /**  */
  void (*play)( const char* record );
  /**  */
  void (*saveIni)( void );
  /**  */
  void (*setIni)( iONode ini );
  /**  */
  Boolean (*shutdown)( int network ,const char* signalname );
  /**  */
  void (*stop)( void );
  /**  */
  void (*stopPlay)( void );
} *iOApp;

extern struct OApp AppOp;

#ifdef __cplusplus
  }
#endif


#endif
