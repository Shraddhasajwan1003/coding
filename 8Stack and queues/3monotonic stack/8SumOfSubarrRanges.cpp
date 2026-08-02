//Sum of Subarray Ranges
// Problem Statement: Given an integer array nums, determine the range of a subarray, defined as the difference between the largest and smallest elements within the subarray. Calculate and return the sum of all subarray ranges of nums.

// A subarray is defined as a contiguous, non-empty sequence of elements within the array.

//ques ko dekhte hi apko lgna chahiye ki  subaray ki range kya hogi 
// range = maximum- minimum
// Agar hum har subarray ke liye $(\text{Max} - \text{Min})$ nikalein aur add karein, toh essentially hum ye kar rahe hain:
// summation(max-min)= sumation(max)-sumation(min);


//The Monotonic Stack Pattern:
// Jab bhi tumse kisi array ke saare subarrays ke Maxima ya Minima ka Sum pucha jaye, tab har element ka "Contribution" nikala jata hai.

// "Ye particular element arr[i] kitne subarrays me MINIMUM hoga?"

// "Ye particular element arr[i] kitne subarrays me MAXIMUM hoga?"

// Jab Next/Previous Smaller/Greater Element ki baat aaye, wahan Monotonic Stack lagta hai.

//Approach 1: Brute Force Approach
// 💡 Core Idea
// Sabse simple tarika: Saare possible subarrays generate kar lo, har ek subarray ka Max aur Min find karo, aur unka difference sum me add kar do.

// 📜 Logic / StepsOuter loop i chalao 0 se n-1 tak (Subarray ka Start Point)

// .Har start point ke liye smallest = arr[i] aur largest = arr[i] initialize karo.

// Inner loop j chalao i se n-1 tak (Subarray ka End Point).

// Jaise-jaise j aage badhta hai, smallest aur largest ko update karte raho:smallest = min(smallest, arr[j])largest = max(largest, arr[j])Har step pe sum += (largest - smallest) kar do.

// ⏱️ ComplexityTime Complexity: O(N^2) — Do nested loops lag rahe hain.Space Complexity: O(1) — Koi extra memory use nahi ho rahi


// 🚀 Approach 2:

// Optimal Approach (Monotonic Stack)
// 💡 Core Idea
// Brute force me bohot saari repetitive calculations hoti hain.

// Optimal me hum Ulta sochte hain:"Har element arr[i] kitne subarrays me MINIMUM bana, aur kitne subarrays me MAXIMUM bana?"

// Agar hume pata chal jaye ki:
// arr[i] total count_{min} subarrays me minimum hai
// arr[i] total count_{max} subarrays me maximum hai


// Toh overall sum me arr[i] ka contribution hoga:


// Contribution =arr[i] * count_{max} - arr[i]*count_{min}

// 📜 Steps to SolveSum of Subarray Minimums (summation(min)):


// Har index i ke liye dhundo:

// NSE (Next Smaller Element): Aage pehla element jo arr[i] se chota ho (Index = nse[i]).


// PSEE (Previous Smaller or Equal Element): Peeche pehla element jo arr[i] se chota ya barabar ho (Index = psee[i]).

// Left side options = i -psee[i]

// Right side options = nse[i] - i

// Total subarrays jahan arr[i] minimum hai:

// count=left*right

// Sum of Subarray Maximums summation(Max):


// Har index i ke liye dhundo:

// NGE (Next Greater Element): Aage pehla element jo arr[i] se bada ho (Index = nge[i]).

// PGEE (Previous Greater or Equal Element): Peeche pehla element jo arr[i] se bada ya barabar ho (Index = pgee[i]).


// Total subarrays jahan arr[i] maximum hai:

// count=(i-pgee[i])*(nge[i]-i);

// Final answer = sum of subarray maxima - sum of subaaray minima

// Note on Duplicates: Ek side strict inequality (<) aur dusri side non-strict (<=) use karte hain taaki duplicate elements hone par subarrays double-count na ho jayein.

