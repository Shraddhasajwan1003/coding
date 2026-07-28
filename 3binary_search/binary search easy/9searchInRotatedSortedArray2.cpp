// Given an integer array arr of size N, sorted in ascending order (may contain duplicate values) and a target value k. Now the array is rotated at some pivot point unknown to you. Return True if k is present and otherwise, return False.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // brute me same h k mila to return true
    //  but in optimal its different bcz repeated allowed h to ek edge case h that it high , low , mid is equal so us condition me binary serach can fail, thats why we put a check , check mid , low and high if they are equal make low++ and high-- and then continue
    bool searchelementinrotatedsortedarray2(vector<int> &nums, int k)
    {
        int high = nums.size() - 1;
        int low = 0;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            // Edge case: all three are equal, we cannot determine which side is sorted
            if (nums[low] == nums[mid] && nums[mid] == nums[high])
            {
                low++;
                high--;
                continue;
            }
            if (nums[mid] == k)
                return true;
            // left side sorted check
            if (nums[mid] >= nums[low])
            {
                if (nums[mid] > k && nums[low] <= k)
                {
                    high = mid - 1;
                }
                else
                    low = mid + 1;
            }
            else
            {
                if (nums[mid] < k && nums[high] >= k)
                {
                    low = mid + 1;
                }
                else
                    high = mid - 1;
            }
        }
        return false;
    }
};

int main()
{
    Solution obj;
    vector<int> nums = {7, 8, 1, 2, 3, 3, 3, 4, 5, 6};
    int k = 3;
    bool res = obj.searchelementinrotatedsortedarray2(nums, k);
    if (!res)
    {
        cout << "Target not found";
    }
    else
        cout << "Target found";
    return 0;
}