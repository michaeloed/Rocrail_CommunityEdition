#!/bin/sh
#File:  MyBundle.app/Contents/MacOS/startup.command
#echo "this is a test"
#pwd
mypath=`dirname "$0"`
#echo $mypath
$mypath/FreeRail -console -l $mypath -x $mypath/../../../rocdata/plan.xml -i $mypath/../../../rocdata/freerail.ini -w $mypath/../../../rocdata/ -img $mypath/../../../rocdata/images/ -t $mypath/../../../rocdata/trace/freerail.trace
