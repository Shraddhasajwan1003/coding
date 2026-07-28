//Problem Statement:
// Given an integer array arr of size N, sorted in ascending order (with distinct values), the array is rotated at any index which is unknown. Find the minimum element in the array.
// Constraints:
// n == nums.length
// 1 <= n <= 5000
// -5000 <= nums[i] <= 5000
// All the integers of nums are unique.
// nums is sorted and rotated between 1 and n times.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //brute that we can search linearly 
    int findMin(vector<int>& nums){
        int mini= INT_MAX;
        int n =nums.size();
        for(int i =0;i<n;i++){
            mini=min(mini,nums[i]);
        }
        return mini;
    }

    //optimal takes binary search , smallest element represents point of rotation 
    //binary search ka use krke we can find this pivot 
    //we compare mid to rightmost in search
    int findMinInRotatedSortedArray(vector<int>& nums){
        int low=0;
        int high =nums.size()-1;
        while(low<high){
            int mid = low+(high-low)/2;
            if(nums[mid]>nums[high]){
                //true h to means mini is right side
                low=mid+1;
            }else{
                high=mid;
            }
        }
        return nums[low];
    }
};

int main() {
    Solution obj;
    vector<int>nums= {3,4,5,7,8,1,2};
    int result=obj.findMin(nums);
    cout<<"Minimum element in rotated sorted array : "<<result;
    return 0;
}