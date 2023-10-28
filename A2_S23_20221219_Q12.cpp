// File: A2_S23_20221219_12.cpp
// Purpose: A program that scans a file of text for these terms and phrases. For each occurrence of a keyword or phrase within
//the text file, add the assigned point value to the total points for that word or phrase. For each keyword or
//phrase found, output one line with the word or phrase, the number of occurrences and the point total.
//Then show the point total for the entire message.
// Author: Farida Youssry
// Section: S23
// ID: 20221219
// TA: --
// Date: 28/10/2023

#include <bits/stdc++.h>
using namespace std;

struct keywords {
    string text;
    int point;
};

const int num_keywords = 30;
keywords phishing_keywords[num_keywords] = {
        {"free money", 1},
        {"You've Won a prize", 3},
        {"Your account has been hacked", 2},
        {"Security Alert", 2},
        {"Unusual Activity", 3},
        {"Urgent Action Required", 2},
        {"Account Verification", 1},
        {"Password Reset", 2},
        {"Update Your Billing Information", 3},
        {"Tax Refund", 1},
        {"Shipping Confirmation", 1},
        {"Click Here to Claim Your Prize", 2},
        {"PayPal", 1},
        {"Amazon", 2},
        {"Limited time offer", 3},
        {"PayPal Security Check", 3},
        {"Lottery Winner", 3},
        {"Netflix", 2},
        {"Credit Card Information Needed", 3},
        {"Instagram", 1},
        {"Unsubscribe", 2},
        {"Your invoice", 2},
        {"Urgent Account Update", 2},
        {"Resend Your Payment", 2},
        {"Linkedin", 1},
        {"Renew Your Subscription", 2},
        {"Credit Card Validation", 3},
        {"Important Update", 1},
        {"Free Gift", 3},
        {"Login", 1},
};

int main() {
    string user_input;

    // Prompt the user to enter the text
    cout << "Enter the text: ";
    getline(cin, user_input);

    // Create and open a file for writing
    ofstream outputFile("user_input.txt");

    if (outputFile.is_open()) {
        // Write the user input to the file
        outputFile << user_input << endl;
        outputFile.close(); // Close the file
    } else {
        cerr << "Error: Unable to open the file for writing." << endl;
        return 1;
    }

    // Now, you can proceed to scan the user input text for phishing keywords

    int totalPoints = 0;
    map<string, int> keywordPoints; // Use a map to store total points for each keyword

    for (int i = 0; i < num_keywords; ++i) {
        size_t found = user_input.find(phishing_keywords[i].text);
        int occurrences = 0; // Count occurrences of the current keyword
        while (found != string::npos) {
            occurrences++;
            keywordPoints[phishing_keywords[i].text] += phishing_keywords[i].point;
            found = user_input.find(phishing_keywords[i].text, found + 1);
        }

        if (occurrences > 0) {
            // Display occurrences along with total points
            cout << phishing_keywords[i].text << ": " << occurrences << " occurrence(s) (Total points: " << keywordPoints[phishing_keywords[i].text] << ")" << endl;
        }
    }

    // Calculate the total points and display the results
    for (const auto& pair : keywordPoints) {
        totalPoints += pair.second;
    }

    cout << "Total Phishing Points: " << totalPoints << endl;

    return 0;
}