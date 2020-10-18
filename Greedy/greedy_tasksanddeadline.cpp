/*
Max jobs problem.
You are given n jobs with start and end time. Find the maximum number of jobs you can do.
*/
#include <bits/stdc++.h>
using namespace std;


// Jon datastructure that encapsulates start as well as end
struct job
{
    int duration;
    int deadline;
};

// Compare function that is used for sorting
bool comp(job a, job b)
{
    if(a.duration != b.duration)
    {
        return a.duration < b.duration;
    }
    else return a.deadline < b.deadline;
}

// Main function which takes the job as input sorts it and outputs maximum jobs that can be done.
void solve()
{
    int n;
    cin >> n;
    job tasks[n];
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin >> x >> y;
        tasks[i].duration = x;
        tasks[i].deadline = y;
    }
    sort(tasks, tasks+n, comp);
    int curr=0;
    int ans=0;
    // Do the task with least time to complete first to maximise the profit.
    for(int i=0;i<n;i++)
    {
        curr+=tasks[i].duration;
        ans+=tasks[i].deadline-curr;
    }
    cout << ans << endl;
}

int main()
{
    solve();
    return 0;
}
