#include<bits/stdc++.h>
using namespace std;
void adjencymatrix()
{
 int n,m;
    
    cin>>n>>m;
    int adj[n+1][n+1];
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1;
    }

}

void adjencylists()
{ 
    //for directed and undirected graph
    int n,m;
    
    cin>>n>>m;
    vector<int> adj[n+1]; // array of vectors
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u); // for undirected graph
    }

    //for directed graph we will not add this line
    // adj[v].push_back(u);
    //u-->v



    //for weighted graph
    int n,m;
    // in weighted graph we will take input in the form of u,v,w
    cin>>n>>m;
    vector<pair<int,int>> adj[n+1]; // array of vectors of pairs
    for(int i=0;i<m;i++) // we use m here because we have to take input of m edges
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w}); // for undirected graph
    }

     //for directed graph we will not add this line
    // adj[v].push_back({u,w});
     //u-->v with weight w
     

}
int main()
{
   
    
 return 0;
}