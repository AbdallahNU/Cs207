#include <iostream>
using namespace std;


template <class T>
class TNode
{
    public:
        T _value;
        int _vip;
        TNode<T>* _next;

        TNode();
        TNode(const T &, TNode<T>*next=0, const int &vip=0);
        ~TNode();
};

template <class T>
TNode<T>::TNode()
{
    _value = _vip = 0;
    _next =0;
}

template <class T>
TNode<T>::~TNode()
{

}

template <class T>
TNode<T>::TNode(const T& value, TNode<T>* next, const int &vip)
{
    _value = value;
    _next = next;
    _vip = vip;
}

template <class T>
class TPqueue
{
    private:
        TNode<T> *_head, *_tail;
    
    public:
        TPqueue();
        ~TPqueue();
        void Enqueue(const T&, const int &vip=0);
        T Dequeue(void);
        void print(void);
};

template <class T>
TPqueue<T>::TPqueue()
{
    _head = _tail = 0;
}

template <class T>
TPqueue<T>::~TPqueue()
{
}

template <class T>
void TPqueue<T>::Enqueue(const T&vlaue, const int &vip)
{
    if(_head==0)
        _head = _tail = new TNode<T>(vlaue, 0, vip);
    else if(vip>_head->_vip)
    {
        _head = new TNode<T>(vlaue, _head, vip);
        _tail = _head->_next;
    }
    else
    {
        TNode<T> *tmp=_head;

        for(;tmp->_next!=0 && vip<=tmp->_next->_vip; tmp=tmp->_next);

        tmp->_next = new TNode<T>(vlaue, tmp->_next, vip);
        if(_head==_tail) _tail=tmp->_next;
    }
}

template <class T>
T TPqueue<T>::Dequeue(void)
{
    if(_head==0)
        cout << "Empty Praiotiry Queue!!!" << endl;
    else if(_head==_tail)
    {
        delete _head;
        _head = _tail = 0;
    }
    else
    {
        TNode<T> * tmp=_head;
        _head = _head->_next;
        delete tmp;
    }
    
}



template <class T>
void TPqueue<T>::print(void)
{
    for(TNode<T>* tmp=_head; tmp!=0; tmp=tmp->_next)
        cout << tmp->_value << ", " << tmp->_vip << endl;
}


int main(void)
{
    TPqueue<int> a;

    a.Enqueue(5,2);
    a.Enqueue(5, 0);
    a.Enqueue(6,0);
    a.Enqueue(5,2);
    a.Enqueue(5,6);
    a.Enqueue(2,5);
    a.Enqueue(4,3);
    a.Enqueue(5,2);

    a.print();

    a.Dequeue();
    a.Dequeue();
    cout << endl;
    a.print();
}