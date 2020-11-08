#include <bits/stdc++.h>
using namespace std;

/* Generating Subsets : Method 2
You are given a set of numbers : {0 , 1 , 2 , 3 , 4}
You have to find all the subsets of this set.
*/

int n;
int A[100];

void search()
{
    // 1 << n means 2^n i.e this number of combinations are possible
    // Now 2^n will take n bits 101001... n
    // Each xth bit represets the presence of xth number in A[i]
    for(int i=0;i< (1<<n);i++)
    {
        for(int j=0;j<n;j++)
        {
            // 1<<j means setting jth bit as 1 and checking if it is set in i using &&
            if((1<<j)&i)
            {
                cout << A[j] << " ";
            }
        }
        cout << endl;
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
    search();
    return 0;
}

