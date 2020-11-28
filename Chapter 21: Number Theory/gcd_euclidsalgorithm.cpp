/*
Chapter 21: Number Thory
Topic: Euclids algorithm for finding GCD
gcd(a,b) = a if b==0
else if it gcd(b,a%b)

Why ?
Let a > b , then

a = b.q + r
now gcd(b.q + r, b) 
= gcd(r, b)
*/

#include <bits/stdc++.h>
using namespace std;

int gcd(int x,int y)
{
    if(x==0) return y;
    if(y==0) return x;
    return gcd(y, x%y);
}
int main()
{
    int x,y;
    cin >> x >> y;
    cout << gcd(max(x,y),min(x,y));
    return 0;
}



