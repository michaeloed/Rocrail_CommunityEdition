/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  2 2018 14:02:35)
  * Module: rocs
  * XML: $Source: /home/cvs/xspooler/rocs/rocs.xml,v $
  * XML: $Revision: 1.85 $
  * Date: Thu Aug  2 14:02:39 2018
  */

#include "rocs/public/queue.h"


static const char* name = "OQueue";


/**  */
typedef struct SqMsg {
    /**  */
  obj o;
    /**  */
  q_prio prio;
    /**  */
  struct SqMsg* next;
} *qMsg;
typedef struct OQueueData {

    /**  */
  char* desc;
    /** Queue size. */
  int size;
    /** Number of messages in queue. */
  int count;
    /**  */
  iOMutex mux;
    /**  */
  iOEvent evt;
    /**  */
  qMsg first;
    /** 0 points to the last low prio message, 2 to the high. */
  qMsg last[3];

} *iOQueueData;

static iOQueueData Data( void* p ) { return (iOQueueData)((iOQueue)p)->base.data; }

