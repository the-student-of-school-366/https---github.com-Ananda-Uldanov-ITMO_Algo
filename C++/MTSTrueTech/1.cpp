#include <iostream>
#include <vector>
using namespace std;
int main()
{
  int a, b, u;
  int sum = 0;
  cin >> a >> b >> u;
  if (u < 100)
    sum = a;
  else
    sum = (u - 100) * b + a;
  cout << sum << endl;
}