// SC IS O(1)  &TC IS O(N^2)--->brute
// SC IS O(N)  &TC IS O(N)---->optimal
//best optimal and easy one and leetcode type is at last 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    /* Function to find the sum of 
    subarray ranges in each subarray */
    long long subArrayRanges(vector<int> &arr) {
        
        // Size of array
        int n = arr.size();
        
        // To store the sum
        long long sum = 0;
        
        // Traverse on the array
        for(int i=0; i < n; i++) {
            
            // To store the smallest value of subarray
            int smallest = arr[i];
            
            // To store the largest value of subarray
            int largest = arr[i];
            
            /* Nested loop to get all 
            subarrays starting from index i */
            for(int j=i; j < n; j++) {
                
                // Update the smallest value
                smallest = min(smallest, arr[j]);
                
                // Update the largest value
                largest = max(largest, arr[j]);
                
                // Update the sum
                sum += (largest - smallest);
            }
        }
        
        // Return the computed sum
        return sum;
    }
};

int main() {
    vector<int> arr = {1, 2, 3};
    
    /* Creating an instance of 
    Solution class */
    Solution sol; 
    
    /* Function call to find the sum of 
    subarray ranges in each subarray */
    long long ans = sol.subArrayRanges(arr);
    
    cout << "The sum of subarray ranges is: " << ans;
    
    return 0;
}


//optimal
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    /* Function to find the indices of 
    next smaller elements */
    vector<int> findNSE(vector<int> &arr) {
        
        // Size of array
        int n = arr.size();
        
        // To store the answer
        vector<int> ans(n);
        
        // Stack 
        stack<int> st;
        
        // Start traversing from the back
        for(int i = n - 1; i >= 0; i--) {
            
            // Get the current element
            int currEle = arr[i];
            
            /* Pop the elements in the stack until 
            the stack is not empty and the top 
            element is not the smaller element */
            while(!st.empty() && arr[st.top()] >= currEle){
                st.pop();
            }
            
            // Update the answer
            ans[i] = !st.empty() ? st.top() : n;
            
            /* Push the index of current 
            element in the stack */
            st.push(i);
        }
        
        // Return the answer
        return ans;
    }
    
    /* Function to find the indices of 
    next greater elements */
    vector<int> findNGE(vector<int> &arr) {
        
        // Size of array
        int n = arr.size();
        
        // To store the answer
        vector<int> ans(n);
        
        // Stack 
        stack<int> st;
        
        // Start traversing from the back
        for(int i = n - 1; i >= 0; i--) {
            
            // Get the current element
            int currEle = arr[i];
            
            /* Pop the elements in the stack until 
            the stack is not empty and the top 
            element is not the greater element */
            while(!st.empty() && arr[st.top()] <= currEle){
                st.pop();
            }
            
            // Update the answer
            ans[i] = !st.empty() ? st.top() : n;
            
            /* Push the index of current 
            element in the stack */
            st.push(i);
        }
        
        // Return the answer
        return ans;
    }
    
    /* Function to find the indices of 
    previous smaller or equal elements */
    vector<int> findPSEE(vector<int> &arr) {
        
        // Size of array
        int n = arr.size();
        
        // To store the answer
        vector<int> ans(n);
        
        // Stack 
        stack<int> st;
        
        // Traverse on the array
        for(int i=0; i < n; i++) {
            
            // Get the current element
            int currEle = arr[i];
            
            /* Pop the elements in the stack until 
            the stack is not empty and the top 
            elements are greater than the current element */
            while(!st.empty() && arr[st.top()] > currEle){
                st.pop();
            }
            
            // Update the answer
            ans[i] = !st.empty() ? st.top() : -1;
            
            /* Push the index of current 
            element in the stack */
            st.push(i);
        }
        
        // Return the answer
        return ans;
    }
    
    /* Function to find the indices of 
    previous greater or equal elements */
    vector<int> findPGEE(vector<int> &arr) {
        
        // Size of array
        int n = arr.size();
        
        // To store the answer
        vector<int> ans(n);
        
        // Stack 
        stack<int> st;
        
        // Traverse on the array
        for(int i=0; i < n; i++) {
            
            // Get the current element
            int currEle = arr[i];
            
            /* Pop the elements in the stack until 
            the stack is not empty and the top 
            elements are smaller than the current element */
            while(!st.empty() && arr[st.top()] < currEle){
                st.pop();
            }
            
            // Update the answer
            ans[i] = !st.empty() ? st.top() : -1;
            
            /* Push the index of current 
            element in the stack */
            st.push(i);
        }
        
        // Return the answer
        return ans;
    }
    
    /* Function to find the sum of the 
    minimum value in each subarray */
    long long sumSubarrayMins(vector<int> &arr) {
        
        vector<int> nse = findNSE(arr);
        
        vector<int> psee = findPSEE(arr);
        
        // Size of array
        int n = arr.size();
        
        // To store the sum
        long long sum = 0;
        
        // Traverse on the array
        for(int i=0; i < n; i++) {
            
            // Count of first type of subarrays
            int left = i - psee[i];
            
            // Count of second type of subarrays
            int right = nse[i] - i;
            
            /* Count of subarrays where 
            current element is minimum */
            long long freq = left*right*1LL;
            
            // Contribution due to current element 
            long long val = (freq*arr[i]*1LL);
            
            // Updating the sum
            sum += val;
        }
        
        // Return the computed sum
        return sum;
    }
    
    /* Function to find the sum of the 
    maximum value in each subarray */
    long long sumSubarrayMaxs(vector<int> &arr) {
        
        vector<int> nge = findNGE(arr);
        
        vector<int> pgee = findPGEE(arr);
        
        // Size of array
        int n = arr.size();
        
        // To store the sum
        long long sum = 0;
        
        // Traverse on the array
        for(int i=0; i < n; i++) {
            
            // Count of first type of subarrays
            int left = i - pgee[i];
            
            // Count of second type of subarrays
            int right = nge[i] - i;
            
            /* Count of subarrays where 
            current element is minimum */
            long long freq = left*right*1LL;
            
            // Contribution due to current element 
            long long val = (freq*arr[i]*1LL);
            
            // Updating the sum
            sum += val;
        }
        
        // Return the computed sum
        return sum;
    }
    
