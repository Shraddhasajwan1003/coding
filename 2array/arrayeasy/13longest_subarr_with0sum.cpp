#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int brute_longest_subarrwith0sum( vector<int>&arr){//same is optimal 
        int maxlen =0;
        unordered_map<int,int>mp;//srore prefix sum and first index seen
        int sum=0;
        int n =arr.size();
        for( int i =0;i<n;i++){
            sum+=arr[i];
            // if sum is zero, subarray [0..i] has zero sum
            if (sum == 0) {
                // update best length
                maxlen = i + 1;
            }
            // if this sum seen before, subarray (prevIndex..i] has zero sum
            else if (mp.find(sum) != mp.end()) {
                // maximize length using previous index
                maxlen = max(maxlen, i -mp[sum]);
            }
            // first time seeing this sum, store its index
            else {
                mp[sum] = i;
            }
        }
        return maxlen;
    }
};

int main() {
    Solution obj;
    int n ;cin>>n;
    vector<int>arr;
    for(int i =0;i<n;i++){
        int x;cin>>x;
        arr.push_back(x);
    }
    cout<<"MAX LENGTH OF SUBARRAY WITH SUM 0: "<<obj.brute_longest_subarrwith0sum(arr);
    return 0;
}