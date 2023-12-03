CONFIG += c++23 \
          qtquickcompiler \
          precompile_header

QT += quick

PRECOMPILED_HEADER = pch.h

HEADERS += pch.h \
           Huppy.h \
           FileDownloader.h \
           ClientSQL.h

SOURCES += Main.cpp \
           Huppy.cpp \
           FileDownloader.cpp \
           ClientSQL.cpp

RESOURCES += Resources.qrc
