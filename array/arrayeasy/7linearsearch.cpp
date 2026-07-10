#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int linear_search(vector<int>&nums,int target){
        int n =nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==target){
                return i;
            }
        }
        return -1;
    }
};

int main() {
    Solution obj;
    cout<<"Vector size";
    int x;
    cin>>x;
    vector<int>vec;
    for(int i=0;i<x;i++){
        int a;
        cin>>a;
        vec.push_back(a);   
    }
    int n ;
    cout<<"Select target element:";
    cin >>n;
    int result =obj.linear_search(vec,n);
    cout<<"Desired index: "<<result;
    return 0;
}