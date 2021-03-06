#!/bin/bash
set -e

# recuperation de la version
response=""
echo -n "Voulez vous mettre a jour la version de l'archive ? [y/N] : "
if read -t 15 response; then
    if [ "$response" = "Y" -o "$response" = "y" ]; then
	nano version.txt
	nano version_os.txt
    fi
fi

version=`cat version.txt`
version_os=`cat version_os.txt`

if [ -n "$version" ]
then
    if [ "$version" = "" ]
    then echo version.txt vide
	 exit 1
   fi
else
    echo version.txt vide
    exit 2
fi

if [ -n "$version_os" ]
then
    if [ "$version_os" = "" ]
    then echo version_os.txt vide
	 exit 1
   fi
else
    echo version_os.txt vide
    exit 2
fi

echo Packaging de la version $version de arm-ada avec un firmware version $version_os

# Exportation des TP, des scripts, des outils et des templates
rm -rf arm-ada
rm -rf *.xz
mkdir -v arm-ada

echo "Copie des bibliotheques, des scripts, des TP"
cp -Rv ../lib ./arm-ada
cp -Rv ../TP ./arm-ada
cp -Rv ../scripts ./arm-ada
cp -Rv ../exemples ./arm-ada

echo "Compilation des outils"
cd ../tools
xbuild tools.sln
cd ../export

echo " Copie des outils"
mkdir -v ./arm-ada/bin
cp -v ../tools/adashell/bin/Debug/adashell.exe ./arm-ada/bin/adashell
cp -v ../tools/flashprog/bin/Debug/flashprog.exe ./arm-ada/bin/flashprog
cp -v ../tools/rca/bin/Debug/rca.exe ./arm-ada/bin/rca
cp -v ../tools/sim-ada/bin/Debug/sim-ada.exe ./arm-ada/bin/sim-ada
cp -v arm-ada/scripts/arm-ada-update arm-ada/bin/
chmod -v +x arm-ada/bin/*

echo "Copie de la derniere version en date du systeme dans arm-ada/firmware"
if [ ! -d arm-ada/firmware ]; then
  mkdir -v arm-ada/firmware
fi

cp -v ../sw4stm32/System/Debug/System.hex arm-ada/firmware/firmware_$version_os.hex
xz -zv arm-ada/firmware/firmware_$version_os.hex
cp -v arm-ada/firmware/firmware_$version_os.hex.xz arm-ada/firmware/firmware_LATEST.hex.xz

echo "Construction de la bibliotheque wrapper"
cd arm-ada/lib/wrapper
make clean
make
cd ../../..

echo "Construction de la bibliotheque lib-appli"
cd arm-ada/lib/lib-ada
make clean
make
cd ../../..

echo "configuration des TP"
# echo "Compilation des solutions"
# cd arm-ada/TP/solutions/TP1
# make clean
# make ressources
# make
# cp solution.hex ../../TP1

# cd ../TP2/test_correl
# make clean
# make ressources
# make
# cp solution.hex ../../../TP2/test_correl

# cd ../../TP2/tp_mouv
# make clean
# make ressources
# make
# cp solution.hex ../../../TP2/tp_mouv

# cd ../../TP2/simon
# make clean
# make ressources
# make
# cp solution.hex ../../../TP2/simon

# cd ../../TP3/dicho
# make clean
# make ressources
# make
# cp solution.hex ../../../TP3/dicho

# cd ../../TP3/koch
# make clean
# make ressources
# make
# cp solution.hex ../../../TP3/koch

# cd ../../TP4/magneto
# make clean
# make ressources
# make
# cp solution.hex ../../../TP4/magneto

# cd ../../TP4/snake
# make clean
# make ressources
# make
# cp solution.hex ../../../TP4/snake

# cd ../../..
# rm -rf solutions
# cd ../..

echo "Preparation des TP"
cd arm-ada/TP/TP1
make ressources
make
make export
make doc

cd ../TP2
make ressources
make
make export
make doc

cd ../TP3/dicho
make ressources
make
make export
make doc

cd ../../TP3/koch
make ressources
make
make export
make doc

cd ../../TP4/magneto
make ressources
make
make export
make doc

cd ../../TP4/snake
make ressources
make
make export
make doc

cd ../../../..

echo "creation de l'archive arm-ada_home"
tar Jcf arm-ada_home_$version.tar.xz arm-ada

response=""
echo -n "Voulez vous transferer les archives sur le serveur ? [y/N] : "
if read response; then
    if [ "$response" = "Y" -o "$response" = "y" ]; then
        echo ""
        echo "Transfert sur gei-srv"
	    scp arm-ada_home_$version.tar.xz dimercur@srv-gei:/services/depot/

        echo ""
        echo "Transfert sur commetud"
        scp arm-ada_home_$version.tar.xz dimercur@srv-ens:"/home/commetud/2eme\ Annee\ IMACS/ADA"
    fi
fi

echo Fini
