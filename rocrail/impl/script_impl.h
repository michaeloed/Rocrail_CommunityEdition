/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocRail
  * XML: $Source: /cvsroot/rojav/rocrail/rocrail.xml,v $
  * XML: $Revision: 1.56 $
  * Date: Fri Aug  3 14:03:35 2018
  */

#include "rocrail/public/script.h"


static const char* name = "OScript";

typedef struct OScriptData {

    /**  */
  int linenr;
    /**  */
  const char* pline;
    /**  */
  int nrlines;
    /**  */
  const char* script;
    /**  */
  char* record;
    /**  */
  Boolean recording;
    /**  */
  Boolean playing;
    /**  */
  Boolean pause;
    /**  */
  iOThread player;
    /**  */
  Boolean run;
    /**  */
  long prevtime;
    /**  */
  obj callback;
    /**  */
  Boolean stamp;

} *iOScriptData;

static iOScriptData Data( void* p ) { return (iOScriptData)((iOScript)p)->base.data; }

