#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class CicularQueue
{
    int *arr;
    int currSize = 0 , capacity;
    int f = 0, r = -1;

public:
    CicularQueue(int size)
    {
        capacity = size;
        arr = new int[size];
    }

    void pushAtBack(int data)
    {
        if (currSize == capacity)
        {
            cout << "circular queue is full \n";
            return;
        }
        r = (r + 1) % capacity;
        arr[r] = data;
        currSize++;
    }

    void popAtBack()
    {
        if (capacity == 0)
        {
            cout << "Circular queue is empty \n";
            return;
        }

        f = (f + 1) % capacity;
        currSize--;
    }

    int giveFront()
    {
        return arr[f];
    }

    bool isEmpty()
    {
        return currSize == 0;
    }

    void printCircularQueue()
    {
        int temp = f;
        while (temp != r)
        {
            cout << arr[temp] << " ->";
            temp = (temp + 1) % capacity;
        }
        cout << arr[temp] << " ->" << endl;
    }
};

int main()
{
    CicularQueue *cq1 = new CicularQueue(3);
    cq1->pushAtBack(1);
    cq1->pushAtBack(2);
    cq1->pushAtBack(3);
    cq1->printCircularQueue();
}
