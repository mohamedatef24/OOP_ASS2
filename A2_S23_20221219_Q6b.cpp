// File: A2_S23_20221219_6b.cpp
// Purpose: The method prints a sequence of binary numbers. Each output number
//consists of the prefix followed by a suffix of exactly k more binary digits (0's or
//1's). All possible combinations of the prefix and k-digit suffix are printed..
// Author: Farida Youssry
// Section: S23
// ID: 20221219
// TA: --
// Date: 28/10/2023


#include <bits/stdc++.h>
using namespace std;

void numbers(string prefix, int k) {
    if (k == 0) {
        // When k reaches 0, print the prefix once by itself and return
        cout << prefix << endl;
    } else {
        // Recursively generate binary numbers with varying suffixes (0 or 1)
        numbers(prefix + "0", k - 1);
        numbers(prefix + "1", k - 1);
    }
}

int main() {
    string prefix;
    int k;

    cout << "Enter the binary prefix: ";
    cin >> prefix;

    cout << "Enter a non-negative integer k: ";
    cin >> k;

    cout << "Generated binary numbers:" << endl;
    numbers(prefix, k);

    return 0;
}