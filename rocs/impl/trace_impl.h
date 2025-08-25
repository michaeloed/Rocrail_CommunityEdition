/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  2 2018 14:02:35)
  * Module: rocs
  * XML: $Source: /home/cvs/xspooler/rocs/rocs.xml,v $
  * XML: $Revision: 1.85 $
  * Date: Thu Aug  2 14:02:39 2018
  */

#include "rocs/public/trace.h"


static const char* name = "OTrace";

/*  */
#define TRC_DUMPSIZE 128
/*  */
#define TRC_FILESIZE 100
/*  */
#define TRC_NRFILES 10
typedef struct OTraceData {

    /** Trace level(s). */
  int level;
    /** Current filename. */
  char* file;
    /** Application ID to use in traces. */
  char* appID;
    /** Native filehandle. */
  FILE* trcfile;
    /** Default dumpsize. */
  int dumpsize;
    /** Default filesize. */
  int filesize;
    /**  */
  int nrfiles;
    /**  */
  char* currentfilename;
    /**  */
  Boolean toStdErr;
    /**  */
  Boolean ebcdicDump;
    /**  */
  ExceptionListener excListener;
    /**  */
  Boolean excTimestamp;
    /**  */
  Boolean excAll;
    /**  */
  iOMutex mux;
    /**  */
  iOEbcdic ebcdic;
    /**  */
  Boolean exceptionfile;
    /**  */
  char* invoke;
    /**  */
  Boolean invokeasync;

} *iOTraceData;

static iOTraceData Data( void* p ) { return (iOTraceData)((iOTrace)p)->base.data; }

