#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
    int V;
    vector<int> *adj;
    vector<bool> DFSutil(int s, vector<bool> visited);
public:
    Graph(int v);
    void addEdge(int u, int v);
    vector<bool> DFS(int s);
    vector<bool> BFS(int s);
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

    for (int i=0; i<adj[s].size(); i++) {
        if (!visited[adj[s][i]]) {
            visited = DFSutil(adj[s][i], visited);
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

vector<bool> Graph::BFS(int s) {
    vector<bool> visited(V);
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

    return visited;
}

void printVectorBool(vector<bool> v) {
    for (int i=0; i<v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    vector<bool> results = g.DFS(3);
    printVectorBool(results);

    vector<bool> results2 = g.BFS(3);
    printVectorBool(results2);

    return 0;
}
