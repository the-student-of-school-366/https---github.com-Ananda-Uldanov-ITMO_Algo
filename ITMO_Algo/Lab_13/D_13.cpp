#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int q;
    cin>>q;
    int counter=0;
    for(int i=0;i<q;i++)
    {
        int a;
        int b;
        int b2;
        char c;
        string d;
        cin>>a;
        if(a==1)
        {
            cin>>b>>c;
            b--;
            s[b]=c;
        }
        if(a==2)
        {
            cin>>b>>b2>>d;
            b--;
            b2--;
            int x=d.size();
            int point=0;
            for(int j=b;j<=b2;j++)
            {
                if(s[j]==d[point%x])
                    counter++;
                point++;
            }
            cout<<counter<<endl;
        }
    }

}