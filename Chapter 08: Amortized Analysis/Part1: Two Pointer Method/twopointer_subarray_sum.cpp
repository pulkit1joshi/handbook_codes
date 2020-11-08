/*
Topic: Amortized Analysis
Method: Two pointer
Queston: Given an array of given size. Find if a contigous subarray have sum equal to x
*/

#include <bits/stdc++.h>
using namespace std;

int A[10000];

bool solve()
{
    int n;
    cin >> n;
    int x;
    cin >> x;
    for(int i=0;i<n;i++) cin >> A[i];
    // Starting pointer that moves from left.
    int st=0;
    int csum=0;
    // Second pointer is i, that tells the right extreme.
    for(int i=0;i<n;i++)
    {
        csum+=A[i];
        if(csum > x)
        {
            while(csum > x && st<=i)
            {
                csum-=A[st];
                st++;
            }
        }
        if(csum == x) return true;
    }
    return false;
}
 
int main() {
    int t;
    cin >> t;
    while(t--)
    {
        if(solve())
        {
            cout << "Yes, exists" << endl;
        }
        else cout << "No, Subarray do not exist" << endl;
    }
    return 0;
}

