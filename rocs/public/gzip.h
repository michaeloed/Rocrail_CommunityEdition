/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  2 2018 14:02:35)
  * Module: rocs
  * XML: $Source: /home/cvs/xspooler/rocs/rocs.xml,v $
  * XML: $Revision: 1.85 $
  * Date: Thu Aug  2 14:02:39 2018
  */

#ifndef __object_GZip_H
#define __object_GZip_H

#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"

#ifdef __cplusplus
  extern "C" {
#endif





typedef struct OGZip {
  /***** Base *****/
  struct OBase  base;

  /***** Object: GZip *****/
  /**  */
  Boolean (*compress)( struct OGZip* inst );
  /**  */
  Boolean (*deCompress)( struct OGZip* inst );
  /**  */
  int (*getRc)( struct OGZip* inst );
  /** Object creator. */
  struct OGZip* (*inst)( const char* fileName );
} *iOGZip;

extern struct OGZip GZipOp;

#ifdef __cplusplus
  }
#endif


#endif
