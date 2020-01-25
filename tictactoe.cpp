#include "tictactoe.h"
#include <QDebug>
#include <QMouseEvent>
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>
#include <QMessageBox>
#include <QAbstractButton>
#include "gamelogic.h" 

//#include "ui_tictactoe.h"


TicTacToe::TicTacToe(QWidget *parent) :
    QWidget(parent)
{
    qDebug() << "Constructor";
    setupUi(this);

    scene = new TicTacToeScene();
    scene->setSceneRect(QRectF(0, 0, 291,192));

    SCENE_HEIGHT = scene->height();
    SCENE_WIDTH = scene->width();

    qreal height = scene->height();
    qreal width = scene->width();
    QPen pen = QPen(Qt::SolidLine);
    pen.setWidth(2);

    for(int i = 1; i <= 2; i++) {
        //draw horizontal line
        scene->addLine(qreal(0), height*i/3, width, height*i/3,pen);
        // vertical line
        scene->addLine(width*i/3, qreal(0), width*i/3, height,pen);
    }

    graphicsView->setScene(scene);
    lastTimeCrossMarked = false;

    gameLogic = new GameLogic();
    clickCount = 0;

    player1Score = 0;
    player2Score = 0;

    // position of view in widget

    VIEW_START_X = 180;

    VIEW_START_Y = 30;

    VIEW_WIDTH = 291;

    VIEW_HEIGHT = 192;

    symbol = -1;

    QObject::connect(this, SIGNAL(gameWon(int)),
                          this, SLOT(showWinMessage(int)));

    msgBox = new QMessageBox(this);

    QObject::connect(pushButtonNewGame,SIGNAL(clicked()),
            this, SLOT(startNewGame()));

    QObject::connect(pushButtonQuit,SIGNAL(pressed()),
            this, SLOT(clearSymbols()));

    qDebug("*************Exiting Constructor**************");
}

TicTacToe::~TicTacToe()
{
    //delete ui;
}

void TicTacToe::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        retranslateUi(this);
        break;

    default:
        qDebug() << "Default event: " << e->type();
        break;
    }
}


void TicTacToe::mousePressEvent(QMouseEvent *e)
 {     


    qDebug() << "TicTacToe#mousePressEvent: eventType" << e->type();
    qDebug() << "TicTacToe#mousePressEvent: x" << e->x();
    qDebug() << "TicTacToe#mousePressEvent: y" << e->y();

    if(e->x() >= VIEW_START_X && e->x() <= VIEW_START_X + VIEW_WIDTH) {
        if(e->y() >= VIEW_START_Y && e->y() <= VIEW_START_Y + VIEW_HEIGHT) {
            // mouse press ocurred inside scene, get x, y coordinate according
            // to scene
            //int sceneClickX = scene->getX();
            //int sceneClickY = scene->getY();
            //drawSymbol(sceneClickX, sceneClickY);
            drawSymbol(e->x() - this->VIEW_START_X, e->y() - this->VIEW_START_Y);
        }
    }
 }

