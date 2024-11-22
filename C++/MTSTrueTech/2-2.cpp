#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 998244353;

// Функция для вычисления степени с модулем
long long mod_pow(long long base, long long exp, long long mod)
{
  long long result = 1;
  while (exp > 0)
  {
    if (exp % 2 == 1)
    {
      result = (result * base) % mod;
    }
    base = (base * base) % mod;
    exp /= 2;
  }
  return result;
}

// Функция для вычисления обратного элемента по модулю
long long mod_inverse(long long a, long long mod)
{
  return mod_pow(a, mod - 2, mod);
}

int main()
{
  int n;
  cin >> n;
  cout << 26 * 26 * 26 * 448903698 % 998244353;
}