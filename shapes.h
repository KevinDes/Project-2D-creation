#ifndef SHAPES_H
#define SHAPES_H

#include <QDialog>
#include <QComboBox>

namespace Ui {
class shapes;
}

class shapes : public QDialog
{
    Q_OBJECT

public:
    explicit shapes(QWidget *parent = 0);
    ~shapes();

    int l=1, m=1, cu=1, ci=1, p=1;

private slots:
    void on_buttonLine_clicked();

    void on_buttonMultiple_clicked();

    void on_buttonCurve_clicked();

    void on_buttonCircle_clicked();

    void on_buttonPoint_clicked();

    void on_buttonLength_clicked();

    void on_buttonDel_clicked();

    void on_buttonSave_clicked();

    void on_buttonLoad_clicked();

private:
    Ui::shapes *ui;


signals:
    void choice(int decision);
};

#endif // SHAPES_H

