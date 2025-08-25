/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  2 2018 14:02:35)
  * Module: rocs
  * XML: $Source: /home/cvs/xspooler/rocs/rocs.xml,v $
  * XML: $Revision: 1.85 $
  * Date: Thu Aug  2 14:02:39 2018
  */

#include "rocs/public/strtok.h"


static const char* name = "OStrTok";

typedef struct OStrTokData {

    /** String value. */
  char* str;
    /** Separator. */
  char sep;
    /** Number of tokens in this string. */
  int countTokens;
    /** Pointer to next token. */
  char* nextToken;

} *iOStrTokData;

static iOStrTokData Data( void* p ) { return (iOStrTokData)((iOStrTok)p)->base.data; }

