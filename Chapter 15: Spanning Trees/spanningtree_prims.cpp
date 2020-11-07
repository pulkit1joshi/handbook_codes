/*
Chapter 15: Spanning Trees
Topic: Prims Algorithm
*/

#include <bits/stdc++.h>
using namespace std;

int nodes = 0;
int m;

vector<pair<int,int>> adj[100000];
bool vis[100000] = {false};


// primes algorithm
void prims()
{
    // Make a priority Queue
    // Push any random node (generally 1) into the pq with w = 0
    // Then pop it and push all the neighbours into pq as {w, node}
    // If it already exist in tree don't add it else, add it and push its neighbours into the pq
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,1});
    int sum = 0;
    while(!pq.empty())
    {
        pair<int,int> node = pq.top();
        pq.pop();
        int x = node.second;
        int w = node.first;
        if(vis[x]) continue;
        vis[x] = true;
        sum+=w;
        for(int i =0;i<adj[x].size();i++)
        {
            pq.push({adj[x][i].second,adj[x][i].first});
        }
    }
    cout << sum << endl;
}

int main()
{
    cin >> nodes >> m;
    for(int i =0;i < m;i++)
    {
        int x,y,z;
        cin >> x >> y >> z;
        adj[x].push_back({y,z});
        adj[y].push_back({x,z});
    }
    prims();
    return 0;
}

