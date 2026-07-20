#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
//TC is O(N^2)
    vector<int>leaders_brute(vector<int>&nums){
        int n =nums.size();
        vector<int>ans;//ans vector
        //apne se right ke sare elemnets dekhne h , chote honge to leader h otherwise nhi h 
        for(int i=0;i<nums.size();i++){
            bool leader =true;
            for( int j=i+1;j<nums.size();j++){
                if(nums[j]>=nums[i]){
                    leader=false;
                    break;
                }
            }
            if(leader){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
    //TC is O(N) ans SC is O(1) if we dont count ans vector
    //rather iterating from start we can move from back or array and find out the leaders
    vector<int>leaders_optimal(vector<int>&nums){
        int n=nums.size();
        int max=nums[n-1];
        vector<int>ans;
        if(nums.empty()) {
            return ans;
        }
        ans.push_back(nums[n-1]);
        for(int i =n-2;i>=0;i--){
            if(max<nums[i]){
                ans.push_back(nums[i]);max=nums[i];
            }
        } 
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

int main() {
    Solution obj;
    vector<int>nums={1,20,2,5,6,3,4,1};
    vector<int>ans=obj.leaders_brute(nums);
    for(int i =0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    nums={1,20,2,5,6,3,4,1};
    vector<int>ans2=obj.leaders_optimal(nums);
    for(int i =0;i<ans2.size();i++){
        cout<<ans2[i]<<" ";
    }
    cout<<endl;
    return 0;
}