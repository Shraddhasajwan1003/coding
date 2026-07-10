#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
//we have to return length of the longest subarray that has sum==target
//TC is O(N^3)
    int brute_longest_subarrwithsumk(vector<int>& nums,int target){
        int n =nums.size();
        int len=0;
        for(int i =0;i<n;i++){
            for(int j=i;j<n;j++){
                int sum=0;
                for(int u=i;u<=j;u++){
                    sum+=nums[u];
                }
                if(sum==target)len=max(len,j-i+1);

            }
        }
        return len;
    }
    //TC is O(N)
    int optimal_app(vector<int>& nums,int target){
        int left =0;
        int right=0;
        int sum= nums[0];
        int n =nums.size();
        int maxlen=0;
        while(right<n){
            while(left<=right && sum>target){
                sum-=nums[left];
                left++;
            }
            if(sum==target){
                maxlen=max(maxlen,right-left+1);
            }
            right++;
            if(right<n){
                sum+=nums[right];
            }

        }
        return maxlen;
    }
};

int main() {
    Solution obj;
    int n;cin>>n;
    vector<int>arr;
    for(int i =0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    int k;cin>>k;
    cout<<"length of subarray: "<<obj.brute_longest_subarrwithsumk(arr,k)<<endl;
    cout<<"length of subarray: "<<obj.optimal_app(arr,k);
    return 0;
}