#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <tree.h>

#include <QMessageBox>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QBrush>
#include <QtCore>
#include <QtGui>
#include <QPainter>
#include <QPainterPath>
#include <QPen>
#include <QRectF>
#include <QFileDialog>
#include <QPixmap>
#include <QByteArray>
#include <QBuffer>


//pixel size = 0.66mm



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);


    ui->comboBox->addItem("Tree");
    ui->comboBox->addItem("Tree2");
    ui->comboBox->addItem("Tree3");
    ui->comboBox->addItem("Tree4");
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

}

void MainWindow::on_buttonPoint_clicked()
{
    ui->labelInfo->setText("Coordinates for a point : ");

}

void MainWindow::on_buttonLine_clicked()
{
    ui->labelInfo->setText("Choose 2 points for a line : ");

}

void MainWindow::on_buttonMultiple_clicked()
{
    ui->labelInfo->setText("Choose multiple points for few lines : ");

}

void MainWindow::on_buttonCurve_clicked()
{
    ui->labelInfo->setText("Choose 3 points for a curve : ");

}

void MainWindow::on_buttonCircle_clicked()
{
    ui->labelInfo->setText("Choose a point and the radius : ");

}


void MainWindow::on_buttonOk_clicked()
{

    //int xValue1,yValue1,xValue2,yValue2,xValue3,yValue3,xValue4,yValue4,xValue5,yValue5;
    //int radiuss,point1,point2,point3,point4;

    if( ui->labelInfo->text() == QString("Coordinates for a point : ") )
    {
        xValue1 = ui->lineEdit->text().toInt();
        yValue1 = ui->lineEdit_2->text().toInt();

        ui->graphicsView->setScene(scene);

        QPen blackPen(Qt::black);
        blackPen.setWidth(4);

        lines = scene->addLine(xValue1,yValue1,xValue1,yValue1,blackPen);



    }

    else if( ui->labelInfo->text() == QString("Choose 2 points for a line : ") )
    {
        xValue1 = ui->lineEdit->text().toInt();
        yValue1 = ui->lineEdit_2->text().toInt();
        xValue2 = ui->lineEdit_3->text().toInt();
        yValue2 = ui->lineEdit_4->text().toInt();

        ui->graphicsView->setScene(scene);

        QPen blackPen(Qt::black);
        blackPen.setWidth(4);

        lines = scene->addLine(xValue1,yValue1,xValue2,yValue2,blackPen);


    }
    else if( ui->labelInfo->text() == QString("Choose multiple points for few lines : ") )
    {
        xValue1 = ui->lineEdit->text().toInt();
        yValue1 = ui->lineEdit_2->text().toInt();
        xValue2 = ui->lineEdit_3->text().toInt();
        yValue2 = ui->lineEdit_4->text().toInt();
        xValue3 = ui->lineEdit_5->text().toInt();
        yValue3 = ui->lineEdit_6->text().toInt();
        xValue4 = ui->lineEdit_7->text().toInt();
        yValue4 = ui->lineEdit_8->text().toInt();
        xValue5 = ui->lineEdit_9->text().toInt();
        yValue5 = ui->lineEdit_10->text().toInt();

        ui->graphicsView->setScene(scene);

        QPen blackPen(Qt::black);
        blackPen.setWidth(4);

        lines = scene->addLine(xValue1,yValue1,xValue2,yValue2,blackPen);
        lines = scene->addLine(xValue2,yValue2,xValue3,yValue3,blackPen);
        lines = scene->addLine(xValue3,yValue3,xValue4,yValue4,blackPen);
        lines = scene->addLine(xValue4,yValue4,xValue5,yValue5,blackPen);


    }
    else if( ui->labelInfo->text() == QString("Choose a point and the radius : ") )
    {
        xValue1 = ui->lineEdit->text().toInt();
        yValue1 = ui->lineEdit_2->text().toInt();

        radiuss = ui->lineEdit_3->text().toInt();

        ui->graphicsView->setScene(scene);

        QPen blackPen(Qt::black);
        blackPen.setWidth(4);

        point1 = xValue1-((radiuss-xValue1)/2);
        point2 = yValue1-((radiuss-yValue1)/2);
        point3 = point1-radiuss;
        point4 = point2-radiuss;

        ellipse = scene->addEllipse(point1,point2,point3,point4,blackPen);


    }
    else if( ui->labelInfo->text() == QString("Choose 3 points for a curve : ") )
    {

        xValue1 = ui->lineEdit->text().toInt();
        yValue1 = ui->lineEdit_2->text().toInt();

        radiuss = ui->lineEdit_11->text().toInt();

        ui->graphicsView->setScene(scene);

        QPen blackPen(Qt::black);
        blackPen.setWidth(4);

        QRectF rectangle(10.0, 20.0, 80.0, 60.0);

        int startAngle = 30 * 16;
        int spanAngle = 120 * 16;

        QPainter painter(this);
        painter.drawArc(rectangle, startAngle, spanAngle);



    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    //use to check positions
    ui->lineEdit ->setText(QString::number(event->x()));
    ui ->lineEdit_2 ->setText(QString::number(event->y()));
}



void MainWindow::on_buttonLoad_clicked()
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


void MainWindow::on_buttonSave_clicked()
{


    QString fileName = QFileDialog::getSaveFileName(this,
                                                    tr("Save Image"), "",
                                                    tr("Image(*.jpeg *.jpg);;All Files (*)"));

    if(fileName != "")
        {
            QImage image(fileName);

            QPixmap pixmap(fileName);

            //The loop runs properly
            //just problem of black picture after saving
            if(pixmap.save(fileName))
                QMessageBox::information(0,"Done","Done");
            else
                QMessageBox::critical(0,"Error","Error");
        }
}
