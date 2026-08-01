#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

// Recursive function to count good numbers
int countGoodNumbers(int index, int n)
{
    // Base case: if we've reached the end of the string
    if (index == n)
    {
        // Return 1 as we've formed a valid string
        return 1;
    }

    int result = 0;
    // Even index: Use even digits
    if (index % 2 == 0)
    {
        // Even digits: 0, 2, 4, 6, 8
        for (int digit : {0, 2, 4, 6, 8})
        {
            // speacila syntax for for loop: initialiser list
            // same way to write is below
            // int evenDigits[] = {0, 2, 4, 6, 8};
            // for (int i = 0; i < 5; i++) {
            //     int digit = evenDigits[i];
            //     result = (result + countGoodNumbers(index + 1, n)) % MOD;
            result = (result + countGoodNumbers(index + 1, n)) % MOD;
        }
    }

    // Odd index: Use prime digits
    else
    {
        // Prime digits: 2, 3, 5, 7
        for (int digit : {2, 3, 5, 7})
        {
            result = (result + countGoodNumbers(index + 1, n)) % MOD;
        }
    }
    return result;
}

int main()
{
    int n = 1;
    cout << countGoodNumbers(0, n) << endl;
    return 0;
}