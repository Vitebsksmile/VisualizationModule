#ifndef MYVIEW_H
#define MYVIEW_H

#include <QListView>    //  стандартный виджет списка


class MyView : public QListView
{
    Q_OBJECT
public:
    MyView(QWidget *parent = nullptr);
};

#endif // MYVIEW_H
