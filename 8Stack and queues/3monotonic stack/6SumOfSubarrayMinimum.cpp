//Problem Statement: Given an array of integers arr of size n, calculate the sum of the minimum value in each (contiguous) subarray of arr. Since the result may be large, return the answer modulo 10⁹ +7.

//🎯 Task Kya Hai?
// Aapko ek integers ka array arr diya hai. Aapko:

// Is array ke sare possible contiguous subarrays nikalne hain.

// Har subarray ka minimum element dhoondhna hai.

// Un sabhi minimums ko add (sum) karna hai.

// Kyunki final answer bohot bada ho sakta hai, isliye result ko 10⁹ + 7 se modulo (%) karke return karna hai.

💡 Example Se Samajhte Hain
Maano arr = [3, 1, 2, 5]
Iske sare continuous subarrays aur unke minimum elements:
Subarray               Minimum Element
[3]                             3
[1]                             1
[2]                             2
[5]                             5
[3, 1]                          1
[1, 2]                          1
[2, 5]                          2
[3, 1, 2]                       1
[1, 2, 5]                       1
[3, 1, 2, 5]                    1
Total Sum = 3 + 1 + 2 + 5 + 1 + 1 + 2 + 1 + 1 + 1 = 18

Two Approaches
 
1. Brute Force Approach (Nested Loops)Logic: 

Har position se start hone wale saare subarrays banao, runtime par mini maintain karo, aur sum mein add karte jao.

Time Complexity: O(N^2) — Chote array ke liye thik hai, lekin bade arrays par Time Limit Exceeded (TLE) aayega.
Space Complexity: O(1)

2. Optimal Approach (Monotonic Stack) 

⚡Poore array par baar-baar iterate karne ki jagah, hum har element se puchte hain:👉 "Tum kitne subarrays mein minimum bane ho?"Agar hume pata chal jaye ki koi element arr[i] total X subarrays mein minimum hai, toh hum seedhe uski total contribution X*arr[i] add kar sakte hain.

X Kaise Nikalein?

Har element arr[i] ke liye hum do cheezein dhoondhte hain using Stack:

PSEE (Previous Smaller or Equal Element): Left side par pehla element jo current element se chota ya barabar ho.

left_count = i - psee_index

NSE (Next Smaller Element): Right side par pehla element jo current element se strictly chota ho.

right_count = nse_index - i

(Note: Duplicate subarrays double-count na hon, isliye ek side par > aur dusri side par >= ka use karte hain).


Total Subarrays jisme arr[i] minimum h:

freq =left_count *right_count

Total Contribution:

Total Sum = sum (freq * arr[i])mod{10^9 + 7}


Time Complexity: {O}(N) — Monotonic stack se har element bus ek baar push aur pop hota hai.

Space Complexity: {O}(N) — Stacks aur arrays store karne ke liye.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

   /* Function to find the sum of the 
   minimum value in each subarray */
   int sumSubarrayMins(vector<int> &arr) {
       
       // Size of array
       int n = arr.size();
       
       int mod = 1e9 + 7; // Mod value
       
       // To store the sum
       int sum = 0;
       
       // Traverse on the array
       for(int i=0; i < n; i++) {
           
           // To store the minimum of subarray
           int mini = arr[i];
           
           /* Nested loop to get all 
           subarrays starting from index i */
           for(int j=i; j < n; j++) {
               
               // Update the minimum value
               mini = min(mini, arr[j]);
               
               // Update the sum
               sum = (sum + mini) % mod;
           }
       }
       
       // Return the computed sum
       return sum;
   }
};

int main() {
   vector<int> arr = {3, 1, 2, 5};
   
   /* Creating an instance of 
   Solution class */
   Solution sol; 
   
   /* Function call to find the sum of the 
   minimum value in each subarray */
   int ans = sol.sumSubarrayMins(arr);
   
   cout << "The sum of minimum value in each subarray is: " << ans;
   
   return 0;
}


//ooptimal

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
         //Ek element minimum kitni subarrays ka minimum banega?
    //   current element   Kab tak minimum rahega? Jab tak Left me smaller na mile.
    //     Aur
    //     Right me smaller na mile.
    //     Previous Smaller + Next Smaller
    int n=arr.size();
    const int MOD=1e9+7;
    vector<int>left(n),right(n);
    stack<int >st;
    //previous smaaler
    for(int i=0;i<n;i++){
        while(!st.empty()&&arr[st.top()]>arr[i]){
            st.pop();
        }
        if(st.empty()){
            left[i]=-1;
        }
            else{
                left[i]=st.top();
            }
            st.push(i);
    }
        //clear stack
        while(!st.empty()){
            st.pop();
        }
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()){
                right[i]=n;
            }
            else{
                right[i]=st.top();
            }
            st.push(i);
        }
        long long ans=0;
        //calculte the no of minimum of each current elemrnt
        for(int i=0;i<n;i++){
            long long leftcount =i-left[i];
            long long rightcount =right[i]-i;
            long long contribution=(1LL*arr[i]*leftcount*rightcount)%MOD;
            ans=(ans+contribution)%MOD;

        }
        return ans;
    }

};