/*BINARY SEARCH USING WHILE LOOP AND USING REURSION ALSO DONE */

#include <iostream>
#include <vector>

using namespace std;

bool binarySearch(int left, int right, int toSearch, const vector<int> &arr)
{
    if (left > right)
    {
        return false;
    }

    int mid = (left + right) / 2;

    if (arr[mid] == toSearch)
    {
        return true;
    }

    if (toSearch > arr[mid])
    {
        return binarySearch(mid + 1, right, toSearch, arr);
    }
    else
    {
        return binarySearch(left, mid - 1, toSearch, arr);
    }
}

int main()
{
    /*BINARY SEARCH USING WHILE LOOP*/

    // vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    // int inp;
    // cout << "Enter the number from 1 to 9\n";
    // cin >> inp;

    // int left = 0;
    // int right = v1.size() - 1;

    // string flag = "the number is not found !";

    // while (left <= right)
    // {
    //     int mid = (left + right) / 2;
    //     if (v1[mid] == inp)
    //     {
    //         flag = "the number is found !";
    //         break;
    //     }

    //     if (inp > mid){
    //         left = mid +1;
    //     }

    //     if (inp<mid){
    //         right = mid - 1;
    //     }

    // }

    // cout<<flag;

    /*BINARY SEARCH USING RECURSION*/
    vector<int> v2 = {1, 2, 4, 7, 9, 11, 13, 16, 20};
    int num;

    cout << "Enter the number from 1 to 20 \n";
    cin >> num;

    if (binarySearch(0, v2.size() - 1, num, v2))
    {
        cout << "the number is founded\n";
    }
    else
    {
        cout << "the number is not founded\n";
    }
    return 0;
}