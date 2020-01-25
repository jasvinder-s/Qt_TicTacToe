/********************************************************************************
** Form generated from reading UI file 'tictactoe.ui'
**
** Created: Tue 11. May 21:26:03 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TICTACTOE_H
#define UI_TICTACTOE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGraphicsView>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TicTacToe
{
public:
    QGraphicsView *graphicsView;
    QLabel *label;
    QLCDNumber *lcdNumber;
    QLabel *label_2;
    QLCDNumber *lcdNumber_2;
    QPushButton *pushButtonQuit;
    QPushButton *pushButtonNewGame;

    void setupUi(QWidget *TicTacToe)
    {
        if (TicTacToe->objectName().isEmpty())
            TicTacToe->setObjectName(QString::fromUtf8("TicTacToe"));
        TicTacToe->resize(643, 480);
        graphicsView = new QGraphicsView(TicTacToe);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(180, 30, 291, 192));
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        label = new QLabel(TicTacToe);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 280, 81, 31));
        lcdNumber = new QLCDNumber(TicTacToe);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(0, 320, 101, 41));
        lcdNumber->setLayoutDirection(Qt::RightToLeft);
        lcdNumber->setFrameShadow(QFrame::Sunken);
        lcdNumber->setLineWidth(0);
        lcdNumber->setSmallDecimalPoint(false);
        label_2 = new QLabel(TicTacToe);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(180, 280, 81, 31));
        lcdNumber_2 = new QLCDNumber(TicTacToe);
        lcdNumber_2->setObjectName(QString::fromUtf8("lcdNumber_2"));
        lcdNumber_2->setGeometry(QRect(120, 320, 101, 41));
        lcdNumber_2->setLayoutDirection(Qt::RightToLeft);
        lcdNumber_2->setFrameShadow(QFrame::Sunken);
        lcdNumber_2->setLineWidth(0);
        lcdNumber_2->setSmallDecimalPoint(false);
        lcdNumber_2->setProperty("intValue", QVariant(0));
        pushButtonQuit = new QPushButton(TicTacToe);
        pushButtonQuit->setObjectName(QString::fromUtf8("pushButtonQuit"));
        pushButtonQuit->setGeometry(QRect(400, 310, 101, 51));
        QFont font;
        font.setPointSize(14);
        pushButtonQuit->setFont(font);
        pushButtonQuit->setAutoDefault(true);
        pushButtonQuit->setDefault(false);
        pushButtonQuit->setFlat(false);
        pushButtonNewGame = new QPushButton(TicTacToe);
        pushButtonNewGame->setObjectName(QString::fromUtf8("pushButtonNewGame"));
        pushButtonNewGame->setGeometry(QRect(280, 310, 101, 51));
        pushButtonNewGame->setFont(font);
        pushButtonNewGame->setAutoDefault(true);
        pushButtonNewGame->setDefault(false);
        pushButtonNewGame->setFlat(false);

        retranslateUi(TicTacToe);

        QMetaObject::connectSlotsByName(TicTacToe);
    } // setupUi

    void retranslateUi(QWidget *TicTacToe)
    {
        TicTacToe->setWindowTitle(QApplication::translate("TicTacToe", "TicTacToe", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("TicTacToe", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:600;\">Player 1</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("TicTacToe", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:600;\">Player 2</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        pushButtonQuit->setText(QApplication::translate("TicTacToe", "Quit", 0, QApplication::UnicodeUTF8));
        pushButtonNewGame->setText(QApplication::translate("TicTacToe", "New Game", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TicTacToe: public Ui_TicTacToe {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TICTACTOE_H
