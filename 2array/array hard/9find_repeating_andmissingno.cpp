#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
//brute checks for every index , and finds repeating with cnt =2 , and missing with cnt =0
    vector<int>findmissingandduplicatenumber_brute(vector<int>& nums){
        int cnt=0;
        int n = nums.size();
        int repeating =-1,missing =-1;
        for(int i =1;i<=n;i++){
            for(int j =0;j<n;j++){
                if(nums[j]==i){
                    cnt++;
                }
                if(cnt==0)repeating =i;
                if(cnt==2)missing =i;
                if(repeating !=-1 && missing !=-1;)break;
            }
        }
        return {repeating,missing};
    }

    vector<int>indmissingandduplicatenumber_better(vector<int>& nums){
        int n =nums.size();
        vector<int>hash(n+1,0);
        for (int i = 0; i < n; i++) {
            hash[nums[i]]++;
        }

        int repeating = -1, missing = -1;
        
        // Find the repeating and missing number:
        for (int i = 1; i <= n; i++) {
            if (hash[i] == 2) {
                repeating = i;
            } else if (hash[i] == 0) {
                missing = i;
            }

            /* If both repeating and missing 
            are found, break out of loop*/
            if (repeating != -1 && missing != -1) {
                break;
            }
        }
        
        // Return {repeating, missing}
        return {repeating, missing};

    }
    //optimal uses formula for sum , n(n+1)/2
    vector<int> findMissingRepeatingNumbers(vector<int>& nums) {
        
        // Size of the array
        long long n = nums.size(); 

        // Sum of first n natural numbers
        long long SN = (n * (n + 1)) / 2;
        
        // Sum of squares of first n natural numbers
        long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;

        /*Calculate actual sum (S) and sum 
        of squares (S2) of array elements*/
        long long S = 0, S2 = 0;
        for (int i = 0; i < n; i++) {
            S += nums[i];
            S2 += (long long)nums[i] * (long long)nums[i];
        }

        //Compute the difference values
        long long val1 = S - SN; 
        
        // S2 - S2n = X^2 - Y^2
        long long val2 = S2 - S2N; 

        //Calculate X + Y using X + Y = (X^2 - Y^2) / (X - Y)
        val2 = val2 / val1;

        /* Calculate X and Y from X + Y and X - Y
         X = ((X + Y) + (X - Y)) / 2
         Y = X - (X - Y)*/
        long long x = (val1 + val2) / 2;
        long long y = x - val1;

        // Return the results as {repeating, missing}
        return {(int)x, (int)y};
    }

    //do by using XOR 
    vector<int>by_using_xor_optimal(vector<int>& nums){
        int n =nums.size();
        iint xr=0;
        
    }
};

int main() {
    Solution obj;

    return 0;
}