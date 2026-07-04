//two approach possible for this question 
//brute uses a temp array to find all non zeroes in array and then copy it , then paste back to the array leaving zeroes at end and nonzeroes in order at first
#include <bits/stdc++.h>
using namespace std;

// Solution class
class Solution {
public:
    // Function to move all zeroes to end
    vector<int> moveZeroes(vector<int>& arr) {
        // Create temp array
        vector<int> temp(arr.size(), 0);

        // Pointer to fill temp
        int index = 0;

        // Traverse input array
        for (int i = 0; i < arr.size(); i++) {
            // If non-zero, add to temp
            if (arr[i] != 0) {
                temp[index] = arr[i];
                index++;
            }
        }

        // Copy back temp to original
        for (int i = 0; i < arr.size(); i++) {
            arr[i] = temp[i];
        }

        // Return updated array
        return arr;
    }
};

// Main function
int main() {
    vector<int> arr = {0, 1, 0, 3, 12};
    Solution sol;
    vector<int> result = sol.moveZeroes(arr);

    // Print result
    cout << "Array after moving zeroes: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}

//optimal has inspace method (thst is no extra space needed)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int>movezerostoend(vector<int>&nums){
        int n = nums.size();
        int j=0;
        for(int i =0;i<n;i++){
            if (nums[i]!=0){
                swap(nums[i],nums[j]);
                j++;
            }
        }
        return nums;
    }
};

int main() {
    Solution obj;
    int n ;
    cin>>n;
    vector<int>arr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    // 1. Capture the returned vector
    vector<int> result = obj.movezerostoend(arr);
    
    // 2. Print the vector
    for (int nums : result) {
        cout << nums << " ";
    }
    cout << endl;
    
    return 0;
}