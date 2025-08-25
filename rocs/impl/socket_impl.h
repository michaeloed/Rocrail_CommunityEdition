/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  2 2018 14:02:35)
  * Module: rocs
  * XML: $Source: /home/cvs/xspooler/rocs/rocs.xml,v $
  * XML: $Revision: 1.85 $
  * Date: Thu Aug  2 14:02:39 2018
  */

#include "rocs/public/socket.h"


static const char* name = "OSocket";

typedef struct OSocketData {

    /** Target hostname. */
  char* host;
    /** Target port. */
  int port;
    /** Local interface IP. */
  char* localip;
    /** Socket handle. */
  int sh;
    /** Current number of readed bytes. */
  long readed;
    /** Currently available bytes. */
  long peeked;
    /** Current number of written bytes. */
  long written;
    /** Last error. */
  int rc;
    /** Host address in xxx.xxx.xxx.xxx format. */
  void* hostaddr;
    /** Socket in blocking mode. */
  Boolean blocking;
    /** Socket is binded. */
  Boolean binded;
    /** Server socket is listening. */
  Boolean listening;
    /** Socket is connected. */
  Boolean connected;
    /** Socket is in SSL mode. */
  Boolean ssl;
    /**  */
  Boolean openssl_support;
    /** SSL control record. */
  SSL_CTX* ssl_ctx;
    /** SSL handle. */
  SSL* ssl_sh;
    /** Socket connection is broken. */
  Boolean broken;
    /** Socket is in UDP mode. */
  Boolean udp;
    /** Socket is in UDP multicast mode. */
  Boolean multicast;

} *iOSocketData;

static iOSocketData Data( void* p ) { return (iOSocketData)((iOSocket)p)->base.data; }

