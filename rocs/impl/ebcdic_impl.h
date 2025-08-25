/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  2 2018 14:02:35)
  * Module: rocs
  * XML: $Source: /home/cvs/xspooler/rocs/rocs.xml,v $
  * XML: $Revision: 1.85 $
  * Date: Thu Aug  2 14:02:39 2018
  */

#include "rocs/public/ebcdic.h"


static const char* name = "OEbcdic";

typedef struct OEbcdicData {

    /** Active codepage. */
  int CodePage;
    /** External converter file in XML format. */
  const char* file;
    /**  */
  unsigned char AsciiToEbcdicTable[256];
    /**  */
  unsigned char EbcdicToAsciiTable[256];

} *iOEbcdicData;

static iOEbcdicData Data( void* p ) { return (iOEbcdicData)((iOEbcdic)p)->base.data; }

