/* 
Range Sum Queries
Concept: Binary Index Tree
You are given an array with elements. Your task is to find sum of a range in O(logn) and update in log(n).

Explaination:
Every number in index can be represented as a binary number. What we do here is, we make a new array of same size but different way of storing. 
1. Suppose k = 5 then it can be written as 101, thus it will be stored at location 5,6 and 8 only as 101+1 = 110 and 110+010 = 1000 =  8
2. Now we know that any index i is at i&(-i), using this we will find prefix sum which is just the ith element and all the other element that can be formed by removing the LSB.
*/

#include <bits/stdc++.h>
using namespace std;
#define long long LL;
int BIT[10000];
int A[10000];
int n;
void add(int k,int x)
{
    while(k<=n)
    {
        BIT[k]+=x;
        k+=(k&(-k));
    }
}

void build()
{
    for(int i=1;i<=n;i++)
    {
       add(i,A[i]);
    }
}

int query(int k)
{
    int s=0;
    while(k>0)
    {
        s+=BIT[k];
        k-=(k&(-k));
    }
    return s;
}

void solve()
{
    build();
    int q;
    cin >> q;
    while(q--)
    {
        int x,y;
        cin >> x >> y;
        cout << query(y) - query(x-1) << endl;
    }
}

int main() {
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> A[i];
    }

    solve();
    return 0;
}

