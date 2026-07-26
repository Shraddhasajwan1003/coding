#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int roman_to_numeral(string &s){
        int result=0;//result store here , DECLARE TO 0 ALWAYS OTHERWISE MAY TAKE ANY VALUE AND THEN ADD IT 
        unordered_map<char,int>rome={
            //unordered map used to store the roman numerals and map them with their chars 
            {'I', 1}, {'V', 5}, {'X', 10},
            {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };


        //loop to run through the string and look out for same characters that are in map , if the value associated with the cahr is less then its next one that means subtract eg IV , I is less than V in roman , that means to subtract , else we have to add these and at last the last character will as usual alwyas added bcz it sat last 
        for(int i=0;i<s.size()-1;i++){
            if (rome[s[i]]<rome[s[i+1]])result-=rome[s[i]];
            else result+=rome[s[i]];
        }
        return result+rome[s.back()];//return the result after adding the last roman numeral to the result 
    }
};

int main() {
    Solution obj;
    string s;
    cin>>s;
    int result=obj.roman_to_numeral(s);
    cout<<" Roman to numeral of "<<s<<" is :"<<result;
    return 0;
}