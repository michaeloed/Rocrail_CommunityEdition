/*
 Copyright (C) 2002-2014 Rob Versluis, Rocrail.net

 

 */
#include "basenotebook.h"

  basenotebook::basenotebook(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name)
  :wxNotebook(parent, id, pos, size, wxGetApp().getTabAlign(), name) {
  }

