#include <iostream>
using namespace std;
int main()
{
  int n, m;
  cin >> n >> m;
  int a[n][m];
  int j, i, ii, jj;
  int c = 0;
  for (j = 0; j < m; ++j)
  {
    i = 0;
    jj = j;
    while (i < n && jj >= 0)
    {
      a[i][jj] = c;
      c++;
      i++;
      jj--;
    }
  }
  for (i = 1; i < n; ++i)
  {
    j = m - 1;
    ii = i;
    while (ii < n && j >= 0)
    {
      a[ii][j] = c;
      c++;
      ii++;
      j--;
    }
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
}