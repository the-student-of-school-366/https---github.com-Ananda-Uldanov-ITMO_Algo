#include  "blazingio.hpp"
#include <vector>
#include <string>
using namespace std;
int const M=1000001;
int h1(string &s)
{
  int tmp = 0;

  for (auto i : s)
  {
    tmp += tmp * 109 + i;
  }
  return tmp % (M);
}

int h2(string &s)
{
  int tmp = 0;

  for (auto i : s)
  {
    tmp += tmp * 109 + i;
  }
  return (tmp + 167) % (M);
}

void insert_a(vector<string> &str_1, string &x, int n)
{
  int ind1 = h1(x);
  int ind2 = h2(x);

  if (str_1[ind1].empty())
  {
    str_1[ind1] = x;
  }

  else if (str_1[ind2].empty())
  {
    str_1[ind2] = x;
  }

  else
  {
    str_1[ind1] = x;
    while (!str_1[ind1].empty() and str_1[ind1] != x)
    {
      if (h1(str_1[ind1]) == ind1)
      {
        swap(str_1[h2(str_1[ind1])], str_1[ind1]);
      }
      else
      {
        swap(str_1[h1(str_1[ind1])], str_1[ind1]);
      }
    }

    str_1[ind2] = x;
    while (!str_1[ind2].empty() and str_1[ind2] != x)
    {
      if (h1(str_1[ind2]) == ind1)
      {
        swap(str_1[h2(str_1[ind2])], str_1[ind2]);
      }
      else
      {
        swap(str_1[h1(str_1[ind2])], str_1[ind2]);
      }
    }
  }
}

void insert_b(vector<string> &str_2, string &x, int n)
{
  int ind1 = h1(x);
  int ind2 = h2(x);

  if (str_2[ind1].empty())
  {
    str_2[ind1] = x;
  }

  else if (str_2[ind2].empty())
  {
    str_2[ind2] = x;
  }

  else
  {
    str_2[ind1] = x;
    while (!str_2[ind1].empty() and str_2[ind1] != x)
    {
      if (h1(str_2[ind1]) == ind1)
      {
        swap(str_2[h2(str_2[ind1])], str_2[ind1]);
      }
      else
      {
        swap(str_2[h1(str_2[ind1])], str_2[ind1]);
      }
    }

    str_2[ind2] = x;
    while (!str_2[ind2].empty() and str_2[ind2] != x)
    {
      if (h1(str_2[ind2]) == ind1)
      {
        swap(str_2[h2(str_2[ind2])], str_2[ind2]);
      }
      else
      {
        swap(str_2[h1(str_2[ind2])], str_2[ind2]);
      }
    }
  }
}

void insert_c(vector<string> &str_3, string &x, int n)
{
  int ind1 = h1(x);
  int ind2 = h2(x);

  if (str_3[ind1].empty())
  {
    str_3[ind1] = x;
  }

  else if (str_3[ind2].empty())
  {
    str_3[ind2] = x;
  }

  else
  {
    str_3[ind1] = x;
    while (!str_3[ind1].empty() and str_3[ind1] != x)
    {
      if (h1(str_3[ind1]) == ind1)
      {
        swap(str_3[h2(str_3[ind1])], str_3[ind1]);
      }
      else
      {
        swap(str_3[h1(str_3[ind1])], str_3[ind1]);
      }
    }

    str_3[ind2] = x;
    while (!str_3[ind2].empty() and str_3[ind2] != x)
    {
      if (h1(str_3[ind2]) == ind1)
      {
        swap(str_3[h2(str_3[ind2])], str_3[ind2]);
      }
      else
      {
        swap(str_3[h1(str_3[ind2])], str_3[ind2]);
      }
    }
  }
}

bool exist(vector<string> &s, string &x)
{
  return (s[h1(x)] == x) or (s[h2(x)] == x);
}

int main()
{
  vector<string> m1;
  vector<string> m2;
  vector<string> m3;
  int n;
  string k;
  int res1=0;
  int res2=0;
  int res3=0;

  cin >> n;

  vector<string> str_1(M);
  vector<string> str_2(M);
  vector<string> str_3(M);

  for (int i = 0; i < n; i++)
  {
    cin >> k;
    insert_a(str_1, k, n);
    m1.push_back(k);
  }
  for (int i = 0; i < n; i++)
  {
    cin >> k;
    insert_b(str_2, k, n);
    m2.push_back(k);
  }
  for (int i = 0; i < n; i++)
  {
    cin >> k;
    insert_c(str_3, k, n);
    m3.push_back(k);
  }

  string t;
  for (int i = 0; i < n; i++)
  {
    t = m1[i];
    if (!exist(str_2, t) and !exist(str_3, t))
    {
      res1 += 3;
    }
    else if (exist(str_2, t) and exist(str_3, t))
    {
      res1 += 0;
    }
    else 
      res1 += 1;
  }
  for (int i = 0; i < n; i++)
  {
    t = m2[i];
    if (!exist(str_1, t) and !exist(str_3, t))
    {
      res2 += 3;
    }
    else if (exist(str_1, t) and exist(str_3, t))
    {
      res2 += 0;
    }
    else 
      res2 += 1;
  }
  for (int i = 0; i < n; i++)
  {
    t = m3[i];
    if (!exist(str_1, t) and !exist(str_2, t))
    {
      res3 += 3;
    }
    else if (exist(str_1, t) and exist(str_2, t))
    {
      res3 += 0;
    }
    else 
      res3 += 1;
  }


    cout << res1 << " "<<res2<<" "<<res3;
}