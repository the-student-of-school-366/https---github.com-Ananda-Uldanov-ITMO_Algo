#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    vector<int> count(n, 0);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
        count[a - 1]++;
        count[b - 1]++;
    }

    int count_of_vertex = n;

    vector<int> answer;

    while (count_of_vertex > 2)
    {
        for (int i = 0; i < n; i++)
        {
            if (count[i] == 1)
            {
                answer.push_back(graph[i][0] + 1);
                count[graph[i][0]]--;
                count_of_vertex--;
                count[i] = 0;
                for (int j = 0; j < graph[graph[i][0]].size(); j++)
                {
                    if (graph[graph[i][0]][j] == i)
                    {
                        graph[graph[i][0]].erase(graph[graph[i][0]].begin() + j);
                        break;
                    }
                }
                graph[i].clear();
                break;
            }
        }
    }

    for (int i = 0; i < answer.size(); i++)
        cout << answer[i] << ' ';
}
