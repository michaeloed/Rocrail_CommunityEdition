/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  2 2018 14:02:35)
  * Module: rocs
  * XML: $Source: /home/cvs/xspooler/rocs/rocs.xml,v $
  * XML: $Revision: 1.85 $
  * Date: Thu Aug  2 14:02:39 2018
  */

#ifndef __object_Socket_H
#define __object_Socket_H

#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"

/* rocs and system includes: */
#include <stdio.h>

#ifdef __cplusplus
  extern "C" {
#endif


typedef void (*socket_listener)(unsigned char* in,int len);



typedef struct OSocket {
  /***** Base *****/
  struct OBase  base;

  /***** Object: Socket *****/
  /** Accept client connections. */
  struct OSocket* (*accept)( struct OSocket* inst );
  /**  */
  Boolean (*bind)( struct OSocket* inst );
  /** Connect socket with target. */
  Boolean (*connect)( struct OSocket* inst );
  /** Disconnect from remote peer. */
  void (*disConnect)( struct OSocket* inst );
  /** Formats a string. */
  Boolean (*fmt)( struct OSocket* inst ,const char* format ,...  );
  /**  */
  char* (*getMAC)( const char* device );
  /** Get number of peeked bytes. */
  long (*getPeeked)( struct OSocket* inst );
  /**  */
  const char* (*getPeername)( struct OSocket* inst );
  /** Get last error. */
  int (*getRc)( struct OSocket* inst );
  /** Get number of readed bytes. */
  long (*getReceived)( struct OSocket* inst );
  /** Get number of written bytes. */
  long (*getSended)( struct OSocket* inst );
  /** Get socket stream object. */
  FILE * (*getStream)( struct OSocket* inst );
  /** Get local host dotted address. */
  const char* (*gethostaddr)( void );
  /** Get local hostname. */
  const char* (*gethostname)( void );
  /**  */
  const char* (*getsockname)( struct OSocket* inst );
  /** Object creator. */
  struct OSocket* (*inst)( const char* host ,int port ,Boolean ssl ,Boolean udp ,Boolean multicast );
  /** Object creator. */
  struct OSocket* (*instSSLserver)( int port ,const char* certFile ,const char* keyFile );
  /** Is connection broken? */
  Boolean (*isBroken)( struct OSocket* inst );
  /** Socket is connected. */
  Boolean (*isConnected)( struct OSocket* inst );
  /** OpenSSL support is enabled. */
  Boolean (*isOpenSSL)( void );
  /** Check if last returncode is a ETIMEDOUT error. */
  Boolean (*isTimedOut)( struct OSocket* inst );
  /** Are some bytes waiting to be read? */
  Boolean (*peek)( struct OSocket* inst ,char* buffer ,int size );
  /** Read bytes. */
  Boolean (*read)( struct OSocket* inst ,char* buffer ,int size );
  /** Read til a terminating zero is detected. */
  char* (*readStr)( struct OSocket* inst ,char* buffer );
  /** Read one character. */
  char (*readc)( struct OSocket* inst );
  /** Read till a linefeed is detected. */
  char* (*readln)( struct OSocket* inst ,char* buffer );
  /** Receive udp message. */
  int (*recvfrom)( struct OSocket* inst ,char* buffer ,int size ,char* client ,int* port );
  /** Reset the socket; clear flags. */
  void (*reset)( struct OSocket* inst );
  /** Send udp message. */
  Boolean (*sendto)( struct OSocket* inst ,char* buffer ,int size ,char* client ,int port );
  /** Set blocking. */
  Boolean (*setBlocking)( struct OSocket* inst ,Boolean blocking );
  /**  */
  Boolean (*setBroadcast)( struct OSocket* inst ,Boolean broadcast );
  /**  */
  Boolean (*setKeepalive)( struct OSocket* inst ,Boolean keepalive );
  /** NOT IMPLEMENTED!. */
  void (*setListener)( struct OSocket* inst ,socket_listener listener );
  /** Local interface IP. */
  void (*setLocalIP)( struct OSocket* inst ,const char* ip );
  /**  */
  Boolean (*setNodelay)( struct OSocket* inst ,Boolean flag );
  /** Set timeout value for reading. */
  Boolean (*setRcvTimeout)( struct OSocket* inst ,int timeout );
  /** Set timeout value for writing. */
  Boolean (*setSndTimeout)( struct OSocket* inst ,int timeout );
  /** Write bytes. */
  Boolean (*write)( struct OSocket* inst ,const char* buffer ,int size );
  /** Write one character. */
  Boolean (*writec)( struct OSocket* inst ,char c );
} *iOSocket;

extern struct OSocket SocketOp;

#ifdef __cplusplus
  }
#endif


#endif
