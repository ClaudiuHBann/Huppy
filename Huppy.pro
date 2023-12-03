CONFIG += c++2a \
          qtquickcompiler \
          precompile_header

QT += quick

PRECOMPILED_HEADER = pch.h

HEADERS += pch.h \
           Huppy.h

SOURCES += Main.cpp \
           Huppy.cpp

RESOURCES += Resources.qrc
