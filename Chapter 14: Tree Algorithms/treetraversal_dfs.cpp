void dfs(int x,int p)
{
    for(int i=0;i<=adj[x].size()-1;i++)
    {
        int y = adj[x][i];
        if(p==y) continue;
        dfs(y,x);
    }
}
