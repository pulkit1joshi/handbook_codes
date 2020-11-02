/*
Chapter 12: Graph Traversal
Topic: Depth First Search
*/
#include <bits/stdc++.h>
using namespace std;

// Adjacency list , lets suppose nodes are less then 1000
vector<int> adj[1000];
vector<int> vis(1000, 0);
vector<int> cols(1000, 0);
int flg=0;

void dfs(int x, int col)
{
    if(vis[x]) return;
    vis[x] = 1;
    cols[x] = col;
    int ncol=1;
    if(col == 1) ncol = 2;
    // Process node x here before going to its children
    for(int i=0;i<adj[x].size();i++)
    {
        int y = adj[x][i];
        if(cols[y] == cols[x]) flg=1;
        if(vis[y]) continue;
        dfs(y, ncol);
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
    dfs(1,1);
    if(flg==1)
    {
        cout << "Not bipartite" << endl;
    }
    else cout << "Bipartite" << endl;
    return 0;
}

