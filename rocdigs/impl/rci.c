/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D  (First time only!)
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocDigs
  * XML: $Source: /cvsroot/rojav/rocdigs/rocdigs.xml,v $
  * XML: $Revision: 1.14 $
  * Object: RCI
  * Date: Fri Aug  3 14:03:49 2018
  * ------------------------------------------------------------
  * $Source$
  * $Author$
  * $Date$
  * $Revision$
  * $Name$
  */

#include "rocdigs/impl/rci_impl.h"

#include "rocs/public/mem.h"

static int instCnt = 0;

/** ----- OBase ----- */
static void __del( void* inst ) {
  if( inst != NULL ) {
    iORCIData data = Data(inst);
    /* Cleanup data->xxx members...*/
    
    freeMem( data );
    freeMem( inst );
    instCnt--;
  }
  return;
}

static const char* __name( void ) {
  return name;
}

static unsigned char* __serialize( void* inst, long* size ) {
  return NULL;
}

static void __deserialize( void* inst,unsigned char* bytestream ) {
  return;
}

static char* __toString( void* inst ) {
  return NULL;
}

static int __count( void ) {
  return instCnt;
}

static struct OBase* __clone( void* inst ) {
  return NULL;
}

static Boolean __equals( void* inst1, void* inst2 ) {
  return False;
}

static void* __properties( void* inst ) {
  return NULL;
}

static const char* __id( void* inst ) {
  return NULL;
}

static void* __event( void* inst, const void* evt ) {
  return NULL;
}

/** ----- ORCI ----- */


/**  */
static iONode _cmd( obj inst ,const iONode cmd ) {
  return 0;
}


/**  */
static byte* _cmdRaw( obj inst ,const byte* cmd ) {
  return 0;
}


/**  */
static void _halt( obj inst ,Boolean poweroff ,Boolean shutdown ) {
  return;
}


/**  */
static Boolean _setListener( obj inst ,obj listenerObj ,const digint_listener listenerFun ) {
  return 0;
}


/**  */
static Boolean _setRawListener( obj inst ,obj listenerObj ,const digint_rawlistener listenerRawFun ) {
  return 0;
}


/** external shortcut event */
static void _shortcut( obj inst ) {
  return;
}


/** bit0=power, bit1=programming, bit2=connection */
static int _state( obj inst ) {
  return 0;
}


/**  */
static Boolean _supportPT( obj inst ) {
  return 0;
}


/** vmajor*1000 + vminor*100 + patch */
static int _version( obj inst ) {
  return 0;
}


/**  */
static struct ORCI* _inst( const iONode ini ,const iOTrace trc ) {
  iORCI __RCI = allocMem( sizeof( struct ORCI ) );
  iORCIData data = allocMem( sizeof( struct ORCIData ) );
  MemOp.basecpy( __RCI, &RCIOp, 0, sizeof( struct ORCI ), data );

  /* Initialize data->xxx members... */

  instCnt++;
  return __RCI;
}

iIDigInt rocGetDigInt(const iONode ini, const iOTrace trc)
{
    return (iIDigInt)_inst(ini, trc);
}


/* ----- DO NOT REMOVE OR EDIT THIS INCLUDE LINE! -----*/
#include "rocdigs/impl/rci.fm"
/* ----- DO NOT REMOVE OR EDIT THIS INCLUDE LINE! -----*/
