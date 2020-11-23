/*
Chapter 17: Tree Queries
Topic: Lowest Common Ancestor
Method 2: 
Idea: During a tree traversal a given node is visited number of time that is equal to the number of its children. The same node is also the LCA when two of its children are the query nodes. Now, this node will be visited atleast once, might be more but atleast once between these two node findings. Thus we will make a traversal array and find this LCA between them. Now LCA is between but which ? LCA is the one with least height. How? Try and see :P.

This code does not have any seg tree or sparse table implementation. These Datastructure can reduce the query complexity to O(log(n))
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100000];
vector<int> euler;
int vis[100000] = {0};
int height[100000] = {0};

void dfs(int x,int h)
{
    if(vis[x]) return;
    vis[x]=1;
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
    dfs(1,1);
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
        cout << euler[mhi] << endl;
    }
    return 0;
}



