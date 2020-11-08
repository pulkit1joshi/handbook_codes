/* 
Minimum Queries
Concept: Sparse Table
You are given an array with elements. Your task is to find minimum in a given range in O(nlogn).
*/

#include <bits/stdc++.h>
using namespace std;
#define long long LL;
int table[10000][10];
int A[10000];
int n;
int mxp;


// Create Sparse Table
void create_sparse()
{
    int p=1;
    while(p<=mxp)
    {
        int len = 1<<p;
        for(int i=1;i+len<=n+1;i++)
        {
            table[i][p] = min(table[i][p-1],table[i+(1<<(p-1))][p-1]);
        }
        p++;
    }
}

// Querying sparse table in nlogn
// We can find in O(1) for Minimum range queries as overlapping intervals doesn't matter as long as in the range.
// Thus although the below is generalised code you can also work out with O(1);
int query_sparse(int x,int y)
{
    int ans=INT_MAX;
    for(int p=mxp;p>=0;p--)
    {
        int len = 1<<p;
        if(y-x+1 >= len)
        {
        ans=min(ans,table[x][p]);
        x+=len;
        }
    }
    return ans;
}

int main() {
    // Initialization
    for(int i=0;i<1000;i++)
        for(int j=0;j<10;j++)
            table[i][j]=INT_MAX;
    cin >> n;
    mxp = log2(n)+1;
    // Take input
    for(int i=1;i<=n;i++)
    {
        cin >> A[i];
        table[i][0] = A[i];
    }
    
    // Create sparse table
    create_sparse();
    // Input queries
    int q;
    cin >> q;
    while(q--)
    {
        int x,y;
        cin >> x >> y;
        cout << query_sparse(x,y) << endl;
    }
    return 0;
}

