import QtQuick 2.15
import QtQuick.Controls

Window {
    width: 640; height: 480
    visible: true
    title: "OIS by QML"

    Text {
        anchors.centerIn: parent
        text: "Приложение запущено!"
    }

    /*ListView {
        anchors.fill: parent
        model: myGlobalModel    //  ссылаемся на модель по имени, к-рое дидим в main.cpp
        spacing: 5

        //  DELEGATE: Как выглядит одна строка
        delegate: Rectangle {
            width: parent.width
            height: 40
            color: "lightgray"
            border.color: "darkgray"

            Text {
                anchors.centerIn: parent
                text: name  //  используем роль 'name' из нашей C++ модели
                color: "blue"
                font.pixelSize: 16
            }
        }
    }*/
}
