import QtQuick
import QtQuick.Controls

Window {
    visible: true
    width: 640; height: 480
    title: "Huppy"

    ViewApp {
        id: viewApp
        objectName: "viewApp"
        anchors.fill: parent
    }
}
