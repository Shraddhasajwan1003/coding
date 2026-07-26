#include <iostream>
using namespace std;

int main() {
    int n ;
    cin>> n;
    int factorial = 1;

    while (n > 0) {
        factorial *= n;  //Keep finding factorial with n and decrement n 
        n--;
    }

    cout << "Factorial of "<<n<< "is: " << factorial << endl;  //Print the factorial

    return 0;
}
