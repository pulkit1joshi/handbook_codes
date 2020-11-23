/*
Chapter 17: Tree Queries
Topic: Finding Ancestors
Given a tree and 2 values x and k. Find kth ancestor of x above x.
Going with brute force.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100000];
int parent[100000];
int vis[100000] = {0};

void dfs(int x)
{
    if(vis[x]) return;
    vis[x]=1;
    for(int i=0;i<adj[x].size();i++)
    {
        int y = adj[x][i];
        if(vis[y]) continue;
        parent[y] = x;
        dfs(y);
    }
}

int main()
{
    int n,q;
    cin >> n >> q;
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1);
    while(q--)
    {
        int x,k;
        cin >> x >> k;
        int nf=0;
        while(k)
        {
            if(parent[x]==0) 
            {
                nf=1;
                break;
            }
            x = parent[x];
            k--;
        }
        if(nf)
        {
            cout << "Not Found" << endl;
        }
        else
        {
            cout << "Found:" << x << endl;
        }
    }
    return 0;
}
