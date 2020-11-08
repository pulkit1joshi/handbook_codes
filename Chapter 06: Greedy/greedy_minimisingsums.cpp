/*
Maximising sums
You are given a1, a2, a3, a4, a5,.... an; you have to find x such that sum 
|a1-x| .... |an-x| is minimised.
*/

#include <bits/stdc++.h>
using namespace std;

int A[100];
void solve()
{
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> A[i];
    }
    sort(A,A+n);
    int x = A[(n-1)/2];
    cout << x << endl;
}

int main() { 
    solve();
    return 0;
}

