#include <iostream>
using namespace std;

// Bit stuffing
string stuff(string data) {
    string res = "";
    int count = 0;

    for (char b : data) {
        res += b;
        if (b == '1') {
            count++;
            if (count == 5) {
                res += '0';
                count = 0;
            }
        } else count = 0;
    }
    return res;
}

// Bit destuffing
string destuff(string data) {
    string res = "";
    int count = 0;

    for (int i = 0; i < data.size(); i++) {
        if (data[i] == '1') {
            count++;
            res += '1';
        } else {
            if (count == 5) {
                count = 0; // skip stuffed 0
                continue;
            }
            count = 0;
            res += '0';
        }
    }
    return res;
}

int main() {
    string data = "01111110111110";

    string stuffed = stuff(data);
    string frame = "01111110" + stuffed + "01111110";

    cout << "Frame: " << frame << endl;

    string received = destuff(stuffed);

    cout << "Recovered: " << received << endl;

    return 0;
}