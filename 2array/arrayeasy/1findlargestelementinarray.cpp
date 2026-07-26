//brute force approach ---> sort the array /vector first and then return the arr[n-1], n=arr.size()
// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     int findlargestelementbysorting(vector<int>&arr){
//         int n =arr.size();
//         sort(arr.begin(),arr.end());//TC is O(NlogN), here we have used vector thats why this arr.begin() menthod is used but in case of int arr[] we can use sort(arr,arr+n)
//         return arr[n-1];
//     }
//     int 
// };

// int main() {
//     Solution obj;
//     //here you might face issues if you will not declare the size of vector , you might not be able to take input 
//     int n;
//     cin >>n;
//     vector<int> arr(n);
//     for(auto t:arr){
//         int a ;
//         cin>>a;
//         arr.push_back(a);
//     }
//     //you can also do it this way 
//     //// 1. Ask for the number of elements first int n; cin>>n;
    
//     // 2. Take the inputs using a standard loop
//     // vector<int> arr;
//     // for(int i = 0; i < n; i++) {
//     //     int a;
//     //     cin >> a;
//     //     arr.push_back(a);
//     // }
//     cout<<"Largest:"<<obj.findlargestelementbysorting(arr);

//     return 0;
// }

//optimal approach ----> take one element as max ( take arr[0], bcz it will also cover all negative elements cases) , then update it by iterating the whole array,TC is O(N) 
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // We pass 'n( size of array)' directly into the function
int takemaxelementforfindinglargest(int arr[], int n) {
    //this can be done by vector array also 
    // Safety check: if array is empty
    if (n <= 0) return -1; 
    
    // Initialize with the first element, NOT -1
    int largest = arr[0]; 
    
    // Loop through the array (we can start at i = 1 since we already used arr[0])
    for (int i = 1; i < n; i++) {
        // If we find a bigger number, update our 'largest' variable
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }
    
    // Don't forget to return the answer!
    return largest; 
}
};

int main() {
    Solution obj;
    int n ;
    cin>>n;
    int arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Largest"<<obj.takemaxelementforfindinglargest(arr,n);
    return 0;
}