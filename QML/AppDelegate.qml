import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

ItemDelegate {
    contentItem: RowLayout {
        spacing: 10

        Label { text: id }
        Label { text: category }
        Label { text: name }
        Label { text: proposed }
    }
}