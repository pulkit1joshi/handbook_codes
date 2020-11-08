/*
Chapter 7: Dynamic Programming

Question : Longest Increasing Subsequence - O(nlogn)
*/

#include <bits/stdc++.h>
using namespace std;

int dp[1000001] = {100000000};
int A[1000001] = {0};
int n;

// This function finds the LIS in nlogn
void solve()
{
    // Set all the dp to max value and initial as least
    dp[0] = -100000000;
    for(int i=1;i<=n;i++) dp[i] = 100000000;

    // Loop nlogn
    for(int i=0;i<n;i++)
    {
        // Find the lower bound i.e next greater or equal element to A[i]
        // If dp[j-1] < A[i] && dp[j] > A[i] then dp[j] = A[i].
        // That means that we had a LIS of length j and now a new element A[i] > dp[j] has arrived.
        auto it = lower_bound(dp,dp+n,A[i]) - dp;
        if(dp[it] > A[i] && A[i] > dp[it-1])
            dp[it] = A[i];
    }
    int ans=0;
    for(int i=0;i<=n;i++)
    {
        if(dp[i] < 10000000)
            ans=i;
    }
    cout << ans << endl;
}

int main() {
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> A[i];
    solve();
    return 0;
}

