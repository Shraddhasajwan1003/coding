//Remove K Digits

// Problem Statement: Given a string nums representing a non-negative integer, and an integer k, find the smallest possible integer after removing k digits from num.
//Example 1:
// Input:
//  nums = "541892", k = 2
// Output:
//  "1892"
// Explanation:
//  Removing the two digits 5 and 4 yields the smallest number, 1892.

// Example 2:
// Input:
//  nums = "1002991", k = 3
// Output:
//  "21"
// Explanation:
//  Remove the three digits 1(leading one), 9, and 9 to form the new number 21(Note that the output must not contain leading zeroes) which is the smallest.

//Algorithm
// Use a stack to store digits of the resulting number
// Iterate through each digit of the input string
// While the stack is not empty, the current digit is smaller than the top of the stack, and k is greater than 0, pop from the stack and decrement k
// Push the current digit onto the stack
// If k is still greater than 0 after the iteration, remove digits from the end of the stack
// Collect the remaining digits from the stack to form the result
// Remove any leading zeroes from the result
// If the result is empty after removing zeroes, return "0"

// Edge Cases:
// If k is equal to the length of the input string, return "0" as all digits will be removed
// If the result contains leading zeroes, remove them before returning
// If no digits were removed during iteration and k is still greater than 0, remove the last k digits from the stack


//Time Complexity: O(N), since traversing the given string takes O(N) time, each element is pushed onto and popped from the stack at most once in worst-case taking o(N) time, removing the remaining digits (if k > 0) takes O(k) time which can go upto O(N) in worst-case and forming the result, trimming the zeros and reversing the digits takes O(N) time.

// Space Complexity: O(N), since we are using a stack to store the digits of the resulting number, in the worst case, the stack can contain all the digits of the input string.


//💡 Core Idea (Main Concept)
// Jab bhi hume sabse chhota number banana hota hai, hum chahte hain ki shuruat ki digits jitni ho sake chhoti hon. 
// Agar koi digit apne baad wali digit se badi hai (e.g., 5 ke baad 4), toh us 5 ko hatana sabse best option hota hai kyunki tabhi chhota number aage aayega.
// Iske liye hum Monotonic Stack ka use karte hain.

// 🛠️ Step-by-Step Approach

// Traverse Karo: Number ki har digit pe ek-ek karke aage badho.

// Badi Digits Pop Karo: Jab tak Stack me rakhi aakhri digit current digit se badi hai aur hamare paas k > 0 hai, tab tak stack se us badi digit ko pop (remove) karte raho aur k ko -1 karo.

// Current Digit Push Karo: Phir current digit ko stack me daal do.

// Remaining K Handle Karo: Agar poora traversal khatam hone ke baad bhi k > 0 bacha hai (jaise ki 12345 me koi bada-se-chhota drop nahi mila), toh stack ke aakhri k elements remove kar do.

// Leading Zeros Hatao: Result string banao aur shuruat ke saare 0s (e.g., 0021 -> 21) hata do.

// ⚠️ Edge Cases (Dhayan Dene Waali Baatein)
// Leading Zeros: 1002991 aur k=3 me 1 hatne par 002991 banta hai, par answer 21 hona chahiye (saare aage ke zeroes trim karne hote hain).

// Already Sorted Digits: Agar input 12345 aur k=2 hai, toh standard loop me koi element pop nahi hoga. 
// Isliye loop ke baad aakhri ke k elements (i.e. 4 aur 5) hatane padenge -> Answer: 123.

// k equals length of string: Agar $k$ original string ki length ke barabar hai, toh saare digits hat jayenge -> Answer: "0".

// Resulting String is Empty: Trimming ke baad agar string khali ho jaye (e.g. 0000), toh return "0" karna hai.

//one approach 
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /* Function to find the smallest possible 
    integer after removing k digits */
    string removeKdigits(string nums, int k) {
        
        stack <char> st; // Stack
        
        // Traverse on the given string
        for(int i=0; i < nums.size(); i++) {
            
            // Current digit
            char digit = nums[i];
            
            /* Pop last digits (when possible)
            if a smaller digit is found*/
            while(!st.empty() && k > 0
                  && st.top() > digit) {

                st.pop(); // Pop the last digit
                k--; // Decrement K by 1
            }
            
            // Push the current digit
            st.push(digit);
        }
        
        // If more digits can be removed
        while(!st.empty() && k > 0) {
            
            st.pop(); // Pop the last added digits
            k--; // Decrement K by 1
        }
        
        // Handling edge case
        if(st.empty()) return "0";
        
        // To store the result
        string res = "";
        
        // Adding digits in stack to result
        while(!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        
        // Trimming the zeroes at the back
        while(res.size() > 0 && 
              res.back() == '0') {

            res.pop_back();
        }
        
        // Reverse to get the actual number
        reverse(res.begin(), res.end());
        
        // Edge case
        if(res.empty()) return "0";
        
        // Return the stored result
        return res;
    }
};

int main() {
    string nums = "541892";
    int k = 2;
    
    /* Creating an instance of 
    Solution class */
    Solution sol; 
    
    /* Function call to find the smallest 
    possible integer after removing k digits */
    string ans = sol.removeKdigits(nums, k);
    
    cout << "The smallest possible integer after removing k digits is: " << ans;
    
    return 0;
}

