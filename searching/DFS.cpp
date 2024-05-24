#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Graph {
    int V;
    list<int> *adj;

    void DFSUtil(int v, vector<bool> &visited) {
        visited[v] = true;
        cout << v << " ";
        for (auto i = adj[v].begin(); i != adj[v].end(); ++i) {
            if (!visited[*i]) {
                DFSUtil(*i, visited);
            }
        }
    }

public:
    Graph(int V);
    void addEdge(int v, int w);
    void DFS(int v);
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}

void Graph::DFS(int v) {
    vector<bool> visited(V, false);
    DFSUtil(v, visited);
}

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Depth First Traversal starting from vertex 2:" << endl;
    g.DFS(2);

    return 0;
}
