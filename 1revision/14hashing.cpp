// int cnt =0;
//  int countingfreq( int n , arr[]){
//      for(int i =0;i<arr.size();i++){
//      if( arr[i]==n){
//          cnt++;
//      }
//      return cnt;
//  }
//  }
//
// hashing me pre storing + fecthing is easy
// hasing is vimp when we need to count frequencty of how many times something is appearing
// array hashing and character hashing is possible, we make array that will store freq , and we can fetch it acc to index
// array hashing has array size fixed upto to 10^8 , or 10^9 , we can not make an array 10^9 +1 , is chote input me
// Character hashing incase of lowercase go for hash index as s[i]-'a', for uppercase only got for s[i]-'A'
// both uppercase and lowercase go for simple s[i]
// for spacing space and larger input we can use map and unordered_map by stl , store sin key value pairs


// NORMAL HASHING 
// #include <bits/stdc++.h>
// using namespace std;

// int main() {
            //input lelia array 
//     int n;
//     cin >> n;
//     int arr[n];
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }

//     //precompute:
//     int hash[13] = {0};
//     for (int i = 0; i < n; i++) {
//         hash[arr[i]] += 1;
//     }

//     int q;
//     cin >> q;
//     while (q--) {
//         int number;
//         cin >> number;
//         // fetching:
//         cout << hash[number] << endl;
//     }
//     return 0;
// }


// HASHED CHARACTERS 
// #include <bits/stdc++.h>
// using namespace std;

// int main() {

//     string s;
//     cin >> s;

//     //precompute:
//     int hash[26] = {0};
//     for (int i = 0; i < s.size(); i++) {
//         hash[s[i] - 'a']++;// hash[s[i]-'A']++ for only uppercase , for both use simple hash[s[i]]++
//     }

//this is to find minimum and max frequency indices
        // int maxFreq = 0;
        // char ans;

        // for(int i=0;i<26;i++){
        //     if(hash[i] > maxFreq){
        //         maxFreq = freq[i];
        //         ans = i + 'a';
        //     }
        // }
//     int q;
//     cin >> q;
//     while (q--) {
//         char c;
//         cin >> c;
//         // fetch:
//         cout << hash[c - 'a'] << endl;
//     }
//     return 0;
// }

//HASHED VIA MAP ( if unordered map gives tle we can use map ) worst case TC is o(n) , varna has a TC of O(logn)
#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    //precompute:
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        mp[arr[i]]++;
    }

    // iterate over the map:
    /* for(auto it : mp){
            cout << it.first << "->" << it.second << endl;
        }
    */
    int maxFreq = INT_MIN;//for min freq take INT_MAX and condition as <
    int element;

    for(auto it : mp){
        if(it.second > maxFreq){
            maxFreq = it.second;
            element = it.first;
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int number;
        cin >> number;
        // fetch:
        cout << mp[number] << endl;//mp[key] can fetch value correspending to the key 

    }
    return 0;
}


// collision in hashing :it can increase TC


