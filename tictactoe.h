#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <QWidget>
#include <QMessageBox>
#include "TicTacToeScene.h"
#include "gamelogic.h"
#include "ui_tictactoe.h"

namespace Ui {
    class TicTacToe;
}

class TicTacToe : public QWidget, public Ui::TicTacToe
{
    Q_OBJECT

public:
    explicit TicTacToe(QWidget *parent = 0);
    friend class TestGui;
    ~TicTacToe();

protected:
    void changeEvent(QEvent *e);
    void mousePressEvent(QMouseEvent *e);

private:
    void drawSymbol(int x, int y);
    void fillArray(int index, int symbol);
    bool checkForWin(int symbol);
    void clearArray();


public slots:
    void showWinMessage(int playerWhoWin);
    void updateScore(int playerWhoWin);
    void clearSymbols();
    void startNewGame();

signals:
    void gameWon(int playerWhoWin);


private:
    //Ui::TicTacToe *ui;
    TicTacToeScene *scene;
    int SCENE_WIDTH;
    int SCENE_HEIGHT;

    //int viewStartX = 180;
    int VIEW_START_X;
    //int viewStartY = 30;
    int VIEW_START_Y;
    //int viewWidth = 291;
    int VIEW_WIDTH;
    //int viewHeight = 192;
    int VIEW_HEIGHT;

    bool lastTimeCrossMarked;
    GameLogic* gameLogic;
    int index;
    // count of total amount of clicks on the scene
    int clickCount;

    int player1Score;
    int player2Score;

    QMessageBox* msgBox;

    QList<QGraphicsItem*> listOfAllItems;

    // Either 0 or 1, states whether 0 or X is marked last time, used only for testing purpose
    int symbol;
};

#endif // TICTACTOE_H
