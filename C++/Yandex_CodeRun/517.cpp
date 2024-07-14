#include <iostream>
#include <vector>
using namespace std;
int main()
{
  int n;
  cin >> n;
  vector<int> v(n, -2);
  cin >> v[0];
  if (v[0] == -1)
  {
    cout << "N0" << endl;
    return 0;
  }
  for (int i = 1; i < n; i++)
  {
    cin >> v[i];
  }
}