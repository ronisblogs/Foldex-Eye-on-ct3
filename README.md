# Foldex-Eye-on-ct3

## Install depends

### add unstable app source
edit /etc/apt/sources.list, add below lines:

 deb http://httpredir.debian.org/debian/ unstable main non-free contrib
 
 deb-src http://httpredir.debian.org/debian/ unstable main non-free contrib

### install qt build tools

apt-get install qt5-qmake qt5-default qtdeclarative5-dev

### install essential run environment
apt-get install qml-module-qtquick2 qml-module-qtquick-window2 qml-module-qtquick-controls qml-module-qt-labs-settings qml-module-qtgraphicaleffects qml-module-qtqml-models2

### edit X11 mouse
delete 'Option	"HWCursor" "false"' line from /etc/X11/xorg.conf

## How to build

### project.pro
 at root directory, using 'qmake -project' to generate the .pro file. Then you need to **modify** this file. add 

 QT += qml quick
 
 CONFIG += c++11

to the top of this file.

### Makefile
 change to the build directory, using 'qmake ../Foldex-Eye-on-ct3.pro' to generate the Makefile file.

### make
 after Makefile is generated, execute 'make -j4' command to build all the source files. 
