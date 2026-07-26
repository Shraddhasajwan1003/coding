//these all below are clockwise rotation 

#include <bits/stdc++.h>
using namespace std;
//
class Solution {
public:
    //TC is O(N^2) and SC is O(N^2)
    vector<vector<int>>matrix_90degreerotate_brute(vector<vector<int>>&matrix){         
        //square matrix
        int n =matrix.size();
        vector<vector<int>>rotated_matrix(n,vector<int>(n));//rotated matrix has size as n and n (n*n)
        for(int i =0;i<n;i++){
            for(int j =0;j<n;j++){
                rotated_matrix[j][n-i-1]=matrix[i][j];
            }
        }
        return rotated_matrix;
    }

//TC is O(N^2) ans SC is O(1)
    vector<vector<int>>matrix_90degreerotate_optimal(vector<vector<int>>& matrix){
        int n =mtrix.size();
        for(int i =0;i<n;i++){
            for(int j =i+1;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }


        //reverse each row 
        for(int i =0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i],end());
        }

        return matrix;
    }
};

int main() {
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    Solution obj;
    vector<vector<int>> rotated = obj.matrix_90degreerotate_optimal(mat);

    // Print the rotated matrix
    for (auto row : rotated) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }

    return 0;
}