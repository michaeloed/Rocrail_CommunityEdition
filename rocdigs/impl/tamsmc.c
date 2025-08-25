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


#include "rocdigs/impl/tamsmc_impl.h"

#include "rocint/public/digint.h"

#include "rocrail/wrapper/public/DigInt.h"
#include "rocrail/wrapper/public/Program.h"
#include "rocrail/wrapper/public/Response.h"
#include "rocrail/wrapper/public/BinCmd.h"
#include "rocrail/wrapper/public/SysCmd.h"
#include "rocrail/wrapper/public/FunCmd.h"

#include "rocs/public/mem.h"
#include "rocs/public/lib.h"
#include "rocs/public/system.h"


static int instCnt = 0;

/** ----- OBase ----- */
static void __del( void* inst ) {
  if( inst != NULL ) {
    iOTamsMCData data = Data(inst);
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

/** ----- OTamsMC ----- */

/*
----- Programmiergleisbefehle -----
Die PT-Befehle funktionieren im Prinzip wie andere P50Xa-Befehle auch - sie
können jedoch deutlich länger brauchen (bis zu mehreren Sekunden). Die Kommandos
geben ein Ergebnis in der Form von Zahlen oder einen Fehlercode als Wort zurück.

Jede Ausgabe wird mit dem Prompt (<CR> + ']') abgeschlossen.

Entsprechend der IB-Dokumentation sind die folgend aufgeführten Fehlercodes vor-
gesehen. Einige werden jedoch beim gegenwärtigen Softwarestand nicht verwendet:
   - "Ok": Funktion erfolgreich beendet (z.B. bei schreibenden Zugriffen)
   - "Error": Allgemeiner Fehler, vor allem für falsche oder fehlende Parameter
   - "Yes": Bei Abfragen einer Funktionalität: positive Antwort
   - "No": Bei Abfragen einer Funktionalität: negative Antwort
   - "Busy!": PT belegt
   - "Short!": Kurzschluß auf dem Programmiergleis
   - "No decoder": kein Decoder gefunden
   - "No ack": Nach der Programmierung oder bei der Abfrage wurde kein ACK
           empfangen
   - "No page": Nach Programmierung im Pagemode wurde kein ACK empfangen
   - "Bit read error": Fehler in einem direkten CV-Zugriff auf Bitebene
   - "Timeout": beim Programmieren gab es ein Timeout

Aufgrund der derzeitigen Implementierung kann es eigentlich nur die Codes "Ok",
"Error" und "No ack" geben.

PTRP: Read using page mode
   Syntax: PTRP [CV]
   CV: 1 .. 1024

   Zurückgeliefert wird der Inhalt der adressierten CV als einfache Zahl.

PTWP: Write using page mode
   Syntax: PTWP [CV], [Value]
   CV: 1 .. 1024
   Value: 0 .. 255

   Der angegebene Wert wird in die entsprechende CV geschrieben.

PD: Write CV to decoder on main track
   Syntax: PD [Adr], [CV], [Value]
   Adr: Lokadresse 1 .. 10239
   CV: 1 .. 1024
   Value: 0 .. 255

   Schreibt den <Value> in die <CV> des über die Adresse <Adr> anzusprechenden
   Decoders (Multi-Funktion-Decoder, also ein normaler Lok-Dekoder).
   Es gibt keine Rückmeldung, daher wird der Befehl blind abgesetzt und als
   Ergebnis "Ok" geliefert. Das Kommando wird ganz normal über das Gleissignal
   gesendet (nicht über das Programmiergleis). Vorsicht ist beim Programmieren
   der Dekoder-Adresse (CV1 bzw. CV17/18) geboten. Programmiert man hier einen
   Wert ein, den bereits ein anderer Decoder hat, so haben beide anschließend
   die selbe Adresse und weitere Programmierungen beschreiben jeweils beide
   Dekoder.

 */

/**  */
static iONode _cmd( obj inst ,const iONode cmd ) {
  iOTamsMCData data = Data(inst);
  iONode response = NULL;

  if( StrOp.equals( NodeOp.getName( cmd ), wProgram.name() ) ) {
    if(  wProgram.getcmd( cmd ) == wProgram.set && wProgram.ispom( cmd )) {
      iONode lccmd = NodeOp.inst( wBinCmd.name(), NULL, ELEMENT_NODE );
      char* str = StrOp.fmt( "XPD %d, %d, %d\r", wProgram.getaddr(cmd), wProgram.getcv(cmd), wProgram.getvalue(cmd) );
      char* byteStr = StrOp.byteToStr( (byte*)str, StrOp.len(str) );
      TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, str );
      wBinCmd.setoutlen( lccmd, StrOp.len(str) );
      wBinCmd.setinlen( lccmd, 256 );
      wBinCmd.setinendbyte( lccmd, '\r' );
      wBinCmd.setout( lccmd, byteStr );
      StrOp.free( byteStr );
      StrOp.free( str );
      response = data->sublib->cmd((obj)data->sublib, lccmd);
    }
    else if(  wProgram.getcmd( cmd ) == wProgram.set ) {
      iONode rsp = NULL;
      iONode lccmd = NodeOp.inst( wBinCmd.name(), NULL, ELEMENT_NODE );
      char* str = StrOp.fmt( "XPTWD %d, %d\r", wProgram.getcv(cmd), wProgram.getvalue(cmd) );
      char* byteStr = StrOp.byteToStr( (byte*)str, StrOp.len(str) );
      TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, str );
      wBinCmd.setoutlen( lccmd, StrOp.len(str) );
      wBinCmd.setinlen( lccmd, 256 );
      wBinCmd.setinendbyte( lccmd, '\r' );
      wBinCmd.setout( lccmd, byteStr );
      StrOp.free( byteStr );
      StrOp.free( str );
      rsp = data->sublib->cmd((obj)data->sublib, lccmd);

      if(rsp != NULL) {
      /* inform listener */
        char* cvdata = (char*)StrOp.strToByte(NodeOp.getStr(rsp, "data", "" ));
        response = NodeOp.inst( wProgram.name(), NULL, ELEMENT_NODE );
        wProgram.setcv( response, wProgram.getcv(cmd) );
        wProgram.setvalue( response,  wProgram.getvalue(cmd) );
        wProgram.setcmd( response, wProgram.datarsp );
        if( data->iid != NULL )
          wProgram.setiid( response, data->iid );
        freeMem(cvdata);
        NodeOp.base.del(rsp);
      }

    }
    else if(  wProgram.getcmd( cmd ) == wProgram.get && wProgram.ispom( cmd )) {
      iONode rsp = NULL;
      iONode lccmd = NodeOp.inst( wBinCmd.name(), NULL, ELEMENT_NODE );
      char* str = StrOp.fmt( "XPD %d, %d\r", wProgram.getaddr(cmd), wProgram.getcv(cmd) );
      char* byteStr = StrOp.byteToStr( (byte*)str, StrOp.len(str) );
      TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, str );
      wBinCmd.setoutlen( lccmd, StrOp.len(str) );
      wBinCmd.setinlen( lccmd, 256 );
      wBinCmd.setinendbyte( lccmd, ']' );
      wBinCmd.setout( lccmd, byteStr );
      StrOp.free( byteStr );
      StrOp.free( str );
      rsp = data->sublib->cmd((obj)data->sublib, lccmd);
      if(rsp != NULL) {
        /* -> response is useless, must use other way 
           -> just ignore
        */
        NodeOp.base.del(rsp);
      }
    }
    else if(  wProgram.getcmd( cmd ) == wProgram.get ) {
      iONode rsp = NULL;
      iONode lccmd = NodeOp.inst( wBinCmd.name(), NULL, ELEMENT_NODE );
      char* str = StrOp.fmt( "XPTRD %d\r", wProgram.getcv(cmd) );
      char* byteStr = StrOp.byteToStr( (byte*)str, StrOp.len(str) );
      TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, str );
      wBinCmd.setoutlen( lccmd, StrOp.len(str) );
      wBinCmd.setinlen( lccmd, 256 );
      wBinCmd.setinendbyte( lccmd, ']' );
      wBinCmd.setout( lccmd, byteStr );
      StrOp.free( byteStr );
      StrOp.free( str );
      rsp = data->sublib->cmd((obj)data->sublib, lccmd);

      if(rsp != NULL) {
      /* inform listener */
        const char* rawdata = NodeOp.getStr(rsp, "data", "" );
        if( StrOp.len(rawdata ) > 0 ) {
          char* cvdata = (char*)StrOp.strToByte(rawdata);
          response = NodeOp.inst( wProgram.name(), NULL, ELEMENT_NODE );
          wProgram.setcv( response, wProgram.getcv(cmd) );
          wProgram.setvalue( response, atoi(cvdata ));
          wProgram.setcmd( response, wProgram.datarsp );
          if( data->iid != NULL )
            wProgram.setiid( response, data->iid );
          freeMem(cvdata);
        }
        NodeOp.base.del(rsp);
      }

    }
    else if(  wProgram.getcmd( cmd ) == wProgram.pton ) {
      iONode iocmd = NodeOp.inst(wSysCmd.name(), NULL, ELEMENT_NODE);
      wSysCmd.setcmd( iocmd, "stopio");
      TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "PT ON" );
      response = data->sublib->cmd((obj)data->sublib, iocmd);
    }
    else if( wProgram.getcmd( cmd ) == wProgram.ptoff ) {
      iONode iocmd = NodeOp.inst(wSysCmd.name(), NULL, ELEMENT_NODE);
      wSysCmd.setcmd( iocmd, "startio");
      TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "PT OFF" );
      response = data->sublib->cmd((obj)data->sublib, iocmd);
    }
  }
  else if( StrOp.equals( NodeOp.getName( cmd ), wFunCmd.name() ) && wFunCmd.getgroup(cmd)  > 4 ) {
    /*
    *** XFunc34 (0x8A) - L‰nge = 1+4 bytes
       Command:
      0: 0x8A XFunc34
      1: LSB der Lokadresse
      2: MSB der Lokadresse (Adresse im Bereich 1 .. 10239)
      3: Status der Funktionen F17 (Bit #0) bis F24 (Bit #7)
      4: Status der Funktionen F25 (Bit #0) bis F28 (Bit #3), die Bits #4 bis
         #7 sind reserviert

       Antwort: 1 Byte
      0: Error-Code

       Mˆgliche Error-Codes:
      OK  - OK, Befehl ausgef¸hrt
      XBADPRM - Lokadresse auﬂerhalb des Bereichs (1 .. 10239)
      XNOSLOT - Kein Platz in Refresh-Queue
    */
    int   addr = wFunCmd.getaddr( cmd );
    iONode fxcmd = NodeOp.inst( wBinCmd.name(), NULL, ELEMENT_NODE );
    char* byteStr = NULL;
    byte outBytes[6];
    outBytes[0] = (byte)'x';
    outBytes[1] = 0x8A;
    outBytes[2] = addr % 256;
    outBytes[3] = addr / 256;
    outBytes[4] = (wFunCmd.isf17(cmd)?0x01:0x00) + (wFunCmd.isf18(cmd)?0x02:0x00) + (wFunCmd.isf19(cmd)?0x04:0x00) + (wFunCmd.isf20(cmd)?0x08:0x00) +
                  (wFunCmd.isf21(cmd)?0x10:0x00) + (wFunCmd.isf22(cmd)?0x20:0x00) + (wFunCmd.isf23(cmd)?0x40:0x00) + (wFunCmd.isf24(cmd)?0x80:0x00);
    outBytes[5] = (wFunCmd.isf25(cmd)?0x01:0x00) + (wFunCmd.isf26(cmd)?0x02:0x00) + (wFunCmd.isf27(cmd)?0x04:0x00) + (wFunCmd.isf28(cmd)?0x08:0x00);

    byteStr = StrOp.byteToStr( outBytes, 6 );
    wBinCmd.setoutlen( fxcmd, 6 );
    wBinCmd.setinlen( fxcmd, 1 );
    wBinCmd.setout( fxcmd, byteStr );
    StrOp.free( byteStr );
    TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "XFunc34" );
    response = data->sublib->cmd((obj)data->sublib, fxcmd);

  }

  else {
    response = data->sublib->cmd((obj)data->sublib, cmd);
  }

  return response;
}


