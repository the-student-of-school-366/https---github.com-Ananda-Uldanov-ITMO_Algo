#include <iostream>
#include <cmath>
using namespace std;
int main()
{
  const float pi = 3.14;
  const float e = 2.71;
  float p = 0;
  float q = 0.114;
  float t2 = 5.096;
  float t = 5.74;
  p = 1 / (q * sqrt(2 * pi)) * e - (t - t2) * (t - t2) / (2 * q * q);
  cout << p;
}