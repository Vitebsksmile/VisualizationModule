#ifndef VISUALISER_H
#define VISUALISER_H

#include <QWidget>
#include <QVBoxLayout>

class Visualiser : public QWidget
{
    Q_OBJECT
public:
    explicit Visualiser(QWidget *parent = nullptr);

    void displayImage(const QImage &image);
    void displayDetections(const QVector<QRect> &boxes);
    void updateStatistics(double precision, double recall, double f1);

private:

};

#endif // VISUALISER_H
