/*
 Rocrail - Model Railroad Software

 Copyright (C) 2002-2014 Rob Versluis, Rocrail.net

 


 This program is free software; you can redistribute it and/or
 as published by the Free Software Foundation; either version 2
 modify it under the terms of the GNU General Public License
 of the License, or (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/

#include "locowidget.h"

#include <wx/dataobj.h>
#include <wx/dnd.h>

#include "rocrail/wrapper/public/Loc.h"
#include "rocrail/wrapper/public/DataReq.h"
#include "rocrail/wrapper/public/Item.h"
#include "rocrail/wrapper/public/Schedule.h"
#include "rocrail/wrapper/public/Tour.h"

#include "rocview/public/guiapp.h"

#include "rocview/wrapper/public/Gui.h"
#include "rocview/wrapper/public/MIC.h"

#include "rocview/dialogs/locdialog.h"
#include "rocview/dialogs/gotodlg.h"
#include "rocview/dialogs/scheduledialog.h"
#include "rocview/dialogs/toursdlg.h"
#include "rocview/dialogs/throttledlg.h"

#include "rocs/public/file.h"
#include "rocs/public/system.h"

#include "rocview/public/base.h"

#include "rocview/xpm/nopict12030.xpm"

LocoWidget::LocoWidget( wxWindow* parent, iONode props, int width ):LocoWidgetGen( parent )
{
  SetMinSize( wxSize( width,-1 ) );
  SetMaxSize( wxSize( width,-1 ) );

  m_Props = props;
  m_Pixpath[0] = '\0';
  m_hasImageRequested = false;
  UpdateLocoImg();
  InitLoco();
}

void LocoWidget::InitLoco() {
  char id[32];
  StrOp.fmtb(id, "%.20s", wLoc.getid( m_Props ));
  m_ID->SetLabel(wxString(wLoc.getid( m_Props ),wxConvUTF8));

  // Set the window name to get it findable by parent->FindWindowByName(name)
  SetName(m_ID->GetLabel());

  m_Block->SetLabel(_T(""));
  m_Destination->SetLabel(_T(""));
  UpdateLoco(m_Props);
}


void LocoWidget::UpdateLoco(iONode node) {
  TraceOp.trc( "locowidget", TRCLEVEL_INFO, __LINE__, 9999, "update [%s] addr=%d", wLoc.getid( node ), wLoc.getaddr( node) );

  if( wLoc.getsecaddr( m_Props) == wLoc.getaddr( node) || wLoc.isusesecaddr( node)  )  {
    // ignore secondary address
    return;
  }

  Boolean dir = wLoc.isdir(node);
  Boolean placing = wLoc.isplacing(node);
  char* val = StrOp.fmt( "%s%s%d%s", dir?"":"<", placing?"":"-", wLoc.getV( node )==-1?0:wLoc.getV( node ), dir?">":"" );
  m_Speed->SetLabel( wxString(val,wxConvUTF8) );
  StrOp.free( val );
  m_Speed->SetBackgroundColour( wLoc.isplacing(node)?GetBackgroundColour():wxColour(240,200,200));

  m_Stop->SetBackgroundColour( (wLoc.getV( node ) > 0) ? Base::getRed():wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW) );
  m_Stop->SetLabel( (wLoc.getV( node ) > 0) ? _T("X"):_T("") );

  wLoc.setV( m_Props, wLoc.getV( node ) );
  TraceOp.trc( "locowidget", TRCLEVEL_INFO, __LINE__, 9999, "update loco V=%d", wLoc.getV( m_Props ) );


  const char* blockid = wLoc.getblockid( node );
  if( blockid == NULL || StrOp.len(blockid) == 0 )
    blockid = "?";

  m_Block->SetLabel( (wLoc.isblockenterside(node)?_T(""):_T("-")) + wxString(blockid,wxConvUTF8) );


  if(!wLoc.isactive(node))
    m_Mode->SetLabel( _T("hold") );
  else if( wLoc.ismanual(node))
    m_Mode->SetLabel( _T(">") + wxString(wLoc.getmode( node ),wxConvUTF8) );
  else
    m_Mode->SetLabel( wxString(wLoc.isresumeauto( node ) ? "*":"",wxConvUTF8) + wxString(wLoc.getmode( node ),wxConvUTF8) );

  m_Mode->SetBackgroundColour( GetBackgroundColour());
  if( StrOp.equals( wLoc.mode_auto, wLoc.getmode( node ) ) ) {
    m_Mode->SetBackgroundColour( Base::getRes2Color() );
  }
  else if( StrOp.equals( wLoc.mode_wait, wLoc.getmode( node ) ) ) {
    m_Mode->SetBackgroundColour( Base::getBlue());
  }
  else if(!wLoc.isactive(node))
    m_Mode->SetBackgroundColour( Base::getNoneActiveColor());


  const char* destblockid = wLoc.getdestblockid( node );
  if( destblockid == NULL || StrOp.len(destblockid) == 0 )
    destblockid = "-";

  if( wLoc.getscidx(node) == -1 )
    m_Destination->SetLabel( wxString(destblockid,wxConvUTF8) );
  else if( wLoc.getdestblockid( node ) != NULL ) {
    val = StrOp.fmt( "[%s:%d] %s", wLoc.getscheduleid(node), wLoc.getscidx( node ), destblockid );
    m_Destination->SetLabel( wxString(val,wxConvUTF8) );
    StrOp.free( val );
  }

  Layout();
}


void LocoWidget::UpdateLocoImg(){
  // Get copied node:
  if( wLoc.getimage( m_Props ) != NULL && StrOp.len(wLoc.getimage( m_Props )) > 0 ) {
    wxBitmapType bmptype = wxBITMAP_TYPE_XPM;
    if( StrOp.endsWithi( wLoc.getimage( m_Props ), ".gif" ) )
      bmptype = wxBITMAP_TYPE_GIF;
    else if( StrOp.endsWithi( wLoc.getimage( m_Props ), ".png" ) )
      bmptype = wxBITMAP_TYPE_PNG;
    else {
      m_LocoImage->SetBitmap( wxBitmap(nopict12030_xpm) );
      m_LocoImage->Refresh();
      TraceOp.trc( "locowidget", TRCLEVEL_WARNING, __LINE__, 9999, "unsupported image format %s", wLoc.getimage( m_Props ) );
      return;
    }

    TraceOp.trc( "locowidget", TRCLEVEL_INFO, __LINE__, 9999, "UpdateLocImage %s", wLoc.getimage( m_Props ) );

    const char* imagepath = wGui.getimagepath(wxGetApp().getIni() );
    StrOp.fmtb( m_Pixpath, "%s%c%s", imagepath, SystemOp.getFileSeparator(), FileOp.ripPath( wLoc.getimage( m_Props ) ) );

    if( FileOp.exist(m_Pixpath)) {
      wxBitmap bmp = scale(wxBitmap(wxString(m_Pixpath,wxConvUTF8), bmptype), 120, 30);
      m_LocoImage->SetBitmap( bmp );
    }
    else if(!m_hasImageRequested) {
      m_hasImageRequested = true;
      m_LocoImage->SetBitmap( wxBitmap(nopict12030_xpm) );
      // request the image from server:
      iONode node = NodeOp.inst( wDataReq.name(), NULL, ELEMENT_NODE );
      wDataReq.setid( node, wLoc.getid(m_Props) );
      wDataReq.setcmd( node, wDataReq.get );
      wDataReq.settype( node, wDataReq.image );
      wDataReq.setfilename( node, wLoc.getimage(m_Props) );
      wxGetApp().sendToRocrail( node );
    }
  }
  else
    m_LocoImage->SetBitmap( wxBitmap(nopict12030_xpm) );

  m_LocoImage->Refresh();

  m_LocoImage->SetToolTip(wxString(wLoc.getid( m_Props ),wxConvUTF8) + _T(" ") + wxString(wLoc.getdesc( m_Props ),wxConvUTF8));
  Layout();
}



wxBitmap LocoWidget::scale(wxBitmap bmp,  int max_width, int max_height) {
    int original_width, original_height;

    original_width = bmp.GetWidth();
    original_height = bmp.GetHeight();

    if( original_width <= max_width && original_height <= max_height ) {
      return bmp;
    }

    wxBitmap result;

    // Regard aspect ratio.
    float ws = (float)original_width / (float)max_width;
    float hs = (float)original_height / (float)max_height;

    wxImage img = bmp.ConvertToImage(); // create an image of the bitmap
    if( ws > hs ) {
      result = wxBitmap(img.Rescale((int)((float)original_width/ws), (int)((float)original_height/ws)));
    }
    else {
      result = wxBitmap(img.Rescale((int)((float)original_width/hs), (int)((float)original_height/hs)));
    }

    return result;
}


void LocoWidget::onThrottle( wxMouseEvent& event ) {
  ThrottleDlg* dlg = new ThrottleDlg(this, wxGetApp().getFrame()->m_ThrottleList, wxGetApp().getFrame()->m_LocDlgMap, wLoc.getid(m_Props));
  dlg->Show(TRUE);
}


void LocoWidget::onPopUp( wxMouseEvent& event ) {
  wxMenu menu( m_ID->GetLabel() );
  menu.Append( ME_GridLocGo, wxGetApp().getMenu("start"), wxGetApp().getTip("start"));
  menu.Connect( ME_GridLocGo, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LocoWidget::onMenuStart ), NULL, this );
  wxMenuItem *mi = menu.FindItem( ME_GridLocGo );
  mi->Enable( wxGetApp().getFrame()->isAutoMode() );
  menu.Append( ME_GridLocStop, wxGetApp().getMenu("stop"), wxGetApp().getTip("stop"));
  menu.Connect( ME_GridLocStop, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LocoWidget::onMenuStop ), NULL, this );
  menu.AppendSeparator();

  menu.Append( ME_GridLocReset, wxGetApp().getMenu("softresetall"), wxGetApp().getTip("softresetall") );
  menu.Connect( ME_GridLocReset, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LocoWidget::onMenuSoftReset ), NULL, this );
  menu.Append( ME_GridLocResetAll, wxGetApp().getMenu("resetall"), wxGetApp().getTip("resetall") );
  menu.Connect( ME_GridLocResetAll, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LocoWidget::onMenuResetAll ), NULL, this );
  menu.Append( ME_GridLocSwap, wxGetApp().getMenu("swapplacing"), wxGetApp().getTip("swapplacing") );
  menu.Connect( ME_GridLocSwap, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LocoWidget::onMenuSwap ), NULL, this );
  menu.Append( ME_GridLocSwapBlockSide, wxGetApp().getMenu("swapblockenterside"), wxGetApp().getTip("swapblockenterside") );
  menu.Connect( ME_GridLocSwapBlockSide, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LocoWidget::onMenuSwapBlockSide ), NULL, this );

  menu.AppendSeparator();
  menu.Append( ME_GridLocGoTo, wxGetApp().getMenu("gotoblock"), wxGetApp().getTip("gotoblock") );
  menu.Connect( ME_GridLocGoTo, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LocoWidget::onMenuGoTo ), NULL, this );
  menu.Append( ME_GridLocSchedule, wxGetApp().getMenu("selectschedule"), wxGetApp().getTip("selectschedule") );
  menu.Connect( ME_GridLocSchedule, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LocoWidget::onMenuSchedule ), NULL, this );
  menu.Append( ME_GridLocTour, wxGetApp().getMenu("selecttour"), wxGetApp().getTip("selecttour") );
  menu.Connect( ME_GridLocTour, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LocoWidget::onMenuTour ), NULL, this );

  menu.AppendSeparator();
  mi = menu.Append( ME_GridLocProps, wxGetApp().getMsg("properties") );
  menu.Connect( ME_GridLocProps, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LocoWidget::onMenuProps ), NULL, this );
  mi->Enable( !wxGetApp().getFrame()->isAutoMode() || !wxGetApp().isRestrictedEdit() );
  PopupMenu(&menu );
}

void LocoWidget::onMenuProps(wxCommandEvent& event) {
  LocDialog*  dlg = new LocDialog(this, m_Props );
  if( wxID_OK == dlg->ShowModal() ) {
    /* Notify Notebook. */
    wxCommandEvent evt( wxEVT_COMMAND_MENU_SELECTED, ME_INITACTIVELOCS );
    wxPostEvent( wxGetApp().getFrame(), evt );
  }
  dlg->Destroy();
}


