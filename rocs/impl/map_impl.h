/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  2 2018 14:02:35)
  * Module: rocs
  * XML: $Source: /home/cvs/xspooler/rocs/rocs.xml,v $
  * XML: $Revision: 1.85 $
  * Date: Thu Aug  2 14:02:39 2018
  */

#include "rocs/public/map.h"


static const char* name = "OMap";

/*  */
#define NHASH 1013
/*  */
#define MULTIPLIER 31
typedef struct OMapData {

    /** Index for next. */
  int index;
    /**  */
  int size;
    /**  */
  iOList hashTable[NHASH];

} *iOMapData;

static iOMapData Data( void* p ) { return (iOMapData)((iOMap)p)->base.data; }


/** Container for a mapitem. */
typedef struct MapItem {
    /** Index for next. */
  char* key;
    /** Object. */
  obj o;
} *iMapItem;
