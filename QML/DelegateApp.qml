import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

import Huppy.QML

ItemDelegate {
    width: 125
    height: 100

    contentItem: Rectangle {
        anchors.fill: parent
        color: "#FF9966"
        radius: 10

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
                sourceSize.width: 60
        
                fillMode: Image.PreserveAspectFit
                
                Layout.bottomMargin: 10
                Layout.fillWidth: true
                horizontalAlignment: Qt.AlignHCenter
            }
        }
        
        MouseArea {
            anchors.fill: parent
        
            onClicked: {
                parent.color = parent.color == Qt.color("#FF9966") ? "#00A550" : "#FF9966";
            }
        }
    }
}