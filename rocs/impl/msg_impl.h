/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  2 2018 14:02:35)
  * Module: rocs
  * XML: $Source: /home/cvs/xspooler/rocs/rocs.xml,v $
  * XML: $Revision: 1.85 $
  * Date: Thu Aug  2 14:02:39 2018
  */

#include "rocs/public/msg.h"


static const char* name = "OMsg";

typedef struct OMsgData {

    /** Reference to sender. */
  obj sender;
    /** Event type. */
  int event;
    /** time to wait before processing */
  int timer;
    /** Optional cargo. */
  void* usrdata;
    /** Type of cargo. */
  usrdatatype type;

} *iOMsgData;

static iOMsgData Data( void* p ) { return (iOMsgData)((iOMsg)p)->base.data; }

