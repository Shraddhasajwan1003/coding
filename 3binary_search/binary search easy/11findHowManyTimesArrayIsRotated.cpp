// Given an integer array arr of size N, sorted in ascending order (with distinct values). Now the array is rotated between 1 to N times which is unknown. Find how many times the array has been rotated.
//Input : arr = [4,5,6,7,0,1,2,3]
// Result: 4
// Explanation: The original array should be [0,1,2,3,4,5,6,7]. So, we can notice that the array has been rotated 4 times.

// Input : arr = [3,4,5,1,2]
// Output : 3
// Explanation: The original array should be [1,2,3,4,5]. So, we can notice that the array has been rotated 3 times.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //brute
    // Function to find the number of rotations in a rotated sorted array
    int findRotations(vector<int>& arr) {
        // Store size of array
        int n = arr.size();

        // Assume the first element is the smallest
        int minVal = arr[0];

        // Index of the smallest element
        int minIndex = 0;

        // Traverse the array
        for (int i = 1; i < n; i++) {
            // If current element is smaller than minVal, update
            if (arr[i] < minVal) {
                minVal = arr[i];
                minIndex = i;
            }
        }

        // The index of smallest element = number of rotations
        return minIndex;
    }
    // Function to find rotation count using one-pass scan
    int findRotationCount(vector<int> &arr) {
    // Get the size of the array
    int n = arr.size();
    // Traverse the array till second-last element
    for (int i = 0; i < n - 1; i++) {//out of bounds bachne ke liye n-1
        // If current element is greater than the next, break point found
        if (arr[i] > arr[i + 1]) {
            // Rotation count is index of next element
            return i + 1;
        }
    }
    // If no break point found, array not rotated
    return 0;
    }

    //same as the find minimum element , its index is rotation count
    int findrotations_optimal(vector<int>&nums){
        int low=0;int high=nums.size()-1;
        while(low<high){
            int mid=low+(high-low)/2;
            if(nums[mid]>nums[high]){//
                low=mid+1;
            }
            else{
                high=mid;
            }
        }
        return low;
    }

};

int main() {
    Solution obj;
    // Example input
    vector<int> arr = {4,5,6,7,0,1,2,3};

    // Call the function and store result
    int rotations = obj.findrotations_optimal(arr);

    // Print result
    cout << rotations << endl;
    return 0;
    
}