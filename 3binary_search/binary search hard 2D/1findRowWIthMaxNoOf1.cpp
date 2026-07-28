//Problem Statement: You have been given a non-empty grid ‘mat’ with 'n' rows and 'm' columns consisting of only 0s and 1s. All the rows are sorted in ascending order. Your task is to find the index of the row with the maximum number of ones. Note: If two rows have the same number of ones, consider the one with a smaller index. If there's no row with at least 1 zero, return -1

//easy approach

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
     int rowWithMax1s(vector<vector<int>> &matrix, int n, int m) {
        int cnt_max = 0;  // Max number of 1s found
        int index = -1;   // Index of row with most 1s

        // Traverse each row of the matrix
        for (int i = 0; i < n; i++) {
            int cnt_ones = 0;  // Count 1s in current row
            for (int j = 0; j < m; j++) {
                cnt_ones += matrix[i][j];
            }
            // Update if this row has more 1s
            if (cnt_ones > cnt_max) {
                cnt_max = cnt_ones;
                index = i;
            }
        }
        return index;
    }
};

int main() {
     vector<vector<int>> matrix = {{1, 1, 1}, {0, 0, 1}, {0, 0, 0}};
    int n = 3, m = 3;

    Solution obj;
    cout << "The row with maximum no. of 1's is: " << obj.rowWithMax1s(matrix, n, m) << '\n';
    return 0;
}