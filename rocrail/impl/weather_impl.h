/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocRail
  * XML: $Source: /cvsroot/rojav/rocrail/rocrail.xml,v $
  * XML: $Revision: 1.56 $
  * Date: Fri Aug  3 14:03:35 2018
  */

#include "rocrail/public/weather.h"


static const char* name = "OWeather";

typedef struct OWeatherData {

    /**  */
  iONode props;
    /**  */
  Boolean run;
    /**  */
  iOThread makeWeather;
    /**  */
  iONode theme;
    /**  */
  int themeduration;
    /**  */
  int themedim;
    /**  */
  int themetimer1;
    /**  */
  int themetimerrand;
    /**  */
  Boolean themestartup;
    /**  */
  Boolean themeshutdown;
    /**  */
  char* requestedTheme;
    /**  */
  int themesoundtimer;
    /**  */
  int themedimtimer;
    /**  */
  int starthour;
    /**  */
  int startminute;
    /**  */
  Boolean ebreak;

} *iOWeatherData;

static iOWeatherData Data( void* p ) { return (iOWeatherData)((iOWeather)p)->base.data; }

