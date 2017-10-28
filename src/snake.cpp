#include "snake.h"

Snake::Snake(QGraphicsScene *gameScene, QObject *parent) : QObject(parent)
{
    qsrand(QTime(0,0,0).msecsTo(QTime::currentTime()));
    this->gameScene = gameScene;
    direction = "UP";
    keyInfo();

    x = 100, y = 100;
    for (int i = 0; i < 5; ++i){
        snake.push_back(new snakePart(x + i * 20, y, r, g, b, this));
    }
    for(auto it = snake.begin(); it != snake.end(); it++)
        gameScene->addItem(*it);

    motionTimer = new QTimer(this);
    motionTimer->start(msec);
    connect(motionTimer, SIGNAL(timeout()),this,SLOT(motion()));
    newFruit();
}

void Snake::stopTimer(){
    motionTimer->stop();
}

void Snake::startTimer(int msec){
    motionTimer->start(msec);
}

int Snake::getScore(){
    return eatenFruit;
}

bool Snake::getFlagPause(){
    return flagPause;
}

void Snake::setFlagPause(bool flag){
    flagPause = flag;
}

QString Snake::getDirection()
{
    return direction;
}

void Snake::motion(){
    if(!directionThread.empty()){
        direction = directionThread.front();
        directionThread.pop_front();
    }

    fruitCollision();

    directPos();
    if(selfCollision()){
        emit GameOver();
        return;
    }

    snake.push_front(new snakePart(x, y, r, g, b, this));
    gameScene->addItem(snake.first());
    gameScene->removeItem(snake.last());
    snake.pop_back();

}

void Snake::directPos(){
    if(direction == "UP")
        y -= 20;
    else if(direction == "DOWN")
        y += 20;
    else if(direction == "LEFT")
        x -= 20;
    else if(direction == "RIGHT")
        x += 20;

    if(x < 0)
        x = 620;
    else if(y < 0)
        y = 460;
    else if(x >= 640)
        x = 0;
    else if(y >= 480)
        y = 0;
}

void Snake::newFruit(){
    fruit = new Fruit(this);
    fruitX = fruit->x();
    fruitY = fruit->y();
    for(auto it = snake.begin(); it != snake.end(); it++){
        if(fruitX == (*it)->x() && fruitY == (*it)->y()){
            delete fruit;
            newFruit();
        }
    }

    gameScene->addItem(fruit);
}

bool Snake::selfCollision(){

    for(auto it = snake.begin() + 1; it != snake.end(); it++){
        if ((x == (*it)->x()) && (y == (*it)->y())){
            motionTimer->stop();

            QList<QGraphicsItem*> allItems = gameScene->items();
            for(int i = 0; i < allItems.size(); ++i)
                gameScene->removeItem(allItems[i]);

            return true;
        }
    }
    return false;
}

void Snake::fruitCollision(){
    if (x == fruitX && y == fruitY){

        r = fruit->r;
        g = fruit->g;
        b = fruit->b;

        gameScene->removeItem(fruit);
        ++eatenFruit;
        infoPanel();

        if(eatenFruit % 5 == 0){
            motionTimer->stop();
            msec -= 5;
            motionTimer->start(msec);
        }

        delete fruit;
        newFruit();

        directPos();

        snake.push_front(new snakePart(x, y, r, g, b, this));
        gameScene->addItem(snake.first());
    }
}

void Snake::infoPanel(){
    if(eatenFruit > 1){
        gameScene->removeItem(currentScore);
        delete currentScore;
    }
    QString score_num = QString::number(eatenFruit);
    currentScore = new QGraphicsTextItem("Score: " + score_num);
    currentScore->setDefaultTextColor(Qt::green);
    currentScore->setPos(280, 495);
    QFont font;
    font.setPixelSize(20);
    currentScore->setFont(font);
    gameScene->addItem(currentScore);
}

void Snake::keyInfo(){
    QFont font;
    font.setPixelSize(18);
    QGraphicsTextItem *keyPause = new QGraphicsTextItem("P - Pause");
    keyPause->setDefaultTextColor(QColor(156, 156, 156));
    keyPause->setPos(2, 500);
    keyPause->setFont(font);
    gameScene->addItem(keyPause);
}

int Snake::getMsec(){
    return msec;
}

void Snake::setDirectionThread(QString newDirection){
    directionThread.push_back(newDirection);
}


