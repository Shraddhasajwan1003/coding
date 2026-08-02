//Problem Statement: Given a postfix expression (a string), convert it into an equivalent infix expression. The postfix expression is evaluated from left to right. The infix expression should have the proper parentheses to ensure correct operator precedence.

//Example 1:
// Input:
//  "ab+c*"
// Output:
//  "(a+b)*c"

// Example 2:
// Input:
//  "ab*cd/+"
// Output:
//  "(a*b)+(c/d)"

//Traverse the postfix expression from left to right.
// Use a stack to store operands.
// For each operator, pop two operands, combine them in infix order with parentheses, and push the result back.
// The final item in the stack will be the infix expression.

#include <iosbits/stdc++.htream>
using namespace std;

// Function to convert postfix to infix
string postfixToInfix(string postfix) {
    stack<string> s;
    int n = postfix.size();

    // Traverse the postfix expression from left to right
    for (int i = 0; i < n; i++) {
        char c = postfix[i];

        // If the character is an operand, push it to the stack
        if (isalnum(c)) {
            s.push(string(1, c));
        } else {
            // Pop two operands from the stack
            string op2 = s.top(); s.pop();
            string op1 = s.top(); s.pop();

            // Form the new infix expression and push back to stack
            s.push("(" + op1 + c + op2 + ")");
        }
    }

    // The final element in the stack is the result
    return s.top();
}

int main() {
    string postfix = "AB*C+";
    cout << "Infix Expression: " << postfixToInfix(postfix) << endl;
    return 0;
}
