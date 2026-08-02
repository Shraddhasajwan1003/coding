//Problem Statement: Given an array of non-negative integers representation elevation of ground. Your task is to find the water that can be trapped after rain .

//1. Core Intuition (Pani Kahan Aur Kitna Rukega?)
// Kisi bhi specific bar i par kitna paani jama hoga, yeh pure array ke pillars par nahi, balki do cheezon par depend karta hai:
// Us bar ke Left side ka sabse bada pillar (maxLeft).
// Us bar ke Right side ka sabse bada pillar (maxRight).

// Key Formula:  {Water at bar } i = min(maxLeft,maxRight) -height[i]


// Note: Agar min(maxLeft,maxRight) <=height i
// hai, toh vahan 0 unit paani rukega (pani beh jayega).

// 2. Pattern Recognition (Pattern Kaise Pehchane?)

// Jab bhi problem mein:Kisi current element par answer nikalne ke liye uske baayein (left) aur daayein (right) ke maximum/minimum elements ki zaroorat ho.Processing har index par independent lag rahi ho.

// Toh vahan Prefix/Suffix Precomputation ya Two Pointers ka pattern lagta hai.

// 3. Brute Force -> Better ->Optimal Approach

// Approach 1: Brute Force
// Har bar i par khade ho kar, do loops chalao:Ek loop left side search karke maxLeft nikalne ke liye.
// Doosra loop right side search karke maxRight nikalne ke liye.
// Time Complexity (TC): O(N^2) (Har index ke liye pure array par loop).
// Space Complexity (SC): $O(1)$ (Koi extra space nahi).


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to calculate trapped rainwater using brute force approach
    int trap(vector<int>& height) {
        int n = height.size();
        
        // Variable to store total trapped water
        int totalWater = 0;
        
        // Iterate over each bar in the elevation map
        for (int i = 0; i < n; i++) {
            // Initialize max heights to the left and right of current bar
            int maxLeft = 0;
            int maxRight = 0;
            
            // Find maximum height to the left of current bar
            for (int j = 0; j <= i; j++) {
                if (height[j] > maxLeft) {
                    maxLeft = height[j];
                }
            }
            
            // Find maximum height to the right of current bar
            for (int j = i; j < n; j++) {
                if (height[j] > maxRight) {
                    maxRight = height[j];
                }
            }
            
            // Water trapped on current bar is min of maxLeft and maxRight minus current height
            totalWater += min(maxLeft, maxRight) - height[i];
        }
        
        // Return total trapped water
        return totalWater;
    }
};

// Driver code
int main() {
    // Input elevation map
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    
    // Create Solution object
    Solution sol;
    
    // Calculate trapped water
    int result = sol.trap(height);
    
    // Print the result
    cout << "Trapped Rainwater: " << result << endl;
    
    return 0;
}

// Approach 2: Better Approach (Prefix & Suffix Arrays)Brute force mein baar-baar left aur right max dhoondhna pad raha tha. Isko optimize karne ke liye do extra arrays banate hain:

// prefixMax[i]: Index 0 se i tak ka maximum element.
// suffixMax[i]: Index i se N-1 tak ka maximum element.

// Har index i par directly formula lagao:
// totalWater += min(prefixMax[i],suffixMax[i]) -height[i]
// Time Complexity (TC): O(N) (Three linear passes).
// Space Complexity (SC): O(N)(Two extra arrays of size N).


// Approach 3: Optimal Approach (Two Pointers)
// Hame O(N)space remove karna hai. Iske liye do pointers, left = 0 aur right = N - 1, use karte hain, saath mein maxLeft = 0 aur maxRight = 0.

// Why and What is the Invariant here?

// Loop Invariant:Jab hum check karte hain height[left] <= height[right]:Hame yeh guarantee milti hai ki right side mein kam se kam ek aisa pillar zaroor hai jo height[left] se bada ya barabar hai.

// Iska matlab: Water trapping ke liye bottleneck right side nahi, maxLeft hoga! Hame exact maxRight janne ki zaroorat hi nahi hai, kyunki min(maxLeft,maxRight) ka result hamesha maxLeft hi decide karega.

// Algorithm Steps:Agar height[left] <= height[right]:

// Agar height[left] >= maxLeft -> maxLeft ko update karo.
// Else ->totalWater += maxLeft - height[left].
// left++

// Else (height[left] > height[right]):
// Agar height[right] >= maxRight -> maxRight ko update karo.
// Else -> totalWater += maxRight - height[right].right--Time Complexity (TC): O(N) (Array ko sirf ek baar traversal karna padta hai).Space Complexity (SC): $O(1)$ (Sirf variables use hue hain).


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to calculate trapped rainwater using the optimal two-pointer approach
    int trap(vector<int>& height) {
        int n = height.size();
        
        // Initialize two pointers at both ends of the array
        int left = 0;
        int right = n - 1;
        
        // Variables to track the maximum height to the left and right
        int maxLeft = 0;
        int maxRight = 0;
        
        // Variable to store total trapped water
        int totalWater = 0;
        
        // Iterate until left pointer meets right pointer
        while (left <= right) {
            // If left bar is smaller or equal to right bar
            if (height[left] <= height[right]) {
                // If current left bar is higher than maxLeft, update maxLeft
                if (height[left] >= maxLeft) {
                    maxLeft = height[left];
                } else {
                    // Water trapped on left is difference between maxLeft and current height
                    totalWater += maxLeft - height[left];
                }
                left++; // Move left pointer to the right
            } else {
                // If current right bar is higher than maxRight, update maxRight
                if (height[right] >= maxRight) {
                    maxRight = height[right];
                } else {
                    // Water trapped on right is difference between maxRight and current height
                    totalWater += maxRight - height[right];
                }
                right--; // Move right pointer to the left
            }
        }
        
        // Return total trapped water
        return totalWater;
    }
};

// Driver code
int main() {
    // Input elevation map
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    
    // Create Solution object
    Solution sol;
    
    // Calculate trapped water
    int result = sol.trap(height);
    
    // Print the result
    cout << "Trapped Rainwater: " << result << endl;
    
    return 0;
}
