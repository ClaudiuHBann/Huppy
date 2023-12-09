﻿import QtQuick
import QtQuick.Controls

import Huppy.QML

ListView {
    width: 320; height: 480

    model: ListViewApp {
        id: listViewApp
        objectName: "listViewApp"
    }

    delegate: DelegateApp {}

    ScrollBar.vertical: ScrollBar {}
}