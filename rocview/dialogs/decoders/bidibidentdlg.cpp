/*
 Rocrail - Model Railroad Software

 Copyright (C) 2002-2014 Rob Versluis, Rocrail.net

 

 Without an official permission commercial use is not permitted.
 Forking this project is not permitted.

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

#include "bidibidentdlg.h"

#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#include "wx/wx.h"
#include "wx/defs.h"
#endif

#include <wx/clipbrd.h>
#include <wx/dataobj.h>
#include <wx/dnd.h>
#include <wx/filedlg.h>

#include "rocs/public/trace.h"
#include "rocs/public/system.h"
#include "rocs/public/strtok.h"
#include "rocs/public/file.h"

#include "rocview/public/guiapp.h"
#include "rocview/wrapper/public/Gui.h"

#include "rocutils/public/vendors.h"
#include "rocrail/wrapper/public/FreeRail.h"
#include "rocrail/wrapper/public/DigInt.h"
#include "rocrail/wrapper/public/Program.h"
#include "rocrail/wrapper/public/Switch.h"
#include "rocrail/wrapper/public/Output.h"
#include "rocrail/wrapper/public/BiDiB.h"
#include "rocrail/wrapper/public/BiDiBnode.h"
#include "rocrail/wrapper/public/Macro.h"
#include "rocrail/wrapper/public/MacroLine.h"
#include "rocrail/wrapper/public/DataReq.h"
#include "rocrail/wrapper/public/ProductList.h"
#include "rocrail/wrapper/public/Product.h"
#include "rocdigs/impl/bidib/bidibutils.h"
#include "rocdigs/impl/bidib/bidib_messages.h"

#include "rocview/res/icons.hpp"


BidibIdentDlg::BidibIdentDlg( wxWindow* parent ):BidibIdentDlgGen( parent )
{
  this->node = NULL;
  __initVendors();
  initProducts();
  initLabels();
  m_Notebook->SetSelection( 0 );
}

BidibIdentDlg::BidibIdentDlg( wxWindow* parent, iONode node ):BidibIdentDlgGen( parent )
{
  this->node = node;
  __initVendors();
  initProducts();
  initLabels();
  initValues();
  m_Notebook->SetSelection( 0 );
}

BidibIdentDlg::~BidibIdentDlg() {
  ListOp.base.del(nodeList);
  MapOp.base.del(nodeMap);
  MapOp.base.del(nodePathMap);
  if( this->node != NULL )
    NodeOp.base.del(this->node);
  if( m_ProductsNode != NULL )
    NodeOp.base.del(m_ProductsNode);
  if( m_ProductsMap != NULL )
    MapOp.base.del(m_ProductsMap);
  clearFeatureList();
}


void BidibIdentDlg::initProducts() {
  char* l_path = StrOp.fmt( "%s%c%s", wGui.getdecpath( wxGetApp().getIni() ), SystemOp.getFileSeparator(), "bidib.xml" );
  m_ProductsMap = MapOp.inst();
  if( FileOp.exist(l_path) ) {
    iOFile f = FileOp.inst( l_path, OPEN_READONLY );
    char* buffer = (char*)allocMem( FileOp.size( f ) +1 );
    FileOp.read( f, buffer, FileOp.size( f ) );
    FileOp.base.del( f );
    iODoc doc = DocOp.parse( buffer );
    if( doc != NULL ) {
      m_ProductsNode = DocOp.getRootNode( doc );
      DocOp.base.del( doc );

      if( m_ProductsNode != NULL ) {
        iONode list = NodeOp.findNode(m_ProductsNode, wProductList.name());
        if( list != NULL ) {
          iONode product = NodeOp.findNode(list, wProduct.name());
          while( product != NULL ) {
            char key[32];
            StrOp.fmtb( key, "%d-%d", wProduct.getvid(product), wProduct.getpid(product));
            TraceOp.trc( "bidibident", TRCLEVEL_INFO, __LINE__, 9999,"product key=%s %s", key, wProduct.getdesc(product) );
            MapOp.put( m_ProductsMap, key, (obj)product);
            product = NodeOp.findNextNode( list, product );
          }
        }
      }
    }
    freeMem(buffer);
  }
  StrOp.free(l_path);
}


void BidibIdentDlg::onClose( wxCloseEvent& event ) {
  wxGetApp().getFrame()->resetBidibIdentRef();
  Destroy();
}


void BidibIdentDlg::onCancel( wxCommandEvent& event ) {
  wxGetApp().getFrame()->resetBidibIdentRef();
  Destroy();
}


void BidibIdentDlg::onOK( wxCommandEvent& event ) {
  //wxClipboard* cb = new wxClipboard();
  wxClipboard* cb = wxTheClipboard;
  if( cb != NULL ) {
    //cb->UsePrimarySelection();
    if( cb->Open() ) {
      wxString text( m_UID->GetValue() );
      if( !text.IsEmpty() ) {
        wxTextDataObject *data = new wxTextDataObject( text );
        cb->SetData( data );
      }
      cb->Close();
    }
    //delete cb;
  }

  wxGetApp().getFrame()->resetBidibIdentRef();
  Destroy();
}

void BidibIdentDlg::event(iONode node) {
  TraceOp.trc( "bidibident", TRCLEVEL_INFO, __LINE__, 9999,"event cmd=%d", wProgram.getcmd( node ) );
  if(  wProgram.getcmd( node ) == wProgram.datarsp ) {
    handleFeature(node);
    NodeOp.base.del(node);
  }
  else if(  wProgram.getcmd( node ) == wProgram.type ) {
    char mnemonic[32];
    char* classname = bidibGetClassName(wProgram.getprod(node), mnemonic, NULL);
    char key[32];
    StrOp.fmtb(key, "[%s] %08X", mnemonic, wProgram.getmodid(node) );
    wxTreeItemId item = findTreeItem( m_Tree->GetRootItem(), wxString( key, wxConvUTF8));
    if( item.IsOk() ) {
      m_Tree->SelectItem(item);
      m_Tree->ScrollTo(item);
    }
    StrOp.free(classname);
    NodeOp.base.del(node);
  }
  else if(  wProgram.getcmd( node ) == wProgram.setstring && wProgram.getval1(node) == 1 ) {
    char mnemonic[32];
    char* classname = bidibGetClassName(wProgram.getprod(node), mnemonic, NULL);
    char key[256];
    StrOp.fmtb(key, "[%s] %08X", mnemonic, wProgram.getmodid(node) );
    wxTreeItemId item = findTreeItem( m_Tree->GetRootItem(), wxString( key, wxConvUTF8));
    if( item.IsOk() ) {
      iONode l_bidibnode = (iONode)MapOp.get( nodeMap, key );
      if( l_bidibnode != NULL ) {
        TraceOp.trc( "bidibident", TRCLEVEL_INFO, __LINE__, 9999,"bidibnode %s found, new username=%s", key, wProgram.getstrval1(node) );
        wBiDiBnode.setusername(l_bidibnode, wProgram.getstrval1(node));
      }
      else
        TraceOp.trc( "bidibident", TRCLEVEL_WARNING, __LINE__, 9999,"bidibnode %s not found", key );

      m_Tree->SelectItem(item);
      m_Tree->ScrollTo(item);
      StrOp.fmtb(key, "[%s] %08X %s", mnemonic, wProgram.getmodid(node), wProgram.getstrval1(node) );
      m_Tree->SetItemText(item, wxString( key, wxConvUTF8) );
    }
    StrOp.free(classname);
    NodeOp.base.del(node);
  }
  else if(  wProgram.getcmd( node ) == wProgram.vendorcvget ) {
    eventUpdate = true;
    m_VendorCVName->SetValue( wxString( wProgram.getstrval1(node),wxConvUTF8));
    m_VendorCVValue->SetValue( wxString( wProgram.getstrval2(node),wxConvUTF8));
    eventUpdate = false;
    NodeOp.base.del(node);
  }
  else if(  wProgram.getcmd( node ) == wProgram.nvget ) {
    eventUpdate = true;
    int porttype = wProgram.getporttype(node);
    m_PortType->SetSelection(porttype);
    if( porttype == 0 ) {
      // SPORT
      m_PortIOSelection->SetSelection(wProgram.getval1(node));
      m_PortTimer->SetValue(wProgram.getval2(node));
      m_ServoLeft->SetValue( 0);
      m_ServoRight->SetValue( 0);
      m_ServoSpeed->SetValue( 0);
      m_ServoReserved->SetValue( 0);
      m_ConfigL->SetValue( 0);
      m_ConfigR->SetValue( 0);
      m_ConfigV->SetValue( 0);
      m_ConfigS->SetValue( 0);
    }
    else {
      m_PortIOSelection->SetSelection(0);
      m_PortTimer->SetValue(0);
      m_ServoLeft->SetValue( wProgram.getval1(node));
      m_ServoRight->SetValue( wProgram.getval2(node));
      m_ServoSpeed->SetValue( wProgram.getval3(node));
      m_ServoReserved->SetValue( wProgram.getval4(node));
      m_ConfigL->SetValue( wProgram.getval1(node));
      m_ConfigR->SetValue( wProgram.getval2(node));
      m_ConfigV->SetValue( wProgram.getval3(node));
      m_ConfigS->SetValue( wProgram.getval4(node));
    }
    eventUpdate = false;
    NodeOp.base.del(node);
  }
  else if(  wProgram.getcmd( node ) == wProgram.writehex ) {
    int rc = wProgram.getrc( node );
    int rs = wProgram.getrs( node );
    if( rc == 0 && rs == 0 ) {
      m_UpdateStart->Enable(true);
      m_UpdateStart->SetLabel( wxGetApp().getMsg( "start" ) );
      m_UpdateProgress->SetValue(0);
    }
    else if( rc == 0 && rs <= m_UpdateProgress->GetRange() ) {
      m_UpdateProgress->SetValue(rs);
    }
    else {
      m_UpdateStart->Enable(true);
      m_UpdateStart->SetLabel( wxGetApp().getMsg( "start" ) );
      m_UpdateProgress->SetValue(0);
      if( rc == wProgram.rc_notfwup) {
        // no firmware update flag
        wxMessageDialog( this, wxT("No firmware update feature read."), _T("Rocrail"), wxOK | wxICON_EXCLAMATION ).ShowModal();
      }
      else if( rc == wProgram.rc_error) {
        // firmware update error in rs
        wxMessageDialog( this, wxT("Firmware update error:") + wxString::Format(wxT(" %d"), rs), _T("Rocrail"), wxOK | wxICON_EXCLAMATION ).ShowModal();
      }
    }
  }
  else if( wProgram.getcmd( node ) == wProgram.macro_get || wProgram.getcmd( node ) == wProgram.macro_getparams ) {
    handleMacro(node);
    NodeOp.base.del(node);
  }
  else if( wProgram.getcmd( node ) == wProgram.macro_set || wProgram.getcmd( node ) == wProgram.macro_setparams ) {
    handleMacro(node);
    NodeOp.base.del(node);
  }
  else if( wProgram.getcmd( node ) == wProgram.acc_getparam || wProgram.getcmd( node ) == wProgram.acc_setparam ) {
    handleAccessory(node);
    NodeOp.base.del(node);
  }
  else if( !StrOp.equals( wProgram.name(), NodeOp.getName(node) ) ) {
    if( this->node != NULL )
      NodeOp.base.del(this->node);
    this->node = node;
    initValues();
  }
}


static int __sortPath(obj* _a, obj* _b)
{
    iONode a = (iONode)*_a;
    iONode b = (iONode)*_b;
    return strcmp( wBiDiBnode.getpath(a), wBiDiBnode.getpath(b) );
}


int BidibIdentDlg::getLevel(const char* path, int* n, int* o, int* p, char** key, char** parentkey ) {
  int level = 4;
  int idx = 0;
  iOStrTok tok = StrTokOp.inst(path, '.');

  *n = 0;
  *o = 0;
  *p = 0;

  const char* prevLevel = "0";
  while(StrTokOp.hasMoreTokens(tok) ) {
    const char* s = StrTokOp.nextToken(tok);
    if( idx == 0 ) {
      *key = StrOp.cat( *key, s);
      if( atoi(s) == 0) {
        level = 0;
        TraceOp.trc( "bidibident", TRCLEVEL_INFO, __LINE__, 9999,"level=%d path=%s key=%s", level, path, *key );
        break;
      }
    }

    if( idx == 1 ) {
      *n = atoi(prevLevel);
      *parentkey = StrOp.dup(*key);
      (*parentkey)[StrOp.len(*parentkey)-1] = '0';
      *key = StrOp.cat( *key, ".");
      *key = StrOp.cat( *key, s);
      if( atoi(s) == 0) {
        level = 1;
        TraceOp.trc( "bidibident", TRCLEVEL_INFO, __LINE__, 9999,"level=%d path=%s key=%s parent=%s", level, path, *key, *parentkey );
        break;
      }
    }
    if( idx == 2 ) {
      *o = atoi(prevLevel);
      *parentkey = StrOp.dup(*key);
      (*parentkey)[StrOp.len(*parentkey)-1] = '0';
      *key = StrOp.cat( *key, ".");
      *key = StrOp.cat( *key, s);
      if( atoi(s) == 0) {
        level = 2;
        TraceOp.trc( "bidibident", TRCLEVEL_INFO, __LINE__, 9999,"level=%d path=%s key=%s parent=%s", level, path, *key, *parentkey );
        break;
      }
    }
    if( idx == 3 ) {
      *p = atoi(prevLevel);
      *parentkey = StrOp.dup(*key);
      *key = StrOp.cat( *key, ".");
      *key = StrOp.cat( *key, s);
      if( atoi(s) == 0) {
        (*parentkey)[StrOp.len(*parentkey)-1] = '0';
        level = 3;
        TraceOp.trc( "bidibident", TRCLEVEL_INFO, __LINE__, 9999,"level=%d path=%s key=%s parent=%s", level, path, *key, *parentkey );
        break;
      }
      else {
        *parentkey = StrOp.cat( *parentkey, ".0");
        level = 4;
        TraceOp.trc( "bidibident", TRCLEVEL_INFO, __LINE__, 9999,"level=%d path=%s key=%s parent=%s", level, path, *key, *parentkey );
        break;
      }
    }

    prevLevel = s;
    idx++;
  };

  StrTokOp.base.del(tok);

  return level;
}

wxTreeItemId BidibIdentDlg::addTreeChild( const wxTreeItemId& root, iONode bidibnode) {
  char key[256];
  StrOp.fmtb(key, "[%s] %08X %s", wBiDiBnode.getclassmnemonic(bidibnode), wBiDiBnode.getuid(bidibnode), wBiDiBnode.getusername(bidibnode) );
  TraceOp.trc( "bidibident", TRCLEVEL_INFO, __LINE__, 9999,"append tree node: key=%s", key );
  wxTreeItemId item = m_Tree->AppendItem( root, wxString( key, wxConvUTF8));
  StrOp.fmtb(key, "[%s] %08X", wBiDiBnode.getclassmnemonic(bidibnode), wBiDiBnode.getuid(bidibnode) );
  MapOp.put( nodeMap, key, (obj)bidibnode);
  MapOp.put( nodePathMap, wBiDiBnode.getpath(bidibnode), (obj)bidibnode);
  return item;
}


void BidibIdentDlg::initLabels() {
  m_Notebook->SetPageText( 0, wxGetApp().getMsg( "index" ) );
  m_Notebook->SetPageText( 1, wxGetApp().getMsg( "features" ) );
  m_Notebook->SetPageText( 2, wxGetApp().getMsg( "accessory" ) );
  m_Notebook->SetPageText( 3, wxGetApp().getMsg( "portsetup" ) );
  m_Notebook->SetPageText( 4, wxGetApp().getMsg( "macro" ) );
  m_Notebook->SetPageText( 5, wxGetApp().getMsg( "firmware" ) );

  m_MacroPanel->Enable(false);

  m_BiDiBlogo->SetBitmap(*_img_bidib);
  m_BiDiBlogo->SetToolTip(wxT("http://www.bidib.org"));


  // Index
  m_labPath->SetLabel(wxGetApp().getMsg( "path" ));
  m_labVendor->SetLabel(wxGetApp().getMsg( "vendor" ));
  m_labProduct->SetLabel(wxGetApp().getMsg( "product" ));
  m_labClass->SetLabel(wxGetApp().getMsg( "class" ));
  m_labUID->SetLabel(wxGetApp().getMsg( "uid" ));
  m_labVersion->SetLabel(wxGetApp().getMsg( "version" ));
  m_Report->SetLabel(wxGetApp().getMenu( "report" ));

  // Features
  m_labIID->SetLabel(wxGetApp().getMsg( "iid" ));
  m_FeatureBox->GetStaticBox()->SetLabel(wxGetApp().getMsg( "featurecv" ));
  m_labFeature->SetLabel(wxGetApp().getMsg( "number" ));
  m_labFeatureValue->SetLabel(wxGetApp().getMsg( "value" ));
  m_FeaturesGet->SetLabel(wxGetApp().getMsg( "get" ));
  m_FeatureSet->SetLabel(wxGetApp().getMsg( "set" ));
  m_VendorCVBox->GetStaticBox()->SetLabel(wxGetApp().getMsg( "vendorcv" ));
  m_labVendorCVName->SetLabel(wxGetApp().getMsg( "name" ));
  m_labVendorCVValue->SetLabel(wxGetApp().getMsg( "value" ));
  m_VendorCVEnable->SetLabel(wxGetApp().getMsg( "enable" ));
  m_VendorCVDisable->SetLabel(wxGetApp().getMsg( "disable" ));
  m_VendorCVGet->SetLabel(wxGetApp().getMsg( "get" ));
  m_VendorCVSet->SetLabel(wxGetApp().getMsg( "set" ));

  // Accessory
  m_AccessoryPortBox->GetStaticBox()->SetLabel(wxGetApp().getMsg( "port" ));
  m_labAccessoryPort->SetLabel(wxGetApp().getMsg( "number" ));
  m_AccessoryOn->SetLabel(wxGetApp().getMsg( "on" ));
  m_AccessoryOff->SetLabel(wxGetApp().getMsg( "off" ));
  m_AccessoryOptionsBox->GetStaticBox()->SetLabel(wxGetApp().getMsg( "options" ));
  m_labAccessorySwitchTime->SetLabel(wxGetApp().getMsg( "switchtime" ));
  m_AccessorySwitchTimeSeconds->SetLabel(wxGetApp().getMsg( "seconds" ));
  m_AccessoryReadOptions->SetLabel(wxGetApp().getMsg( "get" ));
  m_AccessoryWriteOptions->SetLabel(wxGetApp().getMsg( "set" ));
  m_AccessoryMacroMapBox->GetStaticBox()->SetLabel(wxGetApp().getMsg( "macromap" ));
  m_AccessoryReadMacroMap->SetLabel(wxGetApp().getMsg( "get" ));
  m_AccessoryWriteMacroMap->SetLabel(wxGetApp().getMsg( "set" ));

  // Port setup
  m_PortType->SetLabel(wxGetApp().getMsg( "type" ));
  m_PortType->SetString( 0, wxGetApp().getMsg( "output" ) );
  m_PortType->SetString( 1, wxGetApp().getMsg( "lights" ) );
  m_PortType->SetString( 2, wxGetApp().getMsg( "servo" ) );
  m_PortType->SetString( 3, wxGetApp().getMsg( "sound" ) );
  m_PortType->SetString( 4, wxGetApp().getMsg( "motor" ) );
  m_PortType->SetString( 5, wxGetApp().getMsg( "analog" ) );
  m_PortType->SetString( 6, wxGetApp().getMsg( "macro" ) );
  m_PortType->SetString( 7, wxGetApp().getMsg( "backlight" ) );
  m_PortBox->GetStaticBox()->SetLabel(wxGetApp().getMsg( "port" ));
  m_labPortNumber->SetLabel(wxGetApp().getMsg( "number" ));
  m_PortIOConfigBox->GetStaticBox()->SetLabel(wxGetApp().getMsg( "properties" ));
  m_labPortTimer->SetLabel(wxGetApp().getMsg( "timer" ));
  m_ServoGet->SetLabel(wxGetApp().getMsg( "get" ));
  m_PortSet->SetLabel(wxGetApp().getMsg( "set" ));
  m_ServoTestBox->GetStaticBox()->SetLabel(wxGetApp().getMsg( "test" ));
  m_ServoLeftTest->SetLabel(wxGetApp().getMsg( "on" ));
  m_ServoRightTest->SetLabel(wxGetApp().getMsg( "off" ));

  // Macro
  m_labMacroList->SetLabel(wxGetApp().getMsg( "macro" ) + wxT(":"));
  m_labMacroSlowdown->SetLabel(wxGetApp().getMsg( "slowdown" ));
  m_labCycles->SetLabel(wxGetApp().getMsg( "cycles" ));
  m_labMacroTime->SetLabel(wxGetApp().getMsg( "time" ));
  m_MacroStartBox->GetStaticBox()->SetLabel(wxGetApp().getMsg( "every" ));
  m_MacroStartDaily->SetLabel(wxGetApp().getMsg( "day" ));
  m_MacroStartHourly->SetLabel(wxGetApp().getMsg( "hour" ));
  m_MacroStart30->SetLabel(wxT("30 ") + wxGetApp().getMsg( "minutes" ));
  m_MacroStart15->SetLabel(wxT("15 ") + wxGetApp().getMsg( "minutes" ));
  m_MacroStart1->SetLabel(wxGetApp().getMsg( "minute" ));
  m_labMacroDelay->SetLabel(wxGetApp().getMsg( "delay" ));
  m_labMacroType->SetLabel(wxGetApp().getMsg( "type" ));
  m_labMacroPort->SetLabel(wxGetApp().getMsg( "port" ));
  m_labMacroValue->SetLabel(wxGetApp().getMsg( "value" ));

  m_MacroApply->SetLabel(wxGetApp().getMsg( "apply" ));
  m_MacroReload->SetLabel(wxGetApp().getMsg( "get" ));
  m_MacroSave->SetLabel(wxGetApp().getMsg( "set" ));
  m_MacroExport->SetLabel(wxGetApp().getMsg( "export" ) + wxT("..."));
  m_MacroImport->SetLabel(wxGetApp().getMsg( "import" ) + wxT("..."));
  m_MacroSaveMacro->SetLabel(wxGetApp().getMsg( "save" ));
  m_MacroDeleteMacro->SetLabel(wxGetApp().getMsg( "delete" ));
  m_MacroRestoreMacro->SetLabel(wxGetApp().getMsg( "restore" ));
  m_MacroTest->SetLabel(wxGetApp().getMsg( "test" ));

  m_MacroLines->SetColLabelValue(0, wxGetApp().getMsg("delay") );
  m_MacroLines->SetColLabelValue(1, wxGetApp().getMsg("type") );
  m_MacroLines->SetColLabelValue(2, wxGetApp().getMsg("port") );
  m_MacroLines->SetColLabelValue(3, wxGetApp().getMsg("value") );
  m_MacroLines->AutoSizeColumns(false);

  m_MacroType->Append( wxGetApp().getMsg( "default" ) );
  m_MacroType->Append( wxGetApp().getMsg( "lights" ) );
  m_MacroType->Append( wxGetApp().getMsg( "servo" ) );
  m_MacroType->Append( wxGetApp().getMsg( "sound" ) );
  m_MacroType->Append( wxGetApp().getMsg( "motor" ) );
  m_MacroType->Append( wxGetApp().getMsg( "analog" ) );

  // Update
  m_labUpdateFile->SetLabel(wxGetApp().getMsg( "file" ));
  m_labUpdateFilePreview->SetLabel(wxGetApp().getMsg( "preview" ) + wxT(":"));
  m_UpdateStart->SetLabel(wxGetApp().getMsg( "start" ));

  nodeMap  = MapOp.inst();
  nodePathMap  = MapOp.inst();
  nodeList = ListOp.inst();
  bidibnode = NULL;
  macro = 0;
  macroline = 0;
  macrosize = 0;
  macrolevel = 0;
  macroparam = 0;
  macrosave = false;
  macroapply = false;
  configL = 0;
  configR = 0;
  configV = 0;
  configS = 0;
  www = NULL;
  uid = 0;
  eventUpdate = false;
  servoSetMutex = MutexOp.inst(NULL, True);
  m_SelectedBidibNode = NULL;
  m_ProductsNode = NULL;


  iONode l_RocrailIni = wxGetApp().getFrame()->getRocrailIni();
  if( l_RocrailIni != NULL ) {
    iONode digint = wFreeRail.getdigint(l_RocrailIni);
    while( digint != NULL ) {
      iONode bidib = wDigInt.getbidib(digint);
      if( bidib != NULL ) {
        m_IID->SetValue( wxString( wDigInt.getiid(digint), wxConvUTF8) );
        iONode bidibnode = wBiDiB.getbidibnode(bidib);
        while( bidibnode != NULL ) {
          ListOp.add(nodeList, (obj)bidibnode);
          bidibnode = wBiDiB.nextbidibnode( bidib, bidibnode );
        }
        break;
      }
      digint = wFreeRail.nextdigint(l_RocrailIni, digint);
    }
  }

  /*
  wxImageList* imgList = new wxImageList(32, 20);
  imgList->Add(wxIcon(pcb_xpm));
  m_Tree->AssignImageList(imgList);
  */
  if( ListOp.size(nodeList) > 0 ) {
    ListOp.sort(nodeList, &__sortPath);

    /*
     *       0.0.0.0    Level 0 Root
     *     1.0.0.0      Level 1
     *   1.1.0.0        Level 2
     * 1.1.1.0          Level 3
     *     2.0.0.0      Level 1
     *   1.2.0.0        Level 2
     */
    iOList r1 = ListOp.inst();
    iOList r2 = ListOp.inst();
    iOList r3 = ListOp.inst();
    iOList r4 = ListOp.inst();

    iOMap m1 = MapOp.inst();

    int listSize = ListOp.size(nodeList);
    for( int i = 1; i < listSize; i++ ) {
      iONode bidibnode = (iONode)ListOp.get( nodeList, i );
      TraceOp.trc( "bidibident", TRCLEVEL_INFO, __LINE__, 9999,"bidibnode path=%s, %d of %d", wBiDiBnode.getpath(bidibnode), i, listSize );

      char* parentkey = NULL;
      char* key = NULL;
      int n = 0;
      int o = 0;
      int p = 0;
      int childLevel = getLevel(wBiDiBnode.getpath(bidibnode), &n, &o, &p, &key, &parentkey);
      if( key != NULL ) {
        if( parentkey != NULL ) {
          TraceOp.trc( "bidibident", TRCLEVEL_INFO, __LINE__, 9999,"parentkey=%s key=%s path=%s", parentkey, key, wBiDiBnode.getpath(bidibnode) );
          wBiDiBnode.setparentkey(bidibnode, parentkey);
          StrOp.free(parentkey);
        }
        wBiDiBnode.setkey(bidibnode, key);
        StrOp.free(key);
      }


      if( childLevel == 1 ) {
        TraceOp.trc( "bidibident", TRCLEVEL_INFO, __LINE__, 9999,"[%d] path=%s", n, wBiDiBnode.getpath(bidibnode) );
        ListOp.add(r1, (obj)bidibnode);
      }
      else if( childLevel == 2 ) {
        TraceOp.trc( "bidibident", TRCLEVEL_INFO, __LINE__, 9999,"[%d][%d] path=%s", n, o, wBiDiBnode.getpath(bidibnode) );
        ListOp.add(r2, (obj)bidibnode);
      }
      else if( childLevel == 3 ) {
        TraceOp.trc( "bidibident", TRCLEVEL_INFO, __LINE__, 9999,"[%d][%d][%d] path=%s", n, o, p, wBiDiBnode.getpath(bidibnode) );
        ListOp.add(r3, (obj)bidibnode);
      }
      else {
        TraceOp.trc( "bidibident", TRCLEVEL_INFO, __LINE__, 9999,"path=%s", wBiDiBnode.getpath(bidibnode) );
        ListOp.add(r4, (obj)bidibnode);
      }
    }


    iONode bidibnode = (iONode)ListOp.get( nodeList, 0 );
    iONode rootnode  = (iONode)ListOp.get( nodeList, 0 );

    char key[256];
    int level = 0;
    StrOp.fmtb(key, "[%s] %08X %s", wBiDiBnode.getclassmnemonic(bidibnode), wBiDiBnode.getuid(bidibnode), wBiDiBnode.getusername(bidibnode) );
    wxTreeItemId root  = m_Tree->AddRoot(wxString( key, wxConvUTF8));
    StrOp.fmtb(key, "[%s] %08X", wBiDiBnode.getclassmnemonic(bidibnode), wBiDiBnode.getuid(bidibnode) );
    MapOp.put( nodeMap, key, (obj)bidibnode);

    for(int n = 0; n < ListOp.size(r1); n++ ) {
      bidibnode = (iONode)ListOp.get(r1,n);
      wxTreeItemId* child = new wxTreeItemId( addTreeChild( root, bidibnode) );
      TraceOp.trc( "bidibident", TRCLEVEL_INFO, __LINE__, 9999,"put node with key=%s 0x%X", wBiDiBnode.getkey(bidibnode), &child );
      MapOp.put(m1, wBiDiBnode.getkey(bidibnode), (obj)child );
    }

    for(int o = 0; o < ListOp.size(r2); o++ ) {
      bidibnode = (iONode)ListOp.get(r2,o);
      const char* parentKey = wBiDiBnode.getparentkey(bidibnode);
      wxTreeItemId* parent = (wxTreeItemId*)MapOp.get(m1, parentKey );
      if( parent == NULL )
        TraceOp.trc( "bidibident", TRCLEVEL_WARNING, __LINE__, 9999,"no parent found with key=%s", parentKey );
      else {
        TraceOp.trc( "bidibident", TRCLEVEL_INFO, __LINE__, 9999,"parent found with key=%s for path=%s 0x%X", parentKey, wBiDiBnode.getpath(bidibnode), parent );
        wxTreeItemId* child = new wxTreeItemId(addTreeChild( *parent, bidibnode));
        MapOp.put(m1, wBiDiBnode.getkey(bidibnode), (obj)(child) );
      }
    }

    for(int p = 0; p < ListOp.size(r3); p++ ) {
      bidibnode = (iONode)ListOp.get(r3,p);
      const char* parentKey = wBiDiBnode.getparentkey(bidibnode);
      wxTreeItemId* parent = (wxTreeItemId*)MapOp.get(m1, parentKey );
      if( parent == NULL )
        TraceOp.trc( "bidibident", TRCLEVEL_WARNING, __LINE__, 9999,"no parent found with key=%s", parentKey );
      else {
        TraceOp.trc( "bidibident", TRCLEVEL_INFO, __LINE__, 9999,"parent found with key=%s for path=%s", parentKey, wBiDiBnode.getpath(bidibnode) );
        wxTreeItemId* child = new wxTreeItemId( addTreeChild( *parent, bidibnode) );
        MapOp.put(m1, wBiDiBnode.getkey(bidibnode), (obj)(child) );
      }
    }

    for(int q = 0; q < ListOp.size(r4); q++ ) {
      bidibnode = (iONode)ListOp.get(r4,q);
      const char* parentKey = wBiDiBnode.getparentkey(bidibnode);
      wxTreeItemId* parent = (wxTreeItemId*)MapOp.get(m1, parentKey );
      if( parent == NULL )
        TraceOp.trc( "bidibident", TRCLEVEL_WARNING, __LINE__, 9999,"no parent found with key=%s", parentKey );
      else {
        TraceOp.trc( "bidibident", TRCLEVEL_INFO, __LINE__, 9999,"parent found with key=%s for path=%s", parentKey, wBiDiBnode.getpath(bidibnode) );
        wxTreeItemId child = addTreeChild( *parent, bidibnode);
      }
    }

    ListOp.base.del(r1);
    ListOp.base.del(r2);
    ListOp.base.del(r3);
    ListOp.base.del(r4);

    wxTreeItemId* treeItem = (wxTreeItemId*)MapOp.first(m1);
    while( treeItem != NULL ) {
      delete treeItem;
      treeItem = (wxTreeItemId*)MapOp.next(m1);
    }
    MapOp.base.del(m1);

    m_Tree->ExpandAll();
    if( node == NULL ) {
      m_Tree->SelectItem(root, false);
      m_Tree->SelectItem(root, true);
    }
  }

  // Buttons
  m_stdButtonsOK->SetLabel( wxGetApp().getMsg( "ok" ) );
  m_stdButtonsCancel->SetLabel( wxGetApp().getMsg( "cancel" ) );
  m_stdButtonsHelp->SetLabel( wxGetApp().getMsg( "help" ) );


  // Resize
  m_IndexPanel->GetSizer()->Layout();
  m_FeaturesPanel->GetSizer()->Layout();
  m_AccessoryPanel->GetSizer()->Layout();
  m_ServoPanel->GetSizer()->Layout();
  m_MacroPanel->GetSizer()->Layout();
  m_UpdatePanel->GetSizer()->Layout();

  m_Notebook->Fit();

  GetSizer()->Fit(this);
  GetSizer()->SetSizeHints(this);

}


