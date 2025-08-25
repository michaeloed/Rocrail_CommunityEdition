Summary: Model Railway Control Software
Name: freerail
Vendor: tbd
Version: <VERSION>
Release: <BZR>
Group: Amusements/Games
License: gpl
Packager: tbd
URL: https://www.github.com/michaeloed/FreeRail
Source: freerail-%version-%release.tar.gz
%description
FreeRail is a 2 tier application written for Linux and Windows in C/C++ based on the wxWidgets class library.


%prep
%setup

%build
cd FreeRail
# make fromtar DEBUG=
## make fromtar DEBUG=
# if you have more than 1 cpu kernel than use -j<num> to speedup compiling.
# My best prcatice is <num> = 1 + #kernels
MY_MAKEOPTS=`cat /proc/cpuinfo | grep processor | tail -1 | awk '{if(0 != $NF) {print " -j"2+$NF}}'`
make $MY_MAKEOPTS fromtar DEBUG=
cd ..

%install
#rm -rf $RPM_BUILD_ROOT
mkdir -p $RPM_BUILD_ROOT/opt/freerail
mkdir -p $RPM_BUILD_ROOT/opt/freerail/default
mkdir -p $RPM_BUILD_ROOT/opt/freerail/svg
mkdir -p $RPM_BUILD_ROOT/opt/freerail/stylesheets
mkdir -p $RPM_BUILD_ROOT/opt/freerail/decspecs
mkdir -p $RPM_BUILD_ROOT/opt/freerail/web
mkdir -p $RPM_BUILD_ROOT/usr/share/applications
mkdir -p $RPM_BUILD_ROOT/usr/share/desktop-directories
mkdir -p $RPM_BUILD_ROOT/etc/init.d

install -s -m 755 FreeRail/unxbin/freerail $RPM_BUILD_ROOT/opt/freerail/freerail
install -s -m 755 FreeRail/unxbin/rocview $RPM_BUILD_ROOT/opt/freerail/rocview
install -s -m 755 FreeRail/unxbin/*.so $RPM_BUILD_ROOT/opt/freerail

install -g users -m 666 FreeRail/freerail/package/FreeRail.directory $RPM_BUILD_ROOT/usr/share/desktop-directories
install -g users -m 666 FreeRail/freerail/package/Free*.desktop $RPM_BUILD_ROOT/usr/share/applications

install -m 755 FreeRail/freerail/package/roc*.sh $RPM_BUILD_ROOT/opt/freerail
install -g users -m 666 FreeRail/rocrail/package/freeraild.png $RPM_BUILD_ROOT/opt/freerail
install -g users -m 666 FreeRail/rocrail/package/freeraild $RPM_BUILD_ROOT/etc/init.d
install -g users -m 666 FreeRail/rocrail/package/freerail.xpm $RPM_BUILD_ROOT/opt/freerail
install -g users -m 666 FreeRail/rocrail/package/plan.xml $RPM_BUILD_ROOT/opt/freerail/default

install -g users -m 666 FreeRail/stylesheets/*.* $RPM_BUILD_ROOT/opt/freerail/stylesheets
install -g users -m 666 FreeRail/decspecs/*.* $RPM_BUILD_ROOT/opt/freerail/decspecs

### install does not handle directory (sub-)trees, so we have to do this manually
# install -d -g users -m 666 FreeRail/rocview/svg/* $RPM_BUILD_ROOT/opt/freerail/svg
cp -pr FreeRail/rocview/svg $RPM_BUILD_ROOT/opt/freerail/
cp -pr FreeRail/rocrail/impl/web/html/* $RPM_BUILD_ROOT/opt/freerail/web
chown -R :users  $RPM_BUILD_ROOT/opt/freerail/svg
chown -R :users  $RPM_BUILD_ROOT/opt/freerail/web
find $RPM_BUILD_ROOT/opt/freerail/svg -type d -exec chmod 755 {} \;
find $RPM_BUILD_ROOT/opt/freerail/svg -type f -exec chmod 666 {} \;


%clean
#rm -rf $RPM_BUILD_ROOT

%files
%defattr(-,root,root)
%doc

/opt/freerail/freerail
/opt/freerail/rocview
/opt/freerail/*.so
/opt/freerail/default/plan.xml
/opt/freerail/freerail.sh
/opt/freerail/rocview.sh
/opt/freerail/freeraild.png
/etc/init.d/freeraild
/opt/freerail/freerail.xpm
/opt/freerail/stylesheets/*.*
/opt/freerail/decspecs
/opt/freerail/svg
/opt/freerail/web
/usr/share/desktop-directories/FreeRail.directory
/usr/share/applications/FreeRail.desktop
/usr/share/applications/Rocview.desktop

%changelog
