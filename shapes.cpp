#include "shapes.h"
#include "ui_shapes.h"
#include "mainwindow.h"

#include <QMessageBox>

using namespace std;

//http://forum.qtfr.org/discussion/11510/laisser-une-fenetre-en-premier-plan
shapes::shapes(QWidget *parent) :
    QDialog(parent,Qt::WindowStaysOnTopHint),
    ui(new Ui::shapes)
{
    ui->setupUi(this);
}

//destructor of shapes
shapes::~shapes()
{
    delete ui;
}


//Every button functions to emit a signal to the mainWindow
void shapes::on_buttonLine_clicked()
{
    //emition of a signal
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
    //creation of a dialogBox to verify the choice of the user
    QMessageBox msgBox;
    //message
    msgBox.setText("The arc is create by the center of the associate circle, the radius and the angle");
    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);//buttons with choice
    int erasee = msgBox.exec();//close de dialogBox

    //creation of a switch
    switch (erasee)
    {
      //if the user clic on "OK"
      case QMessageBox::Ok:
          emit choice(3);//emission of the choice
          ui->comboBox->addItem("Curve " + QString ::number(cu));
          cu++;
          break;

      //else STOP if CANCEL is clicked
      case QMessageBox::Cancel:
          break;
    }


}

void shapes::on_buttonCircle_clicked()
{
    //creation of a dialogBox to verify the choice of the user
    QMessageBox msgBox;
    msgBox.setText("The circle is an incircle of a rectangle. (ref to the HELP)");
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
          break;
    }
}

void shapes::on_buttonPoint_clicked()
{
    emit choice(5);
    ui->comboBox->addItem("Point " + QString ::number(p));
    p++;
}

void shapes::on_buttonDel_clicked()
{
    //creation of a dialogBox to verify the choice of the user
    QMessageBox msgBox;
    msgBox.setText("This action will erase everything which has a link with writting dimensions.");
    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    int erasee = msgBox.exec();

    switch (erasee)
    {
      case QMessageBox::Ok:
          emit choice(7);
          break;

      case QMessageBox::Cancel:
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
