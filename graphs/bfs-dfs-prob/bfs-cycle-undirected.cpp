class Solution
{
    public: 
     bool iscyclebfs (vector<vector<int>> &adj, int start, vector<bool> &vis){
        queue<pair<int,int>> q; // queue to store curr and its parent
        q.push({start,-1}); // start with parent as -1
         vis[start]=true; // mark the start node as visited

         while (!q.empty())
         {
            auto [curr,par]=q.front(); // pop the first nod ewhose parent is -1
            q.pop(); // pop the first node
            for( auto it : adj[curr]){  // traverse the adjacent nodes of curr
                if(it==par) continue; // ignore the parent

                if( vis[it] && it!=par)
                    return true; // if visited and not parent → cycle
                if(!vis[it]){
                    vis[it]=true;
                    q.push({it,curr});
                }

            }
         }
            return false; // ❗ must return false if no cycle found

         
         

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
                if (iscyclebfs(adj, i, vis))
                    return true;
            }
        }

        return false;
    }
};