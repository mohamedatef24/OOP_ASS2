// File: task1-p2.cpp
// Purpose: to find the prime numbers between 2 and n
// Author: Mohamed Atef
// Section: S23
// ID: 20220293
// TA: ……………………
// Date: 23 Oct 2023
#include "task1-p2.h"
#include <vector>
void ftask1_p4(std::istream &input)
{
    std::cout<<"Enter N to find the prime numbers between 1 and n: ";
    int n;input>>n;
    std::vector<int>output;
    std::vector<bool>vis(n+1,0);
    vis[0]=vis[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(!vis[i])
        {
            output.push_back(i);
            int x=i;
            x+=x;
            while(x<=n)
            {
                vis[x]=1;
                x+=x;
            }
        }
    }
    for(int i=0;i<(int)output.size();i++) std::cout<<output[i]<<" \n"[i+1==output.size()];
}
