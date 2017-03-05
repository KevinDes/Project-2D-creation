#ifndef TREE_H
#define TREE_H

#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QDialog>


namespace Ui {
class treeWindow;
}

class treeWindow : public QGraphicsTextItem
{
    Q_OBJECT

public:
    explicit treeWindow(QWidget *parent = 0);
    //~treeWindow();

private:
    Ui::treeWindow *ui;
    QGraphicsScene *scene;
    QDialog *dialog;

};


#endif // TREE_H