public:
    /* Function to find the sum of 
    subarray ranges in each subarray */
    long long subArrayRanges(vector<int> &arr) {
        
        // Return the result
        return ( sumSubarrayMaxs(arr) - 
                 sumSubarrayMins(arr) );
    }
};

int main() {
    vector<int> arr = {1, 2, 3};
    
    /* Creating an instance of 
    Solution class */
    Solution sol; 
    
    /* Function call to find the sum of 
    subarray ranges in each subarray */
    long long ans = sol.subArrayRanges(arr);
    
    cout << "The sum of subarray ranges is: " << ans;
    
    return 0;
}

class Solution {
public:
    
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        long long sum=0;
        stack<int>st;
        vector<int> minPrev(n,-1),minNext(n,n),maxPrev(n,-1),maxNext(n,n);
        
        for(int i=0;i<n;i++)
        {
            while(!st.empty()&&nums[st.top()]>=nums[i]){st.pop();}
            if(!st.empty()){minPrev[i]=st.top();}
            st.push(i);
        }
        while(!st.empty()){st.pop();}
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty()&&nums[st.top()]>nums[i]){st.pop();}
            if(!st.empty()){minNext[i]=st.top();}
            st.push(i);
        }
        
         for(int i=0;i<n;i++)
         {
            while(!st.empty()&&nums[st.top()]<=nums[i]){st.pop();}
            if(!st.empty()){maxPrev[i]=st.top();}
            st.push(i);
         }
         while(!st.empty()){st.pop();}
         for(int i=n-1;i>=0;i--)
         {
            while(!st.empty()&&nums[st.top()]<nums[i]){st.pop();}
            if(!st.empty()){maxNext[i]=st.top();}
            st.push(i);
         }
        
        for(int i=0;i<n;i++)
        {
            long long leftMin=i-minPrev[i],rightMin=minNext[i]-i;
            long long leftMax=i-maxPrev[i],rightMax=maxNext[i]-i;
            sum+=(leftMax*rightMax-leftMin*rightMin)*nums[i];
            
        }
        return sum;
    }
};