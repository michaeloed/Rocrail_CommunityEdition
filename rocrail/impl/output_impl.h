/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocRail
  * XML: $Source: /cvsroot/rojav/rocrail/rocrail.xml,v $
  * XML: $Revision: 1.56 $
  * Date: Fri Aug  3 14:03:35 2018
  */

#include "rocrail/public/output.h"


static const char* name = "OOutput";

typedef struct OOutputData {

    /**  */
  iONode props;
    /** Address key */
  char* addrKey;
    /**  */
  iOList listeners;

} *iOOutputData;

static iOOutputData Data( void* p ) { return (iOOutputData)((iOOutput)p)->base.data; }

