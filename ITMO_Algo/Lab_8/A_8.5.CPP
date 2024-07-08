#include <iostream>
#include <queue>
using namespace std;
void dfs(vector<vector<int>> &g, vector<int> &visited, int v, queue<int> &q)
{
    visited[v] = 1;
    q.push(v);
    cout<<q.front();
    for (int to : g[v])
        if (!visited[to])
            dfs(g, visited, to, q);
}
int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> g(N);
    vector<int> visited(N);
    queue<int> q;
    for (int i = 0; i < M; M++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
    }
    for (int i = 0; i < M; i++)
    {
        if (!visited[i])
            dfs(g, visited, i, q);
    }
    for (int i = 0; i < q.size(); i++)
    {
        cout<<q.front();
        q.pop();
    }

}
