/*
Chapter 21: Number Thory
Topic: Prime Numbers
Check if x is a prime number in O(root(n))
*/

#include <bits/stdc++.h>
using namespace std;

bool checkprime(int x)
{
    for(int i=2;i*i<=x;i++)
    {
        if(x%i == 0) return false;
    }
    return true;
}
int main()
{
    int x;
    cin >> x;
    if(checkprime(x))
    {
        cout << "Prime" << endl;
    }
    else cout << "Not Prime" << endl;
    return 0;
}



