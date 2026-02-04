#include "mydelegate.h"


void MyDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    painter->save();
    painter->setPen(Qt::blue);  //  Custom color
    painter->drawText(option.rect, Qt::AlignCenter, index.data().toString());
    painter->restore();
}
