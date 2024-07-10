#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long valet;

struct edge
{
    long long start, finish, price;
};

vector<long long> mama;

long long find_s(long long v)
{
    if (v == mama[v])
        return v;
    return mama[v] = find_s(mama[v]);
}

void un_set(long long a, long long b)
{
    a = find_s(a);
    b = find_s(b);
    if (a != b)
        mama[b] = a;
}

bool comp_edg(const edge &a, const edge &b)
{
    return (a.price < b.price);
}

long long krusk(const vector<edge> &edges, long long n)
{
    mama.resize(n);
    for (long long i = 0; i < n; ++i)
        mama[i] = i;

    vector<edge> result;
    long long c = 0;
    for (const edge &e : edges)
    {
        if (find_s(e.start) != find_s(e.finish))
        {
            valet += e.price;
            result.push_back(e);
            un_set(e.start, e.finish);
            c++;
        }
        if (c == n - 1)
        {
            break;
        }
    }
    if (valet < 0)
    {
        return 0;
    }
    return valet;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    long long  k;
    long long n;
    long long  m;
    valet=0;
    cin >> n; 
    cin >> m;
    cin >> k;
    vector<edge> edges(m + k);
    for (long long i = 0; i < m; i++)
    {
        cin >> edges[i].start >> edges[i].finish >> edges[i].price;
        edges[i].start--;
        edges[i].finish--;
        valet -= edges[i].price;
    }
    for (long long i = m; i < m + k; i++)
    {
        cin >> edges[i].start >> edges[i].finish >> edges[i].price;
        edges[i].start--;
        edges[i].finish--;
    }

    sort(edges.begin(), edges.end(), comp_edg);
    long long M_length = krusk(edges, n);
    cout << M_length;
}