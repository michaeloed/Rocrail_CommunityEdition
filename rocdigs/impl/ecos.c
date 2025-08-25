/*
 Rocrail - Model Railroad Software

 Copyright (C) 2002-2014 Rob Versluis, Rocrail.net

 


 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 2
 of the License, or (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/

/** ------------------------------------------------------------
  * Module: RocDigs
  * Object: ECoS
  * ------------------------------------------------------------
  *
  * This code defines the ECoS psuedo-object.  It provides the low-level interface between an ECoS Commander and
  * Rocrail.

When the object is first instantiated, it will attempt to connect to the ECoS, and [do what?].

If it can connect, it will begin listening for messages from the ECoS in a separate thread running the
__reader routine.  That routine passes any incoming messages to __processReply.

The heart of the routine is the _cmd routine, which first calls _translate to convert a Rocrail
command into an ECoS command string, and then _transact to send that command to the ECoS.

ECoS Keywords:
  add
  addr
  addrext
  append
  consist
  control
  create
  cv
  del
  delay
  delete
  dir
  discard
  duration
  favorit
  force
  func
  funcsymbol
  get
  go
  info
  id
  link
  mode
  name
  name1
  name2
  name3
  nr
  ports
  profile
  protocol
  queryObjects
  release
  request
  route
  set
  size
  sniffer
  speed
  speedindicator
  speedstep
  state
  status
  station
  stop
  switch
  symbol
  unlink
  view

  END
  EVENT
  NERROR_NOAPPEND
  NERROR_NOCONTROL
  NERROR_OK
  OK
  REPLY

  *
  *
  *
  * Methods
  * =======
  *
  * __del -- Frees the memory used by the ECoS object
  * __name -- Returns name property
  * __serialize -- Not implemented yet
  * __deserialize -- Not implemented yet
  * __toString -- Not implemented yet
  * __clone -- Not implemented yet
  * __equals -- Not implemented yet
  * __properties -- Not implemented yet
  * __transact -- sends commands to the ECoS.
  * __checkObject -- Takes in a wSysCmd node and either calls the ECoS to create the object,
  * __requestViews -- get views for ECoS system and S88 bus
  * __releaseViews -- Releases the views for the ECoS and the S88 bus
  * __connect -- Establishes a connection to the ECoS
  * __translate -- Translates an incoming command into the ECoS protocol.
  * __cmd -- Main entry point, attempts to pass an incoming command to the ECoS
  * _halt -- Called when Rocrail is shutting down?
  * _setListener -- Hooks a listener object and function into the ECoS data object
  * _state -- Not implemented yet
  * _supportPT -- Not implemented yet
  * _version -- Returns the current version for the ECoS object
  * __initrun -- Start the connecting thread for this object
  * __processLocList -- Takes an incoming list of locs and puts them into
  * __processLocCreate -- Adds a newly created loc into the data object
  * __processS88Events -- Dispatches S88 trigger events to the listener function
  * __processReply -- Handles incoming messages from the ECoS
  * __reader -- Reads messages coming in from the ECoS
  * _inst -- Constructor for an ECoS object.
  * rocGetDigInt -- calls the _inst routine and returns its handle
  *
  *
  * Properties
  * ==========
  *
  * OID_ECOS       = 1;       -- ECoS system manamger
  * OID_LCMANAGER  = 10;      -- Lok Manager
  * OID_SWMANAGER  = 11;      -- Turnout Manager
  * OID_S88MANAGER = 26;      -- S88 Feedback Manager
  *
  * Missing Managers:
  *   Basisobject Programmiergleis -- 5 (not in 1st version)
  *   Basisobjekt Pendelzugsteuerung -- 12 (not in 1st version)
  *     (Basis object pendulum course price increase)
  *   Basisobjekt Device Manager -- 20 (not in 1st version)
  *   ListenObjekt Sniffer -- 25
  *   Listenobjekt Booster -- 27 (not in 1st version)
  *   Basisobjeckt Stellpult -- 31 (not in 1st version)
  *
  *   Listenobjekt Pendulzugstrecke -- dynamic ID
  *   Listenobjekt S88Module -- dynamic ID
  *   Listenobjekt Schaltartikel -- dynamic ID
  *
  * instCnt = 0;  -- Number of active ECoS objects
  *
  * vmajor = 1;
  * vminor = 1;
  * patch  = 0;
  *
  * OECoS
  * OECoSData
  *
  */

#include <string.h>
#include <ctype.h>

#include "rocdigs/impl/ecos_impl.h"

#include "rocs/public/mem.h"
#include "rocs/public/strtok.h"

#include "rocrail/wrapper/public/DigInt.h"
#include "rocrail/wrapper/public/SysCmd.h"
#include "rocrail/wrapper/public/FunCmd.h"
#include "rocrail/wrapper/public/Loc.h"
#include "rocrail/wrapper/public/Switch.h"
#include "rocrail/wrapper/public/Signal.h"
#include "rocrail/wrapper/public/Feedback.h"
#include "rocrail/wrapper/public/Response.h"
#include "rocrail/wrapper/public/Program.h"
#include "rocrail/wrapper/public/Output.h"
#include "rocrail/wrapper/public/Item.h"
#include "rocrail/wrapper/public/State.h"
#include "rocrail/wrapper/public/FbMods.h"
#include "rocrail/wrapper/public/FbInfo.h"

#include "rocdigs/impl/ecos/ecos-parser.h"

  /* ECoS Basic Object ID's: */

static const int OID_ECOS            = 1;
static const int OID_LCMANAGER       = 10;
static const int OID_SWMANAGER       = 11;
static const int OID_SNIFFER         = 25;
static const int OID_S88MANAGER      = 26;
static const int OID_S88_ALL_MODULES = 100;
static const int OID_ECoSDetectors   = 200;

static int instCnt = 0;


static const int PORTSPERCHAR   = 4;     /* Each character = 4 ports */
static const int CHARSPERMODULE = 4;     /* Each module has 4 characters */
static const int S88BUFLEN      = 64;    /* Maximum number of sensors under ECoS is 32 * 16, sb 128 */


  /** -----

    OBase functions
    These command functions are public, and all Rocrail objects have them

  ----- */

  /* Destructor? */

static const char* __id( void* inst ) {
  return NULL;
}

static void* __event( void* inst, const void* evt ) {
  return NULL;
}

/**
 * __del -- Frees the memory used by the ECoS object
 *
 */
static void __del( void* inst ) {
  if ( inst != NULL ) {
    iOECoSData data = Data( inst );

      /* Cleanup data->xxx members...*/

    freeMem( data );
    freeMem( inst );
    instCnt--;
  }

  return;
}


/**
 * __name -- Returns name property
 *
 */
static const char* __name( void ) {
  return name;
}


/**
 * __serialize -- Not implemented yet
 *
 */
static unsigned char* __serialize( void* inst, long* size ) {
  return NULL;
}


/**
 * __deserialize -- Not implemented yet
 *
 */
static void __deserialize( void* inst,unsigned char* bytestream ) {
  return;
}


/**
 * __toString -- Not implemented yet
 *
 */
static char* __toString( void* inst ) {
  return NULL;
}


/**
 * __toString -- Returns number of ECoS object instances
 *
 */
static int __count( void ) {
  return instCnt;
}


/**
 * __clone -- Not implemented yet
 *
 */
static struct OBase* __clone( void* inst ) {
  return NULL;
}


/**
 * __equals -- Not implemented yet
 *
 */
static Boolean __equals( void* inst1, void* inst2 ) {
  return False;
}


/**
 * __properties -- Not implemented yet
 *
 */
static void* __properties( void* inst ) {
  return NULL;
}


  /** -----

    OECoS

    Private functions.  These are specific to the OECoS object.

  ----- */


/*
 * __inits88 -- Initialize the olds88 buffer to all 0's
 */
static void __inits88( iOECoS inst, int nummodules ) {
  iOECoSData data = Data(inst);

  if ( nummodules < 1 ) {
    TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "ERROR: Invalid number of modules [%d]", nummodules );
  } else {
    int i;
    for ( i = 0; i < S88BUFLEN; i++ ) {
      data->olds88[ i ] = 0;
    }
  }
}


/*
 * __hexchartoint -- Takes an incoming hexidecimal character and translates it to an int value.
 * Returns -1 if no translation possible.
 */
static int __hexchartoint( char hexdigit ) {
  int retval = -1;

  if ( isxdigit( hexdigit )) {
    char digitstr[ 2 ];
    digitstr[ 0 ] = hexdigit;
    digitstr[ 1 ] = '\0';
    retval  = strtol( digitstr, NULL, 16 );
  }

  if ( retval == -1 ) {
    TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "ERROR: Invalid character in hexchartoint [%d]", hexdigit );
  }

  return retval;
}


/*
 * __sends88Eventgroup -- sends ON and OFF events into the wFeedback nodes for Rocrail
 *
 */
