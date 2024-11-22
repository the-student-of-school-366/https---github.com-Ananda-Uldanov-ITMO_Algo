#include <iostream>
#include <string>

int main()
{
  int n;
  std::string k;
  std::cin >> n;
  std::string v[n];
  for (int i = 0; i < n; ++i)
  {
    std::cin >> v[i];
  }
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < n - 1; ++j)
    {
      if (v[j + 1] + v[j] > v[j] + v[j + 1])
      {
        k = v[j];
        v[j] = v[j + 1];
        v[j + 1] = k;
      }
    }
  }
  if (v[0] == "0")
  {
    std::cout << 0;
  }
  else
  {
    for (int i = 0; i < n; ++i)
    {
      std::cout << v[i];
    }
  }

  return 0;
}