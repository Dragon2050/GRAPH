#include<bits/stdc++.h>

using namespace std;

#define white 0
#define black 1

int visited[1000000];

vector<int> vec[100000];

int dfs(int source)
{
    int siz=vec[source].size();
    for(int i=0;i<siz;i++)
    {
        int v=vec[source][i];
        if(visited[v]==white)
        {
            visited[v]=black;
            dfs(v);
        }
    }
}
int main()
{
    int node,edge,u,v,source;
    cin>>node>>edge;
    for(int i=0;i<edge;i++)
    {
        cin>>u>>v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    cin>>source;
    dfs(source);
    return 0;
}
