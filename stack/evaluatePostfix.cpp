// Algorithm:
// 1. Define a function `applyOperation` to perform basic arithmetic operations (+, -, *, /, ^).
// 2. Define a function `evaluatePostfix` to evaluate a postfix expression:
//    a. Initialize an empty stack to store operands.
//    b. Iterate through each character in the postfix expression:
//       i. If the character is a digit, convert it to an integer and push it onto the stack.
//       ii. If the character is an operator, pop the top two elements from the stack as operands.
//           Apply the operator using `applyOperation` and push the result back onto the stack.
//    c. After the loop, the top of the stack contains the final result.
// 3. In the `main` function, call `evaluatePostfix` with a postfix expression and print the result.


#include <iostream>
#include <vector>
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

int evaluatePostfix(string s)
{
    stack<int> st;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            st.push(s[i] - '0'); // it can push the int value
        }
        else
        {
            int operand2 = st.top();
            st.pop();

            int operand1 = st.top();
            st.pop();

            int result = applyOperation(operand1, operand2, s[i]);
            st.push(result);
        }
    }

    return st.top();
}

int main()
{
    string postfix = "23*54*+9-";
    int res = evaluatePostfix(postfix);
    cout << "the result of postfix equation is :" <<res;
}