static void __sends88Eventgroup( iOECoS inst, int news88, int olds88, int s88module ) {
  iOECoSData data = Data( inst );

  int port;
  int mask = 0x0001;
  for ( port = 0; port < 16; port++ ) {

    mask = 1 << port;

    TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999,
        "mask=0x%04X news88=0x%04X olds88=0x%04X", mask, news88 & mask, olds88 & mask );

    if( (news88 & mask) != (olds88 & mask) ) {
      int address = s88module * 16 + port + 1;
      Boolean state = news88 & mask ? True:False;

      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "s88 sensor event addr=%d state=%s", address, state?"on":"off" );

      /* inform listener: Node */
      iONode evt = NodeOp.inst( wFeedback.name(), NULL, ELEMENT_NODE );
      wFeedback.setaddr( evt, address );
      if ( data->iid != NULL )
        wFeedback.setiid( evt, data->iid );
      wFeedback.setstate( evt, state );
      data->listenerFun( data->listenerObj, evt, TRCLEVEL_MONITOR );

    }
  }

}



/**
 * __transact -- sends commands to the ECoS.
 *
 * Sends a command into the ECoS.  The reply will be caught by the other thread running the
 * __reader function.
 *
 */
static void __transact( iOECoS inst, const char* ecosCmd, int len ) {
  iOECoSData data = Data(inst);

  if( !data->enablecom ) {
    return;
  }

  if ( SocketOp.isConnected( data->socket )) {

    if ( MutexOp.trywait( data->writemux, 1000 )) {


      char  tracestr[ 2048 ]  = { 0 };

      strncpy( tracestr, ecosCmd, ( strlen( ecosCmd ) - 1 ));
      tracestr[ strlen( ecosCmd ) ] = '0';

      TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "sending ECoS command: %s", tracestr );
      SocketOp.write( data->socket, ecosCmd, len );

        /* Release the mutex. */

      MutexOp.post( data->writemux );
    } else {
      TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "WARNING: Cannot get mutex for thread" );
    }

  } else {
     TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "ERROR: Socket is not connected" );

  }
}


/**
 * __checkObject -- Takes in a wSysCmd node and either calls the ECoS to create the object,
 * or stores the command in the iOECoSData object.
 *
 * Returns an integer (oid).
 */
static int __checkObject( iOECoS inst, iONode node ) {

  iOECoSData data = Data( inst );

  const char* cmdstr  = wSysCmd.getcmd( node );
  const char* id      = wSysCmd.getid( node );
  const char* oid     = wSysCmd.getoid( node );
  int addr            = wSysCmd.getval( node );
  int decformat       = wSysCmd.getvalA( node );
  int speedsteps      = wSysCmd.getvalB( node );

  int manager         = OID_LCMANAGER;
  char buffer[ 1024 ] = { '\0' };

    /* FARKLE -- manager is not used, what was the idea?  To handle turnout commands? */

  if ( StrOp.equals( cmdstr, wSysCmd.swcnfg )) {
    manager = OID_SWMANAGER;
  }

    /* Create the object for this oid if it doesn't exist */

  if ( oid == NULL || StrOp.len( oid ) == 0 ) {
    MutexOp.wait( data->mapmux );
    oid = ( const char* )MapOp.get( data->locoNameToEcosOidMap, id );
    MutexOp.post( data->mapmux );

    if ( oid == NULL ) {

        /* create the object */
        /* create(10, addr[x], name["name"], protocol[DCC128], append) */

      StrOp.fmtb( buffer, "create(%d, addr[%d], name[\"%s\"], protocol[%s%d], append)\n",
                  OID_LCMANAGER, addr, id, decformat, speedsteps);

        /* Call the ECoS */

      __transact( inst, buffer, StrOp.len( buffer ));

        /*

          the reader updates the map async
          TODO: is sleep long enough?
          Can we sleep until a flag is set by the reader, or a timeout?

        */

      ThreadOp.sleep( 1000 );

      MutexOp.wait( data->mapmux );
      oid = ( const char* )MapOp.get( data->locoNameToEcosOidMap, id );
      MutexOp.post( data->mapmux );
    }

    /* Put this object into the Parent unless it already exists */

  }
  else {
    TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999,
                 "Check (Saving) id [%s,%s,%s] in map @ [%d]", id, oid, StrOp.dup( oid ), data->locoNameToEcosOidMap );

    MutexOp.wait( data->mapmux);
    if ( MapOp.get( data->locoNameToEcosOidMap, id) == NULL) {
      /* unknown oid for this name/id; put in maps */
      MapOp.put( data->locoNameToEcosOidMap, id, ( obj)StrOp.dup( oid));
      MapOp.put( data->ecosOidToLocoNameMap, oid, ( obj)StrOp.dup( id));
    }
    MutexOp.post( data->mapmux);

  }

  return atoi( oid );
}


/**
 * __requestViews -- get views for ECoS system and S88 bus
 *
 */
static void __requestViews( iOECoS inst ) {
  iOECoSData data = Data(inst);
  char ecosCmd[ 256 ] = {'\0'};

  /* ECoS */
  StrOp.fmtb( ecosCmd, "request(%d, view)\n", OID_ECOS );
  __transact( inst, ecosCmd, StrOp.len( ecosCmd ));

    /*

      S88Manager

      request(100, view)
      Note: must request 100 to get feedback events
      What is diff between 26 and 100?

    */

  StrOp.fmtb( ecosCmd, "request(%d, view)\n", OID_S88MANAGER );
  __transact( inst, ecosCmd, StrOp.len( ecosCmd ));

  __inits88( inst, S88BUFLEN );
  StrOp.fmtb( ecosCmd, "request(%d, view)\n", OID_S88_ALL_MODULES );
  __transact( inst, ecosCmd, StrOp.len( ecosCmd ));

  StrOp.fmtb( ecosCmd, "request(%d, view)\n", OID_ECoSDetectors );
  __transact( inst, ecosCmd, StrOp.len( ecosCmd ));

  /* loco manager */
  StrOp.fmtb( ecosCmd, "request(%d, view)\n", OID_LCMANAGER );
  __transact( inst, ecosCmd, StrOp.len( ecosCmd ));

  /* switch manager */
  memset( data->dccSwitchStates, 0, sizeof( data->dccSwitchStates));
  StrOp.fmtb( ecosCmd, "request(%d, view, viewswitch)\n", OID_SWMANAGER );
  __transact( inst, ecosCmd, StrOp.len( ecosCmd ));

/*
  StrOp.fmtb( ecosCmd, "request(%d, view)\n", OID_SNIFFER );
  __transact( inst, ecosCmd, StrOp.len( ecosCmd ));
*/


  StrOp.fmtb( ecosCmd, "get(%d, state)\n", OID_S88MANAGER );
  __transact( inst, ecosCmd, StrOp.len( ecosCmd ));
  StrOp.fmtb( ecosCmd, "get(%d, state)\n", OID_S88_ALL_MODULES );
  __transact( inst, ecosCmd, StrOp.len( ecosCmd ));
  StrOp.fmtb( ecosCmd, "get(%d, state)\n", OID_ECoSDetectors );
  __transact( inst, ecosCmd, StrOp.len( ecosCmd ));

}


/**
 * __releaseViews -- Releases the views for the ECoS and the S88 bus
 *
 */
static void __releaseViews( iOECoS inst ) {
  iOECoSData data     = Data( inst );
  char ecosCmd[ 256 ] = {'\0'};
/*
  StrOp.fmtb( ecosCmd, "release(%d, view)\n", OID_SNIFFER );
  __transact( inst, ecosCmd, StrOp.len( ecosCmd ));
*/

  /* release selective switch views */
  MutexOp.wait( data->mapmux );
  {
    const char *oid = ( const char *)MapOp.first( data->dccSwitchAddrToOidMap);
    while( oid != NULL ) {
      TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999,
                   "switch list drop oid [%s] from map @ [%d]", oid, data->dccSwitchAddrToOidMap);

      StrOp.fmtb( ecosCmd, "release(%d, view)\n", oid);
      __transact( inst, ecosCmd, StrOp.len( ecosCmd));
      oid = ( const char *)MapOp.next( data->dccSwitchAddrToOidMap);
    }
  }
  MutexOp.post( data->mapmux );

  /* switch manager */
  StrOp.fmtb( ecosCmd, "release(%d, view, viewswitch)\n", OID_SWMANAGER );
  __transact( inst, ecosCmd, StrOp.len( ecosCmd ));

  /* release selective loco views */
  MutexOp.wait( data->mapmux );
  {
    const char *oid = ( const char *)MapOp.first( data->locoNameToEcosOidMap);
    while( oid != NULL ) {
      TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999,
                   "loco list drop oid [%s] from map @ [%d]", oid, data->locoNameToEcosOidMap);

      StrOp.fmtb( ecosCmd, "release(%d, view)\n", oid);
      __transact( inst, ecosCmd, StrOp.len( ecosCmd));
      oid = ( const char *)MapOp.next( data->locoNameToEcosOidMap);
    }
  }
  MutexOp.post( data->mapmux );

  /* release loco manager view */
  StrOp.fmtb( ecosCmd, "release(%d, view)\n", OID_LCMANAGER );
  __transact( inst, ecosCmd, StrOp.len( ecosCmd ));

    /* ECoS */

  StrOp.fmtb( ecosCmd, "release(%d, view)\n", OID_ECOS );
  __transact( inst, ecosCmd, StrOp.len( ecosCmd ));

    /* S88Manager */

  StrOp.fmtb( ecosCmd, "release(%d, view)\n", OID_S88MANAGER );
  __transact( inst, ecosCmd, StrOp.len( ecosCmd ));

  StrOp.fmtb( ecosCmd, "release(%d, view)\n", OID_S88_ALL_MODULES );
  __transact( inst, ecosCmd, StrOp.len( ecosCmd ));

  StrOp.fmtb( ecosCmd, "release(%d, view)\n", OID_ECoSDetectors );
  __transact( inst, ecosCmd, StrOp.len( ecosCmd ));

    /* FARKLE -- must release all locs??? */
}


