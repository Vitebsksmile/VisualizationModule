#include "mainwindow.h"
#include "visualiser.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
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

    Visualiser *viz = new Visualiser(this);
    setCentralWidget(viz);
    setCentralWidget(centralSplitter);

    //  настройка панели инструментов
    mainToolBar = addToolBar(tr("Main Tools"));
    //setupToolBar();
}
