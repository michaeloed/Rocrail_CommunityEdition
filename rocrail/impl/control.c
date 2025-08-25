/*
 * This is part of FreeRail - Model Railway Software
 *
 * Copyright: See AUTHORS at the top-level directory of this project and
 * at GitHub <https://github.com/michaeloed/FreeRail/>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 3
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "rocrail/impl/control_impl.h"
#include "rocrail/public/app.h"
#include "rocrail/public/model.h"
#include "rocrail/public/block.h"
#include "rocrail/public/r2rnet.h"
#include "rocrail/public/dec.h"
#include "rocrail/public/var.h"

#include "rocint/public/digint.h"

#include "rocs/public/doc.h"
#include "rocs/public/trace.h"
#include "rocs/public/node.h"
#include "rocs/public/thread.h"
#include "rocs/public/mem.h"
#include "rocs/public/str.h"
#include "rocs/public/strtok.h"
#include "rocs/public/map.h"
#include "rocs/public/lib.h"
#include "rocs/public/system.h"
#include "rocs/public/dir.h"

#include "rocrail/wrapper/public/Global.h"
#include "rocrail/wrapper/public/FreeRail.h"
#include "rocrail/wrapper/public/Ctrl.h"
#include "rocrail/wrapper/public/DigInt.h"
#include "rocrail/wrapper/public/Clock.h"
#include "rocrail/wrapper/public/Switch.h"
#include "rocrail/wrapper/public/Signal.h"
#include "rocrail/wrapper/public/Output.h"
#include "rocrail/wrapper/public/Link.h"
#include "rocrail/wrapper/public/Feedback.h"
#include "rocrail/wrapper/public/Route.h"
#include "rocrail/wrapper/public/Turntable.h"
#include "rocrail/wrapper/public/SelTab.h"
#include "rocrail/wrapper/public/Loc.h"
#include "rocrail/wrapper/public/FunCmd.h"
#include "rocrail/wrapper/public/Block.h"
#include "rocrail/wrapper/public/ModelCmd.h"
#include "rocrail/wrapper/public/SysCmd.h"
#include "rocrail/wrapper/public/AutoCmd.h"
#include "rocrail/wrapper/public/Command.h"
#include "rocrail/wrapper/public/Response.h"
#include "rocrail/wrapper/public/Plan.h"
#include "rocrail/wrapper/public/Program.h"
#include "rocrail/wrapper/public/State.h"
#include "rocrail/wrapper/public/DataReq.h"
#include "rocrail/wrapper/public/ActionList.h"
#include "rocrail/wrapper/public/Action.h"
#include "rocrail/wrapper/public/ActionCtrl.h"
#include "rocrail/wrapper/public/PwrCmd.h"
#include "rocrail/wrapper/public/BoosterList.h"
#include "rocrail/wrapper/public/Booster.h"
#include "rocrail/wrapper/public/R2RnetIni.h"
#include "rocrail/wrapper/public/Stage.h"
#include "rocrail/wrapper/public/SystemActions.h"
#include "rocrail/wrapper/public/Issue.h"
#include "rocrail/wrapper/public/Devices.h"
#include "rocrail/wrapper/public/Operator.h"
#include "rocrail/wrapper/public/Variable.h"
#include "rocrail/wrapper/public/VariableList.h"
#include "rocrail/wrapper/public/DirEntry.h"
#include "rocrail/wrapper/public/FileEntry.h"
#include "rocrail/wrapper/public/Trace.h"

#include "rocutils/public/devices.h"
#include "rocutils/public/fileutils.h"

typedef iIDigInt (* LPFNROCGETDIGINT)( const iONode ,const iOTrace );
/* proto types */
static void __informDigInts( iOControl inst );
static void __listener( obj inst, iONode nodeC, int level );
static void __checkAction( iOControl inst, const char* state, const char* by );
static void __control_callback( obj inst, iONode nodeA );

static int instCnt = 0;

/*
 ***** OBase functions.
 */
static const char* __id( void* inst ) {
  return NULL;
}

static void* __event( void* inst, const void* evt ) {
  iOControlData data = Data(inst);
  iONode node = (iONode)evt;
  if( node != NULL && StrOp.equals( wFeedback.name(), NodeOp.getName(node) ) ) {
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999,
        "sensor event [%s][%s]", wFeedback.getid(node), wFeedback.isstate(node)?"ON":"OFF" );
    if( StrOp.equals( wFeedback.getid(node), wFreeRail.getscsensor(AppOp.getIni()) ) ) {
      if( wFeedback.isstate(node) ) {
        TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "short circuit!" );
        /* inform command station */
        if( wFreeRail.getsciid(AppOp.getIni()) != NULL && StrOp.len( wFreeRail.getsciid(AppOp.getIni()) ) > 0 ) {
          const char* iid = wFreeRail.getsciid(AppOp.getIni());
          iIDigInt pDi = (iIDigInt)MapOp.get( data->diMap, iid );
          if( pDi != NULL ) {
            TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999,
                "informing fitting DigInt [%s]...", iid );
            pDi->shortcut( (obj)pDi );
          }

        }
      }
      else {
        TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "booster reports normal operation" );
      }
      return NULL;
    }
  }

  if( node != NULL ) {
    __control_callback(inst, node);
  }

  return NULL;
}

static const char* __name(void) {
  return name;
}
static unsigned char* __serialize(void* inst, long* size) {
  return NULL;
}
static void __deserialize(void* inst, unsigned char* a) {
}
static char* __toString(void* inst) {
  return "";
}
static void __del(void* inst) {
  iOControlData data = Data(inst);
  freeMem( data );
  freeMem( inst );
  instCnt--;
}
static void* __properties(void* inst) {
  if( inst != NULL ) {
    iOControlData data = Data(inst);
    return NULL;
  }
  else
    return NULL;
}
static int __count(void) {
  return instCnt;
}
static struct OBase* __clone( void* inst ) {
  return NULL;
}
static Boolean __equals( void* inst1, void* inst2 ) {
  return False;
}


static void __initSensors( iOControl inst ) {
  iOControlData data = Data(inst);
  iOModel model = AppOp.getModel();
  iOFBack s = ModelOp.getFBack( model, wFreeRail.getscsensor(AppOp.getIni()) );

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "Init short circuit sensor..." );

  if( s != NULL ) {
    FBackOp.addListener( s, (obj)inst );
  }
  else {
    TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "short circuit sensor not set." );
  }

}


static Boolean __informDigInt( iOControl inst, iIDigInt pDi, iONode node, int* error ) {
  iOControlData data  = Data(inst);
  Boolean rc          = True;

  /* inform digitalInterface */
  if( pDi != NULL ) {
    iONode rsp = pDi->cmd( (obj)pDi, node );
    if( rsp != NULL ) {

      if( StrOp.equals( NodeOp.getName( rsp ), wProgram.name() ) ) {
        /* Decoder programming response: */
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "Program event...value=%d", wProgram.getvalue( rsp ) );
        AppOp.broadcastEvent( rsp );
      }
      else if( StrOp.equals( NodeOp.getName( rsp ), wFeedback.name() ) ) {
        /* sensor simulation response: */
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999,
            "Sensor event...addr=%d state=%s", wFeedback.getaddr( rsp ), wFeedback.isstate( rsp )?"true":"false" );
        __listener( (obj)inst, rsp, TRCLEVEL_INFO );
      }
      else if( wResponse.iserror( rsp ) ) {
        char* str = NodeOp.base.toString( rsp );
        TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "%s", str );
        StrOp.free( str );
        rc = False;
        if( error != NULL )
          *error = CMD_ERROR;
      }
      else if( wResponse.isretry( rsp ) ) {
        if( error != NULL )
          *error = CMD_RETRY;
        rc = False;
      }


      /*
      const char* threadName = NodeOp.getStr( node, "server", "?" );
      iOThread sthread = ThreadOp.find( threadName );
      if( sthread != NULL )
        ThreadOp.post( sthread, (obj)rsp );
      else
        TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "cmd() thread [%s] unknown.", threadName );
      */
    }
  }
  else {
    TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "Interface ID is not set!" );
  }

  return rc;
}


static void __txshortids( void* threadinst ) {
  iOThread        th = (iOThread)threadinst;
  iOControl  control = (iOControl)ThreadOp.getParm(th);
  iOControlData data = Data(control);
  iONode cmd = NULL;
  int err;

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "Clear short ID's" );
  cmd = NodeOp.inst(wSysCmd.name(), NULL, ELEMENT_NODE);
  wSysCmd.setcmd( cmd, wSysCmd.clearshortids );
  ControlOp.cmd( control, cmd, &err );

  /* iterate locos */
  {
    iOList list = ModelOp.getLocIDs(AppOp.getModel());
    int i = 0;
    for( i = 0; i < ListOp.size(list); i++ ) {
      const char* id = (const char*)ListOp.get(list, i);
      iOLoc loc = ModelOp.getLoc( AppOp.getModel(), id, NULL, False );
      if( loc != NULL ) {
        iONode lccmd = NodeOp.inst(wLoc.name(), NULL, ELEMENT_NODE);
        wLoc.setcmd( lccmd, wLoc.shortid );
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "loco [%s] transmit short ID", LocOp.getId(loc) );
        LocOp.cmd( loc, lccmd );
        ThreadOp.sleep( 10 );
      }
    }
    ListOp.base.del(list);
  }

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "Transmit short ID's" );
  cmd = NodeOp.inst(wSysCmd.name(), NULL, ELEMENT_NODE);
  wSysCmd.setcmd( cmd, wSysCmd.txshortids );
  ControlOp.cmd( control, cmd, &err );

  data->txshortidsrun = False;
  ThreadOp.base.del(th);
}


