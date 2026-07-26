#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //TC is O(N^3 logN) but as we are sorting only 3 elements thats why we can say TC is O(N^3)
    // given triplets in array that sum as 0 , but they must be unique 
    //take 3 loops , and set to store them , them sort and store that set in vector for returning the vector
    vector<int>3sum_brute(vector<int>& nums){
        set<vector<int>> st;

        // First loop for first element
        for (int i = 0; i < n; i++) {
            // Second loop for second element
            for (int j = i + 1; j < n; j++) {
                // Third loop for third element
                for (int k = j + 1; k < n; k++) {
                    // If triplet sum is zero
                    if (arr[i] + arr[j] + arr[k] == 0) {
                        // Store sorted triplet to avoid duplicates
                        vector<int> temp = {arr[i], arr[j], arr[k]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }

        // Convert set to vector
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
    // instead of finding 3rd element by loop we can find for left amount of sum to make it zero 
    //TC is O(N^2 *logn) or SC is O(2*n)+O(N), here n is no of unique triplets
    vector<int>3sum_better(vector<int>& nums){
              // Store unique triplets
        set<vector<int>> ans;

        // First loop for first element
        for (int i = 0; i < n; i++) {
            // Set to store elements seen in this iteration
            set<int> hashset;

            // Second loop for second element
            for (int j = i + 1; j < n; j++) {
                // Calculate third element needed
                int third = -(arr[i] + arr[j]);

                // If third already in set, we found a triplet
                if (hashset.find(third) != hashset.end()) {
                    vector<int> temp = {arr[i], arr[j], third};
                    sort(temp.begin(), temp.end());
                    ans.insert(temp);
                }

                // Add current element to set
                hashset.insert(arr[j]);
            }
        }

        // Convert set to vector
        return vector<vector<int>>(ans.begin(), ans.end());  
    }
//TC is O(NlogN)+O(N^2) , NlogN sort me lagega , SC is O(no of triplets) use d for storing answer
    vector<int>3sum_optimal(vector<int>& nums){
        int n =nums.size();
        // Sort the array
        sort(arr.begin(), arr.end());
        // Store final result
        vector<vector<int>> ans;

        // First loop for first element
        for (int i = 0; i < n; i++) {
            // Skip duplicates for first element
            if (i > 0 && arr[i] == arr[i - 1]) continue;

            // Two pointers
            int left = i + 1, right = n - 1;

            // Find pairs for current arr[i]
            while (left < right) {
                int sum = arr[i] + arr[left] + arr[right];

                if (sum == 0) {
                    ans.push_back({arr[i], arr[left], arr[right]});
                    left++, right--;

                    // Skip duplicates for left
                    while (left < right && arr[left] == arr[left - 1]) left++;
                    // Skip duplicates for right
                    while (left < right && arr[right] == arr[right + 1]) right--;
                }
                else if (sum < 0) left++;
                else right--;
            }
        }
        return ans;
    }

};

int main() {
     vector<int> arr = {-1, 0, 1, 2, -1, -4};
    int n = arr.size();
    Solution obj;
    vector<vector<int>> res = obj.threeSum(arr, n);

    for (auto &triplet : res) {
        for (auto &num : triplet) cout << num << " ";
        cout << endl;
    }

    return 0;
}