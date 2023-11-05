
// File: task1-q8.cpp
// Purpose: prints a pattern of asterisks and blanks, using recursive function
// Author: Mohamed Osama
// Section: S23
// ID: 20220477
// TA: Mohamed Talaat
// Date: 3 Nov 2023

#include <iostream>
using namespace std;

void Pattern(int spaces, int length)
{
    // Base case: If the length is zero, stop the recursion.
    if (length == 0)
        return;

    // Recursive call to draw the "half pattern" above the current line.
    Pattern(spaces, length / 2);

    // Print spaces to create an indentation, and then print '*' characters to form the central string.
    for (int i = 0; i < spaces; i++) cout << "  ";
    for (int i = 0; i < length; i++) cout << "* ";
    cout << endl;

    // Recursive call to draw the "half pattern" below the current line.
    Pattern(spaces + length / 2, length / 2);
}

int main()
{
    // n is the number that the user will enter
    int n;
    cout << "Enter a number that is power of 2: ";
    cin >> n;

    // Call the pattern drawing function, starting with zero spaces and the specified 'n'.
    Pattern(0, n);
    // in case of n = 8 here the program will print the shape in the question
}
