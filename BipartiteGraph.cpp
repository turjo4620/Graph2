#include <bits/stdc++.h>

using namespace std;


class Graph{
    int V;
    vector<vector<int>>adj;

public:
    Graph(int V){
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    bool bfs_bipartite_checker(int root, vector<int>&color){
        queue<int>q;

        q.push(root);
        color[root] = 0;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int neighbour : adj[node]){
                if(color[neighbour] == -1){
                    color[neighbour] = 1 - color[node];
                    q.push(neighbour);
                }
                else if(color[neighbour] == color[node]){
                    return false;
                }
            }
        }

        return true;


    }

};


int main(){
    int V, E;
    cin>>V>>E;
    bool ischild[26];
    Graph g(V);

    for(int i = 0; i < E; i++){
        int a , b;
        cin>>a>>b;
        g.addEdge(a, b);
        ischild[b] = true;
    }

    vector<int>color(V, -1);

    for(int i = 0; i < V; i++){
        if(color[i] == -1){
            if(!g.bfs_bipartite_checker(i, color)){
                cout<<false;
                return 0;
            }
        }
    }
    cout<<true;
    
    return 0;
}