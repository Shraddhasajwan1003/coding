#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestcommonprefix_lcp(vector<string>& str){
        if(str.empty())return "";
        sort(str.begin(),str.end());
        //agr humne sort kia h to vo lexicographically sort hua hoga , iski vjh se last string or smallest string ko hi check krna hoga 
        //isliye hum ek minimum length le lenge to traverse , that is minimum of first and last string 

        string first =str[0];
        string last=str[str.size()-1];
        string ans ="";
        int minlen
        for(int i =0;i<minlen ; i++){
            if(first[i]!=last[i])break;
            ans+=first[i];
        }
        return ans;
    }
};

int main() {
    Solution obj;

    return 0;
}