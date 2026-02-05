#include "imageviewer.h"

#include <QPainter>

ImageViewer::ImageViewer(QWidget *parent)
    : QGraphicsView(parent)
{
    setupScene();

}

void ImageViewer::setupScene()
{
    scene = new QGraphicsScene(this);
}
