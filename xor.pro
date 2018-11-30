TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

# Remember only one sc_main() function should exist.
# Choose "nand.cpp" here to test your NAND implementation.
# Choose "main.cpp" here to test your XOR implementation.
#SOURCES += main.cpp
SOURCES += nand.cpp

QMAKE_CXXFLAGS += -std=c++0x

HEADERS += exor.h
HEADERS += nand.h
HEADERS += stim.h
HEADERS += mon.h

systemc_home = $$(SYSTEMC_HOME)
isEmpty(systemc_home) {
    systemc_home = /opt/systemc
}

systemc_target_arch = $$(SYSTEMC_TARGET_ARCH)
isEmpty(systemc_target_arch) {
}

unix:!macx {
    systemc_target_arch = linux64
    QMAKE_CXXFLAGS += -std=c++11 -O0 -g
}

macx: {
    systemc_target_arch = macosx64
    QMAKE_CXXFLAGS += -std=c++0x -stdlib=libc++ -O0 -g
}

INCLUDEPATH += $${systemc_home}/include
LIBS += -L$${systemc_home}/lib-$${systemc_target_arch} -lsystemc
