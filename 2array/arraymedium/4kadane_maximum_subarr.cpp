#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // you can do for brute with N^3 also by adding one loop inside j
    int brute_max_subarr(vector<int> &arr)
    {
        int n = arr.size();
        int maxsum = INT_MIN; // bcz it has negatives too
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = 1; j < n; j++)
            { // use j=1 always here
                sum += arr[j];
                maxsum = max(sum, maxsum);
            }
        }
        return maxsum;
    }
    int kadane_for_maximum_sum(vector<int> &arr)
    {
        int n = arr.size();
        int sum = 0;          // take this as long long acc to question
        int presum = INT_MIN; // this as long long too
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            if (sum > presum)
            {
                presum = sum;
            }
            if (sum < 0)
            {
                sum = 0;
            }
        }
        return presum;
    }
    // leetcode way of kadane
    int maxSubArray(vector<int> &nums)
    {
        int currSum = nums[0];
        int maxSum = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            currSum = max(nums[i], currSum + nums[i]);
            maxSum = max(maxSum, currSum);
        }

        return maxSum;
    }
    // printing maximum subarray
    int printing_maximum_subarray(vector<int> &arr)
    {
        int n = arr.size();
        long long sum = 0;
        long long presum = LLONG_MIN;
        int start = 0;
        int anstart = -1;
        int ansend = -1;
        for (int i = 0; i < n; i++)
        {
            // update starting index if sum is reset
            if (sum == 0)
            {
                start = i;
            }

            // add current element to the sum
            sum += arr[i];

            /* Update maxi and subarray indice
            s if current sum is greater*/
            if (sum > presum)
            {
                presum = sum;
                anstart = start;
                ansend = i;
            }

            // Reset sum to 0 if it becomes negative
            if (sum < 0)
            {
                sum = 0;
            }
        }
        // Printing the subarray
        cout << "The subarray is: [";
        for (int i = anstart; i <= ansend; i++) {
            cout << arr[i] << " ";
        }
        cout << "]" << endl;
        
        // Return the maximum subarray sum found
        return presum;
    }
};

    int main()
    {
        Solution obj;
        vector<int> arr = {-1, 2, -2, 9, 8, 3, -7, -6, 2, 20, 1, -9};
        cout << obj.brute_max_subarr(arr) << endl;
        cout << obj.kadane_for_maximum_sum(arr) << endl;
        cout<<obj.printing_maximum_subarray(arr);
        return 0;
    }