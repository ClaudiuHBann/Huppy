import QtQuick
import QtQuick.Controls

import Huppy.QML.Types

ListView {
    id: listView

    width: 320
    height: 480

    focus: true
    boundsBehavior: Flickable.StopAtBounds

    delegate: AppDelegate {
        id: delegate
        width: listView.width
    }

    model: ListViewApp {
        id: appModel
    }

    ScrollBar.vertical: ScrollBar { }
}