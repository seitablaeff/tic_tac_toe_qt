#include "window_pvp.h"
#include "ui_window_pvp.h"
#include "pole.h"

#include <QMessageBox>
#include <QDebug>

using namespace std;

window_PvP::window_PvP(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::window_PvP)
{
    ui->setupUi(this);

    connect(ui->begin, &QPushButton::clicked, this, window_PvP::begin_clicked);
    connect(ui->pushButton, &QPushButton::clicked, this, window_PvP::pushButtonsClicked);
    connect(ui->pushButton_2, &QPushButton::clicked, this, window_PvP::pushButtonsClicked);
    connect(ui->pushButton_3, &QPushButton::clicked, this, window_PvP::pushButtonsClicked);
    connect(ui->pushButton_4, &QPushButton::clicked, this, window_PvP::pushButtonsClicked);
    connect(ui->pushButton_5, &QPushButton::clicked, this, window_PvP::pushButtonsClicked);
    connect(ui->pushButton_6, &QPushButton::clicked, this, window_PvP::pushButtonsClicked);
    connect(ui->pushButton_7, &QPushButton::clicked, this, window_PvP::pushButtonsClicked);
    connect(ui->pushButton_8, &QPushButton::clicked, this, window_PvP::pushButtonsClicked);
    connect(ui->pushButton_9, &QPushButton::clicked, this, window_PvP::pushButtonsClicked);

    arr[0] = ui->pushButton;
    arr[1] = ui->pushButton_2;
    arr[2] = ui->pushButton_3;
    arr[3] = ui->pushButton_4;
    arr[4] = ui->pushButton_5;
    arr[5] = ui->pushButton_6;
    arr[6] = ui->pushButton_7;
    arr[7] = ui->pushButton_8;
    arr[8] = ui->pushButton_9;

    // я не знаю, как работает этот кусок кода, реально
    signalMapper = new QSignalMapper(this);
    connect(signalMapper, SIGNAL(mapped(QString)), this, SLOT(onPushButtonClicked(QString)));

    for (int i = 0; i < 9; i++) {
        QPushButton *button = arr[i];
        connect(button, SIGNAL(clicked()), signalMapper, SLOT(map()));
        signalMapper->setMapping(button, button->objectName());
    }
    // вот граница нижняя
}

window_PvP::~window_PvP()
{
    delete ui;
}

void window_PvP::begin_clicked()
{
    // игру можно начать только если есть 2 имя и нажата радиокнопка
    if ( (ui->choise_first->isChecked() || ui->choise_second->isChecked()) && (ui->name_player_first->text() != "" && ui->name_player_second->text() != "") ){
        // выключаем кнопку Начала игры
        ui->begin->setEnabled(false);

        // включаем кнопки и делаем их пустыми
        for(int i = 0; i < 9; i++){
            arr[i]->setText("");
            arr[i]->setEnabled(true);
        }

        currentPlayer = 1;

        // 1 игрок первым ходит
        if (ui->choise_first->isChecked()) {
            gameMode = 0;
            ui->state_of_game->setText("Ход игрока - " + ui->name_player_first->text());
        }
        // 2 игрок первым ходит
        else if (ui->choise_second->isChecked()) {
            gameMode = 1;
            ui->state_of_game->setText("Ход игрока - " + ui->name_player_second->text());
        }
    }
}