static Boolean _cmd( iOControl inst, iONode node, int* error ) {
  iOControlData data  = Data(inst);
  Boolean rc          = True;
  iONode modelSysCmd  = NULL;
  Boolean skipDigInt  = False;

  if( error != NULL )
    *error = CMD_OK;

  {
    const char* iid = wCommand.getiid( node );
    iIDigInt pDi    = data->pDi;

    TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "NodeOp.getName=%s", NodeOp.getName( node ));

    /* check for program commands which must be send to other than the default */
    if( (iid == NULL || StrOp.len(iid) == 0) && StrOp.equals( NodeOp.getName( node ), wProgram.name() ) ) {
      const char* lciid = wFreeRail.getlciid( AppOp.getIni() );
      const char* ptiid = wFreeRail.getptiid( AppOp.getIni() );
      const char* sviid = wFreeRail.getsviid( AppOp.getIni() );
      if( ( wProgram.getlntype(node) == wProgram.lntype_sv || wProgram.getlntype(node) == wProgram.lntype_cv ) &&
          sviid != NULL && StrOp.len( sviid ) > 0 ) {
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999,
                     "setting iid=[%s] for LN-SV programming", sviid );
        wCommand.setiid( node, sviid );
        iid = sviid;
      }
      else if( ptiid != NULL && StrOp.len( ptiid ) > 0 && !wProgram.ispom(node) ) {
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999,
                     "setting iid=[%s] for programming", ptiid );
        wCommand.setiid( node, ptiid );
        iid = ptiid;
      }
      else if( lciid != NULL && StrOp.len( lciid ) > 0 && wProgram.ispom(node) ) {
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999,
                     "setting iid=[%s] for programming", lciid );
        wCommand.setiid( node, lciid );
        iid = lciid;
      }
    }
    else if( (iid != NULL && StrOp.len(iid) > 0) && StrOp.equals( NodeOp.getName( node ), wProgram.name() ) ) {
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "using iid=[%s] for programming", iid );
    }


    /* check for locomotive commands which must be send to other than the default */
    if( StrOp.equals( NodeOp.getName( node ), wLoc.name() ) || StrOp.equals( NodeOp.getName( node ), wFunCmd.name() ) ) {
      if( iid == NULL || StrOp.len(iid) == 0 ) {
        const char* lciid = wFreeRail.getlciid( AppOp.getIni() );
        const char* dpiid = wFreeRail.getdpiid( AppOp.getIni() );
        if( StrOp.equals( wLoc.getcmd(node), wLoc.dispatch ) && dpiid != NULL && StrOp.len(dpiid) > 0 ) {
          TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999,
                       "setting iid=[%s] for dispatch locomotive %s", dpiid, wLoc.getid(node) );
          wLoc.setiid( node, dpiid );
          iid = dpiid;
        }
        else if( lciid != NULL && StrOp.len( lciid ) > 0 ) {
          TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999,
                       "setting iid=[%s] for locomotive %s", lciid, wLoc.getid(node) );
          wLoc.setiid( node, lciid );
          iid = lciid;
        }
      }
    }


    if( StrOp.equals( wSysCmd.name(), NodeOp.getName(node) ) ) {
      /* keep a copy of the command to inform the model after the digints */
      modelSysCmd = (iONode)NodeOp.base.clone(node);
      __checkAction(inst, wSysCmd.getcmd(node), "cmd");

      if( StrOp.equals(wSysCmd.ebreak, wSysCmd.getcmd(node)) ) {
        if( wCtrl.isv0onebreak( wFreeRail.getctrl( AppOp.getIni() ) ) ) {
          NodeOp.setName(node, wAutoCmd.name());
          wAutoCmd.setcmd(node, wAutoCmd.v0locos);
          wAutoCmd.setreset(node, True);
          NodeOp.base.del(modelSysCmd);
          modelSysCmd = node;
          skipDigInt = True;
        }
      }
    }

    if( StrOp.equals( wPwrCmd.name(), NodeOp.getName(node) ) && data->powerman != NULL ) {
      /* inform power manager */
      PowerManOp.cmd( data->powerman, (iONode)NodeOp.base.clone(node));
    }

    if( StrOp.equals( wActionCtrl.name(), NodeOp.getName(node) ) ) {
      iOAction Action = ModelOp.getAction(AppOp.getModel(), wActionCtrl.getid( node ));
      if( Action != NULL ) {
        ActionOp.exec(Action, node);
      }
    }

    if( !skipDigInt ) {
      if( (StrOp.equals( wSysCmd.name(), NodeOp.getName(node) ) && wSysCmd.isinformall(node)) ||
          StrOp.equals( wClock.name(), NodeOp.getName(node) ) )
      {
        /* inform all */
        pDi = (iIDigInt)MapOp.first( data->diMap );
        while( pDi != NULL ) {
          rc = __informDigInt(inst, pDi, (iONode)NodeOp.base.clone(node), error);
          pDi = (iIDigInt)MapOp.next( data->diMap );
        }
        /* clean up original command node */
        NodeOp.base.del(node);
      }
      else if( iid != NULL && StrOp.len( iid ) > 0 ) {
        TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "address of diMap=%d", data->diMap );
        TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "iid=%s", iid );
        /* inform a specific one */
        pDi = (iIDigInt)MapOp.get( data->diMap, iid );
        if( pDi != NULL )
          rc = __informDigInt(inst, pDi, node, error);
        else
          TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "iid=%s not found", iid );
      }
      else {
        /* inform the default */
        rc = __informDigInt(inst, data->pDi, node, error);
      }
    }

    if( modelSysCmd != NULL ) {
      /* inform model */
      ModelOp.cmd( AppOp.getModel(), modelSysCmd);
    }



  }

  return rc;
}


static void  __grouplink( obj inst, iONode link ) {
  iOControlData data = Data(inst);
  iOModel model = AppOp.getModel();

  if( StrOp.equals( wLink.name(), NodeOp.getName( link ) ) ) {
    const char* src = wLink.getsrc( link );
    iIBlockBase blockA = ModelOp.getBlock( model, src );
    iIBlockBase blockB = NULL;
    iOStrTok tok = StrTokOp.inst( wLink.getdst( link ), ',' );

    while( StrTokOp.hasMoreTokens( tok ) )  {
      const char* id = StrTokOp.nextToken( tok );
      if( StrOp.len( id ) > 0 ) {
        blockB = ModelOp.getBlock( model, id );
        if( blockA != NULL && blockB != NULL ) {
          if( wLink.isactive( link ) )
            BlockOp.link( blockB, blockA );
          else
            BlockOp.unLink( blockB );
          blockA = blockB;
          blockB = NULL;
        }
      }
    }
    StrTokOp.base.del(tok);
  }
}


