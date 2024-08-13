#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
using namespace std;

// Функция для вычисления всех возможных увеличений при замене одной цифры
vector<long long> calculateIncreases(long long number)
{
  vector<long long> increases;
  string numStr = to_string(number);

  for (long long i = 0; i < numStr.size(); ++i)
  {
    long long originalDigit = numStr[i] - '0';
    for (long long newDigit = 9; newDigit > originalDigit; --newDigit)
    {
      long long increase = (newDigit - originalDigit) * pow(10, numStr.size() - i - 1);
      increases.push_back(increase);
    }
  }

  return increases;
}

int main()
{
  long long n, k;
  cin >> n >> k;

  vector<long long> numbers(n);
  for (long long i = 0; i < n; ++i)
  {
    cin >> numbers[i];
  }

  // Используем max heap (приоритетная очередь) для хранения увеличений
  priority_queue<long long> increases;

  for (long long number : numbers)
  {
    vector<long long> incs = calculateIncreases(number);
    for (long long inc : incs)
    {
      increases.push(inc);
    }
  }

  long long maxSumIncrease = 0;
  for (long long i = 0; i < k && !increases.empty(); ++i)
  {
    maxSumIncrease += increases.top();
    increases.pop();
  }

  cout << maxSumIncrease << endl;
  return 0;
}
