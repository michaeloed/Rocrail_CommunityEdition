#!/bin/sh

echo "Creating packages for Debian is currently not supported as parts of the script seem outdated!"
return 1

DIST=$1
ARCH=$2

if [ !  $1 ]; then
  echo "usage  : mkdeb.sh dist arch"
  echo "example: mkdeb.sh ubuntu1104 i386"
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
mkdir -p debian/opt/freerail/images
mkdir -p debian/usr/share/applications
mkdir -p debian/usr/share/desktop-directories
mkdir -p debian/etc/init.d

cp ../rocrail/package/control debian/DEBIAN/control

cp ../unxbin/freerail debian/opt/freerail
cp ../unxbin/*.so debian/opt/freerail

strip debian/opt/freerail/freerail
strip debian/opt/freerail/*.so

cp ../rocrail/package/update.sh debian/opt/freerail
cp ../rocrail/package/roc*.sh debian/opt/freerail
cp ../rocrail/package/freeraild debian/etc/init.d
chmod +x debian/opt/freerail/*.sh
cp ../rocrail/package/freeraild.png debian/opt/freerail
cp ../rocrail/package/freerail.mib debian/opt/freerail
cp -u ../rocrail/package/plan.xml debian/opt/freerail/default

cp -R ../rocrail/package/images/*.* debian/opt/freerail/images
cp -R ../COPYING debian/opt/freerail
cp ../rocrail/package/postinst debian/DEBIAN/postinst

fakeroot dpkg-deb --build debian
mv debian.deb freerail-server-$BAZAARREV-$DIST-$ARCH.deb
rm -Rf debian
cd ../rocrail
