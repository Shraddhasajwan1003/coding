//Given two numbers N and M, find the Nth root of M. The nth root of a number M is defined as a number X when raised to the power N equals M. If the 'nth root is not an integer, return -1.
//Input: N = 3, M = 27
// Output: 3
// Explanation: The cube root of 27 is equal to 3.
// Input : N = 4, M = 69
// Output: -1
// Explanation : The 4th root of 69 does not exist. So, the answer is -1
//find x in x^n=m
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
//TC is O(M)
    int nthRoot_brute(int n,int m  ){
        for(int i =1;i<=m;i++){
            long long power = pow(i,n);//i^n=m
            if(power==m)return i;
            if(power>m)break;
        }
        return -1;
    }
    int nthRoot_optimal(int n,int m ){
        //we can reduce search space by using binary search 
        int low=0;int high=m;
        while(low<=high){
            int mid= low+(high-low)/2;
            // Store result of mid^n
            long long ans = 1;
            for (int i = 0; i < n; i++) {
                ans *= mid;
                if (ans > m) break;
            }

            // If mid^n equals m
            if (ans == m) return mid;

            // If mid^n is less than m
            if (ans < m) low = mid + 1;

            // If mid^n is more than m
            else high = mid - 1;
        }

        // Return -1 if not found
        return -1;
        
    } 
};

int main() {
    Solution obj;

    return 0;
}