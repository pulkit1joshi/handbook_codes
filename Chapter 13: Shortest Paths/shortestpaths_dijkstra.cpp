/*
Chapter 13: Shortest Paths Algorithm
Topic: Dijsktra's Algorithm
Implementation: O(nlog(n))
*/
#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> adj[100000];
int dis[100000];
bool vis[100000];

void dijsktra(int source)
{
    queue<pair<int,int>> q;
    dis[source] = 0;
    q.push({dis[source], source});
    while(!q.empty())
    {
        // Pop least distance element from the queue
        pair<int,int> p = q.front();
        q.pop();
        // If it is always processed then continue;
        if(vis[p.second]) continue;
        // Mark it processed that means now it have minimum possible distance
        vis[p.second] = true;
        int d=p.first;
        int y=p.second;
        // Start pushing the neighbours into the queue
        for(int i=0;i<adj[y].size();i++)
        {
            if(vis[adj[y][i].first]) continue;
            if(dis[adj[y][i].first] > d + adj[y][i].second)
            {
                dis[adj[y][i].first] = d + adj[y][i].second;
                q.push({dis[adj[y][i].first], adj[y][i].first});
            }
        }
    }
}

int main() {
    /*
    Initialise all the variables
    */
    for(int i=0;i<10000;i++)
    {
        dis[i] = INT_MAX;
        vis[i] = false;
    }
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int x,y,w;
        cin >> x >>y >> w;
        adj[x].push_back({y,w});
        adj[y].push_back({x,w});
    }
    int source,dest;
    cin >> source >> dest;
    dijsktra(source);
    cout << dis[dest] << endl;
    return 0;
}

