#include <iostream>
using namespace std;
//below code is better than 2nd one because it avoids uneccessary operations 
int main() {
    // Declare and initialize marks variable
    int marks;
    cout<<"enter marks:";
    cin>>marks;
    // Check grade conditions using if-else ladder
    if (marks < 25) {
        cout << "Grade: F" << endl;  // Less than 25 is Grade F
    } else if (  marks <= 44) {
        cout << "Grade: E" << endl;  // Between 25 and 44 is Grade E
    } else if ( marks <= 49) {
        cout << "Grade: D" << endl;  // Between 45 and 49 is Grade D
    } else if (marks <= 59) {
        cout << "Grade: C" << endl;  // Between 50 and 59 is Grade C
    } else if ( marks <= 69) {
        cout << "Grade: B" << endl;  // Between 60 and 69 is Grade B
    } else if (marks >= 70) {
        cout << "Grade: A" << endl;  // 70 and above is Grade A
    } else {
        cout << "Invalid marks entered." << endl;  // Handles unexpected cases
    }

    return 0;
}

// int main() {
//     // Declare and initialize marks variable
//     int marks = 54;

//     // Check grade conditions using if-else ladder
//     if (marks < 25) {
//         cout << "Grade: F" << endl;  // Less than 25 is Grade F
//     } else if (marks >= 25 && marks <= 44) {
//         cout << "Grade: E" << endl;  // Between 25 and 44 is Grade E
//     } else if (marks >= 45 && marks <= 49) {
//         cout << "Grade: D" << endl;  // Between 45 and 49 is Grade D
//     } else if (marks >= 50 && marks <= 59) {
//         cout << "Grade: C" << endl;  // Between 50 and 59 is Grade C
//     } else if (marks >= 60 && marks <= 69) {
//         cout << "Grade: B" << endl;  // Between 60 and 69 is Grade B
//     } else if (marks >= 70) {
//         cout << "Grade: A" << endl;  // 70 and above is Grade A
//     } else {
//         cout << "Invalid marks entered." << endl;  // Handles unexpected cases
//     }

//     return 0;
// }



