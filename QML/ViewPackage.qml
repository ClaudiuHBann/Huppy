import QtQuick
import QtQuick.Controls

import Huppy.QML

ListView {
    boundsBehavior: Flickable.StopAtBounds

    model: ListViewPackage {
        id: listViewPackage

        Component.onCompleted: {
            ManagerView.GetListViewPackage(listViewPackage);
        }
    }

    delegate: DelegatePackage {}
    ScrollBar.vertical: ScrollBar {}
}