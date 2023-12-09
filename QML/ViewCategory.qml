import QtQuick
import QtQuick.Controls

import Huppy.QML

ListView {
    width: 320; height: 480

    model: ListViewCategory {
        id: listViewCategory

        Component.onCompleted: {
            ManagerView.GetListViewCategory(listViewCategory);
        }
    }
    
    delegate: DelegateCategory {}

    ScrollBar.vertical: ScrollBar {}
}