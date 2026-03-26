#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    int n;
    bool directed;

    // Unweighted adjacency list
    vector<vector<int>> adj;

    // Weighted adjacency list
    vector<vector<pair<int,int>>> adjW;

    // Constructor
    Graph(int nodes, bool isDirected=false) {
        n = nodes;
        directed = isDirected;

        adj.resize(n + 1);
        adjW.resize(n + 1);
    }

    // -----------------------------
    // ADD EDGE (UNWEIGHTED)
    // -----------------------------
    void addEdge(int u, int v) {
        adj[u].push_back(v);

        if (!directed)
            adj[v].push_back(u);
    }

    // -----------------------------
    // ADD EDGE (WEIGHTED)
    // -----------------------------
    void addWeightedEdge(int u, int v, int w) {
        adjW[u].push_back({v, w});

        if (!directed)
            adjW[v].push_back({u, w});
    }

    // -----------------------------
    // PRINT GRAPH
    // -----------------------------
    void printGraph() {
        for (int i = 1; i <= n; i++) {
            cout << i << " -> ";
            for (auto v : adj[i]) {
                cout << v << " ";
            }
            cout << endl;
        }
    }

    // -----------------------------
    // BFS
    // -----------------------------
    vector<int> BFS(int start) {

        vector<int> vis(n + 1, 0);
        queue<int> q;
        vector<int> result;

        vis[start] = 1;
        q.push(start);

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            result.push_back(node);

            for (auto it : adj[node]) {

                if (!vis[it]) {

                    vis[it] = 1;
                    q.push(it);
                }
            }
        }

        return result;
    }

    // -----------------------------
    // DFS (Helper)
    // -----------------------------
    void DFSUtil(int node,
                 vector<int> &vis,
                 vector<int> &result) {

        vis[node] = 1;
        result.push_back(node);

        for (auto it : adj[node]) {

            if (!vis[it]) {

                DFSUtil(it, vis, result);
            }
        }
    }

    // -----------------------------
    // DFS
    // -----------------------------
    vector<int> DFS(int start) {

        vector<int> vis(n + 1, 0);
        vector<int> result;

        DFSUtil(start, vis, result);

        return result;
    }

    // -----------------------------
    // TOPOLOGICAL SORT (Kahn BFS)
    // -----------------------------
    vector<int> topologicalSort() {

        vector<int> indegree(n + 1, 0);

        for (int i = 1; i <= n; i++) {

            for (auto it : adj[i]) {

                indegree[it]++;
            }
        }

        queue<int> q;

        for (int i = 1; i <= n; i++) {

            if (indegree[i] == 0)

                q.push(i);
        }

        vector<int> topo;

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            topo.push_back(node);

            for (auto it : adj[node]) {

                indegree[it]--;

                if (indegree[it] == 0)

                    q.push(it);
            }
        }

        return topo;
    }

    // -----------------------------
    // DIJKSTRA (Shortest Path)
    // -----------------------------
    vector<int> dijkstra(int src) {

        vector<int> dist(n + 1, INT_MAX);

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        dist[src] = 0;

        pq.push({0, src});

        while (!pq.empty()) {

            int node = pq.top().second;
            int d = pq.top().first;

            pq.pop();

            for (auto it : adjW[node]) {

                int adjNode = it.first;
                int weight = it.second;

                if (d + weight < dist[adjNode]) {

                    dist[adjNode] =
                        d + weight;

                    pq.push({
                        dist[adjNode],
                        adjNode
                    });
                }
            }
        }

        return dist;
    }
};

#endif