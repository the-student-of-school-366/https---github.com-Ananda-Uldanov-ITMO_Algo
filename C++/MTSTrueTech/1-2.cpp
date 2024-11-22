#include <iostream>
using namespace std;
int main()
{
  int n;
  cin >> n;
  int x, y;
  int min = 99999999;
  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    int x, y;
    cin >> x;
    sum += x;
    if (min > x / 2)
      min = x / 2;
    y = x;
  }
  if ((y != 0) and (x / y >= 5))
    min = (sum - y) / 2;
  cout << min;
}