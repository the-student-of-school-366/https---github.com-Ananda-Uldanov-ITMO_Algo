#include <iostream> 
#include <vector> 
#include <queue> 
using namespace std; 
 
 
vector<int> bfs(vector<vector<int>>& adjacency_list, int start, int N, int K) { 
    vector<int> distance(N, -1); 
    distance[start] = 0; 
    vector<int> visited; 
    queue<int> que; 
    vector<int> island_count_vec; 
    que.push(start); 
 
 
    while (!que.empty()) { 
        int u = que.front(); 
        que.pop(); 
        for (int v: adjacency_list[u]) { 
            if (distance[v] == -1) { 
                distance[v] = distance[u] + 1;
                que.push(v); 
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
    vector<vector<int>> adjacency_list(N); 
    for (int i = 0; i < M; i++) {
        int vertex1, vertex2;
        cin >> vertex1 >> vertex2;
        vertex1--;
        vertex2--;
        adjacency_list[vertex1].push_back(vertex2);
        adjacency_list[vertex2].push_back(vertex1);
    } 
 
    vector<int> ans = bfs(adjacency_list, 0, N, K); 
     
     
    if (! ans.empty()) { 
        for (int i = 0; i < ans.size(); i++) {
            ans[i]++;
            cout << ans[i] << "\n"; 
        } 
    } 
    else{ 
        cout << "NO"<< "\n"; 
    } 
     
}