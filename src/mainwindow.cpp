#include "mainwindow.h"
#include <QGridLayout>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setFixedSize(640, 550);
    scene = new QGraphicsScene(this);
    view = new QGraphicsView(scene, this);

    setCentralWidget(view);
    view->setFixedSize(642, 552);
    scene->setSceneRect(0, 0, 640, 550);

    this->setFocus();
    snake = new Snake(scene, this);
    panelLine();

    connect(snake, SIGNAL(GameOver()), this, SLOT(gameOver()));
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
        switch (event->key()) {
            case Qt::Key_Left:{
                if (snake->getDirection() != "RIGHT")
                     snake->setDirectionThread("LEFT");
                break;
            }
            case Qt::Key_Right:{

                if (snake->getDirection() != "LEFT")
                    snake->setDirectionThread("RIGHT");
                break;
            }
            case Qt::Key_Down:{
                if (snake->getDirection() != "UP")
                    snake->setDirectionThread("DOWN");
                break;
            }
            case Qt::Key_Up:{
                if (snake->getDirection() != "DOWN")
                    snake->setDirectionThread("UP");
                break;
            }
            case Qt::Key_P:{
                if(snake->getFlagPause()){
                    snake->startTimer(snake->getMsec());
                    snake->setFlagPause(false);
                    this->setFocus();
                }
                else {
                    snake->stopTimer();
                    snake->setFlagPause(true);
                }
                break;
            }
        }
}

void MainWindow::gameOver(){
    end = new QGraphicsTextItem("Game Over");
    end->setDefaultTextColor(Qt::red);
    end->setPos(120, 100);
    font.setPixelSize(70);
    font.setBold(true);
    end->setFont(font);
    scene->addItem(end);

    QString score_num = QString::number(snake->getScore());
    score = new QGraphicsTextItem("Score: " + score_num);
    score->setDefaultTextColor(Qt::green);
    score->setPos(260, 200);
    font.setPixelSize(30);
    font.setBold(false);
    score->setFont(font);
    scene->addItem(score); 

    restart = new QPushButton();
    restart->setText("Restart");
    restart->move(285,300);
    font.setPixelSize(15);
    font.setBold(true);
    restart->setFont(font);
    scene->addWidget(restart);
    connect(restart,SIGNAL(clicked(bool)), this, SLOT(updateSnake()));
}

void MainWindow::updateSnake(){
    QList<QGraphicsItem*> allItems = scene->items();
    for(int i = 0; i < allItems.size(); ++i)
        scene->removeItem(allItems[i]);
    deleteObj();
    this->setFocus();
    scene->addItem(line);
    snake = new Snake(scene, this);
    connect(snake, SIGNAL(GameOver()), this, SLOT(gameOver()));
}

void MainWindow::panelLine(){
    line = new QGraphicsRectItem;
    line->setRect(0, 0, 640, 1);
    line->setPos(0, 480);
    line->setBrush(Qt::black);
    line->setPen(Qt::NoPen);
    scene->addItem(line);
}

void MainWindow::deleteObj(){
    delete snake;
    delete score;
    delete end;
}