int BidibIdentDlg::getProductID(int uid) {
  int pid = (uid >> 16);
  pid = ((pid >> 8)&0x00FF) + ((pid << 8)&0xFF00);
  return pid;
}

const char* BidibIdentDlg::GetProductName(int vid, int pid, char** www) {
  char key[32];
  StrOp.fmtb( key, "%d-%d", vid, pid );
  TraceOp.trc( "bidibident", TRCLEVEL_INFO, __LINE__, 9999,"looking up product key=%s", key );
  iONode product = (iONode)MapOp.get( m_ProductsMap, key);
  if( product != NULL ) {
    TraceOp.trc( "bidibident", TRCLEVEL_INFO, __LINE__, 9999,"product from xml: %s", wProduct.getdesc(product) );
    *www = (char*)wProduct.geturl(product);
    return wProduct.getdesc(product);
  }
  TraceOp.trc( "bidibident", TRCLEVEL_INFO, __LINE__, 9999,"product key=%s not found", key );
  *www = (char*)"http://www.bidib.org/support/product_id.html";
  return "Unknown product.";
}


iONode BidibIdentDlg::findNodeByUID( const char* uid) {
  iONode node = (iONode)MapOp.first(nodeMap);
  while( node != NULL ) {
    char key[256];
    StrOp.fmtb(key, "%08X", wBiDiBnode.getuid(node) );
    if( StrOp.find(uid, key) != NULL ) {
      return node;
    }
    node = (iONode)MapOp.next(nodeMap);
  }
  return NULL;
}


