#include "snakepart.h"

snakePart::snakePart(int posX, int posY, int r, int g, int b, QObject *parent):QObject(parent)
{
    setRect(0, 0, 20, 20);
    setBrush(QColor(r, g, b));
    setPen(Qt::NoPen);
    setPos(posX, posY);
}






