//Problem Statement: Given an array/list of length ‘N’, where the array/list represents the boards and each element of the given array/list represents the length of each board. Some ‘K’ numbers of painters are available to paint these boards. Consider that each unit of a board takes 1 unit of time to paint. You are supposed to return the area of the minimum time to get this job done of painting all the ‘N’ boards under the constraint that any painter will only paint the continuous sections of boards.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
//O(N * (sum(arr[])-max(arr[])+1)), where N = size of the array, sum(arr[]) = sum of all array elements, max(arr[]) = maximum of all array elements.
    // Helper function to count how many painters are required to paint the boards within the given time limit
     int countPainters(vector<int> &boards, int time) {
        int n = boards.size();
        int painters = 1; // Start with one painter
        long long boardsPainter = 0; // Current total board length assigned to a painter

        for (int i = 0; i < n; i++) {
            if (boardsPainter + boards[i] <= time) {
                // If current board can be assigned to the same painter
                boardsPainter += boards[i];
            } else {
                // Otherwise, assign it to the next painter
                painters++;
                boardsPainter = boards[i];
            }
        }
        return painters;
    }

    // Function to find the minimum time to paint all boards using at most k painters
    int findLargestMinDistance(vector<int> &boards, int k) {
        int low = *max_element(boards.begin(), boards.end()); // Min possible time = largest board
        int high = accumulate(boards.begin(), boards.end(), 0); // Max time = total sum of boards

        for (int time = low; time <= high; time++) {
            if (countPainters(boards, time) <= k) {
                return time;
            }
        }
        return low;
    }
    // O(N * log(sum(arr[])-max(arr[])+1))
     // Main function: finds the minimum max time using binary search
    int findLargestMinDistance(vector<int> &boards, int k) {
        int low = *max_element(boards.begin(), boards.end());      // At least the largest board
        int high = accumulate(boards.begin(), boards.end(), 0);    // At most the total sum

        int result = high;

        while (low <= high) {
            int mid = (low + high) / 2;  // Mid time to test
            int painters = countPainters(boards, mid);

            if (painters > k) {
                low = mid + 1; // Too few painters → increase time
            } else {
                result = mid;  // Valid solution → try to minimize
                high = mid - 1;
            }
        }

        return result;
    }
};

int main() {
    Solution obj;

    return 0;
}
