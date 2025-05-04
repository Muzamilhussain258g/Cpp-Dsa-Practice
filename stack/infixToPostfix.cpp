// implementation of infix to postfix

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int precedence(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

string infixToPostfix(string s)
{
    stack<char> st;
    string res;

    for (int i = 0; i < s.length(); i++)
    {
        // case 1 check if it is operand
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            res += s[i];
        }

        // case 2 check if it is opening bracket then direct push into stack
        else if (s[i] == '(')
        {
            st.push(s[i]);
        }

        // case 3 check if is closing bracket then pop the item to the stack until the opening bracket and add the poped item ito result
        else if (s[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                res += st.top();
                st.pop();
            }
            if (!st.empty())
            {
                st.pop();
            }
        }

        // case 4 if it is operator
        else
        {
            while (!st.empty() && precedence(st.top()) >=  precedence(s[i]))
            {
                res += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    // add the remainig item into result if it exist in stack 
    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }

    return res;
}

int main()
{
    string infix = "(a+b*(c*d-e)+(f+g*h)-i)/j";
    string postfix = infixToPostfix(infix);
    cout << "the postfix equation is :" <<postfix;
}