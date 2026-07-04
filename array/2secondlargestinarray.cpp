//two approaches
//brute force ---> sort then return n-2 , 1 element , TC is O(NlogN)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void returns2ndlargest_2ndsmallest(int arr[], int n){
        if(n==0||n==1) 
            cout << -1 << " " << -1 << endl;  // Print -1 for both second smallest and second largest if the array has less than 2 elements
        //bettetr to use if (n<2)return -1;
        // sort (arr.begin(),arr.end()); this cannot be used here this is for vector only
        sort(arr,arr+n);
        cout<<"Second largest: "<<arr[n-2]<<"\n";
        cout<<"Second smallest: "<<arr[1]<<"\n";
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
    obj.returns2ndlargest_2ndsmallest(arr,n);
    return 0;
}


//optimal approach ----> taking 2 variable for finding second one ( one small and one second_small both equal to INT_MAX , same for largest both equal to int_min )
//TC is O(N) or 2N
#include<bits/stdc++.h>
using namespace std;

// Function to find the second smallest element in the array
int secondSmallest(int arr[], int n) {
    // Edge case: if the array has fewer than 2 elements
    if (n < 2)
        return -1;

    int small = INT_MAX;
    int second_small = INT_MAX;

    // Loop through the array to find the second smallest element
    for (int i = 0; i < n; i++) {
        // Update the smallest and second smallest values
        if (arr[i] < small) {
            second_small = small;
            small = arr[i];
        } 
        else if (arr[i] < second_small && arr[i] != small) {
            second_small = arr[i];
        }
    }
    return second_small; // Return the second smallest element
}

// Function to find the second largest element in the array
int secondLargest(int arr[], int n) {
    // Edge case: if the array has fewer than 2 elements
    if (n < 2)
        return -1;

    int large = INT_MIN, second_large = INT_MIN;

    // Loop through the array to find the second largest element
    for (int i = 0; i < n; i++) {
        // Update the largest and second largest values
        if (arr[i] > large) {
            second_large = large;
            large = arr[i];
        } 
        else if (arr[i] > second_large && arr[i] != large) {
            second_large = arr[i];
        }
    }
    return second_large; // Return the second largest element
}

int main() {
    // Array of elements
    int arr[] = {1, 2, 4, 7, 7, 5};  

    // Calculate the size of the array
    int n = sizeof(arr) / sizeof(arr[0]);

    // Find the second smallest and second largest elements
    int sS = secondSmallest(arr, n);
    int sL = secondLargest(arr, n);

    // Output the results
    cout << "Second smallest is " << sS << endl;
    cout << "Second largest is " << sL << endl;

    return 0;
}