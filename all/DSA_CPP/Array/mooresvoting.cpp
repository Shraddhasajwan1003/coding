#include <bits/stdc++.h>
using namespace std;
int Majorityelement(vector<int>v){
    int n=v.size();
    int cnt=0;int el =0;
    for(int i=0;i<n;i++){
        if(cnt==0){
            el =v[i];
            cnt++;
        }
        else if(el==v[i]){
            cnt++;
        }
        else{
            cnt--;
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(v[i]==el)count++;
        }
        if(count>n/2){
            return el;
        }
        return -1;
    }
}
int main(){
    Majorityelement()
}