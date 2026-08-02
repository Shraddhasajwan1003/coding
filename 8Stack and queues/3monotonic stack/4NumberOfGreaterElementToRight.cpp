//1. Brute Force ApproachSamajhne ka tareeka (Intuition)
// Iska sabse simple aur seedha tareeka hai: Aap har element par khade ho jaao aur uske right side jitne bhi elements hain, unhe ek-ek karke check karo.

// Pehla Loop (i): Yeh batata hai ki hum abhi kis element (arr[i]) ke liye NGE dhundh rahe hain.

// Dusra Loop (j): Yeh i + 1 se start hota hai aur array ke end tak jaata hai.

// Jaise hi arr[j] > arr[i] milta hai, wahi hamara NGE hota hai. Hum use result mein store karke inner loop break kar dete hain.

// Agar right side poora traverse karne ke baad bhi koi bada element nahi milta, toh default value -1 hi rehti hai.

// Pattern Kaise Pehchane?

// Pattern: Double Loop / Nested Loops (O(N^2)).

// Kese Sochne Ka: Jab aapko small input ke liye brute-force mind mein banana ho, toh simple lagta hai: "Har element ke liye uske aage ki duniya check karo."

// Complexity: Time Complexity O(N^2) hoti hai aur Space Complexity O(N) (result array store karne ke liye).

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    /* Function to find the next greater 
    element for each element in the array */
    vector<int> nextLargerElement(vector<int> arr) {
        
        int n = arr.size(); // size of array
        
        // To store the next greater elements
        vector<int> ans(n, -1);
        
        for(int i=0; i < n; i++) {
            
            // Get the current element+
            int currEle = arr[i];
            
            /* Nested loop to get the 
            next greater element */
            for(int j=i+1; j < n; j++) {
                
                // If the next greater element is found
                if(arr[j] > currEle) {
                    
                    // Store the next greater element
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
    int n = 4;
    vector<int> arr = {1, 3, 2, 4};

    /* Creating an instance of 
    Solution class */
    Solution sol; 
    
    /* Function call to find the next greater element
    for each element in the circular array */
    vector<int> ans = sol.nextLargerElement(arr);
    
    cout << "The next greater elements are: ";
    for(int i=0; i < n; i++) {
        cout << ans[i] << " ";
    }
    
    return 0;
}

//optimal approach 
//Samajhne ka tareeka (Intuition)

// Double loop wali performance (O(N^2)) ko optimize karne ke liye hum Stack ka use karte hain.

// Traversal Direction: Array ko peeche se (Right to Left) traverse karte hain. Kyunki hume har element ke liye uske right side ki jankari chahiye, toh right waale elements ko pehle process karna samajhdaari hai.

// Stack ka Kaam: Stack mein hum aane waale elements ko holds karke rakhte hain (monotonic order mein).

// Algorithm/Steps:
// Right-most element se start karo.

// Har element currEle ke liye:

// Pop Elements: Stack ke top element ko tab tak hatao (st.pop()) jab tak stack ka top currEle se chota ya barabar (<= currEle) hai. Kyunki yeh chote elements aage aane waale elements ke liye kabhi "Next Greater" nahi ban sakte.

// Answer Set Karo:Agar stack khali ho gaya-> Matlab right side mein koi bada element nahi hai, answer = -1.

// Agar stack khali nahi hua ->Stack ka top hi sabse nearest bada element hai (st.top()), answer = st.top().

// Push Current: Ab currEle ko stack mein push kar do taaki yeh apne se left waale elements ke liye compare ho sake.

//TC is O(N) SC(O(N))+ O(N)(worst case for stack)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    /* Function to find the next greater 
    element for each element in the array */
    vector<int> nextLargerElement(vector<int> arr) {
        
        int n = arr.size(); //size of array
        
        // To store the next greater elements
        vector<int> ans(n);
        
        // Stack to get elements in LIFO fashion
        stack<int> st;
        
        // Start traversing from the back
        for(int i=n-1; i >= 0; i--) {
            
            // Get the current element
            int currEle = arr[i];
            
            /* Pop the elements in the stack until 
            the stack is not empty and the top 
            element is not the greater element */
            while(!st.empty() && st.top() <= currEle) {
                st.pop();
            }
            
            /* If the greater element is not 
            found, stack will be empty */
            if(st.empty()) 
                ans[i] = -1;
                
            // Else store the answer
            else 
                ans[i] = st.top();
            
            /* Push the current element in the stack 
            maintaining the decreasing order */
            st.push(currEle);
        }
        
        // Return the result
        return ans;
    }
};

int main() {
    int n = 4;
    vector<int> arr = {1, 3, 2, 4};
    
    /* Creating an instance of 
    Solution class */
    Solution sol; 
    
    /* Function call to find the next greater 
    element for each element in the array */
    vector<int> ans = sol.nextLargerElement(arr);
    
    cout << "The next greater elements are: ";
    for(int i=0; i < n; i++) {
        cout << ans[i] << " ";
    }
    
    return 0;
}