void BidibIdentDlg::onTreeSelChanged( wxTreeEvent& event ) {
  wxString itemText = m_Tree->GetItemText(event.GetItem());
  char* uid = StrOp.dup(itemText.mb_str(wxConvUTF8));
  bidibnode = (iONode)MapOp.get( nodeMap, uid );
  if( bidibnode == NULL )
    bidibnode = findNodeByUID(uid);

  if( bidibnode != NULL ) {
    TraceOp.trc( "bidibident", TRCLEVEL_INFO, __LINE__, 9999,"tree selection: %s (%s)", wBiDiBnode.getpath(bidibnode), uid );
    TraceOp.trc( "bidibident", TRCLEVEL_INFO, __LINE__, 9999,"vid=%d uid=%d", wBiDiBnode.getvendor(bidibnode), wBiDiBnode.getuid(bidibnode) );

    m_Path->SetValue( wxString( wBiDiBnode.getpath(bidibnode), wxConvUTF8) );
    //m_UID->SetValue( wxString( uid, wxConvUTF8 ) );
    m_UID->SetValue( wxString::Format(_T("%d"), wBiDiBnode.getuid(bidibnode) ) );
    m_UIDX->SetValue( wxString::Format(_T("%08X"), wBiDiBnode.getuid(bidibnode) ) );
    m_VID->SetValue( wxString::Format(_T("%02X"), wBiDiBnode.getvendor(bidibnode)&0xFF ) );
    m_VIDD->SetValue( wxString::Format(_T("%d"), wBiDiBnode.getvendor(bidibnode)&0xFF ) );
    m_VendorName->SetValue( wxString( m_Vendor[wBiDiBnode.getvendor(bidibnode)&0xFF],wxConvUTF8) );
    m_Class->SetValue( wxString( wBiDiBnode.getclass(bidibnode), wxConvUTF8) );
    m_Version->SetValue( wxString( wBiDiBnode.getversion(bidibnode), wxConvUTF8) );

    int pid = getProductID(wBiDiBnode.getuid(bidibnode));
    m_PID->SetValue( wxString::Format(_T("%02X"), pid ) );
    m_PIDD->SetValue( wxString::Format(_T("%d"), pid ) );
    if(wBiDiBnode.getproductname(bidibnode) != NULL && StrOp.len(wBiDiBnode.getproductname(bidibnode)) > 0 ) {
      m_ProductName->SetValue( wxString(wBiDiBnode.getproductname(bidibnode), wxConvUTF8) );
      GetProductName(wBiDiBnode.getvendor(bidibnode)&0xFF, pid, &www);
      m_ProductName->SetToolTip(wxString(www, wxConvUTF8));
    }
    else {
      m_ProductName->SetValue( wxString( GetProductName(wBiDiBnode.getvendor(bidibnode)&0xFF, pid, &www), wxConvUTF8) );
      m_ProductName->SetToolTip(wxString(www, wxConvUTF8));
    }

    m_Username->SetValue( wxT("") );
    if(wBiDiBnode.getusername(bidibnode) != NULL && StrOp.len(wBiDiBnode.getusername(bidibnode)) > 0 ) {
      m_Username->SetValue( wxString(wBiDiBnode.getusername(bidibnode), wxConvUTF8) );
    }

    SetTitle(wxT("BiDiB: ") + wxString::Format(_T("%08X"), wBiDiBnode.getuid(bidibnode) ) + wxT(" ") + wxString( wBiDiBnode.getclass(bidibnode), wxConvUTF8) );

    const char* imagepath = wGui.getimagepath(wxGetApp().getIni());
    static char pixfile[256];
    static char pixpath[256];
    StrOp.fmtb( pixfile, "bidib-%d-%d.png", wBiDiBnode.getvendor(bidibnode)&0xFF, pid);
    StrOp.fmtb( pixpath, "%s%c%s", imagepath, SystemOp.getFileSeparator(), pixfile );

    if( FileOp.exist(pixpath)) {
      TraceOp.trc( "bidibident", TRCLEVEL_INFO, __LINE__, 9999, "picture [%s]", pixpath );
      m_Pict->SetBitmap( wxBitmap(wxString(pixpath,wxConvUTF8), wxBITMAP_TYPE_PNG) );
    }
    else {
      TraceOp.trc( "bidibident", TRCLEVEL_DEBUG, __LINE__, 9999, "picture [%s] not found", pixpath );
      iONode node = NodeOp.inst( wDataReq.name(), NULL, ELEMENT_NODE );
      wDataReq.setcmd( node, wDataReq.get );
      wDataReq.settype( node, wDataReq.image );
      wDataReq.setfilename( node, pixfile );
      wxGetApp().sendToRocrail( node );
      NodeOp.base.del(node);
      m_Pict->SetBitmap( wxBitmap(0,0) );
    }
    m_Pict->Refresh();
    m_IndexPanel->GetSizer()->Layout();
    m_Notebook->Fit();
    GetSizer()->Fit(this);
    GetSizer()->SetSizeHints(this);
    Refresh();

    m_UpdatePanel->Enable(wBiDiBnode.isfwup(bidibnode)?true:false);
    m_PortIOSelection->Enable( (wBiDiBnode.isiocfg(bidibnode) && m_PortType->GetSelection()==0) ? true:false);
    m_PortTimer->Enable( (wBiDiBnode.isiocfg(bidibnode) && m_PortType->GetSelection()==0) ? true:false);

  }
  else {
    TraceOp.trc( "bidibident", TRCLEVEL_INFO, __LINE__, 9999,"node not found: %s", uid );
    TraceOp.dump ( "bidibident", TRCLEVEL_INFO, (char*)uid, StrOp.len(uid) );
  }
  StrOp.free(uid);
}


