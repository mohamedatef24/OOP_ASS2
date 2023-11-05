
// File: task1-q2.cpp
// Purpose: to replace every "he" with "he or she" and every "him" with "him or her"
// Author: Mohamed Osama
// Section: S23
// ID: 20220477
// TA:Mohamed Talaat
// Date: 28 Oct 2023

#include <iostream>
#include <string>
using namespace std;
int main() {
    string s1;
    cout << "Enter a string: ";
    getline(cin, s1); // read the input string
    int pos = 0;
   while ((pos = s1.find("he", pos)) != string::npos) {//search for"he" and loops until there are no more
        if ((pos == 0 || s1[pos - 1] == ' ') && (pos + 2 == s1.size() || s1[pos + 2] == ' ')) {
            //checks if the first word is "he" or followed by space,and checks if the last word is "he"
            s1.replace(pos, 2, "he or she"); // replace "he" with "he or she"
            pos += 9; // move the position to the end of the replacement string
        } else {
            pos += 2; // move the position to the next occurrence of "he"
        }
    }
   pos=0;//resetting the position to 0
     while ((pos = s1.find("him", pos)) != string::npos) {//search for"him" and loops until there are no more
        if ((pos == 0 || s1[pos - 1] == ' ') && (pos + 3 == s1.size() || s1[pos + 3] == ' ')) {
            //checks if the first word is "him" or followed by space,and checks if the last word is "him"
            s1.replace(pos, 3, "him or her"); // replace "him" with "him or her"
            pos += 11; // move the position to the end of the replacement string
        } else {
            pos += 3; // move the position to the next occurrence of "him"
        }
    }

    cout << s1 << endl; // print the modified string
    return 0;
}
