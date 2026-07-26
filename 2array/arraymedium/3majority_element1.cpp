
//majority element occurs more than N/2 times in the array 
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
//TC is O(N^2)
    int brute_majority_element1(vector<int>arr){
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
    int better_majority_el1(vector<int>arr){
        int n =arr.size();
        unordered_map<int,int>mp;
        for(auto num:arr){
            mp[num]++;
        }
        for(auto&pair : mp){
            if(pair.second>n/2){
                return pair.first;
            }
        }
        return -1;
    }
    //moore's voting
    int optimal_majority_element1(vector<int>arr){
        int n=arr.size();
        int cnt=0;
        int el;
        for(int i =0;i<n;i++){
            if(cnt==0){
                cnt =1;
                el =arr[i];
            }
            else if(el==arr[i])cnt++;
            else cnt--;
            
        }
        int cnt1 = 0;//check if the el now is the majority element
        for (int i = 0; i < n; i++) {
            if (nums[i] == el) {
                cnt1++;
            }
        }
        if(cnt1>(n/2)){
            return el;
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
    cout<<"MAJORITY OCCURRING ELEMENT: "<<obj.better_majority_el1(arr);
    cout<<"MAJORITY OCCURRING ELEMENT: "<<obj.optimal_majority_element1(arr);
    return 0;
}