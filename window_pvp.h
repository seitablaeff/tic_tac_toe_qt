#ifndef WINDOW_PVP_H
#define WINDOW_PVP_H

#include <QDialog>
#include <QSignalMapper>
#include <QString>
#include <QPushButton>

using namespace std;

namespace Ui {
class window_PvP;
}

class window_PvP : public QDialog
{
    Q_OBJECT

public:
    explicit window_PvP(QWidget *parent = nullptr);
    ~window_PvP();

private slots:
    // начало игры
    void begin_clicked();

    // одна из 9 кнопок нажата
    void pushButtonsClicked();

    // проверка победы или ничьи
    bool checkWinOrDraw(QString s);

    void pushButton_1_clicked();

    void pushButton_2_clicked();

    void pushButton_3_clicked();

    void pushButton_4_clicked();

    void pushButton_5_clicked();

    void pushButton_6_clicked();

    void pushButton_7_clicked();

    void pushButton_8_clicked();

    void pushButton_9_clicked();

private:
    Ui::window_PvP *ui;
    QSignalMapper *signalMapper;
    QPushButton *arr[9];
    int currentPlayer;
    int gameMode;
};

#endif // WINDOW_PVP_H
