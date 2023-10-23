// File: task1-p1.cpp
// Purpose: to fix the input
// Author: Mohamed Atef
// Section: S23
// ID: 20220293
// TA: ……………………
// Date: 23 Oct 2023
#include "task1-p1.h"
#include <vector>
#include <string>


void ftask1_p1(std::istream &input)
{
    std::cout << "Enter Sentence of up to 100 characters: ";
    char in[100];
    input.getline(in, 100);

    std::vector<std::string> output;
    bool flag = false;
    std::string s = "";

    for (short i = 0; in[i] != '\0'; i++)
    {
        if (in[i] == ' ')
        {
            if (flag)
                output.push_back(s);
            s = "";
            flag = false;
        }
        else
        {
            flag = true;
            s += in[i];
        }
    }
    if(flag) output.push_back(s);

    std::cout << "Your sentence after edit: \n";

    for (int i = 0; i < output.size(); i++)
    {
        if (i == 0 && isalpha(output[0][0]))
        {
            output[0][0] = toupper(output[0][0]);
        }

        std::cout << output[i] << " ";
    }
}

