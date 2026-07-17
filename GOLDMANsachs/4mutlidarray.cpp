#include <bits/stdc++.h>
using namespace std;

//cpp is rowmajor by default, row major is more cache friendly , column major does memory jumps , gives lower performance in large array
int main() {
    int arr[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    cout<<"print by row major: "<<endl;
    for(int i =0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<arr[i][j]<<" ";
        }
    }
    cout<<endl;
    cout<<"print by columnnmajor: "<<endl;
    for(int i =0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<arr[j][i]<<" ";
        }
    }
    cout<<endl;
    return 0;
}