/*
Chapter 13: Shortest Paths Algorithm
Topic: Dijsktra's Algorithm
Implementation: O(nlog(n))
*/
#include <bits/stdc++.h>
using namespace std;
vector<pair<int,long long>> adj[100010];
long long dis[100010];
bool vis[100010];
long long path[100010];
 
void dijsktra(int source)
{
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> q;
    dis[source] = (long long)0;
    q.push({dis[source], source});
    while(!q.empty())
    {
        // Pop least distance element from the queue
        pair<int,int> p = q.top();
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
            //if(vis[adj[y][i].first]) continue;
            if(dis[adj[y][i].first] > d + adj[y][i].second)
            {
                dis[adj[y][i].first] = (long long) (d + adj[y][i].second);
                q.push({dis[adj[y][i].first], adj[y][i].first});
                path[adj[y][i].first] = y;
            }
        }
    }
}
 
int main() {
    /*
    Initialise all the variables
    */
    for(int i=0;i<100010;i++)
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
    dijsktra(1);
    if(dis[n] >= INT_MAX || vis[n] != true)
    {
        cout << -1 << endl;
        return 0;
    }
    vector<int> ans;
    int i = n;
    while(i != 1)
    {
        ans.push_back(i);
        i = path[i];
        
    }
    ans.push_back(1);
    for(int i=ans.size()-1;i>=0;i--)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
