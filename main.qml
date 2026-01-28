import QtQuick 2.15
import QtQuick.Window
import QtQml.Models

Window {
    id: mainWindow
    width: 640
    height: 480
    visible: true
    title: VisualizationModule

    color: "transparent"

    flags: Qt.Window | Qt.FramelessWindowHint

    ObjectModel {
        id: itemsModel

        Rectangle {
            anchors.centerIn: parent
            width: 200; height: 200
            //color: "rgb(255, 255, 255)"
            radius: 20

            Text {
                anchors.centerIn: parent
                text: qsTr("text")
            }
        }
    }

    ListView {
        anchors.fill: parent
        model: itemsModel
    }
}
