/*
Topic: Range Queries
Technqiue: Prefix sum.
*/

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n; int q;
    cin >> n >> q;
    int A[n];
    int pref[n];
    for(int i=0;i<n;i++)
        cin >> A[i];
    for(int i=0;i<n;i++)
    {
        pref[i] = pref[max(i-1,0)]+A[i];
    }
    while(q--)
    {
        int x,y;
        cin >> x >> y;
        cout << pref[y] - pref[max(x-1,0)] << endl;
    }
}

int main() {
    solve(); 
    return 0;
}
