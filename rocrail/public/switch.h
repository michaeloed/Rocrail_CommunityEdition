/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocRail
  * XML: $Source: /cvsroot/rojav/rocrail/rocrail.xml,v $
  * XML: $Revision: 1.56 $
  * Date: Fri Aug  3 14:03:35 2018
  */

#ifndef __object_Switch_H
#define __object_Switch_H

#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"

/* Rocs includes: */
#include "rocs/public/node.h"
#include "rocs/public/mutex.h"
#include "rocs/public/thread.h"
#include "rocs/public/list.h"

/* RocRail and system includes: */
#include "rocrail/public/htmlint.h"
#include "rocrail/public/route.h"

#ifdef __cplusplus
  extern "C" {
#endif


typedef enum {SW_STRAIGHT=0,SW_TURNOUT,SW_LEFT,SW_RIGHT,SW_UNKNOWN} sw_state;



typedef struct OSwitch {
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

  /***** Object: Switch *****/
  /**  */
  Boolean (*addListener)( struct OSwitch* inst ,obj listener );
  /** check if the save position must be set and if the sensors are set */
  void (*checkSenPos)( struct OSwitch* inst );
  /**  */
  Boolean (*cmd)( struct OSwitch* inst ,iONode cmd ,Boolean update ,int extra ,int* error ,const char* lcid );
  /**  */
  char* (*createAddrKey)( int bus ,int addr ,int port ,int type ,const char* iid );
  /**  */
  void (*event)( struct OSwitch* inst ,iONode evt );
  /**  */
  const char* (*getAddrKey)( struct OSwitch* inst );
  /**  */
  const char* (*getAddrKey2)( struct OSwitch* inst );
  /**  */
  const char* (*getId)( struct OSwitch* inst );
  /**  */
  void (*green)( struct OSwitch* inst );
  /**  */
  Boolean (*has2Units)( struct OSwitch* inst );
  /**  */
  struct OSwitch* (*inst)( iONode ini );
  /** true if this is a left turnout */
  Boolean (*isLeft)( struct OSwitch* inst );
  /**  */
  Boolean (*isLocked)( struct OSwitch* inst ,const char* locid ,Boolean manual );
  /** true if this is a right turnout */
  Boolean (*isRight)( struct OSwitch* inst );
  /** true if the sensor state matches the wanted state */
  Boolean (*isSet)( struct OSwitch* inst );
  /**  */
  Boolean (*isState)( struct OSwitch* inst ,const char* state );
  /**  */
  Boolean (*link)( struct OSwitch* inst ,int linkto );
  /**  */
  Boolean (*lock)( struct OSwitch* inst ,const char* locid ,iORoute route );
  /**  */
  void (*modify)( struct OSwitch* inst ,iONode mod );
  /**  */
  void (*red)( struct OSwitch* inst );
  /**  */
  Boolean (*removeListener)( struct OSwitch* inst ,obj listener );
  /**  */
  void (*reset)( struct OSwitch* inst );
  /**  */
  Boolean (*unLink)( struct OSwitch* inst );
  /**  */
  Boolean (*unLock)( struct OSwitch* inst ,const char* locid ,iORoute route ,Boolean force );
} *iOSwitch;

extern struct OSwitch SwitchOp;

#ifdef __cplusplus
  }
#endif


#endif
