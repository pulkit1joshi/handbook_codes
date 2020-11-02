/*
Chapter 13: Tree Algorithm
Topic: Tree Traversal
Question : Count number of nods in subtree of each and every node.
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100000];
int child[100000];

void dfs(int x,int p)
{
    for(int i=0;i<adj[x].size();i++)
    {
        int y = adj[x][i];
        if(p==y) continue;
        dfs(y,x);
        child[x]+=child[y]+1;
    }
}

int main() {
    for(int i=0;i<100000;i++) child[i]=0;
    int n;
    cin >> n;
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1,-1);
    for(int i=1;i<=n;i++)
    {
        cout << i << " has " << child[i] << " number of nodes in its subtree" << endl;
    }
    return 0;
}
