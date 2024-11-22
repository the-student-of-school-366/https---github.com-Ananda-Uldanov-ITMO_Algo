#include <iostream>
#include <vector>
using namespace std;

int func(int x)
{
  if (x == 1)
    return 0;
  else if (x == 2)
    return 1;
  else if (func(x - 1) == 1 and func(x - 2) == 1)
    return 0;
  else
    return 1;
}

int main()
{
  int x;
  cin >> x;
  if (func(x))
  {
    cout << "Schtirlitz" << endl;
    if (x == 2)
      cout << 1 << endl
           << 2 << endl;
    else if (x == 3)
    {
      cout << 2;
    }
    else if (func(x - 1) == 0 and func(x - 2) == 0)
    {
      for (int i = 1; i <= x; i++)
        cout << i << endl;
    }
    else if (func(x - 1) == 0)
    {
      cout << 1 << endl;
      for (int i = 3; i <= x - 2; i++)
        cout << i << endl;
      cout << x << endl;
    }
    else if (func(x - 2) == 0)
    {
      cout << 2 << endl
           << x - 1 << endl;
    }
  }
  else
    cout << "Mueller" << endl;
}