static void __handleIssue(obj inst, iONode node) {
  iOControlData data    = Data(inst);
  const char* issuePath = wFreeRail.getissuepath( AppOp.getIni() );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "issue: %s", wIssue.getsubject(node) );
  if( !FileOp.exist(issuePath) ) {
    FileOp.mkdir(issuePath);
  }
  if( FileOp.exist(issuePath) ) {
    char* issueDir = StrOp.fmt("%s%c%s", issuePath, SystemOp.getFileSeparator(), wIssue.getsubject(node) );
    char* issueTxt = NULL;
    char* tmp = NULL;
    iOFile f = NULL;
    StrOp.replaceAll(issueDir, ' ', '_');
    if( !FileOp.exist(issueDir) ) {
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "creating issue directory: %s", issueDir );
      FileOp.mkdir(issueDir);
    }

    issueTxt = StrOp.fmt("%s%c%s", issueDir, SystemOp.getFileSeparator(), "issue.txt" );
    f = FileOp.inst(issueTxt, OPEN_WRITE );
    if( f != NULL ) {
      /* Write statistics: */
      char* stamp = StrOp.createStamp();
      tmp = StrOp.fmt( "Date: %s\n%s: %d.%d.%d-%d %s\nOS: %s\n\n",
          stamp,
          wGlobal.productname,
          wGlobal.vmajor,
          wGlobal.vminor,
          wGlobal.patch,
          AppOp.getrevno(),
          wGlobal.releasename,
          TraceOp.getOS());

      StrOp.free(stamp);

      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "writing issue text: %s", issueTxt );

      FileOp.writeStr( f, tmp );
      StrOp.free(tmp);

      {
        long t = AppOp.getStartTime();
        FileOp.fmt( f, "started at %s\n", ctime( &t ) );
      }

      FileOp.fmt(f, "process id         = %d\n", SystemOp.getpid());
      tmp = FileOp.pwd();
      FileOp.fmt( f, "working directory = %s\n", tmp );
      StrOp.free(tmp);
      FileOp.fmt( f, "allocation count  = %u\n", MemOp.getAllocCount() );
      FileOp.fmt( f, "allocated memory  = %d MB\n", MemOp.getAllocSize() / (1024*1024) );
      FileOp.fmt( f, "clients           = %d\n", ClntConOp.getClientCount( AppOp.getClntCon() ) );
      FileOp.fmt( f, "connections       = %d\n", ClntConOp.getConCount( AppOp.getClntCon() ) );
      FileOp.fmt( f, "locos             = %d\n", LocOp.base.count() );


      FileOp.fmt( f, "\n\n%s:\n----------------------------------------\n", wIssue.getsubject(node) );
      FileOp.writeStr( f, wIssue.getdesc(node) );

      {
        int i = 0;
        const char** ex = AppOp.getBackTrace();
        FileOp.fmt( f, "\n\nBackTrace: (last 10 exceptions and warnings)\n----------------------------------------\n" );
        for( i = 9; i >= 0; i-- ) {
          if( ex[i] != NULL ) {
            FileOp.fmt( f, " %s\n", ex[i] );
          }
        }
      }

      {
        iOList thList = ThreadOp.getAll();
        int i = 0;
        int cnt = ListOp.size( thList );
        FileOp.fmt( f, "\n\n%d threads:\n----------------------------------------\n", cnt );
        for( i = 0; i < cnt; i++ ) {
          iOThread th = (iOThread)ListOp.get( thList, i );
          const char* tname = ThreadOp.getName( th );
          char* tdesc = ThreadOp.base.toString( th );
          FileOp.fmt( f, "%s \"%s\"\n", tname, tdesc );
          StrOp.free( tdesc );
        }
        /* Cleanup. */
        thList->base.del( thList );
      }


      FileOp.base.del(f);
    }



    /* Write the Inifile from memory: */
    tmp = StrOp.fmt("%s%c%s", issueDir, SystemOp.getFileSeparator(), "rocrail.ini" );
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "writing ini: %s", tmp );
    {
      iOFile iniFile = FileOp.inst( tmp, OPEN_WRITE );
      if( iniFile != NULL ) {
        char* iniStr = NodeOp.base.toString( AppOp.getIni() );
        FileOp.write( iniFile, iniStr, StrOp.len( iniStr ) );
        FileOp.close( iniFile );
        StrOp.free(iniStr);
      }
    }
    StrOp.free(tmp);

    /* Write the model from memory: */
    tmp = StrOp.fmt("%s%c%s", issueDir, SystemOp.getFileSeparator(), "model.xml" );
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "writing model: %s", tmp );
    {
      iOFile iniFile = FileOp.inst( tmp, OPEN_WRITE );
      if( iniFile != NULL ) {
        char* iniStr = NodeOp.base.toString( ModelOp.getModel(AppOp.getModel()) );
        FileOp.write( iniFile, iniStr, StrOp.len( iniStr ) );
        FileOp.close( iniFile );
        StrOp.free(iniStr);
      }
    }
    StrOp.free(tmp);

    /* Copy trace file: */
    tmp = StrOp.fmt("%s%c%s", issueDir, SystemOp.getFileSeparator(), "rocrail.trc" );
    {
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "copy trace %s to %s", TraceOp.getCurrentFilename(NULL), tmp );
      FileOp.cp( TraceOp.getCurrentFilename(NULL), tmp );
    }
    StrOp.free(tmp);

    /* Write occupancy from memory: */
    tmp = StrOp.fmt("%s%c%s", issueDir, SystemOp.getFileSeparator(), "occ.xml" );
    ModelOp.saveBlockOccupancy(AppOp.getModel(), tmp);
    StrOp.free(tmp);

    StrOp.free(issueTxt);
    StrOp.free(issueDir);



  }
}

static int __AnalyseMode = 0;
static void __analyse( void* threadinst ) {
  iOThread        th = (iOThread)threadinst;
  iOControl  control = (iOControl)ThreadOp.getParm(th);
  iOControlData data = Data(control);

  ModelOp.analyse( AppOp.getModel(), __AnalyseMode );
  AppOp.broadcastEvent( ControlOp.getState(control));
  ThreadOp.base.del(th);
}

static char* __getTrcFile( iOControl inst, const char* fileName ) {
  iOControlData data = Data(inst);
  char*     protpath = FileOp.getPath( TraceOp.getFilename(NULL) );
  Boolean   absolute = False;
  char*     text     = NULL;

  if( protpath == NULL )
    protpath = StrOp.dup(".");

  char* realpath = StrOp.fmt( "%s%c%s", protpath, SystemOp.getFileSeparator(), FileOp.ripPath(fileName) );

  if( FileOp.exist(realpath) ) {
    iOFile file = FileOp.inst( realpath, OPEN_READONLY );
    if( file != NULL ) {
      if( FileOp.size( file ) > 110 * 1024 ) {
        TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "trace file [%s] exeeds the 100KB limit; size=%ld", realpath, FileOp.size( file ) );
        text = allocMem( 1024 );
        StrOp.fmtb(text, "trace file [%s] exeeds the 100KB limit; size=%ld", realpath, FileOp.size( file ));
      }
      else {
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "read trace file [%s] size=%ld", realpath, FileOp.size( file ) );
        text = allocMem( FileOp.size( file ) + 1 );
        FileOp.read( file, text, FileOp.size( file ) );
      }

      FileOp.close( file );
      FileOp.base.del( file );
    }
  }
  else {
    TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "trace file [%s] not found", realpath );
  }

  StrOp.free( realpath );
  StrOp.free( protpath );

  return text;
}


static iONode __scan4Trc( iOControl inst ) {
  iOControlData    data = Data(inst);
  iODir        dir = NULL;
  const char*  fileName = NULL;
  char*  protpath = FileOp.getPath( TraceOp.getFilename(NULL) );
  const char* tracefile = FileOp.ripPath( wTrace.getrfile( wFreeRail.gettrace( AppOp.getIni() ) ) );
  Boolean      absolute = False;

  iONode direntry = NULL;

  if( protpath == NULL )
    protpath = StrOp.dup(".");

  absolute = FileOp.isAbsolute( protpath );

  dir = DirOp.inst( protpath );
  if( dir != NULL ) {
    direntry = NodeOp.inst(wDirEntry.name(), NULL, ELEMENT_NODE);
    wDirEntry.setdir(direntry, protpath);
    /* Get the first directory entry. */
    fileName = DirOp.read( dir );

    /* Iterate all directory entries. */
    while( fileName != NULL ) {
      char sep[10];
      sep[0] = SystemOp.getFileSeparator();
      sep[1] = '.';
      sep[2] = SystemOp.getFileSeparator();
      sep[3] = '\0';
      if( StrOp.find( fileName, tracefile ) && StrOp.find( fileName, ".trc" ) ) {
        char* realpath = StrOp.fmt( "%s%c%s", protpath, SystemOp.getFileSeparator(), fileName );
        char* path = StrOp.fmt( "%s%s%c%s", absolute?sep:"", protpath, SystemOp.getFileSeparator(), fileName );
        char* encp = StrOp.encode4URL(path);
        long size  = FileOp.fileSize( realpath );
        long ftime = FileOp.fileTime( realpath );
        StrOp.replaceAll( path, '\\', '/' );

        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "add trace file: [%s]", path );

        iONode fileentry = NodeOp.inst(wFileEntry.name(), direntry, ELEMENT_NODE);
        wFileEntry.setfname(fileentry, FileOp.ripPath(path));
        wFileEntry.setsize(fileentry, size);
        wFileEntry.settime(fileentry,ctime(&ftime));
        NodeOp.addChild(direntry, fileentry);

        StrOp.free( encp );
        StrOp.free( path );
        StrOp.free( realpath );
      }
      /* Get the next directory entry. */
      fileName = DirOp.read( dir );
    };

    /* Close and cleanup. */
    DirOp.close( dir );
    dir->base.del( dir );
  }

  StrOp.free( protpath );

  return direntry;
}


