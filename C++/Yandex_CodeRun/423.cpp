#include <iostream>
#include <vector>
using namespace std;

int binSearch(const vector<int> &road, int x, int left, int right)
{
  if (road[right] < x)
    return right;

  if (road[left] > x)
    return left;

  while (left <= right)
  {
    int mid = left + (right - left) / 2;
    if (road[left] == x)
      return left;
    if (road[mid] == x)
      return mid;
    if (road[mid] < x)
      left = mid + 1;
    else
      right = mid - 1;
  }
  return left;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  cin >> n >> k;
  vector<int> road(n);
  for (int i = 0; i < n; ++i)
  {
    cin >> road[i];
  }

  for (int i = 0; i < k; ++i)
  {
    int stop;
    cin >> stop;

    int res = binSearch(road, stop, 0, n - 1);

    if (res < n and road[res] == stop)
    {
      cout << (res + 1) << endl;
    }
    else
    {
      int leftRes = res - 1;
      int FinalRes = 0;

      if (leftRes >= 0 and (res >= n or abs(road[leftRes] - stop) <= abs(road[res] - stop)))
      {
        FinalRes = leftRes;
      }
      else
      {
        FinalRes = res;
      }

      cout << (FinalRes + 1) << endl;
    }
  }

  return 0;
}
