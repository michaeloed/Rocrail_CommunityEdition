/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  2 2018 14:02:35)
  * Module: rocs
  * XML: $Source: /home/cvs/xspooler/rocs/rocs.xml,v $
  * XML: $Revision: 1.85 $
  * Date: Thu Aug  2 14:02:39 2018
  */

#include "rocs/public/thread.h"


static const char* name = "OThread";

typedef struct OThreadData {

    /** Run method. */
  thread_run run;
    /** Thread name. */
  char* tname;
    /** Thread id. */
  unsigned long id;
    /** Thread handle. */
  unsigned long handle;
    /** Quit is signaled. */
  Boolean quit;
    /** Queue for posting. */
  iOQueue queue;
    /** Thread parameters. */
  void* parm;
    /** Thread stacksize. */
  long stacksize;
    /** Thread description. */
  char* tdesc;
    /** pause is signaled. */
  Boolean pause;

} *iOThreadData;

static iOThreadData Data( void* p ) { return (iOThreadData)((iOThread)p)->base.data; }

