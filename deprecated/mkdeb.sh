#!/bin/sh

echo "Creating packages for Debian is currently not supported as parts of the script seem outdated!"
return 1


DIST=$1
ARCH=$2

if [ !  $1 ]; then
  echo "usage  : mkdeb.sh dist arch"
  echo "example: mkdeb.sh ubuntu1310 i386"
  exit $?
fi

if [ ! $2 ]; then
  ARCH="i386"
fi

echo "Getting revision number..."
if which git > /dev/null
then
  BAZAARREV=`git rev-list --count HEAD`
  echo "    Revision number is $BAZAARREV"
  echo ""
else
  BAZAARREV="user"
  echo "    Revision number not found, using \"user\""
  echo ""
fi

sed s/\<BZR\>/$BAZAARREV/ < ../rocrail/package/control.template > ../rocrail/package/control.tmp
sed s/\<ARCH\>/$ARCH/ < ../rocrail/package/control.tmp > ../rocrail/package/control
rm ../rocrail/package/control.tmp


if [ ! -e ../package ] ; then
	mkdir ../package
fi
cd ../package
rm -Rf *.deb
mkdir -p debian/DEBIAN
mkdir -p debian/opt/freerail/default
mkdir -p debian/opt/freerail/stylesheets
mkdir -p debian/opt/freerail/decspecs
mkdir -p debian/opt/freerail/web
mkdir -p debian/opt/freerail/images
mkdir -p debian/opt/freerail/svg
mkdir -p debian/usr/share/applications
mkdir -p debian/usr/share/desktop-directories
mkdir -p debian/etc/init.d

cp ../freerail/package/control debian/DEBIAN/control

cp ../unxbin/freerail debian/opt/freerail
cp ../unxbin/rocview debian/opt/freerail
cp ../unxbin/rocnetnode debian/opt/freerail
cp ../unxbin/*.so debian/opt/freerail

strip debian/opt/freerail/freerail
strip debian/opt/freerail/rocview
strip debian/opt/freerail/*.so

cp ../freerail/package/FreeRail.directory debian/usr/share/desktop-directories
cp ../freerail/package/Roc*.desktop debian/usr/share/applications
cp ../freerail/package/roc*.sh debian/opt/freerail
cp ../freerail/package/freeraild debian/etc/init.d
chmod +x debian/opt/freerail/*.sh
cp ../freerail/package/freeraild.png debian/opt/freerail
cp ../freerail/package/freerail.xpm debian/opt/freerail
cp ../freerail/package/freerail.mib debian/opt/freerail
cp -u ../freerail/package/plan.xml debian/opt/freerail/default

cp -R ../freerail/package/images/* debian/opt/freerail/images
cp -R ../stylesheets/* debian/opt/freerail/stylesheets
cp -R ../decspecs/* debian/opt/freerail/decspecs
cp -R ../rocview/svg/* debian/opt/freerail/svg
cp -R ../freerail/impl/web/html/* debian/opt/freerail/web
cp -R ../COPYING debian/opt/freerail

fakeroot dpkg-deb --build debian
mv debian.deb freerail-$BAZAARREV-$DIST-$ARCH.deb
rm -Rf debian
cd ../freerail
