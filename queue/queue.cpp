// this is a simple implementation of queue from scratch using array

// #include <iostream>
// #include <vector>
// using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *next;

//     Node(int data)
//     {
//         this->data = data;
//         this->next = NULL;
//     }
// };

// class Queue
// {
//     Node *front, *rear;

// public:
//     Queue()
//     {
//         front = NULL;
//         rear = NULL;
//     }

//     void pushAtBack(int data)
//     {
//         Node *newNode = new Node(data);
//         if (front == NULL)
//         {
//             front = newNode;
//             rear = newNode;
//         }
//         else
//         {
//             rear->next = newNode;
//             rear = newNode;
//         }
//     }

//     void popAtFront()
//     { // in the queue the element can be popped from front only
//         if (front == NULL)
//         {
//             cout << "Queue is empty \n";
//             return;
//         }

//         if (front == rear)
//         {
//             delete front;
//             front = rear = NULL;
//         }
//         else
//         {
//             Node *temp = front;
//             front = front->next;
//             delete temp;
//         }
//     }

//     void giveFront()
//     {

//         if (front == NULL)
//         {
//             cout << "Queue is empty \n";
//             return;
//         }
//         cout << "the front element is : " << front->data << endl;
//     }

//     void printQueue()
//     {
//         if (front == NULL)
//         {
//             cout << "Queue is empty \n";
//             return;
//         }

//         Node *temp = front;
//         cout << "front -> ";

//         while (temp != NULL)
//         {
//             cout << temp->data << " -> ";
//             temp = temp->next;
//         }
//         cout << "<- rear" << endl;
//     }
// };

// int main()
// {
//     Queue *q = new Queue();
//     q->pushAtBack(10);
//     q->pushAtBack(20);
//     q->pushAtBack(30);
//     q->pushAtBack(40);
//     q->pushAtBack(50);
//     q->popAtFront();
//     q->printQueue();
// }

// the end

// this is the implementation of queue using stl

// #include <iostream>
// #include <queue>

// using namespace std;

// int main()
// {
//     queue<int> q1;

//     q1.push(1);
//     q1.push(2);
//     q1.push(3);
//     q1.push(4);
//     q1.push(5);
//     q1.pop();

//     while (!q1.empty()){
//         cout<<q1.front()<<" -> ";
//         q1.pop();
//     }
// }

// the end