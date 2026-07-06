#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
//TC is O(N^2), SC is O(N)
    bool rotatestring_bruteforce(string &s, string &goal){
        //length of both string is equal then only they can be rotation of each other
        if(s.length()!=goal.length())return false;
        //try all possible rotations 
        for(int i=0;i<s.length();i++){
            string rotated = s.substr(i)+ s.substr(0,i);//making all possible substring 
            if(rotated ==goal){
                return true;
            }
        }
        return false;
    }
    //TC is O(N) and SC is O(N)
    bool optimal_rotate_string(string s, string goal){
        // Strings must be the same length to be rotations of each other
        if (s.length() != goal.length()) return false;
        
        // Concatenate s with itself and check if goal exists in it
        string doubledS = s + s;
        return doubledS.find(goal) != string::npos;
    }
};

int main() {
    Solution obj;
    string s;
    string goal;
    cin>>s>>goal;
    cout<<obj.rotatestring_bruteforce(s,goal);
    return 0;
}