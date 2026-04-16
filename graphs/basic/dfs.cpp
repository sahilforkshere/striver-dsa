#include<bits/stdc++.h>
#include "../graph-lib.hpp"
using namespace std;
void dfs( Graph &g, int start,vector<int> &vis){
   
    vis[start]=1;
    cout<<start<<" ";

    for(auto it :g.adj[start]){
        if(vis[it]==0){
            dfs(g,it,vis );
        }
        
    }
}
int main()
{
    int n=8;
    Graph g(n,false); // undirected graph with 8 nodes

    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,5);
    g.addEdge(2,6);
    g.addEdge(3,7);
    g.addEdge(3,4);
    g.addEdge(4,8);
    g.addEdge(7,8);
        cout << "Graph representation (Adjacency List):" << endl;
        g.printGraph();
        cout << "DFS starting from node 1:" << endl;
        vector<int> vis(n+1,0);
        dfs(g,1,vis);
       
 return 0;
}