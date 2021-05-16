#include <iostream>
using namespace std;


template <class T>
class Node
{
    public:
        T _info; Node<T> *_next, *_prev;
        Node()
        {
            _next = _prev = 0;
        }
        Node(const T& info, Node<T> *next=0, Node<T> *prev=0)
        {
            _info = info; _next = next; _prev = prev;
        }
};

template<class T>
class DLL
{
    private:
        Node<T> *_head, *_tail;
    public:
        DLL();
        void addToHead(T);
        void addToTail(T);
        T deleteFromHead(void);
        T deleteFromTail(void);
        void printList(short reversed=0);
        void clear(void);
        bool isEmpty(void);
};

template<class T>
DLL<T>::DLL()
{
    _head = _tail = 0;
}

template<class T>
void DLL<T>::printList(short reversed)
{
    if(_head==0)
        cout << "Empty List!" << endl;
    else
    {
        Node<T> *tmp;
        cout << "List: ";
        if(reversed==-1)
        {
            for(tmp=_tail; tmp!=0; tmp=tmp->_prev)
                cout << tmp->_info << " ";
        }
        else
        {
            for(tmp=_head; tmp!=0; tmp=tmp->_next)
                cout << tmp->_info << " ";
        }
        cout << endl;
    }
}

template <class T>
void DLL<T>::addToHead(T info)
{
    if(_head==0)
        _head = _tail = new Node<T>(info);
    else
    {
        _head = new Node<T>(info, _head);
        _head->_next->_prev = _head;
    }
}

template <class T>
void DLL<T>::addToTail(T info)
{
    if(_tail==0)
        _head = _tail = new Node<T>(info);
    else
    {
        _tail = new Node<T>(info, 0, _tail);
        _tail->_prev->_next = _tail;
    }
}

template <class T>
T DLL<T>::deleteFromHead(void)
{
    if(_head==0)
        cout << "Can't delete from an empty list!!" << endl;
    else
    {
        Node<T> *tmp = _head;
        T info = _head->_info;

        if(_head==_tail)
            _head = _tail = 0;
        else
        {
            _head = _head->_next;
            _head->_prev=0;
            delete tmp;
        }
        return info;
    }
}

template <class T>
T DLL<T>::deleteFromTail(void)
{
    if(_head==0)
        cout << "Can't delete from an empty list!!" << endl;
    else
    {
        Node<T> *tmp = _tail;
        T info = _tail->_info;

        if(_head==_tail)
            _head = _tail = 0;
        else
        {
            _tail = _tail->_prev;
            _tail->_next = 0;
        }
        return info;
    }
}

template <class T>
void DLL<T>::clear(void)
{
    if(_head==0)
        cout << "Already Cleared!" << endl;
    else
    {
        if(_head==_tail)
        {
            delete _head;
        }
        else
        {
            Node<T> *tmp=_head->_next;
            for(;tmp!=0;tmp=tmp->_next)
                delete tmp->_prev;
            delete _tail;
        }
        _head=_tail=0;
    }
}

template <class T>
bool DLL<T>::isEmpty(void)
{
    return !_head;
}

// int main(void)
// {
//     DLL<string> s;
//     s.addToHead("Wells");
//     s.addToTail("Zoom");
//     s.addToHead("Harry");
//     cout << s.isEmpty() << endl;
//     s.printList();
//     s.clear();
//     s.printList();
//     cout << s.isEmpty() << endl;

//     return 0;
// }