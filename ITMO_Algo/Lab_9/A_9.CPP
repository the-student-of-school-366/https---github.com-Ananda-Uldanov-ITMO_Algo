#include <iostream>
#include <vector>
#include <set>
using namespace std;
void dfs(vector<set<int>> &g, int v, vector<int> &visit, int r, int &flag)
{
    visit[v] = 1;
    if (v == r)
    {
        flag = 1;
    }
    for (auto u : g[v])
    {
        if (visit[u] == 2)
        {
            dfs(g, u, visit, r, flag);
        }
    }
    visit[v] = 0;
}
int main()
{
    int a, b;
    int n, m, q;
    char t;
    cin >> n >> m >> q;
    vector<set<int>> g(n);
    int u, v;

    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        u--;
        v--;
        g[u].insert(v);
        g[v].insert(u);
    }
    for (int i = 0; i < q; i++)
    {
        cin >> t;
        cin >> a >> b;
        a--;
        b--;
        if (t == '-')
        {
            g[a].erase(b);
            g[b].erase(a);
        }
        if (t == '?')
        {
            int flag = 0;
            vector<int> visited(n, 2);
            dfs(g, a, visited, b, flag);
            if (flag)
            {
                cout << "YES"
                     << "\n";
            }
            else
            {
                cout << "NO"
                     << "\n";
            }
        }
    }
}