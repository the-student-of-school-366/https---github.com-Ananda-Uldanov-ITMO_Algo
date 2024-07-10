#include <iostream> 
#include <vector> 
#include <queue> 
using namespace std; 
 
 
vector<int> bfs(vector<vector<int>>& adj, int start, int N, int K) { 
    vector<int> distance(N, -1); 
    distance[start] = 0; 
    vector<int> visited; 
    queue<int> Q; 
    vector<int> island_count_vec; 
    Q.push(start); 
 
 
    while (!Q.empty()) { 
        int u = Q.front(); 
        Q.pop(); 
        for (int v: adj[u]) { 
            if (distance[v] == -1) { 
                distance[v] = distance[u] + 1; 
                Q.push(v); 
            } 
        } 
    } 
     
     
    for (int i = 0; i < distance.size(); i++){ 
        if (distance[i] == K){ 
            island_count_vec.push_back(i); 
        } 
    } 
    return island_count_vec; 
} 
 
 
int main() { 
    int N, M, K; 
    cin >> N >> M >> K; 
    vector<vector<int>> adj(N); 
    for (int i = 0; i < M; i++) { 
        int vertex1, vertex2; 
        cin >> vertex1 >> vertex2; 
        adj[vertex1 - 1].push_back(vertex2 - 1); 
        adj[vertex2 - 1].push_back(vertex1 - 1); 
    } 
 
    vector<int> ans = bfs(adj, 0, N, K); 
     
     
    if (! ans.empty()) { 
        for (int i = 0; i < ans.size(); i++) { 
            cout << ans[i] + 1 << "\n"; 
        } 
    } 
    else{ 
        cout << "NO"; 
    } 
     
}