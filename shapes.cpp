#include "shapes.h"
#include "ui_shapes.h"

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

void shapes::on_buttonLine_clicked()
{
    emit choice(1);
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
    emit choice(4);
    ui->comboBox->addItem("Circle " + QString ::number(ci));
    ci++;
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
    emit choice(7);
}


void shapes::on_buttonSave_clicked()
{
    emit choice(8);
}


void shapes::on_buttonLoad_clicked()
{
    emit choice(9);
}
