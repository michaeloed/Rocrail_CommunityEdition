/*
 Rocrail - Model Railroad Software

 Copyright (C) 2002-2014 Rob Versluis, Rocrail.net

 


 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3
 of the License, or (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/
#include "cardlg.h"

#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#include "wx/wx.h"
#include "wx/defs.h"
#endif

#include "rocview/public/guiapp.h"
#include "rocrail/wrapper/public/ModelCmd.h"
#include "rocrail/wrapper/public/Plan.h"
#include "rocrail/wrapper/public/Loc.h"
#include "rocrail/wrapper/public/Car.h"
#include "rocrail/wrapper/public/Item.h"
#include "rocrail/wrapper/public/CarList.h"
#include "rocrail/wrapper/public/Location.h"
#include "rocrail/wrapper/public/LocationList.h"
#include "rocrail/wrapper/public/Block.h"
#include "rocrail/wrapper/public/DataReq.h"
#include "rocrail/wrapper/public/FunDef.h"
#include "rocrail/wrapper/public/Operator.h"
#include "rocrail/wrapper/public/CVByte.h"

#include "rocview/wrapper/public/Gui.h"
#include "rocview/res/icons.hpp"

#include "rocs/public/trace.h"
#include "rocs/public/strtok.h"
#include "rocs/public/system.h"

#include "rocview/xpm/nopict.xpm"

static bool ms_Sort = true;

CarDlg::CarDlg( wxWindow* parent, iONode p_Props, bool save, const char* train, const char* consist, const char* locality )
  :cardlggen( parent )
{
  TraceOp.trc( "cardlg", TRCLEVEL_INFO, __LINE__, 9999, "cardlg" );
  m_TabAlign = wxGetApp().getTabAlign();
  m_Props    = p_Props;
  m_bSave    = save;
  m_SortCol  = 0;
  m_FGroup   = 0;
  m_Train4Add = train;
  m_Train4AddConsist = consist;
  m_Train4AddLocality = locality;
  initLabels();
  initCVDesc();
  initIndex();

  m_IndexPanel->GetSizer()->Layout();
  m_GeneralPanel->GetSizer()->Layout();
  m_DetailsPanel->GetSizer()->Layout();

  m_CarBook->Fit();

  GetSizer()->Fit(this);
  GetSizer()->SetSizeHints(this);

  m_CarList2->SetFocus();

  m_CarBook->Connect( wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( CarDlg::onSetPage ), NULL, this );
  m_SetPage = 0;

  if( p_Props != NULL ) {
    initValues();
    m_SetPage = 1;
  }
  wxCommandEvent event( wxEVT_COMMAND_MENU_SELECTED, ID_CARBOOK );
  wxPostEvent( m_CarBook, event );
}

void CarDlg::onSetPage(wxCommandEvent& event) {
  TraceOp.trc( "cardlg", TRCLEVEL_INFO, __LINE__, 9999, "set page to %d", m_SetPage );
  m_CarBook->SetSelection( m_SetPage );
}


static int __sortStr(obj* _a, obj* _b)
{
    const char* a = (const char*)*_a;
    const char* b = (const char*)*_b;
    return strcmp( a, b );
}

void CarDlg::initLocationCombo() {
  m_Location->Clear();
  m_Location->Append( _T(""), (void*)NULL );

  iONode model = wxGetApp().getModel();
  iOList list = ListOp.inst();

  if( model != NULL ) {
    iONode locationlist = wPlan.getlocationlist( model );
    if( locationlist != NULL ) {
      int cnt = NodeOp.getChildCnt( locationlist );
      for( int i = 0; i < cnt; i++ ) {
        iONode location = NodeOp.getChild( locationlist, i );
        const char* id = wLocation.getid( location );
        if( id != NULL ) {
          ListOp.add(list, (obj)id);
        }
      }
    }

    iONode bklist = wPlan.getbklist( model );
    if( bklist != NULL ) {
      int cnt = NodeOp.getChildCnt( bklist );
      for( int i = 0; i < cnt; i++ ) {
        iONode bk = NodeOp.getChild( bklist, i );
        const char* id = wBlock.getid( bk );
        if( id != NULL ) {
          ListOp.add(list, (obj)id);
        }
      }
    }

    if( ListOp.size(list) > 0 ) {
      ListOp.sort(list, &__sortStr);
      int cnt = ListOp.size( list );
      for( int i = 0; i < cnt; i++ ) {
        const char* id = (const char*)ListOp.get( list, i );
        m_Location->Append( wxString(id,wxConvUTF8) );
      }
    }
  }
  /* clean up the temp. list */
  ListOp.base.del(list);
}

