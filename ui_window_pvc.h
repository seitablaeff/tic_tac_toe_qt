/********************************************************************************
** Form generated from reading UI file 'window_pvc.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_PVC_H
#define UI_WINDOW_PVC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_window_pvc
{
public:
    QVBoxLayout *verticalLayout_2;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_2;
    QGridLayout *pole;
    QPushButton *pushButton_9;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_6;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QVBoxLayout *verticalLayout;
    QPushButton *begin;
    QLabel *label_2;
    QLineEdit *name_player_first;
    QPushButton *submit;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout;
    QRadioButton *choise_first;
    QRadioButton *choise_second;
    QLabel *state_of_game;

    void setupUi(QDialog *window_pvc)
    {
        if (window_pvc->objectName().isEmpty())
            window_pvc->setObjectName("window_pvc");
        window_pvc->resize(836, 479);
        window_pvc->setMinimumSize(QSize(791, 479));
        verticalLayout_2 = new QVBoxLayout(window_pvc);
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_5 = new QLabel(window_pvc);
        label_5->setObjectName("label_5");
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        font.setKerning(true);
        label_5->setFont(font);

        verticalLayout_2->addWidget(label_5);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        pole = new QGridLayout();
        pole->setObjectName("pole");
        pushButton_9 = new QPushButton(window_pvc);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setEnabled(false);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_9->sizePolicy().hasHeightForWidth());
        pushButton_9->setSizePolicy(sizePolicy);

        pole->addWidget(pushButton_9, 2, 2, 1, 1);

        pushButton = new QPushButton(window_pvc);
        pushButton->setObjectName("pushButton");
        pushButton->setEnabled(false);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);

        pole->addWidget(pushButton, 0, 0, 1, 1);

        pushButton_2 = new QPushButton(window_pvc);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setEnabled(false);
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);

        pole->addWidget(pushButton_2, 0, 1, 1, 1);

        pushButton_3 = new QPushButton(window_pvc);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setEnabled(false);
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);

        pole->addWidget(pushButton_3, 0, 2, 1, 1);

        pushButton_6 = new QPushButton(window_pvc);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setEnabled(false);
        sizePolicy.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy);

        pole->addWidget(pushButton_6, 1, 2, 1, 1);

        pushButton_4 = new QPushButton(window_pvc);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setEnabled(false);
        sizePolicy.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy);

        pole->addWidget(pushButton_4, 1, 0, 1, 1);

        pushButton_5 = new QPushButton(window_pvc);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setEnabled(false);
        sizePolicy.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy);

        pole->addWidget(pushButton_5, 1, 1, 1, 1);

        pushButton_7 = new QPushButton(window_pvc);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setEnabled(false);
        sizePolicy.setHeightForWidth(pushButton_7->sizePolicy().hasHeightForWidth());
        pushButton_7->setSizePolicy(sizePolicy);

        pole->addWidget(pushButton_7, 2, 0, 1, 1);

        pushButton_8 = new QPushButton(window_pvc);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setEnabled(false);
        sizePolicy.setHeightForWidth(pushButton_8->sizePolicy().hasHeightForWidth());
        pushButton_8->setSizePolicy(sizePolicy);

        pole->addWidget(pushButton_8, 2, 1, 1, 1);


        horizontalLayout_2->addLayout(pole);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        begin = new QPushButton(window_pvc);
        begin->setObjectName("begin");
        QFont font1;
        font1.setPointSize(13);
        begin->setFont(font1);

        verticalLayout->addWidget(begin);

        label_2 = new QLabel(window_pvc);
        label_2->setObjectName("label_2");
        QFont font2;
        font2.setPointSize(13);
        font2.setKerning(true);
        label_2->setFont(font2);

        verticalLayout->addWidget(label_2);

        name_player_first = new QLineEdit(window_pvc);
        name_player_first->setObjectName("name_player_first");

        verticalLayout->addWidget(name_player_first);

        submit = new QPushButton(window_pvc);
        submit->setObjectName("submit");
        QFont font3;
        font3.setPointSize(14);
        submit->setFont(font3);

        verticalLayout->addWidget(submit);

        label_4 = new QLabel(window_pvc);
        label_4->setObjectName("label_4");
        label_4->setFont(font2);

        verticalLayout->addWidget(label_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName("horizontalLayout");
        choise_first = new QRadioButton(window_pvc);
        choise_first->setObjectName("choise_first");
        choise_first->setFont(font1);

        horizontalLayout->addWidget(choise_first);

        choise_second = new QRadioButton(window_pvc);
        choise_second->setObjectName("choise_second");
        choise_second->setFont(font1);

        horizontalLayout->addWidget(choise_second);


        verticalLayout->addLayout(horizontalLayout);

        state_of_game = new QLabel(window_pvc);
        state_of_game->setObjectName("state_of_game");
        state_of_game->setFont(font1);

        verticalLayout->addWidget(state_of_game);


        horizontalLayout_2->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout_2);


        retranslateUi(window_pvc);

        QMetaObject::connectSlotsByName(window_pvc);
    } // setupUi

    void retranslateUi(QDialog *window_pvc)
    {
        window_pvc->setWindowTitle(QCoreApplication::translate("window_pvc", "Dialog", nullptr));
        label_5->setText(QCoreApplication::translate("window_pvc", "<html><head/><body><p align=\"center\">\320\230\320\263\321\200\320\276\320\272 vs Computer</p></body></html>", nullptr));
        pushButton_9->setText(QString());
        pushButton->setText(QString());
        pushButton_2->setText(QString());
        pushButton_3->setText(QString());
        pushButton_6->setText(QString());
        pushButton_4->setText(QString());
        pushButton_5->setText(QString());
        pushButton_7->setText(QString());
        pushButton_8->setText(QString());
        begin->setText(QCoreApplication::translate("window_pvc", "\320\235\320\260\321\207\320\260\321\202\321\214 \320\270\320\263\321\200\321\203!", nullptr));
        label_2->setText(QCoreApplication::translate("window_pvc", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\201\320\262\320\276\321\221 \320\270\320\274\321\217", nullptr));
        submit->setText(QCoreApplication::translate("window_pvc", "\320\237\320\276\320\264\321\202\320\262\320\265\321\200\320\264\320\270\321\202\321\214 \321\205\320\276\320\264 \320\272\320\276\320\274\320\277\321\214\321\216\321\202\320\265\321\200\320\260", nullptr));
        label_4->setText(QCoreApplication::translate("window_pvc", "\320\232\321\202\320\276 \321\205\320\276\320\264\320\270\321\202 \320\277\320\265\321\200\320\262\321\213\320\274?", nullptr));
        choise_first->setText(QCoreApplication::translate("window_pvc", "\320\230\320\263\321\200\320\276\320\272", nullptr));
        choise_second->setText(QCoreApplication::translate("window_pvc", "Computer", nullptr));
        state_of_game->setText(QCoreApplication::translate("window_pvc", "\320\227\320\264\320\265\321\201\321\214 \320\276\321\202\320\276\320\261\321\200\320\260\320\266\320\260\320\265\321\202\321\201\321\217 \321\201\320\276\321\201\321\202\320\276\321\217\320\275\320\270\320\265 \320\270\320\263\321\200\321\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class window_pvc: public Ui_window_pvc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_PVC_H
