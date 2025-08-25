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
#ifndef __ROCRAIL_rocgui_GUIAPP_H
#define __ROCRAIL_rocgui_GUIAPP_H


#include "rocs/public/rocs.h"
#include "rocs/public/cmdln.h"
#include "rocs/public/doc.h"
#include "rocs/public/node.h"
#include "rocs/public/list.h"
#include "rocs/public/trace.h"
#include "rocs/public/res.h"
#include "rocs/public/wrpinf.h"
#include "rocs/public/map.h"

#include "rocrail/public/rcon.h"

#include "rocview/public/guiframe.h"
#include "rocview/public/planpanel.h"

#include "rocrail/public/script.h"

#if !WXWIN_COMPATIBILITY_2_8
    #define wxADJUST_MINSIZE _Pragma ("GCC warning \"'wxADJUST_MINSIZE' is deprecated\"") 0
#endif

enum {
  PT_EVENT = 20001,
};

class RocGui : public wxApp {
public:
  RocGui();
  virtual bool OnInit();
  virtual int OnExit();
  int getItemSize();
  void sendToRocrail( iONode cmd, bool close=false );
  bool sendToRocrail( char* szCmd, bool wait4rr=false, bool close=false, bool showpopup=true );
  RocGuiFrame* getFrame() { return m_Frame; }
  void setHost( const char* hostname, int port) { m_Host = hostname; m_Port = port; }
  void setModel( iONode node );
  iONode getModel(bool create=true);
  bool isModelSet();
  iONode getIni() { return m_Ini; }
  bool hasUndoItems() { return ListOp.size(m_UndoItems) > 0; }
  iOList getUndoItems() { return m_UndoItems; }
  void pushUndoItem( iONode item );
  iONode popUndoItem();
  bool isOffline() { return m_bOffline; }
  bool isConsoleMode() { return m_bConsoleMode; }
  void setConsoleMode(bool consolemode) { m_bConsoleMode = consolemode; }
  bool isStayOffline() { return m_bStayOffline; }
  void setStayOffline( bool stay ) { m_bStayOffline = stay; }
  void disConnect();
  wxString getMsg( const char* key );
  const char* getCMsg( const char* key );
  wxString getTip( const char* key );
  wxString getMenu( const char* key );
  void openLink( const char* pagename, const char* section=NULL );
  iONode getWrpInf( const char* wrpname );
  void Callback( obj me, iONode node );
  void cleanupOldModel();
  void setLocalModelModified(bool modified=true){m_LocalModelModified=modified;}
  bool isLocalModelModified(){return m_LocalModelModified;}
  int getTabAlign();
  int getRevisionNr() { return m_RevisionNr; }
  const char* getCommitHash() { return m_CommitHash; }
  int getTabSel() { return m_TabSel; }
  int getLocoTabSel() { return m_LocoTabSel; }
  bool isModView() { return m_bModView; }
  void setModView(bool modview) { m_bForceTabView ?  m_bModView = false:m_bModView = modview; }
  bool isInit() { return m_bInit; }
  bool isRestrictedEdit();
  bool isForceTabView() { return m_bForceTabView; }
  bool isTabViewRotated() { return m_bTabViewRotated; }
  const char* findID(bool output, int addr, int bus=0, int porttype=0, const char** type=NULL);
  iOScript getScript(){return m_Script;}
  iOList getSensorEvents(){return m_SensorEvents;}
  void sensorEvent(iONode event);
  void setSensorEventListener(wxDialog* listener) {m_SensorEventListener=listener;}
#ifdef __APPLE__
  void MacOpenFile( const wxString& fileName);
#endif

  iORCon        m_RCon;
  const char*   m_Host;
  int           m_Port;
  int           m_RevisionNr;
  const char*  m_CommitHash;
  iONode        m_Ini;
  RocGuiFrame*  m_Frame;
  bool          m_bOffline;
  bool          m_bConsoleMode;
  bool          m_InitialRocrailIni;
  bool          m_FireBiDiB4RocrailIni;
  bool          m_FireRocNet4RocrailIni;
  iOScript       m_Script;

private:
  void saveSizePos();
  void readArgs(const char* langfile);
  wxString      m_LocalPlan;

  const char*   m_IniFileName;
  iOCmdLn       m_CmdLn;
  iOTrace       m_Trace;
  iONode        m_Model;
  iOList        m_UndoItems;
  iONode        m_OldModel;
  int           m_TabSel;
  int           m_LocoTabSel;
  bool          m_bOnExit;
  bool          m_bStayOffline;
  bool          m_LocalModelModified;
  bool          m_bModView;
  bool          m_bForceTabView;
  bool          m_bTabViewRotated;
  iORes         m_Res;
  iOWrpInf      m_WrpInf;
  bool          m_bInit;
  iOList        m_SensorEvents;
  wxDialog*     m_SensorEventListener;
};
DECLARE_APP(RocGui)





#endif
