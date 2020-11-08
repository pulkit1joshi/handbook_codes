/*
Topic: Dynamic Programming
Question: Edit distance between two strings.
Edit distance between two string is dfined as minimum number of moves required to convert one string to other. These moves can be:
1. Adding a letter (alphabet)
2. Removing a letter (alphabet)
3. Modifying an alphabet
*/

#include <bits/stdc++.h>
using namespace std;

int dp[1000][1000];

string s1,s2;

int solve(int i,int j)
{
    if(dp[i][j] != -1) return dp[i][j];
    if(s1[i-1] == s2[j-1]) dp[i][j] = solve(i-1,j-1);
    else dp[i][j] = min(min(solve(i-1,j),solve(i-1,j-1)),solve(i,j-1))+1;
    return dp[i][j];
}
 
int main() {
    for(int i=0;i<1000;i++)
        for(int j=0;j<1000;j++)
        {
            if(i==0) dp[i][j]=j;
            else if(j==0) dp[i][j]=i;
            else dp[i][j]=-1;
        }
    cin >> s1 >> s2;
    cout << solve(s1.size(),s2.size()) << endl;
    return 0;
}

