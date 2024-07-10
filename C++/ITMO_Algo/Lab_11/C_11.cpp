#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> g;
vector<int> mt;
vector<bool> used;

bool try_kuhn(int v) {
    if (used[v])
        return false;
    used[v] = true;
    for (size_t i = 0; i < g[v].size(); ++i) {
        int to = g[v][i];
        if (mt[to] == -1 || try_kuhn(mt[to])) {
            mt[to] = v;
            return true;
        }
    }
    return false;
}

int main() {
    int m;
    cin >> n >> m;

    g.resize(n);
    mt.assign(n, -1);
    used.assign(n, false);

    for (int i = 0; i < m; i++) {
        int a, b,c;
        cin >> a >> b>>c;
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }

    for (int v = 0; v < n; ++v) {
        fill(used.begin(), used.end(), false);
        try_kuhn(v);
    }

    for (int i = 0; i < n; ++i)
        if (mt[i] != -1)
            cout << mt[i] + 1 << " " << i + 1 << "\n";

    return 0;
}
