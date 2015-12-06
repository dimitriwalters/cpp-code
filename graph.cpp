#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void printArrayBool(bool arr[], int length) {
    for (int i=0; i<length; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

class Graph {
    int V;
    vector<int> *adj;
    void DFSutil(int s, bool visited[]);
public:
    Graph(int v);
    void addEdge(int u, int v);
    void DFS(int s);
    void BFS(int s);
};

Graph::Graph(int v) {
    this->V = v;
    adj = new vector<int>[V];
}

void Graph::addEdge(int u, int v) {
    adj[u].push_back(v);
}

void Graph::DFSutil(int s, bool visited[]) {
    visited[s] = true;

    for (int i=0; i<adj[s].size(); i++) {
        if (!visited[adj[s][i]]) {
            DFSutil(adj[s][i], visited);
        }
    }
}

void Graph::DFS(int s) {
    bool visited[V];
    for (int i=0; i<V; i++) {
        visited[i] = false;
    }

    DFSutil(s, visited);

    printArrayBool(visited, V);
}

void Graph::BFS(int s) {
    bool visited[V];
    for (int i=0; i<V; i++) {
        visited[i] = false;
    }

    queue<int> next;
    next.push(s);

    int current, maybe;
    while (!next.empty()) {
        current = next.front();
        next.pop();
        visited[current] = true;

        for (int i=0; i<adj[current].size(); i++) {
            maybe = adj[current][i];
            if (!visited[maybe]) {
                next.push(maybe);
            }
        }
    }

    printArrayBool(visited, V);
}

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    g.DFS(3);
    g.BFS(3);

    return 0;
}
