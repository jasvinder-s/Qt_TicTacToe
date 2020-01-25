#include <QtGui/QApplication>
#include "tictactoe.h"
#include "testgui.h"

int main(int argc, char *argv[])
{
    #define APP_TEST
    QApplication a(argc, argv);
    TicTacToe w;
#if defined(Q_WS_S60)
    w.showMaximized();
#else
    w.show();
#endif

    TestGui* test;
    test = new TestGui();

    #ifndef APP_TEST
     return a.exec();
    #else
        QTest::qExec(test);
    #endif
}
