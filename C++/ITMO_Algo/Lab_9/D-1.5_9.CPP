#include <iostream>
#include <vector>
using namespace std;
const unsigned long long MAX = 1e19;
int main()
{
    int n, m;
    cin >> n;
    cin >> m;
    vector<vector<unsigned long long>> g(n, vector<unsigned long long>(n, MAX));

    for (int i = 0; i < n; i++)
    {
        g[i][i] = 0;
    }

    for (int i = 0; i < m; i++)
    {
        int v1, v2;
        unsigned long long w;
        cin >> v1 >> v2 >> w;
        g[v1 - 1][v2 - 1] = min(g[v1][v2], w);
        g[v2 - 1][v1 - 1] = min(g[v2][v1], w);
    }

    for (int p = 0; p < n; p++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                g[i][j] = min(g[i][j], g[i][p] + g[p][j]);
            }
        }
    }

    int base = 0;
    unsigned long long S = MAX;
    for (int i = 0; i < n; i++)
    {
        unsigned long long s = 0;
        for (int j = 0; j < n; j++)
        {
            s = s + g[i][j];
        }
        if (s < S)
        {
            S = s;
            base = i;
        }
    }
    base++;
    cout <<base;
}