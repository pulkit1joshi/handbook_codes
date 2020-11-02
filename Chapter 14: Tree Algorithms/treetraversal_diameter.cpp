/*
Chapter 14: Tree Algorithms
Topic: Dp on trees
Question: find the diameter of a tree
Note: Here i am counting the nodes so nodes = edges+1
*/

#include <bits/stdc++.h>
using namespace std;
vector<int> adj[10000];
int subtree[10000];
int diasubtree[10000];
int diameter=0;
void dfs(int x, int p)
{
    int m1,m2;
    m1=m2=0;
    for(int i=0;i<adj[x].size();i++)
    {
        int y = adj[x][i];
        if(y==p) continue;
        dfs(y,x);
        subtree[x] = max(subtree[x],1+subtree[y]);
        if(subtree[y] > m1) { m2=m1; m1=subtree[y]; }
        else if(subtree[y] > m2) { m2 = subtree[y]; }
    }
    diasubtree[x] = max(m1+m2+1,diasubtree[x]);
    diameter=max(diameter,diasubtree[x]);
}

int main()
{
    for(int i=0;i<10000;i++) subtree[i]=1;
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
    cout << diameter-1 << endl;
}
