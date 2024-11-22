#include <iostream>
#include <vector>
using namespace std;
int main()
{
  int n;
  cin >> n;
  vector<int> a;
  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    a.push_back(x);
    sum += x;
  }
  if (sum % 2 == 0)
    cout << 1;
  else
    cout << 0;
}