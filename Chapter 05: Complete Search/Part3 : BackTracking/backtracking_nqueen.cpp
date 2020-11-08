/*
Topic : Back-Tracking
Question : 
Place N queen such that no queen attack each other.
*/

#include <bits/stdc++.h>
using namespace std;

int n;
int m
bool col[100] = {false};
bool diag[100] = {false};
bool diag2[100] = {false};
int A[100][100];

void solve(int k)
{
    if(k>=n)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cout << A[i][j] << " ";
            cout << endl;
        }
        cout << endl;
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            if(col[i] == true) continue;
            if(diag[i+k] == true || diag2[(3-i)+k] == true) continue;
            col[i] = true; diag[i+k] = true; diag2[3-i+k] = true;
            A[k][i]=1;
            solve(k+1);
            col[i] = false; diag[i+k] = false; diag2[k-i+3] = false;
            A[k][i]=0;
        }
    }
}

void initialize()
{
    for(int i=0;i<100;i++)
        for(int j=0;j<100;j++)
            A[i][j] = 0;
}
int main()
{
    initialize();
    cin >> n;
    solve(0);
    
        
}
