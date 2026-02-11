import QtQuick 2.15
import QtCore
import QtQuick.Controls
import QtQuick.Controls.Basic


ApplicationWindow {
    width: 640; height: 480
    visible: true
    title: "OIS by QML"


    //  1. Описываем действия (Actions), чтобы не дублировать код
    Action {
        id: openAction
        text: "&Открыть..."
        shortcut: StandardKey.Open
        onTriggered: console.log("Нажали 'Открыть'")
    }

    Action {
        id: exitAction
        text: "&Выход"
        shortcut: "Ctrl+Q"
        onTriggered: Qt.quit()  //  Стандартная ф-ция выхода
    }

    // 2. Добавляем саму полосу меню
    menuBar: MenuBar {

        Menu {
            title: "&Файл"
            MenuItem { action: openAction }
            MenuItem { action: exitAction }
        }

        Menu {
            title: "&Правка"
            MenuItem { text: "Копировать"; enabled: false }    //  Пример неактивного пункта
            MenuItem { text: "Вставить" }
        }

        Menu {
            title: "&Помощь"
            MenuItem {
                text: "О программе"
                onTriggered: aboutDialog.open()
            }
        }

    }


    //  прозрачный вспомогательный виджет
    Rectangle {
        anchors.fill: parent
        color: "#eeeeee"
    }


    SplitView {
        id: splitView
        anchors.fill: parent
        anchors.margins: 5
        orientation: Qt.Horizontal

        //  боковое меню
        Rectangle {
            id: sideBar
            //color: "#2c3e50"
            color: Qt.rgba(44/255, 62/255, 80/255, 0.9)
            radius: 10


            SplitView.preferredWidth: 200
            SplitView.minimumWidth: 150
            SplitView.maximumWidth: 300

            Text {
                anchors.centerIn: parent
                text: "Side Bar"
                color: "white"
            }
        }


        //  Центр окна (ваш контент)
        Rectangle {
            SplitView.fillWidth: true
            color: "lightblue"
            radius: 10
        }
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
