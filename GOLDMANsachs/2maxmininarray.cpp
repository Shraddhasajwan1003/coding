#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    pair<int, int> getminmaxbrute( vector<int>& arr) {
        if (arr.empty()) return {0, 0};//in case array array is empty 
        //TC is O(N)
        int maxi = arr[0];
        int mini = arr[0];
        for (int i = 1; i < (int)arr.size(); i++) {
            if (arr[i] > maxi) maxi = arr[i];
            if (arr[i] < mini) mini = arr[i];
        }
        return {mini, maxi};
    }
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        int n =mat.size();
        int m =mat[0].size();
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(mat[i][j]==x)return true;
            }
        }
        return false;
    }
};
int main() {
    Solution obj;
    vector<int>nums;
    int n ;
    cin>>n;
    for(int i =0;i<n;i++){
        int a ;
        cin>>a;
        nums.push_back(a);
    }
    pair<int, int>result=obj.getminmaxbrute(nums);
    cout<<result.first<<" "<<result.second;
    cout<<endl;

    //matrix search question in the link 
    int x,y;
    cin>>x>>y;
    vector<vector<int>>mat(x,vector<int>(y));
    cout<<"Enter matrix elements:\n";
    for(int i=0;i<x;i++){
        for(int j =0;j<y;j++){
            cin>>mat[i][j];
        }
    }
    int u;
    cout<<"Enter elements to search"<< endl;
    cin>>u;
    //answer 
    cout<< (obj.searchMatrix(mat,u)?"True":"False");
    return 0;
}