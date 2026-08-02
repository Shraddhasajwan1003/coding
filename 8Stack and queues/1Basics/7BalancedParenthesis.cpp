//Check for Balanced Parentheses

// Problem Statement: Check Balanced Parentheses. Given string str containing just the characters '(', ')', '{', '}', '[' and ']', check if the input string is valid and return true if the string is balanced otherwise return false. .

// Note:
// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.

// Constraints:

// 1 <= s.length <= 104
// s consists of parentheses only '()[]{}'.
//Example 1:
// Input: str = “( )[ { } ( ) ]”
// Output: True
// Explanation: As every open bracket has its corresponding close bracket. Match parentheses are in correct order hence they are balanced.


// Example 2:
// Input: str = “[ ( )”
// Output: False
// Explanation: As ‘[‘ does not have ‘]’ hence it is not valid and will return false.


//Whenever we get the opening bracket we will push it into the stack. I.e ‘{‘, ’[’, ’(‘.
// Whenever we get the closing bracket we will check if the stack is non-empty or not.
// If the stack is empty we will return false, else if it is nonempty then we will check if the topmost element of the stack is the opposite pair of the closing bracket or not.
// If it is not the opposite pair of the closing bracket then return false, else move ahead.
// After we move out of the string the stack has to be empty if it is non-empty then return it as invalid else it is a valid string.
#include <bits/stdc++.h>
using namespace std;

// Class containing the isValid method
class Solution {
public:
    // Function to check if the input string has valid parentheses
    bool isValid(string s) {
        stack<char> st;  // Stack to store opening brackets

        for (auto it : s) {
            if (it == '(' || it == '{' || it == '[')
                st.push(it);  // Push opening brackets to stack
            else {
                if (st.empty()) return false;  // No matching opening bracket
                char ch = st.top();
                st.pop();

                // Check for matching pair
                if ((it == ')' && ch == '(') ||
                    (it == ']' && ch == '[') ||
                    (it == '}' && ch == '{'))
                    continue;
                else
                    return false;
            }
        }
        return st.empty();  // True if all brackets matched
    }
};

int main() {
    Solution sol;
    string s = "()[{}()]";

    if (sol.isValid(s))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}


