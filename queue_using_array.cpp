#include <iostream>
#define n 10

using namespace std;

template <class T>
class Queue
{
    int front, rear;
    T arr[n];

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }

    bool isEmpty()
    {
        if(front == -1)
            return true;
        return false;
    }

    bool isFull()
    {
        if(rear == n-1)
            return true;
        return false;
    }

    void insert(T item)
    {
        if(isFull())
        {
            cout<<"Queue is Full\n";
            return;
        }
        else if(rear == -1)
            front = rear = 0;
        else
            rear = rear + 1;

        arr[rear] = item;
        return;
    }

    T remove()
    {
        T item;
        if(isEmpty())
        {
            cout<<"Queue is Empty\n";
            exit(0);
        }
        item = arr[front];
        if(front == rear)
            front = rear = -1;
        else
            front = front + 1;
        return item;
    }

    void traverse()
    {
        if(isEmpty())
        {
            cout<<"Queue is Empty\n";
            return;
        }
        for(int i=front; i<=rear; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main()
{
    Queue<int> q;
    q.insert(12);
    q.insert(13);
    q.insert(14);
    q.insert(15);
    q.remove();
    q.traverse();
}
