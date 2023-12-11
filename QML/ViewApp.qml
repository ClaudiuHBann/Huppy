import QtQuick
import QtQuick.Controls

import Huppy.QML

ListView {
    orientation: Qt.Horizontal
    boundsBehavior: Flickable.StopAtBounds
    spacing: 15

    model: ListViewApp {}
    delegate: DelegateApp {}
    ScrollBar.horizontal: ScrollBar {}
}