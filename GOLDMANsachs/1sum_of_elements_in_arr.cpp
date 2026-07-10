#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sum_of_all_elements(vector<int>& arr){
        int n = arr.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        return sum;
    }
};

int main() {
    Solution obj;
    int n ;
    cin>>n;
    vector<int>vec;
    for(int i =0;i<n;i++){
        int a;
        cin>>a;
        vec.push_back(a);
    }
    cout<<"Sum of all elements:"<<obj.sum_of_all_elements(vec);
    return 0;
}