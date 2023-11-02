#include <iostream>
#include "Bigreal.h"

using namespace std;

int main()
{
    Bigreal b("10.10");
    cout<<b;
    Bigreal a("10.10");
    cout<<a<<endl;
    cout<<(a==b);
    return 0;
}
