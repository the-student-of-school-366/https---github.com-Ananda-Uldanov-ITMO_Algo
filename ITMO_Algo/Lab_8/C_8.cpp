#include <iostream>
#include <vector>
using namespace std;

void dFSearch(int vertex, vector<vector<int>> &adjacencyList, vector<bool> &Visited) {
    Visited[vertex] = true;
    for (int neighbor : adjacencyList[vertex]) {
        if (!Visited[neighbor]) {
            dFSearch(neighbor, adjacencyList, Visited);
        }
    }
}

int main() {
    int N, M; 
    int connect = 0;
    cin >> N >> M;
    vector<vector<int>> adjacencyList;
    vector<bool> Visited;
    adjacencyList.resize(N + 1);
    Visited.resize(N + 1, false);

    for (int i = 0; i < M; i++) {
        int vertex1, vertex2;
        cin >> vertex1 >> vertex2;
        adjacencyList[vertex1].push_back(vertex2);
        adjacencyList[vertex2].push_back(vertex1);
    }


    for (int i = 1; i <= N; i++) {
        if (!Visited[i]) {
            dFSearch(i,adjacencyList, Visited);
            connect++;
        }
    }

    cout << connect;

}