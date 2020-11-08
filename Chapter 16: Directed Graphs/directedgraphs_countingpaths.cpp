/*
Chapter 15: Spanning Trees
Topic: Counting Paths
Use DFS like we did in Topological Sorting. Before travelling to next node, using its successor, set paths(child) += paths(successor);
*/

#include <bits/stdc++.h>
using namespace std;

int nodes,edges;
vector<int> adj[100000];
vector<int> ans;
int vis[1000000] = {0};
int paths[1000000] = {0};
int flg=0;

// count the number of paths
void fpaths(int x)
{
    if(vis[x] == 1) 
    {
        flg=1;
        return;
    }
    vis[x] = 1;
    for(int i = 0;i<adj[x].size();i++)
    {
        int y = adj[x][i];
        if(vis[y] == 2) continue;
        fpaths(y);
    }
    vis[x]=2;
    ans.push_back(x);
}

int main()
{
    cin >> nodes >> edges;
    for(int i = 0;i < edges;i++)
    {
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    int source;
    cin >> source;
    paths[source] = 1;
    fpaths(source);
    reverse(ans.begin(), ans.end());
    for(int i = 0 ;i < ans.size(); i++)
    {
        int y = ans[i];
        for(int j = 0; j<adj[y].size(); j++)
        {
            paths[adj[y][j]]+=paths[y];
        }
    }
    
    for(int i =0;i<nodes;i++)
    {
        cout << paths[i+1] << " ";
    }
    return 0;
}

