// this is a problem in which we find the next greater element in the element
// sample input =[6,8,0,1,3]
// sample output =[8,-1,1,3,-1]

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> v1 = {6, 8, 0, 1, 3};
    vector<int> ans;
    stack<int> s;

    for (int i = v1.size() - 1; i >= 0; i--)
    {
        while (!s.empty() && s.top() < v1[i])
        {
            s.pop();
        }

        if (s.empty())
        {
            ans.push_back(-1);
        }
        else
        {
            ans.push_back(s.top());
        }
        s.push(v1[i]);
    }
    // for console the ans
    reverse(ans.begin(),ans.end()); // we are done this problem from right to left
    for (int i : ans)
    {
        cout << i << " ";
    }
}