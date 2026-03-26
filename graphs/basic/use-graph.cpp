#include<bits/stdc++.h>
#include "../graph-lib.hpp"
using namespace std;
int main()
{
    int n=5;
    Graph g(n, false); // undirected graph with 5 nodes
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    cout << "Graph representation (Adjacency List):" << endl;
    g.printGraph();

     cout << "BFS starting from node 1:" << endl;
    vector<int> bfsResult = g.BFS(1);
    for (int node : bfsResult) {
        cout << node << " ";
    }
    cout << endl;

        cout << "DFS starting from node 1:" << endl;
    vector<int> dfsResult = g.DFS(1);
    for (int node : dfsResult) {
        cout << node << " ";
    }
    cout << endl;

 return 0;
}