void CarDlg::initLabels() {
  TraceOp.trc( "cardlg", TRCLEVEL_INFO, __LINE__, 9999, "initLabels" );
  SetTitle(wxGetApp().getMsg( "cartable" ));
  m_CarBook->SetPageText( 0, wxGetApp().getMsg( "index" ) );
  m_CarBook->SetPageText( 1, wxGetApp().getMsg( "general" ) );
  m_CarBook->SetPageText( 2, wxGetApp().getMsg( "details" ) );
  m_CarBook->SetPageText( 3, wxGetApp().getMsg( "interface" ) );
  m_CarBook->SetPageText( 4, wxGetApp().getMsg( "functions" ) );

  // Index
  m_Show->SetLabel( wxGetApp().getMsg( "show" ) );
  m_NewCar->SetLabel( wxGetApp().getMsg( "new" ) );
  m_DeleteCar->SetLabel( wxGetApp().getMsg( "delete" ) );
  m_Copy->SetLabel( wxGetApp().getMsg( "copy" ) );
  m_Doc->SetLabel( wxGetApp().getMsg( "doc_report" ) );
  m_Import->SetLabel( wxGetApp().getMsg( "import" ) );

  m_NewCar->Enable( m_bSave );
  m_DeleteCar->Enable( m_bSave );
  m_Copy->Enable( m_bSave );
  m_Import->Enable( m_bSave );

  m_ID->Enable( m_bSave );

  m_CarList2->InsertColumn(0, wxGetApp().getMsg( "id" ), wxLIST_FORMAT_LEFT );
  m_CarList2->InsertColumn(1, wxGetApp().getMsg( "address" ), wxLIST_FORMAT_LEFT );
  m_CarList2->InsertColumn(2, wxGetApp().getMsg( "roadname" ), wxLIST_FORMAT_LEFT );
  m_CarList2->InsertColumn(3, wxGetApp().getMsg( "number" ), wxLIST_FORMAT_LEFT );
  m_CarList2->InsertColumn(4, wxGetApp().getMsg( "type" ), wxLIST_FORMAT_LEFT );
  m_CarList2->InsertColumn(5, wxGetApp().getMsg( "subtype" ), wxLIST_FORMAT_LEFT );
  m_CarList2->InsertColumn(6, wxGetApp().getMsg( "length" ), wxLIST_FORMAT_LEFT );
  m_CarList2->InsertColumn(7, wxGetApp().getMsg( "place" ), wxLIST_FORMAT_LEFT );
  m_CarList2->InsertColumn(8, wxGetApp().getMsg( "train" ), wxLIST_FORMAT_LEFT );

  // General
  m_labID->SetLabel( wxGetApp().getMsg( "id" ) );
  m_labIdent->SetLabel( wxGetApp().getMsg( "identifier" ) );
  m_labNumber->SetLabel( wxGetApp().getMsg( "number" ) );
  m_labRoadname->SetLabel( wxGetApp().getMsg( "roadname" ) );
  m_labColor->SetLabel( wxGetApp().getMsg( "color" ) );
  m_Era->SetLabel( wxGetApp().getMsg( "era" ) );
  m_labLocation->SetLabel( wxGetApp().getMsg( "place" ) );
  m_labImageName->SetLabel( wxGetApp().getMsg( "image" ) );
  m_labOwner->SetLabel( wxGetApp().getMsg( "owner" ) );

  m_Status->SetLabel( wxGetApp().getMsg( "status" ) );
  m_Status->SetString( 0, wxGetApp().getMsg( "empty" ) );
  m_Status->SetString( 1, wxGetApp().getMsg( "loaded" ) );
  m_Status->SetString( 2, wxGetApp().getMsg( "maintenance" ) );

  m_ShowAll->SetLabel( wxGetApp().getMsg( "showall" ) );
  m_ShowAll->Enable( !m_bSave );
  m_ShowAll->SetValue( m_bSave );

  initLocationCombo();


  // Details
  m_Type->SetLabel( wxGetApp().getMsg( "type" ) );
  m_Type->SetString( 0, wxGetApp().getMsg( "goods" ) );
  m_Type->SetString( 1, wxGetApp().getMsg( "passenger" ) );
  m_Commuter->SetLabel( wxGetApp().getMsg( "commuter" ) );
  m_labSubtype->SetLabel( wxGetApp().getMsg( "subtype" ) );
  m_labLength->SetLabel( wxGetApp().getMsg( "length" ) );
  m_labWeight->SetLabel( wxGetApp().getMsg( "weight" ) );
  m_labWeightEmpty->SetLabel( wxGetApp().getMsg( "empty" ) );
  m_labWeightLoaded->SetLabel( wxGetApp().getMsg( "loaded" ) );
  m_labManuId->SetLabel( wxGetApp().getMsg( "manufactured_ID" ) );
  m_labRemark->SetLabel( wxGetApp().getMsg( "remark" ) );
  m_labVMax->SetLabel( wxGetApp().getMsg( "maxkmh" ) );

  // Interface
  BaseDialog::addIIDs(m_IID);

  m_labBus->SetLabel( wxGetApp().getMsg( "bus" ) );
  m_labAddr->SetLabel( wxGetApp().getMsg( "address" ) );
  m_labIID->SetLabel( wxGetApp().getMsg( "iid" ) );
  m_labProtocol->SetLabel( wxGetApp().getMsg( "protocol" ) );
  m_labProtVersion->SetLabel( wxGetApp().getMsg( "protocol_version" ) );
  m_IntOptions->GetStaticBox()->SetLabel( wxGetApp().getMsg( "options" ) );
  m_UseDir->SetLabel( wxGetApp().getMsg( "dir" ) );
  m_InvDir->SetLabel( wxGetApp().getMsg( "invert" ) );
  m_UseLights->SetLabel( wxGetApp().getMsg( "lights" ) );
  m_F0VCmd->SetLabel( wxGetApp().getMsg( "speed" ) + wxT(" ") + wxGetApp().getMsg( "command" ));
  m_Placing->SetLabel( wxGetApp().getMsg( "placing" ) );
  m_labSteps->SetLabel( wxGetApp().getMsg( "speedsteps" ) );

  // Functions
  m_labFDesc->SetLabel( wxGetApp().getMsg( "description" ) );
  m_labIcon->SetLabel( wxGetApp().getMsg( "icon" ) );

  //CV
  m_CVList->SetRowLabelSize(0);
  m_CVList->EnableEditing(false);
  m_CVList->EnableDragGridSize(false);
  m_CVList->SetSelectionMode(wxGrid::wxGridSelectRows);
  m_CVList->SetColLabelValue(0, _T("CV"));
  m_CVList->SetColLabelValue(1, wxGetApp().getMsg( "value" ));
  m_CVList->SetColLabelValue(2, wxGetApp().getMsg( "description" ));
  m_CVList->AutoSizeColumns();
  m_CVList->AutoSizeRows();
  m_CVDescModify->SetLabel( wxGetApp().getMsg( "modify" ) );
  m_labCVDesc->SetLabel( wxGetApp().getMsg( "description" ) );
  m_CVDescModify->Enable(false);
  m_CVDescription->Enable(false);


  // Buttons
  m_stdButtonOK->SetLabel( wxGetApp().getMsg( "ok" ) );
  m_stdButtonCancel->SetLabel( wxGetApp().getMsg( "cancel" ) );
  m_stdButtonApply->SetLabel( wxGetApp().getMsg( "apply" ) );
  m_stdButtonHelp->SetLabel( wxGetApp().getMsg( "help" ) );
  m_stdButtonApply->Enable( m_bSave );
}

/* comparator for sorting by id: */
static int __sortID(obj* _a, obj* _b)
{
    iONode a = (iONode)*_a;
    iONode b = (iONode)*_b;
    const char* idA = wItem.getid( a );
    const char* idB = wItem.getid( b );
    return ms_Sort ? strcmp( idA, idB ):strcmp( idB, idA );
}
static int __sortRoadName(obj* _a, obj* _b)
{
    iONode a = (iONode)*_a;
    iONode b = (iONode)*_b;
    const char* idA = wCar.getroadname( a );
    const char* idB = wCar.getroadname( b );
    return ms_Sort ? strcmp( idA, idB ):strcmp( idB, idA );
}
static int __sortNumber(obj* _a, obj* _b)
{
    iONode a = (iONode)*_a;
    iONode b = (iONode)*_b;
    const char* idA = wCar.getnumber( a );
    const char* idB = wCar.getnumber( b );
    return ms_Sort ? strcmp( idA, idB ):strcmp( idB, idA );
}
static int __sortType(obj* _a, obj* _b)
{
    iONode a = (iONode)*_a;
    iONode b = (iONode)*_b;
    const char* idA = wCar.gettype( a );
    const char* idB = wCar.gettype( b );
    return ms_Sort ? strcmp( idA, idB ):strcmp( idB, idA );
}
static int __sortSubType(obj* _a, obj* _b)
{
    iONode a = (iONode)*_a;
    iONode b = (iONode)*_b;
    const char* idA = wCar.getsubtype( a );
    const char* idB = wCar.getsubtype( b );
    return ms_Sort ? strcmp( idA, idB ):strcmp( idB, idA );
}
static int __sortLen(obj* _a, obj* _b)
{
    iONode a = (iONode)*_a;
    iONode b = (iONode)*_b;
    if( wCar.getlen(a) > wCar.getlen(b) )
      return ms_Sort?1:-1;
    if( wCar.getlen(a) < wCar.getlen(b) )
      return ms_Sort?-1:1;
    return 0;
}
static int __sortAddr(obj* _a, obj* _b)
{
    iONode a = (iONode)*_a;
    iONode b = (iONode)*_b;
    if( wCar.getlen(a) > wCar.getaddr(b) )
      return ms_Sort?1:-1;
    if( wCar.getlen(a) < wCar.getaddr(b) )
      return ms_Sort?-1:1;
    return 0;
}
static int __sortLocation(obj* _a, obj* _b)
{
    iONode a = (iONode)*_a;
    iONode b = (iONode)*_b;
    const char* idA = wCar.getlocation( a );
    const char* idB = wCar.getlocation( b );
    return ms_Sort ? strcmp( idA, idB ):strcmp( idB, idA );
}
static int __sortTrain(obj* _a, obj* _b)
{
    iONode a = (iONode)*_a;
    iONode b = (iONode)*_b;
    const char* idA = CarDlg::findTrain(wCar.getid( a ));
    const char* idB = CarDlg::findTrain(wCar.getid( b ));
    return ms_Sort ? strcmp( idA, idB ):strcmp( idB, idA );
}


const char* CarDlg::findTrain(const char* carid) {
  iONode model = wxGetApp().getModel();
  if( model != NULL ) {
    iONode oplist = wPlan.getoperatorlist( model );
    if( oplist != NULL ) {
      int cnt = NodeOp.getChildCnt( oplist );
      for( int i = 0; i < cnt; i++ ) {
        iONode opr = NodeOp.getChild( oplist, i );
        const char* id = wOperator.getid( opr );
        if( StrOp.find( wOperator.getcarids( opr ), carid) ) {
          return id;
        }
      }
    }
  }
  return "";
}

