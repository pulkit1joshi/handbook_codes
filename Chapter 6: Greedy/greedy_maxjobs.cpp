/*
Max jobs problem.
You are given n jobs with start and end time. Find the maximum number of jobs you can do.
*/
#include <bits/stdc++.h>
using namespace std;


// Jon datastructure that encapsulates start as well as end
struct job
{
    int start;
    int end;
};

// Compare function that is used for sorting
bool comp(job a, job b)
{
    if(a.end != b.end)
    {
        return a.end < b.end;
    }
    else return a.start < b.start;
}

// Main function which takes the job as input sorts it and outputs maximum jobs that can be done.
void solve()
{
    int n;
    cin >> n;
    job jobs[n];
    for(int i=0; i < n; i++)
    {
        int x,y;
        cin >> x >> y;
        jobs[i].start = x;
        jobs[i].end = y;
    }

    sort(jobs, jobs+n, comp);
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        int j=i;
        while(j < n && jobs[j].start < jobs[i].end) j++;
        if(j != i)
            i=j-1;
        cnt++;
    }
    cout << cnt << endl;
}

int main()
{
    solve();
    return 0;
}
