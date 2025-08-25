/*
 Rocs - OS independent C library

 Copyright (C) 2002-2014 Rob Versluis, Rocrail.net

 


 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public License
 as published by the Free Software Foundation.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU Lesser General Public License for more details.

 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/
#ifdef _WIN32

#include <stdlib.h>
#include <string.h>
/*#include <winsock.h>*/
#include <winsock2.h>
#include <ws2tcpip.h>

/*
  You must install the Windows SDK for the [iphlpapi.h] support!!!
  ...Or use the rocs/impl/win/iphlpapi.zip...
*/
#include <iphlpapi.h>

#define ETIMEDOUT WSAETIMEDOUT

#ifdef __OPENSSL__
  #include <openssl/crypto.h>
  #include <openssl/x509.h>
  #include <openssl/pem.h>
  #include <openssl/ssl.h>
  #include <openssl/err.h>
#else
  #define SSL_CTX void
  #define SSL void
#endif

#include "rocs/impl/socket_impl.h"
#include "rocs/public/trace.h"
#include "rocs/public/thread.h"
#include "rocs/public/mem.h"
#include "rocs/public/str.h"

#ifndef __ROCS_SOCKET__
        #pragma message("*** Win32 OSocket is disabled. (define __ROCS_SOCKET__ in rocs.h) ***")
#endif
/*
 ***** __Private functions.
 */

static char* __mac = NULL;
char* rocs_socket_mac( const char* device ) {
#ifdef __ROCS_SOCKET__
  if( __mac == NULL ) {
    PIP_ADAPTER_INFO pAdapterInfo;
    PIP_ADAPTER_INFO pAdapter = NULL;
    DWORD dwRetVal = 0;

    ULONG ulOutBufLen = sizeof(IP_ADAPTER_INFO) * 10;
    pAdapterInfo = (IP_ADAPTER_INFO *) allocMem( ulOutBufLen );

    // Make an initial call to GetAdaptersInfo to get
    // the necessary size into the ulOutBufLen variable
    if (GetAdaptersInfo( pAdapterInfo, &ulOutBufLen) == ERROR_BUFFER_OVERFLOW) {
     TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999,
                 "rocs_socket_mac(): new BufferLen=%ld", ulOutBufLen );
      freeMem(pAdapterInfo);
      pAdapterInfo = (IP_ADAPTER_INFO *) allocMem( ulOutBufLen );
    }

    if ((dwRetVal = GetAdaptersInfo( pAdapterInfo, &ulOutBufLen)) == NO_ERROR) {
      pAdapter = pAdapterInfo;
      __mac = StrOp.fmt( "%02X%02X%02X%02X%02X%02X%02X%02X",
                          (unsigned char)pAdapter->Address[0],
                          (unsigned char)pAdapter->Address[1],
                          (unsigned char)pAdapter->Address[2],
                          (unsigned char)pAdapter->Address[3],
                          (unsigned char)pAdapter->Address[4],
                          (unsigned char)pAdapter->Address[5],
                          (unsigned char)pAdapter->Address[6],
                          (unsigned char)pAdapter->Address[7]
                      );
      TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999,
                   "rocs_socket_mac(): [%s]", __mac );
    }
    else {
      TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999,
                   "rocs_socket_mac(): rc = %d, errno = %d", dwRetVal, errno );
    }

    freeMem( pAdapterInfo );

  }
  return __mac;
#else
  return NULL;
#endif
}

/* OS dependent */
/* initializes the windows socket implementation */
Boolean rocs_socket_init( iOSocketData o ) {
#ifdef __ROCS_SOCKET__
  WSADATA         WsaData;

  if( o->hostaddr == NULL ) {
    o->hostaddr = allocIDMem( sizeof( struct in_addr ), RocsSocketID );
  }

  /* Init WinSocks 1.1 */
  if( WSAStartup(0x0101, &WsaData) == SOCKET_ERROR )
  {
    o->rc = WSAGetLastError();
    TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "WSAStartup() failed: %d", WSAGetLastError());
    return False;
  }
  TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "WinSocks initialized." );
#endif
  return True;
}

