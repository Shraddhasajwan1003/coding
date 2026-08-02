//Array ke har element ke liye, uske right (daayein) side par pehla aisa element dhundhna hai jo usse chhota (smaller) ho.

// Agar right side me koi chhota element mil jata hai, toh woh aapka answer hoga.

// Agar right side me koi bhi chhota element nahi milta, toh uski jagah -1 rakhna hai.

// Kaise Pehchane Ki Ye Stack Ka Question Hai?
// Yeh problem Monotonic Stack pattern ka classic example hai. Jab bhi kisi question me niche diye gaye signs dikhein, samajh jaiye ki Stack use hoga:

// Nearest / Next Element ki Requirement:
// Jab bhi question me aisa kuch pucha ho:
// Next Greater Element,Next Smaller Element,Previous Greater Element,Previous Smaller Element

// Brute Force me O(N^2) Time Lag Raha Ho:
// Brute force me aap har element ke liye nested loop (for i aur for j) chala kar right/left me search karte ho. Jab bhi linear array me $O(N^2)$ ko reduce karke O(N) me karna ho, wahan Stack ka use hota hai.

// Monotonic Property (Increasing / Decreasing Order):Stack hamen nearest past/future elements ki history maintain karne me madad karta hai, jisse faaltu elements ko hum instantly pop() karke discard kar sakte hain.


 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    /* Function to find the next smaller 
    element for each element in the array */
    vector<int> nextSmallerElement(vector<int>& arr) {
        
        int n = arr.size(); // size of array
        
        // To store the next smaller elements
        vector<int> ans(n, -1);
        
        for (int i = 0; i < n; ++i) {
            
            // Get the current element
            int currEle = arr[i];
            
            /* Nested loop to get the 
            next smaller element */
            for (int j = i + 1; j < n; ++j) {
                
                // If the next smaller element is found
                if (arr[j] < currEle) {
                    
                    // Store the next smaller element
                    ans[i] = arr[j];
                    
                    // Break from the loop
                    break;
                }
            }
        }
        
        // Return the answer
        return ans;
    }
};

int main() {
    int n = 5;
    vector<int> arr = {4, 8, 5, 2, 25};

    /* Creating an instance of 
    Solution class */
    Solution sol;
    
    /* Function call to find the next smaller element
    for each element in the array */
    vector<int> ans = sol.nextSmallerElement(arr);
    
    cout << "The next smaller elements are: ";
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    
    return 0;
}


//optimal code
//TC & SC IS O(N)
//Logic (Right to Left Loop):
// Array ko Right se Left (n-1 se 0) traverse karo.

// Jab tak Stack khali na ho aur stack.top() current element se bada ya barabar ho, tab tak stack se elements pop() karte raho (kyunki woh hamare kisi kaam ke chhote element nahi hain).

// Pop karne ke baad:

// Agar stack me koi element bachta hai, toh stack.top() hi hamara Next Smaller Element hai.

// Agar stack empty ho jata hai, toh matlab right side me koi chhota element nahi hai (answer -1).

// Current element ko stack me push() kar do.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextSmallerElement(vector<int>& arr) {
        int n = arr.size();

        // Stack to store potential next smaller elements
        stack<int> st;

        // Answer array initialized with -1
        vector<int> ans(n, -1);

        // Traverse the array from right to left
        for (int i = n - 1; i >= 0; i--) {

            // Pop elements from stack while they are >= current element
            while (!st.empty() && st.top() >= arr[i]) {
                st.pop();
            }

            // If stack is not empty, top is the next smaller element
            if (!st.empty()) {
                ans[i] = st.top();
            }

            // Push current element to stack
            st.push(arr[i]);
        }

        // Return result
        return ans;
    }
};

int main() {
    vector<int> arr = {1, 3, 2, 4};
    Solution sol;

    // Get result
    vector<int> ans = sol.nextSmallerElement(arr);

    // Print result
    cout << "The next smaller elements are: ";
    for (int val : ans) {
        cout << val << " ";
    }

    return 0;
}