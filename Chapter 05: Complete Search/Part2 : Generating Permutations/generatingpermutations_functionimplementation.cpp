/*
You are given a number n. You have to generate all permutations of list 1,2,....n.
Two ways :
1. Recursion
2. Iterative

Now I will implement next permutation function.

*/

#include <bits/stdc++.h>
using namespace std;

void nextpermutation(vector<int> &x)
{
    for(int i=x.size()-1;i>=1;i--)
    {
        if(x[i-1] < x[i])
        {
            int j=i;
            for(j=i;j<x.size();j++)
            {
                if(x[j] < x[i-1])
                {
                    break;
                }
            }
            j--;
            int temp = x[i-1];
            x[i-1] = x[j];
            x[j] = temp;
            reverse(x.begin()+i, x.end());
            return;
        }
    }
    return;
}

int main()
{
    int n;
    cin >> n;
    vector<int> A;
    for(int i=0;i<n;i++) A.push_back(i);
    nextpermutation(A);
    for(int i=0;i<n;i++)
        cout << A[i] << " ";
    cout << endl;

}
