#include <iostream>
#include <vector>

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
        adj[u].push_back(v); // directed graph
    }

    // DFS to detect cycle
   
    bool dfs(int src, vector<bool>&vis, vector<bool>&recPath){
        vis[src] = true;
        recPath[src] = true;

        for(int neigh : adj[src]){
            if(!vis[neigh]){
                if(dfs(neigh, vis, recPath)){
                    return true;
                }
            }
            else if(recPath[neigh]){
                return true;
            }
        }
        recPath[src] = false;
        return false;
    }


    bool canFinish() {
        vector<bool>vis(V, false);
        vector<bool>recPath(V, false);

        for(int i = 0; i < V; i++){
            if(!vis[i]){
                if(dfs(i, vis, recPath)){
                    return false;
                }
            }
        }



        return true; // no cycle
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    Graph g(n);

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        // u -> v means u is prerequisite of v
        g.addEdge(u, v);
    }

    if(g.canFinish() == true) {
        cout << "Possible to finish all courses\n";
    } else {
        cout << "Not possible (cycle exists)\n";
    }

    return 0;
}