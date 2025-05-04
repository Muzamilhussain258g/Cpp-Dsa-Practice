#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// This function gives precedence of operators
int precedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

// This function reverses the string and swaps brackets
string reverseStringExceptBracket(string s)
{
    string res;

    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] == '(')
            res += ')';
        else if (s[i] == ')')
            res += '(';
        else
            res += s[i];
    }
    return res;
}

// This function converts infix to postfix
string infixToPostfix(string s)
{
    stack<char> st;
    string res;

    for (int i = 0; i < s.length(); i++)
    {
        // Case 1: If it is an operand (a-z or A-Z)
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            res += s[i];
        }

        // Case 2: If it is opening bracket '('
        else if (s[i] == '(')
        {
            st.push(s[i]);
        }

        // Case 3: If it is closing bracket ')'
        else if (s[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                res += st.top();
                st.pop();
            }
            if (!st.empty())
            {
                st.pop(); // remove the '('
            }
        }

        // Case 4: If it is operator +, -, *, /, ^
        else
        {
            // While stack is not empty and operator at top has more or same precedence
            while (!st.empty() && precedence(st.top()) >= precedence(s[i]))
            {
                res += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    // Add remaining operators from stack to result
    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }

    return res;
}

// This function converts infix expression to prefix
string infixToPrefix(string s)
{
    // Step 1: Reverse string and brackets
    string reversedString = reverseStringExceptBracket(s);

    // Step 2: Convert reversed string to postfix
    string postfix = infixToPostfix(reversedString);

    // Step 3: Reverse postfix to get prefix
    return reverseStringExceptBracket(postfix);
}

int main()
{
    string infix = "(a+b*(c*d-e)+(f+g*h)-i)/j";
    string prefix = infixToPrefix(infix);
    cout << "The prefix expression is: " << prefix << endl;
}
