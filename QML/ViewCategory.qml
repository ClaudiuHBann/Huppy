import QtQuick
import QtQuick.Controls

import Huppy.QML

ListView {
    width: 320; height: 480

    model: ListViewCategory {
        id: listViewCategory
        objectName: "listViewCategory"
    }

    delegate: DelegateCategory {
        id: delegateCategory
        objectName: "delegateCategory"
    }

    ScrollBar.vertical: ScrollBar {}
}