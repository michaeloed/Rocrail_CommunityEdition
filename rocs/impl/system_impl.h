/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  2 2018 14:02:35)
  * Module: rocs
  * XML: $Source: /home/cvs/xspooler/rocs/rocs.xml,v $
  * XML: $Revision: 1.85 $
  * Date: Thu Aug  2 14:02:39 2018
  */

#include "rocs/public/system.h"

/* rocs and system includes: */
#include "rocs/public/thread.h"

static const char* name = "OSystem";

typedef struct OSystemData {

    /**  */
  char WSName[64];
    /**  */
  char UserName[64];
    /**  */
  iOThread ticker;
    /**  */
  unsigned long tick;

} *iOSystemData;

static iOSystemData Data( void* p ) { return (iOSystemData)((iOSystem)p)->base.data; }

