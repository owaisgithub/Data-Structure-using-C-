#include <iostream>
#define n 20

using namespace std;

template <class T>
class Stack
{
    int top;
    T arr[n];

public:
    Stack()
    {
        top = -1;
    }

    void push(T item)
    {
        if(top == (n-1))
        {
            cout<<"Stack is full\n";
            return;
        }
        top = top + 1;
        arr[top] = item;
    }

    T pop()
    {
        T item;
        if(top == -1)
        {
            cout<<"Stack is Empty\n";
        }
        item = arr[top];
        top = top - 1;
        return item;
    }

    bool isFull()
    {
        if(top == (n-1))
            return true;
        return false;
    }

    bool isEmpty()
    {
        if(top == -1)
            return true;
        return false;
    }

    T peek()
    {
        if(top == -1)
        {
            cout<<"Stack is Empty\n";
            return 0;
        }

        //T item =
        return arr[top];
    }

    void traverse()
    {
        if(top == -1)
        {
            cout<<"Stack is Empty\n";
        }
        else
        {
            cout<<"\nContent of Stack:\n";
            for(int i=top; i>=0; i--)
                cout<<arr[i]<<endl;

            cout<<endl;
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
    5.isFull()
    6.traverse()
    */

    Stack<char> s;
    s.push('a');
    s.push('z');
    s.push('r');
    s.push('b');
    s.traverse();
    return 0;
}
