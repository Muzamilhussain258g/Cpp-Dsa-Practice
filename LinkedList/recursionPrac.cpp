#include <iostream>
#include <vector>

using namespace std;

void printNum(int num)
{
    if (num != 0)
    {
        cout << num << "    ";
        printNum(num - 1);
    }
};

int fib(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fib(n - 1) + fib(n - 2);
}

void printFib(int num)
{

    for (int i = 0; i < num; i++)
    {
        cout << fib(i) << " ";
    }
}

int sum(int n)
{
    if (n == 0)
        return 0;
    return n + sum(n - 1);
}

bool isArraySorted(vector<int> arr, int length)
{
    if (length == 1)
    {
        return true;
    }
    if (arr[length - 1] >= arr[length - 2])
    {
        return isArraySorted(arr, length - 1);
    }
    else{
        return false;
    }
}

int main()
{
    // printNum(5);
    // printFib(9);
    // cout << endl
    //      << sum(1);

    vector<int> arr1 = {1,23,3,4};
    cout<<isArraySorted(arr1,arr1.size());
}