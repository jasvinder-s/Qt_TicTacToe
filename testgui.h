#ifndef TESTGUI_H
#define TESTGUI_H

#include <QtGui>
#include <QtTest/QtTest>
#include "tictactoe.h"

 class TestGui: public QObject
 {
     Q_OBJECT
 public:
     TestGui();      

 private slots:
     // Test Case 1
     void player1Win_data();
     void player1Win();

     // Test Case 2
     void player1ScoreUpdated();

     // Test Case 3
     void player2Win_data();
     void player2Win();

     // Test Case 4
     void player2ScoreUpdated();


 private:

    TicTacToe* tic;

 };


#endif // TESTGUI_H
