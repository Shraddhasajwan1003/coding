//Example 1:
// Input:
//  expression = "ab+"
// Output:
//  "+ab"
// Explanation:
//  Postfix → Prefix

// Example 2:
// Input:
//  expression = "abc*+d-"
// Output:
//  "-+a*bcd"

//  Traverse the postfix expression from left to right.
// Use a stack to store operands.
// For each operator, pop two operands, combine them with the operator in prefix order, and push the result back.
// The final item in the stack will be the prefix expression.
#include <bits/stdc++.h>
using namespace std;

// Function to convert postfix to prefix
string postfixToPrefix(string postfix) {
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

            // Form the new prefix expression and push back to stack
            s.push(c + op1 + op2);
        }
    }

    // The final element in the stack is the result
    return s.top();
}

int main() {
    string postfix = "ABC/-AK/L-*";
    cout << "Prefix Expression: " << postfixToPrefix(postfix) << endl;
    return 0;
}
