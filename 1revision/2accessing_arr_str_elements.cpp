#include <bits/stdc++.h>
using namespace std;
class solution{
    public:
        void accessCharacters(string s){
            for(int i =0;i<s.length();i++){
                cout <<s[i]<<" ";
            }
        }
}; 
int main (){
    solution obj;
    string str;
    cin >> str;
    obj.accessCharacters(str);
}