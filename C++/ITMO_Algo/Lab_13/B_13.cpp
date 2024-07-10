#include <iostream>
#include <vector>
#include<string>
using namespace std;
int main()
{
  string s;
  cin>>s;
  int size;
  size=s.size();
  vector<int> ans(size);
  int val;
  for(int i=1;i<size;i++)
  {
    val=ans[i-1];
    while(val!=0 and s[i]!=s[val])
    {
      val=ans[val-1];
    }
    if(s[i]==s[val])
      val++;
    ans[i]=val;
  }
  for(int i=0;i<size;i++)
    cout<<ans[i]<<" ";
}