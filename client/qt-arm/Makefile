#############################################################################
# Makefile for building: client
# Generated by qmake (2.01a) (Qt 4.7.1) on: Mon Jul 15 06:19:36 2019
# Project:  ../client.pro
# Template: app
# Command: /opt/qt-4.7.1/bin/qmake -spec /opt/qt-4.7.1/mkspecs/qws/linux-arm-g++ -o Makefile ../client.pro
#############################################################################

####### Compiler, tools and options

CC            = arm-linux-gcc -lts
CXX           = arm-linux-g++ -lts
DEFINES       = -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_NETWORK_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/opt/qt-4.7.1/mkspecs/qws/linux-arm-g++ -I../../client -I/opt/qt-4.7.1/include/QtCore -I/opt/qt-4.7.1/include/QtNetwork -I/opt/qt-4.7.1/include/QtGui -I/opt/qt-4.7.1/include -I. -I. -I../../client -I.
LINK          = arm-linux-g++ -lts
LFLAGS        = -Wl,-O1 -Wl,-rpath,/opt/qt-4.7.1/lib
LIBS          = $(SUBLIBS)  -L/opt/qt-4.7.1/lib -lQtGui -L/usr/local/tslib/lib -L/opt/qt-4.7.1/lib -lQtNetwork -lQtCore -lpthread 
AR            = arm-linux-ar cqs
RANLIB        = 
QMAKE         = /opt/qt-4.7.1/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = arm-linux-strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = ../main.cpp \
		../mainwindow.cpp \
		../camera.cpp moc_mainwindow.cpp
OBJECTS       = main.o \
		mainwindow.o \
		camera.o \
		moc_mainwindow.o
DIST          = /opt/qt-4.7.1/mkspecs/common/g++.conf \
		/opt/qt-4.7.1/mkspecs/common/unix.conf \
		/opt/qt-4.7.1/mkspecs/common/linux.conf \
		/opt/qt-4.7.1/mkspecs/common/qws.conf \
		/opt/qt-4.7.1/mkspecs/qconfig.pri \
		/opt/qt-4.7.1/mkspecs/features/qt_functions.prf \
		/opt/qt-4.7.1/mkspecs/features/qt_config.prf \
		/opt/qt-4.7.1/mkspecs/features/exclusive_builds.prf \
		/opt/qt-4.7.1/mkspecs/features/default_pre.prf \
		/opt/qt-4.7.1/mkspecs/features/release.prf \
		/opt/qt-4.7.1/mkspecs/features/default_post.prf \
		/opt/qt-4.7.1/mkspecs/features/warn_on.prf \
		/opt/qt-4.7.1/mkspecs/features/qt.prf \
		/opt/qt-4.7.1/mkspecs/features/unix/thread.prf \
		/opt/qt-4.7.1/mkspecs/features/moc.prf \
		/opt/qt-4.7.1/mkspecs/features/resources.prf \
		/opt/qt-4.7.1/mkspecs/features/uic.prf \
		/opt/qt-4.7.1/mkspecs/features/yacc.prf \
		/opt/qt-4.7.1/mkspecs/features/lex.prf \
		/opt/qt-4.7.1/mkspecs/features/include_source_dir.prf \
		../client.pro
QMAKE_TARGET  = client
DESTDIR       = 
TARGET        = client

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): ui_mainwindow.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: ../client.pro  /opt/qt-4.7.1/mkspecs/qws/linux-arm-g++/qmake.conf /opt/qt-4.7.1/mkspecs/common/g++.conf \
		/opt/qt-4.7.1/mkspecs/common/unix.conf \
		/opt/qt-4.7.1/mkspecs/common/linux.conf \
		/opt/qt-4.7.1/mkspecs/common/qws.conf \
		/opt/qt-4.7.1/mkspecs/qconfig.pri \
		/opt/qt-4.7.1/mkspecs/features/qt_functions.prf \
		/opt/qt-4.7.1/mkspecs/features/qt_config.prf \
		/opt/qt-4.7.1/mkspecs/features/exclusive_builds.prf \
		/opt/qt-4.7.1/mkspecs/features/default_pre.prf \
		/opt/qt-4.7.1/mkspecs/features/release.prf \
		/opt/qt-4.7.1/mkspecs/features/default_post.prf \
		/opt/qt-4.7.1/mkspecs/features/warn_on.prf \
		/opt/qt-4.7.1/mkspecs/features/qt.prf \
		/opt/qt-4.7.1/mkspecs/features/unix/thread.prf \
		/opt/qt-4.7.1/mkspecs/features/moc.prf \
		/opt/qt-4.7.1/mkspecs/features/resources.prf \
		/opt/qt-4.7.1/mkspecs/features/uic.prf \
		/opt/qt-4.7.1/mkspecs/features/yacc.prf \
		/opt/qt-4.7.1/mkspecs/features/lex.prf \
		/opt/qt-4.7.1/mkspecs/features/include_source_dir.prf \
		/opt/qt-4.7.1/lib/libQtGui.prl \
		/opt/qt-4.7.1/lib/libQtNetwork.prl \
		/opt/qt-4.7.1/lib/libQtCore.prl
	$(QMAKE) -spec /opt/qt-4.7.1/mkspecs/qws/linux-arm-g++ -o Makefile ../client.pro
