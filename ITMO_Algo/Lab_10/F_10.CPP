#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int *p;
int *r;

void init(int n)
{
    for (int i = 0; i < n + 1; i++)
    {
        p[i] = i;
        r[i] = 0;
    }
}

int get(int x)
{
    if (x == p[x])
        return x;
    return (p[x] = get(p[x]));
}

void join(int x, int y)
{
    x = get(x);
    y = get(y);
    if (x != y)
    {
        if (r[x] > r[y])
        {
            swap(x, y);
        }
        r[x] += r[y];
        p[x] = y;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    int m;
    long long min1 = 100000;
    long long min2 = 100000;
    long long res;
    res = 0;

    cin >> n >> m;
    p = new int[n + 1];
    r = new int[n + 1];
    init(n);

    vector<vector<int>> graph;

    for (int i = 0; i < m; i++)
    {
        int a;
        int b;
        int c;
        cin >> a >> b >> c;
        vector<int> tmp;
        tmp.push_back(a);
        tmp.push_back(b);
        tmp.push_back(c);
        graph.push_back(tmp);
    }
    for (int p = 0; p < n; p++)
    {
        for (int q = 0; q < n; q++)
        {
            if (graph[p][q])
            {
                graph[p][q]--;
                res = 0;
                for (int i = 1; i < n; i++)
                {
                    for (int j = i; j > 0 && graph[j - 1][2] > graph[j][2]; j--)
                    {
                        swap(graph[j - 1], graph[j]);
                    }
                }

                for (auto i : graph)
                {
                    if (get(i[0]) != get(i[1]))
                    {
                        join(i[0], i[1]);
                        res += i[2];
                    }
                }
            }
            graph[p][q]++;
            if (res < min1 && res>0)
                min1 = res;
        }
    }

    cout << min1;

    delete[] p;
    delete[] r;
}
