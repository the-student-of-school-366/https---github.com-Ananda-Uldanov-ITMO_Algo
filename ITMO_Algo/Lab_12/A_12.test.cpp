#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
long long const A = sqrt(5)-1%1;
long long f(long long x, long long n)
{
    return n*(x*A);
}
int main()
{
    long long n;
    bool flag=1;
    vector<long long> table(3*n,-1);
    cin>>n;
    for(long long i=0;i<n;i++)
    {
        long long x;
        cin>>x;
        table[f(x, n)]=x;
    }
    for(long long i=0;i<n;i++)
    {
        long long x;
        cin>>x;
        if(table[f(x, n)]==-1)
            flag=0;
    }
    if(!flag)
        cout<<"NO";
    else
        cout<<"YES";
}