/opt/qt-4.7.1/mkspecs/common/g++.conf:
/opt/qt-4.7.1/mkspecs/common/unix.conf:
/opt/qt-4.7.1/mkspecs/common/linux.conf:
/opt/qt-4.7.1/mkspecs/common/qws.conf:
/opt/qt-4.7.1/mkspecs/qconfig.pri:
/opt/qt-4.7.1/mkspecs/features/qt_functions.prf:
/opt/qt-4.7.1/mkspecs/features/qt_config.prf:
/opt/qt-4.7.1/mkspecs/features/exclusive_builds.prf:
/opt/qt-4.7.1/mkspecs/features/default_pre.prf:
/opt/qt-4.7.1/mkspecs/features/release.prf:
/opt/qt-4.7.1/mkspecs/features/default_post.prf:
/opt/qt-4.7.1/mkspecs/features/warn_on.prf:
/opt/qt-4.7.1/mkspecs/features/qt.prf:
/opt/qt-4.7.1/mkspecs/features/unix/thread.prf:
/opt/qt-4.7.1/mkspecs/features/moc.prf:
/opt/qt-4.7.1/mkspecs/features/resources.prf:
/opt/qt-4.7.1/mkspecs/features/uic.prf:
/opt/qt-4.7.1/mkspecs/features/yacc.prf:
/opt/qt-4.7.1/mkspecs/features/lex.prf:
/opt/qt-4.7.1/mkspecs/features/include_source_dir.prf:
/opt/qt-4.7.1/lib/libQtGui.prl:
/opt/qt-4.7.1/lib/libQtNetwork.prl:
/opt/qt-4.7.1/lib/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -spec /opt/qt-4.7.1/mkspecs/qws/linux-arm-g++ -o Makefile ../client.pro

dist: 
	@$(CHK_DIR_EXISTS) ../.tmp/client1.0.0 || $(MKDIR) ../.tmp/client1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) ../.tmp/client1.0.0/ && $(COPY_FILE) --parents ../mainwindow.h ../camera.h ../.tmp/client1.0.0/ && $(COPY_FILE) --parents ../main.cpp ../mainwindow.cpp ../camera.cpp ../.tmp/client1.0.0/ && $(COPY_FILE) --parents ../mainwindow.ui ../.tmp/client1.0.0/ && (cd `dirname ../.tmp/client1.0.0` && $(TAR) client1.0.0.tar client1.0.0 && $(COMPRESS) client1.0.0.tar) && $(MOVE) `dirname ../.tmp/client1.0.0`/client1.0.0.tar.gz . && $(DEL_FILE) -r ../.tmp/client1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_mainwindow.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_mainwindow.cpp
moc_mainwindow.cpp: ../camera.h \
		../mainwindow.h
	/opt/qt-4.7.1/bin/moc $(DEFINES) $(INCPATH) ../mainwindow.h -o moc_mainwindow.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_mainwindow.h
compiler_uic_clean:
	-$(DEL_FILE) ui_mainwindow.h
ui_mainwindow.h: ../mainwindow.ui
	/opt/qt-4.7.1/bin/uic ../mainwindow.ui -o ui_mainwindow.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

####### Compile

main.o: ../main.cpp ../mainwindow.h \
		../camera.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o ../main.cpp

mainwindow.o: ../mainwindow.cpp ../mainwindow.h \
		../camera.h \
		../ui_mainwindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mainwindow.o ../mainwindow.cpp

camera.o: ../camera.cpp ../camera.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o camera.o ../camera.cpp

moc_mainwindow.o: moc_mainwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mainwindow.o moc_mainwindow.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

