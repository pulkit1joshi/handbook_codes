/*
Chapter 7 : Dynamic Programming
Topic : Coin Problem
Question : You are given coins of value coins[i] for all i that belong to n. Now find minimum coins to exchange for x.
*/

#include <bits/stdc++.h>
using namespace std;
// imax is value that is biggest and can not actually be exchanged for
int imax = 100000000;
int n;
// Stores the coins that can be exhanged for a value.
vector<int> coins;
int dp[100000000];

// This is recurrsive function that calls find(sum-c) everytime
int find(int sum)
{
    // Base conditions , is sum < 0 return no possible else if sum == 0 return 0;
    if(sum < 0) return imax;
    if(sum ==0)  return 0;
    // If already calculated, return the value saved.
    if(dp[sum] != imax) return dp[sum];
    int ans=imax;
    // Check for every coin possible.
    for(int i=0;i<coins.size();i++)
    {
        ans=min(ans,find(sum-coins[i])+1);
    }
    // Save value and return it.
    dp[sum] = ans;
    return dp[sum];
}

int main() {
    for(int i=0;i<1000000;i++) dp[i] = imax;
    dp[0] = 0;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        coins.push_back(x);
    }  
    int sum;
    cin >> sum;
    cout << find(sum) << endl;
    return 0;
}

