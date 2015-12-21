#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <limits>

using namespace std;

const int INFINITY = numeric_limits<int>::max();

// HELPER FUNCTIONS
void printArrayBool(bool arr[], int length) {
    for (int i=0; i<length; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void printStack(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

class Graph {
    int V;
    vector<int> *adj;
    vector<int> *weights;
    void DFSrec(int s, bool visited[]);
    void topSortUtil(int s, bool visited[], stack<int> &finish);
    int findMinVertex(int dist[], bool known[]);
public:
    Graph(int v);
    ~Graph();
    void addEdge(int u, int v);
    void addWeightedEdge(int u, int v, int weight);
    void DFS(int s);
    void BFS(int s);
    void topSort();
    void dijkstra(int src, int dist[], int parent[]);
    void findPath(int src, int dest, int dist[], int parent[]);
};

Graph::Graph(int v) {
    this->V = v;
    adj = new vector<int>[V];
    weights = new vector<int>[V];

    for (int i=0; i<V; i++) {
        for (int j=0; j<V; j++) {
            weights[i].push_back(INFINITY);
        }
    }
}

Graph::~Graph() {
    delete[] adj;
    delete[] weights;
}

void Graph::addEdge(int u, int v) {
    adj[u].push_back(v);
}

void Graph::addWeightedEdge(int u, int v, int weight) {
    addEdge(u, v);
    weights[u][v] = weight;
}

void Graph::DFSrec(int s, bool visited[]) {
    visited[s] = true;

    for (int i=0; i<adj[s].size(); i++) {
        if (!visited[adj[s][i]]) {
            DFSrec(adj[s][i], visited);
        }
    }
}

void Graph::DFS(int s) {
    bool visited[V];
    for (int i=0; i<V; i++) {
        visited[i] = false;
    }

    DFSrec(s, visited);

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

void Graph::topSortUtil(int s, bool visited[], stack<int> &finish) {
    visited[s] = true;

    for (int i=0; i<adj[s].size(); i++) {
        if (!visited[adj[s][i]]) {
            topSortUtil(adj[s][i], visited, finish);
        }
    }

    finish.push(s);
}

void Graph::topSort() {
    bool visited[V];
    for (int i=0; i<V; i++) {
        visited[i] = false;
    }

    stack<int> finish;

    for (int i=0; i<V; i++) {
        if (!visited[i]) {
            topSortUtil(i, visited, finish);
        }
    }

    printStack(finish);
}

int Graph::findMinVertex(int dist[], bool known[]) {
    int minVertex = 0;
    bool isNotSet = true;

    for (int i=0; i<V; i++) {
        if (!known[i]) {
            if (isNotSet) {
                minVertex = i;
                isNotSet = false;
            } else {
                if (dist[i] < dist[minVertex]) {
                    minVertex = i;
                }
            }
        }
    }

    return minVertex;
}

void Graph::dijkstra(int src, int dist[], int parent[]) {
    bool known[V];
    int knownSize = 0;
    for (int i=0; i<V; i++) {
        known[i] = false;
    }
    known[src] = true;
    knownSize++;

    for (int i=0; i<V; i++) {
        dist[i] = weights[src][i];
        parent[i] = src;
    }

    int minVertex = 0;
    while (knownSize <= V) {
        minVertex = findMinVertex(dist, known);
        known[minVertex] = true;
        knownSize++;

        for (int i=0; i<V; i++) {
            if (!known[i]
                && dist[minVertex] != INFINITY
                && weights[minVertex][i] != INFINITY
                && (dist[minVertex] + weights[minVertex][i]) < dist[i]) {
                dist[i] = dist[minVertex] + weights[minVertex][i];
                parent[i] = minVertex;
            }
        }
    }
}

void Graph::findPath(int src, int dest, int dist[], int parent[]) {
    if (parent[dest] == src && dist[dest] == INFINITY) {
        cout << "unreachable" << endl;
    } else {
        cout << dest << " <-- ";
        int vertex = parent[dest];
        while (vertex != src) {
            cout << vertex << " <-- ";
            vertex = parent[vertex];
        }
        cout << src << endl;
    }
}

int main() {
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(5, 4);
    g.DFS(3);
    g.BFS(3);
    g.topSort();

    Graph g2(4);
    g2.addWeightedEdge(0, 1, 3);
    g2.addWeightedEdge(1, 2, 2);
    g2.addWeightedEdge(2, 3, 2);
    g2.addWeightedEdge(0, 3, 8);
    int dist[4];
    int parent[4];
    g2.dijkstra(0, dist, parent);
    g2.findPath(0, 1, dist, parent);
    g2.findPath(0, 2, dist, parent);
    g2.findPath(0, 3, dist, parent);

    return 0;
}
