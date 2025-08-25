/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  2 2018 14:02:35)
  * Module: rocs
  * XML: $Source: /home/cvs/xspooler/rocs/rocs.xml,v $
  * XML: $Revision: 1.85 $
  * Date: Thu Aug  2 14:02:39 2018
  */

#include "rocs/public/usb.h"


static const char* name = "OUSB";

typedef struct OUSBData {

    /**  */
  void* husb;
    /**  */
  int interfaceNr;
    /**  */
  int input_ep;
    /**  */
  int output_ep;

} *iOUSBData;

static iOUSBData Data( void* p ) { return (iOUSBData)((iOUSB)p)->base.data; }

