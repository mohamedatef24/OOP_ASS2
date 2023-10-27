// File: task1-p2.cpp
// Purpose: to find  the solution of the domino chain
// Author: Mohamed Atef
// Section: S23
// ID: 20220293
// TA: ……………………
// Date: 23 Oct 2023
#include "task1-p7.h"
#include <deque>
int l=0,r=0;
std::deque<int>out,anss;
std::vector<bool>vis;
dominoT::dominoT(int left_,int right_)
{
    leftDots=left_;
    rightDots=right_;
}
void getarr(std::vector<dominoT>&dominos)
{
    std::cout<<"Enter the number of dominos: ";
    int n;std::cin>>n;
    for (int i = 0; i < n; i++)
    {
        vis.push_back(0);
        int ldots, rdots;
        std::cout << "Enter the left dots: ";
        std::cin >> ldots;
        std::cout << "Enter the right dots: ";
        std::cin >> rdots;
        dominos.push_back(dominoT(ldots, rdots));
    }
}
int templ=0,tempr=0;
bool ck( std::vector<dominoT>& dominos)
{
    int ans=0;

    if((int)out.size()==(int)dominos.size()) {
        if(anss.empty())
        {

            for(int j=0;j<(int)out.size();j++)
            {

                anss.push_back(out[j]);
            }
        }

        return 1;
    }
    for(int i=0;i<(int)dominos.size();i++)
    {
        if(out.empty())
        {
            l=dominos[i].leftDots;
            r=dominos[i].rightDots;
            templ=l;tempr=r;
            vis[i]=1;out.push_back(i);
            ans= (ans|ck(dominos));
            vis[i]=0;
            out.pop_back();
            l=r=0;
        }
        else if(dominos[i].leftDots==r&&!vis[i])
        {
            vis[i]=1;
            out.push_back(i);
            templ=l;
            tempr=r;
            r=dominos[i].rightDots;
            ans=(ans| ck(dominos));
            vis[i]=0;
            out.pop_back();
            l=templ;
            r=tempr;
        }
        else if(dominos[i].rightDots==l&&!vis[i])
        {
            vis[i]=1;
            out.push_front(i);
            templ=l;
            tempr=r;
            l=dominos[i].leftDots;
            ans=(ans| ck(dominos));
            vis[i]=0;
            out.pop_front();
            l=templ;
            r=tempr;
        }
    }
    return ans;
}

void FormsDominoChain(std::vector<dominoT> & dominos)
{
    getarr(dominos);
    if(ck(dominos))
    {
        for(int i=0;i<(int)anss.size();i++)
        {
            std::cout<<dominos[anss[i]].leftDots<<"|"<<dominos[anss[i]].rightDots;
            if(i+1<anss.size()) std::cout<<" - ";
            else std::cout<<'\n';
        }
    }
    else std::cout<<"Sorry it's not Possible to build a chain consisting of every domino in the vector.\n";
}
