#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
    string title;
    string name;
    cin>>title;
    cin>>name;
    vector<int> ans;
    int t=title.size();
    int n=name.size();
    for(int i=0;i<t;i++)
    {
        if(title[i]==name[0])
        {
            if(n==1)
            {
                ans.push_back(i);
                continue;
            }
            for(int j=1;j<n;j++)
            {
                if(title[i+j]==name[j])
                {
                    if(j==n-1)
                    {
                        ans.push_back(i);
                    }
                }
                else
                    break;
                
            }
            
        }
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<' ';
    }
}