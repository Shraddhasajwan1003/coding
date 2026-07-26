#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC is O(m+n)log(m+n),o(m+n)
    vector<int> union_by_map(int arr1[], int arr2[], int n, int m)
    {
        map<int, int> freq_map; // use only map , not unordered bcz we need freq in order
        vector<int> Union;
        for (int i = 0; i < n; i++)
        {
            freq_map[arr1[i]]++;
        }
        for (int i = 0; i < m; i++)
        {
            freq_map[arr2[i]]++;
        }
        for (auto it : freq_map)
            Union.push_back(it.first);
        return Union;
    }

    // TC is same as map one
    vector<int> union_by_set(int arr1[], int arr2[], int n, int m)
    {
        // dotn have to take unordered set for this only set
        set<int> st;
        for (int i = 0; i < n; i++)
        {
            st.insert(arr1[i]);
        }
        for (int i = 0; i < m; i++)
        {
            st.insert(arr2[i]);
        }
        vector<int> UNION(st.begin(), st.end());
        return UNION;
    }
    // optimal approach by 2 pointers
    vector<int> union_by_two_pointer(int arr1[], int arr2[], int n, int m)
    {
        vector<int> Union;

        int l = 0, r = 0;
        while (l < n && r < m)
        {
            if (arr1[l] > arr2[r])
            {
                if (Union.empty() || Union.back() != arr1[l])
                    Union.push_back(arr1[l]);
                l++;
            }
            else if (arr1[l] < arr2[r])
            {
                if (Union.empty() || Union.back() != arr2[r])
                    Union.push_back(arr2[r]);
                r++;
            }
        }
    };
}

int
main()
{
    Solution obj;
    int n, m;
    cin >> n >> m;
    int arr1[n];
    int arr2[m];
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }
    vector<int> UNION1 = obj.union_by_map(arr1, arr2, n, m);
    vector<int> UNION2 = obj.union_by_set(arr1, arr2, n, m);
    cout << "Union if two sorted arrays by map is :";
    for (auto &it : UNION1)
    {
        cout << it << " ";
    }
    cout << endl;
    cout << "Union if two sorted arrays by set is :";
    for (auto &it : UNION2)
    {
        cout << it << " ";
    }
    return 0;
}