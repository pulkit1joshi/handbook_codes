/*
Chapter 12: Graph Traversal
Topic: Breadth First Search
*/
#include <bits/stdc++.h>
using namespace std;

// Adjacency list , lets suppose nodes are less then 1000
vector<int> adj[1000];
vector<int> vis(1000, 0);

void bfs(int x)
{
    queue<int> q;
    q.push(x);

    while(!q.empty())
    {
        int y = q.front();
        q.pop();
        vis[y]=true;
        for(int i=0;i<adj[y].size();i++)
        {
            if(vis[adj[y][i]]) continue;
            q.push(adj[y][i]);
        }
    }
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
    bfs(1);
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

