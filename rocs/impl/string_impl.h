/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  2 2018 14:02:35)
  * Module: rocs
  * XML: $Source: /home/cvs/xspooler/rocs/rocs.xml,v $
  * XML: $Revision: 1.85 $
  * Date: Thu Aug  2 14:02:39 2018
  */

#include "rocs/public/string.h"


static const char* name = "OString";

/*  */
#define STRING_MINSIZE 80
typedef struct OStringData {

    /** String value. */
  char* str;
    /** String length. */
  int len;

} *iOStringData;

static iOStringData Data( void* p ) { return (iOStringData)((iOString)p)->base.data; }