Boolean rocs_socket_istimedout( iOSocketData o ) {
#ifdef __ROCS_SOCKET__
  if( o->rc == WSAETIMEDOUT )
    return True;
#endif
  return False;
}




/* OS dependent */
static Boolean __resolveHost( iOSocketData o, const char* hostname ) {
#ifdef __ROCS_SOCKET__
  struct hostent* host = NULL;
  struct in_addr* addr = o->hostaddr;

  addr->S_un.S_addr = inet_addr( hostname );

  if( addr->S_un.S_addr == INADDR_NONE ) {
    host = gethostbyname( hostname );
    if( host == NULL ) {
      o->rc = WSAGetLastError();
      TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "Error looking up host. (rc=%d)", WSAGetLastError() );
      return False;
    }
    memcpy (o->hostaddr, host->h_addr, host->h_length);
  }

  TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "HostAddr: %d", addr->S_un.S_addr );
#endif
  return True;
}

Boolean rocs_socket_resolveHost( iOSocketData o ) {
#ifdef __ROCS_SOCKET__
  return __resolveHost(o, o->host);
#endif
  return True;
}

/* OS dependent */
Boolean rocs_socket_create( iOSocketData o ) {
#ifdef __ROCS_SOCKET__
  o->sh = socket( AF_INET, o->udp ? SOCK_DGRAM:SOCK_STREAM, o->udp ? IPPROTO_UDP:IPPROTO_TCP );
  if( o->sh < 0 ) {
    o->rc = WSAGetLastError();
    TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "socket() failed [%d]", WSAGetLastError() );
    return False;
  }
  TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "socket created." );
#endif
  return True;
}


void rocs_socket_localip( iOSocketData o, const char* ip ) {
#ifdef __ROCS_SOCKET__
  struct in_addr localInterface;
  /* IP_MULTICAST_IF:  Sets the interface over which outgoing multicast datagrams are sent. */
  TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "Set the interface over which outgoing multicast datagrams are sent..." );
  localInterface.s_addr = inet_addr(ip);
  if(setsockopt(o->sh, IPPROTO_IP, IP_MULTICAST_IF, (char *)&localInterface, sizeof(localInterface)) < 0)
  {
    o->rc = errno;
    TraceOp.terrno( name, TRCLEVEL_EXCEPTION, __LINE__, 8015, o->rc, "setsockopt() failed" );
  }
#endif
}


/* OS dependent */
Boolean rocs_socket_close( iOSocketData o ) {
#ifdef __ROCS_SOCKET__
  int rc = 0;

  if( o->ssl ) {
    #ifdef __OPENSSL__
    if( o->ssl_sh )
      /* send SSL/TLS close_notify */
      SSL_shutdown( o->ssl_sh );
    #endif
  }

  /* remove Multicast Socket from group */
  if (o->udp && o->multicast ) {
    struct ip_mreq command;
    command.imr_multiaddr.s_addr = inet_addr (o->host);
    command.imr_interface.s_addr = htonl (INADDR_ANY);
    setsockopt( o->sh, IPPROTO_IP, IP_DROP_MEMBERSHIP,  (void*)&command, sizeof (command));
  }

  rc = closesocket( o->sh );
  if (rc != 0)   /* free all allocated resources */
  {
    o->rc = WSAGetLastError();
    TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "closesocket() failed [%d]", WSAGetLastError() );
    return False;
  }
  o->connected = False;
  o->sh = 0;
  TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "socket closed." );

  if( o->ssl ) {
    #ifdef __OPENSSL__
    /* Clean up. */
    if( o->ssl_sh ) {
      SSL_free( o->ssl_sh );
      o->ssl_sh = NULL;
    }
    if( o->ssl_ctx ) {
      SSL_CTX_free( o->ssl_ctx );
      o->ssl_ctx = NULL;
    }
    #endif
  }

#endif
  return True;
}


/*
 ***** _Public functions.
 */
/* OS dependent */
Boolean rocs_socket_setBlocking( iOSocket inst, Boolean blocking ) {
#ifdef __ROCS_SOCKET__
  iOSocketData o = Data(inst);
  unsigned long args = blocking?0:1;
  int rc   = 0;
  /* set/clear non-blocking i/o */
  rc = ioctlsocket( o->sh, FIONBIO, &args );
#endif
  return True;
}

