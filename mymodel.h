#ifndef MYMODEL_H
#define MYMODEL_H

#include <QAbstractListModel>   //  базовый класс для списков

class MyModel : public QAbstractListModel
{
    Q_OBJECT
public:
    MyModel(QObject *parent = nullptr);

    //  возвращает количество строк в списке (обязательно для переопределения
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    //  возвращает данные для конкретной ячейки и роли (отображение, цвет и т.д.)
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
    QStringList m_items;    //  наше реальное хранилище данных
};

#endif // MYMODEL_H
