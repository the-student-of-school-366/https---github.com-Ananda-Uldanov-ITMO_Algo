#include <iostream>

using namespace std;

int main()
{
  int a, b, n;
  cin >> a >> b >> n;

  int minB = (b + n - 1) / n;
  int maxA = a;

  if (maxA > minB)
    cout << "Yes";
  else
    cout << "No" << endl;
  return 0;
}
