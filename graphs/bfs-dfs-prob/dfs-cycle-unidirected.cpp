#include <bits/stdc++.h>
using namespace std;


class Solution {
public:

    bool iscycledfs(vector<vector<int>> &adj,
                    int start,
                    vector<bool> &vis,
                    int parent)
    {
        vis[start] = true;

        for (int x : adj[start])
        {
            // Ignore the parent
            if (x == parent)
                continue;

            // If visited and not parent → cycle
            if (vis[x] && x != parent)
                return true;

            // If not visited → DFS
            if (!vis[x])
            {
                if (iscycledfs(adj, x, vis, start)) // recursive call with current node as parent
                    return true;
            }
        }

        return false;   // ❗ must return false if no cycle found
    }

    bool isCycle(int V, vector<vector<int>>& edges)
    {
        vector<vector<int>> adj(V);

        // Build adjacency list
        for (auto v : edges)
        {
            int u = v[0];
            int w = v[1];

            adj[u].push_back(w);
            adj[w].push_back(u);
        }

        vector<bool> vis(V, false);

        // Check all components
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (iscycledfs(adj, i, vis, -1))
                    return true;
            }
        }

        return false;
    }
};