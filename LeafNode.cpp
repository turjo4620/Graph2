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
        childCount.resize(V);
    }

    void addEdge(int u, int v){
        adj[u].push_back(v);
        childCount[u]++;
    }

    int BFS_leaf_finder(int root){
        vector<int>parent(V, -1);
        vector<int>level(V, -1);
        vector<int>leafNode;
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

        for(int i = 0; i < V; i++){
            if(childCount[i] == 0 && level[i] != -1){
                leafNode.push_back(i);
            }
        }

        for(int n : leafNode){
            cout<<"leaf node : " << char('A' + n) << " : "<< level[n] <<endl;
        }

    }

    int getChild(int i){
        return childCount[i];
    }


};


int main(){

    int n;
    cin>>n;

    Graph g(26);
    bool isChild[26] = {false};

    for(int i = 0; i < n; i++){
    string s1, s2; 
    cin>>s1>>s2;
    
    int parent = s1[1];
    int child = s2[0];

    int u = parent - 'A';
    int v = child - 'A';

    g.addEdge(u, v);

    isChild[v] = true;
    }

    int root = -1;

    for(int i = 0; i < 26; i++){
        if(!isChild[i] && g.getChild(i) > 0){
            root = i;
            break;
        }
    }

    g.BFS_leaf_finder(root);
    
    return 0;
}