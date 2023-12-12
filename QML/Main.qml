import QtQuick
import QtQuick.Controls

import Huppy.QML

Window {
    id: window
    visible: true
    flags: Qt.Window | Qt.WindowTitleHint | Qt.WindowMinimizeButtonHint | Qt.WindowMaximizeButtonHint | Qt.WindowCloseButtonHint | Qt.WindowStaysOnTopHint
    width: 640; height: 480
    title: "Huppy"
    color: "#0E0E10"

    ViewCategory { anchors.fill: parent }

    Shortcut {
        sequences: ["Ctrl+R"]

        onActivated: {
            window.close();
            ManagerView.HotReload();
        }
    }
}
