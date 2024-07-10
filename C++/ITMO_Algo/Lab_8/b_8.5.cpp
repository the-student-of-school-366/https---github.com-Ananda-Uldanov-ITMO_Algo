#include <iostream>
#include <vector>

std::vector<int> visited1;
std::vector<int> visited2;

bool dfs(int i, std::vector<std::vector<int>>& g, int second, std::vector<int>& visited) {
    visited[i] = 1;

    if (i == second) {
        return true;
    }

    for (int j = 0; j < g[i].size(); j++) {
        int v = g[i][j];
        if (visited[v] == 0 && dfs(v, g, second, visited)) {
            return true;
        }
    }

    return false;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, q;
    std::cin >> n >> m >> q;

    std::vector<std::vector<int>> g(n);
    visited1.resize(n, 0);
    visited2.resize(n, 0);

    for (int i = 0; i < m; i++) {
        int v, u;
        std::cin >> v >> u;
        g[v - 1].push_back(u - 1);
    }

    for (int i = 0; i < q; i++) {
        visited1.assign(n, 0);
        visited2.assign(n, 0);

        int first, second;
        std::cin >> first >> second;

        if (dfs(first - 1, g, second - 1, visited1) && dfs(second - 1, g, first - 1, visited2)) {
            std::cout << "YES" << "\n";
        } else {
            std::cout << "NO" << "\n";
        }
    }

    return 0;
}