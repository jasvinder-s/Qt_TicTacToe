#include "tictactoescene.h"
#include <QDebug>

TicTacToeScene::TicTacToeScene(QGraphicsScene* parent)
    :QGraphicsScene(parent)
{
}

void TicTacToeScene::mousePressEvent( QGraphicsSceneMouseEvent *mouseEvent ){
   qDebug() << "QGraphicsSceneMouseEvent";
   QPointF position = mouseEvent->buttonDownScenePos(Qt::LeftButton);
   mouseX = position.rx();
   mouseY = position.ry();
   qDebug() << position.rx();
   qDebug() << position.ry();
}

int TicTacToeScene::getX() {
    return mouseX;
}

int TicTacToeScene::getY() {
    return mouseY;
}
