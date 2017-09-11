#include "widget.h"
#include "ui_widget.h"
#include<QtGui>
#include<QtCore>
#include "dialog.h"
 #include <QMessageBox>
#include<QString>
#include<QPixmap>
#include<AVL.h>
 #include <QLabel>

Widget::Widget(AVL Y,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{



setStyleSheet("QLineEdit { background: yellow ;}\n Widget { background: #277EB5; }\n QMessageBox{background:#28D69A;}");

    ui->setupUi(this);

    TREE=Y;
}

Widget::~Widget()
{
    delete ui;
}

int  Widget::on_pushButton_clicked()
{
     //QMessageBox ::information(this,"Widget",ui->lineEdit_2->text());
     QString TheNum=ui->lineEdit_2->text();
     int x=TheNum.toInt();
     TREE.root=TREE.Insert(TREE.root,x);
     TREE.show();
     return x;

}

void Widget::on_pushButton_2_clicked()
{
//QMessageBox ::information(this,"Widget","done");
    QString TheNum=ui->lineEdit->text();
    int x=TheNum.toInt();
    TREE.root=TREE.Delete(TREE.root,x);
    TREE.show();

}


void Widget::on_pushButton_3_clicked()
{
    QString TheNum=ui->lineEdit_3->text();
    int x=TheNum.toInt();
    TREE.root=TREE.Search(TREE.root,x);

}


void Widget::on_pushButton_5_clicked()
{
    //std::string l=TREE.inorder(TREE.root);
   // QString qstr = QString::fromStdString(l);
    QString y1=" ",y2=" ",y3=" ";
    y1=TREE.inorder(TREE.root,y1);
    y2=TREE.preorder(TREE.root,y2);
    y3=TREE.postorder(TREE.root,y3);
    QMessageBox ::information(this,"Widget","InOrder : "+y1+"\nPreOrder : "+y2+"\nPostOrder : "+y3);
}
