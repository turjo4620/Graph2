#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    // 1. Cycle Detection (Same as your logic)
    bool isCycle(int curr, vector<bool>& vis, vector<bool>& recPath, vector<vector<int>>& prerequisites) {
        vis[curr] = true;
        recPath[curr] = true;

        for (int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][1]; // src (prerequisite)
            int v = prerequisites[i][0]; // dest (course)

            if (u == curr) {
                if (!vis[v]) {
                    if (isCycle(v, vis, recPath, prerequisites)) {
                        return true;
                    }
                } else if (recPath[v]) {
                    return true;
                }
            }
        }

        recPath[curr] = false;
        return false;
    }

    // 2. Topological Sort (New function needed for the solution)
    void topoSort(int curr, vector<bool>& vis, stack<int>& st, vector<vector<int>>& prerequisites) {
        vis[curr] = true;

        for (int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];

            if (u == curr) {
                if (!vis[v]) {
                    topoSort(v, vis, st, prerequisites);
                }
            }
        }
        // Push current node to stack after visiting all neighbors
        st.push(curr);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // Step 1: Detect Cycle
        vector<bool> vis(numCourses, false);
        vector<bool> recPath(numCourses, false);

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (isCycle(i, vis, recPath, prerequisites)) {
                    return {}; // Return empty if cycle exists
                }
            }
        }

        // Step 2: Perform Topological Sort if no cycle
        stack<int> st;
        fill(vis.begin(), vis.end(), false); // Reset visited array

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                topoSort(i, vis, st, prerequisites);
            }
        }

        // Step 3: Extract result from Stack
        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};


int main(){
    
    return 0;
}