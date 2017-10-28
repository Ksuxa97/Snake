#ifndef BOMB_H
#define BOMB_H

#include <QGraphicsScene>
#include <QGraphicsRectItem>

class Bomb : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
private:
    int posX, posY;
    int r, g, b;
public:
    Bomb(QObject *parent = 0);
    int randInt(int low, int high);
};

#endif // BOMB_H
