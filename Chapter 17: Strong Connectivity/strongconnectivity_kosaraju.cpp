/*
Chapter 17: Strong connectivity
Topic: Kosarau Algorithm
Given a directed graph, number the nodes on the basis of the component to which they belong
*/

#include <bits/stdc++.h>
using namespace std;

int n,e; // Number of edges and nodes
int compo[100000] = {0}; // All nodes in componenet 0 will have this value as 0
vector<int> adj[100000]; // The adjacency list of the graph
vector<int> revadj[100000]; // Adjacency list of reverse edged graph
vector<int> sequence; // Sequence of DFS 1
bool vis[100000]= {false}; // Visted flags
int curr=0; // Value of current compoenent being searched


// DFS 1 : Finds the order in which the nodes will be searched next
void dfs(int x)
{
    if(vis[x]) return;
    vis[x]=1;
    for(int i=0;i<adj[x].size();i++)
    {
        int y = adj[x][i];
        if(vis[y]) continue;
        dfs(y);
    }
    sequence.push_back(x);
}


// DFS 2 : Finds the component to which a node belongs
void dfs2(int x)
{
    if(vis[x]) return;
    vis[x]=1;
    for(int i=0;i<revadj[x].size();i++)
    {
        int y = revadj[x][i];
        if(vis[y]) continue;
        dfs2(y);
    }
    compo[x] = curr; 
}

// Kosaraju calling dfs1 and dfs2
void kosaraju()
{
    // first dfs
    for(int i=1;i<=n;i++)
    {
        if(vis[i]) continue;
        dfs(i);
    }
    
    // second dfs
    for(int i=0;i<=n;i++) vis[i]=false;
    for(int i=sequence.size()-1;i>=0;i--)
    {
        int y = sequence[i];
        if(vis[y]) continue;
        dfs2(y);
        curr++;
    }
    
    for(int i=1;i<=n;i++)
    {
        cout << compo[i] << " ";
    }
    cout << endl;
}

int main()
{

    cin >> n >> e;
    for(int i =0;i<e;i++)
    {
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        revadj[y].push_back(x);
    }
    kosaraju();
    return 0;
}
