#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // below solution can work, give true for this case but it need false
        // s ="bbbaaaba"
        // t ="aaabbbba"
        // set<char> distinct_chars_s(s.begin(), s.end());
        // set<char> distinct_chars_t(t.begin(), t.end());
        // if(distinct_chars_s.size()== distinct_chars_t.size()){
        //     return true;
        // }
        // else return false;


        //correct approach is hashing 
        int arr1[256]={0},arr2[256]={0};
        int n =s.size();
        for(int i =0;i<n;i++){

            if(arr1[s[i]]!=arr2[t[i]])return false;

            arr1[s[i]]=i+1;//store freq of that character in array 
            arr2[t[i]]=i+1;//mapping 
        }
        return true;
    }
};

int main() {
    Solution obj;
    string s;
    string t;
    cin>>s>>t;
    cout<<obj.isIsomorphic(s,t);
    return 0;
}