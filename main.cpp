#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>  //  нужен для передачи модели в QML
//#include <QApplication>
#include <QTimer>

#include "MyModel.h"
//#include "MyView.h"
//#include "MyDelegate.h"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    MyModel model;  //  создаем объект данных
    /*MyView view;
    MyDelegate delegate;

    //  ectablishing connections
    view.setModel(&model);              //  linking the View to the Model
    view.setItemDelegate(&delegate);    //  assigning the Delegate to the View

    view.setWindowTitle("Qt -- MV-D");
    view.resize(300, 200);
    view.show();*/

    QTimer::singleShot(3000, [&model]() {
        model.addItem("New model (for timer)");
    });

    QQmlApplicationEngine engine;

    //  ГЛАВНОЕ: Регестрируем нашу роль в контексте QML под именем 'myGlobalModel'
    engine.rootContext()->setContextProperty("myGlobalModel", &model);

    engine.load(QUrl("qrc:/qt/qml/path/main.qml"));  //   загружаем интерфейс


    return app.exec();
}
