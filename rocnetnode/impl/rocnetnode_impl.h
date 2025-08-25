/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Sep 24 2018 12:45:52)
  * Module: RocNetNode
  * XML: 
  * XML: 
  * Date: Mon Sep 24 12:45:53 2018
  */

#include "rocnetnode/public/rocnetnode.h"


static const char* name = "ORocNetNode";


/**  */
typedef struct RocMouse {
    /**  */
  int ioaddr;
    /**  */
  int adaddr;
    /**  */
  int lcaddr;
    /**  */
  byte io;
    /**  */
  int P1;
    /**  */
  int V_raw;
    /**  */
  int prev_V_raw;
    /**  */
  Boolean dir;
    /**  */
  Boolean prev_dir;
    /**  */
  int lightstrig;
    /**  */
  Boolean lights;
    /**  */
  Boolean prev_lights;
    /**  */
  int fgtrig;
    /**  */
  int fgroup;
    /**  */
  int fn[8];
    /**  */
  int prev_fn[8];
    /**  */
  int strig[8];
    /**  */
  int runLEDcnt;
    /**  */
  Boolean runLED;
} *iORocMouse;

/**  */
typedef struct Port {
    /**  */
  int port;
    /**  */
  int ionr;
    /** 0=i2c-1, 1=i2c-0, 3=direct */
  int iotype;
    /**  */
  int type;
    /**  */
  int delay;
    /**  */
  unsigned long ontimer;
    /**  */
  unsigned long offtimer;
    /**  */
  int state;
    /**  */
  int acktimer;
    /**  */
  int ackretry;
    /**  */
  Boolean ackpending;
    /**  */
  Boolean blink;
    /**  */
  Boolean toggle;
    /**  */
  int eventid;
    /**  */
  int eventport;
} *iOPort;

/**  */
typedef struct Channel {
    /**  */
  int channel;
    /**  */
  int delay;
    /**  */
  int onsteps;
    /**  */
  int offsteps;
    /**  */
  int onpos;
    /**  */
  int offpos;
    /**  */
  int curpos;
    /**  */
  int porttype;
    /**  */
  int options;
    /**  */
  Boolean blink;
    /**  */
  int state;
    /**  */
  Boolean ready;
    /**  */
  int idle;
    /**  */
  Boolean sleep;
} *iOChannel;

/**  */
typedef struct MacroLine {
    /**  */
  int delay;
    /**  */
  int port;
    /**  */
  int type;
    /**  */
  int value;
    /**  */
  Boolean blink;
} *iOMacroLine;

/**  */
typedef struct Macro {
    /**  */
  int slowdown;
    /**  */
  int repeat;
    /**  */
  int minutes;
    /**  */
  int hours;
    /**  */
  int wday;
    /**  */
  struct MacroLine line[16];
} *iOMacro;
typedef struct ORocNetNodeData {

    /**  */
  iONode ini;
    /**  */
  iONode digintini;
    /**  */
  iONode rfidini;
    /**  */
  iOThread reader;
    /**  */
  iOThread scanner;
    /**  */
  iOThread pwm;
    /**  */
  iOThread macroprocessor;
    /**  */
  Boolean run;
    /**  */
  Boolean power;
    /**  */
  Boolean identack;
    /**  */
  int iorc;
    /**  */
  int id;
    /**  */
  int location;
    /**  */
  const char* addr;
    /**  */
  int port;
    /**  */
  int nrio;
    /**  */
  iOSocket readUDP;
    /**  */
  iOSocket writeUDP;
    /**  */
  iOPort ports[129];
    /**  */
  iOChannel channels[129];
    /**  */
  iIDigInt pDI;
    /**  */
  iIDigInt pRFID;
    /**  */
  const char* i2cdevice;
    /**  */
  int i2cdescriptor;
    /**  */
  int iotype;
    /**  */
  int ip[6];
    /**  */
  int ipsize;
    /**  */
  int iomap[8];
    /**  */
  Boolean i2caddr[8];
    /**  */
  Boolean i2caddr40[8];
    /**  */
  int i2caddrError[8];
    /**  */
  int i2caddr40Error[8];
    /**  */
  byte iodata[16];
    /**  */
  Boolean sack;
    /**  */
  Boolean rfid;
    /**  */
  Boolean adcsensor;
    /**  */
  int adcthreshold;
    /**  */
  Boolean usepb;
    /**  */
  Boolean tl_info;
    /**  */
  Boolean tl_monitor;
    /**  */
  iOMutex i2cmux;
    /**  */
  Boolean startofday;
    /**  */
  Boolean adcstartofday;
    /**  */
  int LED1;
    /**  */
  int LED2;
    /**  */
  int PB1;
    /**  */
  int LED1timer;
    /**  */
  int LED2timer;
    /**  */
  int PB1timer;
    /**  */
  Boolean show;
    /**  */
  int cstype;
    /**  */
  int csdevice;
    /**  */
  const char* inifile;
    /**  */
  const char* libpath;
    /**  */
  Boolean consoleMode;
    /**  */
  Boolean pendingHalt;
    /**  */
  iOMacro macro[129];
    /**  */
  int class;
    /**  */
  iORocMouse rocmouses[8];
    /**  */
  iOThread rocmousescanner;
    /**  */
  iOThread adcsensorscanner;
    /**  */
  int adcsensorcounter[32];
    /**  */
  int adcsensorvalue[32];
    /**  */
  long adcsensortimer[32];
    /**  */
  Boolean stress;
    /**  */
  char nickname[64];
    /**  */
  char lastrfid[64];
    /**  */
  Boolean ismobile;
    /**  */
  int Vraw;
    /**  */
  Boolean Vdir;
    /**  */
  int Vmass;
    /**  */
  int Vmax;
    /**  */
  int VPWM;
    /**  */
  int VPWML;
    /**  */
  int VPWMR;
    /**  */
  int RPM;
    /**  */
  iOThread motorPWM;
    /**  */
  int fchanged;
    /**  */
  Boolean fn[32];
    /**  */
  byte rfidMsg[128];
    /**  */
  Boolean rfidAck;
    /**  */
  int rfidAckRetry;
    /**  */
  unsigned long rfidAckTimer;
    /**  */
  iOThread rfidAckWD;

} *iORocNetNodeData;

static iORocNetNodeData Data( void* p ) { return (iORocNetNodeData)((iORocNetNode)p)->base.data; }

