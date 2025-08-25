/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  2 2018 14:02:35)
  * Module: rocs
  * XML: $Source: /home/cvs/xspooler/rocs/rocs.xml,v $
  * XML: $Revision: 1.85 $
  * Date: Thu Aug  2 14:02:39 2018
  */

#include "rocs/public/cmdln.h"


static const char* name = "OCmdLn";

typedef struct OCmdLnData {

    /** Argument count. */
  int argc;
    /** Argument values. */
  const char** argv;
    /** Argument values mapped with their key. */
  iOMap argMap;
    /**  */
  char* argStr;

} *iOCmdLnData;

static iOCmdLnData Data( void* p ) { return (iOCmdLnData)((iOCmdLn)p)->base.data; }