static void __control_callback( obj inst, iONode nodeA ) {
  iOControlData data    = Data(inst);
  iOModel model         = AppOp.getModel();
  const char* nodeName  = NULL;
  int error             = 0;

  if( nodeA == NULL )
    return;

  nodeName  = NodeOp.getName( nodeA );

  TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "__callback..." );
  TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "nodeName=%s", nodeName );

  if( StrOp.equals( wBooster.name(), nodeName ) ) {
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "modify booster %s", wBooster.getid(nodeA) );
    ModelOp.cmd( AppOp.getModel(), nodeA );
  }
  else if( StrOp.equals( wIssue.name(), nodeName ) ) {
    __handleIssue(inst, nodeA);
    NodeOp.base.del( nodeA );
    return;
  }
  else if( StrOp.equals( wClock.name(), nodeName ) ) {
    if( StrOp.equals( wClock.getcmd(nodeA), wClock.freeze ) ) {
      if( data->devider > 1 ) {
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "freeze clock" );
        data->clockrun = False;
        /* broadcast to clients */
        {
          iONode tick = NodeOp.inst( wClock.name(), NULL, ELEMENT_NODE );
          wClock.setcmd( tick, wClock.freeze );
          wClock.setdivider( tick, data->devider );
          wClock.settime( tick, data->time );
          AppOp.broadcastEvent( tick );
        }
        {
          iONode tick = NodeOp.inst( wClock.name(), NULL, ELEMENT_NODE );
          wClock.setdivider( tick, data->devider );
          wClock.settime( tick, data->time );
          wClock.setcmd( tick, wClock.freeze );
          /* inform all digints */
          TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "inform all digints..." );
          ControlOp.cmd( (iOControl)inst, tick, NULL );
        }
      }
      else {
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "freeze/resume clock not possible with real time" );
      }
    }
    else if( StrOp.equals( wClock.getcmd(nodeA), wClock.go ) ) {
      if( data->devider > 1 ) {
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "resume clock" );
        data->clockrun = True;
        /* broadcast to clients */
        {
          iONode tick = NodeOp.inst( wClock.name(), NULL, ELEMENT_NODE );
          wClock.setcmd( tick, wClock.go );
          wClock.setdivider( tick, data->devider );
          wClock.settime( tick, data->time );
          wClock.settemp( tick, data->temp );
          AppOp.broadcastEvent( tick );
        }
        {
          iONode tick = NodeOp.inst( wClock.name(), NULL, ELEMENT_NODE );
          wClock.setdivider( tick, data->devider );
          wClock.settime( tick, data->time );
          wClock.setcmd( tick, wClock.go );
          wClock.settemp( tick, data->temp );
          /* inform all digints */
          TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "inform all digints..." );
          ControlOp.cmd( (iOControl)inst, tick, NULL );
        }
      }
      else {
        TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "freeze/resume clock not possible with real time" );
      }
    }
    else {
      iONode clockini = wFreeRail.getclock( AppOp.getIni() );
      if( clockini != NULL ) {
        if( wClock.getdivider(nodeA) > 0 )
          wClock.setdivider( clockini, wClock.getdivider(nodeA) );
      }
      if( wClock.getdivider(nodeA) > 0 )
        data->devider = wClock.getdivider(nodeA);

      if( wClock.gettime(nodeA) > 0 ) {
        data->time = wClock.gettime(nodeA);
      }
      else {
        struct tm* ltm = localtime( &data->time );
        ltm->tm_hour = wClock.gethour( nodeA );
        ltm->tm_min  = wClock.getminute( nodeA );
        ltm->tm_sec  = 0;
        data->time = mktime(ltm);
      }

      if( NodeOp.findAttr(nodeA, "temp") != NULL )
        data->temp = wClock.gettemp(nodeA);
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "setting time with devider %d", data->devider );
      data->timeset = True;
      {
        iONode tick = NodeOp.inst( wClock.name(), NULL, ELEMENT_NODE );
        wClock.setdivider( tick, data->devider );
        wClock.settime( tick, data->time );
        wClock.setcmd( tick, wClock.set );
        wClock.settemp( tick, data->temp );
        /* inform all digints */
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "inform all digints..." );
        ControlOp.cmd( (iOControl)inst, tick, NULL );
      }
    }
    NodeOp.base.del( nodeA );
    return;
  }
  else if( StrOp.equals( wSwitch.name(), nodeName ) ) {
    iOSwitch sw = ModelOp.getSwitch( model, wSwitch.getid( nodeA ) );
    if( sw != NULL ) {
      SwitchOp.cmd( sw, nodeA, True, 0, &error, NULL );
      return;
    }
  }
  else if( StrOp.equals( wSignal.name(), nodeName ) ) {
    iOSignal sg = ModelOp.getSignal( model, wSignal.getid( nodeA ) );
    if( sg != NULL ) {
      SignalOp.cmd( sg, nodeA, True );
      return;
    }
  }
  else if( StrOp.equals( wOutput.name(), nodeName ) ) {
    iOOutput co = ModelOp.getOutput( model, wOutput.getid( nodeA ) );
    if( co != NULL ) {
      OutputOp.cmd( co, nodeA, True );
      return;
    }
  }
  else if( StrOp.equals( wFeedback.name(), nodeName ) ) {
    iOFBack fb = ModelOp.getFBack( model, wFeedback.getid( nodeA ) );
    if( fb != NULL ) {
      FBackOp.cmd( fb, nodeA, True );
      return;
    }
  }
  else if( StrOp.equals( wRoute.name(), nodeName ) ) {
    iORoute route = ModelOp.getRoute( model, wRoute.getid( nodeA ) );
    if( route != NULL ) {
      RouteOp.cmd( route, nodeA );
      return;
    }
  }
  else if( StrOp.equals( wAction.name(), nodeName ) ) {
    iOAction action = ModelOp.getAction( model, wAction.getid( nodeA ) );
    if( action != NULL ) {
      ActionOp.cmd( action, nodeA );
      return;
    }
  }
  else if( StrOp.equals( wOperator.name(), nodeName ) ) {
    iOOperator opr = ModelOp.getOperator( model, wOperator.getid( nodeA ) );
    if( opr != NULL ) {
      OperatorOp.cmd( opr, nodeA );
      return;
    }
  }
  else if( StrOp.equals( wLoc.name(), nodeName ) ) {
    iOLoc loc = ModelOp.getLoc( model, wLoc.getid( nodeA ), nodeA, False );
    if( loc != NULL ) {
      LocOp.cmd( loc, nodeA );
      return;
    }
    else {
      iOCar car = ModelOp.getCar( model, wLoc.getid( nodeA ) );
      if( car == NULL )
        car = ModelOp.getCarByAddress( model, wLoc.getaddr( nodeA ), wLoc.getiid(nodeA) );
      if( car != NULL ) {
        CarOp.cmd( car, nodeA );
        return;
      }
      else {
        loc = ModelOp.getLoc( model, wLoc.getid( nodeA ), nodeA, True );
        if( loc != NULL ) {
          LocOp.cmd( loc, nodeA );
          return;
        }
      }
    }
  }
  else if( StrOp.equals( wDataReq.name(), nodeName ) ) {
    if( wDataReq.getcmd(nodeA) == wDataReq.get ) {
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "DataReq filename=[%s]", wDataReq.getfilename(nodeA) );
      if( wDataReq.gettype(nodeA) == wDataReq.image || wDataReq.gettype(nodeA) == wDataReq.smallimage ) {
        const char* imageFilename = FileOp.isAbsolute(wDataReq.getfilename(nodeA)) ? FileOp.ripPath(wDataReq.getfilename(nodeA)):wDataReq.getfilename(nodeA);

        if( wDataReq.getfilename(nodeA) != NULL && StrOp.len(wDataReq.getfilename(nodeA)) > 0 ) {
          iOFile f = NULL;
          Boolean smallimage = (wDataReq.gettype(nodeA) == wDataReq.smallimage) ? True:False;
          char* filename = StrOp.fmt( "%s%c%s", AppOp.getImgPath(), SystemOp.getFileSeparator(), imageFilename );
          char* sfilename = StrOp.fmt( "%s%csmall%c%s", AppOp.getImgPath(), SystemOp.getFileSeparator(), SystemOp.getFileSeparator(), imageFilename );
          char* ifilename = StrOp.fmt( "%s%c%s", AppOp.getIconPath(), SystemOp.getFileSeparator(), imageFilename );

          if( !wFreeRail.isfsutf8(AppOp.getIni()) ) {
            if( smallimage && FileOp.exist( sfilename ) ) {
              char* tmp = sfilename;
              sfilename = SystemOp.utf2latin(sfilename);
              StrOp.free(tmp);
            }
            else {
              char* tmp = filename;
              filename = SystemOp.utf2latin(filename);
              StrOp.free(tmp);
              tmp = ifilename;
              ifilename = SystemOp.utf2latin(ifilename);
              StrOp.free(tmp);
            }
          }

          if( smallimage && FileOp.exist( sfilename ) )
            f = FileOp.inst( sfilename, OPEN_READONLY);
          else if(FileOp.exist( filename ))
            f = FileOp.inst( filename, OPEN_READONLY);
          else if(FileOp.exist( ifilename ))
            f = FileOp.inst( ifilename, OPEN_READONLY);

          StrOp.free(filename);
          StrOp.free(sfilename);
          StrOp.free(ifilename);

          if( f == NULL ) {
            /* ToDo: Do a recursive search. */
            char* foundfilename = FileUtilsOp.findFile(AppOp.getImgPath(), imageFilename);
            if( FileOp.exist( foundfilename ) )
              f = FileOp.inst( foundfilename, OPEN_READONLY);
            StrOp.free(foundfilename);
          }

          if( f != NULL ) {
            int   size    = FileOp.size(f);
            TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "Server filename=[%s]", FileOp.getFilename(f) );
            if( size > 0 && size < (50*1024) ) {
              byte* buffer  = allocMem( size );
              char* byteStr = NULL;

              TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "reading %d bytes...", size );
              FileOp.read( f, (char*)buffer, size );
              FileOp.base.del(f);
              TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "convert %d bytes to string...", size );
              byteStr = StrOp.byteToStr( buffer, size );
              TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "free buffer..." );
              freeMem(buffer);
              TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "setdata..." );
              wDataReq.setdata( nodeA, byteStr );
              TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "free byteStr..." );
              StrOp.free( byteStr );
              TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "post event..." );
              ClntConOp.postEvent( AppOp.getClntCon(), nodeA, wCommand.getserver( nodeA ) );
              return;
            }
            else {
              TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "image file size out of range! [%d]", size );
              TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "post empty datareq..." );
              ClntConOp.postEvent( AppOp.getClntCon(), nodeA, wCommand.getserver( nodeA ) );
              return;
            }
          }
          else {
            TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "post empty datareq..." );
            ClntConOp.postEvent( AppOp.getClntCon(), nodeA, wCommand.getserver( nodeA ) );
            return;
          }
        }
        else {
          TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "empty image name..." );
          ClntConOp.postEvent( AppOp.getClntCon(), nodeA, wCommand.getserver( nodeA ) );
          return;
        }
      }
    }
    else if( wDataReq.getcmd(nodeA) == wDataReq.gettracedir ) {
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "DataReq trace directory" );
      iONode direntry = __scan4Trc((iOControl)inst);
      if( direntry != NULL ) {
        NodeOp.addChild( nodeA, direntry);
        ClntConOp.postEvent( AppOp.getClntCon(), nodeA, wCommand.getserver( nodeA ) );
      }
      return;
    }
    else if( wDataReq.getcmd(nodeA) == wDataReq.gettracefile ) {
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "DataReq trace filename=[%s]", wDataReq.getfilename(nodeA)!=NULL?wDataReq.getfilename(nodeA):"-" );
      if( wDataReq.getfilename(nodeA) == NULL || StrOp.len(wDataReq.getfilename(nodeA)) == 0 ) {
        wDataReq.setfilename(nodeA, TraceOp.getCurrentFilename(NULL));
      }

      if(wDataReq.getfilename(nodeA) != NULL &&  StrOp.len(wDataReq.getfilename(nodeA)) > 0 ) {
        char* text = __getTrcFile((iOControl)inst, wDataReq.getfilename(nodeA));
        if( text != NULL ) {
          wDataReq.setdata( nodeA, text );
          freeMem( text );
          ClntConOp.postEvent( AppOp.getClntCon(), nodeA, wCommand.getserver( nodeA ) );
        }
      }
      return;
    }
  }
  else if( StrOp.equals( wFunCmd.name(), nodeName ) ) {
    iOLoc loc = ModelOp.getLoc( model, wFunCmd.getid( nodeA ), NULL, False );
    if( loc != NULL ) {
      LocOp.cmd( loc, nodeA );
      return;
    }
    else {
      iOCar car = ModelOp.getCar( model, wFunCmd.getid( nodeA ) );
      if( car != NULL ) {
        CarOp.cmd( car, nodeA );
        return;
      }
    }
  }
  else if( StrOp.equals( wBlock.name(), nodeName ) ) {
    iIBlockBase block = ModelOp.getBlock( model, wBlock.getid( nodeA ) );
    if( block == NULL ) {
      block = ModelOp.getBlockByAddr( model, wBlock.getiid( nodeA ), wBlock.getaddr( nodeA ) );
    }

    if( block != NULL ) {
      block->cmd( block, nodeA );
      return;
    }
  }
  else if( StrOp.equals( wTurntable.name(), nodeName ) ) {
    iOTT tt = ModelOp.getTurntable( model, wTurntable.getid( nodeA ) );
    if( tt != NULL ) {
      TTOp.cmd( (iIBlockBase)tt, nodeA );
      return;
    }
  }
  else if( StrOp.equals( wSelTab.name(), nodeName ) ) {
    iOSelTab seltab = ModelOp.getSelectiontable( model, wSelTab.getid( nodeA ) );
    if( seltab != NULL ) {
      SelTabOp.cmd( (iIBlockBase)seltab, nodeA );
      return;
    }
  }
  else if( StrOp.equals( wStage.name(), nodeName ) ) {
    iOStage stage = ModelOp.getStage( model, wStage.getid( nodeA ) );
    if( stage != NULL ) {
      StageOp.cmd( (iIBlockBase)stage, nodeA );
      return;
    }
  }
  else if( StrOp.equals( wModelCmd.name(), nodeName ) ) {
    if( wModelCmd.getcmdfrom( nodeA ) != NULL )
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "command from [%s]", wModelCmd.getcmdfrom( nodeA ) );
    ModelOp.cmd( model, nodeA );
    return;
  }
  else if( StrOp.equals( wSysCmd.name(), nodeName ) ) {

    /* Update status */
    if( StrOp.equals( wSysCmd.go, wSysCmd.getcmd( nodeA ) ) ) {
      data->power = True;
    }
    else if( StrOp.equals( wSysCmd.stop, wSysCmd.getcmd( nodeA ) ) ) {
      data->power = False;
    }

    if( StrOp.equals( wSysCmd.enablecom, wSysCmd.getcmd( nodeA ) ) ) {
      data->enablecom = wSysCmd.getval(nodeA) == 1 ? True:False;
    }


    if( StrOp.equals( wSysCmd.shutdown, wSysCmd.getcmd( nodeA ) ) ) {
      /* TODO: Cleanup... */
      if( AppOp.isConsoleMode() ) {
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "Ignoring shutdown in console mode." );
        NodeOp.base.del( nodeA );
      }
      else {
        AppOp.shutdown(wSysCmd.getval( nodeA ), "System command");
      }
      return;
    }
    else if( StrOp.equals( wSysCmd.updateserver, wSysCmd.getcmd( nodeA ) ) ) {
      if( AppOp.isConsoleMode() ) {
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "Ignoring update server in console mode." );
        NodeOp.base.del( nodeA );
      }
      else {
        int revision = wSysCmd.getval(nodeA);
        char cmd[256] = {'\0'};
        TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "update the server software to revision %d...", revision);
        StrOp.fmtb(cmd, "nohup /opt/rocrail/update.sh %d %s %s &", revision, wSysCmd.getdist(nodeA), wSysCmd.getarch(nodeA) );
        SystemOp.system(cmd, True, True);
        NodeOp.base.del( nodeA );
      }
      return;
    }
    else if( StrOp.equals( wSysCmd.getini, wSysCmd.getcmd( nodeA ) ) ) {
      iONode ini = (iONode)NodeOp.base.clone( AppOp.getNewIni() );
      if( data->devlist == NULL ) {
        if( !wFreeRail.isnodevcheck(ini) )
          data->devlist = DevicesOp.getDevicesStr();
      }
      iONode devices = wFreeRail.getdevices(ini);
      if( devices == NULL ) {
        devices = NodeOp.inst( wDevices.name(), ini, ELEMENT_NODE );
        NodeOp.addChild( ini, devices );
      }
      wDevices.setserial(devices, data->devlist);
      ClntConOp.postEvent( AppOp.getClntCon(), ini, wCommand.getserver( nodeA ) );
      NodeOp.base.del( nodeA );
      return;
    }
    else if( StrOp.equals( wSysCmd.getmodplan, wSysCmd.getcmd( nodeA ) ) ) {
      iONode ini = (iONode)NodeOp.base.clone( ModelOp.getModPlan(model) );
      ClntConOp.postEvent( AppOp.getClntCon(), ini, wCommand.getserver( nodeA ) );
      NodeOp.base.del( nodeA );
      return;
    }
    else if( StrOp.equals( wSysCmd.getmodule, wSysCmd.getcmd( nodeA ) ) ) {
      iONode ini = (iONode)NodeOp.base.clone( ModelOp.getModule(model, wSysCmd.getid(nodeA)) );
      ClntConOp.postEvent( AppOp.getClntCon(), ini, wCommand.getserver( nodeA ) );
      NodeOp.base.del( nodeA );
      return;
    }
    else if( StrOp.equals( wSysCmd.setini, wSysCmd.getcmd( nodeA ) ) ) {
      iONode ini = NodeOp.getChild( nodeA, 0 );
      AppOp.setIni( ini );
      NodeOp.base.del( nodeA );
      /* inform the controller: could be an option store rerquest... */
      __informDigInts((iOControl)inst);
      return;
    }
    else if( StrOp.equals( wSysCmd.setmodplan, wSysCmd.getcmd( nodeA ) ) ) {
      iONode ini = NodeOp.getChild( nodeA, 0 );
      ModelOp.setModPlan( model, ini );
      NodeOp.base.del( nodeA );
      return;
    }
    else if( StrOp.equals( wSysCmd.setmodule, wSysCmd.getcmd( nodeA ) ) ) {
      iONode ini = NodeOp.getChild( nodeA, 0 );
      ModelOp.setModule( model, ini );
      NodeOp.base.del( nodeA );
      return;
    }
    else if( StrOp.equals( wSysCmd.grouplink, wSysCmd.getcmd( nodeA ) ) ) {
      iONode link = NodeOp.getChild( nodeA, 0 );
      if( link != NULL ) {
        /* TODO: but what? */
        __grouplink( inst, link );
      }
      NodeOp.base.del( nodeA );
      return;
    }
    else if( StrOp.equals( wSysCmd.analyze, wSysCmd.getcmd( nodeA ) ) ) {
      iOThread ana = ThreadOp.inst( NULL, __analyse, inst );
      ThreadOp.setStacksize(ana, 256 * 4096);
      __AnalyseMode = wSysCmd.getval( nodeA );
      NodeOp.base.del( nodeA );
      ThreadOp.start( ana );
      return;
    }
    else if( StrOp.equals( wSysCmd.txshortids, wSysCmd.getcmd(nodeA) ) ) {
      /* clear locodb and iterate all loco to send the shortid */
      /* start a thread to process this job */
      if( !data->txshortidsrun ) {
        data->txshortidsrun = True;
        data->txshortids = ThreadOp.inst( "txshortids", __txshortids, inst );
        ThreadOp.start( data->txshortids );
      }
      NodeOp.base.del( nodeA );
      return;
    }
    else if( StrOp.equals( wSysCmd.getstate, wSysCmd.getcmd(nodeA) ) ) {
      iONode stateevent = ControlOp.getState(AppOp.getControl());
      iONode autoevent = NodeOp.inst( wAutoCmd.name(), NULL, ELEMENT_NODE );
      wAutoCmd.setcmd( autoevent, ModelOp.isAuto(AppOp.getModel())?wAutoCmd.on:wAutoCmd.off );
      AppOp.broadcastEvent( stateevent );
      AppOp.broadcastEvent( autoevent );
      NodeOp.base.del( nodeA );
      return;
    }

  }
  else if( StrOp.equals( wAutoCmd.name(), nodeName ) ) {
    ModelOp.cmd( model, nodeA );
    return;
  }
  else if( StrOp.equals( wPlan.name(), nodeName ) ) {
    /* Serialize plan. */
    const char* fname = wPlan.getname( nodeA );
    char* xml = NodeOp.base.toString( nodeA );
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "Serialized Plan=%d", StrOp.len( xml ) );
    if( StrOp.len( xml ) > 0 )
    {
      iOFile planFile;

      planFile = FileOp.inst( fname, False );
      if( planFile != NULL ) {
        FileOp.write( planFile, xml, StrOp.len( xml ) );
        FileOp.close( planFile );
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "plan [%s] saved [%ld bytes].", fname, FileOp.getWritten( planFile ) );
        /* Cleanup. */
        planFile->base.del(planFile);
      }
    }
    StrOp.free( xml );
    NodeOp.base.del( nodeA );
    return;
  }
  else if( StrOp.equals( wProgram.name(), nodeName ) ) {
    if( wProgram.getcmd(nodeA) == wProgram.save ) {
      iOLoc loc = ModelOp.getLoc( model, wProgram.getfilename(nodeA), NULL, False );
      iOCar car = NULL;

      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "Program event %d: cv%d=%d addr=%d",
          wProgram.getcmd( nodeA ), wProgram.getcv( nodeA ), wProgram.getvalue( nodeA ), wProgram.getdecaddr( nodeA ) );

      if( loc == NULL )
        loc = ModelOp.getLocByAddress( model, wProgram.getaddr(nodeA), wProgram.getiid(nodeA) );
      if( loc != NULL ) {
        LocOp.setCV( loc, wProgram.getcv(nodeA), wProgram.getvalue(nodeA) );
      }
      if( loc == NULL ) {
        car = ModelOp.getCar( model, wProgram.getfilename(nodeA) );
        if( car != NULL ) {
          CarOp.setCV( car, wProgram.getcv(nodeA), wProgram.getvalue(nodeA) );
        }
      }
      if( loc == NULL && car == NULL ) {
        iONode dec = ModelOp.getDec( model, wProgram.getfilename(nodeA) );
        if( dec != NULL ) {
          DecOp.setCV( dec, wProgram.getcv(nodeA), wProgram.getvalue(nodeA) );
        }
      }

      ClntConOp.postEvent( AppOp.getClntCon(), (iONode)NodeOp.base.clone(nodeA), wCommand.getserver( nodeA ) );
      NodeOp.base.del( nodeA );
      return;
    }
    else if( wProgram.getcmd(nodeA) == wProgram.load ) {
      iOLoc loc = ModelOp.getLocByAddress( model, wProgram.getaddr(nodeA), wProgram.getiid(nodeA) );
      if( loc != NULL ) {
        int value = LocOp.getCV( loc, wProgram.getcv(nodeA) );
        wProgram.setvalue(nodeA, value);
      }
      ClntConOp.postEvent( AppOp.getClntCon(), (iONode)NodeOp.base.clone(nodeA), wCommand.getserver( nodeA ) );
      NodeOp.base.del( nodeA );
      return;
    }
    else {
      ControlOp.cmd( (iOControl)inst, nodeA, &error );
    }
    return;
  }

  ControlOp.cmd( (iOControl)inst, nodeA, &error );
}

