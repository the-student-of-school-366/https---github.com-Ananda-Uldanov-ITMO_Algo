
#include <iostream>
#include <vector>
using namespace std;
bool dfs(vector<vector<int>>& graf, int v, vector<int>& visited, int parent) {
    visited[v] = 0;
    for (int u : graf[v]) {
        if (visited[u] == -1) {
            if (dfs(graf, u, visited, v)) {
                return true;
            }
        } else if (u != parent) {
            return true;
        }
    }
    return false;
}

bool cycle(vector<vector<int>>& graf, int n) {
    vector<int> visited(n, -1);
    for (int u = 0; u < n; u++) {
        if (visited[u] == -1) {
            if (dfs(graf, u, visited, -1)) {
                return true;
            }
        }
    }
    return false;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adjacency_list(n);
    for (int i = 0; i < m; i++) {
        int vertex1, vertex2;
        cin >> vertex1 >> vertex2;
        vertex1--;
        vertex2--;
        adjacency_list[vertex1].push_back(vertex2);
        adjacency_list[vertex2].push_back(vertex1);
    }

    if (cycle(adjacency_list, n)==true) {
        cout << "YES";
    } else {
        cout << "NO";
    }

}