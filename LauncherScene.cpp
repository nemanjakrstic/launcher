#include "LauncherScene.h"

LauncherScene::LauncherScene(QObject *parent) :
    QGraphicsScene(parent)
{
    setSceneRect(0, 0, 1280, 800);

    int margin = 50, columns = 6;

    Grid grid(sceneRect().width(), columns, margin);

    QList<LauncherItem *> items;

    for (int i = 0; i < 10; i++)
    {
        items.append(new LauncherItem("open \"/Applications/Sublime Text.app\"", "/Users/nemanja/qt.png", grid.getItemSize()));
    }

    for (int i = 0; i < items.length(); i++)
    {
        LauncherItem *launcherItem = items.at(i);
        launcherItem->setPos(grid.pos());
        addItem(launcherItem);

        grid.next();
    }

    QGamepad *gamepad = new QGamepad(0, this);

    connect(gamepad, &QGamepad::buttonAChanged, this, &LauncherScene::onGamepadButtonStartChanged);

    qDebug() << "ready";
}

void LauncherScene::onGamepadButtonStartChanged(bool value)
{
    qDebug() << (value ? "on" : "off");
}
