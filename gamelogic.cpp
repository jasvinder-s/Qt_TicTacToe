#include "gamelogic.h"

GameLogic::GameLogic()
{

    symbols = new int[10];
    ARRAY_SIZE = 9;
    for(int i = 0; i < ARRAY_SIZE; i++) {
        symbols[i] = -1;
    }
}

bool GameLogic::checkHorizontally(int symbol) {

    int checkingIndex = 0;
    for(int i = 0; i <= 3; i++) {
        if(symbols[checkingIndex] == symbol && symbols[checkingIndex+1] == symbol
           && symbols[checkingIndex+2] == symbol)
            return true;
        checkingIndex+=3;
    }
    return false;
}


bool GameLogic::checkVertically(int symbol) {

    int checkingIndex = 0;
    for(int i = 0; i <= 2; i++){
        if(symbols[checkingIndex] == symbol && symbols[checkingIndex+3] == symbol
           && symbols[checkingIndex+6] == symbol)
            return true;
        checkingIndex++;
    }
    return false;
}

bool GameLogic::checkCross(int symbol) {

    int checkingIndex = 0;
    if(symbols[checkingIndex] == symbol && symbols[checkingIndex+4] == symbol
       && symbols[checkingIndex + 8] == symbol){
        return true;
    }
    checkingIndex += 2;
    if (symbols[checkingIndex] == symbol && symbols[checkingIndex+2] == symbol
       && symbols[checkingIndex + 4] == symbol){
       return true;
    }
    return false;
}

int* GameLogic::getSymbols() {
    return symbols;
}

void GameLogic::setSymbol(int index, int symbol) {
    symbols[index] = symbol;
}

int GameLogic::arraySize() {
    return this->ARRAY_SIZE;
}
