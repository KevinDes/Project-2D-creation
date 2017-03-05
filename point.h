#ifndef POINT_H
#define POINT_H

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

private slots:

    void on_buttonPoint_clicked();


private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QGraphicsLineItem *lines;

};

#endif // POINT_H
