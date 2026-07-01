/*iteration 1 : mini nikalo array ka , then we will swap that first element elemnet we started iterating with , with the mini , mini or first ko swap krdo , ab hmara first index yani idx=0 is sorted , then next iteration 2, usme start from index =1 , therefore idx++ hua hoga prevoius step me , then again find mini ,swap it with starting index in this case idx=1 and so on after n-1 iterations array is sorted  */
#include <bits/stdc++.h>
using namespace std;
//TC is O(N^2)
class Solution {
public:
    void selectionsort (int arr[], int n ){//take array and size of array as input 
        for ( int i =0; i<n-1;i++){//Writing it as i < n and j = i is not "wrong" because it doesn't break the sort, but it is inefficient.
            //by taking n-1 we are avoiding extra iteration and by j=i+1 avoids one extra comparison that is present if j=i
            int mini =i;// take index as minimum 
            for( int j=i+1;j<n-1;j++){
                if ( arr[j]<arr[mini]){//check if any index j has value lesser than value on mini index
                    mini =j;//value if index of j is less than that of mini then update mini with j  
                }
            }
            swap(arr[i],arr[mini]);//swap the mini and index we assumed to be mini at first, this way upto index i is sorted 
        }
        for( int i =0;i<n;i++){//print sorted array 
            cout<<arr[i]<<" ";
        }
    }
};

int main() {
    Solution obj;
    int n ;
    cin>>n;
    int arr[n];
    for( int i =0;i<n;i++){
        cin>>arr[i];
    }
    n=sizeof(arr)/sizeof(arr[0]);
    obj.selectionsort(arr,n);
    return 0;
}