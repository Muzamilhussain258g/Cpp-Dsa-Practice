#include <iostream>
#include <vector>

using namespace std;
class MaxHeap
{
    int *arr;
    int size;
    int total_size;

public:
    MaxHeap(int n)
    {
        arr = new int[n];
        size = 0;
        total_size = n;
    };

    void insertIntoHeap(int val)
    {
        if (size == total_size)
        {
            cout << "Heap Overflow \n";
            return;
        }

        arr[size] = val;
        int index = size;
        size++;

        // compare it with its parent
        while (index > 0 && arr[(index - 1) / 2] < arr[index])
        {
            swap(arr[(index - 1) / 2], arr[index]);
            index = (index - 1) / 2;
        }
    }

    void Heapify(int index)
    {
        int largest = index; // store the index of largest element
        int left = (2 * index) + 1;
        int right = (2 * index) + 2;

        if (left < size && arr[left] > arr[index])
        {
            largest = left;
        }
        if (right < size && arr[right] > arr[index])
        {
            largest = right;
        }

        if (largest != index)
        {
            swap(arr[index], arr[largest]);
            Heapify(largest);
        }
    }

    void deleteNode()
    {
        if (size == 0)
        {
            cout << "Heap under flow !";
            return;
        }

        cout << arr[0] << "delete from the heap !" << endl;

        arr[0] = arr[size - 1];
        size--;

        if (size == 0)
        {
            return;
        }

        Heapify(0);
    }

    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << "    ";
        }
    }
};

int main()
{
    MaxHeap heap(10);
    heap.insertIntoHeap(20);
    heap.insertIntoHeap(15);
    heap.insertIntoHeap(30);
    heap.insertIntoHeap(5);
    heap.print(); // Output should be a valid MaxHeap (root at index 0)
}