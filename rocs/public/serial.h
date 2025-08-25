/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  2 2018 14:02:35)
  * Module: rocs
  * XML: $Source: /home/cvs/xspooler/rocs/rocs.xml,v $
  * XML: $Revision: 1.85 $
  * Date: Thu Aug  2 14:02:39 2018
  */

#ifndef __object_Serial_H
#define __object_Serial_H

#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"

#ifdef __cplusplus
  extern "C" {
#endif


typedef enum {none=0,even=1,odd=2} serial_parity;
typedef enum {cts=1,dsr=2,xon=3} serial_flow;
typedef enum {onestopbit=1,twostopbits=2} serial_stopbits;
typedef enum {eight=8,seven=7} serial_databits;
typedef enum {undefined=0,mm=1,dcc=2,mma=3} serial_mode;
typedef int serial_bps;



typedef struct OSerial {
  /***** Base *****/
  struct OBase  base;

  /***** Object: Serial *****/
  /** Get number of bytes available to read. */
  int (*available)( struct OSerial* inst );
  /** Close the port. */
  Boolean (*close)( struct OSerial* inst );
  /** clear output buffer */
  void (*flush)( struct OSerial* inst );
  /** Formats a string. */
  Boolean (*fmt)( struct OSerial* inst ,const char* format ,...  );
  /** Get last error. */
  int (*getRc)( struct OSerial* inst );
  /** Get actual readed byte count. */
  int (*getReadCnt)( struct OSerial* inst );
  /** Get number of bytes waiting to send. */
  int (*getWaiting)( struct OSerial* inst );
  /** Object creator. */
  struct OSerial* (*inst)( const char* device );
  /** Control To Send. */
  Boolean (*isCTS)( struct OSerial* inst );
  /** Data Set Ready. */
  Boolean (*isDSR)( struct OSerial* inst );
  /** Ring Indicator. */
  Boolean (*isRI)( struct OSerial* inst );
  /**  */
  Boolean (*isUartEmpty)( struct OSerial* inst ,Boolean soft );
  /** Try to open and to initialize the port. */
  Boolean (*open)( struct OSerial* inst );
  /** Read some bytes. */
  Boolean (*read)( struct OSerial* inst ,char* buffer ,int count );
  /** Read till a linefeed is detected. */
  char* (*readln)( struct OSerial* inst ,char* buffer );
  /** Set blocking/non-blocking io. */
  void (*setBlocking)( struct OSerial* inst ,Boolean blocking );
  /** Clear To Send. */
  void (*setCTS)( struct OSerial* inst ,Boolean cts );
  /** Data Terminal Ready. */
  void (*setDTR)( struct OSerial* inst ,Boolean dtr );
  /** Custom Divisor. */
  void (*setDivisor)( struct OSerial* inst ,int divisor );
  /** Set data flow control. */
  void (*setFlow)( struct OSerial* inst ,serial_flow flow );
  /** Set line settings. */
  void (*setLine)( struct OSerial* inst ,serial_bps bps ,serial_databits databits ,serial_stopbits stopbits ,serial_parity parity ,Boolean rtsdisabled );
  /** set output flow on off */
  void (*setOutputFlow)( struct OSerial* inst ,Boolean flow );
  /** Set data flow control. */
  void (*setPortBase)( struct OSerial* inst ,int addr );
  /** Request To Send. */
  void (*setRTS)( struct OSerial* inst ,Boolean rts );
  /** Set uart speed for MM or DCC */
  void (*setSerialMode)( struct OSerial* inst ,serial_mode mode );
  /** Set timeout. */
  void (*setTimeout)( struct OSerial* inst ,int wtime ,int trime );
  /** Do busy wait for MM protocol */
  void (*waitMM)( struct OSerial* inst ,int usperiod ,int uspause );
  /** Write some bytes. */
  Boolean (*write)( struct OSerial* inst ,const char* buffer ,int count );
} *iOSerial;

extern struct OSerial SerialOp;

#ifdef __cplusplus
  }
#endif


#endif
