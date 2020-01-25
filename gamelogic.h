#ifndef GAMELOGIC_H
#define GAMELOGIC_H

class GameLogic
{
public:
    GameLogic();
    // check for win horizontally
    bool checkHorizontally(int symbol);
    // check for win vertically
    bool checkVertically(int symbol);
    // check for win in cross direction
    bool checkCross(int symbol);
    // set symbols in array
    void setSymbol(int index, int symbol);

    int* getSymbols();
    int arraySize();

    friend class TestGui;
private:
    // array containing symbols
    int *symbols;
    int ARRAY_SIZE;

};

#endif // GAMELOGIC_H
