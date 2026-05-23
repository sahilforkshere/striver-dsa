// Topological Sort using BFS (Kahn's Algorithm)
// Time Complexity: O(V + E)
// Space Complexity: O(V + E)
// Note: This implementation assumes that the graph is a Directed Acyclic Graph (DAG). If the graph contains a cycle, the topological sort is not possible.

  
  #include<bits/stdc++.h>
    using namespace std;
    vector<int> topobfs( int start, vector<vector<int>> &adj, vector<int> &vis){
        vector<int> topo;
        int n= adj.size();
        queue<int> q;
        // Step :-1 Calculate in-degrees 
        vector<int> indegree(n,0);
        for(int i=0;i<n;i++){
            for( int x : adj[i]){
                indegree[x]++;
            }
        }
        // Step :-2 Push all nodes with in-degree 0 into the queue
        for (int i = 0; i <n; i++)
        {
            if(indegree[i]==0){
                q.push(i);
            }
        }
        // Step :-3 Process the queue

        while (!q.empty())
        {
            int curr= q.front();
            q.pop();

            for(int x : adj[curr]){
                indegree[x]--;
                // If in-degree becomes 0, add it to the queue
                if(indegree[x]==0){
                    // Step :-4 Add the node to the topological order
                    topo.push_back(x);
                    q.push(x);
                }
            }
        }
        return topo;
        
        
    }
    int main()
    {
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
    return 0;
    }