#include <bits/stdc++.h>
using namespace std;
// brute has N^2 TC , and 2 loops that check for maxlen and store sum , if sum==0 then len++ , max  of len is returned
class Solution
{
public:
    // optimal
    int solve(int A[], int n)
    {

        // map prefix sum -> first index seen
        unordered_map<int, int> mpp;
        // best length so far
        int maxi = 0;
        // running prefix sum
        int sum = 0;

        // iterate over the array
        for (int i = 0; i < n; i++)
        {
            // update running sum
            sum += A[i];

            // if sum is zero, subarray [0..i] has zero sum
            if (sum == 0)
            {
                // update best length
                maxi = i + 1;
            }
            // otherwise check if this sum was seen before
            else
            {
                // when seen, zero-sum segment between previous index + 1 and i
                if (mpp.find(sum) != mpp.end())
                {
                    // maximize length
                    maxi = max(maxi, i - mpp[sum]);
                }
                // first time seeing this sum
                else
                {
                    // record index
                    mpp[sum] = i;
                }
            }
        }

        // return best length
        return maxi;
    }
}
}
;

int main()
{
    Solution obj;

    return 0;
}