#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    vector<int> result;
    result.reserve(t);
    while(t--){
        int n;
        cin>>n;
        if (n==2)result.push_back(2);
        else result.push_back(n%2);
    }
    for( int ans:result)
    cout<<ans<<'\n';

    return 0;
}