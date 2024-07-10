#include "blazingio.hpp"
#include <queue>
#include <vector>
using namespace std;

vector<bool> visited;
vector<vector<int>> help;

bool bfs(int s, int f, int *parent, int n)
{

    queue<int> q;
    q.push(s);
    parent[s] = -1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && help[u][i] > 0)
            {
                q.push(i);
                parent[i] = u;
                visited[i] = true;
            }
        }
    }
    return visited[f];
}

int FordFalk(int s, int f, int n)
{
    visited.assign(n, false);
    int parent[n];
    int k;
    int MAX = 0;
    while (bfs(s, f, parent, n))
    {
        visited.assign(n, false);
        int way = 99999999;
        for (int i = f; i != s; i = parent[i])
        {
            k = parent[i];
            way = min(way, help[k][i]);
        }

        for (int i = f; i != s; i = parent[i])
        {
            k = parent[i];
            help[k][i] -= way;
            help[i][k] += way;
        }
        MAX += way;
    }
    return MAX;
}

int main()
{
    int ans;
    int m;
    int n;

    cin >> n;
    cin >> m;

    help.assign(n, vector<int>(m, {}));

    for (int i = 0; i < m; i++)
    {
        int a;
        int b;
        int c;
        cin >> a;
        cin >> b;
        cin >> c;
        help[a - 1][b - 1] = c;
    }
    ans = FordFalk(0, n - 1, n);
    cout << ans;
}