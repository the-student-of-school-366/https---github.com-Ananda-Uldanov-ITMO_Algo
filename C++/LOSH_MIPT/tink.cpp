#include <iostream>
using namespace std;

int main()
{
  int an;
  int bn;
  int x;
  int y;
  int t;
  cin >> x;
  cin >> y;
  cin >> an;
  cin >> bn;
  if (x * 2 >= y)
  {
    while (an != 0 || bn != 0)
    {
      if (an > bn)
      {
        an -= 1;
        t += x;
      }
      else if (an < bn)
      {
        bn -= 1;
        t += x;
      }
      else
      {
        an -= 1;
        bn -= 1;
        t += y;
      }
    }
  }
  else
  {
    while (an != 0 || bn != 0)
    {
      if (an > bn)
      {
        an -= 1;
        t += x;
      }
      else if (an < bn)
      {
        bn -= 1;
        t += x;
      }
      else
      {
        an -= 1;
        bn -= 1;
        t += x * 2;
      }
    }
  }
  cout << t;
  return 0;
}