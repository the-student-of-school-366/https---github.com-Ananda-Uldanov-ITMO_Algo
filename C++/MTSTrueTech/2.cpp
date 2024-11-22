#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
  string str;
  cin >> str;
  bool flagM = 0;
  bool flagT = 0;
  bool flagS = 0;
  for (int i = 0; i < str.size(); i++)
  {
    if (str[i] == 'M')
      flagM = 1;
    if (str[i] == 'T' and flagM == 1)
      flagT = 1;
    if (str[i] == 'S' and flagT == 1)
      flagS = 1;
  }
  if (flagS == 1)
    cout << "1";
  else
    cout << "0";
}