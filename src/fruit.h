#ifndef FRUIT_H
#define FRUIT_H

#include <QGraphicsScene>
#include <QGraphicsRectItem>

class Fruit : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
private:
    int posX, posY;
public:
    Fruit(QObject *parent = 0);
    int randInt(int low, int high);
    int r, g, b;
};

#endif // FRUIT_H
