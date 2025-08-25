/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocRail
  * XML: $Source: /cvsroot/rojav/rocrail/rocrail.xml,v $
  * XML: $Revision: 1.56 $
  * Date: Fri Aug  3 14:03:35 2018
  */

#ifndef __object_Script_H
#define __object_Script_H

#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"

/* Rocs includes: */
#include "rocs/public/list.h"
#include "rocs/public/node.h"
#include "rocs/public/thread.h"

#ifdef __cplusplus
  extern "C" {
#endif





typedef struct OScript {
  /***** Base *****/
  struct OBase  base;

  /***** Object: Script *****/
  /**  */
  void (*Pause)( struct OScript* inst );
  /**  */
  void (*Play)( struct OScript* inst );
  /**  */
  void (*Stop)( struct OScript* inst );
  /**  */
  char* (*convertNode)( iONode node ,Boolean addStamp );
  /**  */
  iONode (*getLine)( struct OScript* inst ,int linenr );
  /**  */
  struct OScript* (*inst)( const char* script );
  /**  */
  Boolean (*isPlaying)( struct OScript* inst ,int* linenr );
  /**  */
  Boolean (*isRecording)( struct OScript* inst );
  /**  */
  iONode (*nextLine)( struct OScript* inst ,Boolean playpause );
  /**  */
  iONode (*parseLine)( const char* scriptline ,Boolean playpause );
  /**  */
  void (*recordNode)( struct OScript* inst ,iONode node );
  /**  */
  void (*setCallback)( struct OScript* inst ,obj callback );
  /**  */
  void (*setRecording)( struct OScript* inst ,Boolean recording ,Boolean addStamp );
  /**  */
  void (*setScript)( struct OScript* inst ,const char* script );
} *iOScript;

extern struct OScript ScriptOp;

#ifdef __cplusplus
  }
#endif


#endif