/**  */
static void _halt( obj inst ,Boolean poweroff, Boolean shutdown ) {
  iOTamsMCData data = Data(inst);
  data->run = False;
  data->sublib->halt((obj)data->sublib, poweroff, shutdown);
}


/**  */
static Boolean _setListener( obj inst ,obj listenerObj ,const digint_listener listenerFun ) {
  iOTamsMCData data = Data(inst);
  return data->sublib->setListener( (obj)data->sublib , listenerObj, listenerFun );
}


static Boolean _setRawListener(obj inst, obj listenerObj, const digint_rawlistener listenerFun ) {
  return True;
}

static byte* _cmdRaw( obj inst, const byte* cmd ) {
  return NULL;
}

/** external shortcut event */
static void _shortcut( obj inst ) {
  iOTamsMCData data = Data(inst);
}


/** bit0=power, bit1=programming, bit2=connection */
static int _state( obj inst ) {
  iOTamsMCData data = Data(inst);
  return data->sublib->state((obj)data->sublib);
}


/**  */
static Boolean _supportPT( obj inst ) {
  iOTamsMCData data = Data(inst);
  return data->sublib->supportPT((obj)data->sublib);
}


/* VERSION: */
static int vmajor = 2;
static int vminor = 0;
static int patch  = 99;
static int _version( obj inst ) {
  iOTamsMCData data = Data(inst);
  return vmajor*10000 + vminor*100 + patch;
}


