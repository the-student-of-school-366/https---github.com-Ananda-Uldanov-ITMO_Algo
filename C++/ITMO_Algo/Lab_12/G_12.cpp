#include "blazingio.hpp"
#include <vector>
using namespace std;
int h(int x, int n)
{
    return x%n;
}
int main()
{
    int n;
    cin>>n;
    vector<int> tree1(n+1);
    vector<int> deg1(n);
    vector<int> tree2(n+1);
    vector<int> deg2(n);
    vector<int> has(2*n);
    for(int i=0;i<n-1;i++)
    {
        int x;
        int y;
        cin>>x>>y;
        x;
        y;
        tree1[x]+=1;
        tree1[y]+=1;
    }
    for(int i=0;i<n-1;i++)
    {
        int x;
        int y;
        cin>>x>>y;
        x;
        y;
        tree2[x]+=1;
        tree2[y]+=1;
    }


    for(int i=0;i<n;i++)
    {
        int x=i;
        x++;
        deg1[tree1[x]]+=1;
        deg2[tree2[x]]+=1;
    }

    for(int i=0;i<n;i++)
    {
        has[i]=h(deg1[i],n);
    }
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(has[i]==h(deg2[i],n))
            count++;
    }
    if(count==n)
        cout<<"YES";
    else
        cout<<"NO";
}