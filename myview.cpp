#include "myview.h"

MyView::MyView(QWidget *parent)
    : QListView(parent)
{
    setAlternatingRowColors(true);  //  вкл. "зебру" (чередование цветов строк)
}
