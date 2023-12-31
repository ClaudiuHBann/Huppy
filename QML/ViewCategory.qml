﻿import QtQuick
import QtQuick.Controls

import Huppy.QML

ListView {
    boundsBehavior: Flickable.StopAtBounds

    model: ListViewCategory {
        id: listViewCategory

        Component.onCompleted: {
            ManagerView.GetListViewCategory(listViewCategory);
        }
    }
    
    delegate: DelegateCategory {}
    ScrollBar.vertical: ScrollBar {}
}