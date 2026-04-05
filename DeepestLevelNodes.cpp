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

    void BFS_DEEPEST_LEVEL(int root){
        vector<int>current_level;
        queue<int>q;

        q.push(root);

        int level = 1;
        vector<pair<int , int>>deepest;
        int max_level = 0;

        while(!q.empty()){
            int size = q.size();
            current_level.clear();

            for(int i = 0; i < size; i++){
                int node = q.front();
                q.pop();
                current_level.push_back(node);

                for(int neigh : adj[node]){
                    q.push(neigh);
                }
            }

            // store all leaf nodes at current level
            for(int node : current_level){
                if(adj[node].size() == 0){
                    if(level > max_level){
                        max_level = level; 
                        deepest.clear();
                        deepest.push_back({node, level});
                    }
                    else if(level == max_level){
                        deepest.push_back({node, level});
                    }
                }
            }

            level++;
        }

        // print all deepest nodes
        for(int i = 0; i < deepest.size(); i++){
            cout << char(deepest[i].first + 'A') << " " << deepest[i].second << endl;
        }
    }

    int getChild(int i){
        return childCount[i];
    }
};

int main(){
    int n; 
    cin >> n;

    bool ischild[26] = {false};
    Graph g(26);

    for(int i = 0; i < n; i++){
        string s1, s2;
        cin >> s1 >> s2;

        int parent = s1[1];
        int child = s2[0];

        int u = parent - 'A';
        int v = child - 'A';

        g.addEdge(u, v);
        ischild[v] = true;
    }

    int root = -1;

    for(int i = 0; i < 26; i++){
        if(!ischild[i] && g.getChild(i) > 0){
            root = i;
            break;
        }
    }

    g.BFS_DEEPEST_LEVEL(root);

    return 0;
}