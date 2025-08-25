/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  2 2018 14:02:35)
  * Module: rocs
  * XML: $Source: /home/cvs/xspooler/rocs/rocs.xml,v $
  * XML: $Revision: 1.85 $
  * Date: Thu Aug  2 14:02:39 2018
  */

#ifndef __object_USB_H
#define __object_USB_H

#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"

#ifdef __cplusplus
  extern "C" {
#endif





typedef struct OUSB {
  /***** Base *****/
  struct OBase  base;

  /***** Object: USB *****/
  /**  */
  Boolean (*close)( struct OUSB* inst );
  /** Object creator. */
  struct OUSB* (*inst)( void );
  /**  */
  Boolean (*open)( struct OUSB* inst ,int vendor ,int product ,int configNr ,int interfaceNr );
  /**  */
  int (*read)( struct OUSB* inst ,unsigned char* buf ,int len ,int timeout );
  /**  */
  int (*write)( struct OUSB* inst ,unsigned char* buf ,int len ,int timeout );
} *iOUSB;

extern struct OUSB USBOp;

#ifdef __cplusplus
  }
#endif


#endif
