/*
Chapter 17: Tree Queries
Topic: Distance between two nodes
Method :
Height of x + height of y - height of lca(x,y)
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100000];
vector<int> euler;
int vis[100000] = {0};
int height[100000] = {0};
int h2[100000] = {0};

void dfs(int x,int h)
{
    if(vis[x]) return;
    vis[x]=1;
    h2[x] = h;
    euler.push_back(x);
    height[euler.size()-1] = h;
    for(int i=0;i<adj[x].size();i++)
    {
        int y = adj[x][i];
        if(vis[y]) continue;
        euler.push_back(x);
        height[euler.size()-1] = h;
        dfs(y,h+1);
    }
    
    euler.push_back(x);
    height[euler.size()-1] = h;
}

int main()
{
    int n, q;
    cin >> n >> q;
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1,0);
    while(q--)
    {
        int x,y;
        cin >> x >> y;
        int f,s;
        for(int i=0;i<euler.size();i++)
        {
            if(euler[i] == x)
            {
                f=i;
                break;
            }
        }
        for(int i=0;i<euler.size();i++)
        {
            if(euler[i] == y)
            {
                s=i;
                break;
            }
        }
        if(f>s)
        {
            swap(f,s);
        }
        int mh=INT_MAX;
        int mhi=0;
        for(int i=f;i<=s;i++)
        {
            if(height[i] < mh)
            {
                mh = height[i];
                mhi = i;
            }
        }
        cout << h2[x]+h2[y]-2*mh << endl;
    }
    return 0;
}