/**
 * __connect -- Establishes a connection to the ECoS
 *
 * Returns True if successful, False otherwise.  If successful, will get
 * info and status from the ECoS
 *
 */
static Boolean __connect( iOECoS inst ) {
  iOECoSData data = Data(inst);

  if( !data->enablecom ) {
    return True;
  }

  /* Create a socket object: */
  if ( data->socket == NULL )
    data->socket = SocketOp.inst( data->host, data->port, False, False, False );

    /* Disconnect if connected */

  if ( SocketOp.isConnected( data->socket ))
    SocketOp.disConnect( data->socket );

  TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "Connecting to ECoS at %s:%d",
               data->host, data->port );

  if ( !SocketOp.connect( data->socket )) {
    TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "ERROR connecting to ECoS at %s:%d",
                 data->host, data->port );
    return False;
  }

  data->connected = True;

    /* request info and views of ecos: */

  char ecosCmd[ 256 ] = {'\0'};   /* command buffer */

    /* Get the info */

  StrOp.fmtb( ecosCmd, "get(%d, info)\n", OID_ECOS );
  __transact( inst, ecosCmd, StrOp.len(ecosCmd));

    /* Get the status */

  StrOp.fmtb( ecosCmd, "get(%d, status)\n", OID_ECOS );
  __transact( inst, ecosCmd, StrOp.len(ecosCmd));

    /* Get the views */

  __requestViews( inst );

    /* queryObjects: */

  StrOp.fmtb( ecosCmd, "queryObjects(%d, addr, name, protocol)\n", OID_LCMANAGER );
  __transact( inst, ecosCmd, StrOp.len(ecosCmd));

  StrOp.fmtb( ecosCmd, "queryObjects(%d, addr, protocol)\n", OID_SWMANAGER );
  __transact( inst, ecosCmd, StrOp.len(ecosCmd));

  return True;
}



/* fbmods is a comman separated address list of connected feedback modules. */
static void __updateFB( obj ecos, iONode fbInfo ) {
  iOECoSData data = Data(ecos);
  int cnt = NodeOp.getChildCnt( fbInfo );
  int i = 0;
  int n = 0;
  char ecosCmd[ 1024 ] = {'\0'};

  char* str = NodeOp.base.toString( fbInfo );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "updateFB\n%s", str );
  StrOp.free( str );

  for( i = 0; i < cnt; i++ ) {
    iONode fbmods = NodeOp.getChild( fbInfo, i );
    const char* mods = wFbMods.getmodules( fbmods );
    if( mods != NULL && StrOp.len( mods ) > 0 ) {
      iOStrTok tok = StrTokOp.inst( mods, ',' );
      int idx = 0;
      while( StrTokOp.hasMoreTokens( tok ) ) {
        int addr = atoi( StrTokOp.nextToken(tok) );
        if( addr >= 200 ) {
          TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "query 16 railcom states of module %d...", addr);
          for( n = 0; n < 16; n++ ) {
            StrOp.fmtb( ecosCmd, "get(%d, railcom[%d])\n", addr, n );
            __transact( (iOECoS)ecos, ecosCmd, StrOp.len(ecosCmd) );
            ThreadOp.sleep(10);
          }
          idx++;
        }
      };
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "updateFB count=%d", idx );
    }
  }

}



/**
 * __translate -- Translates an incoming command into the ECoS protocol.
 *
 * Returns the length of the command, and the translated command in ecosCmd.
 *
 */
