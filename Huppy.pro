CONFIG += c++20 \
          qtquickcompiler \
          precompile_header

QT += quick sql

QT_DEBUG_PLUGINS = 1
PRECOMPILED_HEADER = pch.h

HEADERS += pch.h \
           Huppy.h \
           Client\FileDownloader.h \
           Client\ClientSQL.h

SOURCES += Main.cpp \
           Huppy.cpp \
           Client\FileDownloader.cpp \
           Client\ClientSQL.cpp

RESOURCES += Resources.qrc