void BidibIdentDlg::initValues() {
  if( node != NULL && StrOp.equals(wProgram.name(), NodeOp.getName(node)) ) {
    char mnemonic[32];
    char* classname = bidibGetClassName(wProgram.getprod(node), mnemonic, NULL);
    TraceOp.trc( "bidibident", TRCLEVEL_INFO, __LINE__, 9999, "%s", classname );

    m_Path->SetValue( wxString( wProgram.getfilename(node), wxConvUTF8) );
    m_UID->SetValue( wxString::Format(_T("%d"), wProgram.getmodid(node) ) );
    m_UIDX->SetValue( wxString::Format(_T("%08X"), wProgram.getmodid(node) ) );
    m_VID->SetValue( wxString::Format(_T("%02X"), wProgram.getmanu(node)&0xFF ) );
    m_VIDD->SetValue( wxString::Format(_T("%d"), wProgram.getmanu(node)&0xFF ) );
    m_VendorName->SetValue( wxString( m_Vendor[wProgram.getmanu(node)&0xFF],wxConvUTF8) );
    m_Class->SetValue( wxString( classname, wxConvUTF8) );
    StrOp.free(classname);
    m_Version->SetValue( wxString( wProgram.getstrval1(node), wxConvUTF8) );

    int pid = getProductID(wProgram.getmodid(node));
    m_PID->SetValue( wxString::Format(_T("%02X"), pid ) );
    m_PIDD->SetValue( wxString::Format(_T("%d"), pid ) );
    if(wBiDiBnode.getproductname(node) != NULL && StrOp.len(wBiDiBnode.getproductname(node)) > 0 ) {
      m_ProductName->SetValue( wxString(wBiDiBnode.getproductname(node), wxConvUTF8) );
      GetProductName(wBiDiBnode.getvendor(node)&0xFF, pid, &www);
      m_ProductName->SetToolTip(wxString(www, wxConvUTF8));
    }
    else {
      m_ProductName->SetValue( wxString( GetProductName(wProgram.getmanu(node)&0xFF, pid, &www), wxConvUTF8) );
      m_ProductName->SetToolTip(wxString(www, wxConvUTF8));
    }

    m_Username->SetValue( wxT("") );
    if(wBiDiBnode.getusername(node) != NULL && StrOp.len(wBiDiBnode.getusername(node)) > 0 ) {
      m_Username->SetValue( wxString(wBiDiBnode.getusername(node), wxConvUTF8) );
    }

    char key[256];
    StrOp.fmtb(key, "[%s] %08X", mnemonic, wProgram.getmodid(node) );
    wxTreeItemId item = findTreeItem( m_Tree->GetRootItem(), wxString( key, wxConvUTF8));
    if( item.IsOk() ) {
      m_Tree->SelectItem(item);
      m_Tree->ScrollTo(item);
    }
  }
  else if( node != NULL && StrOp.equals(wBiDiBnode.name(), NodeOp.getName(node)) ) {
    m_Path->SetValue( wxString( wBiDiBnode.getpath(node), wxConvUTF8) );
    //m_UID->SetValue( wxString( uid, wxConvUTF8 ) );
    m_UID->SetValue( wxString::Format(_T("%d"), wBiDiBnode.getuid(node) ) );
    m_UIDX->SetValue( wxString::Format(_T("%08X"), wBiDiBnode.getuid(node) ) );
    m_VID->SetValue( wxString::Format(_T("%02X"), wBiDiBnode.getvendor(node)&0xFF ) );
    m_VIDD->SetValue( wxString::Format(_T("%d"), wBiDiBnode.getvendor(node)&0xFF ) );
    m_VendorName->SetValue( wxString( m_Vendor[wBiDiBnode.getvendor(node)&0xFF],wxConvUTF8) );
    m_Class->SetValue( wxString( wBiDiBnode.getclass(node), wxConvUTF8) );
    m_Version->SetValue( wxString( wBiDiBnode.getversion(node), wxConvUTF8) );
    int pid = getProductID(wBiDiBnode.getuid(node));
    m_PID->SetValue( wxString::Format(_T("%02X"), pid ) );
    m_PIDD->SetValue( wxString::Format(_T("%d"), pid ) );
    if(wBiDiBnode.getproductname(node) != NULL && StrOp.len(wBiDiBnode.getproductname(node)) > 0 ) {
      m_ProductName->SetValue( wxString(wBiDiBnode.getproductname(node), wxConvUTF8) );
      GetProductName(wBiDiBnode.getvendor(node)&0xFF, pid, &www);
      m_ProductName->SetToolTip(wxString(www, wxConvUTF8));
    }
    else {
      m_ProductName->SetValue( wxString( GetProductName(wBiDiBnode.getvendor(node)&0xFF, pid, &www), wxConvUTF8) );
      m_ProductName->SetToolTip(wxString(www, wxConvUTF8));
    }

    m_Username->SetValue( wxT("") );
    if(wBiDiBnode.getusername(node) != NULL && StrOp.len(wBiDiBnode.getusername(node)) > 0 ) {
      m_Username->SetValue( wxString(wBiDiBnode.getusername(node), wxConvUTF8) );
    }

    SetTitle(wxT("BiDiB: ") + wxString::Format(_T("%08X"), wBiDiBnode.getuid(node) ) + wxT(" ") + wxString( wBiDiBnode.getclass(node), wxConvUTF8) );
  }
  else {
    TraceOp.trc( "bidibident", TRCLEVEL_INFO, __LINE__, 9999, "no node set" );
  }
}


wxTreeItemId BidibIdentDlg::findTreeItem( const wxTreeItemId& root, const wxString& text)
{
  wxTreeItemId item = root;
  wxTreeItemId child;
  wxTreeItemIdValue cookie;
  wxString findtext(text), itemtext;
  bool bFound;

  while(item.IsOk())
  {
    itemtext = m_Tree->GetItemText(item);
    bFound = itemtext.StartsWith(findtext);
    if(bFound)
      return item;
    child = m_Tree->GetFirstChild(item, cookie);
    if(child.IsOk())
      child = findTreeItem(child, text);
    if(child.IsOk())
      return child;
    item = m_Tree->GetNextSibling(item);
  }

  return item;
}


void BidibIdentDlg::onItemActivated( wxTreeEvent& event ) {
}


void BidibIdentDlg::onBeginDrag( wxTreeEvent& event ) {
  wxString itemText = m_Tree->GetItemText(event.GetItem());
  const char* uid = itemText.mb_str(wxConvUTF8);
  iONode bidibnode = (iONode)MapOp.get( nodeMap, uid );
  if( bidibnode == NULL )
    bidibnode = findNodeByUID(uid);

  if( bidibnode != NULL ) {
    char* dragText = StrOp.fmt("bus:%d", wBiDiBnode.getuid(bidibnode));
    TraceOp.trc( "bidibident", TRCLEVEL_INFO, __LINE__, 9999, "drag action for UID %s (%s)", dragText, uid );
    wxTextDataObject my_data( wxString(dragText,wxConvUTF8) );
    wxDropSource dragSource( this );
    dragSource.SetData( my_data );
    wxDragResult result = dragSource.DoDragDrop(wxDrag_CopyOnly);
    //event.Allow();
  }
}


void BidibIdentDlg::onMenu( wxCommandEvent& event ) {
  int menuItem = event.GetId();
  TraceOp.trc( "bidibident", TRCLEVEL_INFO, __LINE__, 9999, "action %d for UID %d", menuItem, wBiDiBnode.getuid(m_SelectedBidibNode) );
  if( menuItem == 1001 && m_SelectedBidibNode != NULL) {
    int pid = getProductID(wBiDiBnode.getuid(m_SelectedBidibNode));
    char* l_www;
    GetProductName(wBiDiBnode.getvendor(m_SelectedBidibNode)&0xFF, pid, &l_www);
    wxLaunchDefaultBrowser(wxString(l_www, wxConvUTF8), wxBROWSER_NEW_WINDOW );
  }
  else if( (menuItem == 1002 || menuItem == 1005) && m_SelectedBidibNode != NULL ) {
    iONode cmd = NodeOp.inst( wProgram.name(), NULL, ELEMENT_NODE );
    wProgram.setmodid(cmd, wBiDiBnode.getuid(m_SelectedBidibNode));
    wProgram.setcmd( cmd, wProgram.identify );
    wProgram.setvalue(cmd, (menuItem == 1002) ? 1:0);
    wProgram.setiid( cmd, m_IID->GetValue().mb_str(wxConvUTF8) );
    wProgram.setlntype(cmd, wProgram.lntype_bidib);
    wxGetApp().sendToRocrail( cmd );
    cmd->base.del(cmd);
  }
  else if( menuItem == 1003 && m_SelectedBidibNode != NULL ) {
    iONode cmd = NodeOp.inst( wProgram.name(), NULL, ELEMENT_NODE );
    wProgram.setmodid(cmd, wBiDiBnode.getuid(m_SelectedBidibNode));
    wProgram.setcmd( cmd, wProgram.ping );
    wProgram.setvalue(cmd, 1);
    wProgram.setiid( cmd, m_IID->GetValue().mb_str(wxConvUTF8) );
    wProgram.setlntype(cmd, wProgram.lntype_bidib);
    wxGetApp().sendToRocrail( cmd );
    cmd->base.del(cmd);
  }
  else if( menuItem == 1004 && m_SelectedBidibNode != NULL ) {
    iONode cmd = NodeOp.inst( wProgram.name(), NULL, ELEMENT_NODE );
    wProgram.setmodid(cmd, wBiDiBnode.getuid(m_SelectedBidibNode));
    wProgram.setcmd( cmd, wProgram.getlasterror );
    wProgram.setiid( cmd, m_IID->GetValue().mb_str(wxConvUTF8) );
    wProgram.setlntype(cmd, wProgram.lntype_bidib);
    wxGetApp().sendToRocrail( cmd );
    cmd->base.del(cmd);
  }
}

void BidibIdentDlg::onItemRightClick( wxTreeEvent& event ) {
  wxString itemText = m_Tree->GetItemText(event.GetItem());
  char* uid = StrOp.dup(itemText.mb_str(wxConvUTF8));
  m_SelectedBidibNode = (iONode)MapOp.get( nodeMap, uid );
  if( m_SelectedBidibNode == NULL )
    m_SelectedBidibNode = findNodeByUID(uid);
  TraceOp.trc( "bidibident", TRCLEVEL_INFO, __LINE__, 9999, "right click on UID %s", uid );
  StrOp.free(uid);
  if( m_SelectedBidibNode == NULL )
    return;
  wxMenu menu( wxString(wBiDiBnode.getpath( bidibnode ),wxConvUTF8) );
  menu.Append( 1001, wxGetApp().getMenu("info") );
  wxMenu* identMenu = new wxMenu();
  identMenu->Append( 1002, wxGetApp().getMenu("on") );
  identMenu->Append( 1005, wxGetApp().getMenu("off") );
  menu.Append(-1, wxGetApp().getMenu("identify"), identMenu);
  menu.Append( 1003, wxGetApp().getMenu("ping") );
  menu.Append( 1004, wxGetApp().getMenu("getlasterror") );
  menu.Connect( wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( BidibIdentDlg::onMenu ), NULL, this );
  identMenu->Connect( wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( BidibIdentDlg::onMenu ), NULL, this );

  PopupMenu(&menu );
}


void BidibIdentDlg::onFeatureSelect( wxCommandEvent& event ) {
  int sel = m_FeatureList->GetSelection();
  if( sel == wxNOT_FOUND )
    return;
  iONode node = (iONode)m_FeatureList->GetClientData(sel);
  if( node != NULL ) {
    m_Feature->SetValue(wProgram.getcv(node));
    m_FeatureValue->SetValue(wProgram.getvalue(node));
  }
}


void BidibIdentDlg::clearFeatureList() {
  while( m_FeatureList->GetCount() > 0 ) {
    iONode node = (iONode)m_FeatureList->GetClientData(0);
    NodeOp.base.del(node);
    m_FeatureList->Delete(0);
  }
}


void BidibIdentDlg::onFeaturesGet( wxCommandEvent& event ) {
  // Get all features.
  clearFeatureList();

  if( bidibnode != NULL ) {
    iONode cmd = NodeOp.inst( wProgram.name(), NULL, ELEMENT_NODE );
    wProgram.setmodid(cmd, wBiDiBnode.getuid(bidibnode));
    wProgram.setcmd( cmd, wProgram.evgetall );
    wProgram.setiid( cmd, m_IID->GetValue().mb_str(wxConvUTF8) );
    wProgram.setlntype(cmd, wProgram.lntype_bidib);
    wxGetApp().sendToRocrail( cmd );
    cmd->base.del(cmd);
  }
}


void BidibIdentDlg::onFeatureSet( wxCommandEvent& event ) {
  if( bidibnode != NULL ) {
    iONode cmd = NodeOp.inst( wProgram.name(), NULL, ELEMENT_NODE );
    wProgram.setmodid(cmd, wBiDiBnode.getuid(bidibnode));
    wProgram.setcmd( cmd, wProgram.set );
    wProgram.setcv( cmd, m_Feature->GetValue() );
    wProgram.setvalue( cmd, m_FeatureValue->GetValue() );
    wProgram.setiid( cmd, m_IID->GetValue().mb_str(wxConvUTF8) );
    wProgram.setlntype(cmd, wProgram.lntype_bidib);
    wxGetApp().sendToRocrail( cmd );
    cmd->base.del(cmd);
  }
}