static int __translate( obj inst, iONode node, char* ecosCmd ) {

  iOECoSData data   = Data( inst );
  const char* oname = NodeOp.getName( node );
  const char* oid   = wItem.getoid( node );
  const char* id    = wItem.getid( node );

  ecosCmd[ 0 ]  = '\0';

  TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "In __translate, oname = [%s]", oname );

  if( StrOp.equals( oname, wFbInfo.name() ) ) {
    __updateFB( inst, node );
  }

    /*

      Switch command.

    */

  else if ( StrOp.equals( oname, wSwitch.name())) {

    TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "ECoS switch command" );

      /* sample command: set(11, switch[MOT10r] */

    const char* protocol  = wSwitch.getprot( node );
    int module            = wSwitch.getaddr1( node );
    int port              = wSwitch.getport1( node );

      /* calculate address, modules have 4 ports each */

    int address = (( module - 1 ) * 4 ) + port;

    char direction  = 'g';      /* default to green/straight */
    if ( ( StrOp.equals( wSwitch.getcmd( node ), wSwitch.turnout ) && !wSwitch.issinglegate( node ))
      || ( wSwitch.issinglegate( node ) && wSwitch.getgate1( node ))) {
      direction = 'r';          /* red/thrown */
    }

    StrOp.fmtb( ecosCmd, "set(%d, switch[%s%d%c])\n",
                OID_SWMANAGER, ( protocol[ 0 ] == 'M' ? "MOT" : "DCC" ), address, direction );

    TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "switch command set(%d, switch[%s%d%c])",
                 OID_SWMANAGER, ( protocol[ 0 ] == 'M' ? "MOT" : "DCC" ), address, direction);
    /*

      Signal command.

    */

  } else if ( StrOp.equals( oname, wSignal.name()) ) {

   TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "ECoS signal command" );

   TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999,
       "Signal commands are no longer supported at this level." );

    /*

      Output command

    */

  } else if ( StrOp.equals( oname, wOutput.name()) ) {

    TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "ECoS output command" );


    const char* prot  = wOutput.getprot( node );
    int addr          = wOutput.getaddr( node );
    int port          = wOutput.getport( node );
    int gate          = wOutput.getgate( node );

    char dir = 'g';

    /*
    addr = ( addr - 1 ) * 4 + ( port - 1 );
    */
    addr = ( addr - 1 ) * 4 + port;

    /* Rocrail command gate    Ecos
               on      0       green on
               on      1       red on
               off     0       red on
               off     1       green on
    */
    if ( ( StrOp.equals( wOutput.getcmd( node ), wOutput.on ) && gate == 1) ||
           ( StrOp.equals( wOutput.getcmd( node ), wOutput.off ) && gate == 0) )
      dir = 'r'; /* thrown */

    StrOp.fmtb( ecosCmd, "set(%d, switch[%s%d%c])\n",
                OID_SWMANAGER, (prot[0]=='M'?"MOT":"DCC"), addr, dir );

    TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "output command set(%d, switch[%s%d%c])",
                 OID_SWMANAGER, ( prot[ 0 ] == 'M' ? "MOT" : "DCC" ), addr, dir);

    /*

      Loc command.

    */

  } else if ( StrOp.equals( oname, wLoc.name()) ) {

    TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "ECoS loc command" );

      /* Get loc id, and find corresponding ECoS id */

    id    = wLoc.getid( node );
    /* TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "wLoc.getid( node ) returns [%s]", id ); */

    char ecosid[ 64 ] = { '\0' };
    strcat( ecosid, "\"" );
    strcat( ecosid, id );
    strcat( ecosid, "\"" );
    TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "ecosid = [%s,%s]", id, ecosid );

    MutexOp.wait( data->mapmux );
    oid = ( const char* )MapOp.get( data->locoNameToEcosOidMap, ecosid );
    MutexOp.post( data->mapmux );

    /*
    TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "MapOp.get( data->locoNameToEcosOidMap, id ) returns [%s]", oid );
    TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "NodeOp.getStr( node, 'oid', NULL ) returns [%s]", oid );
    */

    if ( oid != NULL && StrOp.len( oid ) > 0 ) {
      int V       = 0;
      int step    = 127;              /* normed at 127 steps */
      Boolean dir = wLoc.isdir( node );

      if ( wLoc.getV( node ) != -1 ) {
        if ( StrOp.equals( wLoc.getV_mode( node ), wLoc.V_mode_percent ))
          V = ( wLoc.getV( node ) * step ) / 100;
        else if( wLoc.getV_max( node ) > 0 )
          V = ( wLoc.getV( node ) * step ) / wLoc.getV_max( node );
      }

        /* Request, Set dir/Speed, Set functions, Release */

      StrOp.fmtb( ecosCmd,
                  "request(%s, control, force)\nset(%s, dir[%d], speed[%d])\nset(%s, func[%d, %d])\nrelease(%s, control)\n",
                    oid,
                    oid, dir ? 0 : 1, V,
                    oid, 0, wLoc.isfn( node ) ? 1 : 0,
                    oid );

      TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "loco %s oid=%s V=%d dir=%s lights=%s", id, oid, V, dir?"fwd":"rev", wLoc.isfn( node )?"on":"off" );

    } else if ( oid == NULL ) {
      TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "no ecos oid found for [%s]", ecosid );
    } else if ( StrOp.len( oid ) <= 0 ) {
      TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "empty ecos oid found for [%s]", ecosid);
    }

    /*

      Loc function command.

    */

  } else if ( StrOp.equals( oname, wFunCmd.name())) {

    TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "ECoS loc function command" );

      /* set(oid,speed[])*/

    id  = wLoc.getid( node );
    char ecosid[ 64 ] = { '\0' };
    strcat( ecosid, "\"" );
    strcat( ecosid, id );
    strcat( ecosid, "\"" );

    MutexOp.wait( data->mapmux );
    oid = ( const char* )MapOp.get( data->locoNameToEcosOidMap, ecosid );
    MutexOp.post( data->mapmux );

    TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "id = [%s], oid = [%s]", id, oid );

    if ( oid != NULL && StrOp.len( oid ) > 0 ) {

      int i     = 0;
      int from  = 0;
      int to    = 28;
      int group = wFunCmd.getgroup( node );
      int fnchanged = wFunCmd.getfnchanged(node);

      int fn[ 28 ];

      fn[ 0 ] = ( int )wFunCmd.isf1( node );
      fn[ 1 ] = ( int )wFunCmd.isf2( node );
      fn[ 2 ] = ( int )wFunCmd.isf3( node );
      fn[ 3 ] = ( int )wFunCmd.isf4( node );
      fn[ 4 ] = ( int )wFunCmd.isf5( node );
      fn[ 5 ] = ( int )wFunCmd.isf6( node );
      fn[ 6 ] = ( int )wFunCmd.isf7( node );
      fn[ 7 ] = ( int )wFunCmd.isf8( node );
      fn[ 8 ] = ( int )wFunCmd.isf9( node );
      fn[ 9 ] = ( int )wFunCmd.isf10( node );
      fn[ 10] = ( int )wFunCmd.isf11( node );
      fn[ 11] = ( int )wFunCmd.isf12( node );
      fn[ 12] = ( int )wFunCmd.isf13( node );
      fn[ 13] = ( int )wFunCmd.isf14( node );
      fn[ 14] = ( int )wFunCmd.isf15( node );
      fn[ 15] = ( int )wFunCmd.isf16( node );
      fn[ 16] = ( int )wFunCmd.isf17( node );
      fn[ 17] = ( int )wFunCmd.isf18( node );
      fn[ 18] = ( int )wFunCmd.isf19( node );
      fn[ 19] = ( int )wFunCmd.isf20( node );
      fn[ 20] = ( int )wFunCmd.isf21( node );
      fn[ 21] = ( int )wFunCmd.isf22( node );
      fn[ 22] = ( int )wFunCmd.isf23( node );
      fn[ 23] = ( int )wFunCmd.isf24( node );
      fn[ 24] = ( int )wFunCmd.isf25( node );
      fn[ 25] = ( int )wFunCmd.isf26( node );
      fn[ 26] = ( int )wFunCmd.isf27( node );
      fn[ 27] = ( int )wFunCmd.isf28( node );

      StrOp.fmtb( ecosCmd + StrOp.len( ecosCmd ), "request(%s, control, force)\n", oid );

      if( fnchanged != -1 && fnchanged > 0 ) {
        StrOp.fmtb( ecosCmd + StrOp.len( ecosCmd ), "set(%s, func[%d, %d])\n", oid, fnchanged, fn[ fnchanged-1 ] );
      }
      else {
        if( group > 0 && group < 8 ) {
          from = ( group - 1 ) * 4;
          to   = ( group - 1 ) * 4 + 4;
        }
        for ( i = from; i < to; i++ ) {
          StrOp.fmtb( ecosCmd + StrOp.len( ecosCmd ), "set(%s, func[%d, %d])\n", oid, i + 1, fn[ i ] );
        }
      }

      TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "loco %s oid=%s function %d set to %d", id, oid, fnchanged, fn[fnchanged] );


      StrOp.fmtb( ecosCmd + StrOp.len( ecosCmd ), "release(%s, control)\n", oid );

      TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "Sending [%s]", ecosCmd );

    } else {
      TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "WARNING: Can't get oid for this command" );
   }

    /*

      System command.

    */

  } else if ( StrOp.equals( oname, wSysCmd.name())) {

    TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "ECoS system function command" );

    const char* cmdstr  = wSysCmd.getcmd( node );

    if ( StrOp.equals( cmdstr, wSysCmd.stop ) || StrOp.equals( cmdstr, wSysCmd.ebreak ) ) {

      StrOp.fmtb( ecosCmd, "set(%d, stop)\n", OID_ECOS );
      TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "Power OFF" );

    } else if ( StrOp.equals( cmdstr, wSysCmd.go )) {

      StrOp.fmtb( ecosCmd, "set(%d, go)\n", OID_ECOS );
      TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "Power ON" );

    } else if ( StrOp.equals( cmdstr, wSysCmd.loccnfg ) || StrOp.equals( cmdstr, wSysCmd.swcnfg )) {

      __checkObject( (iOECoS)inst, node );

    }
    else if( StrOp.equals( cmdstr, wSysCmd.enablecom ) ) {
      TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "%s: %s communication", data->iid, wSysCmd.getval(node) == 1 ? "enable":"disable" );
      data->enablecom = wSysCmd.getval(node) == 1 ? True:False;
    }

    /*

      Program command.

    */

  } else if ( StrOp.equals( oname, wProgram.name()) ) {
    TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "program command: UNDOCUMENTED" );
      /* Missing programming commands */

  }

  /* Sensor command. */
  else if( StrOp.equals( oname, wFeedback.name() ) ) {
    int addr = wFeedback.getaddr( node );
    Boolean state = wFeedback.isstate( node );

    if( wFeedback.isactivelow(node) )
      wFeedback.setstate( node, !state);

    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "simulate fb addr=%d state=%s", addr, state?"true":"false" );
    data->listenerFun( data->listenerObj, (iONode)NodeOp.base.clone( node ), TRCLEVEL_INFO );

  }



  else {
    TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "Unknown command [%s]", oname );
  }

    /* Return length of command created */

  return StrOp.len( ecosCmd );
}


/**
 * __cmd -- Main entry point, attempts to pass an incoming command to the ECoS
 *
 */
static iONode _cmd( obj inst, const iONode cmd ) {

  iOECoSData data = Data( inst );

    /* Make sure we have a valid connection */

  if ( !data->connected ) {
    TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "no ECoS connection" );
    if( cmd != NULL ) {
      if ( StrOp.equals( NodeOp.getName(cmd), wSysCmd.name())) {
        if( StrOp.equals( wSysCmd.getcmd(cmd), wSysCmd.enablecom ) ) {
          TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "%s: %s communication", data->iid, wSysCmd.getval(cmd) == 1 ? "enable":"disable" );
          data->enablecom = wSysCmd.getval(cmd) == 1 ? True:False;
        }
      }
      cmd->base.del(cmd);
    }
    return NULL;
  }
  else {
    TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "Connected to ECoS" );
  }

    /* Prepare and send the command */

  if ( cmd != NULL ) {

    char ecosCmd[ 1024 ] = {'\0'};
    int len = __translate( inst, cmd, ecosCmd );

    if ( len > 0 ) {
      __transact(( iOECoS )inst, ecosCmd, len );
    } else {
      TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "WARNING: __translate returns len [%d]", len );
    }

  } else {
   TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "WARNING: NULL cmd node" );
  }

  if( cmd != NULL )
    cmd->base.del(cmd);

  return NULL;
}


/**
 * _halt -- Called when Rocrail is shutting down?
 *
 */
static void _halt( obj inst, Boolean poweroff, Boolean shutdown ) {
  iOECoSData data = Data( inst );

  if( poweroff ) {
    char ecosCmd[ 1024 ] = {'\0'};
    StrOp.fmtb( ecosCmd, "set(%d, stop)\n", OID_ECOS );
    TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "Power OFF" );
    __transact(( iOECoS )inst, ecosCmd, StrOp.len(ecosCmd) );
  }
  if( shutdown ) {
    char ecosCmd[ 1024 ] = {'\0'};
    StrOp.fmtb( ecosCmd, "set(%d, shutdown)\n", OID_ECOS );
    TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "Shutdown" );
    __transact(( iOECoS )inst, ecosCmd, StrOp.len(ecosCmd) );
  }
  __releaseViews( ( iOECoS )inst );
  data->run = False;
  ThreadOp.sleep(500);
  return;
}


/**
 * _setListener -- Hooks a listener object and function into the ECoS data object
 *
 */
static Boolean _setListener( obj inst, obj listenerObj, const digint_listener listenerFun ) {
  iOECoSData data = Data( inst );
  TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "setListener()" );

  data->listenerObj = listenerObj;
  data->listenerFun = listenerFun;

  return True;
}


static Boolean _setRawListener(obj inst, obj listenerObj, const digint_rawlistener listenerFun ) {
  return True;
}

static byte* _cmdRaw( obj inst, const byte* cmd ) {
  return NULL;
}

/**
 * _state -- Not implemented yet
 *
 * bit0=power, bit1=programming, bit2=connection
 */
static int _state( obj inst ) {
  iOECoSData data = Data( inst );

  return 0;
}


/* external shortcut event */
static void _shortcut(obj inst) {
  iOECoSData data = Data( inst );
}


/**
 * _supportPT -- Not implemented yet
 *
 */
static Boolean _supportPT( obj inst ) {
  iOECoSData data = Data( inst );

  return False;
}


  /* VERSION: */

