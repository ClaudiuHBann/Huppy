import QtQuick
import QtQuick.Controls

Window {
    visible: true
    width: 640; height: 480
    title: "Huppy"

    ViewCategory {
        id: viewCategory
        objectName: "viewCategory"
        anchors.fill: parent
    }
}
