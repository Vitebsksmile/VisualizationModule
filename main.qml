import QtQuick 2.15
import QtCore
import QtQuick.Controls
import QtQuick.Layouts


ApplicationWindow {
    width: 640; height: 480
    visible: true
    title: "OIS by QML"


//------------------------START MENU_BAR------------------------
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
//------------------------END MENU_BAR------------------------

//------------------------START HEADER------------------------
    SplitView {
        id: splitView
        anchors.fill: parent
        anchors.margins: 5
        orientation: Qt.Horizontal

        //  боковое меню
        Rectangle {
            id: sideBar
            color: Qt.rgba(44/255, 62/255, 80/255, 0.9)
            radius: 10

            SplitView.preferredWidth: 150
            SplitView.minimumWidth: 100
            SplitView.maximumWidth: 300

            ButtonSideBar {
                id: sideBarButton
                //  передаем ссылки на объекты из viewer
                //targetHandler: viewer.handler
                //targetPopup: viewer.popup
                // Используем безопасный доступ через Loader.item
                targetHandler: contentLoader.item ? contentLoader.item.handler : null
                targetPopup: contentLoader.item ? contentLoader.item.popup : null
            }
        }


        //  Центр окна (ваш контент)
        ColumnLayout {
            SplitView.fillWidth: true

            Loader {
                id: contentLoader
                Layout.fillWidth: true
                Layout.fillHeight: true

                //  динамический выбор компонента
                sourceComponent: sideBarButton.isVideoSelected ? videoComponent : imageComponent
            }

            Component {
                id: imageComponent
                ImageView {
                    id: imageViewer
                    //Layout.fillWidth: true
                    //Layout.fillHeight: true
                    //  св-ва, к-рые я вы передавали:
                    //handler: imageViewer.handler (если нужно)
                }
            }

            Component {
                id: videoComponent
                VideoViewer {
                    id: videoViewer
                    //  настройки для видео
                }
            }
        }
    }
//------------------------END HEADER------------------------


}
