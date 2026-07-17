#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //     Insert N elements into an array given array of elements and a corresponding array of positions
    // Note: The array positions here are 1-based, i.e., the position of the first element in the array is taken as '1'.

    // Sample:

    // Inputs -
    // arr = {0,1,2,3,4}
    // elements = {5,6}
    // positions={2,4}
    // Output -
    // arr = {0,5,1,6,2,3,4}

    int insertion(vector<int>&arr, vector<int>elements, vector<int>positions){
        int n =elements.size();//how many elements are there to insert
        //first pair up position and elements
        vector<pair<int,int>>forinserting;
        for(int i =0;i<n;i++){
            forinserting.push_back(positions[i],elements[i]);
        }
        sort(forinserting.begin(),forinserting.end());//sorted by positions 
        for(auto &p : forinserting){
            int pos =p.first-1;//1 based indexing to 0 based 
            int val =p.second;
            arr.insert(arr.begin()+pos,val);
        }
        return 0;
    }
    // Delete N elements from an array given array of elements and a corresponding array of positions.
    // Sample:
    // Input -
    // arr = {0,1,2,3,4}
    // positions = {2,4}
    // Output -
    // arr = {0, 2, 3}
    int deletion(vector<int>&arr, vector<int>positions){
        //can also use const vector<int>&positions , in that case i'll have to make one more vector for positions and sort , so that input order doesnt change 
        sort(positions.begin(),positions.end());
        for(auto it : positions){
            int idx=it-1;
            arr.erase(arr.begin()+idx);
        }
        return 0;
    }
    // Update N elements in an array given array of elements and a corresponding array of positions.
    // Sample:
    // Input -
    // arr = {0,1,2,3,4}
    // elements = {5,6}
    // position = {2,4}
    // Output -
    // arr = {0,5,2,6,4}
    int updation(vector<int>&arr,vector<int>positions, vector<int>elements){
        int n =positions.size();
        for(int i =0;i<n;i++){
            int pos=positions[i]-1;
            arr[pos]=element[i];
        }
    }

};

int main()
{
    Solution obj;

    return 0;
}