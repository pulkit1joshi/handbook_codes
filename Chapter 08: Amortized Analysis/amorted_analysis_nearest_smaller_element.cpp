/*
Topic: Amortized Analysis
Datastructure: Stack
Queston: Nearest Smaller Element
Find the closest smaller preceding element.
*/

#include <bits/stdc++.h>
using namespace std;

int A[10000];

bool solve()
{
    int n;
    cin >> n;
    vector<int> vec;
    vector<int> ans(n,-1);
    stack<int> st;
    for(int i=0;i<n;i++) 
    {
        int x;
        cin >> x;
        vec.push_back(x);
    }
    for(int i=n-1;i>=0;i--)
    {
        if(st.empty() || vec[st.top()] <= vec[i])
            st.push(i);
        else
        {
            while(!st.empty() && vec[i] < vec[st.top()])
            {
                ans[st.top()] = vec[i];
                st.pop();
            }
            st.push(i);
        }
    }
    for(int i=0;i<n;i++)
        cout << ans[i] << " ";
    return false;
}
 
int main() {
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}

