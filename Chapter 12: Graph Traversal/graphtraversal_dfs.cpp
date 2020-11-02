/*
Chapter 12: Graph Traversal
Topic: Depth First Search
*/
#include <bits/stdc++.h>
using namespace std;

// Adjacency list , lets suppose nodes are less then 1000
vector<int> adj[1000];
vector<int> vis(1000, 0);

void dfs(int x)
{
    if(vis[x]) return;
    vis[x] = 1;
    // Process node x here before going to its children
    for(int i=0;i<adj[x].size();i++)
    {
        int y = adj[x][i];
        if(vis[y]) continue;
        dfs(y);
        // Process node x here one by one while checking out its children
    }
    // Process node x here after all its children are checked out.
}


int main() {
    int n;
    cin >> n;
    int edges;
    cin >> edges;
    for(int i=0;i<edges;i++)
    {
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1);
    for(int i=1;i<=n;i++)
    {
        if(!vis[i]) 
        {
            cout << "Disconnected Graph" << endl;
            return 0;
        }
    }
    cout << "Connected Graph" << endl;
    return 0;
}

