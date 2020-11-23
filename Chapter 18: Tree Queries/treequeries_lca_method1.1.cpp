/*
Chapter 17: Tree Queries
Topic: Lowest Common Ancestor
Method 1: 
Step 1: We will find the height and parent of each node.
Step 2: For two nodes x and y, we will first traverse up the one that is much lower such that both nodes are in same height
Step 3: Now we will traverse both up till we get a common node.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100000];
int height[100000] = {0};
int parent[100000] = {0};
bool vis[100000] = {0};

void dfs(int x,int h)
{
    if(vis[x]) return;
    vis[x]=1;
    height[x] = h;
    for(int i=0;i<adj[x].size();i++)
    {
        int y=adj[x][i];
        if(vis[y]) continue;
        parent[y] = x;
        dfs(y, h+1);
    }
}

int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1,1);
    int x,y;
    cin >> x >> y;
    if(height[x] > height[y]) swap(x,y);
    while(height[y] > height[x])
    {
        y = parent[y];
    }
    while(x!=y)
    {
        x=parent[x];
        y=parent[y];
    }
    cout << x << endl;
    return 0;
}



