import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

import Huppy.QML

ItemDelegate {
    width: 150
    height: 100

    contentItem: Rectangle {
        anchors.fill: parent

        ColumnLayout {
            anchors.fill: parent
        
            Label {
                text: modelData.name
                font.pixelSize: 18
                
                Layout.fillWidth: true
                horizontalAlignment: Qt.AlignHCenter
            }
            
            Image {
                source: modelData.image
                sourceSize.width: 50
        
                fillMode: Image.PreserveAspectFit
                
                Layout.fillWidth: true
                horizontalAlignment: Qt.AlignHCenter
            }
        }
        
        MouseArea {
            anchors.fill: parent
        
            onClicked: {
                parent.color = "#00A550";
            }
        }
    }
}