void BidibIdentDlg::handleFeature(iONode node) {
  char mnemonic[32] = {'\0'};
  char* classname = bidibGetClassName(wProgram.getprod(node), mnemonic, NULL);
  StrOp.free(classname);

  char uidKey[256];
  StrOp.fmtb(uidKey, "[%s] %08X", mnemonic, wProgram.getmodid(node) );
  iONode l_bidibnode = (iONode)MapOp.get( nodeMap, uidKey );
  if( l_bidibnode != NULL ) {
    int feature = wProgram.getcv(node);
    const char* featureName = bidibGetFeatureName(feature);

    int i = wxNOT_FOUND;
    if( !m_FeatureList->IsEmpty() )
      i = m_FeatureList->FindString( wxString(featureName,wxConvUTF8) );

    if( i == wxNOT_FOUND ) {
      iONode program = (iONode)NodeOp.base.clone(node);
      int value   = wProgram.getvalue(node);
      m_FeatureList->Append( wxString(featureName,wxConvUTF8), program);

      if( feature == FEATURE_CTRL_MAC_COUNT ) {
        m_MacroList->Clear();
        for( int i = 0; i < value; i++ ) {
          m_MacroList->Append( wxString::Format(_T("macro %d"), i+1));
        }
        if( value > 0 ) {
          m_MacroList->Select(0);
          m_MacroList->SetFirstItem(0);
          m_MacroPanel->Enable(true);
        }
        else {
          m_MacroPanel->Enable(false);
        }
      }
      else if( feature == FEATURE_CTRL_MAC_SIZE ) {
        macrosize = value;
      }
      else if( feature == FEATURE_CTRL_MAC_LEVEL ) {
        macrolevel = value;
      }
    }
    else {
      // update feature values
      iONode program = (iONode)m_FeatureList->GetClientData(i);
      if( program != NULL ) {
        wProgram.setvalue( program, wProgram.getvalue(node));
      }
      if( i == m_FeatureList->GetSelection() ) {
        m_Feature->SetValue(wProgram.getcv(node));
        m_FeatureValue->SetValue(wProgram.getvalue(node));
      }
    }

  }
  else {
    TraceOp.trc( "bidibident", TRCLEVEL_INFO, __LINE__, 9999,"bidib node \"%s\" not found", uidKey );
  }
}


void BidibIdentDlg::onServoGet( wxCommandEvent& event ) {
  if( bidibnode != NULL ) {
    iONode cmd = NodeOp.inst( wProgram.name(), NULL, ELEMENT_NODE );
    wProgram.setmodid(cmd, wBiDiBnode.getuid(bidibnode));
    wProgram.setcmd( cmd, wProgram.nvget );
    wProgram.setcv( cmd, m_ServoPort->GetValue() );
    wProgram.setiid( cmd, m_IID->GetValue().mb_str(wxConvUTF8) );
    wProgram.setlntype(cmd, wProgram.lntype_bidib);
    wProgram.setporttype(cmd, m_PortType->GetSelection());
    // ToDo: Input or output???
    wxGetApp().sendToRocrail( cmd );
    cmd->base.del(cmd);
  }
}


void BidibIdentDlg::onServoSet(bool overwrite) {
  if( eventUpdate ) {
    return;
  }
  if( !MutexOp.trywait(servoSetMutex, 100) ) {
    return;
  }
  if( overwrite || m_ConfigL->GetValue() != configL || m_ConfigR->GetValue() != configR ||
      m_ConfigS->GetValue() != configS || m_ConfigV->GetValue() != configV )
  {
    configL = m_ConfigL->GetValue();
    configR = m_ConfigR->GetValue();
    configS = m_ConfigS->GetValue();
    configV = m_ConfigV->GetValue();

    TraceOp.trc( "bidibident", TRCLEVEL_INFO, __LINE__, 9999,"port set L=%d R=%d V=%d S=%d",
        configL, configR, configV, configS );
    if( bidibnode != NULL ) {
      iONode cmd = NodeOp.inst( wProgram.name(), NULL, ELEMENT_NODE );
      wProgram.setmodid(cmd, wBiDiBnode.getuid(bidibnode));
      wProgram.setcmd( cmd, wProgram.nvset );
      wProgram.setcv( cmd, m_ServoPort->GetValue() );
      wProgram.setiid( cmd, m_IID->GetValue().mb_str(wxConvUTF8) );
      wProgram.setlntype(cmd, wProgram.lntype_bidib);
      wProgram.setporttype(cmd, m_PortType->GetSelection());
      if( m_PortType->GetSelection() == 0 ) {
        wProgram.setval1(cmd, m_PortIOSelection->GetSelection());
        wProgram.setval2(cmd, m_PortTimer->GetValue());
        wProgram.setval3(cmd, 0);
        wProgram.setval4(cmd, 0);
      }
      else {
        wProgram.setval1(cmd, configL);
        wProgram.setval2(cmd, configR);
        wProgram.setval3(cmd, configV);
        wProgram.setval4(cmd, 0);
      }
      wxGetApp().sendToRocrail( cmd );
      cmd->base.del(cmd);
    }
  }
  MutexOp.post(servoSetMutex);
}

void BidibIdentDlg::onServoLeft( wxScrollEvent& event ) {
  m_ConfigL->SetValue(m_ServoLeft->GetValue());
  if( configL != m_ConfigL->GetValue() ) {
    onServoSet();
  }
}

void BidibIdentDlg::onServoRight( wxScrollEvent& event ) {
  m_ConfigR->SetValue(m_ServoRight->GetValue());
  if( configR != m_ConfigR->GetValue() ) {
    onServoSet();
  }
}

void BidibIdentDlg::onServoSpeed( wxScrollEvent& event ) {
  m_ConfigV->SetValue(m_ServoSpeed->GetValue());
  if( configV != m_ConfigV->GetValue() ) {
    onServoSet();
  }
}

void BidibIdentDlg::onServoReserved( wxScrollEvent& event ) {
  m_ConfigS->SetValue(m_ServoReserved->GetValue());
  if( configS != m_ConfigS->GetValue() ) {
    onServoSet();
  }
}

void BidibIdentDlg::onServoPort( wxSpinEvent& event ) {
}

void BidibIdentDlg::onServoLeftTest( wxCommandEvent& event ) {
  if( bidibnode != NULL ) {
    iONode cmd = NodeOp.inst( wOutput.name(), NULL, ELEMENT_NODE );
    wOutput.setiid( cmd, m_IID->GetValue().mb_str(wxConvUTF8) );
    wOutput.setbus( cmd, wBiDiBnode.getuid(bidibnode) );
    wOutput.setaddr( cmd, m_ServoPort->GetValue()+1 );
    wOutput.setaccessory( cmd, False );
    wOutput.setporttype(cmd, m_PortType->GetSelection());
    wOutput.setcmd( cmd, wOutput.on );
    wxGetApp().sendToRocrail( cmd );
    cmd->base.del(cmd);
  }
}

void BidibIdentDlg::onServoRightTest( wxCommandEvent& event ) {
  if( bidibnode != NULL ) {
    iONode cmd = NodeOp.inst( wOutput.name(), NULL, ELEMENT_NODE );
    wOutput.setiid( cmd, m_IID->GetValue().mb_str(wxConvUTF8) );
    wOutput.setbus( cmd, wBiDiBnode.getuid(bidibnode) );
    wOutput.setaddr( cmd, m_ServoPort->GetValue()+1 );
    wOutput.setaccessory( cmd, False );
    wOutput.setporttype(cmd, m_PortType->GetSelection());
    wOutput.setcmd( cmd, wOutput.off );
    wxGetApp().sendToRocrail( cmd );
    cmd->base.del(cmd);
  }
}

void BidibIdentDlg::onConfigL( wxSpinEvent& event ) {
  m_ServoLeft->SetValue(m_ConfigL->GetValue());
}


void BidibIdentDlg::onConfigR( wxSpinEvent& event ) {
  m_ServoRight->SetValue(m_ConfigR->GetValue());
}


void BidibIdentDlg::onConfigV( wxSpinEvent& event ) {
  m_ServoSpeed->SetValue(m_ConfigV->GetValue());
}

void BidibIdentDlg::onConfigS( wxSpinEvent& event ) {
  m_ServoReserved->SetValue(m_ConfigS->GetValue());
}

void BidibIdentDlg::onConfigLtxt( wxCommandEvent& event ) {
  m_ServoLeft->SetValue(m_ConfigL->GetValue());
  if( configL != m_ConfigL->GetValue() ) {
    onServoSet();
  }
}
void BidibIdentDlg::onConfigRtxt( wxCommandEvent& event ) {
  m_ServoRight->SetValue(m_ConfigR->GetValue());
  if( configR != m_ConfigR->GetValue() ) {
    onServoSet();
  }
}
void BidibIdentDlg::onConfigVtxt( wxCommandEvent& event ) {
  m_ServoSpeed->SetValue(m_ConfigV->GetValue());
  if( configV != m_ConfigV->GetValue() ) {
    onServoSet();
  }
}
void BidibIdentDlg::onConfigStxt( wxCommandEvent& event ) {
  m_ServoReserved->SetValue(m_ConfigS->GetValue());
  if( configS != m_ConfigS->GetValue() ) {
    onServoSet();
  }
}



void BidibIdentDlg::onPortType( wxCommandEvent& event ) {
  m_PortIOSelection->Enable( (wBiDiBnode.isiocfg(bidibnode) && m_PortType->GetSelection()==0) ? true:false);
  m_PortTimer->Enable( (wBiDiBnode.isiocfg(bidibnode) && m_PortType->GetSelection()==0) ? true:false);
}


void BidibIdentDlg::onSelectUpdateFile( wxCommandEvent& event ) {
  wxString ms_FileExt = _T("PIC HEX (*.HEX;*.hex)|*.HEX;*.hex");
  const char* l_openpath = wGui.getopenpath( wxGetApp().getIni() );
  wxFileDialog* fdlg = new wxFileDialog(this, wxGetApp().getMenu("openhexfile"),
      wxString(l_openpath,wxConvUTF8) , _T(""), ms_FileExt, wxFD_OPEN);
  if( fdlg->ShowModal() == wxID_OK ) {
    //fdlg->GetPath();
    wGui.setopenpath( wxGetApp().getIni(), fdlg->GetPath().mb_str(wxConvUTF8) );
    // strip filename:
    wGui.setopenpath( wxGetApp().getIni(), FileOp.getPath(wGui.getopenpath( wxGetApp().getIni() ) ) );

    TraceOp.trc( "bidib", TRCLEVEL_INFO, __LINE__, 9999, "reading [%s]...", (const char*)fdlg->GetPath().mb_str(wxConvUTF8));
    iOFile f = FileOp.inst( fdlg->GetPath().mb_str(wxConvUTF8), OPEN_READONLY );
    if( f != NULL ) {
      TraceOp.trc( "bidib", TRCLEVEL_INFO, __LINE__, 9999, "file opened...");
      m_UpdateFile->SetValue(fdlg->GetPath());
      FILE* fs = FileOp.getStream(f);
      char str[256];
      fgets( str, 256, fs );

      /* until end of stream or error: */
      m_HEXFileText->Clear();
      int lines = 0;
      while( !ferror(fs) && !feof(fs) ) {
        StrOp.replaceAll(str, '\r', ' ');
        TraceOp.trc( "bidib", TRCLEVEL_DEBUG, __LINE__, 9999, "line=[%s]", str);
        if( lines < 50 ) {
          m_HEXFileText->AppendText(wxString(str,wxConvUTF8));
        }
        fgets( str, 256, fs );
        lines++;
      };

      m_HEXFileText->ShowPosition(0);

      char* preview = StrOp.fmt("Preview %d lines of %d", lines > 50 ? 50:lines, lines);
      m_labUpdateFilePreview->SetLabel(wxString(preview,wxConvUTF8));
      StrOp.free(preview);

      FileOp.base.del( f );
      m_UpdateProgress->SetRange(lines);
    }
  }
  fdlg->Destroy();
  Raise();
}

void BidibIdentDlg::onUpdateStart( wxCommandEvent& event ) {
  if( bidibnode != NULL ) {
    iONode cmd = NodeOp.inst( wProgram.name(), NULL, ELEMENT_NODE );
    wProgram.setcmd( cmd, wProgram.writehex );
    wProgram.setiid( cmd, m_IID->GetValue().mb_str(wxConvUTF8) );
    wProgram.setlntype(cmd, wProgram.lntype_bidib);
    wProgram.setmodid(cmd, wBiDiBnode.getuid(bidibnode));
    wProgram.setfilename( cmd,  m_UpdateFile->GetValue().mb_str(wxConvUTF8) );
    wxGetApp().sendToRocrail( cmd );
    cmd->base.del(cmd);
    m_UpdateStart->Enable(false);
    m_UpdateStart->SetLabel( wxGetApp().getMsg( "wait" )+wxT("...") );
  }
}


void BidibIdentDlg::onMacroList( wxCommandEvent& event ) {
  macro = m_MacroList->GetSelection();
}


void BidibIdentDlg::onMacroLineSelected( wxGridEvent& event ) {
  macroline = event.GetRow();
  m_MacroLines->SelectRow(event.GetRow());
  m_MacroLines->MakeCellVisible( event.GetRow(), 0 );
  int val1 = atoi( m_MacroLines->GetCellValue( event.GetRow(), 0 ).mb_str(wxConvUTF8) );
  int val2 = atoi( m_MacroLines->GetCellValue( event.GetRow(), 1 ).mb_str(wxConvUTF8) );
  int val3 = atoi( m_MacroLines->GetCellValue( event.GetRow(), 2 ).mb_str(wxConvUTF8) );
  int val4 = atoi( m_MacroLines->GetCellValue( event.GetRow(), 3 ).mb_str(wxConvUTF8) );

  m_MacroDelay->SetValue(val1);
  if( val2 < 6 )
    m_MacroType->SetSelection(val2);
  else
    m_MacroType->SetSelection(0);
  m_MacroPort->SetValue(val3);
  m_MacroValue->SetValue(val4);
}


