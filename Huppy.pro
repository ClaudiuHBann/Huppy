CONFIG += c++2a \
          qtquickcompiler \
          precompile_header

QT += quick

PRECOMPILED_HEADER = pch.hpp

HEADERS += pch.hpp

SOURCES += Main.cpp

RESOURCES += Resources.qrc
