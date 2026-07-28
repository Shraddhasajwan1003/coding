// Given an array of N integers. Every number in the array except one appears twice. Find the single number in the array.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // brute , adajacent ko compare kro, if same then twice aya h otherwise number ko return krdo
    int singleElementInSortedArray_brute(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];

        for (int i = 0; i < n; i++)
        {
            // check if first element and not equal to next, return it (do this same check for last element)
            if (i == 0)
            {
                if (nums[i] != nums[i + 1])
                {
                    return nums[i];
                }
            }
            else if (i == n - 1)
                {
                    if (nums[i] != nums[i - 1])
                    {
                        return nums[i];
                    }
                }
            else{
                    if(nums[i] != nums[i-1] && nums[i] != nums[i+1]){
                        return nums[i];
                    }
                }
            
        }
        return -1;
    }
    //use XOR 
    int singleNonDuplicate_XOR(vector<int>& arr) {
        // Get the size of the array
        int n = arr.size();

        // Initialize the result variable with 0
        int ans = 0;

        // Traverse the array and XOR all elements
        for (int i = 0; i < n; i++) {
            ans = ans ^ arr[i];
        }

        // Return the unique element found using XOR
        return ans;
    }


    int singleNonDuplicate_optimal(vector<int>& arr) {
    // Get the size of the array
    int n = arr.size();

    // Edge case: only one element in the array
    if (n == 1) return arr[0];

    // Edge case: first element is the unique one
    if (arr[0] != arr[1]) return arr[0];

    // Edge case: last element is the unique one
    if (arr[n - 1] != arr[n - 2]) return arr[n - 1];

    // Initialize binary search bounds (exclude first and last index)
    int low = 1, high = n - 2;

    // Perform binary search
    while (low <= high) {
        // Calculate middle index
        int mid = (low + high) / 2;

        // Check if middle element is the unique one
        if (arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1]) {
            return arr[mid];
        }

        // If mid is in the left half (pairing is valid)
        if ((mid % 2 == 1 && arr[mid] == arr[mid - 1]) ||
            (mid % 2 == 0 && arr[mid] == arr[mid + 1])) {
            // Move to the right half
            low = mid + 1;
        }
        // If mid is in the right half (pairing broken earlier)
        else {
            // Move to the left half
            high = mid - 1;
        }
    }

    // Dummy return (not reachable if input is valid)
    return -1;
   }
};

int main()
{
    Solution obj;
    vector<int>nums={1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};
    int ans=obj.singleElementInSortedArray(nums);
    cout<<"the single element is : "<<ans;
    return 0;
}