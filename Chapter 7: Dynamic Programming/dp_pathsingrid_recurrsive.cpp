/*
Chapter 7: Dynamic Programming

Question : Maximum sum path on grid. You are given an n x n grid with some values , say coins, now you have to find maximum coins that you can pick from the grid.

*/

#include <bits/stdc++.h>
using namespace std;

int A[1000][1000];
int dp[1000][1000];
int n;

long long solve(int x,int y)
{
    if(x < 0 || y < 0) return 0;
    if(dp[x][y] != -1) return dp[x][y];
    dp[x][y] = max(solve(x-1,y),solve(x,y-1))+A[x][y];
    return dp[x][y];
}


int main() {
    cin >> n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            dp[i][j]=-1;
            A[i][j]=0;
        }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> A[i][j];
        
    cout << solve(n-1,n-1) << endl;
    return 0;
}

