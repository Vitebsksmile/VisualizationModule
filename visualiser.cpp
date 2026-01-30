#include "visualiser.h"

Visualiser::Visualiser(QWidget *parent)
    : QWidget(parent)
{
    auto *layout = new QVBoxLayout(this);

}

void Visualiser::displayImage(const QImage &image)
{

}

void Visualiser::displayDetections(const QVector<QRect> &boxes)
{

}

void Visualiser::updateStatistics(double precision, double recall, double f1)
{

}
