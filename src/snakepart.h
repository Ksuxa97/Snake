#ifndef SNAKEPART_H
#define SNAKEPART_H

#include <QTimer>
#include <QTime>
#include <QGraphicsScene>
#include <QGraphicsRectItem>

class snakePart: public QObject, public QGraphicsRectItem
{
    Q_OBJECT

public:
    snakePart(int posX, int posY, int r, int g, int b, QObject *parent = 0);
};

#endif // SNAKEPART_H
