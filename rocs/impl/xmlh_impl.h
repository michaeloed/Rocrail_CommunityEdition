/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  2 2018 14:02:35)
  * Module: rocs
  * XML: $Source: /home/cvs/xspooler/rocs/rocs.xml,v $
  * XML: $Revision: 1.85 $
  * Date: Thu Aug  2 14:02:39 2018
  */

#include "rocs/public/xmlh.h"


static const char* name = "OXmlh";

typedef struct OXmlhData {

    /**  */
  char* header_tagname;
    /**  */
  char* xml_tagname;
    /**  */
  char* bin_tagname;
    /**  */
  char* xmlh_begin;
    /**  */
  char* xmlh_end;
    /**  */
  Boolean beginHdr;
    /**  */
  Boolean endHdr;
    /**  */
  Boolean error;
    /**  */
  byte* buffer;
    /**  */
  int bufferIdx;
    /**  */
  int bufferSize;
    /**  */
  iONode xmlh;
    /**  */
  iOList xmlList;
    /**  */
  iOList binList;

} *iOXmlhData;

static iOXmlhData Data( void* p ) { return (iOXmlhData)((iOXmlh)p)->base.data; }

