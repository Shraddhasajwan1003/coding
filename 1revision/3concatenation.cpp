#include <bits/stdc++.h>
using namespace std;
class solution{
    public:
        string  concatbyplusoperator(string s,string t){
            string g= s +" "+t;
            return g;
        }
        string appendoperationinstl(string u , string v){
            u.append(" ");
            u.append(v);
            return u;
        }
        string byplusequalto(string w, string x){
            w+=x;
            return w;
        }
        char* byclibrarycstring(char a[] ,char b[] ){
            strcat(a,b);
            return a;
        }
};
//driver code 
int main (){
    solution obj;
    string str1;
    string str2;
    char a[100];
    char  b[100];
    cin>> a >>b;
    cin >> str1>>str2;
    cout<<obj.concatbyplusoperator(str1,str2)<<endl;//spaces created thats why seen 
    cout<<obj.byplusequalto(str1,str2)<<endl;//no spaces seen in output
    cout<<obj.byclibrarycstring(a,b)<<endl;//no spaces seen
    cout<<obj.appendoperationinstl(str1,str2)<<endl;//spaces seen in the output
    return 0;
}