/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  2 2018 14:02:35)
  * Module: rocs
  * XML: $Source: /home/cvs/xspooler/rocs/rocs.xml,v $
  * XML: $Revision: 1.85 $
  * Date: Thu Aug  2 14:02:39 2018
  */

#ifndef __object_Map_H
#define __object_Map_H

#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"

/* Rocs includes: */
#include "rocs/public/list.h"

#ifdef __cplusplus
  extern "C" {
#endif





typedef struct OMap {
  /***** Base *****/
  struct OBase  base;

  /***** Object: Map *****/
  /** Clear the map. */
  void (*clear)( struct OMap* inst );
  /** Get the first item from the map. */
  obj (*first)( struct OMap* inst );
  /** Get an item from the map. */
  obj (*get)( struct OMap* inst ,const char* key );
  /** Get all mapped objects as a list. */
  iOList (*getList)( struct OMap* inst );
  /** Check if a map entry exist with the given key. */
  Boolean (*haskey)( struct OMap* inst ,const char* key );
  /** Map object creator. */
  struct OMap* (*inst)( void );
  /** Get the next item from the map. */
  obj (*next)( struct OMap* inst );
  /** Put a new item in the map. */
  void (*put)( struct OMap* inst ,const char* key ,obj val );
  /** Remove an item from the map. */
  obj (*remove)( struct OMap* inst ,const char* key );
  /** Get the size of the map. (Number of objects in the map.) */
  int (*size)( struct OMap* inst );
} *iOMap;

extern struct OMap MapOp;

#ifdef __cplusplus
  }
#endif


#endif
