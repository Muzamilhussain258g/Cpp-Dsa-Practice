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

class LinkedList
{
public:
    Node *head = NULL;
    Node *tail = NULL;

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
            newNode->nextNode = head;
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
            tail->nextNode = newNode;
            tail = newNode;
        }
    }

    void popFront()
    {
        if (head == NULL)
        {
            cout << "List is empty \n";
            return;
        }

        if (head == tail)
        {
            delete head;
            head = tail = NULL;
            return;
        }

        Node *temp = head;
        head = head->nextNode;
        delete temp;
        return;
    }

    void popBack()
    {
        if (head == NULL)
        {
            cout << "List is empty \n";
            return;
        }

        if (head == tail)
        {
            delete head;
            head = tail = NULL;
            return;
        }

        Node *temp = head;
        while (temp->nextNode->nextNode != NULL)
        {
            temp = temp->nextNode;
        }
        delete temp->nextNode;
        temp->nextNode = NULL;
        tail = temp;
        return;
    }

    void insertAt(int pos, int data)
    {
        if (pos < 0)
        {
            cout << "Invalid Position \n";
            return;
        }
        if (pos == 0)
        {
            pushFront(data);
            return;
        }

        Node *temp = head;
        for (int i = 0; i < pos - 1; i++)
        {
            if (temp == NULL)
            {
                cout << "Invalid position \n";
                return;
            }
            temp = temp->nextNode;
        }
        Node *newNode = new Node(data);
        newNode->nextNode = temp->nextNode;
        temp->nextNode = newNode;
        return;
    }

    void deleteAt(int pos)
    {
        if (pos < 0)
        {
            cout << "Invalid position \n";
            return;
        }
        if (pos == 0)
        {
            popFront();
            return;
        }
        Node *temp = head;
        for (int i = 0; i < pos - 1; i++)
        {
            if (temp == NULL)
            {
                cout << "Invalid Position \n";
            }
            temp = temp->nextNode;
        }
        if (temp->nextNode == tail)
        {
            popBack();
            return;
        }
        Node *toDelete = temp->nextNode;
        temp->nextNode = toDelete->nextNode;
        delete toDelete;
    }

    void middle()
    {
        Node *slow = head;
        Node *fast = head;

        while (fast != NULL && fast->nextNode != NULL)
        {
            slow = slow->nextNode;
            fast = fast->nextNode->nextNode;
        }
        cout << "Middle of the linked list is :" << slow->data << endl;
    }

    void display()
    {
        Node *temp = head;
        if (temp != NULL)
        {
            cout << "LinkedList Items : ";
            while (temp != NULL)
            {
                /* code */
                cout << temp->data << "->";
                temp = temp->nextNode;
            }
            cout << "NULL" << endl;
        }
        else
        {
            cout << "The list is empty." << endl;
        }
    }
};

void swapTwoNodes(LinkedList &ll, int val1, int val2)
{
    if (val1 == val2)
    {
        return;
    }

    Node *temp1 = ll.head;
    while (temp1 != NULL)
    {
        if (temp1->nextNode->data == val1)
        {
            break;
        }
        temp1= temp1->nextNode;
    }
}

int main()
{
    LinkedList *linkList1 = new LinkedList();
    linkList1->pushBack(1);
    linkList1->pushBack(2);
    linkList1->pushBack(3);
    linkList1->pushBack(4);
    linkList1->pushBack(5);
}