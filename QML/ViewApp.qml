import QtQuick
import QtQuick.Controls

import Huppy.QML

ListView {
    width: 320; height: 480

    model: ListViewApp {}
    delegate: DelegateApp {}

    ScrollBar.vertical: ScrollBar {}
}