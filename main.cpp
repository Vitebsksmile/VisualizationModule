#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickWindow>

int main(int argc, char *argv[])
{
    QGuiApplication a(argc, argv);

    QQuickWindow::setDefaultAlphaBuffer(true);

    QQmlApplicationEngine engine;
    const QUrl url("qrc:/qt/qml/path/main.qml");
    engine.load(url);

    return a.exec();
}
