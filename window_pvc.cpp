#include "window_pvc.h"
#include "ui_window_pvc.h"

#include <QMessageBox>
#include <random>

window_pvc::window_pvc(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::window_pvc)
{
    ui->setupUi(this);

    connect(ui->begin, &QPushButton::clicked, this, window_pvc::begin_clicked);
    connect(ui->pushButton, &QPushButton::clicked, this, window_pvc::pushButtonsClicked);
    connect(ui->pushButton_2, &QPushButton::clicked, this, window_pvc::pushButtonsClicked);
    connect(ui->pushButton_3, &QPushButton::clicked, this, window_pvc::pushButtonsClicked);
    connect(ui->pushButton_4, &QPushButton::clicked, this, window_pvc::pushButtonsClicked);
    connect(ui->pushButton_5, &QPushButton::clicked, this, window_pvc::pushButtonsClicked);
    connect(ui->pushButton_6, &QPushButton::clicked, this, window_pvc::pushButtonsClicked);
    connect(ui->pushButton_7, &QPushButton::clicked, this, window_pvc::pushButtonsClicked);
    connect(ui->pushButton_8, &QPushButton::clicked, this, window_pvc::pushButtonsClicked);
    connect(ui->pushButton_9, &QPushButton::clicked, this, window_pvc::pushButtonsClicked);

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

window_pvc::~window_pvc()
{
    delete ui;
}

void window_pvc::begin_clicked()
{
    // выключаем кнопку Начала игры
    ui->begin->setEnabled(false);

    // включаем кнопки и делаем их пустыми
    for(int i = 0; i < 9; i++){
        // arr[i]->setText("");
        arr[i]->setEnabled(true);
    }

    // игрок ходит первым
    if (ui->choise_first->isChecked()) {
        gameMode = 0;
        currentPlayer = 1;
        playerVal = "X";
        ui->state_of_game->setText("Ваш ход!");
    }
    // Computer ходит первым
    if (ui->choise_second->isChecked()) {
        gameMode = 1;
        currentPlayer = 2;
        playerVal = "0";
        ui->state_of_game->setText("Ход Computer!");
    }
}

void window_pvc::pushButtonsClicked() {
    int checks = 0;
    // если игрок ходит первым
    if (gameMode == 0){
        // ХОД ИГРКОКА
        if (currentPlayer == 1 && checks == 0) {
            ui->state_of_game->setText("Ход Computer");
            // нажатие на кнопку заменяет текст на "X"
            QPushButton *clickedButton = qobject_cast<QPushButton*>(sender());
            if (clickedButton) {
                qDebug() << "1";

                clickedButton->setText("X");
                clickedButton->setEnabled(false);

                currentPlayer = 2;
                checks++;

                checkWinOrDraw(ui->name_player_first->text());
            }
        }
    }
    // если Computer ходит первым
    if (gameMode == 1) {
        // ХОД ИГРОКА
        if (currentPlayer == 2 && checks == 0) {
            // нажатие на кнопку заменяет текст на "X"
            ui->state_of_game->setText("Ход компьютера");
            QPushButton *clickedButton = qobject_cast<QPushButton*>(sender());
            if (clickedButton) {
                qDebug() << "2";

                clickedButton->setText("0");
                clickedButton->setEnabled(false);

                currentPlayer = 1;
                checks++;

                checkWinOrDraw(ui->name_player_first->text());
            }
        }
    }
}

void window_pvc::on_submit_clicked() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0, 3);

    QString a0, a1, a2, a3, a4, a5, a6, a7, a8;

    a0 = arr[0]->text();
    a1 = arr[1]->text();
    a2 = arr[2]->text();
    a3 = arr[3]->text();
    a4 = arr[4]->text();
    a5 = arr[5]->text();
    a6 = arr[6]->text();
    a7 = arr[7]->text();
    a8 = arr[8]->text();

    // случайные значения
    int s;
    int count = 0;

    // значение игрока и компа
    QString compVal;
    if (playerVal == "X") {
        compVal = "0";
    }
    if (playerVal == "0") {
        compVal = "X";
    }

    //............... 1 правило
    // ГОРИЗОНТАЛИ
    // X X -
    if (a0 == compVal && a1 == compVal && a2 == "" && count == 0) {
        arr[2]->setText(compVal);
        arr[2]->setEnabled(false);
        count++;
        qDebug() << "1";
    }
    else if (a3 == compVal && a4 == compVal && a5 == "" && count == 0) {
        arr[5]->setText(compVal);
        arr[5]->setEnabled(false);
        count++;
        qDebug() << "2";
    }
    else if (a6 == compVal && a7 == compVal && a8 == "" && count == 0) {
        arr[8]->setText(compVal);
        arr[8]->setEnabled(false);
        count++;
        qDebug() << "3";
    }
    // X - X
    if (a0 == compVal && a2 == compVal && a1 == "" && count == 0) {
        arr[1]->setText(compVal);
        arr[1]->setEnabled(false);
        count++;
        qDebug() << "4";
    }
    else if (a3 == compVal && a5 == compVal && a4 == "" && count == 0) {
        arr[4]->setText(compVal);
        arr[4]->setEnabled(false);
        count++;
        qDebug() << "5";
    }
    else if (a6 == compVal && a8 == compVal && a7 == "" && count == 0) {
        arr[7]->setText(compVal);
        arr[7]->setEnabled(false);
        count++;
        qDebug() << "6";
    }
    // - X X
    if (a1 == compVal && a2 == compVal && a0 == "" && count == 0) {
        arr[0]->setText(compVal);
        arr[0]->setEnabled(false);
        count++;
        qDebug() << "7";
    }
    else if (a4 == compVal && a5 == compVal && a3 == "" && count == 0) {
        arr[3]->setText(compVal);
        arr[3]->setEnabled(false);
        count++;
        qDebug() << "8";
    }
    else if (a7 == compVal && a8 == compVal && a6 == "" && count == 0) {
        arr[6]->setText(compVal);
        arr[6]->setEnabled(false);
        count++;
        qDebug() << "9";
    }

    // ВЕРТИКАЛИ
    // -
    // X
    // X
    if (a3 == compVal && a6 == compVal && a0 == "" && count == 0) {
        arr[0]->setText(compVal);
        arr[0]->setEnabled(false);
        count++;
        qDebug() << "10";
    }
    else if (a4 == compVal && a7 == compVal && a1 == "" && count == 0) {
        arr[1]->setText(compVal);
        arr[1]->setEnabled(false);
        count++;
        qDebug() << "11";
    }
    else if (a5 == compVal && a8 == compVal && a2 == "" && count == 0) {
        arr[2]->setText(compVal);
        arr[2]->setEnabled(false);
        count++;
        qDebug() << "12";
    }
    // X
    // -
    // X
    if (a0 == compVal && a6 == compVal && a3 == "" && count == 0) {
        arr[3]->setText(compVal);
        arr[3]->setEnabled(false);
        count++;
        qDebug() << "13";
    }
    else if (a1 == compVal && a7 == compVal && a4 == "" && count == 0) {
        arr[4]->setText(compVal);
        arr[4]->setEnabled(false);
        count++;
        qDebug() << "14";
    }
    else if (a2 == compVal && a8 == compVal && a5 == "" && count == 0) {
        arr[5]->setText(compVal);
        arr[5]->setEnabled(false);
        count++;
        qDebug() << "15";
    }
    // X
    // X
    // -
    if (a0 == compVal && a3 == compVal && a6 == "" && count == 0) {
        arr[6]->setText(compVal);
        arr[6]->setEnabled(false);
        count++;
        qDebug() << "16";
    }
    else if (a1 == compVal && a4 == compVal && a7 == "" && count == 0) {
        arr[7]->setText(compVal);
        arr[7]->setEnabled(false);
        count++;
        qDebug() << "17";
    }
    else if (a2 == compVal && a5 == compVal && a8 == "" && count == 0) {
        arr[8]->setText(compVal);
        arr[8]->setEnabled(false);
        count++;
        qDebug() << "18";
    }

    // ДИАГОНАЛИ
    if (a0 == compVal && a4 == compVal && a8 == "" && count == 0) {
        arr[8]->setText(compVal);
        arr[8]->setEnabled(false);
        count++;
        qDebug() << "19";
    }
    else if (a2 == compVal && a4 == compVal && a6 == "" && count == 0) {
        arr[6]->setText(compVal);
        arr[6]->setEnabled(false);
        count++;
        qDebug() << "20";
    }
    else if (a6 == compVal && a4 == compVal && a2 == "" && count == 0) {
        arr[2]->setText(compVal);
        arr[2]->setEnabled(false);
        count++;
        qDebug() << "21";
    }
    else if (a8 == compVal && a4 == compVal && a0 == "" && count == 0) {
        arr[0]->setText(compVal);
        arr[0]->setEnabled(false);
        count++;
        qDebug() << "22";
    }

    //.............. 2 правило
    // ГОРИЗОНТАЛИ
    if (a0 == playerVal && a1 == playerVal && a2 == "" && count == 0) {
        arr[2]->setText(compVal);
        arr[2]->setEnabled(false);
        count++;
        qDebug() << "23";
    }
    else if (a3 == playerVal && a4 == playerVal && a5 == "" && count == 0) {
        arr[5]->setText(compVal);
        arr[5]->setEnabled(false);
        count++;
        qDebug() << "24";
    }
    else if (a6 == playerVal && a7 == playerVal && a8 == "" && count == 0) {
        arr[8]->setText(compVal);
        arr[8]->setEnabled(false);
        count++;
        qDebug() << "25";
    }
    // X - X
    if (a0 == playerVal && a2 == playerVal && a1 == "" && count == 0) {
        arr[1]->setText(compVal);
        arr[1]->setEnabled(false);
        count++;
        qDebug() << "26";
    }
    else if (a3 == playerVal && a5 == playerVal && a4 == "" && count == 0) {
        arr[4]->setText(compVal);
        arr[4]->setEnabled(false);
        count++;
        qDebug() << "27";
    }
    else if (a6 == playerVal && a8 == playerVal && a7 == "" && count == 0) {
        arr[7]->setText(compVal);
        arr[7]->setEnabled(false);
        count++;
        qDebug() << "28";
    }
    // - X X
    if (a1 == playerVal && a2 == playerVal && a0 == "" && count == 0) {
        arr[0]->setText(compVal);
        arr[0]->setEnabled(false);
        count++;
        qDebug() << "29";
    }
    else if (a4 == playerVal && a5 == playerVal && a3 == "" && count == 0) {
        arr[3]->setText(compVal);
        arr[3]->setEnabled(false);
        count++;
        qDebug() << "30";
    }
    else if (a7 == playerVal && a8 == playerVal && a6 == "" && count == 0) {
        arr[6]->setText(compVal);
        arr[6]->setEnabled(false);
        count++;
        qDebug() << "31";
    }

    // ВЕРТИКАЛИ
    // -
    // X
    // X
    if (a3 == playerVal && a6 == playerVal && a0 == "" && count == 0) {
        arr[0]->setText(compVal);
        arr[0]->setEnabled(false);
        count++;
        qDebug() << "32";
    }
    else if (a4 == playerVal && a7 == playerVal && a1 == "" && count == 0) {
        arr[1]->setText(compVal);
        arr[1]->setEnabled(false);
        count++;
        qDebug() << "33";
    }
    else if (a5 == playerVal && a8 == playerVal && a2 == "" && count == 0) {
        arr[2]->setText(compVal);
        arr[2]->setEnabled(false);
        count++;
        qDebug() << "34";
    }
    // X
    // -
    // X
    if (a0 == playerVal && a6 == playerVal && a3 == "" && count == 0) {
        arr[3]->setText(compVal);
        arr[3]->setEnabled(false);
        count++;
        qDebug() << "35";
    }
    else if (a1 == playerVal && a7 == playerVal && a4 == "" && count == 0) {
        arr[4]->setText(compVal);
        arr[4]->setEnabled(false);
        count++;
        qDebug() << "36";
    }
    else if (a2 == playerVal && a8 == playerVal && a5 == "" && count == 0) {
        arr[5]->setText(compVal);
        arr[5]->setEnabled(false);
        count++;
        qDebug() << "37";
    }
    // X
    // X
    // -
    if (a0 == playerVal && a3 == playerVal && a6 == "" && count == 0) {
        arr[6]->setText(compVal);
        arr[6]->setEnabled(false);
        count++;
        qDebug() << "38";
    }
    else if (a1 == playerVal && a4 == playerVal && a7 == "" && count == 0) {
        arr[7]->setText(compVal);
        arr[7]->setEnabled(false);
        count++;
        qDebug() << "39";
    }
    else if (a2 == playerVal && a5 == playerVal && a8 == "" && count == 0) {
        arr[8]->setText(compVal);
        arr[8]->setEnabled(false);
        count++;
        qDebug() << "40";
    }

    // ДИАГОНАЛИ
    if (a0 == playerVal && a4 == playerVal && a8 == "" && count == 0) {
        arr[8]->setText(compVal);
        arr[8]->setEnabled(false);
        count++;
        qDebug() << "41";
    }
    else if (a2 == playerVal && a4 == playerVal && a6 == "" && count == 0) {
        arr[6]->setText(compVal);
        arr[6]->setEnabled(false);
        count++;
        qDebug() << "42";
    }
    else if (a6 == playerVal && a4 == playerVal && a2 == "" && count == 0) {
        arr[2]->setText(compVal);
        arr[2]->setEnabled(false);
        count++;
        qDebug() << "43";
    }
    else if (a8 == playerVal && a4 == playerVal && a0 == "" && count == 0) {
        arr[0]->setText(compVal);
        arr[0]->setEnabled(false);
        count++;
        qDebug() << "44";
    }

    // ОТДЕЛЬНО ОТ ПРАВИЛ
    // ЦЕНТР
    if (a4 == "" && count == 0) {
        arr[4]->setText(compVal);
        arr[4]->setEnabled(false);
        count++;
        qDebug() << "45";
    }
    else if (a4 != "" && count == 0) {
        s = dis(gen);
        if ((s == 0 || s == 1 || s == 2 || s == 3) && a0 == "") {
            arr[0]->setText(compVal);
            arr[0]->setEnabled(false);
            count++;
            qDebug() << "46";
        }
        else if ((s == 0 || s == 1 || s == 2 || s == 3) && a2 == "") {
            arr[2]->setText(compVal);
            arr[2]->setEnabled(false);
            count++;
            qDebug() << "47";
        }
        else if ((s == 0 || s == 1 || s == 2 || s == 3) && a6 == "") {
            arr[6]->setText(compVal);
            arr[6]->setEnabled(false);
            count++;
            qDebug() << "48";
        }
        else if ((s == 0 || s == 1 || s == 2 || s == 3) && a8 == "") {
            arr[8]->setText(compVal);
            arr[8]->setEnabled(false);
            count++;
            qDebug() << "49";
        }
    }

    // если не подходит ни один случай,
    // нужно вставлять в первую попавшуюся пустую ячейку
    for (int i = 0; i < 9; i++) {
        if (arr[i]->text() == "" && count == 0) {
            arr[i]->setText(compVal);
            arr[i]->setEnabled(false);
            count++;
            qDebug() << "50";
        }
    }

    int checks = 0;
    // если игрок ходит первым
    if (gameMode == 0){
        if (currentPlayer == 2 && checks == 0) {
            // ХОД COMPUTER
            qDebug() << "3";
            ui->state_of_game->setText("Ход игрока - " + ui->name_player_first->text());
            checks++;
            currentPlayer = 1;
            checkWinOrDraw(compName);
        }
    }
    // если Computer ходит первым
    if (gameMode == 1) {
        if (currentPlayer == 1 && checks == 0) {
            // ХОД COMPUTER
            qDebug() << "4";
            ui->state_of_game->setText("Ход игрока - " + ui->name_player_first->text());
            checks++;
            currentPlayer = 2;
            checkWinOrDraw(compName);
        }
    }
}

bool window_pvc::checkWinOrDraw(QString s) {
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

void window_pvc::pushButton_1_clicked()
{
    // ui->pushButton->setText("X");
}

void window_pvc::pushButton_2_clicked()
{
    // ui->pushButton_2->setText("X");
}

void window_pvc::pushButton_3_clicked()
{
    // ui->pushButton_3->setText("X");
}

void window_pvc::pushButton_4_clicked()
{
    // ui->pushButton_4->setText("X");
}

void window_pvc::pushButton_5_clicked()
{
    // ui->pushButton_5->setText("X");
}

void window_pvc::pushButton_6_clicked()
{
    // ui->pushButton_6->setText("X");
}

void window_pvc::pushButton_7_clicked()
{
    // ui->pushButton_7->setText("X");
}

void window_pvc::pushButton_8_clicked()
{
    // ui->pushButton_8->setText("X");
}

void window_pvc::pushButton_9_clicked()
{
    // ui->pushButton_9->setText("X");
}

