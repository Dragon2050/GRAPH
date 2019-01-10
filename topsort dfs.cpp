#include<bits/stdc++.h>

using namespace std;

#define white 0
#define black 1
#define gray 2

int node,edge,visited[2000005],cnt;
vector<int> vec[2005];
int st[200005];
void dfs(int s)
{
    visited[s]=gray;
    int siz=vec[s].size();
    for(int i=0;i<siz;i++)
    {
        int v=vec[s][i];
        if(visited[v]==white)
        {
            dfs(v);
        }
    }
    visited[s]=black;
    st[cnt]=s;
    cnt++;
}

int main()
{
    cin>>node>>edge;
    for(int i=0;i<edge;i++)
    {
        int u,v;
        cin>>u>>v;
        vec[u].push_back(v);
    }
    for(int i=1;i<=node;i++)
    {
        if(visited[i]==white)
        {
            dfs(i);
        }
    }
    reverse(st,st+cnt);
    for(int i=0;i<cnt;i++)
    {
        cout<<st[i]<<" ";
    }
    return 0;
}
