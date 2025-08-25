#!/bin/bash
cd /opt/freerail/
rm -f nohup.out
#nohup ./freerail -l /opt/freerail&
nohup ./freerail -l /opt/freerail > nohup.out 2>&1 &
echo "$!" > /tmp/freeraild.pid
