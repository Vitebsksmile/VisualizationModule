#ifndef STATISTICSWIDGET_H
#define STATISTICSWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>


class StatisticsWidget : public QWidget
{
    Q_OBJECT
public:
    explicit StatisticsWidget(QWidget *parent = nullptr);
    void setMetrics(double precision, double recall, double f1);

private:
    QLabel *precisionLable;
    QLabel *recallLabel;
    QLabel *f1Label;
};

#endif // STATISTICSWIDGET_H
