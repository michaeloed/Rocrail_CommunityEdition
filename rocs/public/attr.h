/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  2 2018 14:02:35)
  * Module: rocs
  * XML: $Source: /home/cvs/xspooler/rocs/rocs.xml,v $
  * XML: $Revision: 1.85 $
  * Date: Thu Aug  2 14:02:39 2018
  */

#ifndef __object_Attr_H
#define __object_Attr_H

#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"

/* Rocs includes: */
#include "rocs/public/str.h"

#ifdef __cplusplus
  extern "C" {
#endif





typedef struct OAttr {
  /***** Base *****/
  struct OBase  base;

  /***** Object: Attr *****/
  /** Attribute value. */
  Boolean (*getBoolean)( struct OAttr* inst );
  /** Escaped attribute value. */
  const char* (*getEscVal)( struct OAttr* inst );
  /** Attribute value. */
  double (*getFloat)( struct OAttr* inst );
  /** Attribute value. */
  int (*getInt)( struct OAttr* inst );
  /** Attribute value. */
  long (*getLong)( struct OAttr* inst );
  /** Attribute name. */
  const char* (*getName)( struct OAttr* inst );
  /** Attribute value. */
  const char* (*getVal)( struct OAttr* inst );
  /** Creates an attribute with given name and value. */
  struct OAttr* (*inst)( const char* name ,const char* val );
  /** Creates an attribute with given name and integer value. */
  struct OAttr* (*instInt)( const char* name ,int val );
  /** Change attribute value. */
  void (*setBoolean)( struct OAttr* inst ,Boolean val );
  /** Change attribute value. */
  void (*setFloat)( struct OAttr* inst ,double val );
  /** Change attribute value. */
  void (*setInt)( struct OAttr* inst ,int val );
  /** Change attribute value. */
  void (*setLong)( struct OAttr* inst ,long val );
  /** Change attribute name. */
  void (*setName)( struct OAttr* inst ,const char* name );
  /** Change attribute value. */
  void (*setVal)( struct OAttr* inst ,const char* val );
} *iOAttr;

extern struct OAttr AttrOp;

#ifdef __cplusplus
  }
#endif


#endif
