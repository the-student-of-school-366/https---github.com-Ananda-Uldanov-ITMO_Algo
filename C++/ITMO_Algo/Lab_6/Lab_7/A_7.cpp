#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
   int n;
   cin >> n;
   vector<string> cod;
   cod.push_back("0");
   cod.push_back("1");
   int j;
   for (int i = 2; i < pow(2, n); i=i*2)
   {
      for (j = i - 1; j >= 0; j--)
      {
         cod.push_back(cod[j]);
      }
      for (j = 0; j < i; j++)
      {
         cod[j] = "0" + cod[j];
      }
      for (j = i; j < 2 * i; j++)
      {
         cod[j] = "1" + cod[j];
      }
   }
   for (j = 0; j < cod.size(); j++)
   {
      cout << cod[j] << '\n';
   }
}