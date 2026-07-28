//two solutionspossible , brute is also a great one
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
     // Function to find the k-th missing number
    int missingK_brute(vector<int> vec, int n, int k) {
        for (int i = 0; i < n; i++) {
            if (vec[i] <= k) {
                k++;  // If current number is less than or equal to k, increment k
            } else {
                break; // Stop when we reach a number greater than k
            }
        }
        return k;  // Return the final value of k which is the missing number
    }

    //we cannot apply binary search to this question directly but we can find the near number to k easliy by BS 
    // Function to return the k-th missing number
    int missingK(vector<int> vec, int n, int k) {
        int low = 0, high = n - 1;

        // Perform binary search
        while (low <= high) {
            int mid = (low + high) / 2;

            // Calculate how many numbers are missing till vec[mid]
            int missing = vec[mid] - (mid + 1);

            if (missing < k) {
                low = mid + 1;  // Move right to find more missing numbers
            } else {
                high = mid - 1; // Move left to find a smaller valid index
            }
        }

        // After loop, 'high' points to the largest index such that
        // number of missing elements till there < k
        return k + high + 1;
    }
};

int main() {
    Solution obj;

    return 0;
}