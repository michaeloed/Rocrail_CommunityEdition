/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  2 2018 14:02:35)
  * Module: rocs
  * XML: $Source: /home/cvs/xspooler/rocs/rocs.xml,v $
  * XML: $Revision: 1.85 $
  * Date: Thu Aug  2 14:02:39 2018
  */

#include "rocs/public/event.h"


static const char* name = "OEvent";

typedef struct OEventData {

    /** Event name. */
  char* name;
    /** Event handle. */
  void* handle;
    /**  */
  Boolean posted;

} *iOEventData;

static iOEventData Data( void* p ) { return (iOEventData)((iOEvent)p)->base.data; }

