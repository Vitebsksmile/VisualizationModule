#ifndef IMAGEVIEWER_H
#define IMAGEVIEWER_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPixmap>
//#include <QList>
#include <opencv2/cvv/cvv.hpp>

class ImageViewer : public QGraphicsView
{
    Q_OBJECT
public:
    explicit ImageViewer(QWidget *parent = nullptr);

/*public slots:
    void displayImage(const cv::Mat &image);
    void showDetectionResults(const QList<Defect> &defect);
    void clearResults();*/

/*protected:
    void wheelEvent(QWheelEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;*/

private:
    QGraphicsScene *scene;
    QGraphicsPixmapItem *imageItem;
    QList<QGraphicsItem> *defectItem;
    double zoomFactor;

    void setupScene();
    QPixmap mapToPixmap(const cv::Mat &mat);
    //void drawDefect(const Defect &defect);
};

#endif // IMAGEVIEWER_H
