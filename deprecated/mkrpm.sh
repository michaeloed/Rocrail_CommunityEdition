#!/bin/bash
# variable 1 should be something like "0.9"
# variable 2 should be something like "0" == patch 0
# variable 3: CVS revision tag (freerail-vXXX or HEAD)
# variable 4: cvs user
# variable 5: cpu for redhat i386, suse i586, suses390 s390, 64bit x86_64

VERSION=$1
CPU=$2
BUILDROOT=/home/$USER/rpmbuild

if [ !  $1 ] || [ ! $2 ]; then
  echo "usage: mkrpm.sh version cpu"
  exit $?
fi
if [ ! -e ~/.rpmmacros ] ; then
	cp _rpmmacros ~/.rpmmacros
fi

git pull
mkdir -p $BUILDROOT

if [ -e freerail-$VERSION ] ; then
	rm -Rf freerail-$VERSION
fi

mkdir freerail-$VERSION
cd freerail-$VERSION
pwd
git clone https://github.com/michealoed/FreeRail.git FreeRail
BAZAARREV=`git rev-list --count HEAD`
sed s/\<BZR\>/$BAZAARREV/ < FreeRail/freerail/freerail-template.spec > FreeRail/freerail/freerail-1.spec
sed s/\<VERSION\>/$VERSION/ < FreeRail/freerail/freerail-1.spec > FreeRail/freerail/freerail.spec
cd ..

if [ -e freerail-$VERSION-$BAZAARREV.tar ] ; then
	rm -f freerail-$VERSION-$BAZAARREV.tar
fi
echo "creating tar..."
tar -cf freerail-$VERSION-$BAZAARREV.tar freerail-$VERSION
echo "zipping tar..."
gzip -f freerail-$VERSION-$BAZAARREV.tar
echo "copy to SOURCES..."
cp freerail-$VERSION-$BAZAARREV.tar.gz $BUILDROOT

echo "executing rpmbuild..."
rpmbuild -v -ba freerail-$VERSION/FreeRail/freerail/freerail.spec
echo "cleanup..."
rm -Rf freerail-$VERSION
if [ ! -e ../package ] ; then
  mkdir ../package
fi
cp $BUILDROOT/$CPU/freerail*.rpm ../package
rm -Rf $BUILDROOT/BUILD/freerail-$VERSION


