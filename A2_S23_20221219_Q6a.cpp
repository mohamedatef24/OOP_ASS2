// File: A2_S23_20221219_6a.cpp
// Purpose: The method prints the value of n as a BINARY number. If n is zero,
//then a single zero is printed; otherwise no leading zeros are printed in the output.
// Author: Farida Youssry
// Section: S23
// ID: 20221219
// TA: --
// Date: 28/10/2023

#include <bits/stdc++.h>
using namespace std;

void binaryPrint(int n) {
    if (n==0){
        cout<<0;
        return;
    }
    else if (n==1){
        cout<<1;
        return;
    }
    else {
        binaryPrint(n/2);
        cout<<n%2;
    }
}

int main() {
    int num;

    cout << "Enter a non-negative decimal number: ";
    cin >> num;
    if (num<0){
        cout<<"Please enter a non-negative decimal number: " ;
        cin>>num;
        cout << "Output: ";
        binaryPrint(num);
        cout << endl;
    }
    else {
        cout << "Output: ";
        binaryPrint(num);
        cout << endl;
    }
    return 0;
}