void CarDlg::initIndex(){
  TraceOp.trc( "cardlg", TRCLEVEL_INFO, __LINE__, 9999, "initIndex" );

  SetTitle(wxGetApp().getMsg( "cartable" ));

  m_CarList2->DeleteAllItems();
  if( wGui.isgrayicons(wxGetApp().getIni()) )
    m_CarImage->SetBitmapLabel( *_img_noimg );
  else
    m_CarImage->SetBitmapLabel( wxBitmap(nopict_xpm) );
  m_CarImage->Refresh();

  iONode model = wxGetApp().getModel();
  if( model != NULL ) {
    iONode carlist = wPlan.getcarlist( model );
    if( carlist != NULL ) {
      iOList list = ListOp.inst();
      int cnt = NodeOp.getChildCnt( carlist );
      for( int i = 0; i < cnt; i++ ) {
        iONode car = NodeOp.getChild( carlist, i );
        const char* id = wCar.getid( car );
        if( id != NULL ) {
          ListOp.add(list, (obj)car);
        }
      }

      if( m_SortCol == 1 ) {
        ListOp.sort(list, &__sortRoadName);
      }
      else if( m_SortCol == 2 ) {
        ListOp.sort(list, &__sortAddr);
      }
      else if( m_SortCol == 3 ) {
        ListOp.sort(list, &__sortNumber);
      }
      else if( m_SortCol == 4 ) {
        ListOp.sort(list, &__sortType);
      }
      else if( m_SortCol == 5 ) {
        ListOp.sort(list, &__sortSubType);
      }
      else if( m_SortCol == 6 ) {
        ListOp.sort(list, &__sortLen);
      }
      else if( m_SortCol == 7 ) {
        ListOp.sort(list, &__sortLocation);
      }
      else if( m_SortCol == 8 ) {
        ListOp.sort(list, &__sortTrain);
      }
      else {
        ListOp.sort(list, &__sortID);
      }

      int idx = 0;
      cnt = ListOp.size( list );
      for( int i = 0; i < cnt; i++ ) {
        iONode car = (iONode)ListOp.get( list, i );
        bool doNotList = false;
        const char* id = wCar.getid( car );
        if( !m_ShowAll->IsChecked() ) {
          const char* train = findTrain(id);
          if( m_Train4Add != NULL && StrOp.equals( m_Train4Add, train ) )
            continue; // already belongs to this train
          if( m_Train4Add != NULL && !StrOp.equals( m_Train4Add, train ) && StrOp.len(train) > 0 )
            continue; // belongs to another train
          if( m_Train4AddConsist != NULL ) {
            iOStrTok strtok = StrTokOp.inst( m_Train4AddConsist, ',' );
            while( StrTokOp.hasMoreTokens( strtok ) ) {
              const char* carid  = StrTokOp.nextToken( strtok );
              if( StrOp.equals(id, carid) ) {
                doNotList = true; // already in the consist
                break;
              }
            }
            StrTokOp.base.del(strtok);
          }
          if( m_Train4AddLocality != NULL && StrOp.len(m_Train4AddLocality) > 0 ) {
            if( !StrOp.equals( m_Train4AddLocality, wCar.getlocation( car ) ) ) {
              doNotList = true; // not in the same locality
              break;
            }
          }
        }
        if(doNotList)
          continue;

        m_CarList2->InsertItem( idx, wxString(id,wxConvUTF8) );
        m_CarList2->SetItem( idx, 1, wxString::Format(wxT("%d"), wCar.getaddr( car )) );
        m_CarList2->SetItem( idx, 2, wxString(wCar.getroadname( car ), wxConvUTF8) );
        m_CarList2->SetItem( idx, 3, wxString(wCar.getnumber( car ), wxConvUTF8) );
        m_CarList2->SetItem( idx, 4, StrOp.len(wCar.gettype( car )) > 0 ? wxGetApp().getMsg( wCar.gettype( car ) ):wxT("") );
        m_CarList2->SetItem( idx, 5, StrOp.len(wCar.getsubtype( car )) > 0 ? wxGetApp().getMsg(wCar.getsubtype( car )):wxT("") );
        m_CarList2->SetItem( idx, 6, wxString::Format(wxT("%d"), wCar.getlen( car )) );
        m_CarList2->SetItem( idx, 7, wxString(wCar.getlocation( car ), wxConvUTF8) );
        m_CarList2->SetItem( idx, 8, wxString(findTrain(id), wxConvUTF8) );
        m_CarList2->SetItemPtrData(idx, (wxUIntPtr)car);
        idx++;

      }
      // resize
      for( int n = 0; n < 7; n++ ) {
        m_CarList2->SetColumnWidth(n, wxLIST_AUTOSIZE_USEHEADER);
        int autoheadersize = m_CarList2->GetColumnWidth(n);
        m_CarList2->SetColumnWidth(n, wxLIST_AUTOSIZE);
        int autosize = m_CarList2->GetColumnWidth(n);
        if(autoheadersize > autosize )
          m_CarList2->SetColumnWidth(n, wxLIST_AUTOSIZE_USEHEADER);
        else if( autosize > 120 )
          m_CarList2->SetColumnWidth(n, autoheadersize > 120 ? autoheadersize:120);
      }

      /* clean up the temp. list */
      ListOp.base.del(list);

      if( m_Props != NULL ) {
        char* title = StrOp.fmt( "%s %s", (const char*)wxGetApp().getMsg("car").mb_str(wxConvUTF8), wCar.getid( m_Props ) );
        SetTitle( wxString(title,wxConvUTF8) );
        StrOp.free( title );

        setSelection(wCar.getid( m_Props ));

      }
      else if(m_CarList2->GetItemCount() > 0 && m_ShowAll->IsChecked() ) {
        TraceOp.trc( "cardlg", TRCLEVEL_INFO, __LINE__, 9999, "no selection" );
        m_CarList2->SetItemState(0, wxLIST_STATE_SELECTED, wxLIST_STATE_SELECTED);
        m_Props = (iONode)m_CarList2->GetItemData(0);

      }
    }

  }

}

void CarDlg::setSelection(const char* ID) {
  int size = m_CarList2->GetItemCount();
  for( int index = 0; index < size; index++ ) {
    iONode node = (iONode)m_CarList2->GetItemData(index);
    if( StrOp.equals( ID, wCar.getid(node) ) ) {
      m_CarList2->SetItemState(index, wxLIST_STATE_SELECTED, wxLIST_STATE_SELECTED);
      break;
    }
  }

}


static int __sortCV(obj* _a, obj* _b)
{
    iONode a = (iONode)*_a;
    iONode b = (iONode)*_b;
    int nrA = wCVByte.getnr( a );
    int nrB = wCVByte.getnr( b );
    if( nrA == nrB )
      return 0;
    if( nrA > nrB )
      return 1;
    return -1;
}


