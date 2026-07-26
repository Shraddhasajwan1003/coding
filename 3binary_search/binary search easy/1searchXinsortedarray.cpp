
//You are given a sorted array of integers and a target, your task is to search for the target in the given array. Assume the given array does not contain any duplicate numbers.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int binarysearch_iterative(vector<int>& nums,int target){
        // we use to pointer high and low and mid=(low+high)/2; there we do integer division
        //here serach space is sorted 
        //we do divide and conquer , we divide the array in 2 parts
        //TC is O(logN)
        int n =nums.size();
        int low=0;int high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target)return mid;
            else if(nums[mid]>target)high=mid-1;
            else low=mid+1;
        }
        return -1;
    }
    int binarysearch(vector<int>& nums, int target , int low , int high){
        if(low>high)return -1;//base case 
        int mid = (low+high)/2;
        if(nums[mid]==target)return mid;
        else if ( nums[mid]>target)return binarysearch(nums,target,low,mid-1);//left half 
        else return binarysearch(nums,target,mid+1,high);//right half search

    }

    int search(vector<int>& nums, int target){
        return binarysearch(nums, target,0,nums.size()-1);
    }
};

int main() {
    vector<int> a = {3, 4, 6, 7, 9, 12, 16, 17}; // sorted array
    int target = 6; // target element to search

    Solution obj; // Create object of Solution class
    int ind = obj.binarysearch_iterative(a, target);
    int recur= obj.search(a,target);

    if (ind == -1) cout << "The target is not present." << endl;
    else cout << "The target is at index: " << ind << endl;

    if (recur == -1) cout << "The target is not present." << endl;
    else cout << "The target is at index: " << recur << endl;


    return 0;
}