/*
Chapter 15: Spanning Trees
Topic: Kruskals Algorithm using Union Find
*/

#include <bits/stdc++.h>
using namespace std;

int nodes = 0;
int edges;

int leader[10000];

// Basic structure and comparator for sorting

struct edge
{
    int from;
    int to;
    int weight;
};

edge e[10000];

bool comp(edge a, edge b)
{
    return a.weight < b.weight;
}

// Dijoiunt Set Union datastructure

void initialise(int n)
{
    for(int i=1;i<=n;i++)
        leader[i] = i;
}

int fset(int x)
{
    if(leader[x] == x) return x;
    leader[x] = fset(leader[x]);
    return leader[x];
}

void join(int x, int y)
{
    x = fset(x);
    y = fset(y);
    leader[x] = y;
}

// Kruskals algorithm 

void kruskals()
{
    vector<int> ans;
    for(int i =0;i<edges;i++)
    {
        if(fset(e[i].from) == fset(e[i].to)) 
        {
            continue;
        }
        ans.push_back(i);
        join(e[i].from,e[i].to);
    }
    for(int i=0;i<ans.size();i++)
    {
        cout << e[ans[i]].from << " " << e[ans[i]].to << " " << e[ans[i]].weight << endl;
    }
}


int main()
{
    
    cin >> nodes >> edges;
    for(int i=0;i<edges;i++)
    {
        int x,y,w;
        cin >> x >> y >> w;
        e[i].from = x;
        e[i].to = y;
        e[i].weight = w;
    }
    initialise(nodes);
    sort(e,e+edges,comp);
    kruskals();
    return 0;
}
