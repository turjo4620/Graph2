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
    }

    void BFS_LEVEL_ORDER(int root, int k){
        queue<int>q;

        q.push(root);

        int level = 0;

        while(!q.empty()){
            int size = q.size();

            // if wanna print the size of the level, node count per each level
            cout<<size << endl;

            if(level == k){
                for(int i = 0; i < size; i++){
                    cout<<char(q.front() + 'A')<<" ";
                    q.pop();
                }
            }

            
            for(int i = 0; i < size ; i++){
                int node = q.front();
                q.pop();

                for(int neigh : adj[node]){
                    q.push(neigh);
                }
            }
            level++;
            cout<<endl;
        }


    }



};


int main(){

    int n, k;
    cin>>n>>k;

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
        if(!isChild[i]){
            root = i;
            break;
        }
    }

    g.BFS_LEVEL_ORDER(root, k);



    
    return 0;
}