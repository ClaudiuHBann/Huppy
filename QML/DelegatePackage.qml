import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

import Huppy.QML

ItemDelegate {
    width: parent.width
    height: 50

    //Component.onCompleted: console.log(this, "(", this.width, ", ", this.height, ")")

    contentItem: RowLayout {
        anchors.fill: parent

        Image {
            source: image
            sourceSize.height: 30
        
            fillMode: Image.PreserveAspectFit

            Layout.leftMargin: 10
            Layout.alignment: Qt.AlignVCenter
        }
        
        Label {
            text: name
            font.pixelSize: 18
            Layout.alignment: Qt.AlignVCenter
        }

        Button {
            text: "X"
            Layout.alignment: Qt.AlignVCenter
        }
    }
}