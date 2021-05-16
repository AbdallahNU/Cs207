#include <iostream>
#include "dll.cpp"
using namespace std;

template <class T>
class CDLL
{
    private:
        Node<T> *_current;
    public:
        CDLL(){_current=0;}
        void addToCurrent(const T&);
        T deleteFromCurrent();
        void deleteItem(const T&);
        void print(void);
};

template<class T>
void CDLL<T>::addToCurrent(const T& item)
{
    if(_current==0)
    {
        _current = new Node<T>(item);
        _current->_next = _current->_prev = _current;
    }
    else
    {
        _current = new Node<T>(item, _current->_next, _current);
        _current->_prev->_next = _current;
        _current->_next->_prev = _current;
    }
}

template <class T>
T CDLL<T>::deleteFromCurrent()
{
    if(_current==0)
        cout << "Can't delete from an ampty list!!" << endl;
    else if(_current->_next==_current)
    {
        delete _current;
        _current = 0;
    }
    else
    {
        Node<T> *tmp = _current;
        T item = _current->_info;
        _current->_prev->_next = _current->_next;
        _current->_next->_prev = _current->_prev;
        _current = _current->_prev;
        delete tmp;
        return item;
    }
}

template <class T>
void CDLL<T>::print(void)
{
    if(_current==0)
        cout << "Empty list!" << endl;
    else if(_current->_next==_current)
        cout << _current->_info<< " " << endl;
    else
    {
        Node<T>*tmp;
        for(tmp=_current; tmp->_next!=_current; tmp=tmp->_next)
            cout << tmp->_info << " ";
        cout << tmp->_info << endl;
    }
}

int main(void)
{
    CDLL<int> a;
    a.print();
    a.addToCurrent(3);
    a.print();
    a.addToCurrent(4);
    a.print();

    return 0;
}