void LocoWidget::onMenuStart( wxCommandEvent& event ) {
  iONode cmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE );
  wLoc.setid( cmd, wLoc.getid(m_Props) );
  wLoc.setcmd( cmd, wLoc.go );
  wxGetApp().sendToRocrail( cmd );
  cmd->base.del(cmd);
}


void LocoWidget::onMenuStop( wxCommandEvent& event ) {
  iONode cmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE );
  wLoc.setid( cmd, wLoc.getid(m_Props) );
  wLoc.setcmd( cmd, wLoc.stop );
  wxGetApp().sendToRocrail( cmd );
  cmd->base.del(cmd);
}


void LocoWidget::onStop( wxCommandEvent& event ) {
  iONode cmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE );
  wLoc.setid( cmd, wLoc.getid(m_Props) );
  wLoc.setV( cmd, 0 );
  wxGetApp().sendToRocrail( cmd );
  cmd->base.del(cmd);
}


void LocoWidget::onMenuSoftReset( wxCommandEvent& event ) {
  iONode cmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE );
  wLoc.setid( cmd, wLoc.getid(m_Props) );
  wLoc.setcmd( cmd, wLoc.softreset );
  wxGetApp().sendToRocrail( cmd );
  cmd->base.del(cmd);
}

void LocoWidget::onMenuResetAll( wxCommandEvent& event ) {
  iONode cmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE );
  wLoc.setid( cmd, wLoc.getid(m_Props) );
  wLoc.setcmd( cmd, wLoc.reset );
  wxGetApp().sendToRocrail( cmd );
  cmd->base.del(cmd);
}

