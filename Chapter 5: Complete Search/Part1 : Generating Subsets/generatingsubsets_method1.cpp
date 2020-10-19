#include <bits/stdc++.h>
using namespace std;

/* Generating Subsets
You are given a set of numbers : {0 , 1 , 2 , 3 , 4}
You have to find all the subsets of this set.
*/

int n;
int A[100];
vector<int> ans;

void search(int k)
{
    if(k>=n) 
    {
        //Print the subset
        for(int i=0;i<ans.size();i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
        return;
    }
    else
    {
        // Lets not select this element and move forward.
        search(k+1);
        // Lets select this element
        ans.push_back(A[k]);
        search(k+1);
        ans.pop_back();
    }
}


int main() {
    // The number of elements
    cin >> n;
    // Input the elements
    for(int i=0;i<n;i++)
    {
        cin >> A[i];
    }
    search(0);
    return 0;
}

