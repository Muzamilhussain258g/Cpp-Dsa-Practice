#include <iostream>
#include <vector>

using namespace std;

void selectionSort(vector<int> &v)
{
    // [ 4, 1, 5, 2, 3 ]

    for (int i = 1; i < v.size(); i++)
    {
        int curr = v[i];
        int prev = i - 1;

        while (prev >= 0 && v[prev] > curr)
        {
            v[prev + 1] = v[prev];
            prev--;
        }

        v[prev + 1] = curr;
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
    vector<int> v2 = {5, 4, 3, 1, 2};
    selectionSort(v2);
    printArray(v2);
}