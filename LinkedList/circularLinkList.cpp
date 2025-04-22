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

class CircularLinkedList
{
    Node *tail;

public:
    CircularLinkedList()
    {
        tail = NULL;
    }

    void insertAtHead(int data)
    {
        Node *newNode = new Node(data);
        if (tail == NULL)
        {
            tail = newNode;
            tail->nextNode = newNode;
            return;
        }
        else
        {
            newNode->nextNode = tail->nextNode;
            tail->nextNode = newNode;
            return;
        }
    }

    void insertAtTail(int data)
    {
        Node *newNode = new Node(data);
        if (tail == NULL)
        {
            tail = newNode;
            tail->nextNode = newNode;
            return;
        }
        else
        {
            newNode->nextNode = tail->nextNode;
            tail->nextNode = newNode;
            tail = newNode;
            return;
        }
    }

    void deleteAtTail()
    {
        if (tail == NULL)
        {
            cout << "List is empty \n";
            return;
        }

        if (tail == tail->nextNode)
        {
            delete tail;
            tail = NULL;
            return;
        }

        Node *temp = tail->nextNode;
        while (temp->nextNode != tail)
        {
            /* code */
            temp = temp->nextNode;
        }

        temp->nextNode=tail->nextNode;
        tail=temp;
        delete temp;
    }

    void deleteAtHead()
    {
        if (tail == NULL)
        {
            cout << "List is empty \n";
            return;
        }

        if (tail == tail->nextNode)
        {
            delete tail;
            tail = NULL;
            return;
        }

        Node *temp = tail->nextNode;
        tail->nextNode = tail->nextNode->nextNode;
        delete temp;
    }

    void display()
    {
        if (tail == NULL)
        {
            cout << "List is empty \n";
            return;
        }

        Node *temp = tail->nextNode;

        while (temp != tail)
        {
            cout << temp->data << "  ";
            temp = temp->nextNode;
        }
        cout << temp->data << endl;
    }
};

int main()
{
    CircularLinkedList *cLL = new CircularLinkedList();
    // cLL->insertAtHead(4);
    // cLL->insertAtHead(3);
    // cLL->insertAtHead(2);
    // cLL->insertAtHead(1);
    // cLL->display();

    cLL->insertAtTail(1);
    cLL->insertAtTail(2);
    // cLL->insertAtTail(3);
    // cLL->insertAtTail(4);
    // cLL->insertAtTail(5);
    // cLL->deleteAtHead();
    cLL->deleteAtTail();
    cLL->display();
}