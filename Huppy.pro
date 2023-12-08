CONFIG += c++20 \
          qtquickcompiler \
          precompile_header

QT += quick sql

QT_DEBUG_PLUGINS = 1
PRECOMPILED_HEADER = pch.h

HEADERS += pch.h \
           Huppy.h \
\
           Client\ClientSQL.h \
           Client\FileDownloader.h \
\
           View\ManagerView.h \
           View\ListViewApp.h \
\
           Utility\Magic.h \
           Utility\Obfuscate.h \
\
           Model\App.h \
           Model\Link.h \
           Model\Types.h \
           Model\IModel.h \
           Model\Package.h \
           Model\Category.h

SOURCES += Main.cpp \
           Huppy.cpp \
\
           Client\ClientSQL.cpp \
           Client\FileDownloader.cpp \
\
           View\ManagerView.cpp \
           View\ListViewApp.cpp \
\
           Utility\Magic.cpp \
           Utility\Obfuscate.cpp \
\
           Model\App.cpp \
           Model\Link.cpp \
           Model\Types.cpp \
           Model\IModel.cpp \
           Model\Package.cpp \
           Model\Category.cpp

RESOURCES += QML\DelegateApp.qml \
             QML\ViewApp.qml \
             QML\Main.qml
