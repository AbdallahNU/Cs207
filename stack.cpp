#include <iostream>
#include "dll.cpp"
using namespace std;


template <class T>
class Stack
{
    private:
        DLL<T> list;
    public:
        Stack(){}
        void push(T);
        T pop(void);
        T topEl(void);
        void clear(void);
        bool isEmpty(void);
        void printStack(void);
};

template <class T>
void Stack<T>::push(T info)
{
    list.addToHead(info);
}

template <class T>
T Stack<T>::pop(void)
{
    return list.deleteFromHead();
}

template <class T>
T Stack<T>::topEl(void)
{
    T el = list.deleteFromHead();
    list.addToHead(el);
    return el;
}

template <class T>
void Stack<T>::clear(void)
{
    list.clear();
}

template <class T>
bool Stack<T>::isEmpty(void)
{
    return list.isEmpty();
}

template <class T>
void Stack<T>::printStack(void)
{
    list.printList();
}

int main(void)
{
    Stack<int> a;
    cout << "Empty? " << a.isEmpty() << endl;
    a.push(1);
    cout << "Empty? " << a.isEmpty() << endl;
    a.push(2);
    a.push(3);
    a.printStack();
    a.pop();
    cout << a.topEl() << endl;
    a.clear();
    cout << "Empty? " << a.isEmpty() << endl;

    return 0;
}