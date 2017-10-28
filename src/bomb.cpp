#include "bomb.h"

Bomb::Bomb(QObject *parent):QObject(parent)
{
    setRect(0, 0, 20, 20);
    QRadialGradient radialGrad(QPointF(100, 100), 100);
    r = randInt(0, 255);
    g = randInt(0, 255);
    b = randInt(0, 255);
    radialGrad.setColorAt(0, QColor(r, g, b));
    r = randInt(0, 255);
    g = randInt(0, 255);
    b = randInt(0, 255);
    radialGrad.setColorAt(0.5, QColor(r, g, b));
    r = randInt(0, 255);
    g = randInt(0, 255);
    b = randInt(0, 255);
    radialGrad.setColorAt(1, QColor(r, g, b));


//    setBrush(QColor(r, g, b));

//    r = randInt(0, 255);
//    g = randInt(0, 255);
//    b = randInt(0, 255);
    setPen(QColor(r, g, b));


    posX = randInt(1,30);
    posY = randInt(1,22);
    setPos(posX * 20, posY * 20);
}

int Bomb::randInt(int low, int high){
    return qrand() % ((high + 1) - low) + low;
}
