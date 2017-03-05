#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsPathItem>
#include <QtCore>
#include <QtGui>
#include <QGraphicsItem>
#include <QPainter>
#include <QPainterPath>
#include <QPen>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int a;

    void mouseMoveEvent (QMouseEvent * event);

    int xValue1,yValue1,xValue2,yValue2,xValue3,yValue3,xValue4,yValue4,xValue5,yValue5;
    int radiuss,point1,point2,point3,point4;


private slots:


    void on_pushButton_clicked();

    void on_buttonPoint_clicked();

    void on_buttonLine_clicked();

    void on_buttonMultiple_clicked();

    void on_buttonCurve_clicked();

    void on_buttonCircle_clicked();

    void on_buttonOk_clicked();

    void on_buttonLoad_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QGraphicsEllipseItem *ellipse;
    QGraphicsLineItem *lines;
    QGraphicsItem *arc;



};

#endif // MAINWINDOW_H