void CarDlg::initValues() {
  if( m_Props == NULL ) {
    TraceOp.trc( "cardlg", TRCLEVEL_DEBUG, __LINE__, 9999, "no car selected" );
    return;
  }

  m_FGroup   = 0;

  char* title = StrOp.fmt( "%s %s", (const char*)wxGetApp().getMsg("car").mb_str(wxConvUTF8), wCar.getid( m_Props ) );
  SetTitle( wxString(title,wxConvUTF8) );
  StrOp.free( title );

  TraceOp.trc( "cardlg", TRCLEVEL_INFO, __LINE__, 9999, "initValues for car [%s]", wCar.getid( m_Props ) );
  // Init General
  if( wCar.getimage( m_Props ) != NULL && StrOp.len(wCar.getimage( m_Props )) > 0 ) {
    bool isSupported = true;
    wxBitmapType bmptype = wxBITMAP_TYPE_XPM;
    if( StrOp.endsWithi( wCar.getimage( m_Props ), ".gif" ) )
      bmptype = wxBITMAP_TYPE_GIF;
    else if( StrOp.endsWithi( wCar.getimage( m_Props ), ".png" ) )
      bmptype = wxBITMAP_TYPE_PNG;
    else {
      TraceOp.trc( "cardlg", TRCLEVEL_WARNING, __LINE__, 9999, "unsupported image format %s", wCar.getimage( m_Props ) );
      isSupported = false;
    }

    const char* imagepath = wGui.getimagepath(wxGetApp().getIni());
    static char pixpath[256];
    StrOp.fmtb( pixpath, "%s%c%s", imagepath, SystemOp.getFileSeparator(), FileOp.ripPath( wCar.getimage( m_Props ) ) );

    if( isSupported && FileOp.exist(pixpath) && StrOp.len(wCar.getimage( m_Props )) > 0 ) {
      TraceOp.trc( "cardlg", TRCLEVEL_INFO, __LINE__, 9999, "picture [%s]", pixpath );
      m_CarImage->SetBitmapLabel( wxBitmap(wxString(pixpath,wxConvUTF8), bmptype) );
    }
    else {
      TraceOp.trc( "cardlg", TRCLEVEL_WARNING, __LINE__, 9999, "picture [%s] not found", pixpath );
      if( wGui.isgrayicons(wxGetApp().getIni()) )
        m_CarImage->SetBitmapLabel( *_img_noimg );
      else
        m_CarImage->SetBitmapLabel( wxBitmap(nopict_xpm) );
      if( isSupported ) {
        // request the image from server:
        iONode node = NodeOp.inst( wDataReq.name(), NULL, ELEMENT_NODE );
        wDataReq.setid( node, wCar.getid(m_Props) );
        wDataReq.setcmd( node, wDataReq.get );
        wDataReq.settype( node, wDataReq.image );
        wDataReq.setfilename( node, wCar.getimage(m_Props) );
        wxGetApp().sendToRocrail( node );
      }
    }
    m_CarImage->SetToolTip(wxString(wCar.getnumber( m_Props ),wxConvUTF8));


    //m_CarImage->SetBitmapLabel( wxBitmap(wxString(wLoc.getimage( m_Props ),wxConvUTF8), bmptype) );
    //m_CarImageIndex->SetBitmapLabel( wxBitmap(wxString(wLoc.getimage( m_Props ),wxConvUTF8), bmptype) );
  }
  else {
    if( wGui.isgrayicons(wxGetApp().getIni()) )
      m_CarImage->SetBitmapLabel( *_img_noimg );
    else
      m_CarImage->SetBitmapLabel( wxBitmap(nopict_xpm) );
    //m_CarImageIndex->SetBitmapLabel( wxBitmap(nopict_xpm) );
  }
  m_CarImage->Refresh();
  //m_CarImageIndex->Refresh();

  // init General
  m_Show->SetValue(wCar.isshow( m_Props ));
  m_ID->SetValue( wxString(wCar.getid( m_Props ),wxConvUTF8) );
  m_Ident->SetValue( wxString(wCar.getident( m_Props ),wxConvUTF8) );
  m_Number->SetValue( wxString(wCar.getnumber( m_Props ),wxConvUTF8) );
  m_Color->SetValue( wxString(wCar.getcolor( m_Props ),wxConvUTF8) );
  m_Roadname->SetValue( wxString(wCar.getroadname( m_Props ),wxConvUTF8) );
  m_ImageName->SetValue( wxString(wCar.getimage( m_Props ),wxConvUTF8) );
  m_Era->SetSelection( wCar.getera( m_Props ) );
  m_Location->SetStringSelection(wxString(wCar.getlocation(m_Props),wxConvUTF8));
  m_Owner->SetValue( wxString(wCar.getowner( m_Props ),wxConvUTF8) );

  // init Status
  if( StrOp.equals( wCar.status_empty, wCar.getstatus( m_Props) ) )
    m_Status->SetSelection(0);
  else if( StrOp.equals( wCar.status_loaded, wCar.getstatus( m_Props) ) )
    m_Status->SetSelection(1);
  else
    m_Status->SetSelection(2);

  // init Details
  if( StrOp.equals( wCar.cartype_freight, wCar.gettype( m_Props) ) )
    m_Type->SetSelection(0);
  else
    m_Type->SetSelection(1);

  initSubType();

  m_Commuter->SetValue( wCar.iscommuter( m_Props )?true:false );
  m_Length->SetValue( wCar.getlen( m_Props ) );
  m_WeightEmpty->SetValue( wCar.getweight_empty( m_Props ) );
  m_WeightLoaded->SetValue( wCar.getweight_loaded( m_Props ) );
  m_ManuId->SetValue( wxString(wCar.getmanuid( m_Props ),wxConvUTF8) );
  m_Remark->SetValue( wxString(wCar.getremark( m_Props ),wxConvUTF8) );
  m_VMax->SetValue( wCar.getV_max( m_Props ) );

  // Init Interface
  char* str = StrOp.fmt( "%d", wCar.getbus( m_Props ) );
  m_Bus->SetValue( wxString(str,wxConvUTF8) ); StrOp.free( str );
  m_Addr->SetValue( wCar.getaddr( m_Props ) );
  m_IID->SetValue( wxString(wCar.getiid( m_Props ),wxConvUTF8) );

  if( StrOp.equals( wLoc.prot_P, wCar.getprot( m_Props ) ) )
    m_Protocol->SetSelection( 0 );
  else if( StrOp.equals( wLoc.prot_M, wCar.getprot( m_Props ) ) )
    m_Protocol->SetSelection( 1 );
  else if( StrOp.equals( wLoc.prot_N, wCar.getprot( m_Props ) ) )
    m_Protocol->SetSelection( 2 );
  else if( StrOp.equals( wLoc.prot_L, wCar.getprot( m_Props ) ) )
    m_Protocol->SetSelection( 3 );

  str = StrOp.fmt( "%d", wCar.getprotver( m_Props ) );
  m_ProtVersion->SetValue( wxString(str,wxConvUTF8) ); StrOp.free( str );

  m_UseDir->SetValue( wCar.isusedir(m_Props)?true:false );
  m_InvDir->SetValue( wCar.isinvdir(m_Props)?true:false );
  m_Placing->SetValue( wCar.isplacing(m_Props)?true:false );
  m_UseLights->SetValue( wCar.isuselights(m_Props)?true:false );
  m_FnLights->SetValue( wCar.getfnlights(m_Props) );
  m_F0VCmd->SetValue( wCar.isf0vcmd(m_Props)?true:false );
  m_SpeedSteps->SetValue( wLoc.getspcnt( m_Props ) );

  initFunctions();

  // CV's
  TraceOp.trc( "cardlg", TRCLEVEL_INFO, __LINE__, 9999, "CV list...");
  iOList list = ListOp.inst();
  iONode cv = wCar.getcvbyte( m_Props );
  while( cv != NULL ) {
    if( wCVByte.getnr( cv ) > 0 && wCVByte.getnr( cv ) <= 1024 ) {
      ListOp.add(list, (obj)cv);
    }
    cv = wCar.nextcvbyte( m_Props, cv );
  };

  TraceOp.trc( "cardlg", TRCLEVEL_INFO, __LINE__, 9999, "CVs...");
  if( m_CVList->GetNumberRows() > 0 )
    m_CVList->DeleteRows( 0, m_CVList->GetNumberRows() );
  ListOp.sort(list, &__sortCV);
  int cnt = ListOp.size( list );
  for( int i = 0; i < cnt && cnt < 1024; i++ ) {
    iONode cv = (iONode)ListOp.get( list, i );
    char* cvnr = StrOp.fmt( "%d", wCVByte.getnr( cv ) );
    char* cvval = StrOp.fmt( "%d", wCVByte.getvalue( cv ) );
    const char* cvdesc = wCVByte.getdesc(cv);
    m_CVNodes[wCVByte.getnr( cv )] = cv;
    m_CVList->AppendRows();
    int row = m_CVList->GetNumberRows()-1;
    m_CVList->SetCellValue(row, 0, wxString(cvnr,wxConvUTF8) );
    m_CVList->SetCellValue(row, 1, wxString(cvval,wxConvUTF8) );
    if( cvdesc != NULL && StrOp.len(cvdesc) > 0 )
      m_CVList->SetCellValue(row, 2, wxString(cvdesc,wxConvUTF8) );
    else
      m_CVList->SetCellValue(row, 2, wxString(m_CVDesc[wCVByte.getnr( cv )&0xff],wxConvUTF8) );
    m_CVList->SetReadOnly( row, 0, true );
    m_CVList->SetReadOnly( row, 1, true );
    m_CVList->SetReadOnly( row, 2, true );
    StrOp.free( cvnr );
    StrOp.free( cvval );
  }
  /* clean up the temp. list */
  ListOp.base.del(list);
  m_CVList->AutoSizeColumns();

}



