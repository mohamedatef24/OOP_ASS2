#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
// File: task1-q11.cpp
// Purpose: compares 2 files either character by character or word by word
// Author: Mohamed Osama
// Section: S23
// ID: 20220477
// TA:Mohamed talaat
// Date: 5 Nov 2023


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int main() {
    // Declare variables to store filenames, current lines, character comparison flag, and result flag.
    string fileName1, fileName2, f1, f2;
    int line = 1;
    char comp;
    bool ident = true;

    // Prompt the user to enter the names of two files.
    cout << "Enter the name of the first file\n";
    cin >> fileName1;
    fileName1 += ".txt";
    ifstream firstFile(fileName1);

    cout << "Enter the name of the second file\n";
    cin >> fileName2;
    fileName2 += ".txt";
    ifstream secondFile(fileName2);

    // Prompt the user to choose character or word comparison.
    cout << "do you want to compare by character or word?\n";
    cin >> comp;

    if (comp == 'c') {
        // Compare files character by character.
        while (!firstFile.eof() || !secondFile.eof()) {
            f1 = "", f2 = "";
            getline(firstFile, f1);
            getline(secondFile, f2);

            // If a difference is found, set 'ident' to false and break out of the loop.
            if (f1 != f2) {
                ident = false;
                break;
            }
            line++;
        }
    } else if (comp == 'w') {
        // Compare files word by word.
        while (!firstFile.eof() || !secondFile.eof()) {
            vector<string> words1, words2;
            f1 = "", f2 = "";
            getline(firstFile, f1);
            getline(secondFile, f2);
            string word;

            // Extract words from the first file's line.
            for (char c : f1) {
                if (isalpha(c)) {
                    word += c;
                } else if (!word.empty()) {
                    words1.push_back(word);
                    word = "";
                }
            }
            if (!word.empty()) {
                words1.push_back(word);
                word = "";
            }

            // Extract words from the second file's line.
            for (char c : f2) {
                if (isalpha(c)) {
                    word += c;
                } else if (!word.empty()) {
                    words2.push_back(word);
                    word = "";
                }
            }
            if (!word.empty()) {
                words2.push_back(word);
                word = "";
            }

            if (words1.size() > words2.size()) {
                // If the first file has more words, set 'f1' to the extra word and 'f2' to an empty string.
                f1 = words1[words2.size()];
                f2 = "";
                ident = false;
                break;
            } else if (words1.size() < words2.size()) {
                // If the second file has more words, set 'f2' to the extra word and 'f1' to an empty string.
                f2 = words2[words1.size()];
                f1 = "";
                ident = false;
                break;
            } else {
                // Compare each word from both files.
                for (int i = 0; i < words1.size(); ++i) {
                    if (words1[i] != words2[i]) {
                        f1 = words1[i];
                        f2 = words2[i];
                        ident = false;
                        break;
                    }
                }
                if (!ident) break;
            }
            line++;
        }
    }

    // Display the comparison result.
    if (ident) {
        cout << "The two files are identical\n";
    } else {
        cout << "There's a difference in line " << line << endl;
        cout << "First file: " << f1 << endl;
        cout << "Second file: " << f2 << endl;
    }
}