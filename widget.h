#ifndef WIDGET_H
#define WIDGET_H
#include <QWidget>
#include<AVL.h>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(AVL Y,QWidget *parent = 0);
    ~Widget();

private slots:
    int on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::Widget *ui;
    AVL TREE;
};

#endif // WIDGET_H
