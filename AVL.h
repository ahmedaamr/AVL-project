#ifndef AVL_H
#define AVL_H
#include <QGraphicsView>
#include<QGraphicsScene>
#include<QTextStream>
#include<QtGui>
#include<QtCore>
#include<string>
using namespace std;
struct Node
{

    int value;
    Node *left;
    Node *right;
    int height;


};


class AVL
{
    public:
        AVL();
        void init(QGraphicsScene* scene, QGraphicsView* view);
       Node* Insert(Node *root, int value);
       Node* Delete( Node* root, int v);
       Node* Search(Node *root, int v);
       int Get_h(Node *temp);
        int Get_BF(Node *temp);
        Node* RR(Node *parent);
        Node* LL(Node *parent);
        Node* LR(Node *parent);
        Node* RL(Node *parent);
        Node* Get_balance(Node *temp);
        QString inorder(Node *tree,QString y);
        QString preorder(Node *tree,QString y);
        QString postorder(Node *tree,QString y);
        void show();
        QGraphicsScene* _scene;
        QGraphicsView* _view;
        void _graphWalk(Node* p, QTextStream *stream);
        QByteArray _prepareGraph();
         Node *root;
};

#endif // AVL_H
