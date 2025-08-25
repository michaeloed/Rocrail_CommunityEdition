#!/bin/sh
if [ ! -e ~/freerail ] ; then
	mkdir ~/freerail
fi

if [ ! $NO_GNOME_PLEASE ] ; then
  gnome_terminal=`command -v gnome-terminal`
fi

cd ~/freerail

if ps --no-heading -C freerail
  then
    echo "freerail is running"
  else
    echo "freerail is not running. start..."
    
    if [ $gnome_terminal ]
      then
        $gnome_terminal --hide-menubar --title=FreeRail --geometry=132x50 -e "/opt/freerail/freerail -console -l /opt/freerail $*" 
      else
        /opt/freerail/freerail -console -l /opt/freerail $*
    fi
fi    
