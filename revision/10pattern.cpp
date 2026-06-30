#include <bits/stdc++.h>
using namespace std;
class solution{
    public:
        void pattern1(int N){
            for(int i=0;i<N;i++){
                for(int j =0;j<N;j++){
                    cout<<"*"<<" ";
                }
            cout<<endl;
        
            }
        }
        void pattern2(int N){
            for(int i =0;i <=N;i++){
                for (int j =0;j<i;j++){
                    cout<<"*"<<" ";
                }
                cout<<endl;
            }
        }
        void pattern3(int N){
            for(int i =0;i <N;i++){
                for (int j =i;j<N;j++){
                    cout<<"*"<<" ";
                }
                cout<<endl;
            }
        }
        void pattern4(int N ){
            for(int i =0;i <=N;i++){
                for (int j =0;j<i;j++){
                    cout<<i<<" ";
                }
                cout<<endl;
            }
        }
        void pattern5(int N ){
            for(int i =0;i <=N;i++){
                for (int j =1;j<=i;j++){
                    cout<<j<<" ";
                }
                cout<<endl;
            }
        }
        void pattern6(int N ){
            for(int i =0;i <N;i++){
                for (int j =N;j>i;j--){
                    cout<<N-j+1<<" ";
                }
                cout<<endl;
            }
        }
    
};
int main (){
    solution obj;
    int n;
    cin>>n;
    obj.pattern1(n);
    cout<<endl;
    obj.pattern2(n);
    cout<<endl;
    obj.pattern3(n);
    cout<<endl;
    obj.pattern4(n);
    cout<<endl;
    obj.pattern5(n);
    cout<<endl;
    obj.pattern6(n);
}
