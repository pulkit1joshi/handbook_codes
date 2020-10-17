/*
You are given a number n. You have to generate all permutations of list 1,2,....n.
Two ways :
1. Recursion
2. Iterative

This code is recurssive way of doing this.
*/

#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> ans;
bool done[100] = {false};

void print(vector<int> x)
{
    for(int i=0;i<x.size();i++)
        cout << x[i] << " ";
    cout << endl;
}

void solve()
{
    if(ans.size() >= n)
    {
        print(ans);
    }
    else
    {
        for(int i = 0; i < n; i++)
        {
            if(done[i] == true) continue;
            done[i] = true;
            ans.push_back(i+1);
            solve();
            done[i] = false;
            ans.pop_back();
        }
    }
}


int main() {
    cin >> n;
    solve();
    return 0;
}

