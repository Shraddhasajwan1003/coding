#include <iostream>
using namespace std;

int main() {
    int day;

    // Prompt user to enter a number between 1 and 7
    cout << "Enter a number (1-7): ";
    cin >> day;

    // Switch statement to determine the day
    switch (day) {
        case 1:
            cout << "Monday" << endl;
            break; // Exit switch after matching case
        case 2:
            cout << "Tuesday" << endl;
            break;
        case 3:
            cout << "Wednesday" << endl;
            break;
        case 4:
            cout << "Thursday" << endl;
            break;
        case 5:
            cout << "Friday" << endl;
            break;
        case 6:
            cout << "Saturday" << endl;
            break;
        case 7:
            cout << "Sunday" << endl;
            break;
        default://default block 
            // Executed if input is not between 1 and 7
            cout << "Invalid" << endl;
    }

    return 0; // End program
}
//another example of switch cases
//switch works on integer and char mostly 
//Requirement for a Constant Expression :A switch statement necessitates that its expression results in a constant value. This can include constants and arithmetic operations.
// #include <iostream>
// using namespace std;

// int main() {
//     // Define two constant integers
//     const int x = 10;
//     const int y = 5;

//     // Evaluate the sum of x and y using a switch statement
//     switch (x + y) {
//         case 15: // If the sum equals 15
//             cout << "Result is 15." << endl;
//             break; // Exit the switch block
//         case 20: // If the sum equals 20
//             cout << "Result is 20." << endl;
//             break; // Exit the switch block
//         default: // If no case matches
//             cout << "No match found." << endl;
//     }

//     return 0; // End of program
// }
//#include <iostream>
// using namespace std;

// int main() {
//     // Define a character variable representing a grade
//     char grade = 'B';

//     // Evaluate grade using a switch statement
//     switch (grade) {
//         case 'A': // If grade is 'A'
//             cout << "Excellent!" << endl;
//             break; // Exit switch after this case
//         case 'B': // If grade is 'B'
//             cout << "Good!" << endl;
//             break; // Exit switch after this case
//         default: // If no case matches
//             cout << "Not specified." << endl;
//     }

//     return 0; // End of program
// }



