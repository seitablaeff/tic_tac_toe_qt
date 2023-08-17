#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "window_pvp.h"
#include "window_pvc.h"

#include <QSize>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_button_confirm_clicked()
{
    QSize windowSize(836, 479);

    // Игрок vs Игрок
    if (ui->radio_pvp->isChecked()) {
        // close();
        window_PvP window;

        window.resize(windowSize);
        window.setWindowTitle("Игрок vs Игрок");
        window.setWindowIcon(QIcon("C:\\users\\admin\\desktop\\icon_tictactoe.ico"));

        window.exec();
    }
    // Игрок vs Computer
    if (ui->radio_pvc->isChecked()) {
        // 3close();
        window_pvc window;
        window.resize(windowSize);
        window.setWindowTitle("Игрок vs Computer");
        window.setWindowIcon(QIcon("C:\\users\\admin\\desktop\\icon_tictactoe.ico"));

        window.exec();
    }
}

