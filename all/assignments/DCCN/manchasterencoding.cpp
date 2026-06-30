#include <iostream>
using namespace std;

int main() {
    string s, res = "";
    cin >> s;

    for (char c : s)
        res += (c == '1') ? "01" : "10";

    cout << res;
}