#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node * next;
};

class linkedlist   // class to represent the binary tree
{
    Node * head;
    public:
        linkedlist()
        {
            head = nullptr;
        }
        void insertatbegin(int item);
        void insertatend(int item);
        Node * searchitem(int item);
        void insertaftervalue(int item, int after);
        void delbeg();
        void delend();
        void delhavingvalue(int item);
        void traverse();
        ~linkedlist();    // set head = NULL and deletes all nodes
};

void linkedlist::insertatbegin(int item)
{
    Node * pnew = new Node;   // allocate storage for the new node
    pnew->data = item;
    pnew->next = head;
    head = pnew;
}

void linkedlist::insertatend(int item)
{
    Node * pnew = new Node;    // allocate storage for the new node
    pnew->data = item;
    pnew->next =nullptr;

    // if list is empty , insert new node as 1st node
    if(head == nullptr)
    {
        head = pnew;
    }
    else    // obtain address of the last node and insert the new node
    {
        Node * p = head;
        while(p->next != nullptr)
        {
            p = p->next;
        }
        p->next = pnew;     // insert after the last node
    }
}

Node *  linkedlist::searchitem(int item)
{
    Node * p = head;
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

void linkedlist::insertaftervalue(int item, int after)
{
    if(head == nullptr)
    {
        cout << "List Empty : Insertion Not found\n";
        return;
    }

    // Search the node with given value
    Node * p = searchitem(after);

    if(p==nullptr)
    {
        cout << "Node is not found!\n";
        return;
    }
    // allocate storage for the new node
    Node * pnew = new Node;
    pnew->data = item;
    pnew->next = p->next;
    p->next = pnew;
}

void linkedlist::delbeg()
{
    if(head == nullptr)
    {
        cout<< "List is Empty!\n";
        return;
    }
    Node *pdel = head;
    head = head->next;
    delete pdel;
}

void linkedlist::delend()
{
    if(head == nullptr)
    {
        cout<< "List is empty!\n";
        return;
    }
    Node *p = head;
    Node *p1;
    while(p->next != nullptr)
    {
        p1 = p;
        p = p->next;
    }
    p1->next = nullptr;
    delete p;
}


void linkedlist::traverse()
{
    if(head == nullptr)
    {
        cout<< "List is Empty!\n";
        return;
    }
    Node * p = head;
    cout << "Element of list\n";
    while(p != nullptr)
    {
        cout << (p->data)<<endl;
        p = p->next;
    }
}

linkedlist::~linkedlist()
{
    Node * p = head;
    Node * ps;
    head = nullptr;
    while(p!=nullptr)
    {
        ps = p->next;    // ps is pointer to the successor of the node pointed to by p
        delete p;
        p = ps;
    }
}

int main()
{
    linkedlist list1;
    list1.insertatbegin(120);
    list1.insertatend(1201);
    list1.insertatend(121);
    list1.insertatbegin(11);
    //list1.insertaftervalue(12, 1201);
    list1.traverse();
    cout << "After Deletion\n";
    //list1.delbeg();
    list1.delend();
    list1.traverse();
}
