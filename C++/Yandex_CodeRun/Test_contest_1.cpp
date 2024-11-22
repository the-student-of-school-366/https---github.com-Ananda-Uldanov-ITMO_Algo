#include <iostream>
#include <set>
#include <string>
#include <stdio.h>
#include <iomanip>
using namespace std;
int main()
{

  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    set<char> s;
    int sum = 0;
    string fa, im, ot;
    char c, first_letter;
    cin >> first_letter;
    s.insert(first_letter);
    int comma_count = 0;
    while (comma_count < 3)
    {
      cin >> c;
      if (c != ',')
      {
        s.insert(c);
      }
      else
      {
        comma_count++;
      }
    }
    int d, m, y;
    cin >> d >> c >> m >> c >> y;
    while (d > 0)
    {
      sum += d % 10;
      d = d / 10;
    }
    while (m > 0)
    {
      sum += m % 10;
      m = m / 10;
    }
    sum = sum * 64;
    sum += (first_letter - 'A' + 1) * 256;
    sum += s.size();
    sum = sum & 0xFFF;
    printf("%x", sum);
    cout << " ";
  }
}