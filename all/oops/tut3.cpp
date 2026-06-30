#include <iostream>
using namespace std;
int c=6;
int main(){
    int a=5,b=12;
    int c=a+b;
    cout<<"value of c"<<c<<endl;    
    cout<<"value of c"<<::c<<endl;//to access globally present c     
    float f=34.4;
    long double e =34.4;
    cout<<"f is a float: "<<f<<endl<<"e is long double"<<e<<endl;
    //in general if we ask cpp for type of a number like 34.4 it will give double by default 
    cout<<"the size of 34.4l is :"<<sizeof(34.4)<<endl;
    cout<<"the size of 34.4f is :"<<sizeof(34.4f)<<endl;
    cout<<"the size of 34.4l is :"<<sizeof(34.4l)<<endl;
    cout<<"the size of 34.4F is :"<<sizeof(34.4F)<<endl;
    cout<<"the size of 34.4L is :"<<sizeof(34.4L)<<endl;

    // *************Reference Variables**************** 
    // Rohan Das----> Monty -----> Rohu ------> Dangerous Coder ,multiple names for single entity
    float x = 455;//original variable
    float & y = x;//y points to x, reference variable
    cout<<x<<endl;
    cout<<y<<endl;

    // *************Typecasting(changing type of a variable)**************** 
    int u = 45;   
    float v = 45.46;
    cout<<"The value of a is "<<(float)u<<endl;//typecasting
    cout<<"The value of a is "<<float(u)<<endl;//typecasting
    float z = (u);//not typecasted here
    cout<<"The value of z is "<<z<<endl;

    cout<<"The value of b is "<<(int)v<<endl;
    cout<<"The value of b is "<<int(v)<<endl;
    int r = int(v);

    cout<<"The expression is "<<u + v<<endl;
    cout<<"The expression is "<<u + int(v)<<endl;
    cout<<"The expression is "<<u + (int)v<<endl;

    return 0; 
}