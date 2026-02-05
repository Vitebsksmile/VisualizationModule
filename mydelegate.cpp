#include "mydelegate.h"
#include <QPainter>

void MyDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    painter->save();    //  сохраняем настройки кисти/пера

    //  если элемент выделен мышью, рисуем рамку
    if (option.state & QStyle::State_Selected)
    {
        painter->fillRect(option.rect, option.palette.highlight());
    }

    //  кастомная логика: рисуем текст синим цветом
    painter->setPen(Qt::blue);
    QString text = index.data().toString(); //  берем текст из модели
    painter->drawText(option.rect, Qt::AlignCenter, text);  //  рисуем по центру

    painter->restore(); //  восстанавливаем настройки (хороший тон)
}

QSize MyDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    return QSize(100, 40);  //  задаем фиксированный размер каждой ячейки
}