bool CarDlg::evaluate(){
  if( m_Props == NULL )
    return false;

  TraceOp.trc( "cardlg", TRCLEVEL_INFO, __LINE__, 9999, "Evaluate %s", wCar.getid( m_Props ) );

  if( m_ID->GetValue().Len() == 0 ) {
    wxMessageDialog( this, wxGetApp().getMsg("invalidid"), _T("Rocrail"), wxOK | wxICON_ERROR ).ShowModal();
    m_ID->SetValue( wxString(wCar.getid( m_Props ),wxConvUTF8) );
    return false;
  }
  // evaluate General
  wCar.setshow( m_Props, m_Show->IsChecked()?True:False);
  wItem.setprev_id( m_Props, wItem.getid(m_Props) );
  wCar.setid( m_Props, m_ID->GetValue().mb_str(wxConvUTF8) );
  wCar.setident( m_Props, m_Ident->GetValue().mb_str(wxConvUTF8) );
  wCar.setnumber( m_Props, m_Number->GetValue().mb_str(wxConvUTF8) );
  wCar.setcolor( m_Props, m_Color->GetValue().mb_str(wxConvUTF8) );
  wCar.setroadname( m_Props, m_Roadname->GetValue().mb_str(wxConvUTF8) );
  wCar.setimage( m_Props, m_ImageName->GetValue().mb_str(wxConvUTF8) );
  wCar.setera( m_Props, m_Era->GetSelection() );
  wCar.setlocation(m_Props, m_Location->GetStringSelection().mb_str(wxConvUTF8));
  wCar.setowner( m_Props, m_Owner->GetValue().mb_str(wxConvUTF8) );


  if( m_Status->GetSelection() == 0 )
    wCar.setstatus( m_Props, wCar.status_empty );
  else if( m_Status->GetSelection() == 1 )
    wCar.setstatus( m_Props, wCar.status_loaded );
  else
    wCar.setstatus( m_Props, wCar.status_maintenance );

  // evaluate Details
  if( m_Type->GetSelection() == 0 )
    wCar.settype( m_Props, wCar.cartype_freight );
  else
    wCar.settype( m_Props, wCar.cartype_passenger );

  if(m_SubType->GetSelection() != wxNOT_FOUND )
    wCar.setsubtype( m_Props, (char*)((wxItemContainer*)m_SubType)->GetClientData( m_SubType->GetSelection()) );

  wCar.setcommuter( m_Props, m_Commuter->IsChecked()?True:False );
  wCar.setlen( m_Props, m_Length->GetValue() );
  wCar.setweight_empty( m_Props, m_WeightEmpty->GetValue() );
  wCar.setweight_loaded( m_Props, m_WeightLoaded->GetValue() );

  wCar.setmanuid( m_Props, m_ManuId->GetValue().mb_str(wxConvUTF8) );
  wCar.setremark( m_Props, m_Remark->GetValue().mb_str(wxConvUTF8) );
  wCar.setV_max( m_Props, m_VMax->GetValue() );

  // evaluate Interface
  int val = atoi( m_Bus->GetValue().mb_str(wxConvUTF8) );
  wCar.setbus( m_Props, val );
  wCar.setaddr( m_Props, m_Addr->GetValue() );
  wCar.setiid( m_Props, m_IID->GetValue().mb_str(wxConvUTF8) );

  if( m_Protocol->GetSelection() == 0 )
    wCar.setprot( m_Props, wLoc.prot_P );
  else if( m_Protocol->GetSelection() == 1 )
    wCar.setprot( m_Props, wLoc.prot_M );
  else if( m_Protocol->GetSelection() == 2 )
    wCar.setprot( m_Props, wLoc.prot_N );
  else if( m_Protocol->GetSelection() == 3 )
    wCar.setprot( m_Props, wLoc.prot_L );

  val = atoi( m_ProtVersion->GetValue().mb_str(wxConvUTF8) );
  wCar.setprotver( m_Props, val );

  wCar.setusedir(m_Props, m_UseDir->IsChecked()?True:False );
  wCar.setinvdir(m_Props, m_InvDir->IsChecked()?True:False );
  wCar.setplacing(m_Props, m_Placing->IsChecked()?True:False );
  wCar.setuselights(m_Props, m_UseLights->IsChecked()?True:False );
  wCar.setfnlights(m_Props, m_FnLights->GetValue() );
  wCar.setf0vcmd(m_Props, m_F0VCmd->IsChecked()?True:False );
  wLoc.setspcnt( m_Props, m_SpeedSteps->GetValue() );

  evaluateFunctions();

  return true;
}


void CarDlg::onImageChooser( wxCommandEvent& event ) {
  onCarImage(event);
}

void CarDlg::onCarImage( wxCommandEvent& event ){
  if( m_Props == NULL )
    return;

  const char* imagepath = wGui.getimagepath( wxGetApp().getIni() );
  TraceOp.trc( "cardlg", TRCLEVEL_INFO, __LINE__, 9999, "imagepath = [%s]", imagepath );
  wxFileDialog* fdlg = new wxFileDialog(this, _T("Search car image"),
      wxString(imagepath,wxConvUTF8), _T(""),
      _T("PNG files (*.png)|*.png|GIF files (*.gif)|*.gif|XPM files (*.xpm)|*.xpm"), wxFD_OPEN);
  if( fdlg->ShowModal() == wxID_OK ) {
    TraceOp.trc( "cardlg", TRCLEVEL_INFO, __LINE__, 9999, "Loading %s...", (const char*)fdlg->GetPath().mb_str(wxConvUTF8) );
    wxBitmapType bmptype = wxBITMAP_TYPE_XPM;
    if( StrOp.endsWithi( fdlg->GetPath().mb_str(wxConvUTF8), ".gif" ) )
      bmptype = wxBITMAP_TYPE_GIF;
    else if( StrOp.endsWithi( fdlg->GetPath().mb_str(wxConvUTF8), ".png" ) )
      bmptype = wxBITMAP_TYPE_PNG;
    else {
      return;
    }
    m_CarImage->SetBitmapLabel( wxBitmap( fdlg->GetPath(), bmptype ) );
    m_CarImage->Refresh();
    wCar.setimage( m_Props, FileOp.ripPath(fdlg->GetPath().mb_str(wxConvUTF8)) );
    m_ImageName->SetValue( wxString(wCar.getimage( m_Props ),wxConvUTF8) );
  }
}


void CarDlg::onCarList2( wxListEvent& event ) {
  int index = event.GetIndex();
  m_Props = (iONode)m_CarList2->GetItemData(index);
  if( m_Props != NULL )
    initValues();
  else
    TraceOp.trc( "cardlg", TRCLEVEL_INFO, __LINE__, 9999, "no selection..." );
}


iONode CarDlg::getSelectedCar() {
  return m_Props;
}


int CarDlg::findID( const char* ID ) {
  int size = m_CarList2->GetItemCount();
  for( int index = 0; index < size; index++ ) {
    iONode node = (iONode)m_CarList2->GetItemData(index);
    if( StrOp.equals( ID, wCar.getid(node) ) ) {
      return index;
    }
  }
  return wxNOT_FOUND;
}


