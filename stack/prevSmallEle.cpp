// this is a problem in which we find the prev smallest element in the element
// sample input =[3,1,0,8,6]
// sample output =[-1,-1,-1,0,0]

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    vector<int> v1 = {3, 1, 0, 8, 6};
    vector<int> ans;
    stack<int> s;

    for (int i = 0; i < v1.size(); i++)
    {
        while (!s.empty() && v1[i] <= s.top())
        {
            /* code */
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
    for (int i : ans)
    {
        cout << i << " ";
    }
}