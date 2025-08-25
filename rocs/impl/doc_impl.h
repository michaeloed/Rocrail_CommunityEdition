/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  2 2018 14:02:35)
  * Module: rocs
  * XML: $Source: /home/cvs/xspooler/rocs/rocs.xml,v $
  * XML: $Revision: 1.85 $
  * Date: Thu Aug  2 14:02:39 2018
  */

#include "rocs/public/doc.h"


static const char* name = "ODoc";

/*  */
#define startToken "<%s"
/*  */
#define endToken "</%s>"
/*  */
#define endInline "/>"
/*  */
#define remToken "<!--"
/*  */
#define remEndToken "-->"
/*  */
#define propToken "<?"
/*  */
#define propEndToken "?>"
/*  */
#define varToken "<!"
/*  */
#define varEndToken ">"
typedef struct ODocData {

    /** Document. */
  iONode doc;
    /** Root. */
  iONode root;
    /** Is UTF-8 encoded. */
  Boolean utf8;

} *iODocData;

static iODocData Data( void* p ) { return (iODocData)((iODoc)p)->base.data; }