void CarDlg::onNewCar( wxCommandEvent& event ){
  int i = findID("NEW");
  if( i == wxNOT_FOUND ) {
    iONode model = wxGetApp().getModel();
    if( model != NULL ) {
      iONode carlist = wPlan.getcarlist( model );
      if( carlist == NULL ) {
        carlist = NodeOp.inst( wCarList.name(), model, ELEMENT_NODE );
        NodeOp.addChild( model, carlist );
      }
      if( carlist != NULL ) {
        iONode car = NodeOp.inst( wCar.name(), carlist, ELEMENT_NODE );
        NodeOp.addChild( carlist, car );
        wCar.setid( car, "NEW" );
        m_Props = car;
        initValues();
        initIndex();
        setSelection(wCar.getid( car ));
      }
    }
  }
}


void CarDlg::onDeleteCar( wxCommandEvent& event ){
  if( m_Props == NULL )
    return;

  int action = wxMessageDialog( this, wxGetApp().getMsg("removewarning"), _T("Rocrail"), wxYES_NO | wxICON_EXCLAMATION ).ShowModal();
  if( action == wxID_NO )
    return;

  wxGetApp().pushUndoItem( (iONode)NodeOp.base.clone( m_Props ) );
  /* Notify RocRail. */
  iONode cmd = NodeOp.inst( wModelCmd.name(), NULL, ELEMENT_NODE );
  wModelCmd.setcmd( cmd, wModelCmd.remove );
  NodeOp.addChild( cmd, (iONode)m_Props->base.clone( m_Props ) );
  wxGetApp().sendToRocrail( cmd );
  cmd->base.del(cmd);

  iONode model = wxGetApp().getModel();
  if( model != NULL ) {
    iONode carlist = wPlan.getcarlist( model );
    if( carlist != NULL ) {
      NodeOp.removeChild( carlist, m_Props );
      m_Props = NULL;
    }
  }

  initIndex();
}


void CarDlg::OnCopy( wxCommandEvent& event ){
  if( m_Props != NULL ) {
    iONode model = wxGetApp().getModel();
    if( model != NULL ) {
      iONode carlist = wPlan.getcarlist( model );
      if( carlist == NULL ) {
        carlist = NodeOp.inst( wCarList.name(), model, ELEMENT_NODE );
        NodeOp.addChild( model, carlist );
      }

      if( carlist != NULL ) {
        iONode lccopy = (iONode)NodeOp.base.clone( m_Props );
        char* id = StrOp.fmt( "%s (copy)", wCar.getid(lccopy));
        wCar.setid(lccopy, id);
        StrOp.free(id);
        NodeOp.addChild( carlist, lccopy );
        initIndex();
      }

    }
  }
}


void CarDlg::onImport( wxCommandEvent& event ){
  wxString ms_FileExt = wxGetApp().getMsg("planfiles");
  const char* l_openpath = wGui.getopenpath( wxGetApp().getIni() );
  wxFileDialog* fdlg = new wxFileDialog(this, wxGetApp().getMenu("openplanfile"), wxString(l_openpath,wxConvUTF8) , _T(""), ms_FileExt, wxFD_OPEN);
  if( fdlg->ShowModal() == wxID_OK ) {

    wGui.setopenpath( wxGetApp().getIni(), fdlg->GetPath().mb_str(wxConvUTF8) );
    // strip filename:
    wGui.setopenpath( wxGetApp().getIni(), FileOp.getPath(wGui.getopenpath( wxGetApp().getIni() ) ) );

    if( fdlg->GetPath().Len() > 0 && FileOp.exist(fdlg->GetPath().mb_str(wxConvUTF8)) ) {
      iOFile f = FileOp.inst( fdlg->GetPath().mb_str(wxConvUTF8), OPEN_READONLY );
      char* buffer = (char*)allocMem( FileOp.size( f ) +1 );
      FileOp.read( f, buffer, FileOp.size( f ) );
      FileOp.base.del( f );
      iODoc doc = DocOp.parse( buffer );
      if( doc != NULL ) {
        iONode plan = DocOp.getRootNode( doc );
        DocOp.base.del( doc );
        TraceOp.trc( "cardlg", TRCLEVEL_INFO, __LINE__, 9999, "Plan [%s] is successfully parsed!", (const char*)fdlg->GetPath().mb_str(wxConvUTF8) );

        /* TODO: read all loco's and add them to the list */
        iONode list = NodeOp.findNode( plan, wCarList.name() );

        if( list != NULL ) {
          int i = 0;
          int cnt = NodeOp.getChildCnt( list );
          TraceOp.trc( "cardlg", TRCLEVEL_INFO, __LINE__, 9999, "%d cars in list", cnt );
          for( i = 0; i < cnt; i++ ) {
            m_Props = (iONode)NodeOp.base.clone( NodeOp.getChild( list, i ) );

            iONode model = wxGetApp().getModel();
            if( model != NULL ) {
              iONode carlist = wPlan.getcarlist( model );
              if( carlist == NULL ) {
                carlist = NodeOp.inst( wCarList.name(), model, ELEMENT_NODE );
                NodeOp.addChild( model, carlist );
              }
              if( carlist != NULL ) {
                iONode car = NodeOp.inst( wCar.name(), carlist, ELEMENT_NODE );
                NodeOp.addChild( carlist, m_Props );
                initValues();
                onApply(event);
              }
            }
          }
        }
        else {
          TraceOp.trc( "cardlg", TRCLEVEL_INFO, __LINE__, 9999, "No cars found in %s", (const char*)fdlg->GetPath().mb_str(wxConvUTF8) );
        }


        NodeOp.base.del( plan );
      }
      else {
        TraceOp.trc( "cardlg", TRCLEVEL_EXCEPTION, __LINE__, 9999, "Plan [%s] is not parseable!", (const char*)fdlg->GetPath().mb_str(wxConvUTF8) );
      }
    }

  }
  fdlg->Destroy();
}



void CarDlg::initSubType(){
  m_SubType->Clear();

  if( m_Type->GetSelection() == 0 ) {
    m_SubType->Append( wxGetApp().getMsg( wCar.freight_boxcar ), (void*)wCar.freight_boxcar );
    m_SubType->Append( wxGetApp().getMsg( wCar.freight_gondola ), (void*)wCar.freight_gondola );
    m_SubType->Append( wxGetApp().getMsg( wCar.freight_flatcar ), (void*)wCar.freight_flatcar );
    m_SubType->Append( wxGetApp().getMsg( wCar.freight_reefer ), (void*)wCar.freight_reefer );
    m_SubType->Append( wxGetApp().getMsg( wCar.freight_stockcar ), (void*)wCar.freight_stockcar );
    m_SubType->Append( wxGetApp().getMsg( wCar.freight_tankcar ), (void*)wCar.freight_tankcar );
    m_SubType->Append( wxGetApp().getMsg( wCar.freight_wellcar ), (void*)wCar.freight_wellcar );
    m_SubType->Append( wxGetApp().getMsg( wCar.freight_hopper ), (void*)wCar.freight_hopper );
    m_SubType->Append( wxGetApp().getMsg( wCar.freight_caboose ), (void*)wCar.freight_caboose );
    m_SubType->Append( wxGetApp().getMsg( wCar.freight_autorack ), (void*)wCar.freight_autorack );
    m_SubType->Append( wxGetApp().getMsg( wCar.freight_autocarrier ), (void*)wCar.freight_autocarrier );
    m_SubType->Append( wxGetApp().getMsg( wCar.freight_logdumpcar ), (void*)wCar.freight_logdumpcar );
    m_SubType->Append( wxGetApp().getMsg( wCar.freight_coilcar ), (void*)wCar.freight_coilcar );
  }
  else {
    m_SubType->Append( wxGetApp().getMsg( wCar.passenger_coach ), (void*)wCar.passenger_coach );
    m_SubType->Append( wxGetApp().getMsg( wCar.passenger_lounge ), (void*)wCar.passenger_lounge );
    m_SubType->Append( wxGetApp().getMsg( wCar.passenger_dome ), (void*)wCar.passenger_dome );
    m_SubType->Append( wxGetApp().getMsg( wCar.passenger_express ), (void*)wCar.passenger_express );
    m_SubType->Append( wxGetApp().getMsg( wCar.passenger_dinner ), (void*)wCar.passenger_dinner );
    m_SubType->Append( wxGetApp().getMsg( wCar.passenger_sleeper ), (void*)wCar.passenger_sleeper );
    m_SubType->Append( wxGetApp().getMsg( wCar.passenger_baggage ), (void*)wCar.passenger_baggage );
    m_SubType->Append( wxGetApp().getMsg( wCar.passenger_postoffice ), (void*)wCar.passenger_postoffice );
  }
  if( m_Props != NULL && StrOp.len( wCar.getsubtype( m_Props ) ) > 0 )
    m_SubType->SetStringSelection( wxGetApp().getMsg( wCar.getsubtype( m_Props ) ) );
}


