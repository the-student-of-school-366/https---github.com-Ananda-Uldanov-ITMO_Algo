
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
void Paint(stack<int> &st, int v, int &M_color, vector<int> &black)
{
    M_color += 1;
    int last = -1;
    while (last != v && !st.empty())
    {
        black[st.top()] = M_color;
        last = st.top();
        st.pop();
    }
}

void DFS(vector<vector<int>> &graph, vector<bool> &visit, stack<int> &st, int v, int &M_color, vector<int> &black, vector<int> &tin, vector<int> &up, int &time, int mama)
{
    visit[v] = true;
    time += 1;
    st.push(v);
    tin[v] = time;
    up[v] = time;
    for (int u : graph[v])
    {
        if (!visit[u])
        {
            DFS(graph, visit, st, u, M_color, black, tin, up, time, v);
            up[v] = min(up[v], up[u]);
            if (up[u] > tin[v])
            {
                Paint(st, u, M_color, black);
            }
        }
        else if (u != mama and tin[u] < tin[v])
        {
            up[v] = min(up[v], tin[u]);
        }
    }
}

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    int m;
    int q;
    cin >> n;
    cin >> m;
    cin >> q;

    vector<vector<int>> graph(n + 1);

    for (int i = 0; i < m; i++)
    {
        int a;
        int b;
        cin >> a;
        cin >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<bool> visit(n + 1, false);
    int time = 0;
    stack<int> st;
    vector<int> up(n + 1, 0);
    vector<int> black(n + 1, 0);
    vector<int> tin(n + 1, 0);
    int M_color = 0;

    for (int i = 0; i < n + 1; i++)
    {
        if (!visit[i])
        {
            visit[i] = true;
            DFS(graph, visit, st, i, M_color, black, tin, up, time, -1);
        }
    }

    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a;
        cin >> b;
        if (black[a] == black[b])
        {
            cout << "YES" << '\n';
        }
        else
        {
            cout << "NO" << '\n';
        }
    }
}