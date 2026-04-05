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


    int shortestPath(int source, int target){

        vector<int>distance(V, -1);
        queue<int>q;


        q.push(source);
        distance[source] = 0;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            if(node == target){
                return distance[node];
            }


            for(int neigh : adj[node]){
                if(distance[neigh] == -1){
                    distance[neigh] = distance[node] + 1;
                    q.push(neigh);
                }
            }
        }
       
        return -1;
    }
   


};


int main(){

    int n;
    cin>>n;

    Graph g(26);

    for(int i = 0; i < n; i++){
    string s1, s2; 
    cin>>s1>>s2;
    
    int parent = s1[1];
    int child = s2[0];

    int u = parent - 'A';
    int v = child - 'A';

    g.addEdge(u, v);

    }

    char source , target;
    cin>>source>>target;

    int s = source - 'A';
    int t = target - 'A';

    int ans = g.shortestPath(s, t);
    cout<<ans<<endl;


    
    return 0;
}