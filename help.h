#ifndef HELP_H
#define HELP_H

#include <QDialog>
#include <QGraphicsScene>

namespace Ui {
class Help;
}

class Help : public QDialog
{
    Q_OBJECT

public:
    explicit Help(QWidget *parent = 0);
    ~Help();

private slots:
    //void on_pushButton_show_clicked();

private:
    Ui::Help *ui;
    QGraphicsScene *scene;

};

#endif // HELP_H
