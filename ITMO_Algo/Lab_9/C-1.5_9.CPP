#include <iostream> 
#include <vector> 
#include <queue> 
using namespace std; 
int Distance(int n, vector<vector<pair<int, int>>>& re, int start, int end) { 
    vector<int> dist(n + 1, INT_MAX); 
    dist[start] = 0; 
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
    pq.push({ 0, start }); 
    while (!pq.empty()) { 
        int node = pq.top().second; 
        int d = pq.top().first; 
        pq.pop(); 
 
        if (node == end) { 
            return dist[node]; 
        } 
        if (d > dist[node]) { 
            continue; 
        } 
        for (auto& edge : re[node]) { 
            int neighbor = edge.first; 
            int weight = edge.second; 
            if (dist[node] + weight < dist[neighbor]) { 
                dist[neighbor] = dist[node] + weight; 
                pq.push({ dist[neighbor], neighbor }); 
            } 
        } 
    } 
    return -1; 
} 
int main() { 
    int n, m; 
    cin >> n;
    cin>>m;
    vector<vector<pair<int, int>>> re(n + 1); 
    int start = 1;
    int end = n; 
    for (int i = 0; i < m; i++) { 
        int u, v, w; 
        cin >> u >> v >> w; 
        re[u].push_back({ v, w });  
    } 
    cout << Distance(n, re, start, end); 

}