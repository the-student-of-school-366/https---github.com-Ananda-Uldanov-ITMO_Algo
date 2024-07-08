#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
    int n;
    int m;
    string s;
    cin>>n>>m>>s;
    int counter=0;
    for(int i=0;i<m;i++)
    {
        bool flag=true;
        int ii;
        int jj;
        int kk;
        cin>>ii>>jj>>kk;
        ii--;
        jj--;
        for(int j=0;j<kk;j++)
        {
            if(s[ii+j]!=s[jj+j])
            {
                flag=false;
            }
        }
        if(flag)
            counter++;
    }
    cout<<counter;
}