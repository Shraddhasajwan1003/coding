//



//Algorithm
// Traverse the prefix expression from right to left.
// Use a stack to store operands.
// For each operator, pop two operands from the stack, wrap them in parentheses, and push the resulting expression back.
// The final item in the stack will be the infix expression.




#include <bits/stdc++.h>
using namespace std;
//TC & SC IS O(N)
// Function to convert prefix to infix
string prefixToInfix(string prefix) {
    stack<string> s;
    int n = prefix.size();

    // Traverse the prefix expression from right to left
    for (int i = n - 1; i >= 0; i--) {
        char c = prefix[i];

        // If the character is an operand, push it to the stack
        if (isalnum(c)) {
            s.push(string(1, c));
        } else {
            // Pop two operands from the stack
            string op1 = s.top(); s.pop();
            string op2 = s.top(); s.pop();

            // Form the new infix expression and push back to stack
            s.push("(" + op1 + c + op2 + ")");
        }
    }

    // The final element in the stack is the result
    return s.top();
}

int main() {
    string prefix = "*-A/BC-/AKL";
    cout << "Infix Expression: " << prefixToInfix(prefix) << endl;
    return 0;
}
