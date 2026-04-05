#include <bits/stdc++.h>

using namespace std;

class Graph{
    int V;
    vector<vector<int>>adj;
    vector<int>childCount;

public:
    Graph(int V){
        this->V = V;
        adj.resize(V);
        childCount.resize(V, 0);
    }

    void addEdge(int u, int v){
        adj[u].push_back(v);
        childCount[u]++;
    }


    void BFS(int root){
        vector<int>level(V, -1);
        vector<int>parent(V, -1);
        queue<int>q;

        q.push(root);
        level[root] = 1;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int neigh : adj[node]){
                if(level[neigh] == -1){
                    level[neigh] = level[node] + 1;
                    parent[neigh] = node;
                    q.push(neigh);
                }
            }
        }

        vector<int>OnlyChild;

        for(int i = 0; i < V; i++){
            if(parent[i] != -1 && childCount[parent[i]] == 1){
                OnlyChild.push_back(i);
            }
        }

        for(int node : OnlyChild){
            cout<<char(node + 'A')<<" "<<level[node]<<endl;
        }
    }

    int getChildCount(int i){
        return childCount[i];
    }
};


int main(){
    int V;
    cin>>V; 
    Graph g(26);
    string s1, s2;
    bool isChild[26] = {false};

    for(int i = 0; i < V; i++){
        cin>>s1>>s2;

        int parent = s1[1];
        int child = s2[0];

        int u = parent - 'A';
        int v = child - 'A';

        g.addEdge(u,v);
        isChild[v] = true;
    }

    int root = -1;
    for(int i = 0; i < 26; i++){
        if(!isChild[i] && g.getChildCount(i) > 0){
            root = i;
        }
    }

    g.BFS(root);
    return 0;
}