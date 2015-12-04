#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class Graph {
    int V;
    vector<int> *adj;
    vector<bool> DFSutil(int s, vector<bool> visited);
public:
    Graph(int v);
    void addEdge(int u, int v);
    vector<bool> DFS(int s);
};

Graph::Graph(int v) {
    this->V = v;
    adj = new vector<int>[V];
}

void Graph::addEdge(int u, int v) {
    adj[u].push_back(v);
}

vector<bool> Graph::DFSutil(int s, vector<bool> visited) {
    visited[s] = true;
    vector<int> neighbours = adj[s];

    for (int i=0; i<neighbours.size(); i++) {
        if (!visited[neighbours[i]]) {
            visited = DFSutil(neighbours[i], visited);
        }
    }

    return visited;
}

vector<bool> Graph::DFS(int s) {
    vector<bool> visited(V);

    for (int i=0; i<visited.size(); i++) {
        visited[i] = false;
    }

    return DFSutil(s, visited);
}

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    vector<bool> results = g.DFS(2);
    for (int i=0; i<results.size(); i++) {
        cout << results[i] << " ";
    }
    cout << endl;

    return 0;
}
