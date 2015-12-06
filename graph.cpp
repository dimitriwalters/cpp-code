#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

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
    void DFSutil(int s, bool visited[]);
    void topSortUtil(int s, bool visited[], stack<int> &finish);
public:
    Graph(int v);
    void addEdge(int u, int v);
    void DFS(int s);
    void BFS(int s);
    void topSort();
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

    return 0;
}
