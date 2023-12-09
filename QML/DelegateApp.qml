import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

import Huppy.QML

ItemDelegate {
    contentItem: RowLayout {
        spacing: 10

        Label { text: modelData.id }
        Label { text: modelData.category }
        Label { text: modelData.name }
        Label { text: modelData.proposed }
    }
}