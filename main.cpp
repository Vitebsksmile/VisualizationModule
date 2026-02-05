#include <QApplication>

#include "mymodel.h"
#include "mydelegate.h"
#include "myview.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MyModel model;          //  1. создаем объект с данными
    MyView view;            //  2. создаем объект экрана (пустой список)
    MyDelegate delegate;    //  3. создаем объект-отрисовщик

    //  главное: связываем все воедино
    view.setModel(&model);  //  говорим 'view': "Бери данные из этой 'model'"
    view.setItemDelegate(&delegate);    //  говорим 'view': "Рисуй ячейки через этот 'delegate'"

    view.setWindowTitle("MVD_WIDGET");
    view.resize(400, 300);
    view.show();


    return a.exec();
}
