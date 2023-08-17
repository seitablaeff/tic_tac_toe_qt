#ifndef WINDOW_PVC_H
#define WINDOW_PVC_H

#include <QDialog>
#include <QSignalMapper>

using namespace std;

namespace Ui {
class window_pvc;
}

class window_pvc : public QDialog
{
    Q_OBJECT

public:
    explicit window_pvc(QWidget *parent = nullptr);
    ~window_pvc();

    // ход компьютера
    void CompMove();

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

    void on_submit_clicked();

private:
    Ui::window_pvc *ui;
    QSignalMapper *signalMapper;
    QPushButton *arr[9];
    int gameMode;
    int currentPlayer;
    QString playerVal;
    QString compName = "Computer";
};

#endif // WINDOW_PVC_H
