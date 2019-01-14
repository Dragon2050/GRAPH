#include<bits/stdc++.h>

using namespace std;

#define white 0
#define gray 1
#define black 2

vector<int> vec[2005];

int cnt,cycle,visited[200005],take[200005];

void dfs(int s)
{
    if(visited[s]==black or cycle)
    {
        return;
    }
    if(visited[s]==gray)
    {
        cycle=1;
        return;
    }
    visited[s]=gray;
    for(int i=0;i<vec[s].size();i++)
    {
        dfs(vec[s][i]);
    }
    visited[s]=black;
    take[cnt]=s;
    cnt++;
}

int main()
{
    int node,edge;
    cin>>node>>edge;
    for(int i=0;i<edge;i++)
    {
        int u,v;
        cin>>u>>v;
        vec[u].push_back(v);
    }
    int source;
    cin>>source;
    dfs(source);
    reverse(take,take+cnt);
    if(cycle == 1)
    {
        cout<<"topsort cannot apply.."<<endl;
        return 0;
    }
    for(int i=0;i<cnt;i++)
        cout<<take[i]<<" ";
    return 0;
}
