#ifndef LAUNCHERSCENE_H
#define LAUNCHERSCENE_H

#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGamepad>
#include <QObject>
#include <QPointF>
#include <QList>

#include "LauncherItem.h"
#include "Grid.h"

class LauncherScene : public QGraphicsScene
{
    Q_OBJECT

    public:
        LauncherScene(QObject *parent = nullptr);

    private slots:
        void onGamepadButtonStartChanged(bool value);
};

#endif // LAUNCHERSCENE_H
