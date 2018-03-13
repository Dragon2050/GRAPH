#include<bits/stdc++.h>

using namespace std;

vector<int>vec[100010];

int visit[100010],n;

void DFS(int start)
{
    if(visit[start]==1)
        return;
    visit[start]=1;
    int siz=vec[start].size();
    for(int i=0;i<siz;i++)
    {
        DFS(vec[start][i]);
    }

}

int main()
{
    int u,v,start;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>u>>v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    cin>>start;
    DFS(start);
    return 0;
}
