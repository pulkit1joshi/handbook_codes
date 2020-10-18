/*
Coin Problem.
Given coins in euro system : 1, 2, 5, 10 ... Find number of minimum coins to change
*/
#include <bits/stdc++.h>
using namespace std;

int coins[4] = {1, 2, 5, 10};
void solve()
{
    int n;
    cin >>n;
    int ans=0;
    for(int i=3;i>=0;i--)
    {
        ans+=n/coins[i];
        n%=coins[i];
    }
    cout << ans << endl;
}

int main()
{
    solve();
}
