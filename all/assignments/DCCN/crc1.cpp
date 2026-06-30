#include <bits/stdc++.h>
using namespace std;
int crc1(string s)
{
    int n = s.size();
    int crc = 0;
    for (int i = 0; i < n; i++)
    {
        crc ^= s[i];
        for (int j = 0; j < 8; j++)
        {
            if (crc & 1)
                crc = (crc >> 1) ^ 0xEDB88320;
            else
                crc >>= 1;
        }
    }
    return crc ^ 0xFFFFFFFF;
}