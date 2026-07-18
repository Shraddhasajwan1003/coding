#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int>brute_sort_colors(vector<int>&nums){
        //here instead of making new array we can use same nums array for sorting wothout sort function
        int n =nums.size();
        int count0=0;
        int count1=0;
        int count2=0;
        vector<int>arr(nums);
        for(int i =0;i<n;i++){
            if(nums[i]==0)count0++;
            else if(nums[i]==1)count1++;
            else count2++;
        }
        for( int i =0;i<count0;i++){
            arr[i]=0;
        }
        for(int i=count0;i<count0+count1;i++) {
            arr[i]=1;
        }
        for(int i=count0+count1;i<n;i++) {
            arr[i]=2;
        }
        return arr;
    }
    vector<int>optimally_sorting0_1_2_DNF(vector<int>&nums){
        int  n =nums.size();
        int low =0;
        int mid =0;
        int high =n-1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[low],nums[mid]);
                low++;mid++;
            }
            if(nums[mid]==1)mid++;
            if(nums[mid]==2){
                swap(nums[mid],nums[high]);
                high--;
            }

        }
        return nums;
    }

};

int main() {
    Solution obj;
    int n ;cin>>n;
    vector<int>arr;
    for(int i =0;i<n;i++){
        int it;
        cin>>it;
        arr.push_back(it);
    }
    vector<int>result=obj.brute_sort_colors(arr);

    for(auto it : result){
        cout<<it<<" ";
    }
    vector<int>result2=obj.optimally_sorting0_1_2_DNF(arr);
    
    for(auto it : result2 ){
        cout<<it<<" ";
    }
    return 0;
}