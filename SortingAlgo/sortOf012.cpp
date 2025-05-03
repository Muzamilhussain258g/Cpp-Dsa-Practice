// in this question we sort the array [2,0,2,1,1,0,1,2,0,0]

#include <iostream>
#include <vector>

using namespace std;

void sort012s(vector<int> &v)
{
    int zeros = 0, ones = 0, twos = 0;

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == 0)
        {
            zeros++;
        }
        else if (v[i] == 1)
        {
            ones++;
        }
        else if (v[i] == 2)
        {
            twos++;
        }
    }

    int idx = 0;
    for (int i = 0; i < zeros; i++)
    {
        v[idx++] = 0;
    }
    for (int i = 0; i < ones; i++)
    {
        v[idx++] = 1;
    }
    for (int i = 0; i < twos; i++)
    {
        v[idx++] = 2;
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
    vector<int> v = {2, 0, 2, 1, 1, 0, 1, 2, 0, 0};
    sort012s(v);
    printArray(v);
}