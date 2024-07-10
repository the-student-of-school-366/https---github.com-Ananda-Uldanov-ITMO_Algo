#include "do_something.cpp"
int main()
{
    float *a;
    float tma;
    cin>>tma;
    a=&tma;
    do_something(a);
}