#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int upperbound_optimal(vector<int>&nums, int n , int x){
        int low =0;
        int high =n-1;
        int ans =n;
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid]>x){
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