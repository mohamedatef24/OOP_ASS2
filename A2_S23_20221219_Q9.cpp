// File: A2_S23_20221219_9.cpp
// Purpose: A teddy bear game where the user wins if he finishes the game with 42 bears under some conditions.
// Author: Farida Youssry
// Section: S23
// ID: 20221219
// TA: --
// Date: 28/10/2023

#include <bits/stdc++.h>
using namespace std;

bool bears(int n) {
    // Base case: If n is already 42, we've won.
    if (n == 42) {
        return true;
    }

    // Base case: If n is less than 42 or if n has been processed before, we cannot win.
    if (n < 42 || n % 10 == 1) {
        return false;
    }

    // Check the three possible moves and recursively call the function.
    if (n % 2 == 0 && bears(n / 2)) {
        return true;
    }
    if (n % 3 == 0 && bears(n - n % 10 * ((n % 100) / 10))) {
        return true;
    }
    if (n % 4 == 0 && bears(n - n % 10 * ((n % 100) / 10))) {
        return true;
    }
    if (n % 5 == 0 && bears(n - 42)) {
        return true;
    }

    // If none of the moves results in a win, return false.
    return false;
}

int main() {
    int n;
    cout << "Enter the number of bears: ";
    cin >> n;

    if (bears(n)) {
        cout << "is true" << endl;
    } else {
        cout << "is false" << endl;
    }

    return 0;
}