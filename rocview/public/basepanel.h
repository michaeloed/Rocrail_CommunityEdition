/*
 Copyright (C) 2002-2014 Rob Versluis, Rocrail.net

 

 */
#ifndef BASEPANEL_H_
#define BASEPANEL_H_

// ----------------------------------------------------------------------------
// headers
// ----------------------------------------------------------------------------
// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#include "wx/wx.h"
#include "wx/event.h"
#endif


#include "rocs/public/node.h"
#include "wx/colour.h"


class BasePanel : public wxScrolledWindow
{
public:
  BasePanel(wxWindow* parent, long style = wxHSCROLL | wxVSCROLL);

  virtual void modelEvent( iONode node ) = 0;
  virtual void reScale( double scale ) = 0;
  virtual void removeItemFromList( iONode item ) = 0;
  virtual void init(bool modview=false) = 0;
  virtual void clean() = 0;
  virtual const char* getZLevelTitle() = 0;
  virtual int getZ() = 0;
  virtual const char* getZID() = 0;
  virtual iONode getZLevel() = 0;
  virtual void refresh(bool eraseBackground = true) = 0;
  virtual bool SetBackgroundColor(int red, int green, int blue, bool savecolor) = 0;
  virtual void OnPanelProps(wxCommandEvent& event) = 0;
  virtual BasePanel* updateZLevel(iONode zlevel) = 0;
  virtual void showTooltip(bool show) = 0;
  virtual void* GetItem(const char* key) = 0;

};

#endif /*BASEPANEL_H_*/
