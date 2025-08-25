/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  2 2018 14:02:35)
  * Module: rocs
  * XML: $Source: /home/cvs/xspooler/rocs/rocs.xml,v $
  * XML: $Revision: 1.85 $
  * Date: Thu Aug  2 14:02:39 2018
  */

#include "rocs/public/js.h"


static const char* name = "OJS";

typedef struct OJSData {

    /** file descriptors */
  int jsfd[4];
    /** Listeners list. */
  iOList listeners[4];
    /** HID reader */
  iOThread reader;
    /**  */
  Boolean run;
    /**  */
  int devcnt;

} *iOJSData;

static iOJSData Data( void* p ) { return (iOJSData)((iOJS)p)->base.data; }

