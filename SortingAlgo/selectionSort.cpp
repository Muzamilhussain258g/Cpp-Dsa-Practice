#include <iostream>
#include <vector>

using namespace std;

void selectionSort(vector<int> &v)
{
    int n = v.size();

    for (int i = 0; i < n - 1; i++)
    {
        int smallestIdx = i;
        for (int j = i+1; j < n; j++)
        {
            if (v[smallestIdx]>v[j]){
                smallestIdx = j;
            }
        }
        swap(v[i],v[smallestIdx]);
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
    selectionSort(v1);
    printArray(v1);
}