void BidibIdentDlg::onMacroApply( wxCommandEvent& event ) {
  macro = m_MacroList->GetSelection();
  macrosave = false;
  macroapply = true;

  if( bidibnode != NULL ) {
    iONode cmd = NodeOp.inst( wProgram.name(), NULL, ELEMENT_NODE );
    wProgram.setmodid(cmd, wBiDiBnode.getuid(bidibnode));
    wProgram.setcmd( cmd, wProgram.macro_set );
    wProgram.setiid( cmd, m_IID->GetValue().mb_str(wxConvUTF8) );
    wProgram.setlntype(cmd, wProgram.lntype_bidib);
    wProgram.setval1( cmd, macro );
    wProgram.setval2( cmd, macroline );
    wProgram.setval3( cmd, m_MacroDelay->GetValue() );
    wProgram.setval4( cmd, m_MacroType->GetSelection() );
    wProgram.setval5( cmd, m_MacroPort->GetValue() );
    wProgram.setval6( cmd, m_MacroValue->GetValue() );
    wxGetApp().sendToRocrail( cmd );
    cmd->base.del(cmd);
  }
}


void BidibIdentDlg::onMacroReload( wxCommandEvent& event ) {
  macro = m_MacroList->GetSelection();
  macroline = 0;
  macroparam = 0;

  m_MacroLines->ClearGrid();
  if( m_MacroLines->GetNumberRows() > 0 )
    m_MacroLines->DeleteRows( 0, m_MacroLines->GetNumberRows() );

  if( bidibnode != NULL ) {
    iONode cmd = NodeOp.inst( wProgram.name(), NULL, ELEMENT_NODE );
    wProgram.setmodid(cmd, wBiDiBnode.getuid(bidibnode));
    wProgram.setcmd( cmd, wProgram.macro_get );
    wProgram.setiid( cmd, m_IID->GetValue().mb_str(wxConvUTF8) );
    wProgram.setlntype(cmd, wProgram.lntype_bidib);
    wProgram.setval1( cmd, macro );
    wProgram.setval2( cmd, macroline );
    wxGetApp().sendToRocrail( cmd );
    cmd->base.del(cmd);
  }
}


void BidibIdentDlg::onMacroSave( wxCommandEvent& event ) {
  macro = m_MacroList->GetSelection();

  if( bidibnode != NULL && m_MacroLines->GetNumberRows() > 0 ) {
    macrosave = true;
    macroline = 0;
    macroparam = BIDIB_MACRO_PARA_START_CLK; // avoid reading the parameters

    iONode cmd = NodeOp.inst( wProgram.name(), NULL, ELEMENT_NODE );
    wProgram.setmodid(cmd, wBiDiBnode.getuid(bidibnode));
    wProgram.setcmd( cmd, wProgram.macro_set );
    wProgram.setiid( cmd, m_IID->GetValue().mb_str(wxConvUTF8) );
    wProgram.setlntype(cmd, wProgram.lntype_bidib);
    wProgram.setval1( cmd, macro );
    wProgram.setval2( cmd, macroline );

    int val1 = atoi( m_MacroLines->GetCellValue( macroline, 0 ).mb_str(wxConvUTF8) );
    int val2 = atoi( m_MacroLines->GetCellValue( macroline, 1 ).mb_str(wxConvUTF8) );
    int val3 = atoi( m_MacroLines->GetCellValue( macroline, 2 ).mb_str(wxConvUTF8) );
    int val4 = atoi( m_MacroLines->GetCellValue( macroline, 3 ).mb_str(wxConvUTF8) );
    wProgram.setval3( cmd, val1 );
    wProgram.setval4( cmd, val2 );
    wProgram.setval5( cmd, val3 );
    wProgram.setval6( cmd, val4 );

    wxGetApp().sendToRocrail( cmd );
    cmd->base.del(cmd);
  }

}


void BidibIdentDlg::handleAccessory(iONode node) {
  int cv = wProgram.getcv(node);
  if( cv == BIDIB_ACCESSORY_SWITCH_TIME ) {
    int swtime = wProgram.getval1(node);
    m_AccessorySwitchTime->SetValue(swtime & 0x7F);
    m_AccessorySwitchTimeSeconds->SetValue((swtime & 0x80)?true:false);
  }
  else if( cv == BIDIB_ACCESSORY_PARA_MACROMAP ) {
    m_AccessoryMacro1->SetValue(wProgram.getval1(node));
    m_AccessoryMacro2->SetValue(wProgram.getval2(node));
    m_AccessoryMacro3->SetValue(wProgram.getval3(node));
    m_AccessoryMacro4->SetValue(wProgram.getval4(node));
    m_AccessoryMacro5->SetValue(wProgram.getval5(node));
    m_AccessoryMacro6->SetValue(wProgram.getval6(node));
    m_AccessoryMacro7->SetValue(wProgram.getval7(node));
    m_AccessoryMacro8->SetValue(wProgram.getval8(node));
    m_AccessoryMacro9->SetValue(wProgram.getval9(node));
    m_AccessoryMacro10->SetValue(wProgram.getval10(node));
    m_AccessoryMacro11->SetValue(wProgram.getval11(node));
    m_AccessoryMacro12->SetValue(wProgram.getval12(node));
    m_AccessoryMacro13->SetValue(wProgram.getval13(node));
    m_AccessoryMacro14->SetValue(wProgram.getval14(node));
    m_AccessoryMacro15->SetValue(wProgram.getval15(node));
    m_AccessoryMacro16->SetValue(wProgram.getval16(node));
  }
}


void BidibIdentDlg::handleMacro(iONode node) {
  if( macroapply ) {
    macroapply = false;
    int index = wProgram.getval1(node);
    int line = wProgram.getval2(node);
    m_MacroLines->SetCellValue(line, 0, wxString::Format(_T("%d"), wProgram.getval3(node)) );
    m_MacroLines->SetCellValue(line, 1, wxString::Format(_T("%d"), wProgram.getval4(node)) );
    m_MacroLines->SetCellValue(line, 2, wxString::Format(_T("%d"), wProgram.getval5(node)) );
    m_MacroLines->SetCellValue(line, 3, wxString::Format(_T("%d"), wProgram.getval6(node)) );
  }
  else if( wProgram.getcmd(node) == wProgram.macro_get && !macrosave ) {
    int index = wProgram.getval1(node);
    int line = wProgram.getval2(node);

    m_MacroLines->AppendRows();
    m_MacroLines->SetCellValue(m_MacroLines->GetNumberRows()-1, 0, wxString::Format(_T("%d"), wProgram.getval3(node)) );
    m_MacroLines->SetCellValue(m_MacroLines->GetNumberRows()-1, 1, wxString::Format(_T("%d"), wProgram.getval4(node)) );
    m_MacroLines->SetCellValue(m_MacroLines->GetNumberRows()-1, 2, wxString::Format(_T("%d"), wProgram.getval5(node)) );
    m_MacroLines->SetCellValue(m_MacroLines->GetNumberRows()-1, 3, wxString::Format(_T("%d"), wProgram.getval6(node)) );
    m_MacroLines->AutoSizeColumns(false);


    if( line < macrosize && macroline < macrosize) {
      macroline++;
      iONode cmd = NodeOp.inst( wProgram.name(), NULL, ELEMENT_NODE );
      wProgram.setmodid(cmd, wBiDiBnode.getuid(bidibnode));
      wProgram.setcmd( cmd, wProgram.macro_get );
      wProgram.setiid( cmd, m_IID->GetValue().mb_str(wxConvUTF8) );
      wProgram.setlntype(cmd, wProgram.lntype_bidib);
      wProgram.setval1( cmd, macro );
      wProgram.setval2( cmd, macroline );
      wxGetApp().sendToRocrail( cmd );
      cmd->base.del(cmd);
    }
    else if( macrolevel == 2 && macroparam == 0 ) {
      macroparam = BIDIB_MACRO_PARA_SLOWDOWN;
      iONode cmd = NodeOp.inst( wProgram.name(), NULL, ELEMENT_NODE );
      wProgram.setmodid(cmd, wBiDiBnode.getuid(bidibnode));
      wProgram.setcmd( cmd, wProgram.macro_getparams );
      wProgram.setiid( cmd, m_IID->GetValue().mb_str(wxConvUTF8) );
      wProgram.setlntype(cmd, wProgram.lntype_bidib);
      wProgram.setval1( cmd, macro );
      wProgram.setval2( cmd, macroparam );
      wxGetApp().sendToRocrail( cmd );
      cmd->base.del(cmd);
    }
  }
  else if( wProgram.getcmd(node) == wProgram.macro_getparams ) {
    int index = wProgram.getval1(node);
    int param = wProgram.getval2(node);
    int valLSB = wProgram.getval3(node);
    int valM1 = wProgram.getval4(node);
    int valM2 = wProgram.getval5(node);
    int valMSB = wProgram.getval6(node);
    int val = valLSB + (valM1 << 8) + (valM2 << 16)  + (valMSB << 24);

    if( param == BIDIB_MACRO_PARA_SLOWDOWN ) {
      m_MacroSlowdown->SetValue(val);
    }
    else if( param == BIDIB_MACRO_PARA_REPEAT ) {
      m_MacroCycles->SetValue(val);
    }
    else if( param == BIDIB_MACRO_PARA_START_CLK ) {
      m_MacroStart1->SetValue(valLSB == 60);
      m_MacroStart30->SetValue(valLSB == 61);
      m_MacroStart15->SetValue(valLSB == 62);
      m_MacroStartHourly->SetValue(valM1 == 24);
      m_MacroStartDaily->SetValue(valM2 == 7);

      if( valLSB > 23 )
        valLSB = 0;
      m_MacroHours->SetValue(valLSB);
      if( valM1 > 59 )
        valM1 = 0;
      m_MacroMinutes->SetValue(valM1);
      if( valM2 > 6 )
        valM2 = 0;
      m_MacroWDay->SetValue(valM2);
    }

    if( macroparam < BIDIB_MACRO_PARA_START_CLK ) {
      macroparam++;
      iONode cmd = NodeOp.inst( wProgram.name(), NULL, ELEMENT_NODE );
      wProgram.setmodid(cmd, wBiDiBnode.getuid(bidibnode));
      wProgram.setcmd( cmd, wProgram.macro_getparams );
      wProgram.setiid( cmd, m_IID->GetValue().mb_str(wxConvUTF8) );
      wProgram.setlntype(cmd, wProgram.lntype_bidib);
      wProgram.setval1( cmd, macro );
      wProgram.setval2( cmd, macroparam );
      wxGetApp().sendToRocrail( cmd );
      cmd->base.del(cmd);
    }

  }

  else if( wProgram.getcmd(node) == wProgram.macro_get && macrosave ) {
    int index = wProgram.getval1(node);
    int line = wProgram.getval2(node);
    macroline++;
    if( m_MacroLines->GetNumberRows() > macroline ) {
      iONode cmd = NodeOp.inst( wProgram.name(), NULL, ELEMENT_NODE );
      wProgram.setmodid(cmd, wBiDiBnode.getuid(bidibnode));
      wProgram.setcmd( cmd, wProgram.macro_set );
      wProgram.setiid( cmd, m_IID->GetValue().mb_str(wxConvUTF8) );
      wProgram.setlntype(cmd, wProgram.lntype_bidib);
      wProgram.setval1( cmd, macro );
      wProgram.setval2( cmd, macroline );

      int val1 = atoi( m_MacroLines->GetCellValue( macroline, 0 ).mb_str(wxConvUTF8) );
      int val2 = atoi( m_MacroLines->GetCellValue( macroline, 1 ).mb_str(wxConvUTF8) );
      int val3 = atoi( m_MacroLines->GetCellValue( macroline, 2 ).mb_str(wxConvUTF8) );
      int val4 = atoi( m_MacroLines->GetCellValue( macroline, 3 ).mb_str(wxConvUTF8) );
      wProgram.setval3( cmd, val1 );
      wProgram.setval4( cmd, val2 );
      wProgram.setval5( cmd, val3 );
      wProgram.setval6( cmd, val4 );

      wxGetApp().sendToRocrail( cmd );
      cmd->base.del(cmd);
    }
    else {
      macrosave = false;
      iONode cmd = NodeOp.inst( wProgram.name(), NULL, ELEMENT_NODE );
      wProgram.setmodid(cmd, wBiDiBnode.getuid(bidibnode));
      wProgram.setcmd( cmd, wProgram.macro_setparams );
      wProgram.setiid( cmd, m_IID->GetValue().mb_str(wxConvUTF8) );
      wProgram.setlntype(cmd, wProgram.lntype_bidib);
      wProgram.setval1(cmd, macro );
      wProgram.setval2(cmd, BIDIB_MACRO_PARA_SLOWDOWN );
      wProgram.setval3(cmd, m_MacroSlowdown->GetValue() );
      wProgram.setval4(cmd, 0 );
      wProgram.setval5(cmd, 0 );
      wProgram.setval6(cmd, 0 );
      wxGetApp().sendToRocrail( cmd );

      wProgram.setval2(cmd, BIDIB_MACRO_PARA_REPEAT );
      wProgram.setval3(cmd, m_MacroCycles->GetValue() );
      wProgram.setval4(cmd, 0 );
      wProgram.setval5(cmd, 0 );
      wProgram.setval6(cmd, 0 );
      wxGetApp().sendToRocrail( cmd );

      wProgram.setval2(cmd, BIDIB_MACRO_PARA_START_CLK );
      wProgram.setval3(cmd, m_MacroStartHourly->IsChecked()?24:m_MacroHours->GetValue() );
      if( m_MacroStart1->IsChecked() )
        wProgram.setval4(cmd, 60 );
      if( m_MacroStart30->IsChecked() )
        wProgram.setval4(cmd, 61 );
      if( m_MacroStart15->IsChecked() )
        wProgram.setval4(cmd, 62 );
      else
        wProgram.setval4(cmd, m_MacroMinutes->GetValue() );
      wProgram.setval5(cmd, m_MacroStartDaily->IsChecked()?7:m_MacroWDay->GetValue() );
      wProgram.setval6(cmd, 0 );
      wxGetApp().sendToRocrail( cmd );

      cmd->base.del(cmd);
    }
  }

}


