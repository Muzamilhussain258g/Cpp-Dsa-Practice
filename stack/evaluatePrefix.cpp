#include <iostream>
#include <stack>
#include <math.h>

using namespace std;

int applyOperation(int a, int b, char operation)
{
    switch (operation)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b; // assume b != 0
    case '^':
        return pow(a, b);
    default:
        return 0;
    }
}

int evaluatePrefix(string s)
{
    stack<int> st;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            st.push(s[i]-'0');
        }
        else
        {
            int operand1 = st.top();
            st.pop();

            int operand2 = st.top();
            st.pop();
            
            int result = applyOperation(operand1, operand2, s[i]);
            st.push(result);
        }
    }

    return st.top();
}


int main()
{
    int  evaluate = evaluatePrefix("-+7*45+20");
    cout<<"the answer of this equation after evaluation is :"<< evaluate;
}