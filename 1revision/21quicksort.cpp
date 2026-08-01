//divide and conquer strategy 
//pick ka pivot ( can be any element, can be smallest , first element , largest , median of array )

//put pivot at the correct place 
//two function quicksort and partition function

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
//TC is O(NlogN), worst case has pivot is first element and either smllest or greatest and that shows array is already sorted O(N^2)
    void quicksort(vector<int>&arr, int low , int high){
        if(low<high){
            int pivotindex= partition(arr, low, high);
            quicksort(arr, low, pivotindex-1);
            quicksort(arr, pivotindex+1, high);
        }
    }

    int partition(vector<int>&arr, int low , int high){
        int pivot= arr[high];//pivot taken as last element 
        int i =low-1;
        for(int j=low;j<high;j++){
            if(arr[j]<=pivot){
                i++;
                swap(arr[i],arr[j]);
            }
        }
        swap(arr[i+1],arr[high]);
        return i+1;
    }
};

int main() {
    Solution obj;
    vector<int>&arr={4,1,6,7,3,8,0};
    obj.quicksort(arr, 0 , arr.size()-1);
    for(int num : arr)
        cout<<num<<" ";
    return 0;
}


//how to improve quicsksort 
//use randomised pivot , use insertion sort / heapsort 