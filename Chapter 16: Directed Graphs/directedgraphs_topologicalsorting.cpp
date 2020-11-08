/*
Chapter 15: Spanning Trees
Topic: Topological Sorting
Use DFS to create list of nodes that are finished first and so on.
*/

#include <bits/stdc++.h>
using namespace std;

int nodes,edges;
vector<int> adj[100000];
vector<int> ans;
int vis[1000000] = {0};
int flg=0;

// Topological sorting using dfs
void topologicalsort(int x)
{
    if(vis[x] == 1)
    {
        flg=1;
        return;
    }
    vis[x] = 1;
    for(int i = 0; i < adj[x].size(); i++)
    {
        int y = adj[x][i];
        if(vis[y] == 2) continue;
        topologicalsort(y);
    }
    vis[x] = 2;
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
    for(int i = 1; i < nodes;i++)
    {
        if(vis[i]) continue;
        topologicalsort(i);
    }
    if(flg)
    {
        cout << "Topological sort is not possible" << endl;
        return 0;
    }
    for(int i = ans.size()-1; i >= 0 ;i--)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}

