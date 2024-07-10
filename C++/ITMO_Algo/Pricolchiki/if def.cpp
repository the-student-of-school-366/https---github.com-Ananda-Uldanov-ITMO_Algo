#include<iostream>
using namespace std;
#define A true;
int main()
{
    #if defined A
        cout<<"Volodya is right";
    #endif
    cout<<"Volodya made mistake";
}