#include "LauncherView.h"

LauncherView::LauncherView(QGraphicsScene *scene, QWidget *parent) :
    QGraphicsView(scene, parent)
{
    // set background to black
    setBackgroundBrush(QBrush(Qt::black));

    // set viewport update mode to full update
    setViewportUpdateMode(QGraphicsView::FullViewportUpdate);

    setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
}

void LauncherView::resizeEvent(QResizeEvent *event)
{
    fitInView(sceneRect(), Qt::KeepAspectRatio);

    QGraphicsView::resizeEvent(event);
}
