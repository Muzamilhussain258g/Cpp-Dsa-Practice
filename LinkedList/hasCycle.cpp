#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *nextNode;

    Node(int data)
    {
        this->data = data;
        this->nextNode = NULL;
    }
};

class LL
{
    Node *head = NULL;
    Node *tail = NULL;

public:
    void pushBack(int data)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        else
        {
            tail->nextNode = newNode;
            tail = newNode;
        }
    }
};

int main()
{
    LL* linkedList1 = new LL(); 
    linkedList1->pushBack(1);
    linkedList1->pushBack(2);
    linkedList1->pushBack(3);
    linkedList1->pushBack(4);
    linkedList1->pushBack(5);
}