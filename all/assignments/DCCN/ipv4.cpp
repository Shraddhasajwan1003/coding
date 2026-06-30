#include <iostream>
#include <sstream>
using namespace std;

int main() {
    string ip;
    cout << "Enter IPv4 Address: ";
    cin >> ip;

    stringstream ss(ip);
    string firstOctetStr;
    getline(ss, firstOctetStr, '.');

    int firstOctet = stoi(firstOctetStr);
    if (firstOctet >= 1 && firstOctet <= 126)
        cout << "Class A IP Address" << endl;
    else if (firstOctet == 127)
        cout << "Loopback Address (Reserved)" << endl;
    else if (firstOctet >= 128 && firstOctet <= 191)
        cout << "Class B IP Address" << endl;
    else if (firstOctet >= 192 && firstOctet <= 223)
        cout << "Class C IP Address" << endl;
    else if (firstOctet >= 224 && firstOctet <= 239)
        cout << "Class D IP Address (Multicast)" << endl;
    else if (firstOctet >= 240 && firstOctet <= 255)
        cout << "Class E IP Address (Experimental)" << endl;
    else
        cout << "Invalid IP Address" << endl;

    return 0;
}
