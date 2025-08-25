/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocDigs
  * XML: $Source: /cvsroot/rojav/rocdigs/rocdigs.xml,v $
  * XML: $Revision: 1.14 $
  * Date: Fri Aug  3 14:03:49 2018
  */

#include "rocdigs/public/bidib.h"


static const char* name = "OBiDiB";


/**  */
typedef struct bidibnode {
    /**  */
  int uid;
    /**  */
  byte path[4];
    /**  */
  int classid;
    /**  */
  int vendorid;
    /**  */
  int seq;
    /**  */
  int load;
    /**  */
  int volt;
    /**  */
  int temp;
    /**  */
  int loadmax;
    /**  */
  int voltmin;
    /**  */
  int tempmax;
    /**  */
  int stat;
    /**  */
  int laststat;
    /**  */
  Boolean shortcut;
    /**  */
  Boolean fwup;
    /**  */
  Boolean iocfg;
    /**  */
  int conf_void;
    /**  */
  int conf_freeze;
    /**  */
  int conf_signal;
    /**  */
  byte occ[128];
    /**  */
  int bmload[128];
    /**  */
  int sensorcnt;
    /**  */
  Boolean sod;
    /**  */
  int inputcnt;
    /**  */
  Boolean sod4key;
    /**  */
  int pendingfeature;
    /**  */
  char* dmxchannel;
    /**  */
  char username[128];
    /**  */
  int signalquality;
    /**  */
  char* signalreporter;
    /**  */
  int signalport;
} *iOBiDiBNode;

/** Queue command. */
typedef struct QBiDiBCmd {
    /**  */
  byte path[4];
    /**  */
  byte msg[256];
    /**  */
  int opc;
    /**  */
  int len;
    /**  */
  unsigned long time;
    /**  */
  unsigned long delay;
    /**  */
  iOBiDiBNode bidibnode;
} *iQBiDiBCmd;

/** Loco slot */
typedef struct slot {
    /**  */
  char* id;
    /**  */
  int addr;
    /**  */
  int V;
    /**  */
  int Vraw;
    /**  */
  int steps;
    /**  */
  Boolean dir;
    /**  */
  Boolean f[32];
    /**  */
  int kmh;
} *iOSlot;
typedef struct OBiDiBData {

    /**  */
  iONode ini;
    /**  */
  iONode bidibini;
    /**  */
  const char* iid;
    /**  */
  const char* device;
    /**  */
  iOSocket rwUDP;
    /**  */
  int swtime;
    /**  */
  Boolean run;
    /**  */
  Boolean power;
    /**  */
  Boolean csgo;
    /**  */
  int load;
    /**  */
  int volt;
    /**  */
  int temp;
    /**  */
  int tabver;
    /**  */
  iOMap nodemap;
    /**  */
  iOMap localmap;
    /**  */
  obj listenerObj;
    /**  */
  digint_listener listenerFun;
    /**  */
  iOSerial serial;
    /**  */
  iOMutex mux;
    /**  */
  Boolean commOK;
    /**  */
  Boolean magicOK;
    /**  */
  unsigned long lastMagicReq;
    /**  */
  Boolean secAck;
    /**  */
  int secAckInt;
    /**  */
  iOThread reader;
    /**  */
  iOThread writer;
    /**  */
  byte downSeq;
    /**  */
  byte upSeq;
    /**  */
  sublib_init subInit;
    /**  */
  sublib_connect subConnect;
    /**  */
  sublib_disconnect subDisconnect;
    /**  */
  sublib_read subRead;
    /**  */
  sublib_write subWrite;
    /**  */
  sublib_available subAvailable;
    /**  */
  iOThread subReader;
    /**  */
  iOThread subWriter;
    /**  */
  iOQueue subReadQueue;
    /**  */
  iOQueue subWriteQueue;
    /**  */
  int cv;
    /**  */
  int value;
    /**  */
  Boolean ptflag;
    /**  */
  byte nodepath[4];
    /**  */
  iOBiDiBNode defaultbooster;
    /**  */
  iOBiDiBNode defaultprog;
    /**  */
  iOBiDiBNode defaultswitch;
    /**  */
  iOBiDiBNode defaultmain;
    /**  */
  iOBiDiBNode hexnode;
    /**  */
  char* hexfile;
    /**  */
  int hexline;
    /**  */
  int hexstate;
    /**  */
  iOFile hexfh;
    /**  */
  Boolean fcsync;
    /**  */
  iOMutex lcmux;
    /**  */
  iOMap lcmap;
    /**  */
  Boolean stress;
    /**  */
  iOThread stressRunner;
    /**  */
  iOBiDiBNode stressnode;
    /**  */
  iOThread watchdogRunner;
    /**  */
  int watchdogInt;
    /**  */
  Boolean dccreset;
    /**  */
  iOThread timedQueue;

} *iOBiDiBData;

static iOBiDiBData Data( void* p ) { return (iOBiDiBData)((iOBiDiB)p)->base.data; }

