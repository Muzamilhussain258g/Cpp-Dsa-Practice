#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &v, int st, int end)
{
    int idx = st - 1, pivot = v[end];

    for (int j = st; j < end; j++)
    {
        if (v[j] <= pivot){
            idx++;
            swap(v[idx],v[j]);
        }
    }
    
    idx++;
    swap(v[end],v[idx]);

    return idx;
}

void quickSort(vector<int> &v, int st, int end)
{
    if (st < end)
    {
        int pivotIndex = partition(v, st, end);

        // for left half
        quickSort(v, st, pivotIndex - 1);

        // for right half
        quickSort(v, pivotIndex + 1, end);
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
    vector<int> v = {12, 31, 35, 8, 32, 17};

    quickSort(v,0,v.size()-1);
    printArray(v);
}