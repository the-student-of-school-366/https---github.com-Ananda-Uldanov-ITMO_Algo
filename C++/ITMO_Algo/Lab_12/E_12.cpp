#include "blazingio.hpp"
#include <vector>
#include <cmath>
using namespace std;
int has(int k, int n)
{
    return (k + 1000000)*109  % (3*n);
}

int fact(int y)
{
    int tmp = 1;
    for (int i = y; i >= 1; i--)
    {
        tmp = tmp * i;
    }
    return tmp;
}

int main()
{
    int n;
    cin >> n;
    int res;
    res = 0;
    vector<vector<int>> plenty(3 * n);
    vector<int> chair;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        chair.push_back(x);
    }

    for (int i = 0; i < n; i++)
    {
        plenty[has(chair[i] - i, n)].push_back(chair[i]);
    }

    for (int i = 0; i < plenty.size(); i++)
    {
        int a;
        int b;
        a = plenty[i].size();
        b = abs(a - 2);
        res += fact(a) / (2 * fact(b));
    }

    cout << res;
}