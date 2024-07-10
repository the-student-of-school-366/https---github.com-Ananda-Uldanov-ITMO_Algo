#include <iostream>
#include <vector>
using namespace std;

const int M = 999999;
vector<int> graph[M];
int visit[M];
int parent[M];

int find_par(int v)
{
    if (parent[v] == v)
        return v;
    return parent[v] = find_par(parent[v]);
}

void dfs(int v, int p)
{
    visit[v] = true;
    parent[v] = p;
    for (int u : graph[v])
    {
        if (!visit[u])
        {
            dfs(u, v);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    int edges;
    int components;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    for (int i = 1; i < n + 1; i++)
    {
        parent[i] = i;
    }

    components = 0;
    for (int i = 1; i < n + 1; i++)
    {
        if (!visit[i])
        {
            components += 1;
            dfs(i, i);
        }
    }

    if ((components == 1) && (m == n) && (n > 2))
    {
        cout << "ARCHIMEDES";
        return 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j : graph[i])
        {
            int u = find_par(i);
            int v = find_par(j);
            if (u != v)
            {
                parent[u] = v;
            }
        }
    }

    int cycles = 0;
    for (int i = 1; i <= n; i++)
    {
        if (find_par(i) == i)
        {
            edges = 0;
            for (int j : graph[i])
            {
                if (find_par(j) == i)
                {
                    edges += 1;
                }
            }
            if (edges == 2)
            {
                cycles += 1;
            }
        }
    }

    if (cycles >= 3)
    {
        cout << "ARCHIMEDES";
    }
    else
    {
        cout << "EUCLID";
    }
}