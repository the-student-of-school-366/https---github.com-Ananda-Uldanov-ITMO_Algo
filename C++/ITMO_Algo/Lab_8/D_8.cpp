#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> g, gr;
vector<char> used;
vector<int> order, component;

void dfs1(int v)
{
    used[v] = true;
    for (size_t i = 0; i < g[v].size(); ++i)
        if (!used[g[v][i]])
            dfs1(g[v][i]);
    order.push_back(v);
}

void dfs2(int v)
{
    used[v] = true;
    component.push_back(v);
    for (size_t i = 0; i < gr[v].size(); ++i)
        if (!used[gr[v][i]])
            dfs2(gr[v][i]);
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int vertex1, vertex2;
        cin >> vertex1 >> vertex2;
        vertex1--;
        vertex2--;
        gr[vertex1].push_back(vertex2);
        gr[vertex2].push_back(vertex1);
    }

    used.assign(n, false);
    for (int i = 0; i < n; ++i)
        if (!used[i])
            dfs1(i);
    used.assign(n, false);
    for (int i = 0; i < n; ++i)
    {
        int v = order[n - 1 - i];
        if (!used[v])
        {
            dfs2(v);
            cout<<component[i] ;
            
        }
    }
}