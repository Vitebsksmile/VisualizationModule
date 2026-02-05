#include "visualiser.h"

Visualiser::Visualiser(QWidget *parent)
    : QWidget(parent)
{
    auto *layout = new QVBoxLayout(this);
    imageViewer = new ImageViewerWidget(this);
    chartWidget = new ChartWidget(this);
    statsWidget = new StatisticsWidget(this);
    exportManager = new ExportManager(this);

    layout->addWidget(imageViewer, 5);
    layout->addWidget(imageViewer, 2);
    layout->addWidget(imageViewer, 1);
    setLayout(layout);
}

void Visualiser::displayImage(const QImage &image)
{
    imageViewer->displayImage(image);
}

void Visualiser::displayDetections(const QVector<QRect> &boxes)
{
    imageViewer->drawDetections(boxes);
}

void Visualiser::updateStatistics(double precision, double recall, double f1)
{
    chartWidget->updateMetrics(precision, recall, f1);
    statsWidget->setMetrics(precision, recall, f1);
}
