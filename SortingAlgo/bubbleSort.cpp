#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int> &v)
{
    int n = v.size();

    for (int i = 0; i < n - 1; i++)
    {
        bool isSwap = false;
        for (int k = 0; k < n - i - 1; k++)
        {
            if (v[k] < v[k + 1])
            {
                swap(v[k], v[k + 1]);
                isSwap = true;
            }
        }
    }
}

void printArray(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << "  ";
    }
    cout << endl;
}

int main()
{
    vector<int> v1 = {5, 4, 3, 2, 1};

    bubbleSort(v1);
    printArray(v1);
}