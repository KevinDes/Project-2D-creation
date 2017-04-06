#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "shapes.h"

#include <QString>
#include <QPainter>
#include <QGraphicsView>
#include <QFileDialog>
#include <QDir>
#include <QImageWriter>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    shapess = new shapes();
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    connect(shapess, &shapes::choice,
            this, &MainWindow::changeDecision);



    xValue1 = ui->lineEdit->text().toInt();
    yValue1 = ui->lineEdit_2->text().toInt();
    xValue2 = ui->lineEdit_3->text().toInt();
    yValue2 = ui->lineEdit_4->text().toInt();
    xValue3 = ui->lineEdit_5->text().toInt();
    yValue3 = ui->lineEdit_6->text().toInt();
    xValue4 = ui->lineEdit_7->text().toInt();
    yValue4 = ui->lineEdit_8->text().toInt();

    radiuss = ui->lineEdit_9->text().toInt();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeDecision(int decision){

    if (decision == 1)//Draw a line
    {
        ui->graphicsView->setScene(scene);

        QPen blackPen(Qt::black);
        blackPen.setWidth(4);

        lines = scene->addLine(xValue1,yValue1,xValue2,yValue2,blackPen);
    }

    else if (decision == 2)//draw multiple lines
    {
        ui->graphicsView->setScene(scene);

        QPen blackPen(Qt::black);
        blackPen.setWidth(4);

        lines = scene->addLine(xValue1,yValue1,xValue2,yValue2,blackPen);
        lines = scene->addLine(xValue2,yValue2,xValue3,yValue3,blackPen);
        lines = scene->addLine(xValue3,yValue3,xValue4,yValue4,blackPen);
    }
    else if (decision == 3)//draw an arc
    {

    }

    else if (decision == 4)//draw a circle
    {
        ui->graphicsView->setScene(scene);

        QPen blackPen(Qt::black);
        blackPen.setWidth(4);

        point1 = xValue1-((radiuss-xValue1)/2);
        point2 = yValue1-((radiuss-yValue1)/2);
        point3 = point1-radiuss;
        point4 = point2-radiuss;

        circle = scene->addEllipse(point1,point2,point3,point4,blackPen);
    }
    else if (decision == 5)//draw a point
    {
        ui->graphicsView->setScene(scene);

        QPen blackPen(Qt::black);
        blackPen.setWidth(4);

        lines = scene->addLine(xValue1,yValue1,xValue1,yValue1,blackPen);
    }

    else if (decision == 6)//add the length
    {

    }

    else if(decision == 7)
    {

    }

    else if (decision == 8)
    {
        QString fileName = QFileDialog::getSaveFileName(this,
                                                        tr("Save Image"), "",
                                                        tr("Image(*.jpeg *.jpg);;All Files (*)"));
        QPixmap pixmap(fileName);
        pixmap.save(fileName, "JPG");
    }

    else if (decision == 9)//Load an image
    {
        QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                        QDir::currentPath(),
                                                        tr("Images (*.jpeg *.jpg)"));
        QImage image(fileName);
        QPixmap pixmap(fileName);
        scene->addPixmap(pixmap);
        ui->graphicsView->setScene(scene);
        ui->graphicsView->show();
    }
}

void MainWindow::on_pushButton_released()
{
    shapess->show();
}

