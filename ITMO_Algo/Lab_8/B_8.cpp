#include <iostream>
#include <vector>
using namespace std;

vector<int> visited1;
vector<int> visited2;

bool dfs(int i, vector<vector<int>> &graf, int second, vector<int> &visited)
{
    visited[i] = 1;

    if (i == second)
    {
        return true;
    }

    for (int j = 0; j < graf[i].size(); j++)
    {
        int v = graf[i][j];
        if (visited[v] == 0 && dfs(v, graf, second, visited))
        {
            return true;
        }
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> out;
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> graf(n);
    visited1.resize(n, 0);
    visited2.resize(n, 0);

    for (int i = 0; i < m; i++)
    {
        int v, u;
        cin >> v >> u;
        graf[v - 1].push_back(u - 1);
    }

    for (int i = 0; i < q; i++)
    {
        visited1.assign(n, 0);
        visited2.assign(n, 0);

        int first, second;
        cin >> first >> second;

        if (dfs(first - 1, graf, second - 1, visited1) && dfs(second - 1, graf, first - 1, visited2))
        {
            out.push_back(1);
        }
        else
        {
            out.push_back(0);
        }
    }
    for (int i = 0; i < out.size(); i++)
    {
        if (out[i] == 1)
            cout << "YES"
                 << "\n";
        else
            cout << "NO"
                 << "\n";
    }
}