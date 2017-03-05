#include <QMessageBox>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QtGui>
#include <QDialog>
#include <QtGui>

#include <tree.h>
#include <ui_mainwindow.h>
#include <mainwindow.h>

treeWindow::treeWindow(QWidget *parent)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);

    ui->comboBox->addItem("Hello");

}
