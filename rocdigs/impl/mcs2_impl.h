/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocDigs
  * XML: $Source: /cvsroot/rojav/rocdigs/rocdigs.xml,v $
  * XML: $Revision: 1.14 $
  * Date: Fri Aug  3 14:03:49 2018
  */

#include "rocdigs/public/mcs2.h"


static const char* name = "OMCS2";

typedef struct OMCS2Data {

    /** DigInt Ini */
  iONode ini;
    /** MCS2 Ini */
  iONode mcs2ini;
    /** Trace pointer */
  iOTrace trace;
    /** Listener pointer */
  obj listenerObj;
    /** Listener Function pointer */
  digint_listener listenerFun;
    /** Interface ID */
  const char* iid;
    /** Gleisbox UID */
  int gbUID;
    /** MS2-GUI UID */
  int ms2UID;
    /** CS2 GFP UID */
  int mcs2gfpUID;
    /** CS2-GUI UID */
  int mcs2guiUID;
    /**  */
  Boolean run;
    /**  */
  Boolean udp;
    /**  */
  Boolean conOK;
    /**  */
  iOSerial serial;
    /**  */
  iOSocket readUDP;
    /**  */
  iOSocket writeUDP;
    /**  */
  iOThread reader;
    /**  */
  iOThread writer;
    /**  */
  iOThread feedbackReader;
    /**  */
  int fbmod;
    /**  */
  int swtime;
    /**  */
  Boolean power;
    /**  */
  Boolean sensor;
    /**  */
  iOThread discovery;
    /**  */
  Boolean initASCII;
    /**  */
  int cmdpause;
    /**  */
  int sensorbegin;
    /**  */
  int sensorend;
    /**  */
  int load;
    /**  */
  int volt;
    /**  */
  int temp;
    /**  */
  Boolean overload;
    /**  */
  int sod_fbmod;
    /**  */
  int sod_sensorbegin;
    /**  */
  int sod_sensorend;
    /** Id name */
  char* id;
    /** address */
  int sid;
    /** UID */
  unsigned int uid;
    /**  */
  iONode locolist;
    /**  */
  iOThread mfxbinder;
    /**  */
  Boolean mfxDetectInProgress;
    /**  */
  Boolean swtimeset;
    /** address which is processed for bind verification */
  int xS2handling;
    /**  */
  iOThread mgboxsvc;
    /** monitor channel */
  int lstChn;
    /**  */
  byte configchnl;
    /**  */
  byte lastseqnr;
    /**  */
  byte idxcnt;
    /**  */
  float loadStepRate;
    /**  */
  float voltStepRate;
    /**  */
  float tempStepRate;
    /**  */
  byte indices;

} *iOMCS2Data;

static iOMCS2Data Data( void* p ) { return (iOMCS2Data)((iOMCS2)p)->base.data; }

