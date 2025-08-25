/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  2 2018 14:02:35)
  * Module: rocs
  * XML: $Source: /home/cvs/xspooler/rocs/rocs.xml,v $
  * XML: $Revision: 1.85 $
  * Date: Thu Aug  2 14:02:39 2018
  */

#include "rocs/public/mutex.h"


static const char* name = "OMutex";

typedef struct OMutexData {

    /** Mutex name. */
  char* name;
    /** Mutex handle. */
  void* handle;
    /**  */
  void* mh;
    /**  */
  int rc;

} *iOMutexData;

static iOMutexData Data( void* p ) { return (iOMutexData)((iOMutex)p)->base.data; }

