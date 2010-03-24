CPP = g++
JAVAC = javac
JAR = jar cfm
MSGFMT = msgfmt
XGETT = xgettext -k_

MACOSX_DEPLOYMENT_TARGET := 10.4

UNIX_INCLUDES = -I/usr/include/ -I/usr/local/include
UNIX_LIBSRC =  -L/usr/lib/ -L/usr/local/lib
UNIX_SRC = USBPort.cpp Settings.cpp Logic.cpp ReadFlashThread.cpp \
			EraseThread.cpp WriteFlashThread.cpp ReadRamThread.cpp \
			WriteRamThread.cpp gbcflsh.cpp
UNIX_LIB = -lftdi -lusb 


MACOSX_INCLUDES = -I/usr/include/ -I/usr/local/include -I/opt/local/include 
MACOSX_LIBSRC =  -L/usr/lib/ -L/usr/local/lib -L/sw/lib
MACOSX_SRC = USBPort.cpp Settings.cpp Logic.cpp ReadFlashThread.cpp \
				EraseThread.cpp WriteFlashThread.cpp ReadRamThread.cpp \
				WriteRamThread.cpp gbcflsh.cpp
MACOSX_LIB = /usr/local/lib/libftdi.a /opt/local/lib/libusb.a \
			 /opt/local/lib/libintl.a \
			 -framework Carbon -framework IOKit 
MACOSX_HACKS = -mmacosx-version-min=10.4

WIN_INCLUDES = -I/usr/include/
WIN_LIBSRC = -L/usr/lib/
WIN_SRC = USBPortWin.cpp Settings.cpp Logic.cpp ReadFlashThread.cpp \
			EraseThread.cpp WriteFlashThread.cpp ReadRamThread.cpp  \
			WriteRamThread.cpp gbcflsh.cpp
WIN_LIB = -lftd2xx -lintl


JAVA_SRC = Gbflash.java myTextArea.java GBRomFilter.java GBSaveFilter.java
JAVA_PKG = MANIFEST.MF  *.class  Labels* images/ org/


all:
	@echo
	@echo "Use:"
	@echo "    -make unix- -make macosx- or -make windows- to build gbcf"
	@echo "    -make gui- to build the graphical interface"
	@echo

unix:
	$(CPP) -D _GBFLASH_UNIX -static $(UNIX_INCLUDES) $(UNIX_LIBSRC) $(UNIX_SRC) $(UNIX_LIB) -o gbcf
	$(XGETT) *.cpp -o messages.pot
	$(MSGFMT) locale/es/LC_MESSAGES/gbcf.po -o locale/es/LC_MESSAGES/gbcf.mo

macosx:
	$(CPP) $(MACOSX_HACKS) -D _GBFLASH_UNIX $(MACOSX_INCLUDES) \
		$(MACOSX_LIBSRC) $(MACOSX_SRC) $(MACOSX_LIB) -o gbcf

windows:
	$(CPP) -D _GBFLASH_WIN32 -static $(WIN_INCLUDES) $(WIN_LIBSRC) $(WIN_SRC) $(WIN_LIB) -o gbcf


clean:
	rm gbcf *.o *.gb *.sav *.class *~

gui:
	$(JAVAC) $(JAVA_SRC)
	$(JAR) Gbflash.jar $(JAVA_PKG)
