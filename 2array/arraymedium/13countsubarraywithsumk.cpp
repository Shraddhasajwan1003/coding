#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
//TC is O(N^3)
    int count_subarr_withsumk_brute(vector<int>&arr, int k ){
       // Size of the array
        int n = arr.size();

        // Initialize count of subarrays
        int count = 0;

        // Traverse all possible start indices
        for (int i = 0; i < n; i++) {
            // Traverse all possible end indices from start
            for (int j = i; j < n; j++) {
                // Initialize sum for current subarray
                int sum = 0;

                // Calculate sum of subarray from i to j
                for (int m = i; m <= j; m++) {
                    sum += arr[m];
                }

                // If sum equals k, increment count
                if (sum == k) {
                    count++;
                }
            }
        }

        // Return total count of subarrays
        return count; 
    }


    //TC is O(N^2)
    int count_subarr_withsumk_better(vector<int>&arr , int k ){
        int n =arr.size();
        int count=0;
        for(int i =0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=arr[j];
                if ( sum==k){
                    count++;
                }
            }
        }
        return count;
    }

    //hashing (prefixsum)
    //whenever we are asked for sum of anything do consider using prefix sum technique
    //sum =k , find for x-k
    //index + prefix sum (abhi tak ka sum store krege)
    int count_subarr_withsumk_optimal(vector<int>&arr , int k ){
        int  n =arr.size();
        
        unordered_map<int , int>mp;//prefix sum and count stored

        //prefixsum and count initialised
        int prefixsum=0;
        int count=0;

        //basecase prefixsum 0 has ocurred once 
        mp[0]=1;
        for(int i =0;i<n;i++){

            //add element to current  prefixsum
            prefixsum+=arr[i];

            //caluclate x-k and that is to be removed 
            int remove=prefixsum-k;
            if(mp.find(remove) != mp.end()){
                count+=mp[remove];
            }
            mp[prefixsum]++;
        }
        return count;
    }
};

int main() {
    // Create Solution object
    Solution obj;
    // Input array
    vector<int> arr = {3, 1, 2, 4};

    // Target sum
    int k = 6;
    // Call function and store result
    int result = obj.count_subarr_withsumk_optimal(arr, k);

    // Print the count of subarrays
    cout << "The number of subarrays is: " << result << "\n";
    return 0;
}