//Problem Statement: You are the owner of a Shipment company. You use conveyor belts to ship packages from one port to another. The packages must be shipped within 'd' days. The weights of the packages are given in an array 'of weights'. The packages are loaded on the conveyor belts every day in the same order as they appear in the array. The loaded weights must not exceed the maximum weight capacity of the ship. Find out the least-weight capacity so that you can ship all the packages within 'd' days .

//Input: N = 5, weights = [5, 4, 5, 2, 3, 4, 5, 6], d = 5
// Output: 9
// Explanation: The minimum ship capacity needed to ship all packages within 5 days is 9.

// Input: N = 3, weights = [1, 2, 3, 4, 5], d = 2
// Output: 9
// Explanation: With a capacity of 9, the packages can be shipped in 2 days as [1,2,3,4] and [5].


#include <bits/stdc++.h>
using namespace std;
// we add header file <numeric> for using accumulate function, this function gives sum of all elements in an array , it has a for loop in backend of it
//If the sum can exceed the limit of a standard int, pass 0LL (a long long zero) as the third argument:
//long long totalSum = std::accumulate(weights.begin(), weights.end(), 0LL);
class Solution {
public:
    //my answer in one function 
    int shipWithinDays(std::vector<int>& weights, int d) {
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);//0 shows that initial value taken for sum is 0 

        // Try every possible capacity from minimum to maximum
        for (int capacity = left; capacity <= right; capacity++) {//very impt 
            int days = 1;//very impt
            int currentLoad = 0;

            // Check how many days are required for this specific capacity
            for (int w : weights) {
                if (currentLoad + w > capacity) {
                    days++;
                    currentLoad = w;
                } else {
                    currentLoad += w;
                }
            }

            // If it can be shipped within 'd' days, we found our answer
            if (days <= d) {
                return capacity;
            }
        }

        return right;
    }

    //brute striver answer
    // Function to check how many days needed for given capacity
    int daysNeeded(vector<int>& weights, int capacity) {
        // Initialize day count to 1
        int days = 1;
        // Current load for the day
        int currentLoad = 0;

        // Iterate over all package weights
        for (int w : weights) {
            // If adding weight exceeds capacity
            if (currentLoad + w > capacity) {
                // Increase day count and reset load
                days++;
                currentLoad = w;
            } else {
                // Otherwise, add weight to current load
                currentLoad += w;
            }
        }
        // Return total days needed
        return days;
    }
    //TC is O((sum_weights - max_weight) * N), where N is the number of packages. For each capacity between max weight and total sum, we simulate shipping over N packages.
    // Function to find minimum ship capacity to ship in d days
    int shipWithinDays(vector<int>& weights, int d) {
        // Find maximum weight as minimum capacity
        int left = *max_element(weights.begin(), weights.end());
        // Find total sum as maximum capacity
        int right = accumulate(weights.begin(), weights.end(), 0);

        // Iterate from minimum to maximum capacity
        for (int capacity = left; capacity <= right; capacity++) {
            // Calculate days needed for current capacity
            int needed = daysNeeded(weights, capacity);
            // If days needed are less than or equal to d, return capacity
            if (needed <= d) {
                return capacity;
            }
        }
        // Should never reach here given constraints
        return right;
    }

    //Tc is O(N * log(S)), where N is number of packages and S is the search space (sum_weights - max_weight). Each binary search step takes O(N), repeated O(log S) times.
     // Function to calculate how many days are needed to ship packages with given capacity
    int daysNeeded(vector<int>& weights, int capacity) {
        // Initialize count of days to 1 (start with day one)
        int days = 1;

        // Variable to track the current load on the ship for a day
        int currentLoad = 0;

        // Loop through each package weight in the array
        for (int w : weights) {
            // Check if adding current package exceeds ship capacity for the day
            if (currentLoad + w > capacity) {
                // Need a new day to ship this package, so increment day count
                days++;

                // Start new day's load with current package weight
                currentLoad = w;
            } else {
                // If capacity not exceeded, add current package weight to the day's load
                currentLoad += w;
            }
        }

        // Return total number of days needed with this capacity
        return days;
    }

    // Main function to find minimum capacity to ship all packages within d days
    int shipWithinDays(vector<int>& weights, int d) {
        // Find the maximum package weight as the minimum capacity (can't be less than this)
        int left = *max_element(weights.begin(), weights.end());

        // Calculate the sum of all package weights as maximum capacity (ship all at once)
        int right = accumulate(weights.begin(), weights.end(), 0);

        // Binary search loop to find optimal capacity between left and right
        while (left < right) {//impt use only <, not <=
            // Calculate mid value as potential capacity to test
            int mid = left + (right - left) / 2;

            // Calculate how many days needed if ship capacity is mid
            int needed = daysNeeded(weights, mid);

            // If days needed is less or equal to allowed days,
            // try to reduce capacity by moving right boundary
            if (needed <= d) {
                right = mid;
            } else {
                // If days needed is more than allowed, increase capacity by moving left boundary
                left = mid + 1;
            }
        }

        // Left is now the minimum capacity that can ship packages within d days
        return left;
    }

};

int main() {
    Solution obj;

    return 0;
}