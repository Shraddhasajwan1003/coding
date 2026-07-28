//find minimum no of days needed to make M bouqets , and one bouqet has k floers in it , flower bloomed must be adjacent 

//youll be given a array , that will have the day of blooming of flowers , so day that is max will have all the flowers bloomed , but can we have less than max ?? that is what we need to find 
//Problem Statement: You are given 'N’ roses and you are also given an array 'arr' where 'arr[i]' denotes that the 'ith' rose will bloom on the 'arr[i]th' day. You can only pick already bloomed roses that are adjacent to make a bouquet. You are also told that you require exactly 'k' adjacent bloomed roses to make a single bouquet. Find the minimum number of days required to make at least ‘m' bouquets each containing 'k' roses. Return -1 if it is not possible.

//Example 1:
// Input Format: N = 8, arr[] = {7, 7, 7, 7, 13, 11, 12, 7}, m = 2, k = 3
// Result: 12
// Explanation: On the 12th the first 4 flowers and the last 3 flowers would have already bloomed. So, we can easily make 2 bouquets, one with the first 3 and another with the last 3 flowers.

//Example 2:
// Input Format: N = 5, arr[] = {1, 10, 3, 10, 2}, m = 3, k = 2
// Result: -1
// Explanation: If we want to make 3 bouquets of 2 flowers each, we need at least 6 flowers. But we are given only 5 flowers, so, we cannot make the bouquets.

//firstly before solving we need to think about how to deal with impossible condition  that is how -1 comes when M*K<n 
//what we can do is that use smaller and largest element 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int possible(int arr[],int m,int k){
        int n =arr.length;
        int cnt=0;
        int bouq=0;
        for(int i =0;i<n;i++){
            if(arr[i]<=day){
                cnt++;
            }else{
                bouq+=(cnt/k);
                cnt=0;
            }
        }
        bouq+=(cnt/k);

    }
};

int main() {
    Solution obj;

    return 0;
} 