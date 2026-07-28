#include <bits/stdc++.h> //includes <algorithm> header file too
using namespace std;

class Solution
{
public:
    // brute total TC is O(n*max(a[])) SC is O(1), optimal ka O(n*log(max(a[])))
    // read after koko brute function
    //  Function to calculate total hours for given speed
    int calculateTotalHours_brute(vector<int> &a, int hourly)
    {
        int totalHours = 0;
        for (int pile : a)
        {
            // Add hours using ceil
            totalHours += (pile + hourly - 1) / hourly;
        }
        return totalHours;
    }

    int koko_brute(vector<int> &nums, int h)
    {
        // have to find k. nums is pile that has bananas on each index, so he must complete eating all bananas in h hours
        // how many bananas koko must eat in an hour to eat all the bananas on time h
        // find largest pile of banana(max element)
        // loop chalao 1 to max value for this value
        // calculate toatal hours for each speed
        // sum of all hours for all piles
        // if total hours equal or less than the total return the speed

        int n = nums.size();
        // below is maximum element finding function but we have used here a standard library function provided by algorithm , runs this same loop internally
        // int maxi=nums[0];
        // for(int i =1;i<=n;i++){
        //     if(nums[i]>maxi){
        //         maxi=nums[i];
        //     }
        // }
        int maxval = *max_element(nums.begin(), nums.end());
        for (int i = 1; i <= maxval; i++)
        {
            int total_hr = calculateTotalHours_brute(nums, i);

            if (total_hr <= h)
            {
                return i;
            }
        }
        return maxval;
    }
    // helper function for optimal
    //  Function to calculate total hours at given speed
    long long calculatetotalhr(vector<int> &piles, int speed)
    {
        long long totalh = 0;
        for (int it : piles)
        {
            totalh += ceil((double)it / speed);
        }
        return totalh;
    }
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int maxpile = *max_element(piles.begin(), piles.end());

        int low = 1;
        int high = maxpile;
        int ans = maxpile;
        while (low <= high)
        {
            // mid hmari speed h jo function call me as a parameter pass hoga
            int mid = low + (high - low) / 2;
            long long totalh = calculatetotalhr(piles, mid);
            if (totalh <= h)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};

int main()
{
    Solution obj;
    int h = 9;
    vector<int> nums = {3, 6, 7, 11};
    cout << obj.koko_brute(nums, h) << endl;
    cout << obj.koko_optimal(nums, h);
    return 0;
}