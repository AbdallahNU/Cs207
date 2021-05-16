#include <iostream>
using namespace std;

template <class T>
class Node
{

    public:
        T _info;
        Node<T> *_next;
        Node()
        {
            _info=0;
            _next=0;
        }
        Node(const T &info, Node<T> *next=0)
        {
            _info = info;
            _next = next;
        }
};

template <class T>
class SLL
{
    public:
        SLL();
        bool isEmpty(void);
        bool isInList(T);
        void addToHead(T);
        void addToTail(T);
        void addBeforeAndAfter(Node<T>, Node<T> *);
        T deleteFromHead(void);
        T deleteFromTail(void);
        void deleteNode(T);
        void removeDuplicates(void);
        void printList(void);
    private:
        Node<T> *_head, *_tail;
};

template <class T>
SLL<T>::SLL()
{
    _head = _tail = 0;
}

template <class T>
bool SLL<T>::isEmpty(void)
{
    return !_head;
}

template <class T>
bool SLL<T>::isInList(T info)
{
    for(Node<T> *ptr = _head; ptr!=0; ptr=ptr->_next)
        if(ptr->_info==info) return true;
    return false;
}

template <class T>
void SLL<T>::printList(void)
{
    if(_head==0) cout << "Empty List!" << endl;
    else
    {
        cout << "List: ";
        Node<T> *ptr=_head;
        for(;ptr!=0; ptr=ptr->_next)
            cout << ptr->_info << " ";
        cout << endl;
    }
}

template <class T>
void SLL<T>::addToHead(T info)
{
    _head = new Node<T>(info, _head);
    if(_tail==0) _tail=_head;
}

template<class T>
void SLL<T>::addToTail(T info)
{
    if(_tail==0)
        _head = _tail = new Node<T>(info);
    else
    {
        _tail->_next = new Node<T>(info);
        _tail=_tail->_next;
    } 
}

template <class T>
T SLL<T>::deleteFromHead(void)
{
    if(this->isEmpty())
        cout << "can't delete from an empty list!" << endl;
    else
    {
        cout << "deleted: ";
        Node<T> *tmp = _head;
        T info = tmp->_info;

        if(_head==_tail)
            _head=_tail=0;
        else
            _head = _head->_next;
        delete tmp;
        return info;
    }
}

template <class T>
T SLL<T>::deleteFromTail(void)
{
    if(this->isEmpty())
        cout << "can't delete from an empty list!" << endl;
    else
    {
        cout << "deleted: ";
        Node<T> *tmp = _tail;
        T info = _tail->_info;

        if(_head==_tail)
            _head=_tail=0;
        else
        {
            for(_tail=_head; _tail->_next!=tmp; _tail=_tail->_next);
            _tail->_next=0;
        }
        delete tmp;
        return info;
    }
}

template<class T>
void SLL<T>::deleteNode(T info)
{
    if(this->isEmpty() || !this->isInList(info))
        cout << "not here" << endl;
    else
    {   
        if(_head->_info==info)
            this->deleteFromHead();
        else
        {
            Node<T> *tmp=_head;
            for(;tmp->_next->_info!=info;tmp=tmp->_next);
            Node<T> *toBeDeleted = tmp->_next;
            tmp->_next=toBeDeleted->_next;
            delete toBeDeleted;
                
        }
        cout << "deleted: " << info << endl;
    }
}

// For the Quiz 😃
template <class T>
void SLL<T>::removeDuplicates(void)
{
    for(Node<T> *tmp=_head; tmp!=_tail; tmp=tmp->_next)
    {
        int d=1;
        while (d==1)
        {     
            d=0; 
            for(Node<T> *tmp2=tmp; tmp2!=_tail; tmp2=tmp2->_next)
            {
                if(tmp->_info==tmp2->_next->_info)
                {
                    if(tmp2->_next==_tail)
                    {
                        Node<T> *toBeDeleted = tmp2->_next;
                        tmp2->_next = 0;
                        _tail = tmp2;
                        delete toBeDeleted;
                        break;
                    }
                    else
                    {
                        Node<T> *toBeDeleted = tmp2->_next;
                        tmp2->_next = tmp2->_next->_next;
                        delete toBeDeleted;
                    }
                    d=1;
                }
            }
        }
    }
}

template <class T>
void SLL<T>::addBeforeAndAfter(Node<T> newNode, Node<T> *p)
{
    if(_head==0)
        cout << "Empty list!" << endl;
    else
    {    
        T pInfo = p->_info;
        p->_info = newNode._info;
        p->_next = new Node<T>(pInfo, p->_next);
        p->_next->_next = new Node<T>(newNode._info, p->_next->_next);
        if(p->_next->_next->_next==0) _tail = p->_next->_next;
    }
}


int main(void)
{
    SLL<int> a;
    a.addToHead(13);
    a.addToTail(11);
    a.addToTail(11);
    a.addToTail(11);
    a.addToTail(13);
    a.addToTail(13);
    a.addToTail(13);
    a.addToTail(19);
    a.addToTail(13);
    a.printList();
    a.removeDuplicates();
    a.printList();
    

    return 0;
}