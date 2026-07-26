
// majority element is that which comes more than N/3 times in an array
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // brute , take one element and check for it in whole array , and if count is more than N/3 then continue till you find a element that occurs more than N/3 times and return that elemnet in vector form
    // also check if nay element is visited earlier dont visit it
    vector<int> majorityelementtwo_brute(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> result; // store the elements in this
        for (int i = 0; i < n; i++)
        {
            if (result.size() == 0 || result[0] != nums[i])
            { // check here if element is already present in nums[i]
                int cnt = 0;
                for (int j = 0; j < n; j++)
                {
                    if (nums[j] == nums[i])
                    {
                        cnt++;
                    }
                }

                if (cnt > (n / 3))
                    result.push_back(nums[i]);
            }

            if (result.size() == 2)
                break; // this is because logically a array cannot have more than 2 elements that are occuring more than N/3 times
        }
        return result;
    }

    // bettter approach can be we can use hashmap to store freq of all the elements and then check for elemnets that have freq more than N/3
    // for map TC will be O(NlogN ) for unordered_map TC wil be O(N) for best and worst is O(N^2)
    vector<int> majorityrlementtwo_better(vector<int> &nums)
    {

        // size of the array
        int n = nums.size();

        // list of answers
        vector<int> result;

        // declaring a map
        unordered_map<int, int> mpp;

        // least occurrence of the majority element
        int mini = int(n / 3) + 1;

        // storing the elements with its occurrence
        for (int i = 0; i < n; i++)
        {
            mpp[nums[i]]++;

            // checking if nums[i] is the majority element
            if (mpp[nums[i]] == mini)
            {
                result.push_back(nums[i]);
            }

            // if result size is equal to 2 break out of loop
            if (result.size() == 2)
            {
                break;
            }
        }

        // return the majority elements
        return result;
    }

    // opimal is to use for 4 variables cnt1 cnt 2 el1 el2 , store count and element that have potential to be majority element
    // TC is O(N) and SC is O(1)
    vector<int> majorityelementtwo_optimal(vector<int> &nums)
    {
        int n = nums.size();
        int cnt1 = 0, cnt2 = 0;
        int el1 = INT_MIN, el2 = INT_MIN; // int min isiliye liya h taki inhe update krne me koi problem na aaye
        for (int i = 0; i < n; i++)
        {
            if (cnt1 == 0 && el2 != nums[i])
            {
                cnt = 1;
                el1 = nums[i];
            }

            if (cnt1 == 0 && el2 != nums[i])
            {
                cnt1 = 1;
                // Initialize el1 as nums[i]
                el1 = nums[i];
            }
            else if (cnt2 == 0 && el1 != nums[i])
            {
                cnt2 = 1;
                // Initialize el2 as nums[i]
                el2 = nums[i];
            }
            else if (nums[i] == el1)
            {
                // Increment count for el1
                cnt1++;
            }
            else if (nums[i] == el2)
            {
                // Increment count for el2
                cnt2++;
            }
            else
            {
                // Decrement count for el1
                cnt1--;
                // Decrement count for el2
                cnt2--;
            }
        }
        // this is done by moore's voting
        // Validate the candidates by counting occurrences in nums
        // Reset counts for el1 and el2
        cnt1 = 0, cnt2 = 0;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == el1)
            {
                // Count occurrences of el1
                cnt1++;
            }
            if (nums[i] == el2)
            {
                // Count occurrences of el2
                cnt2++;
            }
        }

        /* Determine the minimum count
        required for a majority element*/
        int mini = n / 3 + 1;

        // List of answers
        vector<int> result;

        /*Add elements to the result vector
        if they appear more than n/3 times*/
        if (cnt1 >= mini)
        {
            result.push_back(el1);
        }
        if (cnt2 >= mini && el1 != el2)
        {
            // Avoid adding duplicate if el1 == el2
            result.push_back(el2);
        }

        // Uncomment the following line if you want to sort the answer array
        // sort(result.begin(), result.end()); // TC --> O(2*log2) ~ O(1);

        // return the majority elements
        return result;
    }
};

int main()
{
    // Create an instance of Solution class
    Solution obj;
    vector<int> arr = {11, 33, 33, 11, 33, 11};
    vector<int> ans = obj.majorityelementtwo_brute(arr);

    // Print the majority elements found
    cout << "The majority elements are: ";
    for (auto it : ans)
    {
        cout << it << " , ";
    }
    cout << "\n";
    return 0;
}