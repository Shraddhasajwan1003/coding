//Search in a sorted 2D matrix
//hard but doable
// Problem Statement: You have been given a 2-D array 'mat' of size 'N x M' where 'N' and 'M' denote the number of rows and columns, respectively. The elements of each row are sorted in non-decreasing order. Moreover, the first element of a row is greater than the last element of the previous row (if it exists). You are given an integer ‘target’, and your task is to find if it exists in the given 'mat' or not.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
     // Function to search for a target value in the matrix
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Get number of rows in the matrix
        int n = matrix.size();

        // Get number of columns in the matrix
        int m = matrix[0].size();

        // Traverse each row
        for (int i = 0; i < n; i++) {
            // Traverse each column in the current row
            for (int j = 0; j < m; j++) {
                // Check if the current element matches the target
                if (matrix[i][j] == target)
                    return true;
            }
        }

        // Return false if the target is not found
        return false;
    }

    //How to check if a specific row is containing the target:
    // If the target lies between the first and last element of the row, i (i.e. matrix[i][0] <= target && target <= matrix[i][m-1]), we can conclude that the target might be present in that specific row.
    


};

int main() {
    Solution obj;

    return 0;
}