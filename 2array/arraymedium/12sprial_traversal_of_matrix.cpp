
//we have to traverse the matrix spirraly , we need to move right down , left and up , also making sure that we havent visted the ones we are visitng right now , for that we will maintain a separate matrix 
//we will stoer that if any cell is visited or not 
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int>spiralmatrix(vector<vector<int>>matrix){
        //make 4 direction variables to manage them 
        //if valid way to go then make the iterator go there 
        //ye 4 variable humne rows and columns nikalne ke liye bnaye h 
        int top =0;//upar jate time i same rhega 
        int left =0;//same row rhegi 
        int down = matrix.size()-1;//isme column same rhga 
        int right = matrix[0].size()-1;//isme row same h and column different + ye n pe depend krega 
        //result vector in store hoga spiral traversal ka result 
        vector<int>result;
        while(top<=down && left<=right){
            //first we go left to right 
            for( int i =left;i<=right;i++){
                result.push_back(matrix[top][i]);
            }
            top++;//we pushed boundary of top one level down 

            for(int i =top;i<=down;i++){
                result.push_back(matrix[i][right]);

            }
            right--;//reduce right boundary and start from n-2


            //check if nay columns remianing 
            //now we move from right to left on the bottom row 
            if(top<=down){
                for(int i=right;i>=left;i--){
                    result.push_back(matrix[down][i]);
                }
                down--;
            }
            //down to top , left column
            if(left<=right){
                for(int i =down;i>=top;i--){
                    result.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return result;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> matrix = {
        { 1, 2, 3, 4 },
        { 5, 6, 7, 8 },
        { 9, 10, 11, 12 },
        { 13, 14, 15, 16 }
    };

    vector<int> result = obj.spiralmatrix(matrix);

    for(int val : result) {
        cout << val << " ";
    }


    return 0;
}