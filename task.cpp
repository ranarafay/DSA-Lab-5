#include <iostream>
using namespace std;

class Node
{
private:
    int Data;
    Node *Next;

public:
    // constructor
    Node();

    // setters
    void setData(int);
    void setNext(Node *);
    // getters
    int getData();
    Node *getNext();
};
// fuctions for class Node
// constructor
Node ::Node()
{
    Data = 0;
    Next = NULL;
}
// setters
void Node ::setData(int x)
{
    Data = x;
}
void Node ::setNext(Node *ptr)
{
    Next = ptr;
}
// getters
int Node ::getData()
{
    return Data;
}
Node *Node ::getNext()
{
    return Next;
}

// class LinkedList
class LinkedList
{
    // private
    Node *Head;

public:


    // constructor
    LinkedList();

    // setter
    void setVal(int, int);
    // getter
    void getVal(int);

    // functions
    void Insert(int);
    void Display();
    void InsertAtFirst(int);
    void InsertAtLast(int);
    void InsertAfter(int, int);
    void DeleteAtStart();
    void DeleteAtEnd();
    void DeleteNode(int);
    void DeleteAtValue(int);

    // destructor
    ~LinkedList();
};
// fucntions for class LinkedList
// constructor
LinkedList ::LinkedList()
{
    Head = NULL;
}
// setter
void LinkedList ::setVal(int val, int ind)
{
    if (Head == NULL)
    {
        cout << "List is Empty!" << endl;
    }

    else
    {
        int cnt = 0;

        Node *temp;
        temp = Head;
        while (temp || cnt == ind)
        {
            cnt++;
        }

        if (cnt == ind)
        {
            temp->setData(val);
        }

        else
        {
            cout << "Index Out of bound!" << endl;
        }
    }
}
// getter
void LinkedList ::getVal(int ind)
{
    if (Head == NULL)
    {
        cout << "List is Empty!" << endl;
    }

    else
    {
        int cnt = 0;

        Node *temp;
        temp = Head;
        while (temp || cnt == ind)
        {
            cnt++;
        }

        if (cnt == ind)
        {
            cout << temp->getNext() << endl;
        }

        else
        {
            cout << "Index Out of bound!" << endl;
        }
    }
}
// functions
void LinkedList ::Display()
{
    if (Head == NULL)
    {
        cout << "List is Empty!" << endl;
    }

    else
    {
        Node *temp;
        temp = Head;
        while (temp)
        {
            cout << temp->getData() << " ";
            temp = temp->getNext();
        }
    }
}
void LinkedList ::Insert(int x)
{
    Node *newnode = new Node;
    newnode->setData(x);

    if (Head == NULL)
    {
        Head = newnode;
    }
    else
    {
        Node *temp;
        temp = Head;
        while (temp->getNext() != NULL)
        {
            temp = temp->getNext();
        }
        temp->setNext(newnode);
    }
}
void LinkedList ::InsertAtFirst(int x)
{
    Node *newnode = new Node;
    newnode->setData(x);

    if (Head == NULL)
    {
        Head = newnode;
    }
    else
    {
        newnode->setNext(Head);
        Head = newnode;
    }
}
void LinkedList ::InsertAtLast(int x)
{
    Node *newnode = new Node;
    newnode->setData(x);

    if (Head == NULL)
    {
        Head = newnode;
    }
    else
    {
        Node *temp;
        temp = Head;
        while (temp->getNext() != NULL)
        {
            temp = temp->getNext();
        }
        temp->setNext(newnode);
    }
}
void LinkedList ::InsertAfter(int dv, int vtbi)
{
    Node *temp;
    temp = Head;

    bool chk;
    while (temp)
    {
        if (temp->getData() == dv)
        {
            chk = true;
            break;
        }
        temp = temp->getNext();
    }

    if (chk == true)
    {
        Node *newnode = new Node;
        newnode->setData(vtbi);
        newnode->setNext(temp->getNext());
        temp->setNext(newnode);
    }
    else
    {
        cout << "Data Value not found!" << endl;
    }
}
void LinkedList ::DeleteAtStart()
{
    if (Head == NULL)
    {
        cout << "List is Empty Already!" << endl;
    }

    else
    {
        Node *temp;
        temp = Head;

        Head = temp->getNext();

        delete temp;
    }
}
void LinkedList ::DeleteAtEnd()
{
    if (Head == NULL)
    {
        cout << "List is Empty Already!" << endl;
    }

    else
    {
        Node *temp, *prev;
        temp = Head;

        while (temp)
        {
            prev = temp;
            temp = temp->getNext();
        }

        prev->setNext(NULL);
        delete temp;
    }
}
void LinkedList :: DeleteAtValue(int val)
{
    bool a;
    Node *temp;
    Node *prev;
    temp = Head;
    if (temp == NULL)
    {
        cout << "Linked list is empty." << endl;
        a = false;
    }
    else
    {
        while (temp != NULL)
        {
            prev = temp;
            temp = temp->getNext();
            if (prev->getData() == val)
            {
                Node *del;
                del = prev;
                prev = prev->getNext();
                delete del;
            }
            else if (temp->getData() == val)
            {
                Node *del;
                del = temp;
                temp = temp->getNext();
                delete del;
            }
        }
    }
}
// destructor
LinkedList ::~LinkedList()
{
    Node *temp;
    temp = Head;

    while (temp)
    {
        Node *prev;
        prev = temp;

        temp = temp->getNext();
        delete prev;
    }
    Head = NULL;
}


int main()
{
    LinkedList l1;
    l1.Insert(5);
    l1.Insert(10);
    l1.Insert(20);
    l1.Display();


    return 0;
}