static int vmajor = 2;
static int vminor = 0;
static int patch  = 0;

/**
 * _version -- Returns the current version for the ECoS object
 *
 */
static int _version( obj inst ) {
  iOECoSData data = Data( inst );

  return vmajor * 10000 + vminor * 100 + patch;
}


/**
 * __initrun -- Start the temp. connection thread
 * loop until a connection is established; this is done in a separate thread
 * to avoid blocking the control object.
 *
 */
static void __initrun( void * threadinst )
{
  iOThread th     = ( iOThread )threadinst;
  iOECoS ecos     = ( iOECoS )ThreadOp.getParm( th );
  iOECoSData data = Data( ecos );

    /* Sleep until we are connected */

  while ( data->run && !__connect( ecos )) {
    ThreadOp.sleep( 1000 );
  };
}


/**
 * __processLocList -- Takes an incoming list of locs and puts them into
 * the data object.  Existing entries are overwritten if they are the same id
 *
 * Child nodes are named as the OID's.
 * Known attributes are: addr, name, protocol
 */
static void __processLocList( iOECoS inst, iONode node ) {
  iOECoSData data = Data( inst );
  char ecosCmd[ 256 ] = {'\0'};

  /* TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "Incoming node = [%s]", NodeOp.toEscString( node )); */

    /* process all child nodes */

  int childs  = NodeOp.getChildCnt( node );
  int i       = 0;

  for ( i = 0; i < childs; i++ ) {

      /* Get the node */

    iONode child  = NodeOp.getChild( node, i );
    /* TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "child[%d] = [\n%s]\n", i, NodeOp.toEscString( child )); */

      /* Save it into data */

    if ( child != NULL ) {
      const char* id    = NodeOp.getStr( child, "name", NULL );
      const char* addr  = NodeOp.getStr( child, "addr", NULL );
      const char* oid   = NodeOp.getName( child );

      TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "name = [%s]", id );
      TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "addr = [%s]", addr );
      TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "oid = [%s]", oid );

      if ( ( id != NULL) && ( oid != NULL)) {
        char* oldVal = NULL;

        /* existing id's are overwritten */

        TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999,
                     "mapping Rocrail id=[%s] with Ecos oid=[%s]", id, oid );

        MutexOp.wait( data->mapmux );
        oldVal = (char*)MapOp.get( data->locoNameToEcosOidMap, id );
        if ( oldVal != NULL ) {
          char *oldVal2 = (char*)MapOp.get( data->ecosOidToLocoNameMap, oldVal);
          MapOp.remove( data->locoNameToEcosOidMap, id);
          StrOp.free( oldVal);
          if ( oldVal2 != NULL ) {
              MapOp.remove( data->ecosOidToLocoNameMap, oldVal);
              StrOp.free( oldVal2);
          }
        }
        MapOp.put( data->locoNameToEcosOidMap, id, ( obj)StrOp.dup( oid));
        MapOp.put( data->ecosOidToLocoNameMap, oid, ( obj)StrOp.dup( id));
        MutexOp.post( data->mapmux );

        /* view loco */
        StrOp.fmtb( ecosCmd, "request(%s, view)\n", oid );
        __transact( inst, ecosCmd, StrOp.len( ecosCmd ));

      } else {
        TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "WARNING: NULL id in __processLocList", id );
      }
    }

  }

}


/**
 * __processLocCreate -- Adds a newly created loc into the data object
 *
 */
static void __processLocCreate( iOECoS inst, iONode node ) {
  iOECoSData data = Data( inst );

    /* Get the loc at 0 */

  iONode child    = NodeOp.getChild( node, 0 );
  const char* id  = NodeOp.getStr( node, "name", NULL );
  const char* oid = NodeOp.getStr(child, "id", NULL);

    /* Add it to the data object */

  if ( ( id != NULL) && ( oid != NULL )) {
    char* oldVal = NULL;

    /* existing id's are overwritten... */

    TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999,
                 "Create Saving id [%s,%s,%s] in map @ [%d]", id, oid, StrOp.dup( oid ), data->locoNameToEcosOidMap );

    MutexOp.wait( data->mapmux );
    oldVal = (char*)MapOp.get( data->locoNameToEcosOidMap, id );
    if ( oldVal != NULL ) {
      char *oldVal2 = (char*)MapOp.get( data->ecosOidToLocoNameMap, oldVal);
      MapOp.remove( data->locoNameToEcosOidMap, id);
      StrOp.free( oldVal);
      if ( oldVal2 != NULL ) {
          MapOp.remove( data->ecosOidToLocoNameMap, oldVal);
          StrOp.free( oldVal2);
      }
    }
    MapOp.put( data->locoNameToEcosOidMap, id, ( obj)StrOp.dup( oid));
    MapOp.put( data->ecosOidToLocoNameMap, oid, ( obj)StrOp.dup( id));
    MutexOp.post( data->mapmux );
  }
}


/**
 * __processSwitchList -- Takes an incoming list of locs and puts them into
 * the data object.  Existing entries are overwritten if they are the same id
 *
 * Child nodes are named as the OID's.
 * Known attributes are: addr
 */
static void __processSwitchList( iOECoS inst, iONode node ) {
  iOECoSData data = Data( inst );
  char ecosCmd[ 256 ] = {'\0'};

  /* TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "Incoming node = [%s]", NodeOp.toEscString( node )); */

    /* process all child nodes */

  int childs  = NodeOp.getChildCnt( node );
  int i       = 0;

  for ( i = 0; i < childs; i++ ) {

      /* Get the node */

    iONode child  = NodeOp.getChild( node, i );
    /* TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "child[%d] = [\n%s]\n", i, NodeOp.toEscString( child )); */

      /* Save it into data */

    if ( child != NULL ) {
      const char* oid      = NodeOp.getName( child );
      const char* addr     = NodeOp.getStr( child, "addr", NULL );
      const char* protocol = NodeOp.getStr( child, "protocol", NULL );

      TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "oid = [%s]", oid );
      TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "addr = [%s]", addr );
      TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "protocol = [%s]", protocol );

      if ( ( oid != NULL ) && ( addr != NULL) && StrOp.equals( "DCC", protocol )) {

          /*

            existing id's are overwritten...

          */

        TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999,
                      "Saving switch oid [%s] addr [%s,%s] in map @ [%d]", oid, addr, protocol, data->dccOidToSwitchAddrMap );
        MutexOp.wait( data->mapmux );
        MapOp.put( data->dccSwitchAddrToOidMap, addr, ( obj)StrOp.dup( oid));
        MapOp.put( data->dccOidToSwitchAddrMap, oid, ( obj)StrOp.dup( addr));
        MutexOp.post( data->mapmux );

        /* view switch */
        StrOp.fmtb( ecosCmd, "request(%s, view)\n", oid );
        __transact( inst, ecosCmd, StrOp.len( ecosCmd ));

      } else {
        if ( oid == NULL)
          TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "WARNING: NULL oid in __processSwitchList", oid );
      }
    }

  }

}


/**
 * __processSwitchSet
 *
 */
static void __processSwitchSet( iOECoS inst, iONode node ) {
  iOECoSData data = Data( inst );

  const char* switchStr      = NodeOp.getStr( node, "switch", NULL );
  int         switchAddress  = 0;
  char        switchPosition = 0;

  if ( switchStr != NULL) {

    TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "switchStr [%s]", switchStr );

    if ( ( StrOp.len( switchStr) >= 5) && StrOp.startsWith( switchStr, "DCC" )) {

      sscanf( &switchStr[3], "%d", &switchAddress );
      switchPosition = switchStr[StrOp.len( switchStr) - 1];

      TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "switchAddress [%d,%c]", switchAddress, switchPosition );

      if ( switchAddress && ( switchAddress <= 2048) && ( ( switchPosition == 'g') || ( switchPosition == 'r'))) {

        /* set switch requests */
        if ( switchPosition == 'r') {
           data->dccSwitchStates[switchAddress-1] |= 0x01;
           data->dccSwitchStates[switchAddress-1] &= ~0x02;
        } else {
           data->dccSwitchStates[switchAddress-1] |= 0x02;
           data->dccSwitchStates[switchAddress-1] &= ~0x01;
        }

        /* clear event red, inform listener: Node */
        iONode eventRed = NodeOp.inst( wFeedback.name(), NULL, ELEMENT_NODE );
        wFeedback.setfbtype( eventRed, wFeedback.fbtype_railcom );
        wFeedback.setaddr( eventRed, switchAddress * 2 );
        if ( data->iid != NULL )
          wFeedback.setiid( eventRed, data->iid );
        wFeedback.setstate( eventRed, False );
        data->listenerFun( data->listenerObj, eventRed, TRCLEVEL_MONITOR );

        /* clear event green, inform listener: Node */
        iONode eventGreen = NodeOp.inst( wFeedback.name(), NULL, ELEMENT_NODE );
        wFeedback.setfbtype( eventGreen, wFeedback.fbtype_railcom );
        wFeedback.setaddr( eventGreen, ( switchAddress * 2 ) - 1);
        if ( data->iid != NULL )
          wFeedback.setiid( eventGreen, data->iid );
        wFeedback.setstate( eventGreen, False );
        data->listenerFun( data->listenerObj, eventGreen, TRCLEVEL_MONITOR );
      }
    }
  }
}


