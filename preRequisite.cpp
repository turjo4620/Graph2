/*
    CSE 106
    Online on Graphs (A1/A2)

    Problem Statement:
    There are N courses numbered from 1 to N. Some courses have prerequisite requirements,
    meaning you must complete certain courses before enrolling in them. These prerequisites are
    represented as directed edges, where an edge from course A to course B indicates that course
    A must be completed before course B.

    You will receive multiple queries. Each query provides a specific course, and your task is to
    determine the number of prerequisite courses that must be completed before enrolling in that
    course.

    Input:
    - The first line contains two integers N and M, the number of courses and the number of
      prerequisite relationships.
    - The next M lines each contain two integers A and B, meaning that course A is a
      prerequisite for course B.
    - The following line contains an integer Q, the number of queries.
    - The next Q lines each contain a single integer C, representing a course for which you
      need to determine the prerequisite count.

    Output:
    For each query, print a single integer, representing the number of prerequisite courses required
    for the given course.
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int> > adj(n + 1);
    vector<int> indegree(n + 1, 0);

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        indegree[v]++;
    }

    // queue for Kahn's Algorithm
    queue<int> q;

    for(int i = 1; i <= n; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }

    // store prerequisite count
    vector<int> prereq(n + 1, 0);

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        for(int i = 0; i < adj[node].size(); i++) {
            int neigh = adj[node][i];

            // update prerequisite count
            prereq[neigh] += prereq[node] + 1;

            indegree[neigh]--;

            if(indegree[neigh] == 0) {
                q.push(neigh);
            }
        }
    }

    int qn;
    cin >> qn;

    while(qn--) {
        int course;
        cin >> course;

        cout << prereq[course] << "\n";
    }

    return 0;
}