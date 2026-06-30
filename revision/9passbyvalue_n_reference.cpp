//pass by value eisa h jaise tumne docx file download krke dusre ko uski copy send ki 
//pass by reference eisa h jaise tumne google doc ka link dedia h kisi ko , vo direct edit kr skta h 
// Pass by Value

// #include <iostream>
// using namespace std;

// void modify(int a) {
//     a = a + 10;
// }

// int main() {
//     int x = 5;
//     modify(x);
//     cout << x << endl; // Output: 5
//     return 0;
// }
// Pass by Reference

#include <iostream>
using namespace std;

void modify(int &a) {
    a = a + 10;
}

int main() {
    int x = 5;
    modify(x);
    cout << x << endl; // Output: 15
    return 0;
}
//pass by value 
//Key Characteristics:
// The function receives a separate copy
// Changes inside the function don’t affect the original variable
// Safe, but potentially less efficient for large objects

//pass by refernec 
// Key Characteristics:
// The function receives the original memory address
// Changes inside the function affect the original
// Useful when you want to update multiple variables or return multiple value