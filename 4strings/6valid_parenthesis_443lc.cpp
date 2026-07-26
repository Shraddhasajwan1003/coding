//both code logic are same onlt differ in type of loop thye use, one uses primitive for loop and one uses ch on strings stl style


// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     string removeparenthesis(string s){
//         int cnt=0;//counter variable 
//         int n =s.length();
//         string result ="";
//         for(int i=0;i<n-1;i++){
//             if(s[i]=='('){
                
//                 if(cnt>0)result+=s[i];
//                 cnt++;
//             }
//             else if(s[i]==')'){
//                 cnt--;
//                 if(cnt>0)result+=s[i];
                
//             }
//         }
//         return result;

//     }
// };

// int main() {
//     Solution obj;
//     string s;
//     cin>>s;
//     cout<<obj.removeparenthesis(s);
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to remove outer parentheses
    string removeOuterParentheses(string s) {
        // Initialize result string
        string result = "";  
        // Initialize nesting level counter
        int level = 0;       

        // Traverse the string
        for (char ch : s) {
            // If we encounter '(', increase the level
            if (ch == '(') {
                // If we're inside a primitive, add '(' to result
                if (level > 0) result += ch;
                // Increase the nesting level for '('
                level++;  
            } 
            // If we encounter ')', decrease the level
            else if (ch == ')') {
                // Decrease the nesting level for ')'
                level--;  
                // If we're inside a primitive, add ')' to result
                if (level > 0) result += ch;
            }
        }

        // Return the final result after removing the outer parentheses
        return result;
    }
};

int main() {
    string s = "()(()())(())";  
    // Create object of Solution class
    Solution sol;             

    // Get result
    string ans = sol.removeOuterParentheses(s);

    // Print result
    cout << "The result is: " << ans << endl;

    return 0;
}