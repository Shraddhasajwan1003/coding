// You are given an array of integers 'arr' and an integer i.e. a threshold value 'limit'. Your task is to find the smallest positive integer divisor, such that upon dividing all the elements of the given array by it, the sum of the division's result is less than or equal to the given threshold value.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // O(max(arr[])*N), where max(arr[]) = maximum element in the array, N = size of the array. We are using nested loops. The outer loop runs from 1 to max(arr[]) and the inner loop runs for N times.
    // Function to find the smallest divisor such that
    // the sum of ceil(arr[i] / d) over all i <= limit
    int smallestDivisor_brute(vector<int> &arr, int limit)
    {
        int n = arr.size(); // Size of the array

        // Find the maximum element in the array
        int maxi = *max_element(arr.begin(), arr.end());

        // Try every possible divisor from 1 to maxi
        for (int d = 1; d <= maxi; d++)
        {
            int sum = 0;

            // For each element, compute ceil(arr[i] / d) and add to sum
            for (int i = 0; i < n; i++)
            {
                sum += ceil((double)(arr[i]) / (double)(d));
            }

            // If the total sum is within the limit, return this divisor
            if (sum <= limit)
            {
                return d;
            }
        }

        // If no valid divisor is found, return -1
        return -1;
    }
    // Helper function to calculate sum of division results
    int sumByD(vector<int>& arr, int div) {
        int sum = 0;
        for (int num : arr) {
            sum += ceil((double)num / div);
        }
        return sum;
    }

    // Function to find the smallest divisor
    int smallestDivisor(vector<int>& arr, int limit) {
        if (arr.size() > limit) return -1;

        int low = 1;
        int high = *max_element(arr.begin(), arr.end());

        // Binary search to find smallest divisor
        while (low <= high) {
            int mid = (low + high) / 2;
            if (sumByD(arr, mid) <= limit) {
                high = mid - 1;  // Try smaller divisor
            } else {
                low = mid + 1;   // Try larger divisor
            }
        }

        return low;
    }
    //leetcode solution 1283
    // int sumofdiv(vector<int>&arr,int divisor){
    //     int sum=0;
    //     // for (int num : arr) {
    //     //     sum += ceil((double)num / divisor);
    //     // }
    //     // return sum;//better to use normal loop
    //     int n=arr.size();
    //     for(int i =0;i<n;i++){
    //         sum+=ceil((double)arr[i]/divisor);
    //     } 
    //     return sum;
    // }
    // int smallestDivisor(vector<int>& nums, int threshold) {
    //     if(nums.size()>threshold)return -1;
    //     int low=1;
    //     int high=*max_element(nums.begin(),nums.end());
    //     while(low<=high){
    //         int mid=low + (high-low)/2;
    //         if(sumofdiv(nums,mid)<=threshold){
    //             high=mid-1;
    //         }else{
    //             low=mid+1;
    //         }
    //     }
    //     return low;
    // }

};

int main()
{
    Solution obj;
    vector<int> arr = {1, 2, 3, 4, 5};
    int limit = 8;

    Solution obj;
    int ans = obj.smallestDivisor_brute(arr, limit);
    return 0;
}