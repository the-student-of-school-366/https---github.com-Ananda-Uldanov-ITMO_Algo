#include <iostream>
#include <vector>
using namespace std;
int main()
{

  int n;
  int t;
  cin >> n >> t;
  vector<int> floors(n);
  for (int i = 0; i < n; i++)
  {
    cin >> floors[i];
  }
  int leave_time_id;
  cin >> leave_time_id;
  leave_time_id--;
  if (floors[leave_time_id] - floors[0] <= t)
  {
    cout << floors[n - 1] - floors[0];
  }
  else
  {

    cout << floors[n - 1] - floors[0] + (floors[leave_time_id] - floors[0]);
  }
}