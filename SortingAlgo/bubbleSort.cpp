#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int> &v)
{
    int n = v.size();

    for (int i = 0; i < n - 1; i++)
    {
        bool isSwap = false; // agr is swap inner waly loop mein true nhi hua to array sorted hy koi swapping nhi hui 

        for (int j = 0; j < n - i - 1; j++)
        {
            if (v[j] > v[j + 1])
            {
                swap(v[j], v[j + 1]);
                isSwap = true;
            }
        }

        if(!isSwap){
            return;
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