// applying merge sort using recursion

#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &a, int start, int mid, int end)
{
    vector<int> temp;
    int i = start, j = mid + 1;

    while (i <= mid && j <= end)
    {
        if (a[i] <= a[j])
        {
            temp.push_back(a[i]);
            i++;
        }
        else
        {
            temp.push_back(a[j]);
            j++;
        }
    }

    while (i <= mid)
    {
        temp.push_back(a[i]);
        i++;
    }

    while (j <= end)
    {
        temp.push_back(a[j]);
        j++;
    }

    // changing in original array

    for (int idx = 0; idx < temp.size(); idx++)
    {
        a[idx + start] = temp[idx];
    }
}

void mergeSort(vector<int> &a, int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;

        /* for divide the remaining left array*/
        mergeSort(a, start, mid);

        /* for divide the remaining right array*/
        mergeSort(a, mid + 1, end);

        /* for merge and put the element on the correct position*/
        merge(a,start,mid,end);
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
    vector<int> arr = {12, 31, 35, 8, 32, 17};
    mergeSort(arr ,0 ,arr.size()-1);
    printArray(arr);
}