/*
Chapter 17: Tree Queries
Topic: Finding Ancestors
Given a tree and 2 values x and k. Find kth ancestor of x above x.
Using sparse table 
O(nlogn) - table formation
O(logn) - Per query
*/

#include <bits/stdc++.h>
using namespace std;

int n,q;

vector<int> adj[100000];
int sparse[100000][10];
int vis[100000] = {0};

// Sparse[x][0] stores the parent of node x only.
// Further sparse[x][1] = sparse[sparse[x][0]][0]
void dfs(int x)
{
    if(vis[x]) return;
    vis[x]=1;
    for(int i=0;i<adj[x].size();i++)
    {
        int y = adj[x][i];
        if(vis[y]) continue;
        sparse[y][0] = x;
        dfs(y);
    }
}

// We know 1+1 = 2 , 2+2 = 4 , 4+4 = 8, using this we find the 2^k th ancestor and store it as Sparse[x][k]
void makesparse(int x)
{
    if(x==10) return;
    for(int i=1;i<=n;i++)
    {
        if(sparse[i][x-1] == 0) continue;
        sparse[i][x] = sparse[sparse[i][x-1]][x-1];
    }
    makesparse(x+1);
}

int main()
{

    cin >> n >> q;
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1);
    makesparse(0);
    while(q--)
    {
        int x,k;
        cin >> x >> k;
        int y=0;
        // Using sparse table to query the kth ancstor. k can be written as 1011 (k = 11)
        // Now, 11 = 8 + 2 + 1 = 2^3 + 2^1 + 2^0 , hence we start from max possible power
        // And then keep on increasing y till y=k
        for(int i=10;i>=0;i--)
        {
            int rnge = pow(2,i);
            if(y+rnge <= k)
            {
                x = sparse[x][i];
                y=y+rnge;
            }
        }
        cout << x << endl;
    }
    return 0;
}