/* OS dependent */
Boolean rocs_socket_setSndTimeout( iOSocket inst, int timeout ) {
#ifdef __ROCS_SOCKET__
  iOSocketData o = Data(inst);
  int rc   = 0;
  struct timeval tv;
  int size = sizeof tv;
  tv.tv_sec  = (timeout * 1000); /* Windows needs timeout in mSeconds */
  tv.tv_usec = 0;
  rc = setsockopt( o->sh, SOL_SOCKET, SO_SNDTIMEO, (void*)&tv, size );
  o->rc = rc;
  if( rc != 0 ) {
    o->rc = WSAGetLastError();
    TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "rocs_socket_setSndTimeout() failed [%d]", WSAGetLastError() );
    return False;
  }
  TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "rocs_socket_setSndTimeout() OK." );
#endif
  return True;
}

Boolean rocs_socket_setRcvTimeout( iOSocket inst, int timeout ) {
#ifdef __ROCS_SOCKET__
  iOSocketData o = Data(inst);
  int rc   = 0;
  struct timeval tv;
  int size = sizeof tv;
  tv.tv_sec  = (timeout * 1000); /* Windows needs timeout in mSeconds */
  tv.tv_usec = 0;
  rc = setsockopt( o->sh, SOL_SOCKET, SO_RCVTIMEO, (void*)&tv, size );
  o->rc = rc;

  if( rc != 0 ) {
    o->rc = WSAGetLastError();
    TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "rocs_socket_setRcvTimeout() failed [%d]", WSAGetLastError() );
    return False;
  }
  TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "rocs_socket_setRcvTimeout() OK." );
#endif
  return True;
}


/* OS dependent */
Boolean rocs_socket_connect( iOSocket inst ) {
#ifdef __ROCS_SOCKET__
  iOSocketData o = Data(inst);
  struct sockaddr_in srvaddr;
  struct in_addr* addr = o->hostaddr;
  int rc = 0;

  if( o->sh == 0 )
    rocs_socket_create( o );

  if( o->sh == 0 )
    return False;

  if( !rocs_socket_resolveHost( o ) )
    return False;

  addr = o->hostaddr;

  memset( &srvaddr,0, sizeof( struct sockaddr_in ) );
  srvaddr.sin_family = AF_INET;
  srvaddr.sin_port   = htons( (u_short)o->port );
  srvaddr.sin_addr   = *addr;

  rc = connect( o->sh, (struct sockaddr *)&srvaddr, sizeof( struct sockaddr_in ) );

  if( rc == -1 ) {
    o->rc = WSAGetLastError();
    TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "connect(%s:%d) failed [%d]",
                                                 o->host, o->port , WSAGetLastError() );
    o->connected = False;
    return False;
  }
  o->connected = True;
  TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "socket connected." );

  if( o->ssl ) {
    #ifdef __OPENSSL__
    SSL_METHOD* meth;
    X509*       server_cert;

    o->openssl_support = True;

    SSLeay_add_ssl_algorithms();
    meth = SSLv3_client_method();
    SSL_load_error_strings();
    o->ssl_ctx = SSL_CTX_new (meth);

    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "OpenSSL support.(v%d)", meth->version );

    o->ssl_sh = SSL_new( o->ssl_ctx );
    if( o->ssl_sh != NULL ) {
      SSL_set_fd( o->ssl_sh, o->sh );
      rc = SSL_connect( o->ssl_sh );
      if( rc <= 0 ) {
        char err[256] = {'\0'};
        rc = ERR_peek_error();
        ERR_error_string_n( (unsigned long) rc, err, sizeof(err) );

        TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "SSL_connect() failed [%d] %s", rc, err );
        o->connected = False;
        o->openssl_support = False;
        return False;
      }

      /* Trace some info. */
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "SSL connection using %s", SSL_get_cipher( o->ssl_sh ) );

      server_cert = SSL_get_peer_certificate( o->ssl_sh );
      if( server_cert != NULL ) {
        char* sub = NULL;
        char* iss = NULL;

        sub = X509_NAME_oneline( X509_get_subject_name( server_cert ), 0, 0 );
        iss = X509_NAME_oneline( X509_get_issuer_name ( server_cert ), 0, 0 );

        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999,
          "SSL Server certificate subject = %s, issuer = %s", sub, iss );
        free( sub );
        free( iss );
      }

    }
    #else
    TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "SSL requested but not supported! Compile with __OPENSSL__ defined." );
    return False;
    #endif
  }

