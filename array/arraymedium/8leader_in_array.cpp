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
    vector<int>leaders_optimal(vector<int>&nums){
        
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
    return 0;
}