#include <bits/stdc++.h>
using namespace std;
int main()
{
  int x;
  cin >> x;
  int y = log2(x);
  bool isPowerOfTwo = x && !(x & (x - 1));
  if (isPowerOfTwo)
    cout << y;
  else
    cout << y + 1;
}