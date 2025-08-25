/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  2 2018 14:02:35)
  * Module: rocs
  * XML: $Source: /home/cvs/xspooler/rocs/rocs.xml,v $
  * XML: $Revision: 1.85 $
  * Date: Thu Aug  2 14:02:39 2018
  */

#include "rocs/public/file.h"


static const char* name = "OFile";

typedef struct OFileData {

    /** File handle. */
  FILE* fh;
    /**  */
  int openflag;
    /**  */
  char* path;
    /**  */
  long size;
    /**  */
  long readed;
    /**  */
  long written;
    /**  */
  int rc;

} *iOFileData;

static iOFileData Data( void* p ) { return (iOFileData)((iOFile)p)->base.data; }

