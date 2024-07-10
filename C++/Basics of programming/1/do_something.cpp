#include <iostream>
#include "do_something.h"
using namespace std;
void do_something(float *a)
{
    float tma = *a;
    float tmb;
    tmb = 1 / tma;
    cout << tmb;
}