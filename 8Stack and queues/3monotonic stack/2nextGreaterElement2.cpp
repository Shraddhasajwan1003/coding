//Circular Integer Array Kya Hota Hai?
Ek Circular Integer Array normal array jaisa hi hota hai, lekin iska main difference yeh hai ki yeh end hone par khatam nahi hota—yeh wapas start (index 0) se connect ho jata hai.

//brute force 
//Is problem mein hume har element ke liye usse agla bada number (Next Greater Element) dhoondhna hai. Kyunki array circular hai, isliye hum N  elements tak circular order mein check karte hain.

//steps:
// 1.ans array bnao initialise it whole by -1
// 2.Outer Loop (Har element par jana): Ek loop chalate hain i = 0 se n - 1 tak taaki hum array ke har element arr[i] ka next greater element dhoondh sakein.
// 3.impt point : Inner Loop (Circular Check):Inner loop j = 1 se n - 1 tak chalta hai.Modulo operator (%) ka use karke hum hypothetical circular index nikalte hain:ind= (i + j)% n .Yeh formula hume index n-1 par pahunchne ke baad wapas index 0, 1, 2 ... par le aata hai bina array boundary cross kiye.
// 4.Condition Check:

// Jaise hi koi arr[ind] > currEle milta hai, wahi hamara Next Greater Element hota hai.

// Us value ko ans[i] mein store karte hain aur break karke inner loop se bahar aa jate hain (kyunki hume pehla bada element chahiye).

// 5.Return Result: Agar poora inner loop ghumne par bhi koi bada element nahi milta, toh ans[i] mein default -1 hi rehta hai. Last mein ans array return kar dete hain.

// 6.TC is O(N^2) SC is O(N)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int> arr) {
        int n = arr.size();
        vector<int> ans(n, -1); // Sabhi elements ke liye initial result -1 rakha
        
        for(int i = 0; i < n; i++) {
            int currEle = arr[i]; // Current element jiske liye NGE dhoondhna hai
             
            for(int j = 1; j < n; j++) {
                int ind = (i + j) % n; // Circular index formula
                
                if(arr[ind] > currEle) {
                    ans[i] = arr[ind]; // Pehla bada element mil gaya
                    break;             // Inner loop se bahar nikle
                }    
            }
        }
       
        return ans;
    }
};

//optimal approach 
//Key Intuition & StrategyBrute force mein problem yeh thi ki hum har element ke liye dobara poora array traverse kar rahe the (O(N^2)).
Optimal approach mein hum Monotonic Stack ka use karte hain:
Hypothetical Double Array (2N Traversal): Circular behavior handle karne ke liye hum array ko do baar traverse karenge (yaani virtual array of size 2N).
Right to Left Loop (2N-1 down to 0): PEECHE se AAGE ki taraf aane par stack mein hamesha aage wale elements ka tracking milta rehta hai.
Monotonic Stack: Stack mein hamesha elements ko strictly decreasing order mein rakhte hain, taaki st.top() par hamesha sabse pehla aur closest bada element mile.

Step-by-Step Logic
Stack & Ans Array Setup:Ek stack<int> st banao aur ek ans array jiska size N ho.
Loop 2N-1 se 0 tak:Index ko actual index mein convert karne ke liye modulo ka use karte hain: ind = i % n.Current element nikalte hain: currEle = arr[ind].
Popping Smaller Elements:Jab tak stack empty na ho AUR stack ka top element current element se chhota ya barabar (st.top() <= currEle) ho, tab tak st.pop() karte raho.Kyunki agar koi element currEle se chhota hai, toh woh currEle ke left side wale kisi bhi element ke liye Next Greater Element nahi ban sakta.
Answer Store Karna (Jab i < N Ho):Kyunki hum 2-loops jitna iteration kar rahe hain, answer hume tabhi store karna hai jab hum pehle pass (i < N) mein hon.Agar stack empty ho gaya, toh koi bada element nahi mil: ans[i] = -1.Agar stack mein element bacha hai, toh top element hi hamara next greater element hai: ans[i] = st.top().Push Current Element:Current element (currEle) ko stack mein push kar do taaki left wale elements iska use kar sakein.



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        
        // Circular traversal ke liye 2*N - 1 se 0 tak loop
        for (int i = 2 * n - 1; i >= 0; i--) {
            int ind = i % n; // Actual array index
            int currEle = arr[ind];
            
            // Pop out all smaller or equal elements
            while (!st.empty() && st.top() <= currEle) {
                st.pop();
            }
            
            // Result keval actual elements (i < n) ke liye store karenge
            if (i < n) {
                if (st.empty()) {
                    ans[i] = -1;
                } else {
                    ans[i] = st.top();
                }
            }
            
            // Current element ko stack mein push karein
            st.push(currEle);
        }
        
        return ans;
    }
};