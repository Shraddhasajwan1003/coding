#include <bits/stdc++.h>
using namespace std;
// floor of x is the largest element in the array which is smaller than or equal to x. The ceiling of x is the smallest element in the array greater than or equal to x
class Solution {
public:
    int findfloor(int arr[],int n , int x){
        // int n = arr.length; here given already 
        int low =0 ; int high = n-1;int ans=-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(arr[mid]<=x){
                ans = mid;
                high = mid-1;
            }
            else {
                low = mid +1;
            }
        }
        return ans;
    }
    //finding ceil == lower bound nikalna
    int findceil(int arr[],int n , int x){
        // int n = arr.length; here given already 
        int low =0 ; int high = n-1;int ans=-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(arr[mid]>=x){
                ans = mid;
                high = mid-1;
            }
            else {
                low = mid +1;
            }
        }
        return ans;
    }
};

int main() {
    Solution obj;
    int arr[] = {3, 4, 4, 7, 8, 10};
    int n = 6, x = 5;
    pair<int, int> ans1 = obj.findfloor(arr, n, x);
    pair<int, int> ans2 = obj.findceil(arr, n, x);
    cout << "The floor and ceil are: " << ans.first << " " << ans.second << endl;
    return 0;
} 