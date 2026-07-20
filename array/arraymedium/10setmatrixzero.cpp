#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

//TC is O( m*n(m+n)), SC is O(1)
    void set_zeroes_matrix_brute(vector<vector<int>>&matrix){

        //size nikalo pehele
        int m = matriz.size(); //i ke liye 
        int n = matrix[0].size();// j ke liye 

        //zero kha h vo dhundo and then replace the rows and column of zero with -1 
        for(int i =0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    //mark all elements 0 except the one that are already 0     
                    //column jo 0 h use -1 set kro, row (i) fixed h 
                    for ( int col=0;col<n;col++){
                        if(matrix[i][col] != 0)//ye condition isilye h taki jo pehele se hi 0 given the vo -1 na bn jaye 
                        matrix[i][col]=-1;

                    }
                    //row that has 0 use -1 set kro , yha j fixed h (column fixed h )
                    for(int row=0;row<m;row++){
                        if(matrix[row][j]!=0)
                        matrix[row][j]=-1;
                    }
                }
            }
        }
        //all the -1 are now made one 
        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                if(matrix[i][j]==-1)
                matrix[i][j]=0;
            }
        }
    }
    //TC is O(m*n)
    //next tme hum ab 2 array rkh lenge that will track ki konsi row me zero krna h and konsi column me 0 krna h 
    void set_zeroes_matrix_better(vector<vector<int>>&matrix){
        int m = matrix.size();//rows
        int n = matrix[0].size();//columns
        vector<int>arr2(n,0);//for columns and initialised as 0 , size is n 
        vector<int>arr1(m,0);//for rows 
        //check in first pass that if matrix has any 0 , if it has mark the array as one , of same row and same column of the element that had 0 in it 
        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                if(matrix[i][j]==0){
                    arr1[i];//row array marked with 1 , same row that had zero in matrix
                    arr2[j];
                }
            }
        }
        //make all the row and column that arr 1 and arr2 both have as marked 1
        for(int i = 0;i<m;i++){
            for( int j =0;j<n;j++){
                if(arr1[i]==1 || arr2[j]){
                    matrix[i][j]=0;
                }
            }
        }

    }

//TC is O(m*n)
    void set_zeroes_matrix_optimal(vector<vector<int>>& matrix){
        int m=matrix.size();//row
        int n =matrix[0]size();//column
        //take 2 flag that is bool variable so that it tells if first row or column is zero or not 
        bool firstrowzero = false;
        bool firstcolzero= false;
        for( int i =0;i<m;i++){//column check if zero or not 
            if(matrix[i][0]==0){
                firstcolzero = true;
                break;
            }
        }
        for( int i =0; i<n;i++){//u can use j instead of i 
            if(matrix[0][i]==0){
                firstrowzero= true;
                break;

            }
        }
        for( int i=1;i<m;i++) {
            for( int j =1;j<n;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {//if any row or column is zero , set it 0 
                    matrix[i][j] = 0;
                }
            }
        }
        //if row is zero
        if(firstrowzero ){
            for(int j =0;j<n;j++){
                matrix[0][j];
            }
        }
        if(firstcolzero ){
            for(int i =0;i<n;i++){
                matrix[i][0];
            }
        }

    }

};

int main() {
    // Create the matrix
    vector<vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};
    
    // Create Solution object
    Solution obj;
    // Call function
    obj.set_zeroes_matrix_brute(matrix);
    
    // Print the updated matrix
    for (auto row : matrix) {
        for (auto val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}