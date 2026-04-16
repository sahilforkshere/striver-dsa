// Topological Sort using DFS
// Time Complexity: O(V + E)
// Space Complexity: O(V + E)
// Note: This implementation assumes that the graph is a Directed Acyclic Graph (DAG). If the graph contains a cycle, the topological sort is not possible.

#include <bits/stdc++.h>
using namespace std;

void topoSortDFS(int node, vector<vector<int>> &adj,vector<bool> &vis,stack<int>&st){
    vis[node]=true;
    for(int x : adj[node]){
        if(!vis[x]){
            topoSortDFS(x,adj,vis,st);
        }
    }
    st.push(node);

}

int main() {

    int n = 6;
    vector<bool> vis(n,false);
    stack<int> st;

   
    vector<vector<int>> adj(n);

    // Add edges (0-based graph)
    adj[0].push_back(3);
    adj[0].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(1);
    adj[2].push_back(1);
    adj[1].push_back(4);
    adj[5].push_back(1);
    adj[5].push_back(4);

    // Print graph    cout << "Graph representation (Adjacency List):" << endl;

    for (int i = 0; i < n; i++) {
        cout << i << " -> ";

        for (auto neighbor : adj[i]) {
            cout << neighbor << " ";
        }

        cout << endl;
    }

    for(int i=0;i<n;i++){
        if(!vis[i]){
            topoSortDFS(i,adj,vis,st);
        }
    }

    // Print topological order
    cout << "Topological Order:" << endl;
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}