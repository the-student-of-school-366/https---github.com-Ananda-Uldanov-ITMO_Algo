#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int main()
{

    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n, vector<int>(n));
    vector<int> deg(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            graph[i][j] = 0;
            graph[j][i] = 0;
        }
    }
    for (int i = 0; i < m; i++)
    {
        int a;
        int b;
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
        deg[a-1] += 1;
        deg[b-1] += 1;
    }
    
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            deg[i] += graph[i][j];

    int first = 0;
    while (!deg[first])
        ++first;

    bool bad = false;
    for (int i = 0; i < n; ++i)
        if (deg[i] & 1)
            bad = true;

    stack<int> st;
    st.push(first);
    vector<int> res;
    while (!st.empty())
    {
        int v = st.top();
        int i;
        for (i = 0; i < n; ++i)
            if (graph[v][i])
                break;
        if (i == n)
        {
            res.push_back(v);
            st.pop();
        }
        else
        {
            --graph[v][i];
            --graph[i][v];

            st.push(i);
        }
    }

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (graph[i][j])
                bad = true;

    if (bad)
        puts(":(");
    else
        for (size_t i = 0; i < res.size(); ++i)
            cout << res[i] + 1 << " ";
}