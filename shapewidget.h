#ifndef SHAPEWIDGET_H
#define SHAPEWIDGET_H

#include "shapes.h"

#include <QWidget>
#include <QColor>
#include <QGraphicsItem>

class shapeWidget : public QWidget
{
    Q_OBJECT
public:
    explicit shapeWidget(QWidget *parent = 0);

    void paintEvent(QPaintEvent*);
    void mousePressEvent ( QMouseEvent *);

    QColor usingcolor;

    int outValue;

public slots:
    //slot to receive signal from shapes
    void changeDecision(int decision);

private:
    shapes *shapess;

    QGraphicsScene *scene;
    QGraphicsLineItem *lines;
};

#endif // SHAPEWIDGET_H
