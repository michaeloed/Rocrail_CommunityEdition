/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocDigs
  * XML: $Source: /cvsroot/rojav/rocdigs/rocdigs.xml,v $
  * XML: $Revision: 1.14 $
  * Date: Fri Aug  3 14:03:49 2018
  */

#include "rocdigs/public/loconet.h"


static const char* name = "OLocoNet";

typedef struct OLocoNetData {

    /**  */
  iONode ini;
    /**  */
  iONode loconet;
    /**  */
  iONode options;
    /**  */
  iONode slotserver;
    /**  */
  obj listenerObj;
    /**  */
  digint_listener listenerFun;
    /**  */
  Boolean dummyio;
    /**  */
  iOSerial serial;
    /**  */
  iOSocket socket;
    /**  */
  iOSocket rwTCP;
    /**  */
  iOSocket readUDP;
    /**  */
  iOSocket writeUDP;
    /**  */
  iOMutex mux;
    /**  */
  iOThread loconetReader;
    /**  */
  iOThread loconetWriter;
    /**  */
  iOThread swReset;
    /**  */
  iOThread SensorQuery;
    /**  */
  unsigned long lastSwCmd;
    /**  */
  const char* device;
    /**  */
  serial_bps bps;
    /**  */
  int timeout;
    /**  */
  int swtime;
    /**  */
  int psleep;
    /**  */
  const char* iid;
    /**  */
  Boolean run;
    /**  */
  Boolean commOK;
    /**  */
  Boolean initOK;
    /**  */
  byte initPacket[127];
    /**  */
  int slots;
    /**  */
  byte opsw[10];
    /**  */
  Boolean opswreaded;
    /**  */
  int locoslot[128];
    /**  */
  int locothrottle[128];
    /**  */
  byte slotV[128];
    /**  */
  time_t slotaccessed[128];
    /**  */
  int purgetime;
    /**  */
  iOMutex slotmux;
    /**  */
  iOThread slotPing;
    /**  */
  Boolean activeSlotServer;
    /**  */
  Boolean serveLConly;
    /**  */
  iOThread slotServer;
    /**  */
  long rcvpkg;
    /**  */
  long sndpkg;
    /**  */
  int ctsretry;
    /**  */
  Boolean power;
    /**  */
  Boolean pt;
    /**  */
  Boolean comm;
    /**  */
  sublib_connect lnConnect;
    /**  */
  sublib_disconnect lnDisconnect;
    /**  */
  sublib_read lnRead;
    /**  */
  sublib_write lnWrite;
    /**  */
  sublib_available lnAvailable;
    /**  */
  Boolean didSensorQuery;
    /**  */
  Boolean doSensorQuery;
    /**  */
  Boolean stress;
    /**  */
  iOThread stressRunner;
    /**  */
  Boolean cts;
    /**  */
  Boolean fcsync;
    /**  */
  Boolean powerison;
    /**  */
  iOThread udpReader;
    /**  */
  iOMutex udpmux;
    /**  */
  iOQueue udpQueue;
    /**  */
  iOThread subReader;
    /**  */
  iOThread subWriter;
    /**  */
  iOQueue subReadQueue;
    /**  */
  iOQueue subWriteQueue;
    /**  */
  iOMutex subReadMux;
    /**  */
  iOMutex subWriteMux;
    /**  */
  Boolean subSendEcho;
    /**  */
  char subSendPacket[127];
    /**  */
  int subSendLen;
    /**  */
  Boolean busy;
    /**  */
  Boolean useseq;
    /**  */
  byte inseq;
    /**  */
  byte outseq;
    /**  */
  byte prevPacket[127];
    /**  */
  Boolean usedouble;
    /**  */
  Boolean expectdouble;
    /**  */
  int packetloss;
    /**  */
  Boolean swack;
    /**  */
  int swretry;
    /**  */
  int swsleep;
    /**  */
  iOThread lissyReset;
    /**  */
  Boolean resetLissy;
    /**  */
  Boolean GBM16xn;
    /**  */
  Boolean monitor;

} *iOLocoNetData;

static iOLocoNetData Data( void* p ) { return (iOLocoNetData)((iOLocoNet)p)->base.data; }

