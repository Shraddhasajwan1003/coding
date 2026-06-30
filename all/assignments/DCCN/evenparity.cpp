#include <iostream>
using namespace std;

// Count 1s
int ones(string s) {
    int c = 0;
    for (char x : s) if (x == '1') c++;
    return c;
}

// Generate parity bit
char parityBit(string s, bool even) {
    return ((ones(s) % 2 == 0) == even) ? '0' : '1';
}

// Check error
bool isError(string s, bool even) {
    return ((ones(s) % 2 == 0) != even);
}

int main() {
    string data = "1011";

    // EVEN parity example
    char p = parityBit(data, true);
    string transmitted = data + p;

    cout << "Transmitted: " << transmitted << endl;

    // simulate error
    transmitted[1] = (transmitted[1] == '0') ? '1' : '0';

    cout << "Received: " << transmitted << endl;

    if (isError(transmitted, true))
        cout << "ERROR DETECTED\n";
    else
        cout << "NO ERROR\n";

    return 0;
}