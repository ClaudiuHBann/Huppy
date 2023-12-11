import QtQuick
import QtQuick.Controls

import Huppy.QML

Window {
    id: window
    visible: true
    width: 640; height: 480
    title: "Huppy"

    ViewCategory { anchors.fill: parent }

    Shortcut {
        sequences: ["Ctrl+R"]

        onActivated: {
            window.close();
            ManagerView.HotReload();
        }
    }
}
