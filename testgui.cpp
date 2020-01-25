#include "testgui.h"

TestGui::TestGui() {
      tic = new TicTacToe(0);
      qDebug("Exiting TestGui constructor");
}


void TestGui::player1Win_data() {
    QTest::addColumn<QTestEventList>("events");
    QTest::addColumn<int>("expected");

    QTestEventList list1;
    // click X ocurred inside 1st box
    QPoint clickPoint(tic->VIEW_START_X + 1, tic->VIEW_START_Y + 1);
    list1.addMousePress(Qt::LeftButton, 0,clickPoint, 0);
    QTest::newRow("index 0 value") << list1 << 1;

    QTestEventList list2;
    // click 0 occurs inside 2nd box
    clickPoint.setX(tic->VIEW_START_X + tic->VIEW_WIDTH/3 + 1);
    list2.addMousePress(Qt::LeftButton, 0,clickPoint, 0);
    QTest::newRow("index 1 value") << list2 << 0;

    //click X occurs inside 5th box
    QTestEventList list3;
    clickPoint.setY(tic->VIEW_START_Y + tic->VIEW_HEIGHT/3 + 1);
    list3.addMousePress(Qt::LeftButton, 0, clickPoint, 0);
    QTest::newRow("index 4 value") << list3 << 1;

    // click 0 occurs inside 3rd box
    QTestEventList list4;
    clickPoint.setX(tic->VIEW_START_X + tic->VIEW_WIDTH*2/3 + 1);
    clickPoint.setY(tic->VIEW_START_Y + 1);
    list4.addMousePress(Qt::LeftButton, 0, clickPoint, 0);
    QTest::newRow("index 2 value") << list4 << 0;

    // click X occurs inside last box i.e 9th box
    //Player 1 should win here
    QTestEventList list5;
    clickPoint.setX(tic->VIEW_START_X + tic->VIEW_WIDTH*2/3 + 1);
    clickPoint.setY(tic->VIEW_START_Y + tic->VIEW_HEIGHT*2/3 + 1);
    list5.addMousePress(Qt::LeftButton, 0, clickPoint, 0);
    QTest::newRow("index 8 value") << list5 << 1;


}


void TestGui::player1Win() {
    QFETCH(QTestEventList, events);
    QFETCH(int, expected);

    events.simulate(tic);
    QCOMPARE(tic->symbol, expected);
}


void TestGui::player1ScoreUpdated() {
    QVERIFY(tic->player1Score == 1);
}

void TestGui::player2Win_data() {

    QTest::addColumn<QTestEventList>("events");
    QTest::addColumn<int>("expected");


    QTestEventList list1;
    // click X occurs inside 2nd box
    QPoint clickPoint(tic->VIEW_START_X + tic->VIEW_WIDTH/3 + 1, tic->VIEW_START_Y + 1);
    list1.addMousePress(Qt::LeftButton, 0,clickPoint, 0);
    QTest::newRow("index 1 value") << list1 << 1;

    QTestEventList list2;
    // click 0 ocurred inside 1st box
    clickPoint.setX(tic->VIEW_START_X + 1);
    list2.addMousePress(Qt::LeftButton, 0,clickPoint, 0);
    QTest::newRow("index 0 value") << list2 << 0;

    // click X occurs inside 3rd box
    QTestEventList list3;
    clickPoint.setX(tic->VIEW_START_X + tic->VIEW_WIDTH*2/3 + 1);
    clickPoint.setY(tic->VIEW_START_Y + 1);
    list3.addMousePress(Qt::LeftButton, 0, clickPoint, 0);
    QTest::newRow("index 2 value") << list3 << 1;

    //click 0 occurs inside 5th box
    QTestEventList list4;
    clickPoint.setX(tic->VIEW_START_X + tic->VIEW_WIDTH/3 + 1);
    clickPoint.setY(tic->VIEW_START_Y + tic->VIEW_HEIGHT/3 + 1);
    list4.addMousePress(Qt::LeftButton, 0, clickPoint, 0);
    QTest::newRow("index 4 value") << list4 << 0;

    // click X occurs inside 6th box
    QTestEventList list5;
    clickPoint.setX(tic->VIEW_START_X + tic->VIEW_WIDTH*2/3 + 1);
    clickPoint.setY(tic->VIEW_START_Y + tic->VIEW_HEIGHT*1/3 + 1);
    list5.addMousePress(Qt::LeftButton, 0, clickPoint, 0);
    QTest::newRow("index 5 value") << list5 << 1;

    // click 0 occurs inside last box i.e 9th box
    //Player 2 should win here
    QTestEventList list6;
    clickPoint.setX(tic->VIEW_START_X + tic->VIEW_WIDTH*2/3 + 1);
    clickPoint.setY(tic->VIEW_START_Y + tic->VIEW_HEIGHT*2/3 + 1);
    list6.addMousePress(Qt::LeftButton, 0, clickPoint, 0);
    QTest::newRow("index 8 value") << list6 << 0;
}

void TestGui::player2Win() {
    QFETCH(QTestEventList, events);
    QFETCH(int, expected);

    events.simulate(tic);
    QCOMPARE(tic->symbol, expected);
}


void TestGui::player2ScoreUpdated() {
    QVERIFY(tic->player2Score == 1);
}