static void __listener( obj inst, iONode nodeC, int level ) {
  iOControlData data = Data(inst);
  /* event from digitalInterface */
  /* inform model */
  iOModel model = AppOp.getModel(  );

  if( level == TRCLEVEL_EXCEPTION ) {
    TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, NodeOp.getStr( nodeC, "msg", "" ) );
    /*AppOp.stop(  );*/
  }

  if( nodeC == NULL )
    return;

  if( StrOp.equals( wResponse.name(), NodeOp.getName( nodeC ) ) ) {
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, NodeOp.getStr( nodeC, "msg", "--empty message--" ) );
  }

  if( StrOp.equals( wCommand.name(), NodeOp.getName( nodeC ) ) ) {
    /* command for another controller: */
    if( NodeOp.getChildCnt( nodeC ) > 0 ) {
      iONode cmd = NodeOp.getChild( nodeC, 0 );
      /* release the child node and delete the parent: */
      NodeOp.removeChild( nodeC, cmd );
      NodeOp.base.del(nodeC);
      ControlOp.cmd( (iOControl)inst, cmd, NULL );
    }
  }
  else if( StrOp.equals( wDigInt.name(), NodeOp.getName( nodeC ) ) ) {
    /* Broadcast to clients. Node3 */
    AppOp.broadcastEvent( nodeC );
  }
  else if( StrOp.equals( wProgram.name(), NodeOp.getName( nodeC ) ) ) {
    /* check if it is a multiport event */
    if( wProgram.getlntype(nodeC) == wProgram.lntype_mp ) {
      /* TODO: inform mp listeners */
    }

    /* Broadcast to clients. Node3 */
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "Program event %d: cv%d=%d addr=%d type=%d",
        wProgram.getcmd( nodeC ), wProgram.getcv( nodeC ), wProgram.getvalue( nodeC ), wProgram.getdecaddr( nodeC ), wProgram.getlntype( nodeC ) );
    AppOp.broadcastEvent( nodeC );
  }
  else if( StrOp.equals( wState.name(), NodeOp.getName( nodeC ) ) ) {
    /* Broadcast to clients. Node3 */
    wState.setconsolemode( nodeC, AppOp.isConsoleMode() );
    wState.sethealthy( nodeC, ModelOp.isHealthy(model) );

    if( wFreeRail.getclock(AppOp.getIni()) == NULL ) {
      iONode clock = NodeOp.inst(wClock.name(), AppOp.getIni(), ELEMENT_NODE);
      NodeOp.addChild(AppOp.getIni(), clock);
    }

    if( wClock.isstopclockatpoweroff(wFreeRail.getclock(AppOp.getIni())) && data->power && !wState.ispower( nodeC ) ) {
      /* freeze clock */
      if( data->clockrun ) {
        control_callback cb = ControlOp.getCallback((iOControl)inst);
        iONode clockcmd = NodeOp.inst( wClock.name(), NULL, ELEMENT_NODE );
        wClock.setcmd(clockcmd, wClock.freeze );
        TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "power off, freeze clock" );
        cb(inst,clockcmd);
      }
    }

    if( wState.isemergency(nodeC) ) {
      TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "controller reports emergency: power off, stop all" );
      AppOp.stop();
      if( AppOp.getModel() != NULL ) {
        iONode cmd = NodeOp.inst(wAutoCmd.name(), NULL, ELEMENT_NODE);
        wAutoCmd.setcmd(cmd, wAutoCmd.stop);
        ModelOp.cmd( AppOp.getModel(), cmd);
      }
    }

    data->programming  = wState.isprogramming( nodeC );
    data->trackbus     = wState.istrackbus( nodeC );
    data->sensorbus    = wState.issensorbus( nodeC );
    data->accessorybus = wState.isaccessorybus( nodeC );
    if( data->power != wState.ispower( nodeC )) {
      data->power = wState.ispower( nodeC );
      TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999,
          "State event from=%s: track power is %s",
          wState.getiid( nodeC )==NULL?"":wState.getiid( nodeC ), data->power?"ON":"OFF" );
    }

    if( data->powerman != NULL && wState.getuid(nodeC) > 0 ) {
      PowerManOp.base.event( data->powerman, nodeC);
    }

    if( wState.isshortcut(nodeC) ) {
      __checkAction((iOControl)inst, "short-circuit", "event");
    }

    AppOp.broadcastEvent( nodeC );
    __checkAction((iOControl)inst, data->power?wSysCmd.go:wSysCmd.stop, "event");

  }
  else
    ModelOp.event( model, nodeC );
}


