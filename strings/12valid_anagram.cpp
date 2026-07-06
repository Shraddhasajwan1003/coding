#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
//TC is O(2nlogn +n)
    bool valid_anagram_brute(string s , string t){
        if(s.length()!=t.length())return false;
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());

        for(int i =0;i<s.length();i++){
            if(s[i]!=t[i])return false;
        }
        return true;
    }


    //TC is O(N),SC is O(26)
    bool optimal_anagram(string s, string t){
        if(s.length()!=t.length())return false;
        int hasharr[26]={0};
       
        for(int i =0;i<s.length();i++){
            hasharr[s[i]-'a']++;//subtract for lowercase letters, ++ for adding value in freq array as 1 for the index 
        }

        for(int i =0;i<s.length();i++){
            hasharr[t[i]-'a']--;//-- this will make same indices 0 and all elemnets of hasharr will be 0 if and only if its valid anagram  
        }
        for(int i=0;i<26;i++){
            if(hasharr[i]!=0)return false;
        }
        return true;
    }
};

int main() {
    Solution obj;
    string s,t;
    cin>>s>>t;
    cout<<obj.valid_anagram_brute(s,t)<<endl;
    cout<<obj.optimal_anagram(s,t);
    return 0;
}