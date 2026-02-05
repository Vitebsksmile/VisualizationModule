#include "mymodel.h"

MyModel::MyModel(QObject *parent) :
    QAbstractListModel(parent)
{
    m_items << "Ядро системы" << "Модуль графики" << "База данных" << "Сеть";
}

int MyModel::rowCount(const QModelIndex &parent) const
{
    return m_items.count();
}

QVariant MyModel::data(const QModelIndex &index, int role) const
{
    //  проверяем корректность индекса (не выходит ли за границы)
    if (!index.isValid())
    {
        return QVariant();
    }

    //  если View просит текст для отрисовки (DisplayRole)
    if (role == Qt::DisplayRole)
    {
        return m_items.at(index.row()); //  возвращаем строку из нашего списка
    }

    return QVariant();  //  в остальных случаях возвращаем "ничего"
}
