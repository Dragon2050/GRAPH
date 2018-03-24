#include<bits/stdc++.h>

using namespace std;

#define white 0
#define black 1

vector<int> vec[100010];
int level[100010],parent[100010];
int visited[100010];
int node,edge;

void bfs(int s)
{
    for(int i=1;i<=node;i++)
        visited[i]=white;
    queue<int> q;
    q.push(s);
    visited[s]=black;
    level[s]=0;
    parent[s]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<vec[u].size();i++)
        {
            if(visited[vec[u][i]]==white)
            {
                level[vec[u][i]]=level[u]+1;
                visited[vec[u][i]]=black;
                q.push(vec[u][i]);
                parent[vec[u][i]]=u;
            }
        }
    }
}

int main()
{
    int u,v,s;
    cin>>node>>edge;
    for(int i=0;i<edge;i++)
    {
        cin>>u>>v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    cin>>s;
    bfs(s);
    cout<<endl<<endl;
    for(int i=1;i<=node;i++)
    {
        cout<<"LEVEL OF NODE "<<i<<" is "<<level[i]<<", parent is "<<parent[i]<<endl<<endl;
    }
    return 0;
}
