#include <bits/stdc++.h>
using namespace std; 
// Function to find the largest element in an array
int findlargest(vector<int>&arr, int n){
    n =arr.size();
    sort(arr.begin() , arr.end());
    cout<< arr[n-1];
}
// Driver code
int main(){
    int it;
   vector<int>arr;
   for(auto it:arr){
    cin>>arr[it];
  }
  findlargest(arr,arr.size());
}
