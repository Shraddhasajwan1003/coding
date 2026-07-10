//4 approaches are  present in the given question 
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int naive_Approach(vector<int>& arr)
    {
        // linear search approach
        int n = arr.size();
        for (int i = 1; i < n; i++)
        {
            bool found = false;
            for (int j = 0; j < n; j++)
            {
                if (arr[j] == i)
                {
                    found = true;
                    break;
                }
            }

            if (!found)
                return i;
        }
        return -1;
    }
    int better_App(vector<int> &arr)
    {
        int n = arr.size();
        int hasharr[n + 1];
        // store frequency of all elemnets in hasharray
        for (int i = 0; i < n; i++)
        {
            hasharr[arr[i]]++;
        }
        for (int i = 0; i < n + 1; i++)
        {
            if (hasharr[i] == 0)
            {
                return i;
            }
        }
        return -1;
    }
    int  sum_of_n(vector<int>&arr){
        int n = arr.size() + 1;
  
    // Calculate the sum of array elements
    int sum = 0;
    for (int i = 0; i < n - 1; i++) {
        sum += arr[i];
    }

    // Calculate the expected sum
    long long expSum = (n *1LL* (n + 1)) / 2;  

    // Return the missing number
    return expSum - sum;
    }
    int missingNum(vector<int>& arr) {
    int n = arr.size() + 1;
    int xor1 = 0, xor2 = 0;

    // XOR all array elements
    for (int i = 0; i < n - 1; i++) {
        xor2 ^= arr[i];
    }
    // XOR all numbers from 1 to n
    for (int i = 1; i <= n; i++) {
        xor1 ^= i;
    }

    // Missing number is the XOR of xor1 and xor2
    return xor1 ^ xor2;
}
};

int main()
{
    Solution obj;
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    int result = obj.naive_Approach(arr);
    cout << "missing number is :" << result;
    return 0;
}