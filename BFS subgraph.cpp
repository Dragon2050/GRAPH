#include<bits/stdc++.h>

using namespace std;

#define white 0
#define black 1

int visited[1000010];

vector<int> vec[1000020];

int node,edge;

void BFS(int source)
{
    queue<int> q;
    q.push(source);
    visited[source] = black;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        int len = vec[u].size();
        for(int i=0; i<len; i++)
        {
            int v=vec[u][i];
            if(visited[v] == white)
            {
                q.push(v);
                visited[v] = black;
            }
        }
    }
}

int main()
{
    int u,v;
    cin>>node>>edge;
    for(int i=0; i<edge; i++)
    {
        cin>>u>>v;
        vec[u].push_back(v);///[u-->v]
        vec[v].push_back(u);///[v-->u]
    }
    int cnt=0;
    for(int i=1;i<=node;i++)
    {
        if(visited[i] == white)
        {
            cnt++;
            BFS(i);
        }
    }
    cout<<cnt<<endl;
    return 0;
}
