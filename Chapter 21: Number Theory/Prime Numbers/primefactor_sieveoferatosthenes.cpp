/*
Chapter 21: Number Thory
Topic: Sieve of Eratosthenes
Used to find all the prime numbers from 1 to n in O(nloglogn)
*/

#include <bits/stdc++.h>
using namespace std;

bool sieve[100000] = {true};

void sieves(int n)
{
    sieve[0] = sieve[1] = false;
    for(int i=2;i<=n;i++)
    {
        if(!sieve[i]) continue;
        for(int j=i+i;j<=n;j+=i)
        {
            sieve[j]=false;
        }
    }
}
int main()
{
    for(int i=0;i<100000;i++) sieve[i]=true;
    int n;
    cin >> n;
    sieves(n);
    for(int i=2;i<=n;i++)
    {
        if(sieve[i])
        {
            cout << i << " ";
        }
    }
    return 0;
}



