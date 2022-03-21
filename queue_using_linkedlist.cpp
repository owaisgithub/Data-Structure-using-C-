#include <iostream>

using namespace std;

template<class T>
class Node
{
public:
    T data;
    Node * next;

    Node()
    {
        data = 0;
        next = nullptr;
    }
};

template<class T>
class Queue
{
    Node<T> * front;
    Node<T> * rear;
public:
    Queue()
    {
        front = nullptr;
        rear = nullptr;
    }

    bool isEmpty()
    {
        if(rear == nullptr)
            return true;
        return false;
    }

    void push(T item)
    {
        Node<T> * pnew = new Node<T>;
        if(rear == nullptr)
        {
            pnew->data = item;
            pnew->next = nullptr;
            front = pnew;
            rear = pnew;
            return;
        }

        pnew->data = item;
        pnew->next = nullptr;
        rear->next = pnew;
        rear = rear->next;
        return;
    }

    void pop()
    {
        if(isEmpty())
        {
            cout<<"Queue is Empty\n";
            return;
        }
        Node<T> * pdel = front;
        if(front == rear)
        {
            front = rear = nullptr;
        }
        else
        {
            front = front->next;
        }
        delete pdel;
    }

    int length()
    {
        if(isEmpty())
        {
            return 0;
        }
        Node<T> * p = front;
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
            cout<<"Queue is Empty\n";
            return;
        }

        Node<T> * p = front;
        while(p != nullptr)
        {
            cout<<p->data<< " ";
            p = p->next;
        }
    }
};



int main()
{
    Queue<int> q;
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.traverse();

    cout<<q.length();
}
