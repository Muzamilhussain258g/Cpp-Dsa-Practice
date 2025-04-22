#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    vector<int> price = {100, 80, 60, 70, 60, 75, 80};

    vector<int> answers;
    stack<int> s;

    for (int i = 0; i < price.size(); i++)
    {
        while (s.size() > 0 && price[s.top()] <= price[i]){
            s.pop();
        }

        if (s.empty()){
            answers.push_back(i+1);
        }else{
            int span = i-s.top();
            
            answers.push_back(span);
        }
        s.push(i);
    }

    // Print the answers
    for (int x : answers)
    {
        cout << x << " ";
    }

    return 0;
}