#endif
  return True;
}

/* OS dependent */
Boolean rocs_socket_bind( iOSocketData o ) {
#ifdef __ROCS_SOCKET__
  struct sockaddr_in srvaddr;
  struct in_addr* addr = o->hostaddr;
  int rc = 0;

  if( o->binded )
    return True;

  memset( &srvaddr,0, sizeof( struct sockaddr_in ) );
  srvaddr.sin_family = AF_INET;
  srvaddr.sin_port   = htons( (u_short)o->port );
  if( o->udp )
    srvaddr.sin_addr.s_addr = ADDR_ANY;
  else
    srvaddr.sin_addr = *addr;


  if( o->udp && o->multicast ) {
    int loop = 1;
    TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "allow all processes to use this port..." );
    setsockopt ( o->sh, SOL_SOCKET, SO_REUSEADDR, &loop, sizeof (loop));
  }

  rc = bind( o->sh, (struct sockaddr *)&srvaddr, sizeof( struct sockaddr_in ) );

  if( rc != -1 && o->udp && o->multicast ) {
    struct ip_mreq command;
    int loop = 1;
    TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "Allow broadcasting..." );
    rc = setsockopt ( o->sh, IPPROTO_IP, IP_MULTICAST_LOOP, (void*)&loop, sizeof (loop));
    if( rc == -1 ) {
      o->rc = errno;
      TraceOp.terrno( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, o->rc, "setsockopt() failed" );
      o->binded = False;
      return False;
    }

    /* Join the broadcast group: */
    TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "Join the broadcast group..." );
    command.imr_multiaddr.s_addr = inet_addr (o->host);
    command.imr_interface.s_addr = htonl (INADDR_ANY);

    if (command.imr_multiaddr.s_addr == -1) {
      TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "%s id no multicast address!", o->host );
      o->binded = False;
      return False;
    }

    rc = setsockopt ( o->sh, IPPROTO_IP, IP_ADD_MEMBERSHIP, (void*)&command, sizeof (command));
    if( rc == -1 ) {
      o->rc = errno;
      TraceOp.terrno( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, o->rc, "setsockopt() failed" );
      o->binded = False;
      return False;
    }
  }



  if( rc == -1 ) {
    o->rc = WSAGetLastError();
    TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "bind() failed [%d]", WSAGetLastError() );
    o->binded = False;
    return False;
  }
  TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "socket binded." );
  o->binded = True;
#endif
  return True;
}

/* OS dependent */
Boolean rocs_socket_listen( iOSocketData o ) {
#ifdef __ROCS_SOCKET__
  int rc = 0;

  if( o->listening )
    return True;

  rc = listen( o->sh, SOMAXCONN );

  if( rc != 0 ) {
    o->rc = WSAGetLastError();
    TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "listen() failed [%d]", WSAGetLastError() );
    o->listening = False;
    return False;
  }
  TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "socket listening." );
  o->listening = True;
#endif
  return True;
}

