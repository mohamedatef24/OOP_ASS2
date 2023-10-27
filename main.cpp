// File: task1-p10.cpp
// Purpose: make some edits on words
// Author: Mohamed Atef
// Section: S23
// ID: 20220293
// TA: ……………………
// Date: 27 Oct 2023
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    wifstream fin("input.txt");
    wofstream fout("output.txt");
    if(fin.fail()) {cout<<"can't open input file!";return 1;}
    if(fout.fail()) {cout<<"can't open output file!";return 1;}
    wifstream inputFile("mapinput.txt");
    if (!inputFile.is_open()) {
    wcerr << L"Can't open input file!";
    return 1;
    }
    map<wstring, wstring> mp;
    wstring key, value;
    while (inputFile >> key >> value) {
        mp[key] = value;
    }

    wstring word;
    while (fin >> word) {
        map<wstring, wstring>::iterator it = mp.find(word);
        if (it != mp.end()) {
        fout << mp[word] << L' ';
        } else {
        fout << word << L' ';
        }

    }

    return 0;
}
