#include <iostream>
#include <vector>
using namespace std;
int main()
{
  int n, m;
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  vector<int> vec(n + 1);

  for (int i = 1; i <= n; ++i)
  {
    vec[i] = i;
  }

  for (int i = 0; i < m; ++i)
  {
    int l;
    int r;
    cin >> l >> r;

    for (int j = 0; j < (r - l + 1) / 2; ++j)
    {
      swap(vec[l + j], vec[r - j]);
    }
  }

  for (int i = 1; i <= n; ++i)
  {
    cout << vec[i] << " ";
  }
}