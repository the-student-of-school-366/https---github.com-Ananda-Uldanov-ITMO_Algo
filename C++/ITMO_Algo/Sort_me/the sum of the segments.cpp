#include<iostream>
#include<vector>
using namespace std;
int main()
{
  int n;
  cin>>n;
  vector<int> vec;
  vector<int> din_sum(n+1, 0);
  for(int i=0;i<n;i++)
  {
    int x;
    cin>>x;
    vec.push_back(x);
  }
  din_sum[0]=vec[0];
  for(int i=1;i<=n;i++)
  {
    din_sum[i]=din_sum[i-1]+vec[i];
  }
  int m;
  cin>>m;
  for(int i=0;i<m;i++)
  {
    int begin;
    int end;
    int sum=0;
    cin>>begin>>end;
    begin;
    end;
    
    cout<<din_sum[end]-din_sum[begin-1]<<" ";
  }
}