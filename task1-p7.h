#ifndef TASK1-P7_H_INCLUDED
#define TASK1-P7_H_INCLUDED
#include <iostream>
#include <vector>
struct dominoT {
    int leftDots;
    int rightDots;
    dominoT(int left_ = 0, int right_ = 0);
};
void getarr(std::vector<dominoT>&dominos);
void FormsDominoChain(std::vector<dominoT> &dominos);
#endif // TASK1-P7_H_INCLUDED
