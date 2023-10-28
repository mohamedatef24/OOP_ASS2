// File: task1-q5.cpp
// Purpose: input the names and scores of players and based on this creates a menu that has several functions
// Author: Mohamed Osama
// Section: S23
// ID: 20220477
// TA: ……………………
// Date: 28 Oct 2023

#include <iostream>
#include <algorithm>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int main() {
    vector<pair<int, string>> players;
    while (true) {
        cout << "Enter a command (a: add player, b: print top 10, c: search player, q: quit): ";
        char command;
        cin >> command;
        //validation to make sure the user will enter the right command
        while (command != 'a' && command != 'b' && command != 'c' && command != 'q') {
            cout << "invalid command please enter a or b or c ";
            cin >> command;
        }
        if (command == 'a') {
            int score;
            string name;
            cout << "Enter the player name and his/her score: ";
            cin >> name >> score;

            //inserting the player to my vector
            players.emplace_back(score, name);

            //sorting them based on their score
            sort(players.rbegin(), players.rend());
            //removing the smallest score if they exceeded 10
            if (players.size() > 10) {

                players.pop_back();
            }
        } else if (command == 'b') {
            cout << "The top 10 player names and scores are:" << endl;
            for (const auto &[score, name]: players) {
                cout << name << " ---- " << score << endl;
            }

        } else if (command == 'c') {
            cout << "Do you want to ask for a specific name (y/n)? ";
            char choice;
            cin >> choice;
            // validation to make sure the user will enter y or n
            while (choice != 'y' && choice != 'n') {
                cout << "Invalid choice. Enter y or n: ";
                cin >> choice;
            }
            // if he does not want to ask for a name return 0
            if (choice == 'n') {
                return 0;
            } else {
                //if he wants to ask for a name
                string name;
                cout << "Enter the name you want to ask for: ";
                cin >> name;

                int highest_score = -1;
                for (const auto &[score, player_name]: players) {
                    if (player_name == name) {
                        highest_score = max(highest_score, score);
                    }
                }

                if (highest_score != -1) {
                    //if name exists returns his highest score
                    cout << "The highest score for " << name << " is: " << highest_score << endl;
                } else {
                    // if name does not exist display this message
                    cout << name << " has not been input or is not in the top 10." << endl;
                }
            }


        }
        //command=='q'
        else
            break;
    }
}