/**
 * __processSwitchManagerEvents
 *
 */
static void __processSwitchManagerEvents( iOECoS inst, iONode node ) {
  iOECoSData data = Data( inst );

  int cnt = NodeOp.getChildCnt( node);
  int idx = 0;

  TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "event has %d objects", cnt );

  for( idx = 0; idx < cnt; idx++ ) {

    iONode      child          = NodeOp.getChild( node, idx );
    const char* switchStr      = NodeOp.getStr( child, "switch", NULL );
    int         switchAddress  = 0;
    char        switchPosition = 0;

    if ( switchStr != NULL) {

      TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "switchStr [%s]", switchStr );

      if ( StrOp.len( switchStr) >= 5) {
        if ( StrOp.startsWith( switchStr, "DCC" )) {

          sscanf( &switchStr[3], "%d", &switchAddress );
          if ( switchStr[StrOp.len( switchStr) - 1] == '+')
            switchPosition = switchStr[StrOp.len( switchStr) - 2];
          else
            switchPosition = switchStr[StrOp.len( switchStr) - 1];

          TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "DCC switchAddress [%d,%c]", switchAddress, switchPosition );

          if ( switchAddress && ( switchAddress <= 2048) && ( ( switchPosition == 'g') || ( switchPosition == 'r'))) {
            /* set switch requests */
            if ( switchPosition == 'r') {
               data->dccSwitchStates[switchAddress-1] |= 0x01;
               data->dccSwitchStates[switchAddress-1] &= ~0x02;
            } else {
               data->dccSwitchStates[switchAddress-1] |= 0x02;
               data->dccSwitchStates[switchAddress-1] &= ~0x01;
            }

            /* clear event red, inform listener: Node */
            iONode eventRed = NodeOp.inst( wFeedback.name(), NULL, ELEMENT_NODE );
            wFeedback.setfbtype( eventRed, wFeedback.fbtype_railcom );
            wFeedback.setaddr( eventRed, switchAddress * 2 );
            if ( data->iid != NULL )
              wFeedback.setiid( eventRed, data->iid );
            wFeedback.setstate( eventRed, False );
            data->listenerFun( data->listenerObj, eventRed, TRCLEVEL_MONITOR );

            /* clear event green, inform listener: Node */
            iONode eventGreen = NodeOp.inst( wFeedback.name(), NULL, ELEMENT_NODE );
            wFeedback.setfbtype( eventGreen, wFeedback.fbtype_railcom );
            wFeedback.setaddr( eventGreen, ( switchAddress * 2 ) - 1);
            if ( data->iid != NULL )
              wFeedback.setiid( eventGreen, data->iid );
            wFeedback.setstate( eventGreen, False );
            data->listenerFun( data->listenerObj, eventGreen, TRCLEVEL_MONITOR );

            /* inform upper nodes */
            iONode nodeC = NodeOp.inst( wSwitch.name(), NULL, ELEMENT_NODE );
            if( data->iid != NULL )
              wSwitch.setiid( nodeC, data->iid );
            wSwitch.setprot( nodeC, wSwitch.prot_N);
            wSwitch.setaddr1( nodeC, ( ( ( ( switchAddress - 1) / 4) + 1)));
            wSwitch.setport1( nodeC, ( ( ( ( switchAddress - 1) % 4) + 1)));
            wSwitch.setstate( nodeC, ( switchPosition == 'g') ? "straight" : "turnout" );
            data->listenerFun( data->listenerObj, nodeC, TRCLEVEL_INFO );
          }
        } else if ( StrOp.startsWith( switchStr, "MOT" )) {

          sscanf( &switchStr[3], "%d", &switchAddress );
          if ( switchStr[StrOp.len( switchStr) - 1] == '+')
            switchPosition = switchStr[StrOp.len( switchStr) - 2];
          else
            switchPosition = switchStr[StrOp.len( switchStr) - 1];

          TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "MOT switchAddress [%d,%c]", switchAddress, switchPosition );

          if ( switchAddress && ( switchAddress < 320) && ( ( switchPosition == 'g') || ( switchPosition == 'r'))) {

            /* inform upper nodes */
            iONode nodeC = NodeOp.inst( wSwitch.name(), NULL, ELEMENT_NODE );
            if( data->iid != NULL )
              wSwitch.setiid( nodeC, data->iid );
            wSwitch.setprot( nodeC, wSwitch.prot_M);
            wSwitch.setaddr1( nodeC, ( ( ( ( switchAddress - 1) / 4) + 1)));
            wSwitch.setport1( nodeC, ( ( ( ( switchAddress - 1) % 4) + 1)));
            wSwitch.setstate( nodeC, ( switchPosition == 'g') ? "straight" : "turnout" );
            data->listenerFun( data->listenerObj, nodeC, TRCLEVEL_INFO );
          }
        }
      }
    }
  }
}


/**
 * __processLocoEvents
 *
 */
static void __processLocoEvents( iOECoS inst, iONode node ) {
  iOECoSData data = Data( inst );

  int cnt = NodeOp.getChildCnt( node);
  int idx = 0;

  TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "event has %d objects", cnt );

  for( idx = 0; idx < cnt; idx++ ) {

    iONode      child           = NodeOp.getChild( node, idx );
    const char* ecosLocoNameStr = ( const char *)MapOp.get( data->ecosOidToLocoNameMap, NodeOp.getName( child ));

    if ( ( ecosLocoNameStr != NULL ) && ( StrOp.len( ecosLocoNameStr) >= 2)) {
      char rrLocoNameStr[ 64 ] = { '\0' };
      const char* parameterStr;

      strcat( rrLocoNameStr, &ecosLocoNameStr[1]);
      rrLocoNameStr[StrOp.len( rrLocoNameStr)-1] = '\0';

      parameterStr = NodeOp.getStr( child, "speed", NULL );
      if ( parameterStr && ( StrOp.len( parameterStr) >= 1)) {
        int velocityVal = -1;

        sscanf( parameterStr, "%d", &velocityVal);

        if ( ( velocityVal != -1) && ( velocityVal <= 127)) {
          iONode nodeC = NULL;

          TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "velocity [%s,%s,%d]", ecosLocoNameStr, rrLocoNameStr, velocityVal);

          nodeC = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE);
          if( data->iid != NULL)
            wLoc.setiid( nodeC, data->iid);
          wLoc.setid( nodeC, rrLocoNameStr);
          wLoc.setV_raw( nodeC, velocityVal);
          wLoc.setV_rawMax( nodeC, 127);
          wLoc.setcmd( nodeC, wLoc.velocity);
          data->listenerFun( data->listenerObj, nodeC, TRCLEVEL_INFO);
        }
      }

      parameterStr = NodeOp.getStr( child, "dir", NULL );
      if ( parameterStr && ( StrOp.len( parameterStr) >= 1)) {
        int directionVal = -1;

        sscanf( parameterStr, "%d", &directionVal);

        if ( ( directionVal != -1) && ( directionVal <= 1)) {
          iONode nodeC = NULL;

          TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "direction [%s,%s,%d]", ecosLocoNameStr, rrLocoNameStr, directionVal);

          nodeC = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE);
          if( data->iid != NULL)
            wLoc.setiid( nodeC, data->iid);
          wLoc.setid( nodeC, rrLocoNameStr);
          wLoc.setdir( nodeC, ( directionVal ? False : True));
          wLoc.setcmd( nodeC, wLoc.direction);
          data->listenerFun( data->listenerObj, nodeC, TRCLEVEL_INFO);
        }
      }

      parameterStr = NodeOp.getStr( child, "func", NULL );
      if ( parameterStr && ( StrOp.len( parameterStr) >= 3)) {
        int functionNumber = -1;
        int functionVal    = -1;

        sscanf( parameterStr, "%d", &functionNumber);
        functionVal = parameterStr[StrOp.len( parameterStr) - 1] - '0';

        if ( ( functionNumber != -1) && ( functionNumber <= 28) && ( functionVal != -1) && ( functionVal <= 1)) {

          TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "function [%s,%s,%d]", ecosLocoNameStr, rrLocoNameStr, functionVal);

          if ( functionNumber == 0) {
            iONode nodeC = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE);
            if( data->iid != NULL)
              wLoc.setiid( nodeC, data->iid);
            wLoc.setid( nodeC, rrLocoNameStr);
            wLoc.setfn( nodeC, ( functionVal ? True : False));
            wLoc.setcmd( nodeC, wLoc.function);
            data->listenerFun( data->listenerObj, nodeC, TRCLEVEL_INFO);
          }

          iONode nodeD = NodeOp.inst( wFunCmd.name(), NULL, ELEMENT_NODE );
          if( data->iid != NULL )
            wLoc.setiid( nodeD, data->iid );
          wFunCmd.setid( nodeD, rrLocoNameStr);
          wFunCmd.setfnchanged( nodeD, functionNumber);
          switch ( functionNumber) {
            case 0 : wFunCmd.setf0( nodeD, ( functionVal ? True : False)); break;
            case 1 : wFunCmd.setf1( nodeD, ( functionVal ? True : False)); break;
            case 2 : wFunCmd.setf2( nodeD, ( functionVal ? True : False)); break;
            case 3 : wFunCmd.setf3( nodeD, ( functionVal ? True : False)); break;
            case 4 : wFunCmd.setf4( nodeD, ( functionVal ? True : False)); break;
            case 5 : wFunCmd.setf5( nodeD, ( functionVal ? True : False)); break;
            case 6 : wFunCmd.setf6( nodeD, ( functionVal ? True : False)); break;
            case 7 : wFunCmd.setf7( nodeD, ( functionVal ? True : False)); break;
            case 8 : wFunCmd.setf8( nodeD, ( functionVal ? True : False)); break;
            case 9 : wFunCmd.setf9( nodeD, ( functionVal ? True : False)); break;
            case 10 : wFunCmd.setf10( nodeD, ( functionVal ? True : False)); break;
            case 11 : wFunCmd.setf11( nodeD, ( functionVal ? True : False)); break;
            case 12 : wFunCmd.setf12( nodeD, ( functionVal ? True : False)); break;
            case 13 : wFunCmd.setf13( nodeD, ( functionVal ? True : False)); break;
            case 14 : wFunCmd.setf14( nodeD, ( functionVal ? True : False)); break;
            case 15 : wFunCmd.setf15( nodeD, ( functionVal ? True : False)); break;
            case 16 : wFunCmd.setf16( nodeD, ( functionVal ? True : False)); break;
            case 17 : wFunCmd.setf17( nodeD, ( functionVal ? True : False)); break;
            case 18 : wFunCmd.setf18( nodeD, ( functionVal ? True : False)); break;
            case 19 : wFunCmd.setf19( nodeD, ( functionVal ? True : False)); break;
            case 20 : wFunCmd.setf20( nodeD, ( functionVal ? True : False)); break;
            case 21 : wFunCmd.setf21( nodeD, ( functionVal ? True : False)); break;
            case 22 : wFunCmd.setf22( nodeD, ( functionVal ? True : False)); break;
            case 23 : wFunCmd.setf23( nodeD, ( functionVal ? True : False)); break;
            case 24 : wFunCmd.setf24( nodeD, ( functionVal ? True : False)); break;
            case 25 : wFunCmd.setf25( nodeD, ( functionVal ? True : False)); break;
            case 26 : wFunCmd.setf26( nodeD, ( functionVal ? True : False)); break;
            case 27 : wFunCmd.setf27( nodeD, ( functionVal ? True : False)); break;
            case 28 : wFunCmd.setf28( nodeD, ( functionVal ? True : False)); break;
          }
          data->listenerFun( data->listenerObj, nodeD, TRCLEVEL_INFO );
        }
      }
    }
  }
}


