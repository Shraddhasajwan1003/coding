#include <iostream>
#include <vector>
using namespace std;

// 8-bit checksum
uint8_t checksum8(vector<uint8_t> d) {
    int sum = 0;
    for (auto x : d) sum += x;
    return ~(sum % 256);
}

// verify
bool verify8(vector<uint8_t> d, uint8_t cs) {
    int sum = cs;
    for (auto x : d) sum += x;
    return (sum % 256) == 255;
}

// inject error
void error(vector<uint8_t> &d, int pos, int bit) {
    d[pos] ^= (1 << bit);
}

int main() {
    vector<uint8_t> data = {0x45, 0x3A, 0x7F};

    uint8_t cs = checksum8(data);
    cout << "Checksum: " << (int)cs << endl;

    cout << "No error: " << (verify8(data, cs) ? "PASS" : "FAIL") << endl;

    error(data, 1, 2); // flip bit

    cout << "With error: " << (verify8(data, cs) ? "PASS" : "FAIL") << endl;

    return 0;
}