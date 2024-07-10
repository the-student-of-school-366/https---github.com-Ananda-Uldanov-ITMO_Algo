#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1000000;
int n, m;
vector<int> graph[MAXN];
int parent[MAXN], degree[MAXN];

void dfs(int v)
{
    for (size_t i = 0; i < graph[v].size(); ++i)
    {
        int to = graph[v][i];
        if (to != parent[v])
        {
            parent[to] = v;
            dfs(to);
        }
    }
}

vector<int> prufer_code()
{
    parent[n - 1] = -1;
    dfs(n - 1);

    int ptr = -1;
    for (int i = 0; i < n; ++i)
    {
        degree[i] = (int)graph[i].size();
        if (degree[i] == 1 && ptr == -1)
            ptr = i;
    }

    vector<int> result;
    int leaf = ptr;
    for (int iter = 0; iter < n - 2; ++iter)
    {
        int next = parent[leaf];
        result.push_back(next);
        --degree[next];
        if (degree[next] == 1 && next < ptr)
            leaf = next;
        else
        {
            ++ptr;
            while (ptr < n && degree[ptr] != 1)
                ++ptr;
            leaf = ptr;
        }
    }
    return result;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int> result;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
    }
    result = prufer_code();
    for (int i = 0; i < result.size(); ++i)
    {

        cout << result[i] +1 << " "; 

    }
}
