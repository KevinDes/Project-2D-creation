#ifndef VECSHAPE_H
#define VECSHAPE_H

#include <QGraphicsLineItem>
#include <QGraphicsEllipseItem>

class vecShape
{
public:
    vecShape();

    int xValue1,yValue1,xValue2,yValue2,xValue3,yValue3,xValue4,yValue4,xValue5,yValue5,angle;

private:
    QGraphicsLineItem *lines;
    QGraphicsEllipseItem *circle;

};

#endif // VECSHAPE_H
