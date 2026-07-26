// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     void generatePermutation(string s) {
//         sort(s.begin(), s.end());//for sorting 

//         do {
//             cout << s << endl;//print string
//         } 
//         while (next_permutation(s.begin(), s.end()));//gives all the possible permutations 

//         char maxi = *max_element(s.begin(), s.end());//give max element presnet lexicographically 
//         cout << "Max character: " << maxi << endl;
//     }
// };
// int main(){
//     Solution obj;//object to call the function presnet in public class 
//     string str;
//     cin>>str;
//     obj.generatePermutation(str);
//     return 0;
// }

//extract digits , count digits and reverse number 
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int extractDigitsAndCount(int N) {
        int cnt = 0;
        int revNumber = 0;
        if(N==0)return 1;
        while (N > 0) {
            int last_digit = N % 10;
            cout << "Digit: " << last_digit << endl;

            revNumber = (revNumber * 10) + last_digit;
            cnt++;

            N = N / 10;
        }

        cout << "Reversed Number: " << revNumber << endl;

        return cnt;
    }

    bool checkpalindrome(int m){
        int revNo=0;
        int original=m;
        while(m>0){
            int last_digit=m%10;
            revNo=  (revNo*10)+ last_digit;
            m=m/10;
        }
        // if(revNo==original){
        //     return true;
        // }
        // else return false;
        return revNo==original;
    }
    int gcd_of_two_numbers(int n,int m){
        for( int i = min(n,m);i>=1;i++){
            if(n%i==0 && m%i==0){
                return i;
            }
        }
        return 1;//no gcd then 1 
    }
    void printdivisor(int m){
    for(int i = 1; i <= m; i++){
        if(m % i == 0){
            cout << i << ",";
        }
    }
    cout << endl;
    }
    void checkprime(int m){
         int cnt=0;
    for(int i = 1; i <= m; i++){
        if(m % i == 0){
            cnt++;
        }
    }
    if(cnt==2){
            cout<<"is prime"<<"\n";
        }
    else cout<<"not prime"<<"\n";
    }
    bool checkarmstrong(int m){
        int Ano=0;
        int real=m;
        while(m>0){
            int digit=m%10;
            Ano =(pow(digit,3))+Ano;
            m=m/10;
        }
        return Ano==real;
    }
};

int main() {
    Solution obj;
    int n,m;
    cin >> n>>m;
    cout << "Count: " <<  obj.extractDigitsAndCount(n) << endl;
    cout<< "Check palindrome:"<<(obj.checkpalindrome(n))<<endl;
    //to return true or false use ternary opertaor (obj.checkpalindrome(n)?"true":"false")
    cout<<"give GCD:"<<obj.gcd_of_two_numbers(n,m)<<endl;
    cout<< "print divisor: ";
    obj.printdivisor(m);
    cout<<"check prime: ";
    obj.checkprime(m);
    cout<<"Check for armstrong: "<<(obj.checkarmstrong(m)?"true":"false")<<endl;
    return 0;
}

 
