#include <iostream>
#include <stdlib.h>

using namespace std;

template <class T>
class Node
{
public:
    T data;
    Node * next;

    // default contructor
    Node()
    {
        data = 0;
        next = nullptr;
    }

    // parameterized contructor
    /*
    Node(T data)
    {
        this->data = data;
        this->next = nullptr;
    }
    */
};

template <class T>
class Stack
{
    Node<T> * top;
    //Node * last;
public:
    Stack()
    {
        top = nullptr;
    }

    void push(T item)
    {
        Node<T> * pnew = new Node<T>;
        pnew->data = item;
        pnew->next = top;
        top = pnew;
    }

    void pop()
    {
        if(top == nullptr)
        {
            cout<<"Stack is Empty!\n";
            return;
        }
        Node<T> * p = top;
        top = top->next;
        p->next = nullptr;
        delete p;
    }

    bool isEmpty()
    {
        if(top == nullptr)
        {
            return true;
        }

        return false;
    }

    T peek()
    {
        if(!isEmpty())
        {
            return top->data;
        }
        else
        {
            cout<<"Stack is Empty";
            exit(1);
        }
    }

    int length()
    {
        if(isEmpty())
        {
            return 0;
        }
        Node<T> * p = top;
        int c=0;
        while(p != nullptr)
        {
            c++;
            p = p->next;
        }
        return c;
    }

    void traverse()
    {
        if(isEmpty())
        {
            cout<< "Stack is Empty!\n";
            return;
        }
        else
        {
            Node<T> * p = top;
            cout << "Element in Stack\n";
            while(p != nullptr)
            {
                cout << (p->data)<<endl;
                p = p->next;
            }
        }
    }
};


int main()
{
    /*
    Stack methods
    1.push(item)
    2.pop()
    3.peek()
    4.isEmpty()
    5.traverse()
    6.length()
    */
    Stack<double> s;

    s.push(12.3);
    s.push(12 );
    s.push(89.00);
    s.push(87.34474);
    s.push(8.009);

    s.traverse();
    cout<<s.length();

    //cout<<s.peek()<<endl;



    //l.insertAtMiddle(48, 86);
    //l.traverse();
    //Node * p;
    //p = l.firstElement();

    //cout<<"DATA:   " <<p->data<<"    ADDRESS:    "<<p<<endl;

    //Node * q = l.lastElement();
    //cout<<"DATA:  " <<q->data<< "     ADDRESS:  "<<q<<endl;
    return 0;
}
