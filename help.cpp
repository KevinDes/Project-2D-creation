#include "help.h"
#include "ui_help.h"

#include <QGraphicsView>
#include <QPixmap>
#include <QFileDialog>
#include <QDir>
#include <QGraphicsScene>
#include <QLabel>


Help::Help(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Help)
{
    ui->setupUi(this);

    //Integration of two pictures in the UI
    ui->label->show();
    ui->label_2->show();

    //the rest is in the help.ui file
}

Help::~Help()
{
    delete ui;
}
