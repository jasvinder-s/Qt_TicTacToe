#ifndef TICTACTOESCENE_H
#define TICTACTOESCENE_H
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>
class TicTacToeScene: public QGraphicsScene
{
public:
    TicTacToeScene(QGraphicsScene* parent = 0);
    int getX();
    int getY();
private:
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);

    int mouseX;
    int mouseY;


};

#endif // TICTACTOESCENE_H
