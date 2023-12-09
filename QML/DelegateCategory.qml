import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

import Huppy.QML

ItemDelegate {
    contentItem: RowLayout {
        spacing: 10

        Label { text: category.name }

        ViewApp {
            id: viewApp
            objectName: "viewApp"
            model: apps
        }
    }
}