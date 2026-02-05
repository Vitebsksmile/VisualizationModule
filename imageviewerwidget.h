#ifndef IMAGEVIEWERWIDGET_H
#define IMAGEVIEWERWIDGET_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>


class ImageViewerWidget : public QGraphicsView
{
    Q_OBJECT
public:
    explicit ImageViewerWidget(Qwidget *parent = nullptr);
    void displayImage(const QImage &image);
    void drawDetections(const QVector<QRect> &boxes);

private:
    QGraphicsScene *scene;
    QGraphicsPixmapItem *pixmapItem;
};

#endif // IMAGEVIEWERWIDGET_H
