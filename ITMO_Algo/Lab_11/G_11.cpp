#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int N;
    int M;
    cin >> N >> M;

    vector<vector<int>> graph(N);

    for (int i = 0; i < M; i++)
    {
        int a;
        int b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a); 
    }


    vector<int> cycle;
    vector<bool> visit(N, false);
    queue<int> q;

    q.push(0);
    visit[0] = true;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        cycle.push_back(cur);

        
        for (int i : graph[cur])
        {
            if (visit[i]==false)
            {
                visit[i] = true;
                q.push(i);
            }
        }
    }


    for (int i=0;i<cycle.size();i++)
    {
        cout << cycle[i] << " ";
    }
}
