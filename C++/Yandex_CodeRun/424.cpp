#include <iostream>
#include <string>

using namespace std;

bool Happy(const string &number)
{
  int len = number.length();
  int half = len / 2;
  int sum1 = 0, sum2 = 0;

  for (int i = 0; i < half; i++)
  {
    sum1 += number[i] - '0';
    sum2 += number[i + half] - '0';
  }

  return sum1 > 0 && sum1 == sum2;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string number;
  cin >> number;

  int len = number.length();
  string limit(len + 1, '0');
  limit[0] = '1';

  for (int i = len - 1; i >= 0; i--)
  {
    if (number[i] == '9')
    {
      number[i] = '0';
    }
    else
    {
      number[i]++;
      break;
    }
  }

  while (number != limit && !Happy(number))
  {
    for (int i = len - 1; i >= 0; i--)
    {
      if (number[i] == '9')
      {
        number[i] = '0';
      }
      else
      {
        number[i]++;
        break;
      }
    }
  }

  if (number == limit)
  {
    number = string(len, '0');
    int half = len / 2;
    number[half - 1] = '1';
    number[len - 1] = '1';
  }

  cout << number;

  return 0;
}
