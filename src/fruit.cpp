#include "fruit.h"

Fruit::Fruit(QObject *parent):QObject(parent)
{
    setRect(0, 0, 20, 20);

    r = randInt(0, 255);
    g = randInt(0, 255);
    b = randInt(0, 255);
    setBrush(QColor(r, g, b));

    posX = randInt(1,30);
    posY = randInt(1,22);
    setPos(posX * 20, posY * 20);
}

int Fruit::randInt(int low, int high){
    return qrand() % ((high + 1) - low) + low;
}

