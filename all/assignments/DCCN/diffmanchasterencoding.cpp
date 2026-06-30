#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;

    char level = 'H';

    for (char b : s) {
        if (b == '0') // start transition
            level = (level == 'H') ? 'L' : 'H';

        cout << level; // first half

        level = (level == 'H') ? 'L' : 'H'; // mid transition

        cout << level << " ";
    }
}