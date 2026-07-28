// Problem Statement: Given an integer array ‘A’ of size ‘N’ and an integer ‘K'. Split the array ‘A’ into ‘K’ non-empty subarrays such that the largest sum of any subarray is minimized. Your task is to return the minimized largest sum of the split. A subarray is a contiguous part of the array.
// ye sbme maximum ka mininum nikalne h and then binarry search
// Example 1:
//  Input Format: N = 5, a[] = {1,2,3,4,5}, k = 3
//  Result: 6
//  Explanation: There are many ways to split the array a[] into k consecutive subarrays. The best way to do this is to split the array a[] into [1, 2, 3], [4], and [5], where the largest sum among the three subarrays is only 6.

// Example 2:
// Input Format: N = 3, a[] = {3,5,1}, k = 3
// Result: 5
// Explanation: There is only one way to split the array a[] into 3 subarrays, i.e., [3], [5], and [1]. The largest sum among these subarrays is 5.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:F
    // Function to count how many partitions are needed
    // if each subarray sum is restricted to at most maxSum
    int countPartitions(vector<int> &a, int maxSum)
    {
        int n = a.size();          // size of the array
        int partitions = 1;        // always have at least 1 partition
        long long subarraySum = 0; // sum of the current subarray

        for (int i = 0; i < n; i++)
        {
            // If adding this element doesn't exceed maxSum, keep adding to current subarray
            if (subarraySum + a[i] <= maxSum)
            {
                subarraySum += a[i];
            }
            else
            {
                // Otherwise, start a new subarray
                partitions++;
                subarraySum = a[i];
            }
        }
        return partitions;
    }
    // algo for optiimal
    // Algorithm
    //  Place the 2 pointers i.e. low and high: Initially, we will place the pointers. The pointer low will point to max(arr[]) and the high will point to sum(arr[]).
    //  Calculate the ‘mid’: Now, inside the loop, we will calculate the value of ‘mid’ using the following formula: mid = (low+high) // 2 ( ‘//’ refers to integer division.
    //  Eliminate the halves based on the number of subarrays returned by countPartitions(): We will pass the potential value of ‘maxSum’, represented by the variable 'mid', to the ‘countPartitions()' function. This function will return the number of partitions we can make.
    //  If partitions > k: On satisfying this condition, we can conclude that the number ‘mid’ is smaller than our answer. So, we will eliminate the left half and consider the right half(i.e. low = mid+1).
    //  Otherwise, the value mid is one of the possible answers. But we want the minimum value. So, we will eliminate the right half and consider the left half(i.e. high = mid-1).
    //  Finally, outside the loop, we will return the value of low as the pointer will be pointing to the answer.
    //  Function to find the smallest maximum subarray sum possible
    //  such that the array is split into exactly k subarrays
    int largestSubarraySumMinimized(vector<int> &a, int k)
    {
        // Lower bound: max element in array (can't be smaller than that)
        int low = *max_element(a.begin(), a.end());
        // Upper bound: sum of entire array (only one subarray)
        int high = accumulate(a.begin(), a.end(), 0);

        // Brute-force: test each possible maxSum from low to high
        for (int maxSum = low; maxSum <= high; maxSum++)
        {
            // If we can form exactly k partitions with this maxSum, return it
            if (countPartitions(a, maxSum) == k)
                return maxSum;
        }
        return low; // fallback
    }
    int largestSubarraySumMinimized_optimal(vector<int> &a, int k)
    {
        // Lower bound: max element in array (can't be smaller than that)
        int low = *max_element(a.begin(), a.end());
        // Upper bound: sum of entire array (only one subarray)
        int high = accumulate(a.begin(), a.end(), 0);
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int partition = countPartitions(a, mid);
            if (partition > k)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return low;
    }
};

int main()
{
    Solution obj;

    return 0;
}