static iONode _getState( iOControl inst ) {
  iOControlData data = Data(inst);
  iOModel model = AppOp.getModel();
  iONode node = NodeOp.inst( wState.name(), NULL, ELEMENT_NODE );
  wState.setpower( node, data->power );
  wState.setenablecom( node, data->enablecom );
  wState.setprogramming( node, data->programming );
  wState.settrackbus( node, data->trackbus );
  wState.setsensorbus( node, data->sensorbus );
  wState.setaccessorybus( node, data->accessorybus );
  wState.sethealthy( node, ModelOp.isHealthy(model) );
  wState.setneedkey4loconet( node, data->needkey4loconet );
  return node;
}


static void __informDigInts( iOControl inst ) {
  iOControlData o = Data(inst);
  iONode rsp = NULL;
  iONode ini    = AppOp.getNewIni();
  iONode digint = wFreeRail.getdigint( ini );
  while( digint != NULL ) {
    const char*  iid = wDigInt.getiid( digint );
    iIDigInt pDi = NULL;

    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999,
        "informDigInt [%s]...", iid!=NULL ? iid:"?" );

    if( iid != NULL ) {
      pDi = (iIDigInt)MapOp.get( o->diMap, iid );
      if( pDi != NULL ) {
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999,
            "informing fitting DigInt [%s]...", iid );
        pDi->cmd( (obj)pDi, (iONode)NodeOp.base.clone(digint) );
      }
    }

    digint = wFreeRail.nextdigint( ini, digint );
  };
}


