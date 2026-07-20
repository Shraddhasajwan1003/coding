//optimal smjh nhi aya firse padhna pdega 
//Longest Consecutive Sequence in an Array
// Problem Statement: Given an array nums of n integers.
// Return the length of the longest sequence of consecutive integers. The integers in this sequence can appear in any order.
// Example 1:
// Input:
//  nums = [100, 4, 200, 1, 3, 2]  
// Output:
//  4  
// Explanation:
//  The longest sequence of consecutive elements in the array is [1, 2, 3, 4], which has a length of 4. This sequence can be formed regardless of the initial order of the elements in the array.

// Example 2:
// Input:
//  nums = [0, 3, 7, 2, 5, 8, 4, 6, 0, 1]  
// Output:
//  9  
// Explanation:
//  The longest sequence of consecutive elements in the array is [0, 1, 2, 3, 4, 5, 6, 7, 8], which has a length of 9.

#include <bits/stdc++.h>
using namespace std;
// brute ke steps :
//  make a loop jisme hum ek number pakad ke serach krege , ab usi loop me apna linear search ka separate private class me bnaya function call kro , to vo ek baar me ek no ke sare consecutive dhundega from a while loop jisme har baar hum nums[i] ko +1 krke uska consecutive dhundege , agr condition starting se true hoti arhi h to

// total loops used 3 , 1 in linear serach ke function me , ek for loop jiske under ek while loop h that calls linear serach ka loop
class Solution
{
private:
    bool linear_search(vector<int> &s, int num)
    {
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == num)
                return true;
        }
        return false;
    }

public:
    // first we run loop to see the consecutive of any elemnt and count them by using a counter , we use linear serach for all the seraching , there fore we make it as a separate helper function
    int longest_consec_sequence_in_array_brute(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        int longest = 0;
        for (int i = 0; i < n; i++)
        {
            int x = nums[i];
            int cnt = 1;
            while (linear_search(nums, x + 1) == true)
            {
                x += 1;
                cnt++;
            }
            longest = max(longest, cnt);
        }
        return longest;
    }
    // TC is O(NlogN)
    int longest_consec_sequence_in_array_better(vector<int> &arr)
    {
        int n = arr.size(); // size lelo
        if (n == 0)
            return 0;                 // empty h to return 0
        int lastsmaller = INT_MIN;    // ye store krega prevoius value
        int cnt = 0;                  // cnt krega consecutive as array is sorted and duplicates ko count nhi krega
        int longest = 1;              // longest seq kitna ho skta h store krne ke liye
        sort(arr.begin(), arr.end()); // sort krdo taki consecutive sath sath aajaye
        for (int i = 0; i < n; i++)
        { // sbko check krne ke liye ek loop
            if (arr[i] - 1 == lastsmaller)
            { // check kro abhi ka element kya last smaller ke brabar h after -1 , ya fir ye bhi keh skte h ki lastsmaller +1 kya equal h arr[i] ke , if yes then hum update krege lastsmaller ko by arr[i] and count me +1 krdege as hume consecutive milgya h
                cnt += 1;
                lastsmaller = arr[i];
            }
            else if (arr[i] != lastsmaller)
            { // agr hume consecutive nhi mila to hum cnt to new element ke liye start krege , and lastsmaleer ko upadte krdege by arr[i], ye case tab bhi execute hoga jb hum arr[0] pe honge
                cnt = 1;
                lastsmaller = arr[i];
            }
            longest = max(longest, cnt); // max count store krane ke liye
        }
        return longest;
    }

    // optimal way h use set , non repeating rkhega elements ko , plus usme search krna bhi O(1) me hota h
    int longestConsecutive(vector<int> &a)
    {
        int n = a.size();
        // If the array is empty
        if (n == 0)
            return 0;

        // Initialize the longest sequence length
        int longest = 1;
        unordered_set<int> st;

        // Put all the array elements into the set
        for (int i = 0; i < n; i++)
        {
            st.insert(a[i]);
        }

        /* Traverse the set to
           find the longest sequence  */
        for (auto it : st)
        {
            // Check if 'it' is a starting number of a sequence
            if (st.find(it - 1) == st.end())
            {
                // Initialize the count of the current sequence
                int cnt = 1;
                // Starting element of the sequence
                int x = it;

                // Find consecutive numbers in the set
                while (st.find(x + 1) != st.end())
                {
                    // Move to the next element in the sequence
                    x = x + 1;
                    // Increment the count of the sequence
                    cnt = cnt + 1;
                }
                // Update the longest sequence length
                longest = max(longest, cnt);
            }
        }
        return longest;
    }
};

int main()
{
    Solution obj;
    vector<int> a = {100, 4, 200, 1, 3, 2};

    int ans = obj.longest_consec_sequence_in_array_brute(a);

    cout << " the longest consecutive seq by brute is " << ans << "\n";
    return 0;
}