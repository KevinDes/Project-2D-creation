#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QString>
#include <QPainter>
#include <QGraphicsView>
#include <QFileDialog>
#include <QDir>
#include <QImageWriter>
#include <QMouseEvent>
#include <QPainterPath>
#include <QTextStream>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    shapess = new shapes();
    helps = new Help();
    scene = new QGraphicsScene(this);//creation of the scene

    ui->graphicsView->setScene(scene);//set the scene on the graphicsView

    //connection by signal and slot between shapes and mainwindow
    connect(shapess, &shapes::choice,
            this, &MainWindow::changeDecision);
}

//destructor of the mainWindow
MainWindow::~MainWindow()
{
    delete ui;
}

//beginning of the changeDecision function
//which is working with signal and slot
void MainWindow::changeDecision(int decision)
{
    if (decision == 1)//Draw a line
    {
        //transform the lineEdit texts into integers
        xValue1 = ui->lineEdit->text().toInt();
        yValue1 = ui->lineEdit_2->text().toInt();
        xValue2 = ui->lineEdit_3->text().toInt();
        yValue2 = ui->lineEdit_4->text().toInt();

        //creation of the pen (color and width)
        QPen blackPen(Qt::black);
        blackPen.setWidth(4);

        //creation of the corresponding line with coordinates and the using pen
        lines = scene->addLine(xValue1,yValue1,xValue2,yValue2,blackPen);

        //here we erase the other lineEdit
        ui->lineEdit_5->setText("");
        ui->lineEdit_6->setText("");
        ui->lineEdit_7->setText("");
        ui->lineEdit_8->setText("");

        //Writing in a .txt file
        QFile file("Coordinates.txt");
        if (!file.open(QIODevice::WriteOnly | QIODevice::Append))
            return;

        QTextStream out(&file);
        out << "line =>\r\nxValue1 = " + ui->lineEdit->text()+ "\r\n" +
               "yValue1 = " + ui->lineEdit_2->text() + "\r\n" +
               "xValue2 = " + ui->lineEdit_3->text()+ " \r\n" +
               "yValue2 = " + ui->lineEdit_4->text() + " \r\n \r\n";
    }

    else if (decision == 2)//draw multiple lines
    {
        //transform the lineEdit texts into integers
        xValue1 = ui->lineEdit->text().toInt();
        yValue1 = ui->lineEdit_2->text().toInt();
        xValue2 = ui->lineEdit_3->text().toInt();
        yValue2 = ui->lineEdit_4->text().toInt();
        xValue3 = ui->lineEdit_5->text().toInt();
        yValue3 = ui->lineEdit_6->text().toInt();
        xValue4 = ui->lineEdit_7->text().toInt();
        yValue4 = ui->lineEdit_8->text().toInt();

        //creation of the pen (color and width)
        QPen blackPen(Qt::black);
        blackPen.setWidth(4);

        //creation of the corresponding lines with coordinates and the using pen
        lines = scene->addLine(xValue1,yValue1,xValue2,yValue2,blackPen);
        lines = scene->addLine(xValue2,yValue2,xValue3,yValue3,blackPen);
        lines = scene->addLine(xValue3,yValue3,xValue4,yValue4,blackPen);

        //Writing in a .txt file
        QFile file("Coordinates.txt");
        if (!file.open(QIODevice::WriteOnly | QIODevice::Append))
            return;

        QTextStream out(&file);
        out << "Multiple lines =>\r\nxValue1 = " + ui->lineEdit->text()+ " \r\n" +
               "yValue1 = " + ui->lineEdit_2->text() + " \r\n" +
               "xValue2 = " + ui->lineEdit_3->text()+ " \r\n" +
               "yValue2 = " + ui->lineEdit_4->text()+ " \r\n" +
               "xValue3 = " + ui->lineEdit_5->text() + " \r\n" +
               "yValue3 = " + ui->lineEdit_6->text()+ " \r\n" +
               "xValue4 = " + ui->lineEdit_7->text()+ " \r\n" +
               "yValue4 = " + ui->lineEdit_8->text() + " \r\n\r\n";
    }
    else if (decision == 3)//draw an arc
    {
        //transform the lineEdit texts into integers
        xValue1 = ui->lineEdit->text().toInt();
        yValue1 = ui->lineEdit_2->text().toInt();
        xValue2 = ui->lineEdit_3->text().toInt();
        yValue2 = ui->lineEdit_4->text().toInt();
        angle = ui->lineEdit_9->text().toInt();

        //creation of the pen (color and width)
        QPen blackPen(Qt::black);
        blackPen.setWidth(4);

        //creation of the corresponding arc using the QPainterPath
        //http://www.qtcentre.org/threads/22149-How-to-draw-a-semi-circle-or-arc-of-ellipse
        QPainterPath * path = new QPainterPath();
        path->arcMoveTo(xValue1,yValue1,xValue2,yValue2,0);
        path->arcTo(xValue1,yValue1,xValue2,yValue2,0, angle);

        //here we erase the other lineEdit
        ui->lineEdit_5->setText("");
        ui->lineEdit_6->setText("");
        ui->lineEdit_7->setText("");
        ui->lineEdit_8->setText("");

        //add the previous path to the scene
        scene->addPath(*path);


        //Writing in a .txt file
        QFile file("Coordinates.txt");
        if (!file.open(QIODevice::WriteOnly | QIODevice::Append))
            return;

        QTextStream out(&file);
        out << "Curve =>\r\nxValue1 = " + ui->lineEdit->text()+ " \r\n" +
               "yValue1 = " + ui->lineEdit_2->text() + " \r\n" +
               "xValue2 = " + ui->lineEdit_3->text() + " \r\n" +
               "yValue2 = " + ui->lineEdit_4->text() + " \r\n" +
               "angle = " + ui->lineEdit_9->text() + " \r\n\r\n" ;

    }

    else if (decision == 4)//draw a circle
    {
        //transform the lineEdit texts into integers
        xValue1 = ui->lineEdit->text().toInt();
        yValue1 = ui->lineEdit_2->text().toInt();
        xValue2 = ui->lineEdit_3->text().toInt();
        yValue2 = ui->lineEdit_4->text().toInt();

        //creation of the pen (color and width)
        QPen blackPen(Qt::black);
        blackPen.setWidth(4);

        //creation of the corresponding circle with rectangle coordinates and the using pen
        circle = scene->addEllipse(xValue1,yValue1,xValue2,yValue2,blackPen);

        //here we erase the other lineEdit
        ui->lineEdit_5->setText("");
        ui->lineEdit_6->setText("");
        ui->lineEdit_7->setText("");
        ui->lineEdit_8->setText("");

        //Writing in a .txt file
        QFile file("Coordinates.txt");
        if (!file.open(QIODevice::WriteOnly | QIODevice::Append))
            return;

        QTextStream out(&file);
        out << "Circle =>\r\nxValue1 = " + ui->lineEdit->text()+ " \r\n" +
               "yValue1 = " + ui->lineEdit_2->text() + " \r\n" +
               "xValue2 = " + ui->lineEdit_3->text() + " \r\n" +
               "yValue2 = " + ui->lineEdit_4->text() + " \r\n\r\n";
    }
    else if (decision == 5)//draw a point
    {
        //transform the lineEdit texts into integers
        xValue1 = ui->lineEdit->text().toInt();
        yValue1 = ui->lineEdit_2->text().toInt();

        //creation of the pen (color and width)
        QPen blackPen(Qt::black);
        blackPen.setWidth(4);

        //creation of the corresponding point with coordinates and the using pen
        lines = scene->addLine(xValue1,yValue1,xValue1,yValue1,blackPen);

        //here we erase the other lineEdit
        ui->lineEdit_3->setText("");
        ui->lineEdit_4->setText("");
        ui->lineEdit_6->setText("");
        ui->lineEdit_5->setText("");
        ui->lineEdit_7->setText("");
        ui->lineEdit_8->setText("");

        //Writing in a .txt file
        QFile file("Coordinates.txt");
        if (!file.open(QIODevice::WriteOnly | QIODevice::Append))
            return;

        QTextStream out(&file);
        out << "Point =>\r\nxValue1 = " + ui->lineEdit->text()+ " \r\n" +
               "yValue1 = " + ui->lineEdit_2->text() + " \r\n" ;

    }


    else if(decision == 7)
    {
        //creation of the pen (color and width)
        QPen whitePen(Qt::white);
        whitePen.setWidth(4);

        //Creation of shapes which will erase the black ones
        lines = scene->addLine(xValue1,yValue1,xValue2,yValue2,whitePen);
        lines = scene->addLine(xValue2,yValue2,xValue3,yValue3,whitePen);
        lines = scene->addLine(xValue3,yValue3,xValue4,yValue4,whitePen);
        circle = scene->addEllipse(xValue1,yValue1,xValue2,yValue2,whitePen);

        /*
        QPainterPath * path = new QPainterPath();
        path->arcMoveTo(xValue1,yValue1,xValue2,yValue2,0);
        path->arcTo(xValue1,yValue1,xValue2,yValue2,0, angle);

        scene->addPath(*path);*/

    }

    else if (decision == 8)//Save an image
    {
        QGraphicsView* view = new QGraphicsView(scene);

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

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    //if the left clic is pressed
    if(event->button()==Qt::LeftButton)
    {
        //put coordinates in lineEdit and lineEdit_2
        ui->lineEdit ->setText(QString::number(event->x()-473-41+25));
        ui ->lineEdit_2 ->setText(QString::number(event->y()-250-78+25));
        //-473
        //-250
    }
    //if the right clic is pressed
    else if(event->button()==Qt::RightButton)
    {
        //put coordinates in lineEdit_3 and lineEdit_4
        ui->lineEdit_3 ->setText(QString::number(event->x()-473-41+25));
        ui ->lineEdit_4 ->setText(QString::number(event->y()-250-78+25));
    }
}

//Openning of the window shapes
void MainWindow::on_pushButton_released()
{
    shapess->show();
}

//Openning of the window HELP
void MainWindow::on_pushButton_help_clicked()
{
    helps->show();
}
