#include<bits/stdc++.h>

using namespace std;

vector<int> graph[100010],cost[100010];

int visited[100010],par[100010],node,edge;

int distanc[100010];

struct nod
{
    int u, w;
    nod(int a, int b) { u = a; w = b; }
    bool operator <(const nod& p) const { return w>p.w; }
};

void dijstra(int source)
{
    for(int i=0;i<=node;i++)
    {
        distanc[i]=99999999;
        par[i]=-1;
    }
    distanc[source]=0;
    priority_queue<nod>pq;
    pq.push(nod(source,0));
    while(!pq.empty())
    {
        nod top=pq.top();
        pq.pop();
        int u=top.u;
        ///if(u==node-1) return;
        for(int i=0;i<graph[u].size();i++)
        {
            int v=graph[u][i];
            if(distanc[u]+cost[u][i]<distanc[v])
            {
                distanc[v]=distanc[u]+cost[u][i];
                pq.push(nod(v,distanc[v]));
                par[v]=u;
            }
        }
    }
    return;
}

int main()
{
    int u,v,w,source;
    cin>>node>>edge;
    for(int i=0;i<edge;i++)
    {
        cin>>u>>v>>w;
        graph[u].push_back(v);
        graph[v].push_back(u);
        cost[u].push_back(w);
        cost[v].push_back(w);
    }
    cin>>source;
    dijstra(source);
    for(int i=0;i<node;i++)
    {
        cout<<"node = "<<i<<" distanc = "<<distanc[i]<<" parent = "<<par[i]<<endl;
    }
    return 0;
}

