#include "shapewidget.h"
#include <QPainter>
#include <iostream>
using namespace std;

shapeWidget::shapeWidget(QWidget *parent) : QWidget(parent)
{
    shapess = new shapes();

    //connection by signal and slot between shapes and shapewidget
    connect(shapess, &shapes::choice,
            this, &shapeWidget :: changeDecision);

    usingcolor = QColor (250, 0, 0, 255);
}


void shapeWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setPen( usingcolor );

    painter.drawLine(0,60,50,110);
    painter.drawEllipse(0, 0, 50, 50);
    painter.drawPoint(25,125);
    painter.drawArc(25,150,25,150,0,90);
}

void shapeWidget::changeDecision(int decision)
{

}

void shapeWidget::mousePressEvent(QMouseEvent *)
{

}
