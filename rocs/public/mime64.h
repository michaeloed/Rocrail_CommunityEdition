/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  2 2018 14:02:35)
  * Module: rocs
  * XML: $Source: /home/cvs/xspooler/rocs/rocs.xml,v $
  * XML: $Revision: 1.85 $
  * Date: Thu Aug  2 14:02:39 2018
  */

#ifndef __object_Mime64_H
#define __object_Mime64_H

#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"

#ifdef __cplusplus
  extern "C" {
#endif





typedef struct OMime64 {
  /***** Base *****/
  struct OBase  base;

  /***** Object: Mime64 *****/
  /** decode the input from mime64 to binary */
  int (*decode)( unsigned char* dst ,int* dlen ,const unsigned char* src ,int slen );
  /** decode the input file into it's  */
  Boolean (*decodeFile)( const char* infile ,const char* outfile );
  /** encode the input into mime64 */
  int (*encode)( unsigned char* dst ,int* dlen ,const unsigned char* src ,int slen );
  /** encode the input file into mime64 */
  Boolean (*encodeFile)( const char* infile ,const char* outfile );
  /** generate a sha1 key */
  char* (*sha1)( const char* str );
} *iOMime64;

extern struct OMime64 Mime64Op;

#ifdef __cplusplus
  }
#endif


#endif
