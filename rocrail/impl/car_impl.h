/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocRail
  * XML: $Source: /cvsroot/rojav/rocrail/rocrail.xml,v $
  * XML: $Revision: 1.56 $
  * Date: Fri Aug  3 14:03:35 2018
  */

#include "rocrail/public/car.h"


static const char* name = "OCar";

typedef struct OCarData {

    /**  */
  iONode props;
    /**  */
  Boolean fx[32];
    /**  */
  iOMap cvMap;

} *iOCarData;

static iOCarData Data( void* p ) { return (iOCarData)((iOCar)p)->base.data; }

