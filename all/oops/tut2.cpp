#include <iostream>//system defined header file ( given by compiler)
//#include "this.h"//user defined header file , error will be seen if this header file is not presnet in the current working directory 
//cpp.reference - use this site to know about all header files & new versions of cpp
using namespace std;
int main (){
    cout<<"hello world"<<endl;//both \n snd endl used to go in new line 
    //arithmetic operators
    int a,b;
    cin >>a>>b;
    cout<<"value of a+b is :"<<a+b<< endl;
    cout<<"value of a-b is :"<<a-b<< endl;
    cout<<"value of a*b is :"<<a*b<< endl;
    cout<<"value of a/b is :"<<a/b<< endl;
    cout<<"value of a%b is :"<<a%b<< endl;
    cout<<"value of a++ is :"<<a++<< endl;
    cout<<"value of a-- is :"<<a--<< endl;
    cout<<"value of ++a is :"<<++a<< endl;
    cout<<"value of --a is :"<<--a<< endl;
    //assignment operators
    int c =4 , d=6;
    char e = 'k';
    //comparison operators
    cout<<"the value of a>b is :"<<(a>b)<<endl;
    cout<<"the value of a<b is :"<<(a<b)<<endl;
    cout<<"the value of a==b is :"<<(a==b)<<endl; 
    cout<<"the value of a>=b is :"<<(a>=b)<<endl; 
    cout<<"the value of a<=b is :"<<(a<=b)<<endl; 
    cout<<"the value of a!=b is :"<<(a!=b)<<endl; 
    //logical operators or and not 
    cout<<"the value of (a>b)&&(a!=b) is :"<<((a>b)&&(a!=b))<<endl; //and (when both true then true)
    cout<<"the value of (a>b)||(a!=b) is :"<<((a>b)||(a!=b))<<endl; //or(when one true then true)
    cout<<"the value of !((a>b)&&(a!=b)) is :"<<!((a>b)&&(a!=b))<<endl; //not (true is false , false is true)
    return 0;
}