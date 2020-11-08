/*
Chapter 7 : Dynamic Programming
Topic : Coin Problem
Question : You are given x and you have to count the number of solutions you can have, different arrangement means one count. 1 2 and 2 1 are different.
*/

#include <bits/stdc++.h>
using namespace std;
int n;
// Stores the coins that can be exhanged for a value.
vector<int> coins;
int dp[100000000];

// This is iterative function that calls find(sum-c) everytime
int find(int sum)
{
    dp[0] = 1;
    // First we build smaller solutions i.e 0 , 1 , 2 , 3 and then use them to find the greater solution.
    for(int i=0;i<=sum;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i-coins[j] < 0) continue;
                dp[i] +=dp[i-coins[j]];
        }
    }
    return dp[sum];
}

int main() {
    for(int i=0;i<1000000;i++) dp[i] = 0;
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

