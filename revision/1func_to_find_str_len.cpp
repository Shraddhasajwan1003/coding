#include <bits/stdc++.h>
using namespace std;
class solution {

    //class bna di public wali 
    public :
        int findlength(string s){
            return s.length();//function hai ye stl ka 
        }
};
int main (){
    solution obj;//object bna dia class ka 
    string s;
    cin >> s ;//input lelia 
    cout<<obj.findlength(s);//object ki help se class ke function ko call kia 
    return 0;
}