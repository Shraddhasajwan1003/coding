
//we now have to implement the pow(x,n) x raise to power n 
//BRUTE FORCE APPROACH
//for power<0 we have n=-n ( converted n to positive power) and make number x go x=1/x 
//for power>0 we can make x*x the times we have n 


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    //brute force approach
    double myPow(double x, int n) {
        if(n==0 || x==1.0)return 1;
        long long temp=n;//integer overflow na ho isliye ye liya h 

        if(n<0){
            x=1/x;
            temp=-1*1LL*n;
        }

        double ans=1;
        for (long long i = 0; i < temp; i++) {
            // Multiply ans by x for n times
            ans *= x; 
        }
        return ans;
    
    }

    //optimal approach
private:
    // Function to calculate power
    // of 'x' raised to 'n'
    double power(double x, long n) {
        // Base case: anything raised to 0 is 1
        if (n == 0) return 1.0;

        // Base case: anything raised to 1 is itself
        if (n == 1) return x;

        // If 'n' is even
        if (n % 2 == 0) {
            // Recursive call: x * x, n / 2
            return power(x * x, n / 2);
        }
        // If 'n' is odd
        // Recursive call: x * power(x, n-1)
        return x * power(x, n - 1);
    }

public:
    // Function to calculate x raised to n
    double myPow(double x, int n) {
        // Store the value of n in a separate variable
        long long num = n; //otherwise overflow kr rha h 

        // If n is negative
        if (num < 0) {
            // Calculate the power of -n and take reciprocal
            return (1.0 / power(x, -1 * num));
        }
        // If n is non-negative
        return power(x, num);
    }
};

int main() {
    Solution obj;

    return 0;
}