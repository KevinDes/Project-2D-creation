#include "shapes.h"
#include "ui_shapes.h"
#include "mainwindow.h"

#include <QMessageBox>

using namespace std;

shapes::shapes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::shapes)
{
    ui->setupUi(this);
}

shapes::~shapes()
{
    delete ui;
}


//Every button functions to emit a signal to the mainWindow
void shapes::on_buttonLine_clicked()
{
    emit choice(1);
    //the comboBox will receive the name of the item which is
    //created with an associated number
    ui->comboBox->addItem("Line " + QString ::number(l));
    l++;
}

void shapes::on_buttonMultiple_clicked()
{
    emit choice(2);
    ui->comboBox->addItem("Multiple " + QString ::number(m));
    m++;
}

void shapes::on_buttonCurve_clicked()
{
    emit choice(3);
    ui->comboBox->addItem("Curve " + QString ::number(cu));
    cu++;
}

void shapes::on_buttonCircle_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("The circle is an incircle of a rectangle.");
    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    int circ = msgBox.exec();

    switch (circ)
    {
      case QMessageBox::Ok:
          emit choice(4);
          ui->comboBox->addItem("Circle " + QString ::number(ci));
          ci++;
          break;

      case QMessageBox::Cancel:
          // Cancel was clicked
          break;
    }
}

void shapes::on_buttonPoint_clicked()
{
    emit choice(5);
    ui->comboBox->addItem("Point " + QString ::number(p));
    p++;
}

void shapes::on_buttonLength_clicked()
{
    emit choice(6);
}

void shapes::on_buttonDel_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("This action will erase everything with a link with writting dimensions.");
    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    int erasee = msgBox.exec();

    switch (erasee)
    {
      case QMessageBox::Ok:
          emit choice(7);
          break;

      case QMessageBox::Cancel:
          // Cancel was clicked
          break;
    }
}


void shapes::on_buttonSave_clicked()
{
    emit choice(8);
}


void shapes::on_buttonLoad_clicked()
{
    emit choice(9);
}
