CONFIG += c++20 \
          qtquickcompiler \
          precompile_header

QT += quick sql

QT_DEBUG_PLUGINS = 1
PRECOMPILED_HEADER = pch.h

HEADERS += pch.h \
           Huppy.h \
           Magic.h \
           Database.h \
           Client\FileDownloader.h \
           Client\ClientSQL.h \
           Model\Types.h \
           Model\IModel.h \
           Model\App.h \
           Model\Category.h \
           Model\Link.h \
           Model\Package.h

SOURCES += Main.cpp \
           Huppy.cpp \
           Magic.cpp \
           Database.cpp \
           Client\FileDownloader.cpp \
           Client\ClientSQL.cpp \
           Model\Types.cpp \
           Model\IModel.cpp \
           Model\App.cpp \
           Model\Category.cpp \
           Model\Link.cpp \
           Model\Package.cpp

RESOURCES += Resources.qrc
