/*
Chapter 17: Tree Queries
Topic: Subtree Queries
Given a tree rooted at 1. You have to answer q queries. Queries can be of two types
1. Update the node value.
2. Find the subtree sum.
Update takes place in O(1) and Every query is answered in O(n).
*/

#include <bits/stdc++.h>
using namespace std;

// adj stores the tree
// val stores the values of ith node and can be referenced using val[i]
// size stores the size of subtree of any ith node and can be referenced using size[i]
int n,q;
vector<int> adj[100000];
int aval[100000] = {0};
int val[100000] = {0};
int size[100000] = {0};
int nodeid[100000] = {0};
int vis[100000];
int id=1;
int dfs(int x)
{
    if(vis[x]) return 0;
    int cid = id;
    nodeid[id++] = x;
    vis[x] = 1;
    size[cid]=1;
    for(int i=0;i<adj[x].size();i++)
    {
        int y=adj[x][i];
        if(vis[y]) continue;
        
        size[cid] +=dfs(y);
    }
    val[cid] = aval[x];
    return size[cid];
}

void printinfo()
{
    cout << "Node id" << endl;
    for(int i=1;i<=n;i++)
    {
        cout << nodeid[i] << " ";
    }
    cout << endl;
    cout << "Size" << endl;
    for(int i=1;i<=n;i++)
    {
        cout << size[i] << " ";
    }
    cout << endl;
    cout << "Value" << endl;
    for(int i=1;i<=n;i++)
    {
        cout << val[i] << " ";
    }
    cout << endl;
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
    for(int i=1;i<=n;i++)
    {
        int x;
        cin >> x;
        aval[i]=x;
    }
    dfs(1);
    // Uncomment below to see the nodeid , size and node values.
    // printinfo();

    while(q--)
    {
        int choice;
        cin >> choice;
        if(choice == 1)
        {
            int x,v;
            cin >> x >> v;
            for(int i=1;i<=n;i++)
            {
                if(nodeid[i] ==x)
                    val[x]=v;
            }
        }
        else
        {
            int x;
            cin >> x;
            int s=0;
            int st=0;
            int ans=0;
            for(int i=1;i<=n;i++)
            {
                if(nodeid[i] ==x)
                {
                    st=i;
                    s=size[i];
                    break;
                }
            }
            for(int i=0;i<s;i++)
            {
                ans+=val[i+st];
            }
            cout << ans << endl;
        }
    }
    return 0;
}

