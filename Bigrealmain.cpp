#include <iostream>
#include "Bigreal.h"

using namespace std;

int main()
{
    Bigreal b("5.8");
    Bigreal a("99.7");

    cout<<a+b<<' '<<a-b;


    return 0;
}
