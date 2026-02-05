#ifndef VISUALISER_H
#define VISUALISER_H

#include <QWidget>
#include <QVBoxLayout>

#include "imageviewerwidget.h"
#include "chartwidget.h"
#include "statisticswidget.h"
#include "exportmanager.h"


class Visualiser : public QWidget
{
    Q_OBJECT
public:
    explicit Visualiser(QWidget *parent = nullptr);

    void displayImage(const QImage &image);
    void displayDetections(const QVector<QRect> &boxes);
    void updateStatistics(double precision, double recall, double f1);

private:
    ImageViewerWidget *imageViewer;
    ChartWidget *chartWidget;
    StatisticsWidget *statsWidget;
    ExportManager *exportManager;
};

#endif // VISUALISER_H
