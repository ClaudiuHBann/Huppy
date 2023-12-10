import QtQuick
import QtQuick.Controls

import Huppy.QML

ListView {
    model: ListViewCategory {
        id: listViewCategory

        Component.onCompleted: {
            ManagerView.GetListViewCategory(listViewCategory);
        }
    }
    
    delegate: DelegateCategory {}

    ScrollBar.vertical: ScrollBar {}
}