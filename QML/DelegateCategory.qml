import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

import Huppy.QML

ItemDelegate {
    width: parent.width

    contentItem: ColumnLayout {
        anchors.fill: parent

        Label {
            text: category.name
            font.pixelSize: 22
        }

        ViewApp {
            width: parent.width; height: 100
            model: apps
        }
    }
}