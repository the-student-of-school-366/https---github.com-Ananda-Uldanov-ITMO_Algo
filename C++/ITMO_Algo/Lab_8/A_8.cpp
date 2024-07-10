#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> topologicalSort(vector<vector<int>> &graf, vector<int> &indeed)
{
    int n = graf.size();
    vector<int> order;
    queue<int> q;

    for (int i = 0; i < n; i++)
    {
        if (indeed[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        order.push_back(u);

        for (int v : graf[u])
        {
            indeed[v]--;
            if (indeed[v] == 0)
            {
                q.push(v);
            }
        }
    }

    return order;
}

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> titles(N);
    vector<int> indeed(N, 0);
    vector<vector<int>> graf(N);
    int v, u;
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v;
        u--;
        v--;
        indeed[v] += 1;
        graf[u].push_back(v);
    }

    vector<int> order = topologicalSort(graf, indeed);


    for (int i = 0; i < N; i++)
    {
        titles[order[i]] = i + 1;
    }

    for (int i = 0; i < N; i++)
    {
        cout << titles[i] << " ";
    }
}