void LocoWidget::onMenuSwap( wxCommandEvent& event ) {
  iONode cmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE );
  wLoc.setid( cmd, wLoc.getid(m_Props) );
  wLoc.setcmd( cmd, wLoc.swap );
  wxGetApp().sendToRocrail( cmd );
  cmd->base.del(cmd);
}

void LocoWidget::onMenuSwapBlockSide( wxCommandEvent& event ) {
  iONode cmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE );
  wLoc.setid( cmd, wLoc.getid(m_Props) );
  wLoc.setcmd( cmd, wLoc.blockside );
  wxGetApp().sendToRocrail( cmd );
  cmd->base.del(cmd);
}


void LocoWidget::onMenuGoTo( wxCommandEvent& event ) {
  GotoDlg* gotoDlg = new GotoDlg( this, wLoc.getid(m_Props) );
  if( wxID_OK == gotoDlg->ShowModal() ) {
    iONode selection = gotoDlg->getSelected();
    if( selection != NULL ) {
      /* Inform RocRail... */
      iONode cmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE );
      wLoc.setid( cmd, wLoc.getid(m_Props) );
      wLoc.setcmd( cmd, wLoc.gotoblock );
      wLoc.setblockid( cmd, wItem.getid(selection) );
      wxGetApp().sendToRocrail( cmd );
      cmd->base.del(cmd);
    }
  }
  gotoDlg->Destroy();
}