void BidibIdentDlg::onMacroEveryMinute( wxCommandEvent& event ) {
  if( event.GetEventObject() == m_MacroStart1 && m_MacroStart1->IsChecked() ) {
    m_MacroStart30->SetValue(false);
    m_MacroStart15->SetValue(false);
  }
  else if( event.GetEventObject() == m_MacroStart15 && m_MacroStart15->IsChecked() ) {
    m_MacroStart1->SetValue(false);
    m_MacroStart30->SetValue(false);
  }
  else if( event.GetEventObject() == m_MacroStart30 && m_MacroStart30->IsChecked() ) {
    m_MacroStart1->SetValue(false);
    m_MacroStart15->SetValue(false);
  }
}


void BidibIdentDlg::onMacroExport( wxCommandEvent& event ) {
  const char* l_openpath = wGui.getopenpath( wxGetApp().getIni() );
  wxString ms_FileExt = _T("Macro (*.xml)|*.xml");
  wxFileDialog* fdlg = new wxFileDialog(this, wxGetApp().getMenu("export"), wxString(l_openpath,wxConvUTF8),
                       wxString::Format( _T("bidib-macro-%d.xml"), m_MacroList->GetSelection()), ms_FileExt, wxFD_SAVE);
  if( fdlg->ShowModal() == wxID_OK ) {
    iONode model = wxGetApp().getModel();
    // Check for existence.
    wxString path = fdlg->GetPath();
    if( FileOp.exist( path.mb_str(wxConvUTF8) ) ) {
      int action = wxMessageDialog( this, wxGetApp().getMsg("fileexistwarning"), _T("Rocrail"), wxYES_NO | wxICON_EXCLAMATION ).ShowModal();
      if( action == wxID_NO ) {
        fdlg->Destroy();
        return;
      }
    }
    if( !path.Contains( _T(".xml") ) )
      path.Append( _T(".xml") );

    iOFile f = FileOp.inst( path.mb_str(wxConvUTF8), OPEN_WRITE );
    if( f != NULL ) {
      iONode macro = NodeOp.inst( wMacro.name(), NULL, ELEMENT_NODE );
      wMacro.setuid(macro, atoi(m_UID->GetValue().mb_str(wxConvUTF8)) );
      wMacro.setnr(macro, m_MacroList->GetSelection());
      // Set level 2 parameters.
      wMacro.sethours(macro, m_MacroHours->GetValue());
      wMacro.setminutes(macro, m_MacroMinutes->GetValue());
      wMacro.setwday(macro, m_MacroWDay->GetValue());

      for( int i = 0; i < m_MacroLines->GetNumberRows(); i++ ) {
        iONode macroline = NodeOp.inst( wMacroLine.name(), macro, ELEMENT_NODE );
        NodeOp.addChild(macro, macroline);
        wMacroLine.setnr(macroline, i);
        // ToDo: Set line values.
        int val1 = atoi( m_MacroLines->GetCellValue( i, 0 ).mb_str(wxConvUTF8) );
        int val2 = atoi( m_MacroLines->GetCellValue( i, 1 ).mb_str(wxConvUTF8) );
        int val3 = atoi( m_MacroLines->GetCellValue( i, 2 ).mb_str(wxConvUTF8) );
        int val4 = atoi( m_MacroLines->GetCellValue( i, 3 ).mb_str(wxConvUTF8) );
        wMacroLine.setdelay( macroline, val1 );
        wMacroLine.setporttype( macroline, val2 );
        wMacroLine.setport( macroline, val3 );
        wMacroLine.setstatus( macroline, val4 );
      }

      char* s = NodeOp.base.toString(macro);
      FileOp.writeStr(f, s);
      StrOp.free(s);
      NodeOp.base.del(macro);
      FileOp.base.del( f );
    }

  }

  fdlg->Destroy();
}


void BidibIdentDlg::onMacroImport( wxCommandEvent& event ) {
  wxString ms_FileExt = _T("Macro (*.xml)|*.xml");
  const char* l_openpath = wGui.getopenpath( wxGetApp().getIni() );
  wxFileDialog* fdlg = new wxFileDialog(this, wxGetApp().getMenu("import"), wxString(l_openpath,wxConvUTF8) , _T(""), ms_FileExt, wxFD_OPEN);
  if( fdlg->ShowModal() == wxID_OK ) {

    wGui.setopenpath( wxGetApp().getIni(), fdlg->GetPath().mb_str(wxConvUTF8) );
    // strip filename:
    wGui.setopenpath( wxGetApp().getIni(), FileOp.getPath(wGui.getopenpath( wxGetApp().getIni() ) ) );

    TraceOp.trc( "bidib", TRCLEVEL_INFO, __LINE__, 9999, "reading [%s]...", (const char*)fdlg->GetPath().mb_str(wxConvUTF8));
    iOFile f = FileOp.inst( fdlg->GetPath().mb_str(wxConvUTF8), OPEN_READONLY );
    if( f != NULL ) {
      TraceOp.trc( "bidib", TRCLEVEL_INFO, __LINE__, 9999, "file opened...");
      char* macroXml = (char*)allocMem( FileOp.size( f ) + 1 );
      FileOp.read( f, macroXml, FileOp.size( f ) );
      FileOp.close( f );
      FileOp.base.del(f );

      iODoc macroDoc = DocOp.parse( macroXml );
      freeMem( macroXml );
      if( macroDoc != NULL ) {
        iONode macro = DocOp.getRootNode( macroDoc );
        if( macro != NULL ) {
          // Set level 2 parameters.
          m_MacroHours->SetValue( wMacro.gethours(macro) );
          m_MacroMinutes->SetValue( wMacro.getminutes(macro) );
          m_MacroWDay->SetValue( wMacro.getwday(macro) );

          m_MacroLines->ClearGrid();
          if( m_MacroLines->GetNumberRows() > 0 )
            m_MacroLines->DeleteRows( 0, m_MacroLines->GetNumberRows() );

          iONode macroline = wMacro.getmacroline(macro);
          while( macroline != NULL ) {
            m_MacroLines->AppendRows();
            m_MacroLines->SetCellValue(m_MacroLines->GetNumberRows()-1, 0, wxString::Format(_T("%d"), wMacroLine.getdelay(macroline)) );
            m_MacroLines->SetCellValue(m_MacroLines->GetNumberRows()-1, 1, wxString::Format(_T("%d"), wMacroLine.getporttype(macroline)) );
            m_MacroLines->SetCellValue(m_MacroLines->GetNumberRows()-1, 2, wxString::Format(_T("%d"), wMacroLine.getport(macroline)) );
            m_MacroLines->SetCellValue(m_MacroLines->GetNumberRows()-1, 3, wxString::Format(_T("%d"), wMacroLine.getstatus(macroline)) );
            m_MacroLines->AutoSizeColumns(false);

            macroline = wMacro.nextmacroline(macro, macroline);
          }

          NodeOp.base.del(macro);
        }
        DocOp.base.del(macroDoc);
      }
    }
  }

  fdlg->Destroy();
}


void BidibIdentDlg::onMacroSaveMacro( wxCommandEvent& event ) {
  iONode cmd = NodeOp.inst( wProgram.name(), NULL, ELEMENT_NODE );
  wProgram.setmodid(cmd, wBiDiBnode.getuid(bidibnode));
  wProgram.setcmd( cmd, wProgram.macro_save );
  wProgram.setiid( cmd, m_IID->GetValue().mb_str(wxConvUTF8) );
  wProgram.setlntype(cmd, wProgram.lntype_bidib);
  wProgram.setval1( cmd, macro );
  wxGetApp().sendToRocrail( cmd );
  cmd->base.del(cmd);
}


void BidibIdentDlg::onMacroDeleteMacro( wxCommandEvent& event ) {
  m_MacroLines->ClearGrid();
  if( m_MacroLines->GetNumberRows() > 0 )
    m_MacroLines->DeleteRows( 0, m_MacroLines->GetNumberRows() );

  iONode cmd = NodeOp.inst( wProgram.name(), NULL, ELEMENT_NODE );
  wProgram.setmodid(cmd, wBiDiBnode.getuid(bidibnode));
  wProgram.setcmd( cmd, wProgram.macro_delete );
  wProgram.setiid( cmd, m_IID->GetValue().mb_str(wxConvUTF8) );
  wProgram.setlntype(cmd, wProgram.lntype_bidib);
  wProgram.setval1( cmd, macro );
  wxGetApp().sendToRocrail( cmd );
  cmd->base.del(cmd);
}


void BidibIdentDlg::onMacroRestoreMacro( wxCommandEvent& event ) {
  m_MacroLines->ClearGrid();
  if( m_MacroLines->GetNumberRows() > 0 )
    m_MacroLines->DeleteRows( 0, m_MacroLines->GetNumberRows() );

  iONode cmd = NodeOp.inst( wProgram.name(), NULL, ELEMENT_NODE );
  wProgram.setmodid(cmd, wBiDiBnode.getuid(bidibnode));
  wProgram.setcmd( cmd, wProgram.macro_restore );
  wProgram.setiid( cmd, m_IID->GetValue().mb_str(wxConvUTF8) );
  wProgram.setlntype(cmd, wProgram.lntype_bidib);
  wProgram.setval1( cmd, macro );
  wxGetApp().sendToRocrail( cmd );
  cmd->base.del(cmd);
}


void BidibIdentDlg::onMacroTest( wxCommandEvent& event ) {
  if( bidibnode != NULL ) {
    iONode cmd = NodeOp.inst( wOutput.name(), NULL, ELEMENT_NODE );
    wOutput.setiid( cmd, m_IID->GetValue().mb_str(wxConvUTF8) );
    wOutput.setbus( cmd, wBiDiBnode.getuid(bidibnode) );
    wOutput.setaddr( cmd, macro+1 );
    wOutput.setporttype(cmd, wProgram.porttype_macro);
    wOutput.setcmd( cmd, wOutput.on );
    wxGetApp().sendToRocrail( cmd );
    cmd->base.del(cmd);
  }
}


void BidibIdentDlg::onAccessoryOnTest( wxCommandEvent& event ) {
  if( bidibnode != NULL ) {
    iONode cmd = NodeOp.inst( wOutput.name(), NULL, ELEMENT_NODE );
    wOutput.setiid( cmd, m_IID->GetValue().mb_str(wxConvUTF8) );
    wOutput.setbus( cmd, wBiDiBnode.getuid(bidibnode) );
    wOutput.setaddr( cmd, m_AccessoryPort->GetValue()+1 );
    wOutput.setaccessory( cmd, True );
    wOutput.setcmd( cmd, wOutput.on );
    wxGetApp().sendToRocrail( cmd );
    cmd->base.del(cmd);
  }
}


void BidibIdentDlg::onAccessoryOffTest( wxCommandEvent& event ) {
  if( bidibnode != NULL ) {
    iONode cmd = NodeOp.inst( wOutput.name(), NULL, ELEMENT_NODE );
    wOutput.setiid( cmd, m_IID->GetValue().mb_str(wxConvUTF8) );
    wOutput.setbus( cmd, wBiDiBnode.getuid(bidibnode) );
    wOutput.setaddr( cmd, m_AccessoryPort->GetValue()+1 );
    wOutput.setaccessory( cmd, True );
    wOutput.setcmd( cmd, wOutput.off );
    wxGetApp().sendToRocrail( cmd );
    cmd->base.del(cmd);
  }
}


void BidibIdentDlg::onAccessoryReadOptions( wxCommandEvent& event ) {
  if( bidibnode != NULL ) {
    iONode cmd = NodeOp.inst( wProgram.name(), NULL, ELEMENT_NODE );
    wProgram.setmodid(cmd, wBiDiBnode.getuid(bidibnode));
    wProgram.setcmd( cmd, wProgram.acc_getparam );
    wProgram.setaddr( cmd, m_AccessoryPort->GetValue() );
    wProgram.setcv( cmd, BIDIB_ACCESSORY_SWITCH_TIME );
    wProgram.setiid( cmd, m_IID->GetValue().mb_str(wxConvUTF8) );
    wProgram.setlntype(cmd, wProgram.lntype_bidib);
    wxGetApp().sendToRocrail( cmd );
    cmd->base.del(cmd);
  }
}


void BidibIdentDlg::onAccessoryWriteOptions( wxCommandEvent& event ) {
  if( bidibnode != NULL ) {
    iONode cmd = NodeOp.inst( wProgram.name(), NULL, ELEMENT_NODE );
    wProgram.setmodid(cmd, wBiDiBnode.getuid(bidibnode));
    wProgram.setcmd( cmd, wProgram.acc_setparam );
    wProgram.setaddr( cmd, m_AccessoryPort->GetValue() );
    wProgram.setcv( cmd, BIDIB_ACCESSORY_SWITCH_TIME );
    wProgram.setval1( cmd, m_AccessorySwitchTime->GetValue() + (m_AccessorySwitchTimeSeconds->IsChecked()?0x80:0x00) );
    wProgram.setiid( cmd, m_IID->GetValue().mb_str(wxConvUTF8) );
    wProgram.setlntype(cmd, wProgram.lntype_bidib);
    wxGetApp().sendToRocrail( cmd );
    cmd->base.del(cmd);
  }
}


