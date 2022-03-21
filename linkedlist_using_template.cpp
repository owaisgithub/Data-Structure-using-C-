#include <iostream>

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
};

template <class T>
class LinkedList
{
    Node<T> * head;
    Node<T> * last;
public:
    LinkedList()
    {
        head = nullptr;
        last = nullptr;
    }

    void insertAtBegin(T item)
    {
        Node<T> * pnew = new Node<T>;

        if(head == nullptr && last == nullptr)
        {
            pnew->data = item;
            pnew->next = head;
            head = pnew;
            last = pnew;
        }
        else
        {
            pnew->data = item;
            pnew->next = head;
            head = pnew;
        }
    }

    void insertAtLast(T item)
    {
        Node<T> * pnew = new Node<T>;

        if(head == nullptr && last == nullptr)
        {
            pnew->data = item;
            pnew->next = head;
            head = pnew;
            last = pnew;
        }
        else
        {
            pnew->data = item;
            pnew->next = nullptr;
            last->next = pnew;
            last = pnew;
        }
    }

    Node<T> *  searchItem(T item)
    {
        Node<T> * p = head;
        while(p != nullptr)
        {
            if(p->data == item)
            {
                return p;    // return address of the node
            }
            else
            {
                p = p->next;
            }
        }
        return nullptr;    // search unsuccessful
    }

    void insertAtMiddle(T after_item, T item)
    {
        //Node<T> * pnew = new Node<T>;

        if(head == nullptr)
        {
            cout << "List is Empty\n";
            return;
        }

        // search the node for given value
        Node<T> * p = searchItem(after_item);

        if(p == nullptr)
        {
            cout<<"Node is not found\n";
            return;
        }

        // allocate storage for new node
        Node<T> * pnew = new Node<T>;
        pnew->data = item;
        pnew->next = p->next;
        p->next = pnew;
    }

    T firstElement()
    {
        return head->data;
    }

    T lastElement()
    {
        return last->data;
    }

    void delbeg()
    {
        if(head == nullptr)
        {
            cout<< "List is Empty!\n";
            return;
        }
        Node<T> * pdel = head;
        head = head->next;
        delete pdel;
    }

    void delend()
    {
        if(head == nullptr)
        {
            cout<<"List is Empty\n";
            return;
        }
        Node<T> * pdel = head;
        Node<T> * p;

        while(pdel->next != nullptr)
        {
            p = pdel;
            pdel = pdel->next;
        }
        p->next = nullptr;
        delete pdel;
    }

    void delmiddle(T item)
    {
        if(head == nullptr)
        {
            cout<<"List is Empty\n";
            return;
        }

        Node<T> * pdel = head;
        Node<T> * p;

        while(pdel->data != item)
        {
            p = pdel;
            pdel = pdel->next;
        }
        p->next = pdel->next;

        delete pdel;
    }

    bool isEmpty()
    {
        if(head == nullptr)
        {
            return true;
        }
        return false;
    }

    int length()
    {
        if(isEmpty())
        {
            cout<<"List is Empty\n";
            exit(0);
        }
        int c;
        Node<T> * pcount = head;
        while(pcount != nullptr)
        {
            c++;
            pcount = pcount->next;
        }
        return c;
    }

    void traverse()
    {
        if(head == nullptr)
        {
            cout<< "List is Empty!\n";
            return;
        }
        Node<T> * p = head;
        cout << "Element of list\n";
        while(p != nullptr)
        {
            cout << (p->data)<<endl;
            p = p->next;
        }
    }
};


int main()
{
    /*
    // method of linkedlist
    1.insertAtBegin()
    2.insertAtLast()
    3.insertAtMiddle()
    4.delbeg()
    5.delend()
    6.delmiddle()
    7.firstElement()
    8.lastElement()
    9.traverse()
    10.searchItem()
    11.isEmpty()
    12.length()
    */
    LinkedList<char> l;
    l.insertAtBegin('a');
    l.insertAtBegin('b');
    l.insertAtLast('c');
    l.insertAtLast('d');
    l.insertAtLast('e');
    l.insertAtBegin('f');
    l.insertAtMiddle('c', 'z');

    l.traverse();
    cout<<l.length();
    /*
    l.delbeg();
    cout<<"After delbeg:   \n";
    l.traverse();
    l.delend();
    cout<<"\nAfter delend:   \n";
    l.traverse();
    */
    //l.delmiddle('c');
    //l.traverse();
    return 0;
}
