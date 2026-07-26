#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //lower bound :lower bound algorithm finds the first or the smallest index in a sorted array where the value at that index is greater than or equal to a given key i.e. x.
    //arr[ind]>=x
    //upper bound arr[ind]>x
    //n is size of array , x is the number we hav eto find the lower bound of 
    int lowerbound_iterative(vector<int>& nums, int n ,int x){//TC is O(N)
        //use a loop and find the lower bound
        for(int i =0;i<n;i++){
            if(nums[i]>=x)return i;
        }
        return n ;//if all elements are smaller than x 
    }
    int lowerbound_optimal(vector<int>&nums, int n , int x){
        int low =0;
        int high =n-1;
        int ans =n;
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid]>=x){
                ans=mid;
                high =mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }


};

int main() {
    Solution obj;

    return 0;
}