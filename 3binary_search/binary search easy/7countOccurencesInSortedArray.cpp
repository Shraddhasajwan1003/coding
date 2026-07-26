// given target count occurences in an array 
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
//TC is O(N)
    int count_occurences_brute(vector<int>&nums , int target ){
        int n = nums.size();
        int cnt=0;
        for(int i =0;i<n;i++){
            if(nums[i]==target){
                cnt++;
            }
        }
        return cnt;
    }
    //TC is O(2logN)
    //logic is that we do last_occurence-first_occurence+1; we get total occurences
    int first_occurences(vector<int>&nums, int k){
        int n =nums.size();
        int low =0;
        int high=n-1;
        int first=-1;
        while(low<=high){
            int mid= low+(high-low)/2;
            if(nums[mid]==k){
                first=mid;
                high=mid-1;//search smaller index, so go left 
            }
            else if (nums[mid]>k){
                high =mid-1;
            }
            else low=mid+1;
        }
        return first;
    }
    int last_occurences(vector<int>&nums, int k ){
        int n =nums.size();
        int low =0;
        int high=n-1;
        int last=-1;
        while(low<=high){
            int mid= low+(high-low)/2;
            if(nums[mid]==k){
                last=mid;
                low=mid+1;//search larger index, so go right
            }
            else if (nums[mid]>k){
                high =mid-1;
            }
            else low=mid+1;
        }
        return last;
    }

    pair<int,int> firstandlastposition(vector<int>& nums, int k ){
        int first=first_occurences(nums, k);
        if(first==-1)return {-1,-1};
        int last= last_occurences(nums, k);
        return {first,last};
    }
    int count(vector<int>&nums,int k){
        pair<int,int>ans=firstandlastposition(nums, k);
        if (ans.first==-1)return 0;
        return (ans.second-ans.first+1);
    }
};

int main() {
    Solution obj;
    vector<int>nums={2,4,6,8,8,8,10,11};
    int k =8;
    int ans=obj.count(nums,k);
    cout<<"the number of occurences is : "<<ans;
    return 0;
}