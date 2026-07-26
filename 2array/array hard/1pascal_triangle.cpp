
#include <bits/stdc++.h>
using namespace std;

// Class containing Pascal's Triangle generation logic
class Solution {
public:
    //brute force approach TC and SC is O(N^2)
    // Function to generate Pascal's Triangle up to numRows
    vector<vector<int>> generate(int numRows) {
        // Result vector to hold all rows
        vector<vector<int>> triangle;

        // Loop for each row
        for (int i = 0; i < numRows; i++) {
            // Create a row with size (i+1) and initialize all elements to 1
            vector<int> row(i + 1, 1);

            // Fill elements from index 1 to i-1 (middle values)
            for (int j = 1; j < i; j++) {
                // Each element = sum of two elements above it
                row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }

            // Add current row to the triangle
            triangle.push_back(row);
        }
        return triangle;
    }
    //approach-2 TC SC is O(n)
    //recursive way of approaching this problem 
    //we can use relation C(n,k)=C(n,k-1)*(n-k+1)/k
    vector<long long>getnthrow(int N ){
        vector <long long >row;//store all the rows 
        long long val=1;value of row is always one
        row.push_back(val);//push the correct ones into vector row 
        for(int i =1;i<N;i++){
            val = val * (N-K)/k;//remaining values calculated via int and max 
            row.push_back(val);
        }
        return row;
    }
    //bionomial way of getting a pascal triangle 
    // r means no of rows , c is no of columns 
    //optimal TC is O(N), O(min(c,r-c)), as loop goes for min(c-1,r-c) operations 
    //SC is O(1)
    long long findpascalelement(int r , int c){
        int n = r-1;//index to 0 se shuru hota h isliye 
        int k =c-1;
        long long result=1;
        for( int i =0;i<k;i++){
            result*=(n-i);
            result/=(i+1);
        }
        return result;
    }
};

int main() {
    Solution obj;
    int n = 5;

    // Generate and print Pascal's Triangle
    vector<vector<int>> result = obj.generate(n);
    for (auto &row : result) {
        for (auto &val : row) cout << val << " ";
        cout << endl;
    }
}
