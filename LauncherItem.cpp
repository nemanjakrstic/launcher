#include "LauncherItem.h"

LauncherItem::LauncherItem(QString appPath, QString iconPath, int size, QGraphicsItem *parent) :
    QObject(),
    QGraphicsItemGroup(parent),
    appPath(appPath)
{
    setAcceptHoverEvents(true);

    QPixmap iconPixmap(iconPath);

    iconPixmapItem = new QGraphicsPixmapItem(
        iconPixmap.scaledToHeight(size, Qt::SmoothTransformation), this
    );

    addToGroup(iconPixmapItem);

    iconPixmapItem->setTransformOriginPoint(iconPixmapItem->boundingRect().center());

    timeLine.setDuration(333);
    timeLine.setUpdateInterval(20);

    connect(&timeLine, &QTimeLine::valueChanged, this, &LauncherItem::onTimeLineValueChanged);
    connect(&timeLine, &QTimeLine::finished, this, &LauncherItem::onTimeLineFinished);
}

void LauncherItem::onTimeLineValueChanged(qreal value)
{
    iconPixmapItem->setScale(1 + value);
    iconPixmapItem->setOpacity(1 - value);
}

void LauncherItem::onTimeLineFinished()
{
    iconPixmapItem->setScale(1);
    iconPixmapItem->setOpacity(1);
}

void LauncherItem::hoverEnterEvent(QGraphicsSceneHoverEvent *)
{
    iconPixmapItem->setScale(1.15);
}

void LauncherItem::hoverLeaveEvent(QGraphicsSceneHoverEvent *)
{
    iconPixmapItem->setScale(1);
}

void LauncherItem::mousePressEvent(QGraphicsSceneMouseEvent *)
{
    iconPixmapItem->setOpacity(0.75);
}

void LauncherItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *)
{
    timeLine.start();

    qDebug() << (QProcess::startDetached(appPath) ? 1 : 0);
}
