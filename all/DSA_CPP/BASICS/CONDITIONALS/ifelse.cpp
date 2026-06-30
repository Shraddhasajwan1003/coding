#include <iostream>
using namespace std;
int main() {
//     int marks;
//     cout << "Enter marks: ";
//     cin >> marks;
//     if ( marks >= 90 ) {
//     cout << "Grade A" << endl;
//     } else if ( marks >= 80 ) {
//     cout << "Grade B" << endl;
//     } else if ( marks >= 70 ) {
//     cout << "Grade C" << endl;
//     } else if ( marks >= 60 ) {
//     cout << "Grade D" << endl;
//     } else {
//     cout << "Grade F" << endl;
//     }
// return 0;
// }
//     int num;
//     cout << "Enter a number: ";
//     cin >> num;
//     if (num % 2 == 0) {
//         cout << num << " is even." << endl;
//     } else {
//         cout << num << " is odd." << endl;
//     return 0;
// }
//     int a, b;
//     cout << "Enter two numbers: ";
//     cin >> a >> b;
//     if (a > b) {
//         cout << a << " is greater than " << b << "." << endl;
//     } else if (b > a) {
//         cout << b << " is greater than " << a << "." << endl;
//     } else {
//         cout << "Both numbers are equal." << endl;
//     }
//     return 0;
// }
    int year;
    cout << "Enter a year: ";
    cin >> year;
    if ( (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0) ) {
        cout << year << " is a leap year." << endl;
    } else {
        cout << year << " is not a leap year." << endl;
    }
    return 0;
} 