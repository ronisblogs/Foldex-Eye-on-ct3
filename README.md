# Foldex-Eye-on-ct3

## original source

https://github.com/rtty122333/Foldex-Eye

## Install depends

### add unstable app source
edit /etc/apt/sources.list, add below lines:

 deb http://httpredir.debian.org/debian/ unstable main non-free contrib
 
 deb-src http://httpredir.debian.org/debian/ unstable main non-free contrib
 
edit /etc/apt/apt.conf, add below line:

 APT::Default-Release "stable";
 
then run:

 apt-get update
 
 apt-get -f install
 
to update the source list.

### download and build xfreerdp

first, install build essentials:

 apt-get install build-essential git-core cmake xsltproc libssl-dev libx11-dev libxext-dev libxinerama-dev libxcursor-dev libxdamage-dev libxv-dev libxkbfile-dev libasound2-dev libcups2-dev libxml2 libxml2-dev libxrandr-dev libgstreamer0.10-dev libgstreamer-plugins-base0.10-dev libxi-dev libgstreamer-plugins-base1.0-dev
 
 apt-get install libavutil-dev libavcodec-dev 

second, clone the source code:

 git clone https://github.com/FreeRDP/FreeRDP
 
then run belows to build and install xfreerdp:

 cd FreeRDP
 
 cmake .
 
 make -j4

 make install
 
at last edit /etc/ld.so.conf.d/freerdp.conf and add below lines:
 
 /usr/local/lib/freerdp

 /usr/local/lib
 
### Install virt-viewer
 
 apt-get -t unstable install virt-viewer

### install qt build tools and run environment

apt-get -t unstable install qt5-qmake qt5-default qtdeclarative5-dev

apt-get -t unstable install qml-module-qtquick2 qml-module-qtquick-window2 qml-module-qtquick-controls qml-module-qt-labs-settings qml-module-qtgraphicaleffects qml-module-qtqml-models2

### edit X11 mouse
delete 'Option	"HWCursor" "false"' line from /etc/X11/xorg.conf

## How to build Foldex-Eye

### project.pro
 at root directory, using 'qmake -project' to generate the .pro file. Then you need to **modify** this file. add 

 QT += qml quick
 
 CONFIG += c++11

to the top of this file.

### Makefile
 change to the build directory, using 'qmake ../Foldex-Eye-on-ct3.pro' to generate the Makefile file.

### make
 after Makefile is generated, execute 'make -j4' command to build all the source files. 
