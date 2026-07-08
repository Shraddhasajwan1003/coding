//recursion : function will call itself until the base condition is reached , recursion runs on stack , if base condiiton is wrongly written , the recursion goes infinite times and stack gets overflowed , gives a segmnetation fault, MLE ( memory limit exceed error)
// after achieving base case , function returns to its parent function  
//recursion tree bnata h , tree ke last me ana ke badd ( that is base case reach krne ke bad , tree se backtrack hota h function )
//backtrack wale recursion me print condition jo hoti h vo after function call likhte h ( ye call inside the main parent function ho rhi h )
//jabki normal me hum print statement pehle hi likh dete h 
//recursion me bhi parameterised and functional recursion hota h, parameterised me hum kuch retrun nhi krate bs call krte h , functional me return krate h  
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void printmyname(int i, int n){//function is a parameterised func
        if(i == n){
            return;
        }

        cout << "shraddha "<<"\n";
        printmyname(i + 1, n);
    }
    void print1ton(int i, int n){
        if(i == n){
            return;
        }
        cout<<"number:"<<i<<"\n";
        print1ton(i + 1, n);
    }
    void printnto1(int i, int n){
        if(i == n){
            return;
        }
        cout<<"number:"<<i<<"\n";
        printnto1(i - 1, n);
    }
    int sumofn( int n){       //TC is O(n)
        if (n==1) {
            return 1;
        }
        return (n+ sumofn(n-1));
    }
    int byformulasumofn(int n ){     //TC is O(1)
        return (n*(n+1))/2;
    }
    int factorial(int n ){
        if(n==1)return 1;
        return (n*(n-1));
    }
    void reversearr(int i,int arr[],int n){//even if i dont use " & " mpercent here while passing array as an argument but still original array gets changed because array is a pointer 
        if(i==n)return;
        else{
        swap(arr[i],arr[n-i-1]);
        reversearr(i+1,arr,n);
        }
    }
    bool validpalindrome(string s){
        string str="";
        for (char i :s){
            if(isalnum(i)){
                str+= tolower(i);
            }
        }
        reverse(str.begin(),str.end());
        return str==s;
    }
    bool validpalindrome_twopointer_approach(string s){
        int i =0,j=s.size()-1;
        while(i<j){
            while(!isalnum(s[i])) i++;
            while(!isalnum(s[j])) j--;
            if(tolower(s[i]) != tolower(s[j]))return false;
            i++;
            j--;
        }
        return true;
    }
    bool validplaindrome_without_stl(string s ){//dont include nonalphanumeric , include letters and numbers
        string str="";
        for(int i=0;i<s.size();i++){//this loop removes all the non alphanumric characters
            char c = s[i];
            if(c>='A'&&c<='Z')c=c+32;//for making lowercase , can also use stl function like tolower()
            if(c>='a'&&c<='z'||c>='0'&&c<='9')str.push_back(c);//for taking only lower cases and numbers + pushing them in to the string str 
        }
        string real = str;
        int lo =0, hi=str.size()-1;
        for( int i =0; i<str.size()/2;i++){//two pointer for reversing the string instead of using stl
            swap(str[lo],str[hi]);//instead of this we can use , temp variable 
            //temp=str[lo];str[lo]=str[hi];str[hi]=temp;lo++;hi--;
            lo++;
            hi--;
        }
        return str==real;//here i wrote a separate function to reverse the whole string then compare but i can compare without even reversing the string str, no need of string named real also 
        //for(int i =0; i<str.size()/2;i++){if (str[i]!=str[str.size()-i-1])return false;else{return true;}}
        //Or you can use a while loop---> 
        //int lo=0,hi=str.size()-1; while(lo<hi){if(str[lo] !=str[hi])return false; else{return false;}lo++;hi--;}
    }
    bool recursive_palindrome(int i, string& s) {
    // Base Condition: If i exceeds half of the string, all the elements have been compared
    // and the string is a palindrome, return true.
    if (i >= s.length() / 2) return true;

    // If the start and end characters are not equal, it's not a palindrome.
    if (s[i] != s[s.length() - i - 1]) return false;

    // If both characters are the same, increment i and check start+1 and end-1.
    return recursive_palindrome(i + 1, s);
}
    int recursive_fib(int n) {
            if (n<=1)return n;
            return(recursive_fib(n-1)+recursive_fib(n-2));
        }

};

int main() {
    Solution obj;
    int n;
    cin >> n;

    obj.printmyname(0, n);
    obj.print1ton(1,n);
    obj.printnto1(n,0);
    cout<<"sum of n numbers"<<obj.sumofn(n)<<"\n";
    cout<<"by formula sumof n"<<obj.byformulasumofn(n)<<"\n";
    cout<<"factorial:"<<obj.factorial(n);


    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    obj.reversearr(0,arr,n);
    for( int i =0;i<n;i++){
        cout<<arr[i]<<" , ";
    }
    return 0;
}