void LocoWidget::onDestination( wxMouseEvent& event ) {
  wxCommandEvent evt( wxEVT_COMMAND_MENU_SELECTED, ME_GridLocGoTo );
  onMenuGoTo( evt );
}


void LocoWidget::onModeStart( wxMouseEvent& event ) {
  wxCommandEvent evt( wxEVT_COMMAND_MENU_SELECTED, ME_GridLocGo );
  onMenuStart( evt );
}


void LocoWidget::onModeStop( wxMouseEvent& event ) {
  wxCommandEvent evt( wxEVT_COMMAND_MENU_SELECTED, ME_GridLocStop );
  onMenuStop( evt );
}


void LocoWidget::onMenuSchedule( wxCommandEvent& event ) {
  ScheduleDialog* dlg = new ScheduleDialog( this, (iONode)NULL, false, wLoc.getblockid(m_Props) );
  if( wxID_OK == dlg->ShowModal() ) {
    iONode sel = dlg->getProperties();
    if( sel != NULL ) {
      const char* id = wSchedule.getid( sel );

      if( id != NULL ) {
        /* Inform RocRail... */
        iONode cmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE );
        wLoc.setid( cmd, wLoc.getid(m_Props) );
        wLoc.setcmd( cmd, wLoc.useschedule );
        wLoc.setscheduleid( cmd, id );
        wxGetApp().sendToRocrail( cmd );
        cmd->base.del(cmd);
      }
    }
  }
  dlg->Destroy();
}


