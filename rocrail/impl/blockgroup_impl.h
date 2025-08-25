/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocRail
  * XML: $Source: /cvsroot/rojav/rocrail/rocrail.xml,v $
  * XML: $Revision: 1.56 $
  * Date: Fri Aug  3 14:03:35 2018
  */

#include "rocrail/public/blockgroup.h"


static const char* name = "OBlockGroup";

typedef struct OBlockGroupData {

    /**  */
  iONode props;
    /**  */
  iOMap lockmap;
    /**  */
  const char* firstBlock;
    /**  */
  const char* firstLoco;
    /**  */
  Boolean allowfollowup;
    /**  */
  int maxfollowup;
    /**  */
  Boolean followupend;

} *iOBlockGroupData;

static iOBlockGroupData Data( void* p ) { return (iOBlockGroupData)((iOBlockGroup)p)->base.data; }

