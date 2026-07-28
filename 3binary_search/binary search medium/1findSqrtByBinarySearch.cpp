#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //brute force approach 
    int floorsqrt(int n ){
        int ans=0;
        for(int i =1;i<=n;i++){
            if((long long )i*i <=n){
                ans=i;
            }else{
                break;
            }
        }
        return ans;
    }
    int sqrtbinarysearch(int n ){
        if(n<2)return n;
        int low=0;int high=n;int ans=0;
        while(low<=high){
            int mid= low+ (high-low)/2;
            if((long long)mid*mid<=n){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    } 
};

int main() {
    Solution obj;
    int n =27;
    int res1=obj.floorsqrt(n);
    int res2=obj.sqrtbinarysearch(n);
    cout<<res1<<endl;
    cout<<"Sqrt by binary search: "<<res2;
    return 0;
}