//Problem Statement: You are given an array 'arr' of size 'n' which denotes the position of stalls. You are also given an integer 'k' which denotes the number of aggressive cows.
// You are given the task of assigning stalls to 'k' cows such that the minimum distance between any two of them is the maximum possible. Find the maximum possible minimum distance.

// Example 1:
// Input Format:
//  N = 6, k = 4, arr[] = {0,3,4,7,10,9}
// Result:
//  3
// Explanation:
//  The maximum possible minimum distance between any two cows will be 3 when 4 cows are placed at positions {0, 3, 7, 10}. Here the distances between cows are 3, 4, and 3 respectively. We cannot make the minimum distance greater than 3 in any ways.

// Example 2:
// Input Format:
//  N = 5, k = 2, arr[] = {4,2,1,3,6}
// Result:
//  5
// Explanation:
//  The maximum possible minimum distance between any two cows will be 5 when 2 cows are placed at positions {1, 6}. 

#include <bits/stdc++.h>
using namespace std;
//nums is stalls
class Solution {
public:
    //is function se check krege ki cows ko kha place krna h , taki minimum dist d mile hume , we will give dist like 1 , 2 ,3 as minimum distance beetween two cows and check ki is that distance okay to go and use and then return  it 
    bool canweplace(vector<int>&nums, int cows, int d){
        int count=1;//count of placed cows , ye initially isiliye 1 h taki ek ke reference se dusri cow ko place kr ske and ye hmesha hi 0th index pe place rhega 
        int n =nums.size();
        int lastpos= nums[0];
        for(int i =1;i<n;i++){
            if(nums[i]-lastpos>=d){
                count++;
                lastpos=nums[i];
            }
            //if count is more than or equal to no of cows 
            if(count>=cows)return true;
        }
        return false;

    }
    int aggressivecows_brute(vector<int>& nums, int cows ){//cows is total no of cows 
        sort(nums.begin(),nums.end());
        int n =nums.size();
        int maxdist=nums[n-1]-nums[0];//maximum possible distance between any 2 cows , it is max - min element 
        int ans =0;
        for( int i =1;i<=maxdist;i++){
            if(canweplace(nums, cows,i)){
                ans=i;
            }
        }
        return ans;
    }


    int aggressivecows_optimal(vector<int>&nums, int cows){
        int low=1;
        int high=nums.back()-nums.front();
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(canweplace(nums, cows, mid)){
                ans=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return ans;
    }
};

int main() {
    // Example input
    vector<int> stalls = {1, 2, 8, 4, 9};
    int cows = 3;

    // Create object of Solution class
    Solution obj;
    // Call function and print result
    cout << obj.aggressivecows_brute(stalls, cows) << endl;
    cout << obj.aggressivecows_optimal(stalls, cows) ;
    return 0;
}
