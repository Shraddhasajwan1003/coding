//we are given with a vector<char> function in a public class and we have to sort charaters of a string passed as a parameter of this function , 
//what we can do is, take a ds that satisfy storing freq and characters all togetther and in order , so we use a pair <int (for freq),char(for character label)>
//then run  a loop to give labels to the characters in the pair freq[i]={0,i+a} , then add frequency to the pair using another loop not nested , freq[ch-'a'].first++;, then you can sort this pair by using sort function, but also need to pass a comparator function that compares the freq and sorts (compaartor is made as a separate function in a private class )
//then take a ans vector<char> and push_back then labels one by one , as they are sorted now on basis of frequency 
//TC IS O(N+KLogK) K is size of freq array that is constant
//SC IS O(N)
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:

    static bool comparator(pair<int, char>p1,pair<int,char>p2){

        if(p1.first>p2.first)return true;
        if(p1.first<p2.first)return false;
        return p1.second<p2.second;
    }
public:
//class has method for storing and sorting , calls a comparator method from a private class to sort according to freq in a pair
    vector<char>frequencysort(string &s){
        pair<int,char>freq[26];//pair array to store both characters and freq together 

        //give frequnecy with the character labels
        for(int i=0;i<26;i++){
            freq[i]={0,i+'a'};//aage waala freq store krega piche wala character
        }
        for(char ch : s){
            freq[ch-'a'].first++;//now we added freq to the pair of each character , that exists in string s

        }
        sort (freq,freq+26,comparator);//used to sort the pair one by one using first value in them 

        vector<char>ans;
        for(int i =0;i<26;i++){
            if(freq[i].first>0)ans.push_back(freq[i].second);
    }
        return ans;


    }
};

int main() {
    Solution obj;
    string s ;
    cin>>s;
    vector<char>result =obj.frequencysort(s);
    for(char it : result){
        cout<<it<<" ";
    }
    return 0;
}