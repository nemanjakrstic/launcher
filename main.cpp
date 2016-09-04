#include <QApplication>

#include "LauncherScene.h"
#include "LauncherView.h"

int main(int argc, char *argv[])
{
    QApplication application(argc, argv);

    LauncherScene launcherScene;

    LauncherView launcherView(&launcherScene);

    launcherView.showFullScreen();

    return application.exec();
}
