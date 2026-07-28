// Given an integer array nums, sorted in ascending order (with distinct values) and a target value k. The array is rotated at some pivot point that is unknown. Find the index at which k is present and if k is not present return -1.
// Input:nums = [4, 5, 6, 7, 0, 1, 2], k = 0
// Output :4
// Explanation : Here, the target is 0. We can see that 0 is present in the given rotated sorted array, nums. Thus, we get output as 4, which is the index at which 0 is present in the array.

// Input: nums = [4, 5, 6, 7, 0, 1, 2], k = 3
// Output :-1
// Explanation :Here, the target is 3. Since 3 is not present in the given rotated sorted array. Thus, we get the output as -1.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // brute to h simple linear search ,TC is o(n)
    // Now given is not sorted but binary search still works ,we check on mid , if yes mid==target then return mid ,other wise check for which side is sorted , then go that side, if left sorted then --->check if target falls in range of left , find the target , if not wise go to right do same as left , do till low<=high

    int search(vector<int> &nums, int k)
    {
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] == k)
                return mid;

            // check for left one first
            if (nums[low] <= nums[mid])
            { // low or mid se chota h , it means sorted h
                if (nums[low] <= k && k < nums[mid])
                { // check if k is smaller than mid and greater then low tabhi left sorted side ayega k
                    high = mid - 1;
                }

                else
                {
                    low = mid + 1;
                }
            }

            else
            {
                if (nums[high] >= k && k > nums[mid])
                { // check if k is larger than mid and smaller then high tabhi right sorted side ayega k
                    low = mid + 1;
                }

                else
                {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main()
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    Solution obj;
    int result = obj.search(nums, target);

    cout << "result is:" << result << endl;

    return 0;
}