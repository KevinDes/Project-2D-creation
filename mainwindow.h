#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "shapes.h"
#include "help.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    //coordinates of each shapes
    int xValue1,yValue1,xValue2,yValue2,xValue3,yValue3,xValue4,yValue4,angle;

    //mousePressEvent
    void mousePressEvent (QMouseEvent * event);


private slots:
    //slot to receive signal from shapes
    void changeDecision(int decision);

    void on_pushButton_released();

    void on_pushButton_help_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QGraphicsView *view;
    shapes *shapess;
    QGraphicsLineItem *lines;
    QGraphicsEllipseItem *circle;
    Help * helps;

};

#endif // MAINWINDOW_H
