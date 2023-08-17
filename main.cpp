#include "mainwindow.h"
#include "window_pvc.h"
#include "window_pvp.h"

#include <QApplication>
#include <QSize>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QSize windowSize(836, 479);
    MainWindow w;

    w.resize(windowSize);
    w.setWindowTitle("Выбор режима игры");
    QIcon appIcon("C:\\users\\admin\\desktop\\icon_tictactoe.ico");
    w.setWindowIcon(appIcon);

    w.show();
    return app.exec();
}
