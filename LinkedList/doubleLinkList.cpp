#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        next = prev = NULL;
    }
};

class DoubleLinkList
{
    Node *head;
    Node *tail;

public:
    DoubleLinkList()
    {
        head = tail = NULL;
    }
    void pushFront(int data)
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
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            return;
        }
    }

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
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
            return;
        }
    }

    void popFront()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        if (head == tail)
        {
            delete head;
            head = tail = NULL;
        }

        Node *temp = head;
        head = head->next;
        head->prev == NULL;
        delete temp;
        return;
    }

    void popBack()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        if (head == tail)
        {
            delete head;
            head = tail = NULL;
            return;
        }

        Node *temp = tail;
        tail = tail->prev;
        delete temp;
        tail->next = NULL;
    }
};

int main()
{
}