typedef iIDigInt (* LPFNROCGETDIGINT)( const iONode ,const iOTrace );

/**  */
static struct OTamsMC* _inst( const iONode ini ,const iOTrace trc ) {
  iOTamsMC __TamsMC = allocMem( sizeof( struct OTamsMC ) );
  iOTamsMCData data = allocMem( sizeof( struct OTamsMCData ) );
  MemOp.basecpy( __TamsMC, &TamsMCOp, 0, sizeof( struct OTamsMC ), data );

  TraceOp.set( trc );

  /* Initialize data->xxx members... */
  data->iid = StrOp.dup( wDigInt.getiid( ini ) );
  data->ini = (iONode)NodeOp.base.clone(ini);

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "----------------------------------------" );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "tamsmc %d.%d.%d", vmajor, vminor, patch );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "iid    = %s", data->iid );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "----------------------------------------" );

  /* load sub library */
  {
    iOLib    pLib = NULL;
    LPFNROCGETDIGINT pInitFun = (void *) NULL;
    /* TODO: get the library path! */
    char* libpath = StrOp.fmt( "%s%c%s", wDigInt.getlibpath(data->ini),
        SystemOp.getFileSeparator(), "p50x" );
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "try to load [%s]", libpath );
    pLib = LibOp.inst( libpath );
    StrOp.free( libpath );


    if (pLib != NULL) {
      pInitFun = (LPFNROCGETDIGINT)LibOp.getProc(pLib,"rocGetDigInt");
      if (pInitFun != NULL) {
        data->sublib = pInitFun( data->ini, trc );
      }
    }
  }

  if( data->sublib == NULL ) {
    TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "unable to load [%s]", "p50x" );
    freeMem( data );
    freeMem(__TamsMC);
    return NULL;
  }

  data->run = True;

  instCnt++;
  return __TamsMC;
}

/* Support for dynamic Loading */
iIDigInt rocGetDigInt( const iONode ini ,const iOTrace trc )
{
  return (iIDigInt)_inst(ini,trc);
}



/* ----- DO NOT REMOVE OR EDIT THIS INCLUDE LINE! -----*/
#include "rocdigs/impl/tamsmc.fm"
/* ----- DO NOT REMOVE OR EDIT THIS INCLUDE LINE! -----*/
