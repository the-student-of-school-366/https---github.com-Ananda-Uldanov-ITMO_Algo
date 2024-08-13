#include <bits/stdc++.h>
using namespace std;
int main()
{
  int N, M;
  cin >> N >> M;
  vector<int> vec(N);
  for (int i = 0; i < N; i++)
  {
    vec[i] = i + 1;
  }
  for (int i = 0; i < M; i++)
  {
    int A, B;
    cin >> A >> B;
    A--;
    B--;
    swap(vec[A], vec[B]);
  }
}