/**
 * __processSwitchEvents
 *
 */
static void __processSwitchEvents( iOECoS inst, iONode node ) {
  iOECoSData data = Data( inst );

  int cnt = NodeOp.getChildCnt( node);
  int idx = 0;

  TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "event has %d objects", cnt );

  for( idx = 0; idx < cnt; idx++ ) {

    iONode      child         = NodeOp.getChild( node, idx );
    const char* switchStr     = ( const char *)MapOp.get( data->dccOidToSwitchAddrMap, NodeOp.getName( child ));
    int         switchAddress = 0;
    const char* positionStr   = NodeOp.getStr( child, "position", NULL );
    int         positionOk    = 0;

    if ( ( switchStr != NULL ) && ( positionStr != NULL)) {

      sscanf( switchStr, "%d", &switchAddress );

      if ( switchAddress && ( switchAddress <= 2048 )) {

        if ( StrOp.equals( "wrong", positionStr ) || StrOp.equals( "ok", positionStr )) {

          positionOk = 0;
          if ( StrOp.equals( "ok", positionStr ))
            positionOk = 1;

          TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "switchAddress [%d,%d]", switchAddress, positionOk );

          if ( data->dccSwitchStates[switchAddress-1] & 0x03) {

            if ( positionOk) {

              /* event red, inform listener: Node */
              iONode eventRed = NodeOp.inst( wFeedback.name(), NULL, ELEMENT_NODE );
              wFeedback.setfbtype( eventRed, wFeedback.fbtype_railcom );
              wFeedback.setaddr( eventRed, switchAddress * 2 );
              if ( data->iid != NULL )
                wFeedback.setiid( eventRed, data->iid );
              wFeedback.setstate( eventRed, ( data->dccSwitchStates[switchAddress-1] & 0x01) ? True : False );
              data->listenerFun( data->listenerObj, eventRed, TRCLEVEL_MONITOR );

              /* event green, inform listener: Node */
              iONode eventGreen = NodeOp.inst( wFeedback.name(), NULL, ELEMENT_NODE );
              wFeedback.setfbtype( eventGreen, wFeedback.fbtype_railcom );
              wFeedback.setaddr( eventGreen, ( switchAddress * 2 ) - 1);
              if ( data->iid != NULL )
                wFeedback.setiid( eventGreen, data->iid );
              wFeedback.setstate( eventGreen, ( data->dccSwitchStates[switchAddress-1] & 0x02) ? True : False );
              data->listenerFun( data->listenerObj, eventGreen, TRCLEVEL_MONITOR );

              /* clear switch requests */
              data->dccSwitchStates[switchAddress-1] &= ~0x03;
            } else {

              /* clear event red, inform listener: Node */
              iONode eventRed = NodeOp.inst( wFeedback.name(), NULL, ELEMENT_NODE );
              wFeedback.setfbtype( eventRed, wFeedback.fbtype_railcom );
              wFeedback.setaddr( eventRed, switchAddress * 2 );
              if ( data->iid != NULL )
                wFeedback.setiid( eventRed, data->iid );
              wFeedback.setstate( eventRed, False );
              data->listenerFun( data->listenerObj, eventRed, TRCLEVEL_MONITOR );

              /* clear event green, inform listener: Node */
              iONode eventGreen = NodeOp.inst( wFeedback.name(), NULL, ELEMENT_NODE );
              wFeedback.setfbtype( eventGreen, wFeedback.fbtype_railcom );
              wFeedback.setaddr( eventGreen, ( switchAddress * 2 ) - 1);
              if ( data->iid != NULL )
                wFeedback.setiid( eventGreen, data->iid );
              wFeedback.setstate( eventGreen, False );
              data->listenerFun( data->listenerObj, eventGreen, TRCLEVEL_MONITOR );
            }
          }
        }
      }
    }
  }
}


/**
 * __processS88Events -- Dispatches S88 trigger events to the listener function
 *
 * # section 16
 * <EVENT 100>
 * 100 state[0x8000]
 * 101 state[0x0000]
 * <END 0 (OK)>
 *
 * <EVENT 200>
* 200 state[0x3]
* <END 0 (OK)>
*
* <EVENT 200>
* 200 railcom[00, 0324, 1]
* <END 0 (OK)>
 *
 */
static void __processS88Events( iOECoS inst, iONode node ) {
  iOECoSData data = Data( inst );

  int cnt = NodeOp.getChildCnt(node);
  int idx = 0;
  TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "event has %d objects", cnt );

  for( idx = 0; idx < cnt; idx++ ) {

    iONode child = NodeOp.getChild( node, idx );

    const char* statestring   = NodeOp.getStr( child, "state", NULL );
    const char* railcomstring = NodeOp.getStr( child, "railcom", NULL );

      /* Make sure we have a valid event string */

    if ( railcomstring != NULL ) {
      /* 00, 0324, 1 */
      int chanel = 0;
      int loco   = 0;
      int dir    = 0;
      char ident[32];
      /* getting the module number */
      const char* sIOD = NodeOp.getName(child);
      int module = atoi(sIOD);

      if( module >= 200 ) {
        int addr = 0;
        module = module - 200;
        TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "railcom module [%d]", module );

        iOStrTok tok = StrTokOp.inst(railcomstring, ',' );
        if( StrTokOp.hasMoreTokens( tok ) ) {
          const char* schanel = StrTokOp.nextToken( tok );
          chanel = (int)strtol( schanel, (char**)NULL, 10 );
        }
        if( StrTokOp.hasMoreTokens( tok ) ) {
          const char* sloco = StrTokOp.nextToken( tok );
          loco = (int)strtol( sloco, (char**)NULL, 10 );
        }
        if( StrTokOp.hasMoreTokens( tok ) ) {
          const char* sdir = StrTokOp.nextToken( tok );
          dir = (int)strtol( sdir, (char**)NULL, 10 );
        }
        StrTokOp.base.del(tok);

        addr = module * 16 + chanel + 1;
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "railcom sensor event addr=%d, loco=%d, dir=%s", addr, loco, dir?"fwd":"rev" );

        iONode nodeC = NodeOp.inst( wFeedback.name(), NULL, ELEMENT_NODE );

        wFeedback.setaddr( nodeC, addr );
        wFeedback.setfbtype( nodeC, wFeedback.fbtype_railcom );

        if( data->iid != NULL )
          wFeedback.setiid( nodeC, data->iid );

        wFeedback.setdirection( nodeC, dir == 1 ? True:False );

        wFeedback.setstate( nodeC, loco > 0 ? True:False );
        StrOp.fmtb(ident, "%d", loco);
        wFeedback.setidentifier( nodeC, ident);

        data->listenerFun( data->listenerObj, nodeC, TRCLEVEL_INFO );
      }
      else {
        module = 0;
        TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "Invalid railcom module ID: [%s]", sIOD );
      }

      continue;
    }

    if ( statestring == NULL ) {
      TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "Empty event string!" );
      continue;
    }

    char* lastdigit;
    long news88  = strtol( statestring, &lastdigit, 16 );
    if ( lastdigit != ( statestring + strlen( statestring ))) {
      TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "Invalid event string!" );
      continue;
    }

    /* getting the s88 module number */
    const char* sIOD = NodeOp.getName(child);
    int s88module = atoi(sIOD);

    if( s88module >= 100 ) {
      s88module = s88module - 100;
      TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "s88 module [%d]", s88module );
    }
    else {
      s88module = 0;
      TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "Invalid s88 module ID: [%s]", sIOD );
    }

    news88 = news88 & 0xFFFF;
    TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999,
        "news88[0x%04X] olds88[0x%04X]", news88, data->olds88[s88module] );

    if( news88 != data->olds88[s88module] ) {

      /* Send the on events to the ECoS */
      __sends88Eventgroup( inst, news88, data->olds88[s88module], s88module);


      data->olds88[ s88module ] = news88;
    }

  }

}


