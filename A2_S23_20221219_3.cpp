// File: A2_S23_20221219_3.cpp
// Purpose: implementing the function split so that it returns a vector of the strings in target that are separated by the
//string delimiter.
// Author: Farida Youssry
// Section: S23
// ID: 20221219
// TA: --
// Date: 28/10/2023

#include <bits/stdc++.h>
using namespace std;

vector<string> split(string target, string delimiter) {
    vector<string> result; // Create a vector to store the split parts.
    size_t start = 0; // Initialize the start index for searching.
    size_t end = target.find(delimiter); // Find the first occurrence of the delimiter.

    while (end != string::npos) {
        // Add the substring from start to the delimiter position to the result vector.
        result.push_back(target.substr(start, end - start));
        start = end + delimiter.length(); // Update the start index for the next search.
        end = target.find(delimiter, start); // Find the next occurrence of the delimiter.
    }

    // Add the last part of the string after the last delimiter (or the entire string if there are no more delimiters).
    result.push_back(target.substr(start));

    return result; // Return the vector containing the split parts.
}

int main() {
    string input;
    string delimiter;

    cout << "Enter a string to split: ";
    getline(cin, input);

    cout << "Enter the delimiter: ";
    getline(cin, delimiter);

    vector<string> parts = split(input, delimiter);

    // Display all the split parts
    for (const string& part : parts) {
        cout << part << endl;
    }

    return 0;
}