void TicTacToe::drawSymbol(int x, int y) {
    qDebug() <<"TicTacToe::drawSymbol x: " << x << "y: " << y;
    clickCount++;
    int drawingX;
    int drawingY;

    if( x >= 0 && x <= SCENE_WIDTH/3 ) {
        drawingX = SCENE_WIDTH/3/2;
        if(y >= 0 && y <= SCENE_HEIGHT/3) {
            drawingY = SCENE_HEIGHT/3/2;
            index = 0;
        } else if (y > SCENE_HEIGHT/3 && y <= SCENE_HEIGHT*2/3){
            drawingY = SCENE_HEIGHT/2;
            index = 3;
        } else if( y > SCENE_HEIGHT*2/3 && y <= SCENE_HEIGHT) {
            drawingY = SCENE_HEIGHT*5/6;
            index = 6;
        }
    } else if ( x >= SCENE_WIDTH/3 && x <= SCENE_WIDTH*2/3 ) {
        drawingX = SCENE_WIDTH/2;
        if(y >= 0 && y <= SCENE_HEIGHT/3) {
            drawingY = SCENE_HEIGHT/3/2;
            index = 1;
        } else if (y > SCENE_HEIGHT/3 && y <= SCENE_HEIGHT*2/3){
            drawingY = SCENE_HEIGHT/2;
            index = 4;
        } else if( y > SCENE_HEIGHT*2/3 && y <= SCENE_HEIGHT) {
            drawingY = SCENE_HEIGHT*5/6;
            index = 7;
        }

    } else {
        drawingX = SCENE_WIDTH*5/6;
        if(y >= 0 && y <= SCENE_HEIGHT/3) {
            drawingY = SCENE_HEIGHT/3/2;
            index = 2;
        } else if (y > SCENE_HEIGHT/3 && y <= SCENE_HEIGHT*2/3){
            drawingY = SCENE_HEIGHT/2;
            index = 5;
        } else if( y > SCENE_HEIGHT*2/3 && y <= SCENE_HEIGHT) {
            drawingY = SCENE_HEIGHT*5/6;
            index = 8;
        }

    }

    if(!lastTimeCrossMarked) {
        int symbol = 1;
        this->symbol = symbol;
        qDebug() << "TicTacToe::drawSymbol symbol: " << symbol;
        QGraphicsLineItem *line1 = new QGraphicsLineItem(qreal(drawingX-20),
                            qreal(drawingY-10), drawingX+20, drawingY+20, 0);

        QGraphicsLineItem *line2 = new QGraphicsLineItem(qreal(drawingX+20),
                            qreal(drawingY-10), drawingX-20, drawingY+20, 0);
        scene->addItem(line1);
        listOfAllItems.append(line1);


        scene->addItem(line2);
        listOfAllItems.append(line2);

        lastTimeCrossMarked = true;

        fillArray(index, symbol);
        if(clickCount >= 5) {
            bool win = checkForWin(symbol);
            //player 1 win, display some widget
            qDebug() << "TicTacToe::drawSymbol win: " << win;
            if(win)
                emit gameWon(symbol);
        }

    } else {
        int symbol = 0;
        this->symbol = symbol;
        qDebug() << "TicTacToe::drawSymbol symbol: " << symbol;
        QGraphicsEllipseItem *ellipse = new QGraphicsEllipseItem(qreal(drawingX-20),
                            qreal(drawingY-20), 45, 45, 0);
        scene->addItem(ellipse);
        listOfAllItems.append(ellipse);
        lastTimeCrossMarked = false;
        fillArray(index, symbol);
        if(clickCount >= 5) {
            bool win = checkForWin(symbol);
            qDebug() << "TicTacToe::drawSymbol win: " << win;
            if(win)
                emit gameWon(symbol);
        }

    }

    qDebug() <<"TicTacToe::drawSymbol x: " << drawingX << "y: " << drawingY;
    qDebug() << "TicTacToe::drawSymbol index: " << index << "**************";



}

void TicTacToe::fillArray(int index, int symbol) {
    gameLogic->getSymbols()[index] = symbol;

    for(int i = 0; i < gameLogic->arraySize(); i++) {
        qDebug() << gameLogic->getSymbols()[i];
    }
}

bool TicTacToe::checkForWin(int symbol) {
    //boolean win = false;
    if(gameLogic->checkHorizontally(symbol))
        return true;
    else if(gameLogic->checkVertically(symbol))
        return true;
    else
        return gameLogic->checkCross(symbol);
    return false;

}

void TicTacToe::showWinMessage(int playerWhoWin) {


    if(playerWhoWin)
        //qDebug() << "Player 1";
        msgBox->setText("Player 1 win");
    else
        //qDebug() << "Player 2";
        msgBox->setText("Player 2 win");

    // Commented out here as it is giving some problme in testing,,
    // Event related problem.
    //msgBox->exec();
    updateScore(playerWhoWin);
}

void TicTacToe::updateScore(int PlayerWhoWin) {
    qDebug() << "TicTacToe::updateScore";


    if(PlayerWhoWin) {
        player1Score++;
        lcdNumber->display((int)player1Score);
    }
    else{
        player2Score++;
        lcdNumber_2->display((int)player2Score);
    }

    // clear symbols from the scene
    clearSymbols();
    clearArray();
}

void TicTacToe::startNewGame() {
    clearSymbols();
    clearArray();
}

void TicTacToe::clearSymbols() {
    qDebug() << "TicTacToe::clearSymbols";
    for(int i = 0; i < listOfAllItems.length(); i++) {
        scene->removeItem(listOfAllItems.at(i));
    }
    listOfAllItems.clear();
    lastTimeCrossMarked = false;
}

void TicTacToe::clearArray() {
    qDebug() << "TicTacToe::clearArray";
    for(int i = 0; i < gameLogic->arraySize(); i++) {
        gameLogic->setSymbol(i, -1);
    }
}
