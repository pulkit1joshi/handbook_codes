/*
You are given a number n. You have to generate all permutations of list 1,2,....n.
Two ways :
1. Recursion
2. Iterative

This code is iterative way of doing this using stl function, next_permutation.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> ans;

void print(vector<int> x)
{
    for(int i=0;i<ans.size();i++)
        cout << ans[i] << " ";
}

int main() {
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        ans.push_back(i+1);
    }
    do
    {
        print(ans);
        cout << endl;
    }
    while(next_permutation(ans.begin(),ans.end()));
    return 0;
}