/* OS dependent */
Boolean rocs_socket_write( iOSocket inst, char* buf, int size ) {
#ifdef __ROCS_SOCKET__
  iOSocketData o = Data(inst);
  int written  = 0;
  int twritten = 0;
  int flags    = 0;
  int l_InvalidSocketHandle = 1;

  o->written = 0;

  while( size > 0 && twritten < size && !o->broken ) {

    if( o->ssl ) {
      #ifdef __OPENSSL__
      if (o->ssl_sh){
        l_InvalidSocketHandle = 0;
        written = SSL_write( o->ssl_sh, buf + twritten, size - twritten );
      }
      #endif
    }
    else{
      if (o->sh){
        l_InvalidSocketHandle = 0;
        written = send( o->sh, buf + twritten, size - twritten, flags );
      }
    }


    if( written == 0 ) {
      /**/
      TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "cannot write to socket errno=%d...", errno );
      rocs_socket_close(o);
      o->broken = True;
      return False;
    }
    else if( written < 0 || l_InvalidSocketHandle ) {
      if( WSAGetLastError() == WSAEWOULDBLOCK ) {
        ThreadOp.sleep(10);
        continue;
      }
      o->rc = WSAGetLastError();

      rocs_socket_close(o);

      if( o->ssl ) {
      #ifdef __OPENSSL__
        ERR_print_errors_fp( (FILE*)TraceOp.getF(NULL) );
        fflush( (FILE*)TraceOp.getF(NULL) );
      #endif
      }

      TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "send() failed [%d]", o->rc );
      o->broken = True;
      return False;
    }
    twritten += written;
  }
  o->written = twritten;
  TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "%d bytes written to socket.", twritten );
#endif
  return True;
}

/* OS dependent */
Boolean rocs_socket_readpeek( iOSocket inst, char* buf, int size, Boolean peek ) {
#ifdef __ROCS_SOCKET__
  iOSocketData o = Data(inst);
  int readed   = 0;
  int treaded  = 0;
  int flags    = peek ? MSG_PEEK:0;

  o->readed = 0;

  while( treaded < size ) {

    if( o->ssl ) {
      #ifdef __OPENSSL__
      if( peek )
        readed = SSL_peek( o->ssl_sh, buf + treaded, size - treaded );
      else
      readed = SSL_read( o->ssl_sh, buf + treaded, size - treaded );
      #endif
    }
    else
      readed = recv( o->sh, buf + treaded, size - treaded, flags );

    /* Has otherside closed the connection? */
    if( readed == 0 ) {
      o->rc = errno;
      o->broken = True;
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "Other side has closed connection." );
      TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "errno=%d, read=%d", errno, readed );
      return False;
    }

    if( peek ) {
      o->rc = WSAGetLastError();
      o->peeked = readed;
      if( readed == -1 && o->rc != 0 && o->rc != WSAETIMEDOUT && o->rc != WSAEINTR && o->rc != WSAEWOULDBLOCK ) {
        if( o->ssl ) {
        #ifdef __OPENSSL__
          ERR_print_errors_fp( (FILE*)TraceOp.getF(NULL) );
          fflush( (FILE*)TraceOp.getF(NULL) );
        #endif
        }

        TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "*broken* errno=%d, rc=%d, readed=%d", errno, o->rc, readed );
        o->broken = True;
      }
        /* WinSock problems: http://sources.redhat.com/ml/cygwin/2001-08/msg00628.html
         * MSG_PEEK always returns 1 with Windows NT & 2000; XP returns correct number. */
                                /* return (readed >= size) ? True:False; */
      return (readed >= 1) ? True:False;
    }

    if( readed < 0 )
    {
      o->rc = WSAGetLastError();
      /* For none blocking...
      if( !o->blocking && o->rc == WSAEWOULDBLOCK ) {
        ThreadOp.sleep(10);
        continue;
      }
      */
      if( o->rc != WSAETIMEDOUT ) {
        if( o->rc == WSAEWOULDBLOCK || o->rc == WSAESHUTDOWN || o->rc == WSAENOTSOCK || o->rc == WSAECONNRESET )
          rocs_socket_close(o);
      }

      if( o->ssl ) {
      #ifdef __OPENSSL__
        ERR_print_errors_fp( (FILE*)TraceOp.getF(NULL) );
        fflush( (FILE*)TraceOp.getF(NULL) );
      #endif
      }

      TraceOp.trc( name, o->rc == WSAETIMEDOUT ? TRCLEVEL_DEBUG:TRCLEVEL_EXCEPTION, __LINE__, 9999, "recv() failed [%d] size=%d readed=%d", o->rc, size, treaded );

      return False;
    }
    treaded += readed;
  }
  o->readed = treaded;
  if( treaded > 1 )
    TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "%d bytes read from socket.", treaded );
#endif
  return True;
}

Boolean rocs_socket_read( iOSocket inst, char* buf, int size ) {
  return rocs_socket_readpeek( inst, buf, size, False );
}
Boolean rocs_socket_peek( iOSocket inst, char* buf, int size ) {
  return rocs_socket_readpeek( inst, buf, size, True );
}


