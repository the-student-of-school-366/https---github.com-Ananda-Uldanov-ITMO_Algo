#include <iostream>
#include <vector>

#include <list>

using namespace std;

void dfs(int v, vector<bool> &vis, vector<list<int>> &graph)
{
    vis[v] = true;
    for (int i : graph[v])
    {
        if (!vis[i])
        {
            dfs(i, vis, graph);
        }
    }
}

bool exist(vector<list<int>> &graph, vector<int> degrees)
{
    int n;
    n = graph.size();
    for (int i = 0; i < n; i++)
    {
        if (degrees[i] % 2 != 0)
        {
            return false;
        }
    }

    vector<bool> vis(n, false);
    dfs(0, vis, graph);
    for (int i = 0; i < n; i++)
    {
        if (!vis[i] and graph[i].size() > 0)
        {
            return false;
        }
    }

    return true;
}

void remove(list<int> &a, int b)
{
    for (auto j = a.begin(); j != a.end(); j++)
    {
        if (*j == b)
        {
            a.erase(j);
            break;
        }
    }
}

void euler(int v, vector<list<int>> &graph, vector<int> &res)
{
    while (!graph[v].empty())
    {
        int w = *graph[v].begin();
        graph[v].pop_front();
        remove(graph[w], v);
        euler(w, graph, res);
    }
    res.push_back(v);
}

int main()
{
    int n, m;
    cin >> n;
    cin >> m;
    vector<list<int>> graph(n);
    vector<int> degrees(n, 0);

    int v1;
    int v2;
    for (int i = 0; i < m; i++)
    {
        cin >> v1;
        cin >> v2;
        v1--;
        v2--;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
        degrees[v1]+=1;
        degrees[v2]+=1;
    }

    if (!exist(graph, degrees))
    {
        cout << ":(";
    }

        vector<int> res;
        euler(0, graph, res);
        reverse(res.begin(), res.end());
        for (int v : res)
        {
            cout << v+1 << " ";
        }
}