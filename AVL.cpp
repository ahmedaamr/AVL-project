#include "AVL.h"
#include <iostream>
#include<QProcess>
#include<QtCore>
#include <algorithm>
#include<QMessageBox>
using namespace std;

AVL::AVL()
{
    root=0;

}

void AVL::init(QGraphicsScene* scene, QGraphicsView* view){
    this->_scene = scene;
    this->_view = view;
}
Node* AVL::Insert(Node *root, int v)
{

    if (root == 0)
    {
        root = new Node;
        root->value = v;
        root->left = 0;
        root->right = 0;
        root->height= Get_h(root);
        root = Get_balance(root);

        return root;
    }
    else if (v < root->value)
    {

        root->left = Insert(root->left, v);

        root = Get_balance(root);

    }




    else if (v > root->value)
    {

        root->right = Insert(root->right, v);

        root = Get_balance(root);


    }


    return root;
}




Node* AVL::Delete( Node* root, int v)
{

    if (root == 0)
    {
        return root;
    }
    if ( v < root->value )
        root->left = Delete(root->left, v);

    else if( v > root->value )
        root->right = Delete(root->right, v);



    else
    {
                                    //no child
        if (root->left == 0 && root->right == 0)
        {
            delete root;
            root = 0;
        }
                                    //one child
        else if (root->left == 0)
        {

            Node *temp = root;
            root = root->right;
            delete temp;
        }

        else if (root->right == 0)
        {
            Node *temp = root;
            root = root->left;
            delete temp;

        }
        else              //two child
        {

            Node* temp=root->left;
            while(temp->right!=0 )
            {
                temp=temp->right;

            }


            root->value = temp->value;
            root->left = Delete(root->left, temp->value);
        }
    }


    if(root!=0)
    {
        root->height=Get_h(root);
        root=Get_balance(root);
    }





    return root;
}


Node* AVL::Search(Node *root, int v)
{

if(root==0)
{
    QMessageBox msgBox;
    msgBox.setText("The Number was Not  Found ");
    msgBox.exec();
    return root;
}
 if(v==root->value)
{

     QMessageBox msgBox;
     msgBox.setText("The Number has been   Found ");
     msgBox.exec();
    return root;

}


else if (v < root->value)
        root->left = Search(root->left, v);

else if (v > root->value)
       root->right = Search(root->right, v);



return root;

}

int AVL::Get_h(Node *temp)
{
    int h = 0;
    if (temp != 0)
    {
        int l_height = Get_h (temp->left);
        int r_height = Get_h (temp->right);
        h = max (l_height, r_height) + 1;
    }
    return h;
}

int AVL::Get_BF(Node *temp)
{
    int l_height = Get_h (temp->left);
    int r_height = Get_h (temp->right);
    int bf= l_height - r_height;
    return bf;
}



Node *AVL::Get_balance(Node *temp)
{
    int bf = Get_BF(temp);
    if (bf > 1)
    {
        if (Get_BF(temp->left) > 0)    // 5   ->2
            temp = LL (temp);         //3     ->1
                                    //2       ->0
        else
            temp = LR (temp);         //5
    }                              //3
                                       //4
    else if (bf < -1)
    {
        if (Get_BF(temp->right) > 0)
            temp = RL (temp);               //5         ->-2
        else                                    //6     ->-1
            temp = RR (temp);                       //9   ->0
    }
    return temp;
}


Node *AVL::RR(Node *parent)
{

    Node *temp;
    temp = parent->right;    //=2
    parent->right=temp->left;
    temp->left=parent;
                                       //1
                                                                        //2
                                                                            //3
    //parent->right =  0;


    return temp;
}


Node *AVL::LL(Node *parent)
{
    Node *temp;
    temp = parent->left; //=4
    parent->left=temp->right;
    temp->right=parent;                   //5
                                       //4
   // parent->left = 0;               //3

    return temp;
}


Node *AVL::LR(Node *parent)
{
    Node *temp;
    temp = parent->left;
    parent->left = RR (temp);
    return LL (parent);
}


Node *AVL::RL(Node *parent)
{
    Node *temp;
    temp = parent->right;
    parent->right = LL (temp);
    return RR (parent);
}

 QString AVL::inorder(Node *tree,QString y)
{
    if (tree!=0)
    {
        int x=tree->value;
        QString z=y;
         y=y+QString::number(x);
    return inorder(tree->left,z)+y+inorder(tree->right,z);
    }
    return " ";
}


QString AVL::preorder(Node *tree,QString y)
{
    if(tree!=0)
    {
    int x=tree->value;
    QString z=y;
     y=y+QString::number(x);
     return y+preorder(tree->left,z)+preorder(tree->right,z);
    }
    return " ";
}



QString AVL::postorder(Node *tree,QString y)
{
    if (tree != 0)
    {
        int x=tree->value;
        QString z=y;
        y=y+QString::number(x);
        return postorder(tree->left,z)+postorder(tree->right,z)+y;
    cout<<tree->value<<"  ";
    }
    return " ";
}

void AVL::_graphWalk(Node* p, QTextStream *stream) {

    if (p != NULL){
        *stream << "\t\t" << "n" << p->value << "[label=\"" << p->value <<"\"];" << endl;
        if(p->left != NULL){
            *stream << "\t\tn" << p->value << "--" << "n" << p->left->value << ";" << endl;
            this->_graphWalk(p->left, stream);
        }else{
            *stream << "\t\t" << "n" << p->value << "leftNull" << "[style=\"filled\",label=\"NULL\"];" << endl;
            *stream << "\t\tn" << p->value<< "--" << "n" << p->value << "leftNull" << endl;
        }

        if(p->right != NULL){
            *stream << "\t\tn" << p->value << "--" << "n" << p->right->value << ";" << endl;
            this->_graphWalk(p->right, stream);
        }else{
            *stream << "\t\t" << "n" << p->value << "rightNull" << "[style=\"filled\",label=\"NULL\"];" << endl;
            *stream << "\t\tn" << p->value << "--" << "n" << p->value<< "rightNull" << endl;
        }
    }

    /*

        if (p==NULL)
        *stream<< "1->2"<<endl;
*/
}
QByteArray AVL::_prepareGraph(){

    QByteArray a = QByteArray();

    QTextStream stream(&a, QIODevice::ReadWrite);
    stream << "graph ""{" << endl;
    stream << "\tnode[fontsize=10,margin=0,width=\".4\", height=\".3\"];" << endl;
    stream << "\tsubgraph cluster17{" << endl;


    this->_graphWalk(this->root, &stream);
    stream << "\t}\n" << "}" << endl;
    stream.flush();

    return a;


/*
    QByteArray a = QByteArray();

    QTextStream stream(&a, QIODevice::ReadWrite);
    stream << "digraph g {" << endl;
    this->_graphWalk(root, &stream);
    stream << "\t}\n" << "}" << endl;
    stream.flush();

    return a;
*/
}



void AVL::show(){
    QProcess* p = new QProcess();
    QByteArray a = this->_prepareGraph();

    p->setProcessChannelMode(QProcess::MergedChannels);
    p->start("dot", QStringList() << "-Tpng");
    p->write(a);

    QByteArray data;
    QPixmap pixmap = QPixmap();
    while(p->waitForReadyRead(400)){
        data.append(p->readAll());
    }

    pixmap.loadFromData(data);
    this->_scene->clear();
    this->_scene->addPixmap(pixmap);

    this->_view->show();




}
