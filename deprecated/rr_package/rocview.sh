#!/bin/sh
if [ ! -e ~/freerail ] ; then
	mkdir ~/freerail
fi

if [ ! -e ~/freerail/plan.xml ] ; then
	cp /opt/freerail/default/plan.xml ~/freerail
fi

if [ ! -e ~/freerail/svg ] ; then
	ln -s /opt/freerail/svg ~/freerail/svg
fi

if [ ! -e ~/freerail/images ] ; then
  mkdir ~/freerail/images
fi
cp -pur /opt/freerail/images ~/freerail

if [ ! -e ~/freerail/decspecs ] ; then
  mkdir ~/freerail/decspecs
fi
cp -pur /opt/freerail/decspecs ~/freerail

if [ ! -e ~/freerail/stylesheets ] ; then
  mkdir ~/freerail/stylesheets
fi
cp -pur /opt/freerail/stylesheets ~/freerail


cd ~/freerail

/opt/freerail/rocview -sp /opt/freerail $*