static void __reportState(iOECoS inst) {
  iOECoSData data = Data(inst);

  if( data->listenerFun != NULL && data->listenerObj != NULL ) {
    iONode node = NodeOp.inst( wState.name(), NULL, ELEMENT_NODE );

    if( data->iid != NULL )
      wState.setiid( node, data->iid );
    wState.setpower( node, data->power );
    wState.setenablecom( node, data->enablecom );

    data->listenerFun( data->listenerObj, node, TRCLEVEL_INFO );
  }
}



/* ToDo: System events:
  <EVENT 1>1 status[GO]<END 0 (OK)>
  <EVENT 1>1 status[STOP]<END 0 (OK)>
*/
static void __processSystemEvents( iOECoS inst, iONode node ) {
  iOECoSData data = Data(inst);
  int cnt = NodeOp.getChildCnt( node);
  if( cnt > 0 ) {
    iONode child = NodeOp.getChild(node, 0);
    const char* status = NodeOp.getStr(child, "status", "?");
    if( StrOp.equals("?", status ) ) {
      char* xml = NodeOp.base.toString(node);
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "Unhandled: %s", xml );
      StrOp.free(xml);
    }
    else {
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "system status is [%s]", status );
      data->power = StrOp.equals("GO", status);
      __reportState(inst);
    }
  }
}


/**
 * __processReply -- Handles incoming messages from the ECoS
 *
 * Called by __reader when data is available on the ECoS socket
 *
 */
static void __processReply( iOECoS inst, iONode node ) {
  iOECoSData data = Data( inst );

  int rtype         = NodeOp.getInt( node, "rtype", REPLY_TYPE_REPLY );
  const char* rname = NodeOp.getStr( node, "cmd", NULL );
  int oid           = NodeOp.getInt( node, "oid", 0 );

  if( (TraceOp.getLevel(NULL) & TRCLEVEL_BYTE) == TRCLEVEL_BYTE ) {
    char* s = NodeOp.base.toString(node);
    TraceOp.trc( name, TRCLEVEL_BYTE, __LINE__, 9999, "%s", s);
    StrOp.free(s);
  }

  if ( rtype == REPLY_TYPE_REPLY ) {

      /* These are the loco, switch and sensor events */

    TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999,
                  "MemOp.mem_getAllocCount() = [%d]", MemOp.getAllocCount());
    TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999,
                  "MemOp.mem_getAllocSize() = [%d]", MemOp.getAllocSize());

    TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "rname = [%s]", rname );
    TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "oid =[%d]", oid );

    if ( StrOp.equals( "queryObjects", rname ) && oid == OID_LCMANAGER ) {
      __processLocList( inst, node );

    } else if ( StrOp.equals( "create", rname ) && oid == OID_LCMANAGER ) {
      __processLocCreate( inst, node );

    } else if ( StrOp.equals( "queryObjects", rname ) && oid == OID_SWMANAGER ) {
      __processSwitchList( inst, node );

    } else if ( StrOp.equals( "set", rname ) && oid == OID_SWMANAGER ) {
      __processSwitchSet( inst, node );

    }
    else if ( oid == OID_ECOS) {
      __processSystemEvents( inst, node );
    }
    else if ( oid >= 100 && oid <= 300 ) {
      __processS88Events( inst, node );
    }
    else {
      TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "other reply, rname = [%s]", rname );
      TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "other reply, oid = [%d]", oid );
    }
  } else if ( rtype == REPLY_TYPE_EVENT ) {

    TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "event, rname = [%s]", rname );
    TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "event, oid = [%d]", oid );

    if ( oid == OID_ECOS) {
      __processSystemEvents( inst, node );
    }
    else if ( oid == 11) {
      __processSwitchManagerEvents( inst, node );

    } else if ( oid >= 20000 ) {
      __processSwitchEvents( inst, node );

    } else if ( oid >= 1000 ) {
      __processLocoEvents( inst, node );

    } else if ( oid >= 100 ) {
      __processS88Events( inst, node );

    }
  }
}


/**
 * __reader -- Reads messages coming in from the ECoS
 *
 * Sits in a tight 10msec loop checking for input.  Stops when the data object's
 * run flag is set false.  Incoming data is passed to __processReply.
 *
 * Note the use of ecos_reader (ecos-parser.c) to parse the incoming data.
 *
 */
static void __reader( void * threadinst ) {
  iOThread th     = ( iOThread )threadinst;
  iOECoS ecos     = ( iOECoS )ThreadOp.getParm( th );

  iOECoSData data = Data( ecos );

  TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "reader started" );

  while ( data->run ) {

    if ( data->connected && data->enablecom ) {
      char c;
      if( !SocketOp.isConnected( data->socket ) || SocketOp.isBroken( data->socket ) ) {
        data->connected = False;
        ThreadOp.sleep( 1000 );
        __connect( ecos );
      }
      else if ( SocketOp.peek( data->socket, &c, 1 )) {

          /* See ecos-parser.c for this call */

        iONode node = ecos_reader( data->socket );

          /* process reply */

        if ( node != NULL ) {
          __processReply( ecos, node );
          NodeOp.base.del( node );
        }
      }
    }

    ThreadOp.sleep( 10 );
  };

  TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "reader stopped" );
}


/**
 * _inst -- Constructor for an ECoS object.
 *
 * Creates a new ECoS object.  Allocates memory for the 2 main structs, and
 * starts 2 threads, one to try to connect, and another to read replies.
 *
 * Note that OECoSData is defined by the XML in rocdigs.xml
 *
 */
static struct OECoS* _inst( const iONode ini, const iOTrace trace ) {
  iOECoS __ECoS   = allocMem( sizeof( struct OECoS ));
  iOECoSData data = allocMem( sizeof( struct OECoSData ));

  TraceOp.set( trace );

  MemOp.basecpy( __ECoS, &ECoSOp, 0, sizeof( struct OECoS ), data );

  data->ini   = ini;
  data->trace = trace;

  /* an unnamed mutex to protect the object map */
  data->mapmux = MutexOp.inst( NULL, True );

    /* Evaluate attributes. */

  data->iid = StrOp.dup( wDigInt.getiid( ini ));  /* Set interface id */

  data->host      = wDigInt.gethost( ini );       /* host address */
  data->port      = wDigInt.getport( ini ) > 0 ? wDigInt.getport( ini ):15471;       /* port, usually 15471 */
  data->enablecom = True;

    /* Mark this object as running */

  data->run       = True;

    /* Show console we are up and running */

  TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "----------------------------------------" );
  TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "ECoS %d.%d.%d", vmajor, vminor, patch );
  TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "\"Started in Zeeland, finished in New York\"" );
  TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "----------------------------------------" );
  TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "iOECoS[%s] %s:%d",
                wDigInt.getiid( ini ) != NULL ? wDigInt.getiid( ini ) : "",
                data->host, data->port );

    /* Initialize data->xxx members... */

  data->writemux              = MutexOp.inst( NULL, True );
  data->locoNameToEcosOidMap  = MapOp.inst();
  data->ecosOidToLocoNameMap  = MapOp.inst();
  data->dccSwitchAddrToOidMap = MapOp.inst();
  data->dccOidToSwitchAddrMap = MapOp.inst();

  /* Start the reader thread */

  data->reader = ThreadOp.inst( NULL, &__reader, __ECoS );
  ThreadOp.start( data->reader );

  /* Start the run thread */

  data->initrun = ThreadOp.inst( NULL, &__initrun, __ECoS );
  ThreadOp.start( data->initrun );


    /* Count this instance */

  instCnt++;

  return __ECoS;
}


/* Support for dynamic Loading */

/**
 * rocGetDigInt -- calls the _inst routine and returns its handle
 *
 */
iIDigInt rocGetDigInt( const iONode ini, const iOTrace trc ) {
  return ( iIDigInt )_inst( ini, trc );
}

/* Ooooo I soooooo wanna remove or edit that line! :-)) */

/* ----- DO NOT REMOVE OR EDIT THIS INCLUDE LINE! -----*/
#include "rocdigs/impl/ecos.fm"
/* ----- DO NOT REMOVE OR EDIT THIS INCLUDE LINE! -----*/
