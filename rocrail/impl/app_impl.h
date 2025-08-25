/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocRail
  * XML: $Source: /cvsroot/rojav/rocrail/rocrail.xml,v $
  * XML: $Revision: 1.56 $
  * Date: Fri Aug  3 14:03:35 2018
  */

#include "rocrail/public/app.h"


static const char* name = "OApp";

typedef struct OAppData {

    /** RocRail ini */
  iONode ini;
    /** RocRail ini */
  iONode newini;
    /**  */
  iOModel model;
    /**  */
  iOControl control;
    /**  */
  iOWeather weather;
    /**  */
  iOClntCon clntCon;
    /**  */
  iOSrcpCon srcpCon;
    /**  */
  long appstartTime;
    /**  */
  iOHttp http;
    /**  */
  iOSNMP snmp;
    /**  */
  Boolean consoleMode;
    /**  */
  const char* szIniFile;
    /**  */
  const char* szLibPath;
    /**  */
  const char* szImgPath;
    /**  */
  Boolean stress;
    /**  */
  Boolean createmodplan;
    /**  */
  int revno;
    /**  */
  Boolean run;
    /**  */
  iOScript script;

} *iOAppData;

static iOAppData Data( void* p ) { return (iOAppData)((iOApp)p)->base.data; }

