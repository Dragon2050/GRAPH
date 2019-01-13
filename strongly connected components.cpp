#include<bits/stdc++.h>

using namespace std;

#define white 0
#define black 1
#define gray 2

int node,edge,visited[2000005],cnt;
vector<int> vec[2005],rev[2005],nodes,scc[2005];
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

void dfs1(int s)
{
    visited[s]=1;
    nodes.push_back(s);
    for(int i=0;i<rev[s].size();i++)
    {
        int v=rev[s][i];
        if(visited[v]==white)
        {
            dfs1(v);
        }
    }
}

int main()
{
    cin>>node>>edge;
    for(int i=0;i<edge;i++)
    {
        int u,v;
        cin>>u>>v;
        vec[u].push_back(v);
        rev[v].push_back(u);
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
    memset(visited,0,sizeof(visited));
    int totalscc=0;
    for(int i=0;i<cnt;i++)
    {
        int v=st[i];
        if(visited[v]==0)
        {
           nodes.clear();
           dfs1(v);
           scc[totalscc]=nodes;
           totalscc++;
        }
    }
    cout<<endl<<totalscc<<endl;
    for(int i=0;i<totalscc;i++)
    {
        for(int j=0;j<scc[i].size();j++)
        {
            cout<<scc[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