void BidibIdentDlg::onAccessoryReadMacroMap( wxCommandEvent& event ) {
  if( bidibnode != NULL ) {
    iONode cmd = NodeOp.inst( wProgram.name(), NULL, ELEMENT_NODE );
    wProgram.setmodid(cmd, wBiDiBnode.getuid(bidibnode));
    wProgram.setcmd( cmd, wProgram.acc_getparam );
    wProgram.setaddr( cmd, m_AccessoryPort->GetValue() );
    wProgram.setcv( cmd, BIDIB_ACCESSORY_PARA_MACROMAP );
    wProgram.setiid( cmd, m_IID->GetValue().mb_str(wxConvUTF8) );
    wProgram.setlntype(cmd, wProgram.lntype_bidib);
    wxGetApp().sendToRocrail( cmd );
    cmd->base.del(cmd);
  }
}


void BidibIdentDlg::onAccessoryWriteMacroMap( wxCommandEvent& event ) {
  if( bidibnode != NULL ) {
    iONode cmd = NodeOp.inst( wProgram.name(), NULL, ELEMENT_NODE );
    wProgram.setmodid(cmd, wBiDiBnode.getuid(bidibnode));
    wProgram.setcmd( cmd, wProgram.acc_setparam );
    wProgram.setaddr( cmd, m_AccessoryPort->GetValue() );
    wProgram.setcv( cmd, BIDIB_ACCESSORY_PARA_MACROMAP );
    wProgram.setval1( cmd, m_AccessoryMacro1->GetValue() );
    wProgram.setval2( cmd, m_AccessoryMacro2->GetValue() );
    wProgram.setval3( cmd, m_AccessoryMacro3->GetValue() );
    wProgram.setval4( cmd, m_AccessoryMacro4->GetValue() );
    wProgram.setval5( cmd, m_AccessoryMacro5->GetValue() );
    wProgram.setval6( cmd, m_AccessoryMacro6->GetValue() );
    wProgram.setval7( cmd, m_AccessoryMacro7->GetValue() );
    wProgram.setval8( cmd, m_AccessoryMacro8->GetValue() );
    wProgram.setval9( cmd, m_AccessoryMacro9->GetValue() );
    wProgram.setval10( cmd, m_AccessoryMacro10->GetValue() );
    wProgram.setval11( cmd, m_AccessoryMacro11->GetValue() );
    wProgram.setval12( cmd, m_AccessoryMacro12->GetValue() );
    wProgram.setval13( cmd, m_AccessoryMacro13->GetValue() );
    wProgram.setval14( cmd, m_AccessoryMacro14->GetValue() );
    wProgram.setval15( cmd, m_AccessoryMacro15->GetValue() );
    wProgram.setval16( cmd, m_AccessoryMacro16->GetValue() );
    wProgram.setiid( cmd, m_IID->GetValue().mb_str(wxConvUTF8) );
    wProgram.setlntype(cmd, wProgram.lntype_bidib);
    wxGetApp().sendToRocrail( cmd );
    cmd->base.del(cmd);
  }
}

void BidibIdentDlg::onLeftLogo( wxMouseEvent& event ) {
  wxLaunchDefaultBrowser(wxT("http://www.bidib.org"), wxBROWSER_NEW_WINDOW );
}


void BidibIdentDlg::onProductName( wxMouseEvent& event ) {
  if( www != NULL )
    wxLaunchDefaultBrowser(wxString(www, wxConvUTF8), wxBROWSER_NEW_WINDOW );
}

void BidibIdentDlg::onPageChanged( wxNotebookEvent& event ) {
  if( event.GetSelection() != -1 )
    m_Notebook->ChangeSelection(event.GetSelection());

  switch( event.GetSelection() ) {
  case 0: // index
    break;
  case 1: // features
    if( bidibnode != NULL && uid != wBiDiBnode.getuid(bidibnode) ) {
      uid = wBiDiBnode.getuid(bidibnode);
      onFeaturesGet(event);
    }
    break;
  case 2: // accessory
    break;
  case 3: // portsetup
    break;
  case 4: // macro
    break;
  case 5: // firmware
    break;
  }

}


void BidibIdentDlg::onPortSet( wxCommandEvent& event ) {
  onServoSet(true);
}


void BidibIdentDlg::onVendorCVEnable( wxCommandEvent& event ) {
  if( bidibnode != NULL ) {
    iONode cmd = NodeOp.inst( wProgram.name(), NULL, ELEMENT_NODE );
    wProgram.setmodid(cmd, wBiDiBnode.getuid(bidibnode));
    wProgram.setcmd( cmd, wProgram.vendorcvenable );
    wProgram.setvalue( cmd, 1 );
    wProgram.setiid( cmd, m_IID->GetValue().mb_str(wxConvUTF8) );
    wProgram.setlntype(cmd, wProgram.lntype_bidib);
    wxGetApp().sendToRocrail( cmd );
    cmd->base.del(cmd);
  }
}


void BidibIdentDlg::onVendorCVDisable( wxCommandEvent& event ) {
  if( bidibnode != NULL ) {
    iONode cmd = NodeOp.inst( wProgram.name(), NULL, ELEMENT_NODE );
    wProgram.setmodid(cmd, wBiDiBnode.getuid(bidibnode));
    wProgram.setcmd( cmd, wProgram.vendorcvenable );
    wProgram.setvalue( cmd, 0 );
    wProgram.setiid( cmd, m_IID->GetValue().mb_str(wxConvUTF8) );
    wProgram.setlntype(cmd, wProgram.lntype_bidib);
    wxGetApp().sendToRocrail( cmd );
    cmd->base.del(cmd);
  }
}


void BidibIdentDlg::onVendorCVGet( wxCommandEvent& event ) {
  if( bidibnode != NULL ) {
    iONode cmd = NodeOp.inst( wProgram.name(), NULL, ELEMENT_NODE );
    wProgram.setmodid(cmd, wBiDiBnode.getuid(bidibnode));
    wProgram.setcmd( cmd, wProgram.vendorcvget );
    wProgram.setstrval1( cmd, m_VendorCVName->GetValue().mb_str(wxConvUTF8) );
    wProgram.setiid( cmd, m_IID->GetValue().mb_str(wxConvUTF8) );
    wProgram.setlntype(cmd, wProgram.lntype_bidib);
    wxGetApp().sendToRocrail( cmd );
    cmd->base.del(cmd);
  }
}


void BidibIdentDlg::onVendorCVSet( wxCommandEvent& event ) {
  if( bidibnode != NULL ) {
    iONode cmd = NodeOp.inst( wProgram.name(), NULL, ELEMENT_NODE );
    wProgram.setmodid(cmd, wBiDiBnode.getuid(bidibnode));
    wProgram.setcmd( cmd, wProgram.vendorcvset );
    wProgram.setstrval1( cmd, m_VendorCVName->GetValue().mb_str(wxConvUTF8) );
    wProgram.setstrval2( cmd, m_VendorCVValue->GetValue().mb_str(wxConvUTF8) );
    wProgram.setiid( cmd, m_IID->GetValue().mb_str(wxConvUTF8) );
    wProgram.setlntype(cmd, wProgram.lntype_bidib);
    wxGetApp().sendToRocrail( cmd );
    cmd->base.del(cmd);
  }
}


void BidibIdentDlg::onReport( wxCommandEvent& event ) {
  const char* l_openpath = wGui.getopenpath( wxGetApp().getIni() );
  wxString ms_FileExt = _T("BiDiB-Report (*.csv)|*.csv");
  wxFileDialog* fdlg = new wxFileDialog(this, wxGetApp().getMenu("saveas"), wxString(l_openpath,wxConvUTF8),
                       wxString::Format( _T("bidib-report.csv")), ms_FileExt, wxFD_SAVE);
  if( fdlg->ShowModal() == wxID_OK ) {
    iONode model = wxGetApp().getModel();
    // Check for existence.
    wxString path = fdlg->GetPath();
    if( FileOp.exist( path.mb_str(wxConvUTF8) ) ) {
      int action = wxMessageDialog( this, wxGetApp().getMsg("fileexistwarning"), _T("Rocrail"), wxYES_NO | wxICON_EXCLAMATION ).ShowModal();
      if( action == wxID_NO ) {
        fdlg->Destroy();
        return;
      }
    }
    if( !path.Contains( _T(".csv") ) )
      path.Append( _T(".csv") );

    iOFile l_ReportFile = FileOp.inst( path.mb_str(wxConvUTF8), OPEN_WRITE );
    FileOp.fmt(l_ReportFile, "\"uid\",\"port\",\"type\",\"RocrailID\"\n");
    FileOp.flush(l_ReportFile);

    iONode l_RocrailIni = wxGetApp().getFrame()->getRocrailIni();
    if( l_RocrailIni != NULL ) {
      iONode digint = wFreeRail.getdigint(l_RocrailIni);
      while( digint != NULL ) {
        iONode bidib = wDigInt.getbidib(digint);
        if( bidib != NULL ) {
          m_IID->SetValue( wxString( wDigInt.getiid(digint), wxConvUTF8) );
          iONode bidibnode = wBiDiB.getbidibnode(bidib);
          while( bidibnode != NULL ) {
            if( wBiDiBnode.getsensorcnt(bidibnode) > 0 ) {
              for( int i = 0; i < wBiDiBnode.getsensorcnt(bidibnode); i++ ) {
                const char* id = wxGetApp().findID( false, i+1, wBiDiBnode.getuid(bidibnode) );
                FileOp.fmt(l_ReportFile, "\"%d\",\"%d\",\"%s\",\"%s\"\n",
                    wBiDiBnode.getuid(bidibnode), i+1, "sensor", id);
              }
            }
            if( wBiDiBnode.getservocnt(bidibnode) > 0 ) {
              for( int i = 0; i < wBiDiBnode.getservocnt(bidibnode); i++ ) {
                const char* id = wxGetApp().findID( true, i+1, wBiDiBnode.getuid(bidibnode), wProgram.porttype_servo );
                FileOp.fmt(l_ReportFile, "\"%d\",\"%d\",\"%s\",\"%s\"\n",
                    wBiDiBnode.getuid(bidibnode), i+1, "servo", id);
              }
            }
            if( wBiDiBnode.getinputcnt(bidibnode) > 0 ) {
              for( int i = 0; i < wBiDiBnode.getinputcnt(bidibnode); i++ ) {
                const char* id = wxGetApp().findID( false, i+1, wBiDiBnode.getuid(bidibnode) );
                FileOp.fmt(l_ReportFile, "\"%d\",\"%d\",\"%s\",\"%s\"\n",
                    wBiDiBnode.getuid(bidibnode), i+1, "input", id);
              }
            }
            if( wBiDiBnode.getsportcnt(bidibnode) > 0 ) {
              for( int i = 0; i < wBiDiBnode.getsportcnt(bidibnode); i++ ) {
                const char* id = wxGetApp().findID( false, i+1, wBiDiBnode.getuid(bidibnode), wProgram.porttype_switch );
                FileOp.fmt(l_ReportFile, "\"%d\",\"%d\",\"%s\",\"%s\"\n",
                    wBiDiBnode.getuid(bidibnode), i+1, "sport", id);
              }
            }
            if( wBiDiBnode.getlportcnt(bidibnode) > 0 ) {
              for( int i = 0; i < wBiDiBnode.getlportcnt(bidibnode); i++ ) {
                const char* id = wxGetApp().findID( false, i+1, wBiDiBnode.getuid(bidibnode), wProgram.porttype_light );
                FileOp.fmt(l_ReportFile, "\"%d\",\"%d\",\"%s\",\"%s\"\n",
                    wBiDiBnode.getuid(bidibnode), i+1, "lport", id);
              }
            }
            bidibnode = wBiDiB.nextbidibnode( bidib, bidibnode );
          }
          break;
        }
        digint = wFreeRail.nextdigint(l_RocrailIni, digint);
      }
    }

    TraceOp.trc( "bidibident", TRCLEVEL_INFO, __LINE__, 9999,"open report %s...", FileOp.getFilename(l_ReportFile) );
#if wxCHECK_VERSION(3, 0, 0)
    wxLaunchDefaultApplication(wxString(FileOp.getFilename(l_ReportFile), wxConvUTF8));
#else
    wxShell(wxString(FileOp.getFilename(l_ReportFile), wxConvUTF8));
#endif
    FileOp.base.del(l_ReportFile);
  }
  fdlg->Destroy();

}


void BidibIdentDlg::onUsernameSet( wxCommandEvent& event ) {
  if( bidibnode != NULL ) {
    iONode cmd = NodeOp.inst( wProgram.name(), NULL, ELEMENT_NODE );
    wProgram.setmodid(cmd, wBiDiBnode.getuid(bidibnode));
    wProgram.setcmd( cmd, wProgram.setstring );
    wProgram.setiid( cmd, m_IID->GetValue().mb_str(wxConvUTF8) );
    wProgram.setlntype(cmd, wProgram.lntype_bidib);
    wProgram.setval1(cmd, 1);
    wProgram.setstrval1(cmd, m_Username->GetValue().mb_str(wxConvUTF8) );
    wxGetApp().sendToRocrail( cmd );
    cmd->base.del(cmd);
  }
}


void BidibIdentDlg::onHelp( wxCommandEvent& event ) {
  switch( m_Notebook->GetSelection() ) {
  case 0: wxGetApp().openLink( "bidib:bidib-config", "index" ); break;
  case 1: wxGetApp().openLink( "bidib:bidib-config", "features" ); break;
  case 2: wxGetApp().openLink( "bidib:bidib-config", "accessory" ); break;
  case 3: wxGetApp().openLink( "bidib:bidib-config", "portsetup" ); break;
  case 4: wxGetApp().openLink( "bidib:bidib-config", "macro" ); break;
  case 5: wxGetApp().openLink( "bidib:bidib-config", "firmwareupdate" ); break;
  default: wxGetApp().openLink( "bidib:bidib-config" ); break;
  }
}

