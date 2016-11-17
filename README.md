# Foldex-Eye-on-ct3

## How to build

### project.pro
 at root directory, using 'qmake -project' to generate the .pro file. Then you need to **modify** this file. add 

//QT += qml quick
//CONFIG += c++11

to the top of this file.

### Makefile
 change to the build directory, using 'qmake ../Foldex-Eye-on-ct3.pro' to generate the Makefile file.

### make
 after Makefile is generated, then execute 'make -j4' command to build all the source files. 
