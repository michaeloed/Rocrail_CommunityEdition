/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  2 2018 14:02:35)
  * Module: rocs
  * XML: $Source: /home/cvs/xspooler/rocs/rocs.xml,v $
  * XML: $Revision: 1.85 $
  * Date: Thu Aug  2 14:02:39 2018
  */

#include "rocs/public/serial.h"


static const char* name = "OSerial";


/**  */
 struct _line {
    /**  */
  int bps;
    /**  */
  int bits;
    /**  */
  serial_stopbits stopbits;
    /**  */
  serial_parity parity;
    /**  */
  serial_flow flow;
    /**  */
  Boolean rtsdisabled;
} ;

/**  */
 struct _timeout {
    /**  */
  int write;
    /**  */
  int read;
} ;
typedef struct OSerialData {

    /** Serial device name. */
  char* device;
    /**  */
  int portbase;
    /**  */
  void* handle;
    /**  */
  long sh;
    /**  */
  int rc;
    /**  */
  int read;
    /** used if != 0 */
  int divisor;
    /**  */
  int ioState;
    /**  */
  struct _line line;
    /**  */
  struct _timeout timeout;
    /** True for blocking IO */
  Boolean blocking;
    /** pointer to Win overlapped struct */
  void* overlapped;
    /** True for 16550 compatible devices */
  Boolean directIO;
    /**  */
  int currserialmode;

} *iOSerialData;

static iOSerialData Data( void* p ) { return (iOSerialData)((iOSerial)p)->base.data; }

