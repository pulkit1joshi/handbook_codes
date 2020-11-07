/*
Chapter 15: Spanning trees
Topic: Union find datastructure
Question: Implement basic union find datastructure O(n) complexity.
*/

#include <bits/stdc++.h>
using namespace std;

// We can have atmost 1000000 independing set
int leader[1000000];

// Find the leader of this set. Leader is the one who is leader of its own set.
int findleader(int a)
{
    if(leader[a] == a)
    return a;
    return findleader(leader[a]);
}

//Combine the leader of set b and set its leader as that of a
void combine(int a,int b)
{
    leader[findleader(b)] = findleader(a);
}

int main()
{
// We have n sets initially
    int n;
    cin >> n;
    // Initialise every leader as i
    for(int i=1;i<=n;i++)    
        leader[i] = i;
    // We will take q queries to combine the sets. This is just for explaining.
    int q;
    cin >> q;
    for(int i = 0;i < q;i++)
    {
        int x,y;
        cin >> x >> y;
        combine(x,y);
    }
    for(int i =1;i<=n;i++)
    {
        cout << "Set of " << i << " is: " << leader[i] << endl;
    }
    return 0;
}