int rocs_socket_recvfrom( iOSocket inst, char* buf, int size, char* client, int* port ) {
  iOSocketData o = Data(inst);
  int rc = 0;
  SOCKADDR_IN remoteAddr;
  int     remoteAddrLen;
  remoteAddrLen=sizeof(SOCKADDR_IN);

  if( buf == NULL ) {
    char l_buf[256];
    size = 256;
    rc = recvfrom( o->sh, l_buf, size, MSG_PEEK, (SOCKADDR*)&remoteAddr, &remoteAddrLen );
  }
  else
    rc = recvfrom( o->sh, buf, size, 0, (SOCKADDR*)&remoteAddr, &remoteAddrLen );

  if(rc==SOCKET_ERROR)
  {
    o->rc = WSAGetLastError();
    TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "recvfrom() failed[%d]", o->rc );
    return 0;
  }
  if( client != NULL && port != NULL ) {
    StrOp.copy( client, inet_ntoa(remoteAddr.sin_addr));
    *port = ntohs(remoteAddr.sin_port);
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "%d bytes readed from %s:%d", rc, client, *port );
  }
  return rc;
}



Boolean rocs_socket_sendto( iOSocket inst, char* buf, int size, char* client, int port ) {
  iOSocketData o = Data(inst);
  int rc = 0;
  struct in_addr* addr = o->hostaddr;
  SOCKADDR_IN address;

  if( !__resolveHost( o, client == NULL ? o->host:client ) )
    return False;

  addr = o->hostaddr;

  memset (&address, 0, sizeof (address));
  address.sin_family = AF_INET;
  /*address.sin_addr.s_addr = inet_addr (client == NULL ? o->host:client);*/
  address.sin_addr   = *addr;
  address.sin_port = htons (port > 0 ? port:o->port);

  o->rc = 0;
  rc = sendto( o->sh, buf, size, 0, (SOCKADDR*)&address, sizeof(SOCKADDR_IN) );
  if( rc == SOCKET_ERROR) {
    o->rc = WSAGetLastError();
    TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "sendto() failed[%d]", o->rc );
    return False;
  }
  return True;
}



int rocs_socket_accept( iOSocket inst ) {
  int sh = 0;
#ifdef __ROCS_SOCKET__
  iOSocketData o = Data(inst);
  struct sockaddr_in clntaddr;
  int len = sizeof( struct sockaddr_in );

  rocs_socket_bind( o );
  rocs_socket_listen( o );

  if( !o->binded || !o->listening ) {
    TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "server socket not ready." );
    return -1;
  }

  sh = accept( o->sh, (struct sockaddr *)&clntaddr, &len );

  if( sh < 0 ) {
    o->rc = WSAGetLastError();
    TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "accept() failed [%d]", WSAGetLastError() );
  }

#endif
  return sh;
}

char* rocs_socket_getPeername(iOSocket inst) {
  char* lp = NULL;
#ifdef __ROCS_SOCKET__
  iOSocketData o = Data(inst);
  struct sockaddr_in sin;
  /*struct hostent* hp;*/
  int len = sizeof( sin );
  int rc = getpeername( o->sh, (struct sockaddr *)&sin, & len );
  if( rc < 0 ) {
    o->rc = WSAGetLastError();
    TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "getsockpeer() failed [%d]", WSAGetLastError() );
    return "";
  }
/*  if( hp = gethostbyaddr( (char *)&sin.sin_addr.s_addr, sizeof(sin.sin_addr.s_addr), AF_INET) )
    lp = hp->h_name;
  else*/
    lp = inet_ntoa( sin.sin_addr );
  TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "getsockpeer() :%s", lp );
#endif
  return lp;
}

Boolean rocs_socket_setKeepalive( iOSocket inst, Boolean alive ) {
#ifdef __ROCS_SOCKET__
  iOSocketData o = Data(inst);
  int rc   = 0;
  int size = sizeof( alive );
  rc = setsockopt( o->sh, SOL_SOCKET, SO_KEEPALIVE, (void*)&alive, size );

  if( rc != 0 ) {
    o->rc = WSAGetLastError();
    TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "rocs_socket_setKeepalive() failed [%d]", WSAGetLastError() );
    return False;
  }
  TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "rocs_socket_setKeepalive() OK." );
