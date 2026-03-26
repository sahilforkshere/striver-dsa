//bfs traversal of a graph
#include<bits/stdc++.h>
#include "../graph-lib.hpp"
using namespace std;

void bfs( Graph &g,int start){
    vector<int> vis(g.n+1,0);
    queue<int> q;
    vis[start]=1;
    q.push(start);

    while (!q.empty())
    {
        int curr= q.front();
        q.pop();
        cout<<curr<<" ";
        for( auto it : g.adj[curr]){
            if(vis[it]==0){
                vis[it]=1;
                q.push(it);
            }
        }
    }
    

}

int main()
{
    int n=9;
    Graph g(n, false); // undirected graph with 5 nodes
    g.addEdge(1,2);
    g.addEdge(1,6);
    g.addEdge(2,3);
    g.addEdge(2,4);
    g.addEdge(4,5);
    g.addEdge(6,7);
    g.addEdge(6,9);
    g.addEdge(7,8);
    g.addEdge(5,8);
        cout << "Graph representation (Adjacency List):" << endl;
        g.printGraph();
        cout << "BFS starting from node 1:" << endl;
        bfs(g,1);


    return 0;
}
