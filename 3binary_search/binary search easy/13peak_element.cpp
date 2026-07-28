// Given an array of length N, peak element is defined as the element greater than both of its neighbors. Formally, if arr[i] is the peak element, arr[i - 1] < arr[i] and arr[i + 1] < arr[i]. Find the index(0-based) of a peak element in the array. If there are multiple peak numbers, return the index of any peak number.
// Constraints:

// 1 <= nums.length <= 1000
// -231 <= nums[i] <= 231 - 1
// nums[i] != nums[i + 1] for all valid i.
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // there are nultiple peak no in the array and we have to return index of any one
    // cases can be
    // Case 1: An array with a single peak number:
    // Case 2: An array with multiple peaks:
    // Case 3: Last element as peak element:
    //  Case 4: First element as peak element:
    //brute submit krke bhi TLE nhi arha h lol
    int peak_element_index_brute(vector<int> nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            bool left = (i == 0) || nums[i] >= nums[i - 1];
            bool right = (i == n - 1) || nums[i] >= nums[i + 1];

            if (left && right)
                return i;
        }

        return -1;
    }

    int peak_element_optimal(vector<int> nums)
    {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] > nums[mid + 1])
            {
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};

int main()
{
    vector<int> nums = {1, 2, 1, 3, 5, 6, 4};

    // Create object
    Solution obj;

    // Output result
    cout << obj.peak_element_optimal(nums) << endl;
    cout<<obj.peak_element_index_brute(nums);

    return 0;
}