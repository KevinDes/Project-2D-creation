#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "shapes.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    int xValue1,yValue1,xValue2,yValue2,xValue3,yValue3,xValue4,yValue4,xValue5,yValue5;

    void mouseMoveEvent (QMouseEvent * event);


private slots:
    void changeDecision(int decision);
    void on_pushButton_released();


private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QGraphicsView *view;
    shapes *shapess;
    QGraphicsLineItem *lines;
    QGraphicsEllipseItem *circle;

};

#endif // MAINWINDOW_H
