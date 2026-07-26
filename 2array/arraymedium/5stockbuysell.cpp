#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //TC is O(N^2)
    int brute_max_profit(vector<int>&arr){
        int n =arr.size();
        int profit;
        int maxprofit=INT_MIN;
        for(int i=0;i<n;i++ ){
            for(int j =i+1;j<n;j++){
                profit=arr[j]-arr[i];
                maxprofit=max(maxprofit,profit);
            }
        }
        return maxprofit;
    }
    int optimal_max_profit(vector<int>&arr){
        int miniprice=INT_MAX;
        int maxprofit=0;
        int n =arr.size();
        for( int i =0;i<n;i++){
            // if(arr[i]<miniprice){
            //     miniprice=arr[i];
            // }
            // else{
            //     maxprofit=max(maxprofit,arr[i]-miniprice);
            // }
            //leetcode style 
            miniprice=min(miniprice,arr[i]);
            maxprofit=max(maxprofit,arr[i]-miniprice);
        }
        return maxprofit;
    }
};

int main() {
    Solution obj;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << obj.optimal_max_profit(prices) << endl;
    cout << obj.brute_max_profit(prices) << endl;
    return 0;
}