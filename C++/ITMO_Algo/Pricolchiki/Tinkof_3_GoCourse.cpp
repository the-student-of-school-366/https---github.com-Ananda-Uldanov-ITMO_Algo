#include <iostream>
#include <vector>
#include <cstdlib> // для std::abs
using namespace std;
// const int a = 252149039; // Задайте значение a
// const int m = 281474977; // Задайте значение m

int lcg(int e, int a, int m)
{
  return (a * e + 11) % m;
}

void generator(int seed, int a, int m)
{
  vector<int> sequence;
  while (true)
  {
    seed = lcg(seed, a, m);
    int value = (abs(seed % 3 - 1) * 5 + abs(seed % 3) * 2) % 8;
    sequence.push_back(value);
    cout << value << " ";
    if (sequence.size() > 100)
      break;
  }
}

int main()
{
  int n, k, a, m;
  cin >> n >> k >> a >> m;
  generator(0, a, m);
  return 0;
}
