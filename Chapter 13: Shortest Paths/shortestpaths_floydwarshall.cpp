/*
Chapter 13: Shortest Paths
Topic: Floyd Warshalls' Algorithm
*/

#include <bits/stdc++.h>
using namespace std;
int adj[1000][1000];
int dis[1000][1000];

int main() {
    for(int i=0;i<1000;i++)
        for(int j=0;j<1000;j++)
        {
            adj[i][j] = 1000000;
            dis[i][j] = 1000000;
            if(i==j) 
            {
                adj[i][j]=0;
                dis[i][j]=0;
            }
            
        }
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int x,y,w;
        cin >> x >> y >> w;
        adj[x][y] = w;
        dis[x][y] = w;
        adj[y][x] = w;
        dis[y][x] = w;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=n;k++)
            {
                dis[j][k] = min(dis[j][k],dis[j][i]+dis[i][k]);
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout << dis[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

