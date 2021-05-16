#include <iostream>
#include <queue>
#include <bits/stdc++.h>
using namespace std;

template <class T> 
class TNode
{
    public:
        T _value;
        TNode<T> *_left, *_right;
        TNode();
        TNode(const T &info=0, TNode<T> *left=0, TNode<T> *right=0);
        bool isLeaf(void);
};

template <class T>
TNode<T>::TNode()
{
   _left = _right = 0;
   _value = 0; 
}

template <class T>
TNode<T>::TNode(const T &info, TNode<T> *left, TNode<T> *right)
{
    _left = left;
    _right = right;
    _value = info;
}

template <class T>
bool TNode<T>::isLeaf(void)
{
    if(this->_left ==0 &&  this->_right == 0)
        return true;
    else
        return false;
}

template <class T>
class BTree
{
    private:
        TNode<T> *_root;
        int _nNodes;
    public:
        BTree();
        void insert(const T &);
        T remove(const T&);
        void print(void);
        int number_nodes(void);
        void preorder(TNode<T> *);
        void print_preorder(void);
};

template <class T>
BTree<T>::BTree()
{
    _root = 0;
    _nNodes = 0;
}

template <class T>
void BTree<T>::insert(const T &info)
{
    if(_root==0)
    {
        _root = new TNode<T>(info);
        _nNodes++;
        return;
    }
    else
    {
        TNode<T> *tmp = _root;
        while (!tmp->isLeaf())
        {
            if(info>tmp->_value)
            {
                if(tmp->_right!=0)
                    tmp = tmp->_right;
                else
                {
                    tmp->_right = new TNode<T>(info);
                    _nNodes++;
                    return;
                }
            }
            else if(info<tmp->_value)
            {
                if(tmp->_left!=0)
                    tmp = tmp->_left;
                else
                {
                    tmp->_left = new TNode<T>(info);
                    _nNodes++;
                    return;
                }
                
            }
            else
            {
                cout << "Value Already exists!!" << endl;
                return;
            }
        }

        if(info>tmp->_value)
            tmp->_right = new TNode<T>(info);
        else if(info<tmp->_value)
            tmp->_left = new TNode<T>(info);
        else
        {
            cout << "Value Already exists!!" << endl;
            return;
        }
        _nNodes++;
    }
}

template <class T>
T BTree<T>::remove(const T&info)
{
    if(_root==0)
        cout << "Can't remove from an ampty tree!!!" << endl;
    else if(_root->_left==0 && _root->_right==0)    // only one node
    {
        if(info==_root->_value) delete _root;
        else cout << "Not in Tree!!" << endl;
    }
    else
    {
        TNode<T> *tmp = _root;

        while(true)
        {
            if(tmp==0)
            {
                cout << "Not in Tree!" << endl;
                return 0;
            }
            else if(tmp->_right==info)
            {
                
            }
            else if (tmp->_left==info)
            {

            }
            else if(tmp->_value==info)
            {
                cout << "found" << endl;
                return tmp->_value;
            }
            else if (info>tmp->_value)
                tmp = tmp->_right;
            else if (info<tmp->_value)
                tmp = tmp->_left;
        }
    }
}

template <class T>
void BTree<T>::print(void)
{
    if(_root==0)
        cout << "Empty tree!!!" << endl;
    else if(_root->isLeaf())    // only one node
    {
        cout << _root->_value << endl;
    }
    else
    {
        queue<TNode<T>*> q;
        q.push(_root);
        TNode<T> *node;
        while (q.size() != 0)
        {
            node = q.front();
            q.pop();
            cout << node->_value << " ";
            if(node->_left!=0)
                q.push(node->_left);
            if(node->_right!=0)
                q.push(node->_right);
        }
        cout << endl;
    }
}

template <class T>
int BTree<T>::number_nodes(void)
{
    return _nNodes;
}

template <class T>
void BTree<T>::preorder(TNode<T> *node)
{
    if(node==0) return;
    cout << node->_value << " ";
    preorder(node->_left);
    preorder(node->_right);
}

template <class T>
void BTree<T>::print_preorder(void)
{
    preorder(_root);
    cout << endl;
}


int main(void)
{
    BTree<int> a;

    a.insert(13);
    a.insert(10);
    a.insert(25);
    a.insert(2);
    a.insert(12);
    a.insert(20);
    a.insert(29);
    a.insert(31);
    cout << "Breadth-First Traversal" << endl;
    a.print();
    cout << "Preorder Traversal" << endl;
    a.print_preorder();


    return 0;
}





