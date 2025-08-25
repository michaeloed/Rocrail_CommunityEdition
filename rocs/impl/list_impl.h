/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  2 2018 14:02:35)
  * Module: rocs
  * XML: $Source: /home/cvs/xspooler/rocs/rocs.xml,v $
  * XML: $Revision: 1.85 $
  * Date: Thu Aug  2 14:02:39 2018
  */

#include "rocs/public/list.h"


static const char* name = "OList";

/* Initial listsize. */
#define LIST_MINSIZE 20
typedef struct OListData {

    /** List items. */
  obj* objList;
    /** Item pointer for next function. */
  int ix;
    /** Number of items in list. */
  int size;
    /** List size. */
  int allocsize;

} *iOListData;

static iOListData Data( void* p ) { return (iOListData)((iOList)p)->base.data; }

