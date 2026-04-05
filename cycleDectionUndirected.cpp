#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    vector<vector<int> > adj;

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // undirected
    }

    bool bfs(int start, vector<bool> &visited) {
        queue<pair<int, int> > q;

        q.push(make_pair(start, -1));
        visited[start] = true;

        while(!q.empty()) {
            pair<int, int> frontNode = q.front();
            q.pop();

            int node = frontNode.first;
            int parent = frontNode.second;

            for(int i = 0; i < adj[node].size(); i++) {
                int neigh = adj[node][i];

                if(visited[neigh] == false) {
                    visited[neigh] = true;
                    q.push(make_pair(neigh, node));
                }
                else if(neigh != parent) {
                    return true; // cycle found
                }
            }
        }

        return false;
    }

    bool hasCycle() {
        vector<bool> visited(V, false);

        for(int i = 0; i < V; i++) {
            if(visited[i] == false) {
                if(bfs(i, visited) == true) {
                    return true;
                }
            }
        }

        return false;
    }
};

int main() {
    int V, E;
    cin >> V >> E;

    Graph g(V);

    for(int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    if(g.hasCycle() == true) {
        cout << "Cycle Detected\n";
    } else {
        cout << "No Cycle\n";
    }

    return 0;
}