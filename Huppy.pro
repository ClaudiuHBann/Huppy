CONFIG += c++20 \
          qtquickcompiler \
          precompile_header

QT += quick sql

QT_DEBUG_PLUGINS = 1
PRECOMPILED_HEADER = pch.h

HEADERS += pch.h \
           Huppy.h \
           Client\FileDownloader.h \
           Client\ClientSQL.h \
           Model\Types.h \
           Model\App.h \
           Model\Category.h \
           Model\Link.h \
           Model\Package.h

SOURCES += Main.cpp \
           Huppy.cpp \
           Client\FileDownloader.cpp \
           Client\ClientSQL.cpp \
           Model\Types.cpp \
           Model\App.cpp \
           Model\Category.cpp \
           Model\Link.cpp \
           Model\Package.cpp

RESOURCES += Resources.qrc
