import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

import Huppy.QML

ItemDelegate {
    width: parent.width
    height: 200

    contentItem: ColumnLayout {
        anchors.fill: parent

        Label {
            text: category.name
            font.pixelSize: 22
            Layout.leftMargin: 10
        }

        ViewApp {
            width: parent.width; height: 100
            model: apps
            Layout.leftMargin: 25
            Layout.topMargin: 10
        }
    }
}