void CarDlg::onTypeSelect( wxCommandEvent& event ){
  initSubType();
}


void CarDlg::onApply( wxCommandEvent& event ){
  if( m_Props == NULL || !m_bSave )
    return;

  if( !evaluate() )
    return;

  if( !wxGetApp().isStayOffline() ) {
    /* Notify RocRail. */
    iONode cmd = NodeOp.inst( wModelCmd.name(), NULL, ELEMENT_NODE );
    wModelCmd.setcmd( cmd, wModelCmd.modify );
    NodeOp.addChild( cmd, (iONode)m_Props->base.clone( m_Props ) );
    wxGetApp().sendToRocrail( cmd );
    cmd->base.del(cmd);
  }
  else {
    wxGetApp().setLocalModelModified(true);
  }
  initIndex();
}


void CarDlg::onCancel( wxCommandEvent& event ){
  EndModal( 0 );
}


void CarDlg::onOK( wxCommandEvent& event ){
  if( m_bSave )
    onApply(event);
  EndModal( wxID_OK );
}

void CarDlg::onDoc( wxCommandEvent& event )
{
  doDoc( event, "cars");
}

void CarDlg::onListColClick( wxListEvent& event ) {
  if(m_SortCol == event.GetColumn())
    ms_Sort = !ms_Sort;
  else
    ms_Sort = true;

  m_SortCol = event.GetColumn();
  initIndex();
}


void CarDlg::evaluateFunctions() {
  if( m_Props == NULL )
    return;

  wxTextCtrl* l_desc[] = {m_F1Desc,m_F2Desc,m_F3Desc,m_F4Desc};
  wxSpinCtrl* l_fx[] = {m_F1x,m_F2x,m_F3x,m_F4x};
  wxTextCtrl* l_icon[] = {m_F1Icon,m_F2Icon,m_F3Icon,m_F4Icon};
  int f0 = 0;
  int function[] = {0,0,0,0};

  if( m_F0Desc->GetValue().Length() > 0 )
    f0 = 1;

  for( int i = 0; i < 4; i++ ) {
    if( l_desc[i]->GetValue().Length() > 0 )
      function[i] = 1;
  }


  TraceOp.trc( "locdlg", TRCLEVEL_INFO, __LINE__, 9999, "evaluate function group %d", m_FGroup + 1);

  iONode fundef = wCar.getfundef( m_Props );
  while( fundef != NULL ) {
    int fnr = wFunDef.getfn( fundef );
    if( fnr == 0 ) {
      wFunDef.settext( fundef, m_F0Desc->GetValue().mb_str(wxConvUTF8)  );
      wFunDef.setmappedfn( fundef, m_F0x->GetValue() );
      wFunDef.seticon( fundef, m_F0Icon->GetValue().mb_str(wxConvUTF8)  );
      f0 = 0;
    }
    else if( fnr >= 1 + m_FGroup*4 && fnr <= 4 + m_FGroup*4 ) {
      TraceOp.trc( "cardlg", TRCLEVEL_INFO, __LINE__, 9999, "modify function  %d", fnr );

      wFunDef.settext( fundef, l_desc[(fnr-1) - m_FGroup*4]->GetValue().mb_str(wxConvUTF8)  );
      wFunDef.setmappedfn( fundef, l_fx[(fnr-1) - m_FGroup*4]->GetValue() );
      wFunDef.seticon( fundef, l_icon[(fnr-1) - m_FGroup*4]->GetValue().mb_str(wxConvUTF8)  );

      function[(fnr-1) - m_FGroup*4] = 0;
    }
    fundef = wCar.nextfundef( m_Props, fundef );
  }

  if( f0 == 1 ) {
    fundef = NodeOp.inst( wFunDef.name(), m_Props, ELEMENT_NODE );
    NodeOp.addChild( m_Props, fundef );
    wFunDef.setfn( fundef, 0 );
    wFunDef.settext( fundef, m_F0Desc->GetValue().mb_str(wxConvUTF8)  );
    wFunDef.setmappedfn( fundef, m_F0x->GetValue() );
    wFunDef.seticon( fundef, m_F0Icon->GetValue().mb_str(wxConvUTF8)  );
  }

  for( int i = 0; i < 4; i++ ) {
    if( function[i] == 1 ) {
      int f = i +1 + m_FGroup*4;
      TraceOp.trc( "cardlg", TRCLEVEL_INFO, __LINE__, 9999, "adding function  %d", f );
      fundef = NodeOp.inst( wFunDef.name(), m_Props, ELEMENT_NODE );
      NodeOp.addChild( m_Props, fundef );
      wFunDef.setfn( fundef, f );
      wFunDef.settext( fundef, l_desc[i]->GetValue().mb_str(wxConvUTF8)  );
      wFunDef.setmappedfn( fundef, l_fx[i]->GetValue() );
      wFunDef.seticon( fundef, l_icon[i]->GetValue().mb_str(wxConvUTF8)  );
    }
  }

}


void CarDlg::initFunctions() {
  if( m_Props == NULL )
    return;

  wxStaticText* l_fn[] = {m_F1,m_F2,m_F3,m_F4};
  wxTextCtrl* l_desc[] = {m_F1Desc,m_F2Desc,m_F3Desc,m_F4Desc};
  wxSpinCtrl* l_fx[] = {m_F1x,m_F2x,m_F3x,m_F4x};
  wxTextCtrl* l_icon[] = {m_F1Icon,m_F2Icon,m_F3Icon,m_F4Icon};

  m_F0Desc->SetValue( _T("") );
  m_F0x->SetValue(0);
  m_F0Icon->SetValue( _T("") );

  for( int i = 0; i < 4; i++ ) {
    l_fn[i]->SetLabel( wxString::Format(_T("F%d"), i+1+m_FGroup*4 ) );
    l_desc[i]->SetValue( _T("") );
    l_fx[i]->SetValue(0);
    l_icon[i]->SetValue( _T("") );
  }

  iONode fundef = wCar.getfundef( m_Props );
  while( fundef != NULL ) {

    wxString fntxt( wFunDef.gettext( fundef ),wxConvUTF8 );
    int funnr = wFunDef.getfn( fundef );
    TraceOp.trc( "cardlg", TRCLEVEL_INFO, __LINE__, 9999,
        "function[%d] name[%s]", funnr, wFunDef.gettext( fundef ) );

    if( funnr == 0 ) {
      m_F0Desc->SetValue( fntxt );
      m_F0x->SetValue(wFunDef.getmappedfn(fundef));
      m_F0Icon->SetValue( wxString( wFunDef.geticon(fundef), wxConvUTF8) );
    }
    else if( funnr >= m_FGroup * 4 + 1 && funnr <= m_FGroup * 4 + 4) {
      l_desc[(funnr - 1) - m_FGroup * 4]->SetValue( fntxt );
      l_fx[(funnr - 1) - m_FGroup * 4]->SetValue( wFunDef.getmappedfn(fundef) );
      l_icon[(funnr - 1) - m_FGroup * 4]->SetValue( wxString( wFunDef.geticon(fundef), wxConvUTF8) );
    }

    fundef = wCar.nextfundef( m_Props, fundef );
  }

}

