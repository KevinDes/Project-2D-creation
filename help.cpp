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

    ui->label->show();
    ui->label_2->show();
}

Help::~Help()
{
    delete ui;
}