void window_PvP::pushButtonsClicked() {
    QString name_first = ui->name_player_first->text();
    QString name_second = ui->name_player_second->text();

    // если 1 игрок ходит первым
    if (gameMode == 0){
        int checks = 0;
        // ход 1 игрока
        if (currentPlayer == 1 && checks == 0) {
            ui->state_of_game->setText("Ход игрока - " + ui->name_player_second->text());
            // нажатие на кнопку заменяет текст на "X"
            QPushButton *clickedButton = qobject_cast<QPushButton*>(sender());
            if (clickedButton) {
                // qDebug() << "я меняю на Х";
                clickedButton->setText("X");
                clickedButton->setEnabled(false);

                currentPlayer = 2;
                checks++;

                checkWinOrDraw(name_first);
            }
        }

        // ход 2 игрока
        if (currentPlayer == 2 && checks == 0) {
            // нажатие на кнопку заменяет текст на "0"
            ui->state_of_game->setText("Ход игрока - " + ui->name_player_first->text());
            QPushButton *clickedButton = qobject_cast<QPushButton*>(sender());
            if (clickedButton) {
                // qDebug() << "а я меняю на 0";
                clickedButton->setText("0");
                clickedButton->setEnabled(false);

                currentPlayer = 1;
                checks++;

                checkWinOrDraw(name_second);
            }
        }
    }
    // если 2 игрок ходит первым
    if (gameMode == 1) {
        int checks = 0;
        // ход 2 игрока
        if (currentPlayer == 1 && checks == 0) {
            // нажатие на кнопку заменяет текст на "X"
            ui->state_of_game->setText("Ход игрока - " + ui->name_player_first->text());
            QPushButton *clickedButton = qobject_cast<QPushButton*>(sender());
            if (clickedButton) {
                // qDebug() << "я меняю на Х";
                clickedButton->setText("X");
                clickedButton->setEnabled(false);

                currentPlayer = 2;
                checks++;

                checkWinOrDraw(name_second);
            }
        }

        // ход 1 игрока
        if (currentPlayer == 2 && checks == 0) {
            // нажатие на кнопку заменяет текст на "0"
            ui->state_of_game->setText("Ход игрока - " + ui->name_player_second->text());
            QPushButton *clickedButton = qobject_cast<QPushButton*>(sender());
            if (clickedButton) {
                // qDebug() << "а я меняю на 0";
                clickedButton->setText("0");
                clickedButton->setEnabled(false);

                currentPlayer = 1;
                checks++;

                checkWinOrDraw(name_first);
            }
        }
    }
}

bool window_PvP::checkWinOrDraw(QString s) {
    string a0, a1, a2, a3, a4, a5, a6, a7, a8;

    a0 = arr[0]->text().toStdString();
    a1 = arr[1]->text().toStdString();
    a2 = arr[2]->text().toStdString();
    a3 = arr[3]->text().toStdString();
    a4 = arr[4]->text().toStdString();
    a5 = arr[5]->text().toStdString();
    a6 = arr[6]->text().toStdString();
    a7 = arr[7]->text().toStdString();
    a8 = arr[8]->text().toStdString();

    // главная и побочная диагональ
    if ( (a0 == a4 && a4 == a8 && a0 != "") || (a2 == a4 && a4 == a6 && a2 != "") ) {
        QMessageBox::information(this, "Победа!", "Победа игрока - " + s + " !");
        ui->state_of_game->setText("Игра окончена!");
        return true;
    }

    // все горизонтали
    if ( (a0 == a1 && a1 == a2 && a0 != "") || (a3 == a4 && a4 == a5 && a3 != "") || (a6 == a7 && a7 == a8 && a6 != "") ) {
        QMessageBox::information(this, "Победа!", "Победа игрока - " + s + " !");
        ui->state_of_game->setText("Игра окончена!");
        return true;
    }

    // все вертикали
    if ( (a0 == a3 && a3 == a6 && a0 != "") || (a1 == a4 && a4 == a7 && a1 != "") || (a2 == a5 && a5 == a8 && a2 != "") ) {
        QMessageBox::information(this, "Победа!", "Победа игрока - " + s + " !");
        ui->state_of_game->setText("Игра окончена!");
        return true;
    }

    // проверка ничьи
    int isFull = 0;
    for (int i = 0; i < 9; i++) {
        if (arr[i]->text() != "") {
            isFull++;
        }
    }

    if(isFull == 9) {
        QMessageBox::information(this, "Ничья!", "По итогам игры - у вас ничья!");
        ui->state_of_game->setText("Игра окончена!");
        return true;
    }

    return false;
}

void window_PvP::pushButton_1_clicked()
{
    // ui->pushButton->setText("X");
}

void window_PvP::pushButton_2_clicked()
{
    // ui->pushButton_2->setText("X");
}

void window_PvP::pushButton_3_clicked()
{
    // ui->pushButton_3->setText("X");
}

void window_PvP::pushButton_4_clicked()
{
    // ui->pushButton_4->setText("X");
}

void window_PvP::pushButton_5_clicked()
{
    // ui->pushButton_5->setText("X");
}

void window_PvP::pushButton_6_clicked()
{
    // ui->pushButton_6->setText("X");
}

void window_PvP::pushButton_7_clicked()
{
    // ui->pushButton_7->setText("X");
}

void window_PvP::pushButton_8_clicked()
{
    // ui->pushButton_8->setText("X");
}

void window_PvP::pushButton_9_clicked()
{
    // ui->pushButton_9->setText("X");
}

