
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find the next permutation
    vector<int> brutenextpermutation(vector<int> &nums)
    {
        vector<int> original = nums; // Save the original input
        vector<vector<int>> all;

        sort(nums.begin(), nums.end());
        do
        {
            all.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));

        // Search using the saved 'original' array
        for (int i = 0; i < all.size(); i++)
        {
            if (all[i] == original)
            {
                if (i == all.size() - 1)
                    return all[0];
                return all[i + 1];
            }
        }
        return original;
    }
//TC is O(N)
    vector<int>optimalnextpermutation(vector<int>&nums){
        int index=-1;
        for(int i=nums.size()-2;i>=0;i--){
            //if a smaller element found that current found that is breaking point
            if(nums[i]<nums[i+1]){
                index =i;break;//store the index that is break point
            }
        }
        // if no index that has breaking point is found then reverse whole array 
        if(index==-1){
            reverse(nums.begin(),nums.end());
            return nums;
        }
        for(int i=nums.size()-1;i>index;i--){
            //swap the breaking point 
            if(nums[i]>nums[index]){
                swap(nums[i],nums[index]);
                break;
            }
        }
        reverse(nums.begin()+(index+1),nums.end());//reverse the part after index 
        return nums;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 3, 2};

    vector<int> result = sol.brutenextpermutation(nums);

    for (int x : result)
        cout << x << " ";
    cout << endl;
    nums={1,3,2};//assigned again bcz we gave refernece in above func , therefore num is changing to  { 2,1,3 }  
    vector<int> result2 = sol.optimalnextpermutation(nums);
    
    for (int x : result2)
        cout << x << " ";
    cout << endl;
    return 0;
}
