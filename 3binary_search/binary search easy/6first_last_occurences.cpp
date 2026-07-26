#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //return the index of the number where it first occurs and last occurs in an array in 0 based indexing 
    vector<int> searchRange_brute(vector<int>& nums, int target) {
        //simple go for linear search , starting se srecah kroge to u will get first occurence and from last you will get last occurence 
        for(int i =n-1;i>=0;i--){//last occurence 
            if(nums[i]==target){
                // return i; would have returned i if vector was not asked 

            }

        }
    }
    int solve(int n, int key, vector<int>& v) {
  // initialize search bounds and result
  int start = 0;
  int end = n - 1;
  int res = -1;

  // binary search loop
  while (start <= end) {
    // compute mid safely
    int mid = start + (end - start) / 2;
    // when match found, store index and move right
    if (v[mid] == key) {
      res = mid;
      start = mid + 1;
    }
    // when key is smaller, move left
    else if (key < v[mid]) {
      end = mid - 1;
    }
    // otherwise move right
    else {
      start = mid + 1;
    }
  }
  // return last occurrence or -1
  return res;
}
    int findBound(const vector<int>& nums, int target, bool isFirst) {
        int low = 0, high = nums.size() - 1;
        int bound = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                bound = mid; // Candidate index found
                if (isFirst) {
                    high = mid - 1; // Keep searching to the left
                } else {
                    low = mid + 1;  // Keep searching to the right
                }
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return bound;
    }
};

int main() {
    Solution obj;

    return 0;
}

// #include <vector>

// using namespace std;

// class Solution {
// private:
//     int findBound(const vector<int>& nums, int target, bool isFirst) {
//         int low = 0, high = nums.size() - 1;
//         int bound = -1;

//         while (low <= high) {
//             int mid = low + (high - low) / 2;

//             if (nums[mid] == target) {
//                 bound = mid; // Candidate index found
//                 if (isFirst) {
//                     high = mid - 1; // Keep searching to the left
//                 } else {
//                     low = mid + 1;  // Keep searching to the right
//                 }
//             } else if (nums[mid] < target) {
//                 low = mid + 1;
//             } else {
//                 high = mid - 1;
//             }
//         }

//         return bound;
//     }

// public:
//     vector<int> searchRange(vector<int>& nums, int target) {
//         int first = findBound(nums, target, true);
//         int last = findBound(nums, target, false);

//         return {first, last};
//     }
// };