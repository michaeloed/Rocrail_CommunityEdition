/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  2 2018 14:02:35)
  * Module: rocs
  * XML: $Source: /home/cvs/xspooler/rocs/rocs.xml,v $
  * XML: $Revision: 1.85 $
  * Date: Thu Aug  2 14:02:39 2018
  */

#include "rocs/public/dir.h"


static const char* name = "ODir";

typedef struct ODirData {

    /** Path pointing to the directory. */
  char* path;
    /** Last error. */
  int rc;
    /** Directory structure as defined in dirent.h. */
  DIR* dir;

} *iODirData;

static iODirData Data( void* p ) { return (iODirData)((iODir)p)->base.data; }