void LocoWidget::onMenuTour( wxCommandEvent& event ) {
  ToursDlg* dlg = new ToursDlg( this, (iONode)NULL, false, wLoc.getblockid(m_Props) );
  if( wxID_OK == dlg->ShowModal() ) {
    iONode sel = dlg->getProperties();
    if( sel != NULL ) {
      const char* id = wTour.getid( sel );

      if( id != NULL ) {
        /* Inform RocRail... */
        iONode cmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE );
        wLoc.setid( cmd, wLoc.getid(m_Props) );
        wLoc.setcmd( cmd, wLoc.usetour );
        wLoc.settourid( cmd, id );
        wxGetApp().sendToRocrail( cmd );
        cmd->base.del(cmd);
      }
    }
  }
  dlg->Destroy();
}


void LocoWidget::onImageLeftDown( wxMouseEvent& event ) {
#ifndef __APPLE__
  if( event.ControlDown() || event.CmdDown() ) {
#endif
    wxTextDataObject my_data(_T("moveto:") + wxString(wLoc.getid( m_Props ),wxConvUTF8)+_T("::"));
    wxDropSource dragSource( this );
    dragSource.SetData( my_data );
    wxDragResult result = dragSource.DoDragDrop(wxDrag_CopyOnly);
#ifndef __APPLE__
  }
#endif
}

void LocoWidget::onSpeedUp( wxMouseEvent& event ) {
  if( wLoc.getV(m_Props) < 100 ) {
    iONode cmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE );
    wLoc.setid( cmd, wLoc.getid(m_Props) );
    wLoc.setV( cmd, wLoc.getV(m_Props) + 1 );
    wxGetApp().sendToRocrail( cmd );
    cmd->base.del(cmd);
  }
}


void LocoWidget::onSpeedDown( wxMouseEvent& event ) {
  if( wLoc.getV(m_Props) > 0 ) {
    iONode cmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE );
    wLoc.setid( cmd, wLoc.getid(m_Props) );
    wLoc.setV( cmd, wLoc.getV(m_Props) - 1 );
    wxGetApp().sendToRocrail( cmd );
    cmd->base.del(cmd);
  }
}


void LocoWidget::onDirection( wxMouseEvent& event ) {
  wLoc.setdir(m_Props, wLoc.isdir(m_Props)?False:True );

  iONode cmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE );
  wLoc.setid( cmd, wLoc.getid( m_Props ) );
  wLoc.setV( cmd, wLoc.getV(m_Props) );
  wLoc.setfn( cmd, wLoc.isfn(m_Props) );
  wLoc.setdir( cmd, wLoc.isdir(m_Props) );
  wxGetApp().sendToRocrail( cmd );
  cmd->base.del(cmd);
}


void LocoWidget::onMouseWheel( wxMouseEvent& event ) {
  bool dirchange = event.MiddleDown();
  int rotation   = event.GetWheelRotation();
  int V_max      = wLoc.getV_max(m_Props);
  int V          = wLoc.getV(m_Props);
  bool send      = false;

  iONode m_MICini = wGui.getmic( wxGetApp().getIni() );

  if( dirchange ) {
    wLoc.setdir(m_Props, wLoc.isdir(m_Props)?False:True );
    wLoc.setV( m_Props, 0);
    send = true;
  }
  else if( rotation > 0 && V < V_max ) {
    int newV = V+wMIC.getstep(m_MICini);
    if( newV > V_max )
      newV = V_max;
    if( V != newV ) {
      wLoc.setV( m_Props, newV );
      send = true;
    }
  }
  else if( rotation < 0 && V > 0) {
    int newV = V-wMIC.getstep(m_MICini);
    if( newV < 0 )
      newV = 0;
    if( V != newV ) {
      wLoc.setV( m_Props, newV );
      send = true;
    }
  }

  if( send ) {
    iONode cmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE );
    wLoc.setid( cmd, wLoc.getid( m_Props ) );
    wLoc.setV( cmd, wLoc.getV(m_Props) );
    wLoc.setfn( cmd, wLoc.isfn(m_Props) );
    wLoc.setdir( cmd, wLoc.isdir(m_Props) );
    wxGetApp().sendToRocrail( cmd );
    cmd->base.del(cmd);
  }

}
