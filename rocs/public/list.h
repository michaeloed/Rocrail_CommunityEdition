/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  2 2018 14:02:35)
  * Module: rocs
  * XML: $Source: /home/cvs/xspooler/rocs/rocs.xml,v $
  * XML: $Revision: 1.85 $
  * Date: Thu Aug  2 14:02:39 2018
  */

#ifndef __object_List_H
#define __object_List_H

#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"

#ifdef __cplusplus
  extern "C" {
#endif


typedef int(*comparator)(obj* o1, obj* o2);



typedef struct OList {
  /***** Base *****/
  struct OBase  base;

  /***** Object: List *****/
  /** Adds an object to the list. */
  void (*add)( struct OList* inst ,obj object );
  /** Empties the list. */
  void (*clear)( struct OList* inst );
  /** Gets the first object from the list. */
  obj (*first)( struct OList* inst );
  /** Gets an object from the list by position. */
  obj (*get)( struct OList* inst ,int pos );
  /** Gets the current pointer position. */
  int (*getIndex)( struct OList* inst );
  /** Inserts an object into the list. */
  void (*insert)( struct OList* inst ,int pos ,obj object );
  /** Object creator. */
  struct OList* (*inst)( void );
  /** Gets the next object from the list. */
  obj (*next)( struct OList* inst );
  /** Removes an object from the list by position. */
  obj (*remove)( struct OList* inst ,int pos );
  /** Removes an object from the list by reference. */
  obj (*removeObj)( struct OList* inst ,obj object );
  /** Replaces an object. */
  void (*replace)( struct OList* inst ,int pos ,obj object );
  /** Gets the number of objects currently in the list. */
  int (*size)( struct OList* inst );
  /** Sorts this list. */
  void (*sort)( struct OList* inst ,comparator comp );
} *iOList;

extern struct OList ListOp;

#ifdef __cplusplus
  }
#endif


#endif
