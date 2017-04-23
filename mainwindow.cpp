#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "shapes.h"

#include <QString>
#include <QPainter>
#include <QGraphicsView>
#include <QFileDialog>
#include <QDir>
#include <QImageWriter>
#include <QMouseEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    shapess = new shapes();
    scene = new QGraphicsScene(this);//creation of the scene
    ui->graphicsView->setScene(scene);//set the scene on the graphicsView

    connect(shapess, &shapes::choice,
            this, &MainWindow::changeDecision);//connection by signal and slot

}

//destructor of the mainWindow
MainWindow::~MainWindow()
{
    delete ui;
}

//beginning of the changeDecision function
//which is working with signal and slot
void MainWindow::changeDecision(int decision){

    if (decision == 1)//Draw a line
    {
        ui->graphicsView->setScene(scene);

        xValue1 = ui->lineEdit->text().toInt();
        yValue1 = ui->lineEdit_2->text().toInt();
        xValue2 = ui->lineEdit_3->text().toInt();
        yValue2 = ui->lineEdit_4->text().toInt();

        QPen blackPen(Qt::black);
        blackPen.setWidth(4);

        lines = scene->addLine(xValue1,yValue1,xValue2,yValue2,blackPen);


        ui->lineEdit_5->setText("");
        ui->lineEdit_6->setText("");
        ui->lineEdit_7->setText("");
        ui->lineEdit_8->setText("");

    }

    else if (decision == 2)//draw multiple lines
    {
        ui->graphicsView->setScene(scene);

        xValue1 = ui->lineEdit->text().toInt();
        yValue1 = ui->lineEdit_2->text().toInt();
        xValue2 = ui->lineEdit_3->text().toInt();
        yValue2 = ui->lineEdit_4->text().toInt();
        xValue3 = ui->lineEdit_5->text().toInt();
        yValue3 = ui->lineEdit_6->text().toInt();
        xValue4 = ui->lineEdit_7->text().toInt();
        yValue4 = ui->lineEdit_8->text().toInt();

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

        xValue1 = ui->lineEdit->text().toInt();
        yValue1 = ui->lineEdit_2->text().toInt();
        xValue2 = ui->lineEdit_3->text().toInt();
        yValue2 = ui->lineEdit_4->text().toInt();

        QPen blackPen(Qt::black);
        blackPen.setWidth(4);

        circle = scene->addEllipse(xValue1,yValue1,xValue2,yValue2,blackPen);

        ui->lineEdit_5->setText("");
        ui->lineEdit_6->setText("");
        ui->lineEdit_7->setText("");
        ui->lineEdit_8->setText("");
    }
    else if (decision == 5)//draw a point
    {
        ui->graphicsView->setScene(scene);

        xValue1 = ui->lineEdit->text().toInt();
        yValue1 = ui->lineEdit_2->text().toInt();

        QPen blackPen(Qt::black);
        blackPen.setWidth(4);

        lines = scene->addLine(xValue1,yValue1,xValue1,yValue1,blackPen);

        ui->lineEdit_3->setText("");
        ui->lineEdit_4->setText("");
        ui->lineEdit_6->setText("");
        ui->lineEdit_5->setText("");
        ui->lineEdit_7->setText("");
        ui->lineEdit_8->setText("");
    }


    else if(decision == 7)
    {
        QPen whitePen(Qt::white);
        whitePen.setWidth(4);

        lines = scene->addLine(xValue1,yValue1,xValue2,yValue2,whitePen);
        lines = scene->addLine(xValue2,yValue2,xValue3,yValue3,whitePen);
        lines = scene->addLine(xValue3,yValue3,xValue4,yValue4,whitePen);
        circle = scene->addEllipse(xValue1,yValue1,xValue2,yValue2,whitePen);

    }

    else if (decision == 8)//Save an image
    {
        QGraphicsView* view = new QGraphicsView(scene,this);

        QString fileName = QFileDialog::getSaveFileName(this,
                                                        tr("Save Image"), "",
                                                        tr("Image(*.jpeg *.jpg);All Files (*)"));
        QPixmap pixMap = QPixmap::grabWidget(view);
        //http://stackoverflow.com/questions/7451183/how-to-create-image-file-from-qgraphicsscene-qgraphicsview
        pixMap.save(fileName);
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

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    //use to check positions
    ui->lineEdit ->setText(QString::number(event->x()));
    ui ->lineEdit_2 ->setText(QString::number(event->y()));
}

//Openning of the window shapes
void MainWindow::on_pushButton_released()
{
    shapess->show();
}

