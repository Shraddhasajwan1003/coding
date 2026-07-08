#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int beauty_of_substring(string s ){
        int n =s.size();
        int sum=0;


        //loop over all substrings 
        for(int i =0;i<n;i++){
            unordered_map<char,int>freq;
            for(int j =0;j<n;j++){
                freq[s[j]]++;
                int maxi = INT_MIN;
                int mini = INT_MAX;
                //calculate min and max freq 
                for(auto it : freq){
                    int mini = min(mini,it.second);
                    int maxi=max(maxi,it.second);
                }
                sum+=(maxi-mini);
            }
        }
        return sum;
    }
};

int main() {
    Solution obj;
    string s;
    cin>>s;
    int result =obj.beauty_of_substring(s);
    cout<<"Sum of beauty of all substrings :"<<result;
    return 0;
}