#ifndef SNAKE_H
#define SNAKE_H

#include <QObject>
#include <QList>
#include <QQueue>
#include <QKeyEvent>
#include <QTime>
#include <QLabel>
#include <QPainter>

#include "snakepart.h"
#include "fruit.h"
#include "bomb.h"

class Snake : public QObject
{
    Q_OBJECT
private:
    QGraphicsScene *gameScene;
    QList<snakePart*> snake;
    QQueue<QString> directionThread;
    QTimer *motionTimer;
    QString direction;
    QGraphicsTextItem *currentScore;
    Fruit *fruit;
    bool flagPause = false;
    int msec = 100;
    int x, y, fruitX, fruitY;
    int r, g, b;
    int eatenFruit = 0;

public:
    Snake(QGraphicsScene *gameScene, QObject *parent);
    QString getDirection();
    void setDirectionThread(QString);
    void setFlagPause(bool);
    void newFruit();
    void directPos();
    void fruitCollision();
    void infoPanel();
    void keyInfo();
    void stopTimer();
    void startTimer(int);
    bool selfCollision();
    bool getFlagPause();
    int getScore();
    int getMsec();


private slots:
    void motion();

signals:
    void GameOver();
};

#endif // SNAKE_H
