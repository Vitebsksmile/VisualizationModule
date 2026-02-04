import QtQuick 2.15
import QtQuick.Controls

Window {
    width: 400; height: 300
    visible: true
    title: "C++ Model + QML View"

    ListView {
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
    }
}
