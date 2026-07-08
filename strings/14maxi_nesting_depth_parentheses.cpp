#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int max_nestdepth(string &s){
        int p=0;
        int ans=0;
        for(char ch: s){
            if(ch=='(')p++;
            else if(ch==')')p--;
            ans = max(ans,p);
        } 
        return ans;
    }
};

int main() {
    Solution obj;
    string s;
    cin>>s;
    int result=obj.max_nestdepth(s);
    cout <<"maxi depth: "<<result;
    return 0;
}