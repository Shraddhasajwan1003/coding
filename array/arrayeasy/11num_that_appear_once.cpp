#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int brute_to_find_no_that_appear_once_other_twice(vector<int>&arr){
        int n= arr.size();
        for(int i =0;i<n;i++){
            int num=arr[i];
            int cnt=0;
            for(int j=0;j<n;j++){
                if(arr[j]==num){
                    cnt++;
                }
            }
            if(cnt==1)return num;
        }

        return -1;
    }
    int getSingleElement(vector<int>& arr) {
        int n = arr.size();

        // Step 1: Find the maximum value in the array
        int maxi = arr[0];
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, arr[i]);
        }

        // Step 2: Declare and initialize hash array of size maxi+1
        vector<int> hash(maxi + 1, 0);

        // Step 3: Count the frequency of each number
        for (int i = 0; i < n; i++) {
            hash[arr[i]]++;
        }

        // Step 4: Find the element that occurs exactly once
        for (int i = 0; i < n; i++) {
            if (hash[arr[i]] == 1)
                return arr[i];
        }

        return -1; // fallback, shouldn't occur in valid input
    }
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int num : nums) {
            ans ^= num; // XOR each number
        }
        return ans;
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
    cout<<"num that appear once by brute "<<obj.brute_to_find_no_that_appear_once_other_twice(arr)<<endl;
    cout<<"num that appear once by better "<<obj.getSingleElement(arr)<<endl;
    cout<<"num that appear once by optimal  "<<obj.singleNumber(arr)<<endl;
    return 0;
}