import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

import Huppy.QML

Window {
    id: window
    visible: true
    flags: Qt.Window | Qt.WindowTitleHint | Qt.WindowMinimizeButtonHint | Qt.WindowMaximizeButtonHint | Qt.WindowCloseButtonHint | Qt.WindowStaysOnTopHint
    width: 640; height: 480
    title: "Huppy"
    //color: "#0E0E10"

    GridLayout {
        anchors.fill: parent
        rows: 2; columns: 2

        ColumnLayout {
            Layout.rowSpan: 2
            Layout.maximumWidth: 200

            Label {
                text: "Your Package:"
                font.pixelSize: 18
                
                Layout.fillWidth: true
                horizontalAlignment: Qt.AlignHCenter
            }

            ViewPackage {
                Layout.fillHeight: true
                Layout.fillWidth: true
            }
        }

        ViewCategory {
            Layout.fillHeight: true
            Layout.fillWidth: true

            Layout.column: 1
            Layout.rowSpan: 2
        }
    }

    Shortcut {
        sequences: ["Ctrl+R"]

        onActivated: {
            window.close();
            ManagerView.HotReload();
        }
    }
}
