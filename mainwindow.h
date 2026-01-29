#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QSplitter>
#include <QToolBar>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QPushButton *btn1, *btn2;

    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    //  приватный указатель на пользовательский виджет
    //

    /*  объявление приватного метода для инициализации
     *  и компоновки всего интерфейса*/
    void setupUI();
};

#endif // MAINWINDOW_H
