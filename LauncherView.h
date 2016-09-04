#ifndef LAUNCHERVIEW_H
#define LAUNCHERVIEW_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWidget>
#include <QDebug>
#include <QBrush>

class LauncherView : public QGraphicsView
{
    public:
        LauncherView(QGraphicsScene *scene, QWidget *parent = nullptr);

    protected:
        void resizeEvent(QResizeEvent *event);
};

#endif // LAUNCHERVIEW_H
