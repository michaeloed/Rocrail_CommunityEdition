/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  2 2018 14:02:35)
  * Module: rocs
  * XML: $Source: /home/cvs/xspooler/rocs/rocs.xml,v $
  * XML: $Revision: 1.85 $
  * Date: Thu Aug  2 14:02:39 2018
  */

#ifndef __object_Ebcdic_H
#define __object_Ebcdic_H

#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"

/* Rocs includes: */
#include "rocs/public/node.h"

#ifdef __cplusplus
  extern "C" {
#endif


typedef enum {CODEPAGE_DEFAULT=0,CODEPAGE_1252=1252,CODEPAGE_437=437,CODEPAGE_850=437} codepage;



typedef struct OEbcdic {
  /***** Base *****/
  struct OBase  base;

  /***** Object: Ebcdic *****/
  /** Converts ascii into ebcdic. */
  char* (*Ascii2Ebcdic)( struct OEbcdic* inst ,char* ascii ,int count );
  /** Converts ebcdic into ascii. */
  char* (*Ebcdic2Ascii)( struct OEbcdic* inst ,char* ebcdic ,int count );
  /** Converts ebcdic into ascii. */
  char* (*Ebcdic2ExtAscii)( struct OEbcdic* inst ,char* ebcdic ,int count );
  /** Converts ebcdic into ascii. */
  char* (*Ebcdic2TrueAscii)( struct OEbcdic* inst ,char* ebcdic ,int count );
  /** Gets the ascii coding for the given ebcdic code. */
  char (*getAscii)( struct OEbcdic* inst ,char ebcdic );
  /** Gets the ebcdic coding for the given ascii code. */
  char (*getEbcdic)( struct OEbcdic* inst ,char ascii );
  /** Object creator. */
  struct OEbcdic* (*inst)( codepage CodePage ,const char* converterfile );
} *iOEbcdic;

extern struct OEbcdic EbcdicOp;

#ifdef __cplusplus
  }
#endif


#endif
