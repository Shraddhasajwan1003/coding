// checking if array is sorted , we will take one element and check whether all the values next to it are less than it , 
//take one element idx =0 check with all if any found greater return false , if for idx=1 then check from idx=2 and so on 
// a nested loop is used here 
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool byusingnestedloop(int arr[], int n ){//TC is O(N^2)
            
            for( int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    if( arr[i]>arr[j])return false;

                }
            }
            return true;
    }
    
    bool by_comparing_adjacent_elements(int arr[], int n ){//TC is O(N)
        
        for( int i=0;i<n-1;i++){//used n-1 here to stop array from going out of bounds 
            if(arr[i]>arr[i+1])
            return false;
        }
        return true;
    }
    bool checkif_rotated_sorted(vector<int>& nums) {
        int n = nums.size();
        int drops = 0;
        
        for (int i = 0; i < n; i++) {
            // Use modulo operator % to easily wrap around and compare the last element to the first
            if (nums[i] > nums[(i + 1) % n]) {
                drops++;
            }
        }
        
        // If it drops more than once, it cannot be a sorted and rotated array
        return drops <= 1;
    }
};

int main() {
    Solution obj;
    int n ;//size of array 
    cin>>n;
    int arr[n];
    vector<int>nums(n);
    for(auto it:nums){
        int x;
        cin>>x;
        nums.push_back(x);
    }
    for( int i =0;i<n;i++){
        cin>>arr[i];
    }
    cout <<(obj.by_comparing_adjacent_elements(arr,n)?"true":"false")<<endl;
    cout <<(obj.byusingnestedloop(arr,n)?"true":"false")<<endl;
    cout<<(obj.checkif_rotated_sorted(nums)?"true":"false");
    
    return 0;
}

