#include <iostream>
using namespace std;

// XOR operation
string XOR(string a, string b) {
    string r = "";
    for (int i = 1; i < b.size(); i++)
        r += (a[i] == b[i]) ? '0' : '1';
    return r;
}

// CRC division
string crc(string data, string gen) {
    int n = gen.size();
    string temp = data.substr(0, n);

    for (int i = n; i < data.size(); i++) {
        temp = (temp[0] == '1') ? XOR(gen, temp)
                                : XOR(string(n, '0'), temp);
        temp += data[i];
    }

    return (temp[0] == '1') ? XOR(gen, temp)
                           : XOR(string(n, '0'), temp);
}

int main() {
    string data, gen, received;

    cout << "Enter data: ";
    cin >> data;

    cout << "Enter generator: ";
    cin >> gen;

    // Sender side
    string appended = data + string(gen.size() - 1, '0');
    string rem = crc(appended, gen);
    string codeword = data + rem;

    cout << "Remainder: " << rem << endl;
    cout << "Codeword: " << codeword << endl;

    // Receiver side
    cout << "Enter received codeword: ";
    cin >> received;

    string check = crc(received, gen);

    if (check.find('1') != string::npos)
        cout << "ERROR DETECTED\n";
    else
        cout << "NO ERROR\n";

    return 0;
}
