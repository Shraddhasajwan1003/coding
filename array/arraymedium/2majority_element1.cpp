
//majority element occurs more than N/2 times in the array 
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
//TC is O(N^2)
    int brute_majority_element1(vector<int>&arr){
        int n =arr.size();
        for(int i =0;i<n;i++){
            int cnt =0;
            for(int j =0;j<n;j++){
                if(arr[j]==arr[i])cnt++;
            }
            if (cnt>(n/2))return arr[i];
        }
        return -1;
    }
    

};

int main() {
    Solution obj;
    int n;cin>>n;
    vector<int>arr;
    for(int i=0;i<n;i++) {
        int x;
        cin>>x;
        arr.push_back(x);
    }
    cout<<"MAJORITY OCCURRING ELEMENT: "<<obj.brute_majority_element1(arr);
    return 0;
}