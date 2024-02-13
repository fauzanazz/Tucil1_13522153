/********************************************************************************
** Form generated from reading UI file 'gamestart.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMESTART_H
#define UI_GAMESTART_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameStart
{
public:
    QPushButton *Solve;
    QLabel *Time_;
    QPushButton *LoadFromFile;
    QWidget *MatrixWidget;
    QTableWidget *Matrix_2;
    QWidget *BufferWidget;
    QTableWidget *tableWidget;
    QPushButton *GenerateRandom;
    QWidget *Sequence;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_2;
    QWidget *widget_7;
    QLabel *Sequence3_2;
    QTableWidget *Seq3Table_2;
    QWidget *widget_5;
    QLabel *Sequence1_2;
    QTableWidget *Seq1Table_2;
    QWidget *widget_6;
    QLabel *Sequence2_2;
    QTableWidget *Seq2Table_2;
    QLabel *TimeRemainingLabel;
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QDialog *GameStart)
    {
        if (GameStart->objectName().isEmpty())
            GameStart->setObjectName("GameStart");
        GameStart->resize(1280, 720);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(GameStart->sizePolicy().hasHeightForWidth());
        GameStart->setSizePolicy(sizePolicy);
        Solve = new QPushButton(GameStart);
        Solve->setObjectName("Solve");
        Solve->setGeometry(QRect(550, 530, 141, 24));
        Time_ = new QLabel(GameStart);
        Time_->setObjectName("Time_");
        Time_->setGeometry(QRect(460, 145, 49, 21));
        LoadFromFile = new QPushButton(GameStart);
        LoadFromFile->setObjectName("LoadFromFile");
        LoadFromFile->setGeometry(QRect(550, 490, 141, 24));
        MatrixWidget = new QWidget(GameStart);
        MatrixWidget->setObjectName("MatrixWidget");
        MatrixWidget->setGeometry(QRect(110, 200, 421, 421));
        Matrix_2 = new QTableWidget(MatrixWidget);
        Matrix_2->setObjectName("Matrix_2");
        Matrix_2->setGeometry(QRect(0, 0, 421, 421));
        BufferWidget = new QWidget(GameStart);
        BufferWidget->setObjectName("BufferWidget");
        BufferWidget->setGeometry(QRect(549, 129, 611, 51));
        tableWidget = new QTableWidget(BufferWidget);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(-5, 1, 621, 51));
        GenerateRandom = new QPushButton(GameStart);
        GenerateRandom->setObjectName("GenerateRandom");
        GenerateRandom->setGeometry(QRect(550, 450, 141, 24));
        Sequence = new QWidget(GameStart);
        Sequence->setObjectName("Sequence");
        Sequence->setGeometry(QRect(550, 200, 611, 221));
        scrollArea = new QScrollArea(Sequence);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(-1, -1, 611, 221));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName("scrollAreaWidgetContents_2");
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 609, 219));
        widget_7 = new QWidget(scrollAreaWidgetContents_2);
        widget_7->setObjectName("widget_7");
        widget_7->setGeometry(QRect(0, 140, 611, 80));
        Sequence3_2 = new QLabel(widget_7);
        Sequence3_2->setObjectName("Sequence3_2");
        Sequence3_2->setGeometry(QRect(340, 30, 49, 16));
        Seq3Table_2 = new QTableWidget(widget_7);
        Seq3Table_2->setObjectName("Seq3Table_2");
        Seq3Table_2->setGeometry(QRect(0, 0, 311, 81));
        widget_5 = new QWidget(scrollAreaWidgetContents_2);
        widget_5->setObjectName("widget_5");
        widget_5->setGeometry(QRect(0, 0, 611, 71));
        Sequence1_2 = new QLabel(widget_5);
        Sequence1_2->setObjectName("Sequence1_2");
        Sequence1_2->setGeometry(QRect(340, 30, 49, 16));
        Seq1Table_2 = new QTableWidget(widget_5);
        Seq1Table_2->setObjectName("Seq1Table_2");
        Seq1Table_2->setGeometry(QRect(0, 0, 311, 71));
        widget_6 = new QWidget(scrollAreaWidgetContents_2);
        widget_6->setObjectName("widget_6");
        widget_6->setGeometry(QRect(0, 70, 611, 71));
        Sequence2_2 = new QLabel(widget_6);
        Sequence2_2->setObjectName("Sequence2_2");
        Sequence2_2->setGeometry(QRect(340, 30, 49, 16));
        Seq2Table_2 = new QTableWidget(widget_6);
        Seq2Table_2->setObjectName("Seq2Table_2");
        Seq2Table_2->setGeometry(QRect(0, 0, 311, 71));
        scrollArea->setWidget(scrollAreaWidgetContents_2);
        TimeRemainingLabel = new QLabel(GameStart);
        TimeRemainingLabel->setObjectName("TimeRemainingLabel");
        TimeRemainingLabel->setGeometry(QRect(120, 140, 181, 31));
        label = new QLabel(GameStart);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 1280, 720));
        label->setPixmap(QPixmap(QString::fromUtf8(":/Images/Main Menu.png")));
        pushButton = new QPushButton(GameStart);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(550, 570, 141, 29));
        label->raise();
        Time_->raise();
        TimeRemainingLabel->raise();
        BufferWidget->raise();
        MatrixWidget->raise();
        Sequence->raise();
        LoadFromFile->raise();
        GenerateRandom->raise();
        Solve->raise();
        pushButton->raise();

        retranslateUi(GameStart);

        QMetaObject::connectSlotsByName(GameStart);
    } // setupUi

    void retranslateUi(QDialog *GameStart)
    {
        GameStart->setWindowTitle(QCoreApplication::translate("GameStart", "Dialog", nullptr));
        Solve->setText(QCoreApplication::translate("GameStart", "BruteForce Solve", nullptr));
        Time_->setText(QCoreApplication::translate("GameStart", "<html><head/><body><p align=\"center\"><span style=\" color:#ffffff;\">Time</span></p></body></html>", nullptr));
        LoadFromFile->setText(QCoreApplication::translate("GameStart", "Load From File", nullptr));
        GenerateRandom->setText(QCoreApplication::translate("GameStart", "Generate Random", nullptr));
        Sequence3_2->setText(QCoreApplication::translate("GameStart", "<html><head/><body><p><span style=\" color:#ffffff;\">TextLabel</span></p></body></html>", nullptr));
        Sequence1_2->setText(QCoreApplication::translate("GameStart", "<html><head/><body><p><span style=\" color:#ffffff;\">TextLabel</span></p></body></html>", nullptr));
        Sequence2_2->setText(QCoreApplication::translate("GameStart", "<html><head/><body><p><span style=\" color:#ffffff;\">TextLabel</span></p></body></html>", nullptr));
        TimeRemainingLabel->setText(QCoreApplication::translate("GameStart", "<html><head/><body><p><span style=\" color:#ffffff;\">Breach Time Remaining</span></p></body></html>", nullptr));
        label->setText(QString());
        pushButton->setText(QCoreApplication::translate("GameStart", "Greedy Solve", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameStart: public Ui_GameStart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMESTART_H
