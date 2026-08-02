//Max Consecutive Ones III
// Problem Statement: Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

//Input : nums = [1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0] , k = 3
// Output : 10
// Explanation : The maximum number of consecutive 1's are obtained only if we flip the 0's present at position 3, 4, 5 (0 base indexing).
// The array after flipping becomes [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0].
// The number of consecutive 1's is 10.


// Input : nums = [0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1] , k = 3
// Output : 9
// Explanation : The underlines 1's are obtained by flipping 0's in the new array.
// [1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1].
// The number of consecutive 1's is 9.

//ALGO for brute force 
//In the brute force approach, we examine every possible subarray in the input array and check if the number of zeros in that subarray is less than or equal to the allowed number of flips (K). For each subarray that satisfies this condition, we calculate its length and update the maximum length encountered so far. Though inefficient, this approach checks all possibilities exhaustively and is useful for understanding the base logic of the problem.
Iterate through all possible starting points of subarrays.
For each starting point, iterate through all possible ending points to form subarrays.
For every subarray, count the number of zeros present.
If the number of zeros is less than or equal to k, treat the subarray as valid (since we can flip the zeros).
Track the length of all valid subarrays and update the maximum length encountered.
Return the length of the longest valid subarray found.


//Time complexity: O(n^2) , as we are using two nested loops.

Space complexity: O(1), no extra space used.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the longest subarray with at most k zero flips
    int longestOnes(vector<int>& nums, int k) {

        // Variable to store the maximum length of valid subarray
        int maxLen = 0;

        // Loop to pick every possible starting point
        for (int i = 0; i < nums.size(); i++) {

            // Counter for zeros in the current subarray
            int zeros = 0;

            // Loop to pick every possible ending point
            for (int j = i; j < nums.size(); j++) {

                // If current element is zero, increment zero count
                if (nums[j] == 0) {
                    zeros++;
                }

                // If number of zeros exceeds k, break this subarray
                if (zeros > k) {
                    break;
                }

                // Update max length if this subarray is valid
                maxLen = max(maxLen, j - i + 1);
            }
        }

        // Return the length of the longest valid subarray
        return maxLen;
    }
};

// Driver code
int main() {
    Solution sol;
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;

    // Output the result
    cout << sol.longestOnes(nums, k) << endl;
    return 0;
}


//better approach 
//Algorithm
// To solve the problem efficiently, we can use a sliding window technique. The goal is to find the longest subarray of 1s that we can obtain by flipping at most K zeros. The idea is to expand the window to the right while keeping track of how many zeros are inside it. If the number of zeros becomes more than K, we shrink the window from the left until we are within the allowed limit of flips. At each step, we record the maximum window size that fits the requirement. This approach ensures we traverse the array only once.


// Initialize two pointers to represent the current window boundaries.
// Initialize a counter to keep track of the number of zeros in the window.
// Iterate through the array and expand the right boundary of the window.
// Each time a zero is encountered, increment the zero counter.
// If the zero counter exceeds the allowed limit, shrink the window from the left until the count is back within the limit.
// After each expansion, record the maximum window size encountered so far.

//Time Complexity: O(N), We traverse the array only once using two pointers (left and right). Each element is visited at most twice once by the right pointer, and once by the left pointer when shrinking the window.

// Space Complexity: O(1), Only a few integer variables are used to track the window and counters,so the space usage is constant.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the longest subarray with at most k zero flips
    int longestOnes(vector<int>& nums, int k) {

        // Left pointer for the sliding window
        int left = 0;

        // Counter to track how many zeros are in the current window
        int zeros = 0;

        // Variable to store the maximum length found
        int maxLen = 0;

        // Iterate through the array using the right pointer
        for (int right = 0; right < nums.size(); right++) {

            // If current element is zero, increment zero counter
            if (nums[right] == 0) {
                zeros++;
            }

            // If number of zeros exceeds k, shrink the window from left
            while (zeros > k) {
                if (nums[left] == 0) {
                    zeros--;
                }
                // Move the left pointer forward
                left++; 
            }
            // Update the max length of valid window
            maxLen = max(maxLen, right - left + 1);
        }

        // Return the result
        return maxLen;
    }
};

// Driver code
int main() {
    Solution sol;
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;

    // Output the result
    cout << sol.longestOnes(nums, k) << endl;
    return 0;
}


//optimal solution

//Algorithm
// We can optimize the standard sliding window approach by eliminating the inner while-loop. Instead of using an explicit loop to shrink the window when the number of zeros exceeds the allowed flips (K), we can use a single conditional check to move the left pointer forward only when needed. This ensures that each pointer moves in a controlled and efficient manner without unnecessary loop nesting. The logic remains similar to the standard sliding window, but this structure can make the code slightly faster and cleaner in certain languages.
// Initialize two pointers, left and right, both set to 0, and a variable zerocount to keep track of the number of zeros in the current window.
// Traverse the array using the right pointer.
// If the current element is 0, increment zerocount.
// If zerocount exceeds k, check if the element at the left pointer is 0, and if so, decrement zerocount. Then increment the left pointer.
// At each step, calculate the current window size and update the maximum length if it's greater than the previously recorded maximum.
// Continue this process until the right pointer has traversed the entire array.
// Return the maximum window size found.
//Time Complexity: O(N), Each element is processed at most once by the right pointer and once by the left pointer. There’s no nested iteration, so the traversal is strictly linear.

// Space Complexity: O(1), We use only a fixed number of integer variables (left, right, zerocount, maxlen), regardless of input size, so space usage remains constant.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the longest subarray with at most k zero flips
    int longestOnes(vector<int>& nums, int k) {

        // Left pointer of the sliding window
        int left = 0;

        // Counter for zeros in the current window
        int zerocount = 0;

        // Variable to store the maximum valid window length
        int maxlen = 0;

        // Right pointer expands the window
        for (int right = 0; right < nums.size(); right++) {

            // If current element is 0, increment zerocount
            if (nums[right] == 0) {
                zerocount++;
            }

            // If zero count exceeds k, move left pointer and adjust zerocount
            if (zerocount > k) {
                if (nums[left] == 0) {
                    zerocount--;
                }
                // Shrink the window from left
                left++; 
            }

            // Update the maximum window size
            maxlen = max(maxlen, right - left + 1);
        }

        // Return the maximum length found
        return maxlen;
    }
};

// Driver code
int main() {
    Solution sol;
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;

    // Output the result
    cout << sol.longestOnes(nums, k) << endl;
    return 0;
}

