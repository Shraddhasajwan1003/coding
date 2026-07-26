// for brute force we make 2 array pos and neg that will be used to store , positive and negative elements of gievn array, TC is O(N+N/2), SC is O(N)
//given with equal no of postive and negative integers
//for optimal wde use two varaible rather than two array and a extra array to store the result, TC is O(N) and SC is O(N)
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> rearrange_by_sign_brute(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> pos;
        vector<int> neg;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > 0)
            {
                pos.push_back(arr[i]);
            }
            else
            {
                neg.push_back(arr[i]);
            }
        }
        for (int i = 0; i < n / 2; i++)
        {
            arr[2 * i] = pos[i];
            arr[2 * i + 1] = neg[i];
        }
        return arr;
    }
    vector<int>optimal_rearrange_by_sign(vector<int>&arr){
        //we take 2 varaibles that store posindex and negindex
        int n =arr.size();
        int posindex=0;//even indices
        int negindex=1;//odd indices 
        vector<int>resultarr;
        for( int i=0;i<n;i++){
            if(arr[i]>0){
                resultarr[posindex]=arr[i];
                posindex+=2;
            }
            else{
                resultarr[negindex]=arr[i];
                negindex+=2;
            }
        }
        return resultarr;
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
    vector<int> result = obj.rearrange_by_sign_brute(arr);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    vector<int> resultopt = obj.optimal_rearrange_by_sign(arr);
    for (int i = 0; i < resultopt.size(); i++)
    {
        cout << resultopt[i] << " ";
    }
    return 0;
}