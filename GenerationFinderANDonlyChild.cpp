#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    int V;
    vector<vector<int>> adj;
    vector<int> childCount;

    Graph(int V) {
        this->V = V;
        adj.resize(V);
        childCount.resize(V, 0);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        childCount[u]++;
    }

    void BFS(int root) {
        vector<int> level(V, -1);
        vector<int> parent(V, -1); // store parent of each node
        queue<int> q;
        q.push(root);
        level[root] = 1;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neigh : adj[node]) {
                if (level[neigh] == -1) {
                    level[neigh] = level[node] + 1;
                    parent[neigh] = node; // set parent
                    q.push(neigh);
                }
            }
        }

        // Collect only-children
        vector<int> OnlyChild;
        for (int i = 0; i < V; i++) {
            if (parent[i] != -1 && childCount[parent[i]] == 1) {
                OnlyChild.push_back(i);
            }
        }

        // Output
        if (OnlyChild.size() == 0) {
            cout << "0\n";
        } else {
            cout << OnlyChild.size() << endl;
            for (int node : OnlyChild) {
                cout << char('A' + node) << " " << level[node] << endl;
            }
        }
    }
};

int main() {
    int N;
    cin >> N;

    Graph g(26); // assuming only uppercase letters A-Z
    bool isChild[26] = {false};

    for (int i = 0; i < N; i++) {
        string s1, s2;
        cin >> s1 >> s2;

        char parentChar = s1[1]; // input format [A, B]
        char childChar = s2[0];

        int u = parentChar - 'A';
        int v = childChar - 'A';

        g.addEdge(u, v);
        isChild[v] = true;
    }

    // Find root (King)
    int root = -1;
    for (int i = 0; i < 26; i++) {
        if (!isChild[i] && g.childCount[i] > 0) {
            root = i;
            break;
        }
    }

    g.BFS(root);

    return 0;
}