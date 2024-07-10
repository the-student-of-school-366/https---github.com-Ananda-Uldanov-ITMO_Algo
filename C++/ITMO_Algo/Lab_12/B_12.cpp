#include <iostream>
#include <vector>
#include <string>
using namespace std;
int h1(int x)
{
    return (x * 13 % 3) + x % 2 + x % 7;
}
void h(int x, vector<int> &has)
{
    int y =x;
    if (has[h1(x)] == 0)
        has[h1(x)] == x;
    else
    while(has[h1(x)] != 0)
    {
        x+=3;
    }
    has[h1(x)] == y;
}
int main()
{
    int n;
    int m;
    cin >> n >> m;
    vector<int> w1(n);
    vector<int> w2(m);
    vector<int> has(n * m,0);
    for (int i = 0; i < n; i++)
    {
        cin >> w1[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> w2[i];
    }
    for(int i=0;i<n;i++)
    {
        h(w1[i], has);
    }
    for(int i=0;i<m;i++)
    {
        h(w2[i], has);
    }




    for(int i=0;i<n+m;i++)
    {
        if(has[i]!=0)
            cout<<has[i]<<" ";
    }
    


    for(int i=0;i<n;i++)
    {
        w1[i]=w1[i-1]+has[i];
    }
}
