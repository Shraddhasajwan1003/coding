#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
//TC is O(N^2)
    bool twosumbrute(vector<int>&arr, int target){
        int n =arr.size();
        for(int i=0;i<n;i++){
            for(int j=1;j<n;j++){
                if (arr[i]+arr[j]==target)return true;//if you want to return the indices use vector type function and say return{i,j} and return {-1,-1}
            }
        }
        return false;
    }
    // for btter approach we will store all the elements in hashmap with index then i willl loop the elements and find the matching one in hashmap 
    bool twosumbetter(vector<int>&arr, int target){
        unordered_map<int , int>mp;
        for(int i;i<(int)arr.size();i++){
            int complement=target-arr[i];
            if(mp.find(complement)!=mp.end()){
                return "Yes";
            }
            mp[arr[i]]=i;//store current element for future 
        }
        return "no";
    }
    //two pointer approach here, so we use a map to store the indices 
    vector<int> twosumoptimal(vector<int>&arr, int target){
       int n = arr.size();
        vector<pair<int, int>> numsWithIndex;
        for (int i = 0; i < n; i++) {
            numsWithIndex.push_back({arr[i], i});//stored element and index
        }
        sort(numsWithIndex.begin(), numsWithIndex.end());

        int left = 0, right = n - 1;
        while (left < right) {
            int sum = numsWithIndex[left].first + numsWithIndex[right].first;
            if (sum == target) {
                // Return original indices
                return {numsWithIndex[left].second, numsWithIndex[right].second};
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
        return {-1, -1};  // No pair found
    }
    string optimal_for_return_of_true_false(vector<int>&arr, int target){
         int n = arr.size();
        // Create a vector of pairs to remember original indices after sorting
        vector<pair<int, int>> numsWithIndex;
        for (int i = 0; i < n; i++) {
            numsWithIndex.push_back({arr[i], i});
        }
        // Sort based on the element values
        sort(numsWithIndex.begin(), numsWithIndex.end());

        int left = 0, right = n - 1;
        // Loop until pointers cross
        while (left < right) {
            int sum = numsWithIndex[left].first + numsWithIndex[right].first;
            if (sum == target) {
                return "YES";  // Pair found
            } else if (sum < target) {
                left++;  // Need bigger sum, move left pointer right
            } else {
                right--; // Need smaller sum, move right pointer left
            }
        }
        return "NO";  // No pair found
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
    int target;cin>>target;
    cout<<"DOES TWO NO WITH SUM K EXIST: "<<obj.twosumbrute(arr,target)<<endl;
    cout<<"DOES TWO NO WITH SUM K EXIST: "<<obj.twosumbetter(arr,target)<<endl;
    cout<<"DOES TWO NO WITH SUM K EXIST: "<<obj.twosumoptimal(arr,target)<<endl;
    cout<<"DOES TWO NO WITH SUM K EXIST: "<<obj.optimal_for_return_of_true_false(arr,target)<<endl;
    return 0;
}