static Boolean __initDigInts( iOControl inst ) {
  iOControlData o = Data(inst);
  iOModel model = AppOp.getModel();
  iONode ini    = AppOp.getIni();
  iONode plan   = ModelOp.getModel( model );
  iONode modeldigint = plan?wPlan.getdigint( plan ):NULL;
  iONode digint = wFreeRail.getdigint( ini );
  Boolean bModelDigints = modeldigint == NULL ? False:True;

  if( bModelDigints ) {
    digint = modeldigint;
  }

  if( digint == NULL ) {
    /* no digint specified */
    iONode virtual = NodeOp.inst( wDigInt.name(), ini, ELEMENT_NODE );
    wDigInt.setlib( virtual, wDigInt.vcs );
    wDigInt.setiid( virtual, "vcs-1" );
    NodeOp.addChild( ini, virtual );
    digint = virtual;
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "no digint defined; using default [virtual]" );
  }

  while( digint != NULL ) {
    /* TODO! Create Map with multiple digints; one is the default,
             others should be addressed with their iid.
             <system iid="p50_1" cmd="go"/>
    */
    const char*  lib = wDigInt.getlib( digint );
    const char*  iid = wDigInt.getiid( digint );
    iIDigInt pDi = NULL;
    iOLib    pLib = NULL;
    LPFNROCGETDIGINT pInitFun = (void *) NULL;

    o->needkey4loconet = False;
    wDigInt.setrestricted(digint, False);

    if( StrOp.equals( wDigInt.lenz, lib ) ) {
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "set lib from [lenz] to [xpressnet]" );
      lib = wDigInt.xpressnet;
    }

    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "initDigInts lib=\"%s\" idd=\"%s\"", lib, iid!=NULL ? iid:"?" );

    wDigInt.setstress( digint, AppOp.isStress());

    wDigInt.setlibpath( digint, AppOp.getLibPath() );
    {
      char* libpath = StrOp.fmt( "%s%c%s", AppOp.getLibPath(), SystemOp.getFileSeparator(), lib );
      pLib = LibOp.inst( libpath );
      StrOp.free( libpath );
    }


    if (pLib == NULL)
      return False;
    pInitFun = (LPFNROCGETDIGINT)LibOp.getProc(pLib,"rocGetDigInt");
    if (pInitFun == NULL)
      return False;
    pDi = pInitFun(digint,TraceOp.get());

    if (pDi == NULL) {
      return False;
    }
    else {
      /* vmajor*10000 + vminor*100 */
      int libVersion = pDi->version((obj)pDi);
      int vmajor = libVersion/10000;
      int vminor = (libVersion%10000)/100;
      if( vmajor != wGlobal.vmajor || vminor != wGlobal.vminor ) {
        TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999,
            "version mismatch for library [%s]; reports:[%d.%d] wanted:[%d.%d]", lib, vmajor, vminor, wGlobal.vmajor, wGlobal.vminor );
        pDi->halt((obj)pDi, True, False );
        return False;
      }
    }

    pDi->setListener( (obj)pDi, (obj)inst, &__listener );

    if( iid != NULL )
      MapOp.put( o->diMap, iid, (obj)pDi );

    if( wDigInt.islocolist(digint)) {
      iONode lclist = wPlan.getlclist(ModelOp.getModel(AppOp.getModel()));
      if( lclist != NULL ) {
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "send loco list to digint...");
        lclist = (iONode)NodeOp.base.clone(lclist);
        pDi->cmd((obj)pDi, lclist);
      }
    }
    if( wDigInt.isswitchlist(digint)) {
      iONode swlist = wPlan.getswlist(ModelOp.getModel(AppOp.getModel()));
      if( swlist != NULL ) {
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "send switch list to digint...");
        swlist = (iONode)NodeOp.base.clone(swlist);
        pDi->cmd((obj)pDi, swlist);
      }
    }

    /* First digint is default! */
    if( o->pDi == NULL ) {
      o->pDi = pDi;
      o->iid = iid != NULL ? iid:"default";
    }

    if( bModelDigints )
      digint = wPlan.nextdigint( ModelOp.getModel( model ), digint );
    else

      digint = wFreeRail.nextdigint( ini, digint );
  };

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "initDigInts OK" );
  return True;
}

/*
 ***** _Public functions.
 */
static control_callback _getCallback( iOControl inst ) {
  iOControlData data = Data(inst);
  return &__control_callback;
}

static void _halt( iOControl inst ) {
  if( inst != NULL ) {
    iOControlData data = Data(inst);

    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "Shutting down..." );

    ThreadOp.requestQuitAll();

    /* Inform DigInts. */
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "Informing interfaces..." );
    {
      iIDigInt di = (iIDigInt)MapOp.first( data->diMap );
      while( di != NULL ) {
        di->halt((obj)di, wFreeRail.ispoweroffonexit(AppOp.getIni()), wFreeRail.isshutdownonexit(AppOp.getIni()) );
        di = (iIDigInt)MapOp.next( data->diMap );
      }
    }
  }
}

static const char* _getIid( iOControl inst ) {
  iOControlData data = Data(inst);
  return data->iid;
}

static long _getTime( iOControl inst ) {
  iOControlData data = Data(inst);
  return data->time;
}

static void _setTime( iOControl inst, long p_Time ) {
  iOControlData data = Data(inst);
  data->time = p_Time;
}

/* Model seconds */
static void __checkActions( iOControl control, int seconds ) {
  iOModel model = AppOp.getModel();
  iOControlData data = Data(control);

  char state[64] = {'\0'};
  struct tm* ltm = localtime( &data->time );
  StrOp.fmtb(state, "%02d:%02d", ltm->tm_hour, ltm->tm_min );

  if( model != NULL ) {
    iONode plan   = ModelOp.getModel( model );
    if( plan != NULL ) {
      iONode aclist = wPlan.getaclist(plan);
      iONode varlist = wPlan.getvrlist(plan);
      if( aclist != NULL ) {
        iONode action = wActionList.getac( aclist );
        while( action != NULL ) {
          iOAction act = ModelOp.getAction(model, wAction.getid(action));
          if( act != NULL )
            ActionOp.tick(act, seconds);
          action = wActionList.nextac( aclist, action );
        };
      }
      if( varlist != NULL ) {
        iONode var = wVariableList.getvr( varlist );
        while( var != NULL ) {
          if( wVariable.istimer(var) ) {
            wVariable.setvalue(var, wVariable.getvalue(var) + 1);
            VarOp.checkActions(var);
          }
          var = wVariableList.nextvr( varlist, var );
        };
      }

      if( seconds == 60 ) {
        iONode system = wPlan.getsystem(plan);
        if( system != NULL ) {
          iONode action = wSystemActions.getactionctrl(system);
          /* loop over all actions */
          while( action != NULL ) {
            if( StrOp.equals(state, wActionCtrl.getstate( action )) )
            {
              iOAction Action = ModelOp.getAction(model, wActionCtrl.getid( action ));
              if( Action != NULL ) {
                ActionOp.exec(Action, action);
              }
            }
            else {
              TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "action state does not match: [%s-%s]",
                  wActionCtrl.getstate( action ), state );
            }
            action = wSystemActions.nextactionctrl( system, action );
          }
        }
      }

    }
  }

}