#endif
  return True;
}


Boolean rocs_socket_setBroadcast( iOSocket inst, Boolean broadcast ) {
#ifdef __ROCS_SOCKET__
  iOSocketData o = Data(inst);
  int rc   = 0;
  int size = sizeof( broadcast );
  rc = setsockopt( o->sh, SOL_SOCKET, SO_BROADCAST, (void*)&broadcast, size );

  if( rc != 0 ) {
    o->rc = WSAGetLastError();
    TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "rocs_socket_setBroadcast() failed [%d]", WSAGetLastError() );
    return False;
  }
  TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "rocs_socket_setBroadcast() OK." );
#endif
  return True;
}


Boolean rocs_socket_setNodelay( iOSocket inst, Boolean flag ) {
#ifdef __ROCS_SOCKET__
  iOSocketData o = Data(inst);
  int rc   = 0;
  int size = sizeof( flag );
  rc = setsockopt( o->sh, IPPROTO_TCP, TCP_NODELAY, (void*)&flag, size );

  if( rc != 0 ) {
    o->rc = WSAGetLastError();
    TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "rocs_socket_setKeepalive() failed [%d]", WSAGetLastError() );
    return False;
  }
  TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "rocs_socket_setKeepalive() OK." );
#endif
  return True;
}


Boolean rocs_socket_CreateCTX( iOSocket inst ) {
#ifdef __OPENSSL__
  iOSocketData o = Data(inst);
  /* The method describes which SSL protocol we will be using. */
  SSL_METHOD *method;

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "SSL_library_init()..." );
  SSL_library_init();
  /* Load algorithms and error strings. */
  OpenSSL_add_all_algorithms();
  SSL_load_error_strings();

  /* Compatible with SSLv2, SSLv3 and TLSv1 */
  method = SSLv23_server_method();

  /* Create new context from method. */
  o->ssl_ctx = SSL_CTX_new( method );
  if( o->ssl_ctx == NULL ) {
    ERR_print_errors_fp( stderr );
    return False;
  }
  return True;
#else
  return False;
#endif
}

/* Load the certification files, ie the public and private keys. */
Boolean rocs_socket_LoadCerts( iOSocket inst, const char *cFile, const char *kFile ) {
#ifdef __OPENSSL__
  iOSocketData o = Data(inst);

  if ( SSL_CTX_use_certificate_chain_file( o->ssl_ctx, cFile ) <= 0) {
    ERR_print_errors_fp(stderr);
    return False;
  }
  if ( SSL_CTX_use_PrivateKey_file( o->ssl_ctx, kFile, SSL_FILETYPE_PEM ) <= 0) {
    ERR_print_errors_fp(stderr);
    return False;
  }

  /* Verify that the two keys goto together. */
  if ( !SSL_CTX_check_private_key( o->ssl_ctx ) ) {
    fprintf(stderr, "Private key is invalid.\n");
    return False;
  }

  return True;
#else
  return False;
#endif
}

const char* rocs_socket_getsockname(iOSocket inst) {
  iOSocketData data = Data(inst);
  /*
  struct sockaddr_in sa;
  int sa_len;
  sa_len = sizeof(sa);
  if (getsockname(data->sh, (struct sockaddr*)&sa, &sa_len) != -1) {
    return inet_ntoa(sa.sin_addr);
  }
  */
  return "";
}

static char __hostname[256];
const char* rocs_socket_gethostaddr( void ) {
  struct hostent *he;
  struct in_addr a;
  int i = 0;

  gethostname( __hostname, sizeof( __hostname ) );
  he = gethostbyname (__hostname);
  while( he!=NULL && he->h_addr_list[i] != NULL ) {
    const char* s = inet_ntoa (*(struct in_addr *)he->h_addr_list[i]);
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "address %d = %s", i, s );
    i++;
    if( !StrOp.equals( "127.0.1.1", s ) )
      return s;
  }
  return __hostname;
}


#endif
