#include <iostream>
#include <vector>
using namespace std;



void init(long long n,long long *p, long long *r )
{
    for (long long i = 0; i < n + 1; i++)
    {
        p[i] = i;
        r[i] = 0;
    }
}

long long get(long long x, long long *p, long long *r)
{
    if (x == p[x])
        return x;
    return (p[x] = get(p[x], p, r));
}

void join(long long x, long long y, long long *p,long long *r)
{
    x = get(x, p, r);
    y = get(y, p, r);
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
    long long n;
    long long m;
    long long k;
    long long dif = 0;
    long long counter = 0;
    long long res;
    res = 0;

    cin >> n >> m >> k;
    long long *p = new long long[n + 1];
    long long *r = new long long[n + 1];
    init(n,  p, r);

    vector<vector<long long>> MST;
    vector<vector<long long>> money;
    vector<vector<long long>> spend;

    for (long long i = 0; i < m; i++)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        money.push_back({a, b, c});
        MST.push_back({a, b, c});
        dif += c;
    }

    for (long long i = 0; i < k; i++)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        spend.push_back({a, b, c});
        MST.push_back({a, b, c});
    }

    for (long long i = 0; i < n; i++)
    {
        for (long long j = i; j > 0 && MST[j - 1][2] > MST[j][2]; j--)
        {
            swap(MST[j - 1], MST[j]);
        }
    }

    for (auto i : MST)
    {
        if (get(i[0], p, r) != get(i[1], p, r))
        {
            join(i[0], i[1],p, r);
            res += i[2];
        }
    }
    if ((dif - res) >= 0)
        cout << 0;
    else
    {
        long long ans = res - dif;
        cout << ans;
    }
    return 0;
}
