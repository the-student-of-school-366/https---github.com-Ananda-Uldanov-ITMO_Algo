#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> vec(n);
  for (int i = 0; i < n; i++)
    cin >> vec[i];

  vector<int> c(1000001, -1);

  for (int i = 0; i < n; i++)
    c[vec[i]]++;

  for (size_t i = 0; i < c.size(); i++)
  {
    if (c[i] != 3 && c[i] != -1)
    {
      cout << i;
      break;
    }
  }
}