void CarDlg::onFG( wxCommandEvent& event )
{
  if( m_Props == NULL )
    return;

  evaluateFunctions();
  m_FGroup++;
  if( m_FGroup > 6 )
    m_FGroup = 0;
  initFunctions();
}

void CarDlg::initCVDesc() {
  for( int i = 0; i < 256; i++ )
    m_CVDesc[i] = "";

  m_CVDesc[  1]  = "Primary Address";
  m_CVDesc[  2]  = "Vstart";
  m_CVDesc[  3]  = "Acceleration Rate";
  m_CVDesc[  4]  = "Deceleration Rate";
  m_CVDesc[  5]  = "Vhigh";
  m_CVDesc[  6]  = "Vmid";
  m_CVDesc[  7]  = "Manufacturer Version No.";
  m_CVDesc[  8]  = "Manufactured ID";
  m_CVDesc[  9]  = "Total PWM Period";
  m_CVDesc[ 10]  = "EMF Feedback Cutout";
  m_CVDesc[ 11]  = "Packet Time-Out Value";
  m_CVDesc[ 12]  = "Power Source Conversion";
  m_CVDesc[ 13]  = "Alternate Mode Function Status F1-F8";
  m_CVDesc[ 14]  = "Alternate Mode Fnc. Status FL,F9-F12";
  m_CVDesc[ 15]  = "Decoder Lock";
  m_CVDesc[ 16]  = "Decoder Lock";
  m_CVDesc[ 17]  = "Extended Address";
  m_CVDesc[ 18]  = "Extended Address";
  m_CVDesc[ 19]  = "Consist Address";
  m_CVDesc[ 20]  = "Reserved by NMRA for future use";
  m_CVDesc[ 21]  = "Consist Addr Active for F1-F8";
  m_CVDesc[ 22]  = "Consist Addr Active for FL-F9-F12";
  m_CVDesc[ 23]  = "Acceleration Adjustment";
  m_CVDesc[ 24]  = "Deceleration Adjustment";
  m_CVDesc[ 25]  = "Speed Table/Mid-range Cab Speed Step";
  m_CVDesc[ 26]  = "Reserved by NMRA for future use";
  m_CVDesc[ 27]  = "Decoder Automatic Stopping Configuration";
  m_CVDesc[ 28]  = "Bi-Directional Communication Configuration";
  m_CVDesc[ 29]  = "Configuration Data #1";
  m_CVDesc[ 30]  = "Error Information";
  m_CVDesc[ 31]  = "Index High Byte";
  m_CVDesc[ 32]  = "Index Low Byte";

}

void CarDlg::onCVCell( wxGridEvent& event ) {
  m_iSelectedCV = event.GetRow();
  if( m_iSelectedCV == -1 )
    return;

  wxString str = m_CVList->GetCellValue( m_iSelectedCV, 2 );
  m_CVDescription->SetValue(str);
  m_CVDescription->Enable(true);
  m_CVDescModify->Enable(true);
  event.Skip();

}

void CarDlg::onCVModify( wxCommandEvent& event ) {
  if( m_iSelectedCV == -1 )
    return;

  wxString str = m_CVList->GetCellValue(m_iSelectedCV, 0 );
  long cvnr = 0;
  str.ToLong(&cvnr);
  if( cvnr < 256 ) {
    iONode cv = m_CVNodes[cvnr];
    wCVByte.setdesc( cv, m_CVDescription->GetValue().mb_str(wxConvUTF8) );
    m_CVList->SetCellValue(m_iSelectedCV, 2, m_CVDescription->GetValue() );
  }

}

void CarDlg::onShow( wxCommandEvent& event ) {
  evaluate();
}


void CarDlg::onListAvailableOnly( wxCommandEvent& event ) {
  initIndex();
}

void CarDlg::onF0Icon( wxMouseEvent& event )
{
  const char* imagepath = wGui.getimagepath( wxGetApp().getIni() );
  TraceOp.trc( "cardlg", TRCLEVEL_INFO, __LINE__, 9999, "imagepath = [%s]", imagepath );
  wxFileDialog* fdlg = new wxFileDialog(this, _T("Search icon image"),  wxString(imagepath,wxConvUTF8), _T(""),
      _T("PNG files (*.png)|*.png"), wxFD_OPEN);
  if( fdlg->ShowModal() == wxID_OK ) {
    m_F0Icon->SetValue( fdlg->GetFilename() );
  }
}


void CarDlg::onF1Icon( wxMouseEvent& event )
{
  const char* imagepath = wGui.getimagepath( wxGetApp().getIni() );
  TraceOp.trc( "cardlg", TRCLEVEL_INFO, __LINE__, 9999, "imagepath = [%s]", imagepath );
  wxFileDialog* fdlg = new wxFileDialog(this, _T("Search icon image"),  wxString(imagepath,wxConvUTF8), _T(""),
      _T("PNG files (*.png)|*.png"), wxFD_OPEN);
  if( fdlg->ShowModal() == wxID_OK ) {
    m_F1Icon->SetValue( fdlg->GetFilename() );
  }
}


void CarDlg::onF2Icon( wxMouseEvent& event )
{
  const char* imagepath = wGui.getimagepath( wxGetApp().getIni() );
  TraceOp.trc( "cardlg", TRCLEVEL_INFO, __LINE__, 9999, "imagepath = [%s]", imagepath );
  wxFileDialog* fdlg = new wxFileDialog(this, _T("Search icon image"),  wxString(imagepath,wxConvUTF8), _T(""),
      _T("PNG files (*.png)|*.png"), wxFD_OPEN);
  if( fdlg->ShowModal() == wxID_OK ) {
    m_F2Icon->SetValue( fdlg->GetFilename() );
  }
}


void CarDlg::onF3Icon( wxMouseEvent& event )
{
  const char* imagepath = wGui.getimagepath( wxGetApp().getIni() );
  TraceOp.trc( "cardlg", TRCLEVEL_INFO, __LINE__, 9999, "imagepath = [%s]", imagepath );
  wxFileDialog* fdlg = new wxFileDialog(this, _T("Search icon image"),  wxString(imagepath,wxConvUTF8), _T(""),
      _T("PNG files (*.png)|*.png"), wxFD_OPEN);
  if( fdlg->ShowModal() == wxID_OK ) {
    m_F3Icon->SetValue( fdlg->GetFilename() );
  }
}


void CarDlg::onF4Icon( wxMouseEvent& event )
{
  const char* imagepath = wGui.getimagepath( wxGetApp().getIni() );
  TraceOp.trc( "cardlg", TRCLEVEL_INFO, __LINE__, 9999, "imagepath = [%s]", imagepath );
  wxFileDialog* fdlg = new wxFileDialog(this, _T("Search icon image"),  wxString(imagepath,wxConvUTF8), _T(""),
      _T("PNG files (*.png)|*.png"), wxFD_OPEN);
  if( fdlg->ShowModal() == wxID_OK ) {
    m_F4Icon->SetValue( fdlg->GetFilename() );
  }
}


void CarDlg::onHelp( wxCommandEvent& event ) {
  switch( m_CarBook->GetSelection() ) {
  case 0: wxGetApp().openLink( "car" ); break;
  case 1: wxGetApp().openLink( "car-gen" ); break;
  case 2: wxGetApp().openLink( "car-details" ); break;
  case 3: wxGetApp().openLink( "car-int" ); break;
  case 4: wxGetApp().openLink( "car-fun" ); break;
  case 5: wxGetApp().openLink( "car:car-cv" ); break;
  default: wxGetApp().openLink( "car" ); break;
  }
}

