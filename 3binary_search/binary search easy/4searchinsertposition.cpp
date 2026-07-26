#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int serachinsertposition(vector<int>&nums, int x){
        int n =nums.size();
        int low=0;
        int high =n-1;
        int ans=n;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]>=x){
                ans =mid;
                high=mid-1;
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
    vector<int>a={2,3,4,5,6,7,8,10};
    int target=8;
    int res= obj.serachinsertposition(a,target);
    cout<<"Insertion position is :"<<res;
    return 0;
}