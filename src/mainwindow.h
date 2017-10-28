#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QKeyEvent>
#include <QPushButton>
#include <QGraphicsRectItem>

#include "snake.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    QGraphicsScene *scene;
    QGraphicsView *view;
    Snake *snake;
    QGraphicsTextItem *end;
    QGraphicsTextItem *score;
    QPushButton *restart;
    QGraphicsRectItem *line;
    QFont font;

public:
    MainWindow(QWidget *parent = 0);
    void keyPressEvent(QKeyEvent *event);
    void panelLine();
    void deleteObj();

public slots:
    void gameOver();
    void updateSnake();

};

#endif // MAINWINDOW_H
