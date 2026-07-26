#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
//brute we can store the prevoius elements and first and last elements are not chnaged , so they are fix only in between elements are chnaged 

    vector<vector<int>>generate(int numrows){
        //resultant vector that holds every elemnt , all rows 
        vector<vector<int>>triangle;

        //pehla kaam ek loop chalao 
        for( int i=0;i<numrows;i++ ){
            //ek or row bnayi jo row store kregi , all elements are initilased to 1 in this 
            vector<int>row(i+1,1);

            //fill elements from index 1 to i-1 (middle values)
            for(int j=1;j<i;j++){
                row[j]=triangle[i-1][j-1] + triangle[i-1][j];//beech ki values 
            }

            triangle.push_back(row);//push these values into triangle vector
        }
        return triangle;
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
    return 0;
    }
}