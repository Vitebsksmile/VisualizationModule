#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent)
{
    setMinimumSize(600, 300);
    setupUI();
}

//  деструктор
MainWindow::~MainWindow()
{
    //  Qt сам позаботиться об удалении дочерних виджетов
}

void MainWindow::setupUI()
{
    QSplitter *centralSplitter = new QSplitter(Qt::Horizontal);


}
