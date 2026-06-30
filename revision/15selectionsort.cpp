/*iteration 1 : mini nikalo array ka , then we will swap that first element elemnet we started iterating with , with the mini , mini or first ko swap krdo , ab hmara first index yani idx=0 is sorted , then next iteration 2, usme start from index =1 , therefore idx++ hua hoga prevoius step me , then again find mini ,swap it with starting index in this case idx=1 and so on after n-1 iterations array is sorted  */
#include <bits/stdc++.h>
using namespace std;

// Function to perform selection sort
void selection_sort(int arr[], int n) {
    // Traverse the array
    for (int i = 0; i < n - 1; i++) {
        int mini = i; // Assume current index holds the minimum value

        // Find the index of the smallest element in the remaining array
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[mini]) {
                mini = j; // Update mini if smaller element is found
            }
        }

        // Swap the found minimum element with the first element of unsorted part
        int temp = arr[mini];
        arr[mini] = arr[i];
        arr[i] = temp;
    }

    // Print the sorted array
    cout << "After selection sort: " << "\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main() {
    // Initialize array
    int arr[] = {13, 46, 24, 52, 20, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Print array before sorting
    cout << "Before selection sort: " << "\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    // Call selection sort
    selection_sort(arr, n);

    return 0;
}