static void __checkAction( iOControl inst, const char* cmd, const char* by ) {
  iOControlData data   = Data(inst);
  iOModel       model  = AppOp.getModel();
  char state[64];
  if( StrOp.equals(cmd, wSysCmd.go) || StrOp.equals(cmd, wSysCmd.stop) )
    StrOp.fmtb(state, "%s-%s", cmd, by);
  else
    StrOp.fmtb(state, "%s", cmd);

  if( model != NULL ) {
    iONode plan   = ModelOp.getModel( model );
    if( plan != NULL ) {
      iONode system = wPlan.getsystem(plan);
      if( system != NULL ) {
        iONode action = wSystemActions.getactionctrl(system);
        /* loop over all actions */
        while( action != NULL ) {
          if( StrOp.equals(state, wActionCtrl.getstate( action )) )
          {
            iOAction Action = ModelOp.getAction(model, wActionCtrl.getid( action ));
            if( Action != NULL ) {
              ActionOp.exec(Action, action);
            }
          }
          else {
            TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "action state does not match: [%s-%s]",
                wActionCtrl.getstate( action ), state );
          }

          action = wSystemActions.nextactionctrl( system, action );
        }
      }
    }
  }
}






static void __clockticker( void* threadinst ) {
  iOThread        th = (iOThread)threadinst;
  iOControl  control = (iOControl)ThreadOp.getParm(th);
  iOControlData data = Data(control);
  iONode         ini = AppOp.getIni();
  iONode    clockini = wFreeRail.getclock( ini );
  int        seconds = 0;
  Boolean    timeset = False;
  Boolean  firstsync = True;
  int         update = 1;
  int   updateticker = 0;

  data->time = time(NULL);
  data->devider = 1;
  data->temp = 20;

  if( clockini == NULL ) {
    clockini = NodeOp.inst( wClock.name(), ini, ELEMENT_NODE );
    NodeOp.addChild( ini, clockini );
  }
  data->devider = wClock.getdivider( clockini );
  update = wClock.getupdate( clockini );
  if( data->devider > 1 && wClock.gethour( clockini ) < 24 && wClock.getminute( clockini ) < 60 ) {
    struct tm* ltm = localtime( &data->time );
    ltm->tm_hour = wClock.gethour( clockini );
    ltm->tm_min  = wClock.getminute( clockini );
    ltm->tm_sec  = 0;
    data->time = mktime(ltm);
    ltm = localtime( &data->time );
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "Using saved time %d:%02d (%d:%02d)", ltm->tm_hour, ltm->tm_min, wClock.gethour( clockini ), wClock.getminute( clockini ) );
  }

  if( data->devider > 100 || data->devider < 1 ) {
    TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "ClockTicker: unexpected devider value [%d] reset to [1].", data->devider );
    data->devider = 1;
  }

  if( update > 60 || update < 1 ) {
    TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "ClockTicker: unexpected update value [%d] reset to [1].", update );
    update = 1;
  }

  struct tm lTime = *localtime( &data->time );
  seconds = lTime.tm_sec;

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "ClockTicker started." );

  while( !ThreadOp.isQuit(th) ) {

    /* 1=1000, 2=500, 4=250, 5=200, 10=100, 20=50, 25=40, 40=25, 50=20 100=10 */
    ThreadOp.sleep( 1000 / data->devider );

    if( data->clockrun ) {
      if( data->devider > 1 )
        data->time += 1;
      else {
        if( abs((int)(data->time - time(NULL))) > 60 )
          data->time += 1;
        else
          data->time = time(NULL);
      }
    }

    if( !wCtrl.isactiontimer60( wFreeRail.getctrl( AppOp.getIni() ) ) ) {
      __checkActions( control, 1 );
    }

    if( data->timeset ) {
      wClock.setdivider( clockini, data->devider );
      timeset = True;
      data->timeset = False;
      firstsync = True;
      seconds = 1;
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "ClockTicker time set." );
    }
    else if( data->clockrun ) {
      seconds++;
      if( !firstsync && seconds < 60 )
        continue;
    }
    else if(!firstsync) {
      continue;
    }

    /* reached every 60 ticks only (or firstsync or data->timeset) */

    if( !firstsync )
      seconds = 0;

    updateticker++;

    if( wCtrl.isactiontimer60( wFreeRail.getctrl( AppOp.getIni() ) ) )
      __checkActions( control, 60 );

    if( firstsync || updateticker >= update ) {
      struct tm* ltm = localtime( &data->time );

      iONode tick = NodeOp.inst( wClock.name(), NULL, ELEMENT_NODE );
      wClock.setdivider( tick, data->devider );
      wClock.settime( tick, data->time );
      wClock.settemp( tick, data->temp );
      wClock.setcmd( tick, firstsync ? wClock.set:wClock.sync );
      AppOp.broadcastEvent( (iONode)NodeOp.base.clone(tick) );
      /* inform all digints */
      TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "new clock event %d:%02d.%02d", ltm->tm_hour, ltm->tm_min, ltm->tm_sec );
      ControlOp.cmd( control, tick, NULL );
      updateticker = 0;
    }

    if( firstsync )
      firstsync = False;

    lTime = *localtime( &data->time );
    wClock.sethour( clockini, lTime.tm_hour );
    wClock.setminute( clockini, lTime.tm_min );
  };

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "ClockTicker ended." );
}


static void __checker( void* threadinst ) {
  iOThread        th = (iOThread)threadinst;
  iOControl  control = (iOControl)ThreadOp.getParm(th);
  iOControlData data = Data(control);
  iONode         ini = AppOp.getIni();
  iOModel      model = AppOp.getModel();
  iOMap        swMap = NULL;

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "Checker started." );

  ThreadOp.sleep( 1000 );
  swMap = ModelOp.getSwitchMap(model);
  while( !ThreadOp.isQuit(th) ) {

    /* call the switches every 100 ms */
    ThreadOp.sleep( 100 );

    /* only in automode to make sure there are no edits on the map */
    if( ModelOp.isAuto(model) ) {
      iOSwitch sw = (iOSwitch)MapOp.first( swMap );

      while( sw != NULL && ModelOp.isAuto(model) ) {
        /* call the switch */
        SwitchOp.checkSenPos( sw );
        sw = (iOSwitch)MapOp.next( swMap );
      };
    }

  };

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "Checker ended." );
}

static iOR2Rnet _getR2Rnet(iOControl control) {
  iOControlData data = Data(control);
  return data->r2rnet;
}

static void _setBoosters(iOControl control, iONode ini) {
  iOControlData data = Data(control);
  if( data->powerman == NULL )
    data->powerman = PowerManOp.inst(ini);
  else
    PowerManOp.modify(data->powerman, ini);
}


static Boolean _power4Block(iOControl control, const char* blockid, Boolean on) {
  iOControlData data = Data(control);
  if( data->powerman == NULL )
    return False;
  else {
    iONode cmd = NodeOp.inst(wPwrCmd.name(), NULL, ELEMENT_NODE);
    wPwrCmd.setblockid(cmd, blockid);
    wPwrCmd.setcmd(cmd, on?wPwrCmd.on:wPwrCmd.off);
    return PowerManOp.cmd(data->powerman, cmd );
  }
}


static Boolean _hasBlockPower(iOControl control, const char* blockid) {
  iOControlData data = Data(control);
  if( data->powerman == NULL )
    return True;
  else {
    return PowerManOp.hasBlockPower(data->powerman, blockid );
  }
}


static iOControl _inst( Boolean nocom ) {
    iOControl     control = allocMem( sizeof( struct OControl ) );
    iOControlData data    = allocMem( sizeof( struct OControlData ) );
    iONode        ini     = AppOp.getIni();

    /* OBase operations */
    MemOp.basecpy( control, &ControlOp, 0, sizeof( struct OControl ), data );

    data->diMap = MapOp.inst();
    data->enablecom = True;

    if( !wFreeRail.isnodevcheck(ini) )
      data->devlist = DevicesOp.getDevicesStr();

    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "devices: \"%s\"", data->devlist );

    if( !nocom ) {
      if( __initDigInts( control ) ) {
        __checkAction(control, wSysCmd.init, "event");
      }
    }

    {
      iOModel model = AppOp.getModel();
      if( model != NULL) {
        iONode plan = ModelOp.getModel( model );
        if( plan != NULL) {
          if( wPlan.getboosterlist(plan) == NULL ) {
            iONode boosterlist = NodeOp.inst( wBoosterList.name(), NULL, ELEMENT_NODE);
            NodeOp.addChild(plan, boosterlist);
          }
          ControlOp.setBoosters(control, wPlan.getboosterlist(plan));
        }
      }
    }




    data->clockrun = True;
    data->clockticker = ThreadOp.inst( "clockticker", __clockticker, control );
    ThreadOp.start( data->clockticker );

    data->checker = ThreadOp.inst( "checker", __checker, control );
    ThreadOp.start( data->checker );

    __initSensors(control);

    if( wFreeRail.getr2rnet(ini) != NULL && wR2RnetIni.isenable(wFreeRail.getr2rnet(ini))) {
      data->r2rnet = R2RnetOp.inst(wFreeRail.getr2rnet(ini));
    }


    instCnt++;

  return control;
}


/* ----- DO NOT REMOVE OR EDIT THIS INCLUDE LINE! -----*/
#include "rocrail/impl/control.fm"
/* ----- DO NOT REMOVE OR EDIT THIS INCLUDE LINE! -----*/
