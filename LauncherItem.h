#ifndef LAUNCHERITEM_H
#define LAUNCHERITEM_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItemGroup>
#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QTimeLine>
#include <QProcess>
#include <QPixmap>
#include <QObject>
#include <QDebug>
#include <QBrush>

class LauncherItem : public QObject, public QGraphicsItemGroup
{
    Q_OBJECT

    public:

        LauncherItem(QString appPath, QString iconPath, int size, QGraphicsItem *parent = nullptr);

    private:

        QGraphicsPixmapItem *iconPixmapItem;
        QTimeLine timeLine;
        QString appPath;

        void onTimeLineValueChanged(qreal value);
        void onTimeLineFinished();

    protected:

        void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;
        void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override;
        void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
        void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // LAUNCHERITEM_H
