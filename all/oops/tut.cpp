#include <bits/stdc++.h>
using namespace std;
void anyfunction(int a,int b){
    cout<</*<< this is insertion operator*/"My name shraddha:"<< a <<endl;
    int sum =a+b;
    cout<<"This is sum:"<<sum<<endl;
}
int main(){
    int c,d;
    cin>>c>>d;//>> this is extracion operator
    int a,b;
    cin>>a>>b;
    anyfunction(a,b);//calling a function 
    anyfunction(c,d);
}