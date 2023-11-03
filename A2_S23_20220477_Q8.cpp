
// File: task1-q8.cpp
// Purpose: prints a pattern of asterisks and blanks, using recursive function
// Author: Mohamed Osama
// Section: S23
// ID: 20220477
// TA: ……………………
// Date: 3 Nov 2023

#include <iostream>
using namespace std;

// n: number of stars in the middle row
// i: number of spaces before the pattern
void pattern(ostream& outs, unsigned int n, unsigned int i){

    if (n == 1){ // Base case: if n is 1, print a single star and return
        outs << "*"<<endl;
    }

    else{ // Recursive case: print the pattern recursively
        pattern(outs, n / 2, i + 1); // Print the pattern for the top half
        for (int k = 0; k < n; k++){ // Print the middle row of stars
            outs << "* ";

        }
        outs<<endl;

        for (int k = 0; k < i; k++){ // Print the spaces before the pattern
            outs << ' ';
        }

        pattern(outs, n / 2, i + 1); // Print the pattern for the bottom half

    }
}

int main() {
    pattern(cout,8,2); // Call the pattern function with n=8 and i=2
    return 0;
}